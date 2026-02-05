// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// vector<int>v;
// int len;//标记长度
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int op;cin>>op;
//         if(op==1)
//         {
//             int x;cin>>x;
//             v.push_back(x);
//             len++;
//         }
//         else
//         {
//             sort(v.begin(),v.end());
//             if(op==2)
//             {
//                 cout<<v[0]<<endl;
//             }
//             else
//             {
//                 for(int i=1;i<len;i++)
//                 v[i-1]=v[i];
//                 len--;
//             }
//         }
//     }
//     return 0;
// }



// //超时
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long

// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     vector<int> v;
    
//     for(int i=0;i<n;i++)
//     {
//         int op;cin>>op;
//         if(op==1)
//         {
//             int x;cin>>x;
//             v.push_back(x);
//         }
//         else if(op==2)
//         {
//             if(!v.empty())
//             {
//                 sort(v.begin(),v.end());
//                 cout<<v[0]<<endl;
//             }
//             // 可添加空vector处理逻辑
//         }
//         else if(op==3)
//         {
//             if(!v.empty())
//             {
//                 sort(v.begin(),v.end());
                
//                 //注意这个用法还是第一次见到
//                 v.erase(v.begin()); // 正确删除第一个元素
//                 //v.erase(v.begin())是删除 vector 第一个元素的标准、安全且高效的方法。
//             }
//             // 可添加空vector处理逻辑
//         }
//         // 可添加无效操作码处理逻辑
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     priority_queue<int,vector<int>,greater<int>>q;
//     int n;cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         int op;cin>>op;
//         if(op==1)
//         {
//             int x;cin>>x;
//             q.push(x);
//         }
//         else if(op==2)
//         {
//             cout<<q.top()<<endl;
//         }
//         else 
//         {
//             q.pop();
//         }
//     }
//     return 0;
// }




