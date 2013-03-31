// by item4
#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    array<int,6> data={19,2,25,92,36,45};
    int min,max,total=0;
    double temp=0.,average,variance;
    
    min=*min_element(data.begin(),data.end());
    max=*max_element(data.begin(),data.end());
    
    for(auto it=data.begin();it!=data.end();++it)
        total+=*it;
    
    average=total/(double)data.size();
    
    for(auto it=data.begin();it!=data.end();++it)
        temp+=pow((double)(*it-average),2.);
    
    variance=temp/data.size();
    
    cout<<"Minimum:"<<min<<endl;
    cout<<"Maximum:"<<max<<endl;
    cout<<"Total:"<<total<<endl;
    cout<<"Average:"<<average<<endl;
    cout<<"Variance:"<<variance<<endl;
            
    return 0;
}