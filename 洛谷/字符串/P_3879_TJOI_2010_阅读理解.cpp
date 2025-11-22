//秒了
#include<bits/stdc++.h>
using namespace std;
int n;
map<string,vector<int>>mp;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;cin>>m;
        for(int j=0;j<m;j++)
        {
            string s;cin>>s;
            mp[s].push_back(i);//里面有重复的
        }
    }
    int m;cin>>m;
    while(m--)
    {
        string s;cin>>s;
        vector<int>v=mp[s];
        //注意这两行代码 去重
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}