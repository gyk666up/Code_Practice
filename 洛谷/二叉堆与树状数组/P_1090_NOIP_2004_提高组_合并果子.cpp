// //秒了
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     priority_queue<int,vector<int>,greater<int>>q;
//     for(int i=0;i<n;i++)
//     {
//         int x;cin>>x;
//         q.push(x);
//     }
//     int ans=0;
//     while(q.size()>1)
//     {
//         int x=q.top();q.pop();
//         int y=q.top();q.pop();
//         ans+=x+y;
//         q.push(x+y);
//     }
//     cout<<ans;
//     return 0;
// }


