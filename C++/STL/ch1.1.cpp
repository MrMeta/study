#include <iostream>
#include <cstring>

using namespace std;

class String
{
    char p[100];
public:
    String(const char* s)
    {
        strcpy(p, s);
    }
    operator char* ()
    {
        return p;
    }
};

int main()
{
    String s("Hello!");
    const char* sz = s;
    cout << sz << endl;
    return 0;
}