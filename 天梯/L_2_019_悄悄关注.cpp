#include<bits/stdc++.h>
using namespace std;
const int N=5e4+66;
map<string,bool>mp;//关注的列表
string name[N];
int dianzhan[N];
vector<string>v;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;cin>>name;
        mp[name]=1;
    }
    int m;cin>>m;
    int average=0;
    for(int i=0;i<m;i++)
    {
        cin>>name[i]>>dianzhan[i];
        average+=dianzhan[i];
    }
    average/=m;

    for(int i=0;i<m;i++)
    {
        if(mp.count(name[i])==0)
        {
            if(dianzhan[i]>=average)
            {
                v.push_back(name[i]);
            }
        }
    }
    sort(v.begin(),v.end());
    if(v.size()==0)
    {
        cout<<"Bing Mei You\n";
        return 0;
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}