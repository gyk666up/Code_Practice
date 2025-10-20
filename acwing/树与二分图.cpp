#include<bits/stdc++.h>
using namespace std;
const int N=1e6+66;
int e[2*N];//e[i]=x i索引边的终点是x
int h[N];//h[x]：x结点对应第一条边的索引
int ne[2*N];//ne[x]x边对应的下一条边的索引
int idx=0;
int color[N];
void add_edge(int x,int y)
{
    e[++idx]=y;
    ne[idx]=h[x];
    h[x]=idx;
}
void dfs(int u,int c)
{
    color[u]=c;
    for(int i=h[u];i;i=ne[i])
    {
        int v=e[i];
        if(!color[v])dfs(v,c^1);
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;cin>>a>>b;
        add_edge(a,b);
        add_edge(b,a);
    }
    dfs(1,2);
    long long  cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(color[i]==2)cnt++;
    }
    cout<<cnt*(n-cnt)-(n-1)<<endl;
    return 0;
}