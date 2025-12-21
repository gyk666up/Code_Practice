#include<bits/stdc++.h>
using namespace std;
const int N=1e2;
map<int,bool>mp[N];
bool st[10002];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m;cin>>m;
        for(int j=0;j<m;j++)
        {
            int x;cin>>x;
            mp[i][x]=1;
        }
    }
    int t;cin>>t;
    
    while(t--)
    {
    	int ans=0;
        int x,y;cin>>x>>y;
        //在map中这种遍历方式是错误的
        // for(int i=0;i<mp[x].size();i++)
        // {
        //     if(st[mp[x][i]])
        // }
        for(auto t:mp[x])
        {
            if(mp[y].count(t.first))ans++;//
        }
        cout<<fixed<<setprecision(2)<<100*(double)ans/(mp[x].size()+mp[y].size()-ans)<<"%"<<endl;
    }

   
    return 0;
}