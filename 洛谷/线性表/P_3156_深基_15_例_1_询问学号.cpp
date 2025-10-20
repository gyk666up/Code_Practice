//脑残题
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+11;
int s[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>s[i];
    while(m--)
    {
        int x;cin>>x;
        cout<<s[x]<<endl;
    }
    return 0;
}