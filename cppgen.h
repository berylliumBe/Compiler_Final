#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

ifstream tacin;
ofstream cppout;

string StandardHead = "\
#include <iostream> \n\
using namespace std; \n\
                    \n\
int main () { \n\
  int _intparam; \n\
";

string StandardTail = "\
  return 0; \n\
} \n\
";

set<string> symbols;

void PrintVar(string var, string type) {
  cppout << "  ";
  if (symbols.find(var) == symbols.end()) {
    cppout << type << " ";
    symbols.insert(var);
  }
  cppout << var << ";" << endl;
}

void TacToCpp () {
  tacin.open("tac.txt");
  cppout.open("program.cpp");

  cppout << StandardHead;
  string line;
  while(getline(tacin, line)) {
    string element;
    vector<string> elements;
    istringstream sline(line);
    while (sline >> element) {
      elements.push_back(element);
    }

    if (elements.size() == 0) {
      // TODO(yuxifeng): is this going to happen?
    }
    else if (elements.size() == 1) {
      // Label.
      cppout << elements[0] << endl;
    }
    else if (elements.size() == 2) {
      // PushParam | PopParams | LCall
      // Goto
      if (elements[0] == "PushParam") {
        string var = elements[1];
        cppout << "  _intparam = " << var << ";" << endl;
      }
      else if (elements[0] == "PopParams") {
        // Do nothing.
      }
      else if (elements[0] == "LCall") {
        string func = elements[1];
        if (func == "_PrintInt") {
          cppout << "  cout << _intparam;" << endl;
        }
      }
      else if (elements[0] == "Goto") {
        string label = elements[1];
        cppout << "  goto " << label << ";" << endl;
      }
    }
    else if (elements.size() == 3) {
      // n = _ReadInteger
      // n = _ReadChar
      // n = ImmediateValue
      if (elements[2] == "_ReadInteger") {
        string var = elements[0];
        PrintVar(var, "int");
        cppout << "  cin >> " << var << ";" << endl;
      }
      else if (elements[2] == "_ReadChar") {
        string var = elements[0];
        PrintVar(var, "char");
        cppout << "  cin >> " << var << ";" << endl;
      }
      else if (elements[1] == "=") {
        string var = elements[0];
        PrintVar(var, "int");
        cppout << "  " << var << " = " << elements[2] << ";" << endl;
      }
    }
    else if (elements.size() == 4) {
      // PRSADD | SUSADD
      // IfZ x Goto x
      if (elements[2] == "PRSADD") {
        string a = elements[0];
        string b = elements[3];
        PrintVar(a, "int");
        cppout << "  " << a << " = ++" << b << ";" << endl;
      }
      else if (elements[2] == "PRSMINUS") {
        string a = elements[0];
        string b = elements[3];
        PrintVar(a, "int");
        cppout << "  " << a << " = --" << b << ";" << endl;
      }
      else if (elements[3] == "SUSADD") {
        string a = elements[0];
        string b = elements[2];
        PrintVar(a, "int");
        cppout << "  " << a << " = " << b << "++;" << endl;
      }
      else if (elements[3] == "SUSMINUS") {
        string a = elements[0];
        string b = elements[2];
        PrintVar(a, "int");
        cppout << "  " << a << " = " << b << "--;" << endl;
      }
      else if (elements[0] == "IfZ") {
        string cond = elements[1];
        string label = elements[3];
        cppout << "  if (!" << cond <<") goto " << label << ";" << endl;
      }
    }
    else if (elements.size() == 5) {
      // binary operations
      string a = elements[0];
      string b = elements[2];
      string c = elements[4];
      string op = elements[3];

      if (op == "MUL") {
        PrintVar(a, "double");
        cppout << "  " << a << " = " << b << " * " << c << ";" << endl;
      }
      else if (op == "DIV") {
        PrintVar(a, "double");
        cppout << "  " << a << " = " << b << " / " << c << ";" << endl;
      }
      else if (op == "MOD") {
        PrintVar(a, "int");
        cppout << "  " << a << " = " << b << " % " << c << ";" << endl;
      }
      else if (op == "ADD") {
        PrintVar(a, "double");
        cppout << "  " << a << " = " << b << " + " << c << ";" << endl;
      }
      else if (op == "MINUS") {
        PrintVar(a, "double");
        cppout << "  " << a << " = " << b << " - " << c << ";" << endl;
      }
      else if (op == "COMP_LT") {
        PrintVar(a, "bool");
        cppout << "  " << a << " = " << b << " < " << c << ";" << endl;
      }
      else if (op == "COMP_GT") {
        PrintVar(a, "bool");
        cppout << "  " << a << " = " << b << " > " << c << ";" << endl;
      }
      else if (op == "COMP_LE") {
        PrintVar(a, "bool");
        cppout << "  " << a << " = " << b << " <= " << c << ";" << endl;
      }
      else if (op == "COMP_GE") {
        PrintVar(a, "bool");
        cppout << "  " << a << " = " << b << " >= " << c << ";" << endl;
      }
      else if (op == "COMP_EQL") {
        PrintVar(a, "bool");
        cppout << "  " << a << " = " << b << " == " << c << ";" << endl;
      }
      else if (op == "COMP_NE") {
        PrintVar(a, "bool");
        cppout << "  " << a << " = " << b << " != " << c << ";" << endl;
      }
      else if (op == "BLEFT") {
        PrintVar(a, "int");
        cppout << "  " << a << " = " << b << " << " << c << ";" << endl;
      }
      else if (op == "BRIGHT") {
        PrintVar(a, "int");
        cppout << "  " << a << " = " << b << " >> " << c << ";" << endl;
      }
      else if (op == "BAND") {
        PrintVar(a, "int");
        cppout << "  " << a << " = " << b << " & " << c << ";" << endl;
      }
      else if (op == "BOR") {
        PrintVar(a, "int");
        cppout << "  " << a << " = " << b << " | " << c << ";" << endl;
      }
      else if (op == "BXOR") {
        PrintVar(a, "int");
        cppout << "  " << a << " = " << b << " ^ " << c << ";" << endl;
      }
      else if (op == "AND") {
        PrintVar(a, "bool");
        cppout << "  " << a << " = " << b << " && " << c << ";" << endl;
      }
      else if (op == "OR") {
        PrintVar(a, "bool");
        cppout << "  " << a << " = " << b << " || " << c << ";" << endl;
      }
    }
  }

  cppout << StandardTail;
  tacin.close();
  cppout.close();

  return;
}
