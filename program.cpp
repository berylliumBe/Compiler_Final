#include <iostream> 
using namespace std; 
                    
int main () { 
  int _intparam; 
start:
  int n;
  cin >> n;
  int _r1;
  _r1 = ++n;
  double _r2 = _r1 * n;
  double _r3 = _r2 / 2;
  double _r4 = _r3 - 1;
  _intparam = _r4;
  cout << _intparam;
  return 0; 
} 
