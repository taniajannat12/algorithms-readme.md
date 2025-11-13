#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
    int s[n],f[n];
    cout<<"Start time :"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    cout<<"Finish time :"<<endl;
     for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(f[i]>f[j])
            {
                swap(f[i],f[j]);
                swap(s[i],s[j]);
            }
        }
    }
    cout<<"Select Activities :"<<endl;
    int i=0;
    cout<<i+1<<" ";
    for(int j=1;j<n;j++)
    {
        if(s[j]>=f[i])
        {
            cout<<j+1<<" ";
            i=j;
        }
    }
    cout<<endl;
}

