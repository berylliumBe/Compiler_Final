#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    //cin>>t;
    read(t);
    while(t--)
    {
        int n;
        //cin>>n;
        read(n);
        long double x1,y1,x2,y2,x3,y3;
        read(x1);
        read(y1);
        read(x2);
        read(y2);
        read(x3);
        read(y3);
        //cin>>x1>>y1>>x2>>y2>>x3>>y3;
        long double xx1,yy1,xx2,yy2,xx3,yy3;

        while(n--)
        {
            xx1= ((x2+x3)/2-x1)/3+x1;
            yy1= ((y2+y3)/2-y1)/3+y1;

            xx2= ((x1+x3)/2-x2)/3+x2;
            yy2= ((y1+y3)/2-y2)/3+y2;

            xx3= ((x1+x2)/2-x3)/3+x3;
            yy3= ((y1+y2)/2-y3)/3+y3;

            x1=xx1;
            y1=yy1;
            x2=xx2;
            y2=yy2;
            x3=xx3;
            y3=yy3;

            double cx=((x1+x2)/2+x3)/2,cy=((y1+y2)/2+y3)/2;
            xx1=2*cx-x1;
            yy1=2*cy-y1;
            xx2=2*cx-x2;
            yy2=2*cy-y2;
            xx3=2*cx-x3;
            yy3=2*cy-y3;

            x1=xx2;
            y1=yy2;

            x2=xx1;
            y2=yy1;

            x3=xx3;
            y3=yy3;
        }
        write(x1);
        write(y1);
        write(x2);
        write(y2);
        write(x3);
        write(y3);
        //printf("%.4Lf %.4Lf %.4Lf %.4Lf %.4Lf %.4Lf\n",x1,y1,x2,y2,x3,y3);
    }
    return 0;
}
