int a1,a2,a3,n;
int main()
{
    //cout << "Hello world!" << endl;
    read(n);
    a1=1;
    a2=1;
    if (n==1)
    {
       	write(a1);
    }
    if (n==2)
    {
        write(a2);
    }
    for (int i=3;i<=n;i++)
    {
        a3=a1+a2;
        a1=a2;
        a2=a3;
    }
    if (n>=3) write(a3);
    return 0;
}
