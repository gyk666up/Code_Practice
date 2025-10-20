#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1502;
vector<pair<int,int>>g[N];
int dp[N];//记录1到其它点的距离

#define INF -0x3f3f3f3f
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    
    fill(dp+1,dp+1+n,INF);
    dp[1]=0;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==INF)continue;//从1到不了这个点
        for(auto [v,w]:g[i])
        {
            if(dp[v]<dp[i]+w)
            {
                dp[v]=dp[i]+w;
            }
        }
    }
    cout<<(dp[n]==INF?-1:dp[n]);
    return 0;
}