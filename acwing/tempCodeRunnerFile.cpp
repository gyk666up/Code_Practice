
// #include<bits/stdc++.h>
// using  namespace std;
// const int N=5e4+55;
// vector<int>g[N];
// int n,m,d;
// bool st[N];//标记防控地区
// bool vis[N];//标记是否访问过
// bool dfs(int s,int d)
// {
//     vis[s]=1;
//     if(s==d)return 1;
//     for(int it:g[s])
//     {
//         if(!vis[it])
//         dfs(it,d);
//     }
//     return 0;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>d;
//     for(int i=1;i<=m;i++)
//     {
//         int x,y;
//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     while(d--)
//     {
//         int c,q;cin>>c>>q;
//         st[c]=1;
//         int cnt=0;//当天有多少不能成行
//         while(q--)
//         {
//             int x,y;cin>>x>>y;
//             if(!dfs(x,y))//如果x不能到达y则
//             cnt++;
//         }
//         cout<<cnt<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int M=2e5+66;
vector<int> a[M];
const int D=1e3+22;
int n,m,d;
int lock[D];//存第i天封锁的机场编号
int p[M];//标记一个机场是否已经封锁了
typedef pair<int,int>PII;
int ans[D];//存第i天的答案
int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>d;
    vector<PII>query[D];//用来存第i天的所有查询
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=0;i<m;i++)
    {
        int s,t;cin>>s>>t;
        a[s].push_back(t);
        a[t].push_back(s);
    }
    for(int i=1;i<=d;i++)
    {
        int s,Q;cin>>s>>Q;
        lock[i]=s;
        p[s]=0;
        vector<PII>temp;
        for(int j=0;j<Q;j++){
            int w,t;cin>>w>>t;
            temp.push_back({w,t});
        }
        query[i]=temp;
    }
    for(int i=1;i<=n;i++)
    {
        if(p[i])
        {
            for(int j=0;j<a[i].size();j++)
            {
                int t=a[i][j];
                if(p[i])p[find(t)]=find(i);
            }
        }
    }
    for (int i = d; i >= 1; i--) {
        for (int j = 0; j < query[i].size(); j++) {
            auto t = query[i][j];
            if (find(t.first)!= find(t.second)|| find(t.first) == 0 || find(t.second) == 0) ans[i]++;
        }
        int s = lock[i];
        p[s] =s;
        for (int j = 0; j < a[s].size(); j++) {
            int t = a[s][j];//将lock[i]的所有非封锁邻边union
            if (p[t]) p[find(s)]= find(t);
        }
    }
    for (int i = 1; i <= d; i++) cout << ans[i]<<endl;
    return 0;
}

















