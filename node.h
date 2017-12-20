#include <iostream>
#include <vector>
#include <string>
// #include <llvm/Value.h>

class Node {
public:
  std::vector<Node*> Children;
  std::string NodeType;
  std::string NodeValue;
  std::string NodeInfo;
  std::string type; // e.g. int_char, double_float
  bool IsLit;
  Node (std::string nt, std::string nv="", std::string ni="", std::string t="")
  {
    NodeType = nt;
    NodeValue = nv;
    NodeInfo = ni;
    Children = std::vector<Node*>();
    type = t;
    IsLit = false;
  }
};
