#include <iostream> 
using namespace std; 
                    
int main () { 
  int _intparam; 
start:
  int num;
  num = 0;
  int t;
  cin >> t;
_L1:
  int _r1;
  _r1 = t--;
  if (!_r1) goto _L2;
  int n;
  cin >> n;
  bool _r2;
  _r2 = n < 2;
  if (!_r2) goto _L3;
  _intparam = -1;
  cout << _intparam;
  goto _L4;
_L3:
  int flag;
  flag = 0;
  int i;
  i = 2;
_L5:
  double _r3;
  _r3 = i * i;
  bool _r4;
  _r4 = _r3 <= n;
  if (!_r4) goto _L6;
  int _r5;
  _r5 = n % i;
  bool _r6;
  _r6 = _r5 == 0;
  if (!_r6) goto _L7;
  flag;
  flag = 1;
  goto _L8;
_L7:
_L8:
  int _r7;
  _r7 = i++;
  goto _L5;
_L6:
  if (!flag) goto _L9;
  _intparam = 1;
  cout << _intparam;
  goto _L10;
_L9:
  int _r8;
  _r8 = num++;
  _intparam = 0;
  cout << _intparam;
_L10:
_L4:
  goto _L1;
_L2:
  n;
  n = num;
  _intparam = n;
  cout << _intparam;
  return 0; 
} 
