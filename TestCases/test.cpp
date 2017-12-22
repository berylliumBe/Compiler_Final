//int a1,a2,a3,n;

#include <iostream>
using namespace std;

int main()
{
    //cout << "Hello world!" << endl;
    int a1, a2, a3, n;
    cin >> n;
    a1=1;
    a2=1;
    if (n==1)
    {
       	cout << a1;
    }
    if (n==2)
    {
        cout << a2;
    }
    for (int i=3;i<=n;i++)
    {
        a3=a1+a2;
        a1=a2;
        a2=a3;
    }
    if (n>=3) cout << a3;
    return 0;
}
