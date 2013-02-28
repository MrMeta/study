#include <cstdio>

int getint()
{
    int s=0,c;
    for(c=getchar(); c < '0' || c > '9';c=getchar());
    for(s=c-'0',c=getchar();c >= '0' && c <= '9';c=getchar())
    {
        s=s*10+c-'0';
    }
    return s;
}

int main()
{
    int c,n,l;
    int i,j,k;
    int min,minlen,temp;
    int days[1001];

    c=getint();
    
    while(c--)
    {
        min=0;
        n=getint();
        l=getint();
        
        for(i=0;i<n;++i)
        {
            days[i]=getint();
            min+=days[i];
        }
        
        minlen=n;
        for(i=l;i<n+1;++i)
        {
            for(j=0;j<n-i+1;++j)
            {
                temp=0;
                for(k=0;k<i;++k)
                {
                    temp+=days[j+k];
                }
                if(temp * minlen < min * i)
                {
                    min=temp;
                    minlen=i;
                }
            }
            
        }
        printf("%.10f\n",min/(double)minlen);
    }
    return 0;
}