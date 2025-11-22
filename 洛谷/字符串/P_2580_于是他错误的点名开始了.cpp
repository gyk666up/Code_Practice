// //秒了 哈哈哈哈哈😁
// #include<bits/stdc++.h>
// using namespace std;
// map<string,int>mp;
// map<string,int>dian;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         string s;cin>>s;
//         mp[s]=1;
//     }
//     int m;cin>>m;
//     while(m--)
//     {
//         string s;cin>>s;
//         if(mp.count(s))
//         {
//             //第一次点
//             if(dian[s]==0)
//             {
//                 cout<<"OK\n";
//                 dian[s]++;
//             }
//             else
//             {
//                 cout<<"REPEAT\n";
//             }
//         }
//         else
//         {
//             cout<<"WRONG\n";
//         }
//     }
//     return 0;
// }
