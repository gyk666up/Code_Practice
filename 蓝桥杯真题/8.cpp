#include<bits/stdc++.h>
using namespace std;
int n;
const int N=500001;
// struct edge
// {
//     bool f=1;
//     int to,w;
// }edge[N];
bool st[N];
vector<int>g[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>st[i];
    for(int i=0;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<g[i].size();j++)
        {
            int v=g[i][j];
            
        }
    }
    
    return 0;
}