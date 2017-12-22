#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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
      // n = ImmediateValue
      if (elements[2] == "_ReadInteger") {
        string var = elements[0];
        cppout << "  int " << var << ";" << endl;
        cppout << "  cin >> " << var << ";" << endl;
      }
      else if (elements[1] == "=") {
        string var = elements[0];
        cppout << "  int " << var << ";" << endl;
        cppout << "  " << var << " = " << elements[2] << ";" << endl;
      }
    }
    else if (elements.size() == 4) {
      // PRSADD | SUSADD
      // IfZ x Goto x
      if (elements[2] == "PRSADD") {
        string a = elements[0];
        string b = elements[3];
        cppout << "  int " << a << ";" << endl;
        cppout << "  " << a << " = ++" << b << ";" << endl;
      }
      else if (elements[2] == "PRSMINUS") {
        string a = elements[0];
        string b = elements[3];
        cppout << "  int " << a << ";" << endl;
        cppout << "  " << a << " = --" << b << ";" << endl;
      }
      else if (elements[3] == "SUSADD") {
        string a = elements[0];
        string b = elements[2];
        cppout << "  int " << a << ";" << endl;
        cppout << "  " << a << " = " << b << "++;" << endl;
      }
      else if (elements[3] == "SUSMINUS") {
        string a = elements[0];
        string b = elements[2];
        cppout << "  int " << a << ";" << endl;
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
        cppout << "  double " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " * " << c << ";" << endl;
      }
      else if (op == "DIV") {
        cppout << "  double " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " / " << c << ";" << endl;
      }
      else if (op == "MOD") {
        cppout << "  int " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " % " << c << ";" << endl;
      }
      else if (op == "ADD") {
        cppout << "  double " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " + " << c << ";" << endl;
      }
      else if (op == "MINUS") {
        cppout << "  double " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " - " << c << ";" << endl;
      }
      else if (op == "COMP_LT") {
        cppout << "  bool " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " < " << c << ";" << endl;
      }
      else if (op == "COMP_GT") {
        cppout << "  bool " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " > " << c << ";" << endl;
      }
      else if (op == "COMP_LE") {
        cppout << "  bool " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " <= " << c << ";" << endl;
      }
      else if (op == "COMP_GE") {
        cppout << "  bool " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " >= " << c << ";" << endl;
      }
      else if (op == "COMP_EQL") {
        cppout << "  bool " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " == " << c << ";" << endl;
      }
      else if (op == "COMP_NE") {
        cppout << "  bool " << a << ";" << endl;
        cppout << "  " << a << " = " << b << " != " << c << ";" << endl;
      }
    }
  }

  cppout << StandardTail;
  tacin.close();
  cppout.close();

  return;
}
