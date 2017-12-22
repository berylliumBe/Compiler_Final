//prime test
#include <iostream>
using namespace std;


int main()
{
    int t,num=0;
    cin >> t;
    while (t--)

    {
        int n;
        cin >> n;
        if (n<2)
        {
            cout << -1;
        }
        else
        {
            int flag=0;
            for (int i=2;i*i<=n;i++)
                if (n%i==0) flag=1;
            if (flag) cout << 1;
                else
                    {
                        num++;
                        cout << 0;
                    }
        }
    }
    int n=num;
    cout << n;
    return 0;

}
