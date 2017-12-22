// Three address code optimization.
// Method used: Dead Code Elimination.

#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

void OptimizeTac() {
  ifstream fin("tacraw.txt");
  ofstream fout("tac.txt");

  set<string> RightVars;
  vector<string> LeftVars;

  string line;
  while(getline(fin, line)) {
    string element;
    vector<string> elements;
    istringstream sline(line);
    while (sline >> element) {
      elements.push_back(element);
    }
    if (elements.size() == 5) {
      // a = b op c
      string a = elements[0];
      string b = elements[2];
      string c = elements[4];
      RightVars.insert(b);
      RightVars.insert(c);
      LeftVars.push_back(a);
    }
    else if (elements.size() == 4) {
      // PRSADD | SUSADD
      // IfZ x Goto x
      if (elements[1] == "=") {
        LeftVars.push_back("#");
        RightVars.insert(elements[2]);
        RightVars.insert(elements[3]);
      }
      else if (elements[0] == "IfZ") {
        LeftVars.push_back("#");
        RightVars.insert(elements[1]);
      }
      else {
        LeftVars.push_back("#");
      }
    }
    else if (elements.size() == 3) {
      if (elements[1] == "=") {
        // a = b
        string a = elements[0];
        string b = elements[2];
        RightVars.insert(b);
        LeftVars.push_back(a);
      } else {
        LeftVars.push_back("#");
      }
    }
    else if (elements.size() == 2) {
      if (elements[0] == "PushParam") {
        RightVars.insert(elements[1]);
        LeftVars.push_back("#");
      }
      else {
        LeftVars.push_back("#");
      }
    }
    else {
      LeftVars.push_back("#");
    }
  }
  fin.close();

  fin.open("tacraw.txt");
  int n = 0;
  while(getline(fin, line)) {
    string v = LeftVars[n++];
    if (v != "#" && RightVars.find(v) == RightVars.end()) {
      // Skip this line
    } else {
      fout << line << endl;
    }
  }

  fin.close();
  fout.close();
  return;
}
