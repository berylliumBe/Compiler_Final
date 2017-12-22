#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;
    for (int n=100; n<1000; n++)
    {
        x = n / 100;
        y = (n % 100)/10 ;
        z = n % 10;

        if(n == x*x*x + y*y*y +z*z*z)
        {
            cout << n;
        }
    }
    int a = 0;
    for ( x=1; x<10; x++)
    {
        for ( y =0; y<10; y++)
        {
            for ( z = 0; z<10; z++)
            {
                a = 100*x+10*y+z;
                if (a== x*x*x + y*y*y + z*z*z)
                {
                    cout << a;
                }
            }
        }

    }
    return 0;
}
