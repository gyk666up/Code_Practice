#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+11;
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int cnt=0;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(sum+a[i]<=k)
        {
            cnt++;
            sum+=a[i];
        }
        else break;
    }
    cout<<cnt;
    return 0;
}