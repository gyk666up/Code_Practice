#include<bits/stdc++.h>
using namespace std;
const int N=1e2+66;
int fa[N];
int g[N][N];//这个思想不错 将关系看出边
int find(int x)
{
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)return;
    else
    fa[yy]=xx;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    //并查集固定模板
    for(int i=1;i<=n;i++)fa[i]=i;
    while(m--)
    {
        int x,y,t;cin>>x>>y>>t;
        g[x][y]=g[y][x]=t;
        if(t==1)merge(x,y);
    }
    while(k--)
    {
        int x,y;cin>>x>>y;
        if(find(x)==find(y)&&g[x][y]!=-1)cout<<"No problem\n";
        else if(find(x)!=find(y)&&g[x][y]!=-1)cout<<"OK\n";
        else if(find(x)==find(y)&&g[x][y]==-1)cout<<"OK but...\n";
        else cout<<"No way\n";
    }
    return 0;
}