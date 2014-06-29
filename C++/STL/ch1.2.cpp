#include <iostream>
#include <cstring>

using namespace std;

class String
{
    char buff[100];
public:
    String(const char * str)
    {
        strcpy(buff, str);
    }

    void print()
    {
        cout << buff << endl;
    }
};

int main()
{
    const char * sz = "Hello!";
    String s("Hi~!");
    s = sz;

    s.print();
    return 0;
}