#include "my_printf.h"

int main()
{
    my_printf("%d %d\n",543,-789);
    my_printf("%u %u\n",123u,-789);
    my_printf("%c %c\n",'a',66);
    my_printf("%s %s\n","무궁화 꽃이","피었습니다.");
    my_printf("%f %f\n",123.456,-987.65);
    return 0;
}