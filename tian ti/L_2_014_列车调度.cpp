#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    vector<int>a;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        a.push_back(x);
    }

    vector<int>dp;
    for(auto t:dp)
    {
        auto it=lower_bound(dp.begin(),dp.end(),s);
        if(it==dp.end)
        {
            dp.push_back(s);
        }
        else
        {
            *it=s;
        }
    }
    cout<<dp.size();
}