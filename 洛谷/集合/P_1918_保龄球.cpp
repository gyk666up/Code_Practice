// //用map高效查找 键为瓶子数 值为位置
// //秒了
// #include<bits/stdc++.h>
// using namespace std;
// map<int,int>mp;
// int main()
// {
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         mp[x]=i;
//     }
//     int m;cin>>m;
//     while(m--)
//     {
//         int x;cin>>x;
//         if(mp.count(x))cout<<mp[x]<<endl;
//         else cout<<0<<endl;
//     }
//     return 0;
// }