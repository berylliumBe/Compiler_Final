//get pi
int main()
{
    int num,times,n;
    read(n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
        {
            double xx=i*1.0/n;
            double yy=j*1.0/n;
            if (xx*xx+yy*yy<1) num++;
            times++;
        }
    double ans=num*1.0/times*4;
    write(ans);
    return 0;
}
