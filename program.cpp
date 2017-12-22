#include <iostream> 
using namespace std; 
                    
int main () { 
  int _intparam; 
start:
  int n;
  cin >> n;
  int a1;
  a1 = 1;
  int a2;
  a2 = 1;
  bool _r1;
  _r1 = n == 1;
  if (!_r1) goto _L1;
  _intparam = a1;
  cout << _intparam;
  goto _L2;
_L1:
_L2:
  bool _r2;
  _r2 = n == 2;
  if (!_r2) goto _L3;
  _intparam = a2;
  cout << _intparam;
  goto _L4;
_L3:
_L4:
  int i;
  i = 3;
_L5:
  bool _r3;
  _r3 = i <= n;
  if (!_r3) goto _L6;
  double _r4;
  _r4 = a1 + a2;
  int a3;
  a3 = _r4;
  a1;
  a1 = a2;
  a2;
  a2 = a3;
  int _r5;
  _r5 = i++;
  goto _L5;
_L6:
  bool _r6;
  _r6 = n >= 3;
  if (!_r6) goto _L7;
  _intparam = a3;
  cout << _intparam;
  goto _L8;
_L7:
_L8:
  return 0; 
} 
