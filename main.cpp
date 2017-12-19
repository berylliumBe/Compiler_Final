#include <iostream>
#include <map>
#include <assert.h>
#include "node.h"
extern Node* RootNode;
extern int yyparse();

void DfsOutput(Node* r, int nSpace) {
  for (int i = 0; i < nSpace; i++) {
    std::cout << " ";
  }

  std::cout << r->NodeType << "\t" << r->NodeValue << "\t" << r->NodeInfo;
  std::cout << "\t" << "type:" << r->type << std::endl;

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
    return 0;
}
