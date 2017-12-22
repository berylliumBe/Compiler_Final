#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <assert.h>
#include <fstream>
#include "node.h"
#include "tacgen.h"
#include "astgen.h"
//#include "asmgen.h"
#include "cppgen.h"
#include "tacopt.h"

using namespace std;

extern Node* RootNode;
extern int yyparse();

extern string ThreeAddressCodeGen();
extern ofstream tacout;

extern void DfsOutput();
extern ofstream astout;

extern void TacToAsm();

extern void OptimizeTac();

extern void TacToCpp();

int main(int argc, char **argv)
{
    tacout.open("tacraw.txt");
    astout.open("ast.txt");

    yyparse();
    DfsOutput(RootNode, 0);
    ThreeAddressCodeGen(RootNode);

    tacout.close();
    astout.close();

    //TacToAsm();
    OptimizeTac();
    TacToCpp();

    return 0;
}
