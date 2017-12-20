//NKOJ1037
int b[201]={0};

int main()
{
    b[1]=1;
    int i;
    for(i=2;i<200;i++){
        if(i%2==0){
            if(i>20&&(i/2)%10>=(i/2)/10*2){
                b[i]=b[i/2]+b[i-1]-b[(i/2)/10];
            }
            else b[i]=b[i/2]+b[i-1];
        }
        else b[i]=b[i-1];
    }
    b[200]=b[199]+b[100];
    read(i);
    write(b[i]);
    return 0;
}
