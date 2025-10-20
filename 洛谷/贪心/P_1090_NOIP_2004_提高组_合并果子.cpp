#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        pq.push(x);
    }
    int ans=0;
    while(pq.size()>1)
    {
        int x=pq.top();pq.pop();
        int y=pq.top();pq.pop();
        ans+=x+y;
        pq.push(x+y);
    }
    cout<<ans<<endl;
}