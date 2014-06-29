#include <iostream>

using namespace std;

class Equal
{
public:
    bool operator () (int a, int b)
    {
        return a == b;
    }
};

int main()
{
    Equal cmp;
    if(cmp(10, 20))
    {
        cout << "같다" << endl;
    }
    else
    {
        cout << "다르다" << endl;
    }
    return 0;
}