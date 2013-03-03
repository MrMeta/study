#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ary;
    vector<int>::iterator it;
    
    int i;
    
    do
    {
        cin >> i;
        ary.push_back(i);
    }
    while(i);
    
    for(it=ary.begin();it<ary.end();++it)
    {
        cout << *it << ", ";
    }
    return 0;
}