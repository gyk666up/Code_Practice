// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int fa[N];
// int n,m;
// int cnt[N];
// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)
//     {
//         //cnt[xx]++;//这个对吗？
//         //已经是一个连通块了，没有引入任何新的点  注意这里！！！
//         return ;
//     }
//     fa[yy]=xx;
//     cnt[xx]+=cnt[yy];
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
//     while(m--)
//     {
//         string s;cin>>s;
//         if(s=="C")
//         {
//             int x,y;cin>>x>>y;
//             merge(x,y);
//         }
//         else if(s=="Q1"){
//             int x,y;cin>>x>>y;
//             if(find(x)==find(y))cout<<"Yes\n";
//             else cout<<"No\n";
//         }
//         else if(s=="Q2")
//         {
//             int x;cin>>x;
//             cout<<cnt[find(x)]<<endl;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+66;
int fa[N];
int siz[N];
int n,m;
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)
    {
        return;
        //siz[xx]++;//这里易错
    }
    fa[yy]=xx;
    siz[xx]+=siz[yy];
}

signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
    while(m--)
    {
        string op;cin>>op;
        if(op=="C")
        {
            int x,y;cin>>x>>y;
            if(x!=y)
            merge(x,y);
        }
        else if(op=="Q1")
        {
            int x,y;cin>>x>>y;
            if(find(x)==find(y))cout<<"Yes\n";
            else cout<<"No\n";
        }
        else{
            int x;cin>>x;
            cout<<siz[find(x)]<<endl;
        }
    }
    return 0;
}