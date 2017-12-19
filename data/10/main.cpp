//NKOJ 2328
int maxn = 5e5 + 100;
int MOD = 1e9 + 7;
int a[500100], n;

long long w[500000+5];
long long s[500000+5];
long long ss[500000+5];
int len=0;
int c[500000*2+5];

int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int val)
{
    while(i<=maxn)
    {
        c[i]=c[i]+val;
        i=i+lowbit(i);
    }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s=s+c[i];
        i=i-lowbit(i);
    }
    return s;
}
void get_ss()
{
	int i;
	for(i=1;i<=n;i++)
	{
		//cout<<"a"<<endl;
		add(a[i],1);
		ss[i]=i-sum(a[i]);
	}
}
int wtf(int x)
{
    int b_tree = 0, no_b_tree = 0;
    if(w[x]!=0) return w[x];
    no_b_tree =no_b_tree+ ss[x] ;
    b_tree=b_tree+s[x-1];
    b_tree=b_tree % MOD;
    b_tree = b_tree+no_b_tree;
    b_tree=b_tree % MOD;
    return w[x]=b_tree;
}
int main()
{
    read(n);
    for(int i = 1; i <= n; i++)
        read(a[i]);
    get_ss();
    s[1]=wtf(1);
    for(int i=2;i<=n;i++)
    {
        s[i]=s[i-1]+wtf(i);
        s[i]%=MOD;
    }
    write(wtf(n));
    //cout<<wtf(n)<<endl;
}