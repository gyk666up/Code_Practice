// // #include<bits/stdc++.h>
// // using namespace std;
// // int n,q;
// // const int N=1e8+1;
// // bool is_prime[N];
// // int prime[N];
// // map<int,int>mp;//记录素数的位置和大小
// // void solve()
// // {
// //     memset(is_prime,1,sizeof is_prime);
// //     is_prime[0]=is_prime[1]=0;
// //     // for(int i=2;i<=n;i++)
// //     // {
// //     //     if(is_prime[i])
// //     //     {
// //     //         for(int j=2;i*j<=n;j++)
// //     //         {
// //     //             is_prime[i*j]=0;
// //     //         }
// //     //     }
// //     // }

// //     //优化版
// //     for(int i=2;i*i<=n;i++)
// //     {
// //         if(is_prime[i])
// //         {
// //             for(int j=i*i;j<=n;j+=i)
// //             {
// //                 is_prime[j]=false;
// //             }
// //         }
// //     }
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>q;
// //     solve();

// //     int id=1;

// //     //这样写怎么会超时
// //     // for(int i=2;i<=n;i++)
// //     // {
// //     //     if(is_prime[i])mp[id++]=i;//这里容易写错mp[id++]=is_prime[i];
// //     // }

// //     for(int i=2;i<=n;i++)
// //     {
// //         if(is_prime[i])prime[id++]=i;
// //     }
// //     while(q--)
// //     {
// //         int k;cin>>k;
// //         // cout<<mp[k]<<endl;
// //         cout<<prime[k]<<endl;
// //     }
// //     return 0;
// // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // int n,q;
// // const int N=1e8+1;
// // bool is_prime[N];
// // int prime[N];
// // //如果理解不了的话 就死死的记下来
// // void find_isprime()
// // {
// //     memset(is_prime,1,sizeof is_prime);
// //     is_prime[0]=is_prime[1]=0;
// //     for(int i=2;i*i<=n;i++)
// //     {
// //         if(is_prime[i])
// //         {
// //             for(int j=i*i;j<=n;j+=i)
// //             {
// //                 is_prime[j]=0;
// //             }
// //         }
// //     }
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>q;
// //     find_isprime();
// //     int id=0;
// //     for(int i=1;i<=n;i++)
// //     {
// //         if(is_prime[i])
// //         {
// //             prime[++id]=i;
// //         }
// //     }
// //     while(q--)
// //     {
// //         int k;cin>>k;
// //         cout<<prime[k]<<endl;
// //     }
// //     return 0;
// // }



// //没太大问题 就是这个素数筛的时候要牢记
// //这段代码用 map 会 TLE，不是因为查询慢，而是因为「插入 + 红黑树常数巨大」；
// //用数组不会，是因为「顺序存 + O(1) 访问 + 常数极小」
// #include<bits/stdc++.h>
// using namespace std;
// int n,q;
// const int N=1e8+11;
// bool is_prime[N];
// //map<int,int>mp;//记录素数的位置
// int prime[N];
// void isprime()
// {
//     memset(is_prime,1,sizeof is_prime);
//     is_prime[0]=is_prime[1]=0;
//     for(int i=2;i*i<=n;i++)
//     {
//         if(is_prime[i])
//         {
//             for(int j=i*i;j<=n;j+=i)
//             {
//                 is_prime[j]=0;
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>q;
//     isprime();
//     int id=1;
//     for(int i=1;i<=n;i++)
//     {
//         if(is_prime[i])
//         {
//             //mp[id++]=i;
//             prime[id++]=i;
//         }
//     }
//     while(q--)
//     {
//         int x;cin>>x;
//         cout<<prime[x]<<endl;
//     }
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e8+11;
// int n,q;
// bool is_prime[N];
// //写错了 
// // void find_prime()
// // {
// //     is_prime[0]=is_prime[1]=0;
// //     for(int i=2;i*i<=n;i++)
// //     {
// //         is_prime[i]=1;
// //         for(int j=i*i;j<=n;j+=i)
// //         {
// //             is_prime[j]=0;
// //         }
// //     }
// // }
// int prime[N];
// void find_prime()
// {
//     memset(is_prime,1,sizeof is_prime);
//     is_prime[0]=is_prime[1]=0;
//     for(int i=2;i*i<=n;i++)
//     {
//         if(is_prime[i])
//         {
//             for(int j=i*i;j<=n;j+=i)
//             {
//                 is_prime[j]=0;
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>q;
//     find_prime();
//     map<int,int>mp;
//     int id=1;
//     for(int i=1;i<=n;i++)
//     {
//         if(is_prime[i])
//         prime[id++]=i;
//     }
//     while(q--)
//     {
//         int x;cin>>x;
//         cout<<prime[x]<<endl;
//     }
//     return 0;
// }


