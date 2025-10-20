#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans1,ans2;//矩形个数，正方形个数
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans1+=i*j;
            ans2+=min(i,j);
        }
    }
    cout<<ans2<<" "<<ans1-ans2<<endl;
    return 0;
}