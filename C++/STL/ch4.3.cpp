#include <iostream>

using namespace std;

template<typename T>
class Queue
{
    T * data;
    int size;
public:
    Queue(): size(0), data(nullptr) {}
    ~Queue()
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
        T res = data[0];
        if(size > 1)
        {
            T * new_data = new T[size - 1];

            for(int i = 1; i < size; ++i)
            {
                new_data[i - 1] = data[i];
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
    Queue<int> q;

    q.Push(10);
    q.Push(20);
    q.Push(30);

    if(!q.Empty())
    {
        cout << q.Pop() << endl;
    }
    if(!q.Empty())
    {
        cout << q.Pop() << endl;
    }
    if(!q.Empty())
    {
        cout << q.Pop() << endl;
    }
    return 0;
}