#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+11;
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,c;cin>>n>>c;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans=0;
    // for(int i=1;i<=n;i++)
    // {
    //     int A=a[i]+c;
    //     ans+=mp[A];
    // }
    for(int i=1;i<=n;i++)
    {
        int B=a[i]-c;
        ans+=mp[B];
    }
    cout<<ans;
    
    return 0;
}