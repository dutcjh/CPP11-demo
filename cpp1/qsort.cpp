#include<cstdlib>
#include<iostream>
//void qsort(void *base, int nelem, unsigned int width,
             //int ( * pfCompare)( const void *, const void *));
using namespace std;

struct ST
{
    int value;
    int index;
};

int compare(const void *a, const void *b)
{
    ST *pa = (ST *) a;
    ST *pb = (ST *) b;
    return (pa->value)-(pb->value);
}

int main()
{
    int a[10] = {5,6,4,3,7,0,8,9,2,1};
    ST b[10] = {};
    for(int i = 0; i<10; ++i)
    {
        b[i].value = a[i];
        b[i].index = i;
    }
    qsort(b,10,sizeof(ST),compare);
    for(int i = 0; i < 10; ++i)
    {
        cout << "(" << b[i].index << ", " << b[i].value << ");";
    }
    cout << endl;
    return 0;
}
