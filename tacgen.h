#include <fstream>
using namespace std;

int rn = 0;
int Ln = 0;
ofstream tacout;

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

bool IsAssign(string NodeValue) {
  if (NodeValue == "ASSIGN" || NodeValue == "DECL_ASSIGN") {
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
    if (NodeInfo == "NEG") {
      return "-" + NodeValue;
    } else {
      return NodeValue;
    }
  }
  else if (NodeType == "VAR") {
    return NodeValue;
  }
  else if (NodeType == "EXPR") {
    string res = "";
    if (IsBinaryOperation(NodeValue)) {
      string arg1 = ThreeAddressCodeGen(Children[0]);
      string arg2 = ThreeAddressCodeGen(Children[1]);
      rn++;
      res = "_r" + to_string(rn);
      tacout << "  " << res << " = " << arg1 << " " << NodeValue << " " << arg2 << endl;
    }
    else if (IsPreUnaryOperation(NodeValue)) {
      string arg1 = ThreeAddressCodeGen(Children[0]);
      rn++;
      res = "_r" + to_string(rn); // TODO(yuxifeng): extensible design for ++/--.
      tacout << "  " << res << " = " << NodeValue << " " << arg1 << endl;
    }
    else if (IsSufUnaryOperation(NodeValue)) {
      string arg1 = ThreeAddressCodeGen(Children[0]);
      rn++;
      res = "_r" + to_string(rn);
      tacout << "  " << res << " = " << arg1 << " " << NodeValue << endl;
    }
    else if (IsAssign(NodeValue)) {
      res = ThreeAddressCodeGen(Children[0]);
      string arg2 = ThreeAddressCodeGen(Children[1]);

      string op = NodeInfo;
      if (op != "") {
        rn++;
        string reg = "_r" + to_string(rn);
        tacout << "  " << reg << " = " << res << " " << op << " " << arg2 << endl;
        tacout << "  " << res << " = " << reg << endl;
      } else {
        tacout << "  " << res << " = " << arg2 << endl;
      }
    }
    return res;
  }
  else if (NodeType == "STMT") {
    if (NodeValue == "IF") {
      Node* expr = Children[0];
      string cond = ThreeAddressCodeGen(expr);
      Ln++;
      string FalseBranchLabel = "_L" + to_string(Ln);
      Ln++;
      string EndIfLabel = "_L" + to_string(Ln);

      tacout << "  IfZ " << cond << " Goto " << FalseBranchLabel << endl;
      Node* stmts_iftrue = Children[1];
      ThreeAddressCodeGen(stmts_iftrue);
      tacout << "  Goto " << EndIfLabel << endl;

      tacout << FalseBranchLabel << ":" << endl;
      if (Children.size() == 3) {
        Node* stmts_else = Children[2];
        ThreeAddressCodeGen(stmts_else);
      }

      tacout << EndIfLabel << ":" << endl;
      return "";
    }
    else if (NodeValue == "FOR") {
      Node* first_start = Children[0];
      Node* second_condition = Children[1];
      Node* third_action = Children[2];
      Node* stmts = Children[3];

      Ln++;
      string ForBlockLabel = "_L" + to_string(Ln);
      Ln++;
      string EndForLabel = "_L" + to_string(Ln);

      ThreeAddressCodeGen(first_start);
      tacout << ForBlockLabel << ":" << endl;
      string cond = ThreeAddressCodeGen(second_condition);
      tacout << "  IfZ " << cond << " Goto " << EndForLabel << endl;
      ThreeAddressCodeGen(stmts);
      ThreeAddressCodeGen(third_action);
      tacout << "  Goto " << ForBlockLabel << endl;
      tacout << EndForLabel << ":" << endl;
      return "";
    }
    else if (NodeValue == "WHILE") {
      Ln++;
      string WhileBlockLabel = "_L" + to_string(Ln);
      Ln++;
      string EndWhileLabel = "_L" + to_string(Ln);

      Node* condition = Children[0];
      Node* stmts = Children[1];

      tacout << WhileBlockLabel << ":" << endl;
      string cond = ThreeAddressCodeGen(condition);
      tacout << "  IfZ " << cond << " Goto " << EndWhileLabel << endl;
      ThreeAddressCodeGen(stmts);
      tacout << "  Goto " << WhileBlockLabel << endl;
      tacout << EndWhileLabel << ":" << endl;
      return "";
    }
    else if (NodeValue == "RET") {
      return "";
    }
    else if (NodeValue == "READ") {
      string res = Children[0]->NodeValue;
      tacout << "  " << res + " = _ReadInteger" << endl;
      return res;
    }
    else if (NodeValue == "WRITE") {
      string arg1 = ThreeAddressCodeGen(Children[0]);
      tacout << "  PushParam " << arg1 << endl;
      tacout << "  LCall _PrintInt" << endl;
      tacout << "  PopParams 4" << endl;
      return "";
    }
    else if (NodeValue == "EXPR") {
      ThreeAddressCodeGen(Children[0]);
      return "";
    }
    else if (NodeValue == "DECL") {
      Node* ArgsList = Children[1];
      ThreeAddressCodeGen(ArgsList);
      return "";
    }
  }
  else if (NodeType == "ARGS_LIST") {
    for (auto c : Children) {
      ThreeAddressCodeGen(c);
    }
    return "";
  }
  else if (NodeType == "COMP_STMT") {
    for (auto c : Children) {
      ThreeAddressCodeGen(c);
    }
    return "";
  }
  else if (NodeType == "START") {
    tacout << "start:" << endl;
    for (auto c : Children) {
      ThreeAddressCodeGen(c);
    }
    return "";
  }
}
