#include<bits/stdc++.h>
using namespace std;
int n;
const int N=30;
unordered_set<int>dp[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    dp[0].insert(0);
    for(int i=1;i<=n;i++)
    {
        for(int m=1;m<=i;m++)//平行组的数量
        {
            int remain=i-m;
            for(int j:dp[remain])
            {
                dp[i].insert(j+m*remain);
            }
        }
    }
    cout<<dp[n].size();
    return 0;
}