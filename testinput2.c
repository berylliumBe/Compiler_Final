int main() {
  int a = 1, b = 2;
  read(a);
  read(b);
  char c = a+b;
  if(c >= 5)
    c = c + 2;
  else
  {
   int b = 0;
   write(b);
   b = 10+5*(4-2)/(3>=1)+(5!=4)*('a'/5); //请求值
   write(b);
   c = 2;
   c = (c == 2) + (c = 4); //强调左结合，以及后序遍历
  }
  write(c);

}
