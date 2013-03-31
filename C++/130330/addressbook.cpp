#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

struct data
{
    string name,tel,addr,birth;
};

class AddressBook
{
    private:
        vector<data> array;
    public:
        void list()
        {
            vector<data>::iterator it;
            int i=0;
            for(it=array.begin();it!=array.end();++it,++i)
            {
                print(it,i);
            }
        };
        void insert(string name,string tel,string addr,string birth)
        {
            data temp;
            temp.name=name;
            temp.tel=tel;
            temp.addr=addr;
            temp.birth=birth;
            array.push_back(temp);
        };
        void search(string keyword)
        {
            vector<data>::iterator it;
            int i=0;
            for(it=array.begin();it!=array.end();++it,++i)
            {
                if(it->name == keyword || it->tel == keyword || it->addr == keyword || it->birth == keyword)
                {
                    print(it,i);
                }
            }
        };
        void print(vector<data>::iterator it, int i)
        {
            cout << "���� : " << i << endl;
            cout << "�̸� : " << it->name << endl;
            cout << "��ȭ : " << it->tel << endl;
            cout << "�ּ� : " << it->addr << endl;
            cout << "���� : " << it->birth << endl << endl;
        };
        void remove(int i)
        {
            array.erase(array.begin()+i);
        };
    
};
    
int main()
{
    AddressBook book;
    int i=0;
    
    do
    {
        cout << "��ɾ�(0~4):";
        cin >> i;
        
        if(i == 1)
        {
            book.list();
        }
        else if(i == 2)
        {
            string name,tel,addr,birth;
            cin.ignore(INT_MAX, '\n');
            cout << "�̸�:";
            getline(cin,name);
            cout << "��ȭ:";
            getline(cin,tel);
            cout << "�ּ�:";
            getline(cin,addr);
            cout << "����:";
            getline(cin,birth);
            book.insert(name,tel,addr,birth);
        }
        else if(i == 3)
        {
            string keyword;
            cin.ignore(INT_MAX, '\n');
            cout << "�˻���:";
            getline(cin,keyword);
            book.search(keyword);
        }
        else if(i == 4)
        {
            int index;
            cout << "����:";
            cin >> index;
            book.remove(index);
        }
        else
        {
            cout << "0:���� / 1:��� / 2:���� / 3:�˻� / 4:����" << endl;
        }
    }
    while(i!=0);
    
    return 0;
}