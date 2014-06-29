#include <iostream>

using namespace std;

template<typename T>
class Stack
{
    T * data;
    int size;
public:
    Stack(): size(0), data(nullptr) {}
    ~Stack()
    {
        delete [] data;
    }
    void Push(T d)
    {
        T * new_data = new T[size + 1];
        T * temp = data;
        
        for(int i = 0; i < size; ++i)
        {
            new_data[i] = data[i];
        }
        new_data[size] = d;
        
        delete [] temp;
        
        data = new_data;
        ++size;
    }
    T Pop()
    {
        T * temp = data;
        T res = data[size - 1];
        if(size > 1)
        {
            T * new_data = new T[size - 1];

            for(int i = 0; i < size - 1; ++i)
            {
                new_data[i] = data[i];
            }
            delete [] temp;
            data = new_data;
        }
        else
        {
            delete [] temp;
            data = nullptr;
        }
        
        --size;
        return res;
    }
    bool Empty()
    {
        return size == 0;
    }
};

int main()
{
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    if(!st.Empty())
    {
        cout << st.Pop() << endl;
    }
    if(!st.Empty())
    {
        cout << st.Pop() << endl;
    }
    if(!st.Empty())
    {
        cout << st.Pop() << endl;
    }
    return 0;
}