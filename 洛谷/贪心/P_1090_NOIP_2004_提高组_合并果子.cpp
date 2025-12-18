// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     priority_queue<int,vector<int>,greater<int>>pq;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         pq.push(x);
//     }
//     int ans=0;
//     while(pq.size()>1)
//     {
//         int x=pq.top();pq.pop();
//         int y=pq.top();pq.pop();
//         ans+=x+y;
//         pq.push(x+y);
//     }
//     cout<<ans<<endl;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int N=2e4+11;
int a[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        q.push(x);
    }
    int ans=0;
    while(q.size()>1)
    {
        int x=q.top();q.pop();
        int y=q.top();q.pop();
        ans+=x+y;
        q.push(x+y);
    }
    cout<<ans;
    return 0;
}