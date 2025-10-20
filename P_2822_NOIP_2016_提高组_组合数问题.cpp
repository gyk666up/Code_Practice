//不会！组合的代码不会写

//最简单的写法：不过只能得到很少一部分分数
#include<bits/stdc++.h>
using namespace std;
int t,k;
#define int long long
int ans=0;
int n,m;
inline int ck(int x)
{
    if(x==0)return 1;
    int sum=1;
    for(int i=1;i<=x;i++)sum*=i;
    return sum;
}
inline int C(int n,int m)
{
    return ck(n)/(ck(m)*ck(n-m));//组合数公式
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t>>k;
    while(t--)
    {
        ans=0;
        cin>>n>>m;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=min(i,m);j++)
            {
                if(C(i,j)%k==0)ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}