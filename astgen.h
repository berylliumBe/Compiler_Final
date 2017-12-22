#include <fstream>
using namespace std;

ofstream astout;

void DfsOutput(Node* r, int nSpace) {

  for (int i = 0; i < nSpace; i++) {
    astout << " ";
  }

  astout << r->NodeType << "\t" << r->NodeValue << "\t" << r->NodeInfo;
  astout << "\t" << "type:" << r->type << endl;

  nSpace += 4;
  int NumChil = r->Children.size();
  for (int i = 0; i < NumChil; i++) {
    DfsOutput(r->Children[i], nSpace);
  }
}
