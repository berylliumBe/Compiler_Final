#include <iostream> 
using namespace std; 
                    
int main () { 
  int _intparam; 
start:
  char log;
  cin >> log;
  int num;
  num = 0;
  int i;
  i = 0;
_L1:
  bool _r1;
  _r1 = i < 8;
  if (!_r1) goto _L2;
  int _r2;
  _r2 = log >> i;
  int val;
  val = _r2;
  int _r3;
  _r3 = val & 0x01;
  val;
  val = _r3;
  if (!val) goto _L3;
  int _r4;
  _r4 = num++;
  goto _L4;
_L3:
_L4:
  int _r5;
  _r5 = i++;
  goto _L1;
_L2:
  _intparam = num;
  cout << _intparam;
  return 0; 
} 
