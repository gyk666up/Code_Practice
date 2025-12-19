// #include<bits/stdc++.h>
// using namespace std;
// //set 和 multiset 内部都是有序的（默认升序）set<int, greater<int>> s;  // 降序排列的set
// //set和multiset的区别
// //（1）set内部的元素唯一不可重复但是multiset可以
// //这道题并不适合用set 因为会破坏原本的顺序

// //map和unorder_map的区别
// //unordered_map内部是无序的 而map是有序的
// //这个无序是真的无序 并不是按照原本的顺序
// #define int long long
// const int N=1e5+11;//对应st数组只能最大标记1e5+11的数字再大就会re 并不是因为效率通不过
// bool st[N];
// int a[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)
//     {
//         // unordered_map<int,bool>mp;
//         // int n;cin>>n;
//         // for(int i=1;i<=n;i++)
//         // {
//         //     int x;cin>>x;
//         //     mp[x]=1;//如果键已经有了就不会再加了 不用判断语句
//         // }
//         // for(auto t:mp)
//         // {
//         //     cout<<t.first<<" ";
//         // }
//         // cout<<endl;
//         memset(st,0,sizeof st);
//         int n;cin>>n;
//         int id=0;
//         for(int i=1;i<=n;i++)
//         {
//             int x;cin>>x;
//             if(!st[x])
//             {
//                 a[++id]=x;
//                 st[x]=1;
//             }
//         }
//         for(int i=1;i<=id;i++)cout<<a[i]<<" ";
//         cout<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;
// int a[N];
// int  main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)
//     {
//         map<int,bool>mp;
//         // vector<int>a;
    
//         int n;cin>>n;
//         int id=0;
//         for(int i=0;i<n;i++)
//         {
//             int x;cin>>x;
//             if(mp.count(x))
//             {
//              continue;
//             }
//              mp[x]=1;
//             //a.push_back(x);
//             a[++id]=x;
//         }
//         //for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
//         for(int i=1;i<=id;i++)cout<<a[i]<<" ";
//         cout<<endl;
        
//     }

//     return 0;
// }



