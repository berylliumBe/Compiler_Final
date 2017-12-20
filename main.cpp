#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <assert.h>
#include "node.h"

using namespace std;

extern Node* RootNode;
extern int yyparse();

int rn = 0;

bool IsBinaryOperation(string NodeValue) {
  if (NodeValue == "MUL" || NodeValue == "DIV" || NodeValue == "MOD" ||
      NodeValue == "MINUS" || NodeValue == "ADD" ||
      NodeValue == "BLEFT" || NodeValue == "BRIGHT" ||
      NodeValue == "COMP_LT" || NodeValue == "COMP_GT" ||
      NodeValue == "COMP_LE" || NodeValue == "COMP_GE" ||
      NodeValue == "COMP_EQL" || NodeValue == "COMP_NE" ||
      NodeValue == "BAND" || NodeValue == "BXOR" || NodeValue == "BOR" ||
      NodeValue == "AND" || NodeValue == "OR")
  {
      return true;
  }
  else {
    return false;
  }
}

bool IsPreUnaryOperation(string NodeValue) {
  if (NodeValue == "BNOT" || NodeValue == "NOT" ||
      NodeValue == "PRSADD" || NodeValue == "PRSMINUS" ||
      NodeValue == "NEG")
  {
        return true;
  }
  else {
    return false;
  }
}

bool IsSufUnaryOperation(string NodeValue) {
  if (NodeValue == "SUSADD" || NodeValue == "SUSMINUS") {
    return true;
  }
  else {
    return false;
  }
}

string ThreeAddressCodeGen(Node* r) {

  string NodeType = r->NodeType;
  string NodeValue = r->NodeValue;
  string NodeInfo = r->NodeInfo;
  string type = r->type;
  vector<Node*> Children = r->Children;

  if (NodeType == "VAL") {
    return NodeValue;
  }
  else if (NodeType == "VAR") {
    return NodeValue;
  }
  else if (NodeType == "EXPR") {
    if (IsBinaryOperation(NodeValue)) {
      string arg1 = ThreeAddressCodeGen(Children[0]);
      string arg2 = ThreeAddressCodeGen(Children[1]);
      rn++;
      string res = "r" + to_string(rn);
      cout << res << " = " << arg1 << " " << NodeValue << " " << arg2 << endl;
      // cout << NodeValue << "\t" << arg1 << "\t" << arg2 << "\t" << res << endl;
      return res;
    }
    else if (IsPreUnaryOperation(NodeValue)) {
      string arg1 = ThreeAddressCodeGen(Children[0]);
      rn++;
      string res = "r" + to_string(rn);
      cout << res << " = " << NodeValue << " " << arg1 << endl;
      return res;
    }
  }
  else if (NodeType == "STMT") {
    if (NodeValue == "IF") {

    }
    else if (NodeValue == "FOR") {

    }
    else if (NodeValue == "WHILE") {

    }
    else if (NodeValue == "RET") {
      return "";
    }
    else if (NodeValue == "READ") {
      string res = Children[0]->NodeValue;
      cout << res + " = _ReadInteger" << endl;
      return res;
    }
    else if (NodeValue == "WRITE") {
      string arg1 = ThreeAddressCodeGen(Children[0]);
      cout << "PushParam " << arg1 << endl;
      cout << "LCall _PrintInt" << endl;
      cout << "PopParams 4" << endl;
      return "";
    }
    else if (NodeValue == "EXPR") {

    }
    else if (NodeValue == "DECL") {
      return "";
    }
  }
  else if (NodeType == "COMP_STMT") {
    for (auto c : Children) {
      ThreeAddressCodeGen(c);
    }
    return "";
  }
  else if (NodeType == "START") {
    cout << "start:" << endl;
    ThreeAddressCodeGen(Children[0]);
    return "";
  }
}

void DfsOutput(Node* r, int nSpace) {
  for (int i = 0; i < nSpace; i++) {
    cout << " ";
  }

  cout << r->NodeType << "\t" << r->NodeValue << "\t" << r->NodeInfo;
  cout << "\t" << "type:" << r->type << endl;

  nSpace += 4;
  int NumChil = r->Children.size();
  for (int i = 0; i < NumChil; i++) {
    DfsOutput(r->Children[i], nSpace);
  }
}

int main(int argc, char **argv)
{
    yyparse();
    DfsOutput(RootNode, 0);
    ThreeAddressCodeGen(RootNode);
    return 0;
}
