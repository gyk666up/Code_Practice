#include<bits/stdc++.h>
using namespace std;
const int N=1e5+66;
int a[N];
#define int long long //注意define前有个#
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,x;cin>>n>>x;
    for(int i=1;i<=n;i++)cin>>a[i];

    int ans=0;
    for(int i=1;i+1<=n;i++)
    {
        int temp=a[i]+a[i+1];
        if(temp<=x)continue;
        else 
        {
            ans+=(temp-x);//超过的都得吃掉
            //前提是a[i+1]够减 否则只能减a[i]
            // if(a[i+1]-(temp-x)>=0)
            // a[i+1]-=(temp-x);//吃中间的才有可以最小 （两边都可以影响到）
            // else 
            // a[i]-=(temp-x);

            //上面的不对
            //够减减a[i+1]
            //否则 先将a[i+1]=0 再减去剩下需要减的！！！
            if(a[i+1]-(temp-x)>=0)
            a[i+1]-=temp-x;
            else
            {
                int need=temp-x-a[i+1];
                a[i]-=need;
                a[i+1]=0;
            }
        }
    
    }
    cout<<ans<<endl;
    return 0;
}