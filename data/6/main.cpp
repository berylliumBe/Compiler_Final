#include <iostream>

using namespace std;

int main()
{
   char log;
   read(log);
   int   i;
   int   num=0,   val;
   for(i=0;   i<8;   i++)    {
        val   =   log   >>   i;
        val   &=   0x01;
        if(val)
            num++;
    }
    write(num);
    return  0;
}
