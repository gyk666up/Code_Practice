// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+66;
// struct node
// {
//     int time;
//     int value;
//     double pervalue;
//     bool operator<(const node&u)
//     {
//         return pervalue>u.pervalue;
//     }
// }dat[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>dat[i].time;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>dat[i].value;
//         dat[i].pervalue=(double)dat[i].value/dat[i].time;
//     }
//     sort(dat+1,dat+1+n);
//     int j=m;
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(j>dat[i].time)
//         {
//             j-=dat[i].time;
//             ans+=dat[i].value;    
//         }
//         else
//         {
//             break;
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+44;
int v[N],w[N];
int dp[N][N];
int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++ )cin>>w[i];
    for(int i=1;i<=n;i++)cin>>v[i];

    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=0;j--)
        {
            if(j<w[i])dp[i][j]=dp[i-1][j];
            else 
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[n][m];
}