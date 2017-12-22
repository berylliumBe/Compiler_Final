#include <iostream> 
using namespace std; 
                    
int main () { 
  int _intparam; 
start:
  int num;
  num = 0;
  int times;
  times = 0;
  int n;
  cin >> n;
  int i;
  i = 0;
_L1:
  bool _r1;
  _r1 = i < n;
  if (!_r1) goto _L2;
  int j;
  j = 0;
_L3:
  bool _r2;
  _r2 = j < n;
  if (!_r2) goto _L4;
  double _r3;
  _r3 = i * 1.0;
  double _r4;
  _r4 = _r3 / n;
  int xx;
  xx = _r4;
  double _r5;
  _r5 = j * 1.0;
  double _r6;
  _r6 = _r5 / n;
  int yy;
  yy = _r6;
  double _r7;
  _r7 = xx * xx;
  double _r8;
  _r8 = yy * yy;
  double _r9;
  _r9 = _r7 + _r8;
  bool _r10;
  _r10 = _r9 < 1;
  if (!_r10) goto _L5;
  int _r11;
  _r11 = num++;
  goto _L6;
_L5:
  int _r12;
  _r12 = num--;
_L6:
  int _r13;
  _r13 = times++;
  int _r14;
  _r14 = j++;
  goto _L3;
_L4:
  int _r15;
  _r15 = i++;
  goto _L1;
_L2:
  double _r16;
  _r16 = num * 1.0;
  double _r17;
  _r17 = _r16 / times;
  double _r18;
  _r18 = _r17 * 4;
  int ans;
  ans = _r18;
  _intparam = ans;
  cout << _intparam;
  return 0; 
} 
