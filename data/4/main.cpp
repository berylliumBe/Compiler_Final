//prime test
int main()
{
    int t,num=0;
    read(t);
    while (t--)
    {
        int n;
        read(n);
        if (n<2)
        {
            write(-1);
        }
        else
        {
            int flag=0;
            for (int i=2;i*i<=n;i++)
                if (n%i==0) flag=1;
            if (flag) write(1);
                else
                    {
                        num++;
                        write(0);
                    }
        }
    }
    int n=num;
    write(n);
    return 0;
}