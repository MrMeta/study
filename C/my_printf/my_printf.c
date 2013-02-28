#include <stdio.h>
#include <stdarg.h>
#include <my_printf.h>

int my_printf(char * pattern, ...)
{
    char * p=pattern;
    int pos=0;
    int pattern_start=0;
    int count=0;
    va_list vl;
    pattern=0;
    while(*(p+pos))
    {
        char c=*(p+pos);
        if(c=='%')
        {
            ++pattern;
        }
        ++pos;
    }
    
    va_start(vl,pattern);
    
    pos=0;
    while(*(p+pos))
    {
        char c=*(p+pos);
        if(c=='%')
        {
            pattern_start=1;
        }
        else
        {
            if(pattern_start)
            {
                if(c=='d')
                {
                    print_int(va_arg(vl,int));
                }
                else if(c=='u')
                {
                    print_unsigned(va_arg(vl,unsigned));
                }
                else if(c=='c')
                {
                    putchar(va_arg(vl,int));
                }
                else if(c=='s')
                {
                    print_string(va_arg(vl,char *));
                }
                else if(c=='f')
                {
                    print_double(va_arg(vl,double));
                }
                else
                {
                    putchar(c);
                }
                pattern_start=0;
            }
            else
            {
                putchar(c);
            }
        }
        ++pos;
    }
    
    va_end(vl);
    
    return 1;
}

void print_int(int n)
{
    char buff[20]={0,};
    int i=0;
    int pos=0;
    if(n<0)
    {
        putchar('-');
        n*=-1;
    }
    while(n)
    {
        buff[i++]=n%10;
        n/=10;
    }
    while(i--)
    {
        putchar('0'+buff[i]);
    }
}

void print_unsigned(int n)
{
    char buff[20]={0,};
    unsigned u=n;
    int i=0;
    int pos=0;
    while(u)
    {
        buff[i++]=u%10;
        u/=10;
    }
    while(i--)
    {
        putchar('0'+buff[i]);
    }
}

void print_string(char * str)
{
    while(*str)
    {
        putchar(*str++);
    }
}

void print_double(double n)
{
    int big;
    double small;
    char buff[50]={0,};
    int i=0,j=0;
    big = (int)n;
    small = n-(double)big;
    print_int(big);
    if(n<0)
    {
        small*=-1.;
    }
    if(small)
    {
        buff[i++]='.';
        while(small && small<1 && small>0.0)
        {
            buff[i++]='0'+(int)(small*10.0);
            small=small*10.0-(double)(int)(small*10.0);
            if((int)(small+.5)>=1)
            {
                ++buff[i-1];
                small-=1.0;
            }
            if(i>20) break;
            
        }
        
        for(j=0;j<i;++j)
        {
            putchar(buff[j]);
        }
    }
}