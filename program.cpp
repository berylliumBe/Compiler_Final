#include <iostream> 
using namespace std; 
                    
int main () { 
  int _intparam; 
start:
  int x;
  x = 0;
  int y;
  y = 0;
  int z;
  z = 0;
  int n;
  n = 100;
_L1:
  bool _r1;
  _r1 = n < 1000;
  if (!_r1) goto _L2;
  double _r2;
  _r2 = n / 100;
  x;
  x = _r2;
  int _r3;
  _r3 = n % 100;
  double _r4;
  _r4 = _r3 / 10;
  y;
  y = _r4;
  int _r5;
  _r5 = n % 10;
  z;
  z = _r5;
  double _r6;
  _r6 = x * x;
  double _r7;
  _r7 = _r6 * x;
  double _r8;
  _r8 = y * y;
  double _r9;
  _r9 = _r8 * y;
  double _r10;
  _r10 = _r7 + _r9;
  double _r11;
  _r11 = z * z;
  double _r12;
  _r12 = _r11 * z;
  double _r13;
  _r13 = _r10 + _r12;
  bool _r14;
  _r14 = n == _r13;
  if (!_r14) goto _L3;
  _intparam = n;
  cout << _intparam;
  goto _L4;
_L3:
_L4:
  int _r15;
  _r15 = n++;
  goto _L1;
_L2:
  int a;
  a = 0;
  x;
  x = 1;
_L5:
  bool _r16;
  _r16 = x < 10;
  if (!_r16) goto _L6;
  y;
  y = 0;
_L7:
  bool _r17;
  _r17 = y < 10;
  if (!_r17) goto _L8;
  z;
  z = 0;
_L9:
  bool _r18;
  _r18 = z < 10;
  if (!_r18) goto _L10;
  double _r19;
  _r19 = 100 * x;
  double _r20;
  _r20 = 10 * y;
  double _r21;
  _r21 = _r19 + _r20;
  double _r22;
  _r22 = _r21 + z;
  a;
  a = _r22;
  double _r23;
  _r23 = x * x;
  double _r24;
  _r24 = _r23 * x;
  double _r25;
  _r25 = y * y;
  double _r26;
  _r26 = _r25 * y;
  double _r27;
  _r27 = _r24 + _r26;
  double _r28;
  _r28 = z * z;
  double _r29;
  _r29 = _r28 * z;
  double _r30;
  _r30 = _r27 + _r29;
  bool _r31;
  _r31 = a == _r30;
  if (!_r31) goto _L11;
  _intparam = a;
  cout << _intparam;
  goto _L12;
_L11:
_L12:
  int _r32;
  _r32 = z++;
  goto _L9;
_L10:
  int _r33;
  _r33 = y++;
  goto _L7;
_L8:
  int _r34;
  _r34 = x++;
  goto _L5;
_L6:
  return 0; 
} 
