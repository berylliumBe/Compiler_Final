int main()
{
	int a = 1, b = a, _ = 0, _1, _2, _3; 
	int (d) = (1), e = (1), (f) = d; // May Be tolerated at first time if ...
	int c = (a+b);
	c = _ + c * c - c / c;
	write(c);
	a = (b >= a) <= (a == a);
	write(c);
	c = (c, ++c); // Can be tolerated if failed, please notate it
	write(c);
	c=c++;
	write(c);
	int x1,x2,x3,x4,x5,x6;
	read(x1);
	read(x2);
	read(x3);
	read(x4);
	read(x5);
	read(x6);
	c=x1|x2^x3+x4/x5&x6;
	write(c);
}
