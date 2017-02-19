#include <stdio.h>
typedef struct
{
    int a;
    char b;
}ST;

ST *fun(ST x)
{
    ST *px;
    x.a = 100;
    x.b = 'C';
    px = &x;
    return px;
}

main()
{
    ST y, *p;
    y.a = 999;
    y.b = 'X';
    printf("y.a = %d y.b = %c\n",y.a, y.b);
    p = fun(y);
    printf("(*p).a = %d (*p).b = %c\n", (*p).a, p->b);
}
