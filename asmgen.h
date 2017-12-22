#include <fstream>

void TacToAsm() {
  ifstream tacin;
  ofstream asmout;
  tacin.open("tac.txt");
  asmout.open("program.asm");

  tacin.close();
  asmout.close();

  return;
}
