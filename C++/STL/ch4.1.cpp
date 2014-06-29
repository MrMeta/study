#include <iostream>

using namespace std;

typedef char MyType;

template<typename T>
void Copy(T * dst, T * src, int size)
{
    for(int i = 0; i < size; ++i)
    {
        dst[i] = src[i];
    }
}

template<typename T>
void Print(T * src, int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << src[i] << endl;
    }
    cout << endl;
}

int main()
{
    int arr1[] = {10,20,30,40,50};
    int arr2[5];
    Copy(arr2, arr1, 5);
    Print(arr2, 5);

    MyType myArr1[5] = {'a','b','c','d','e'};
    MyType myArr2[5];
    Copy(myArr2, myArr1, 5);
    Print(myArr2, 5);

    return 0;
}