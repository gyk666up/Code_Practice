#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=6002;
int h[N],e[N],ne[N];
int w[N];//每个节点的值
int n;
bool st[N];//标记有父节点的点
int f[N][3];//f[i][0]:这个节点不选 f[i][1]:这个节点选
int idx=0;
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
void dfs(int x)
{
    f[x][1]=w[x];
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        dfs(j);

        f[x][1]+=f[j][0];//如果这个根节点选的话 子节点就不能选了，否则取子节点的最大值
        f[x][0]+=max(f[j][0],f[j][1]);
    }
    return ;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=1;i<=n;i++)
    {
        cin>> w[i];
    }
    int root=1;
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        st[a]=1;
        add(b,a);//从 b 到a 有一条边
    }
    while(st[root])root++;//比之前 for 循环找根节点要聪明很多

    dfs(root);
    cout<<max(f[root][0],f[root][1]);
    return 0;
}