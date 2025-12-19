#include<bits/stdc++.h>
using namespace std;
const int N=1001;
int a[N],prefix[N];
bool st[N];//标记有的可能的情况
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    // for(int i=1;i<=n;i++)
    // prefix[i]=prefix[i-1]+a[i];
    // //计算长度为4区间的所有可能性
    // for(int i=4;i<=n;i++)
    // {
    //     st[prefix[i]-prefix[i-4]]=1;
    // }
    //不对 不一定是连续的

    //!!!
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(int u=j+1;u<=n;u++)
            {
                for(int v=u+1;v<=n;v++)
                {
                    int sum=a[i]+a[j]+a[u]+a[v];
                    st[sum]=1;
                }
            }
        }
    }
    while(k--)
    {
        int m;cin>>m;
        bool f=1;
        int sum=0;
        for(int i=1;i<=m;i++)
        {
            int x;cin>>x;
            if(!st[x*4])f=0;
        }
        if(f)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}