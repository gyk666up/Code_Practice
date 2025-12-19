// #include<bits/stdc++.h>
// using namespace std;
// //想到了树状数组 结果做不成来
// #define int long long
// const int N=1e7+11;
// int a[N];
// int id=0;
// //      /\          1
// //     /  \       -1 2
// //    /    \     -2 1.5 3
// void up(int x)//x是下标
// {
//     if(x==1)return;
//     if(a[x]>a[x/2])
//     {
//         swap(a[x],a[x/2]);
//         up(x/2);
//     }
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int q;cin>>q;
    
//     while(q--)
//     {
//         int op,x;cin>>op>>x;
//         if(op==5)
//         {
//             a[id]=x;
//             up(id);
//             id++;
//         }
//         else if(op==4)
//         {
//             for(int i=1;a[i]!=x;i++);
//             //此时 a[i]==x
//             cout<<a[2*i+1];
//         }
//     }

//     return 0;
// }

// //两个不用二叉树的方法
// //使用multiset
// //性质：（1）里面的元素按顺序排列，默认升序 都是默认升序的
// //(2)不去重 这是与set的区别
// multiset<int>q;
// //定义一个multiset，尖括号里写类型
// //如果是自定义类型，需要重载小于号 

// q.insert(x);
// //插入一个数 x 

// q.clear();
// //清空 

// q.erase(x);
// //删除容器中的所有值为 x 的数 

// q.erase(it);
// //删除容器中迭代器it指向的元素 

// q.empty();
// //返回bool值，如果容器为空返回true，否则返回false 

// q.size()
// //返回元素个数

// q.begin();
// //返回首个元素的迭代器 

// q.end();
// //返回最后一个元素的下一个位置的迭代器 

// q.count(x);
// //返回容器中 x 的个数 

// q.find(x);
// //返回容器中第一个x的位置（迭代器），如果没有就返回q.end() 

// q.lower_bound(x);
// //返回容器中第一个大于等于x的数的迭代器 

// q.upper_bound(x);
// //返回容器中第一个大于x的数的迭代器 


// #include<bits/stdc++.h>
// using namespace std;
// int n;
// multiset<int>q;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     q.insert(-0x7fffffff);
//     q.insert(0x7fffffff);
//     cin>>n;
//     while(n--)
//     {
//         int t,x;cin>>t>>x;
//         if(t==1)
//         {
//             auto it=q.lower_bound(x);//找到x的位置
//             int order=-1;
//             for(auto i=q.begin();i!=it;i++,order++);
//             order++;
//             cout<<order<<endl;
//         }
//         else if(t==2)
//         {
//             int order=-1;//初值为-1是因为前面有个-0x7fffffff,所以order要多跑一步
//             for(int i:q)
//             {
//                 if(++order==x)
//                 cout<<i<<endl;//i就是容器里的值
//             }
//         }
//         else if(t==3)
//         {
//             auto it=q.lower_bound(x);
//             cout<<(*--it)<<endl;//先找到x的迭代器 他的前一个位置就是x的前驱
//         }
//         else if(t==4)
//         {
//             cout<<*q.upper_bound(x)<<endl;//获得x后驱的迭代器 解引用输出即可就是排名
//         }
//         else
//         {
//             q.insert(x);
//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// multiset<int>q;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     q.insert(-0x7fffffff);
//     q.insert(0x7fffffff);
//     while(n--)
//     {
//         int op,x;cin>>op>>x;
//         if(op==1)
//         {
//          auto it=q.lower_bound(x);//找到x的位置
//             int order=-1;
//             for(auto i=q.begin();i!=it;i++,order++);
//             order++;
//             cout<<order<<endl;
//         }
//         else if(op==2)
//         {   //在其他地方这种写法没有问题 但这里不行
//            // auto it=upper_bound(q.begin(),q.end(),x)-q.begin();
//            int order=-1;
//             for(int i:q)
//             {
//                 if(++order==x)
//                 {
//                     cout<<i<<endl;
//                 }
//             }
//         }
//         else if(op==3)
//         {
//             auto it=q.lower_bound(x);
//             cout<<*--it<<endl;
//         }
//         else if(op==4)
//         {
//             auto it=q.upper_bound(x);
//             cout<<*it<<endl;
//         }
//         else
//         {
//             q.insert(x);
//         }
//     }
//     return 0;
// }



// //不熟
// // #include<bits/stdc++.h>
// // using namespace std;
// // multiset<int>q;

// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int m;cin>>m;
// //     q.insert(-0x7fffffff);
// //     q.insert(0x7fffffff);
// //     while(m--)
// //     {
// //         int op,x;cin>>op>>x;
// //         if(op==1)
// //         {
// //             int cnt=-1;
// //             auto it=q.lower_bound(x);
// //             for(auto i=q.begin();i!=it;i++)
// //             {
// //                 if(*i<x)cnt++;
// //             }
// //             cout<<cnt+1<<endl;
// //         }
// //         else if(op==2)
// //         {
// //             int order=-1;
// //             for(auto it=q.begin();it!=q.end();it++)
// //             {
// //                 order++;
// //                 if(order==x)cout<<*it<<endl;
// //             }
// //         }
// //         else if(op==3)
// //         {
// //             auto it=q.lower_bound(x);
// //             cout<<*--it<<endl;
// //         }
// //         else if(op==4)
// //         {
// //             auto it=q.upper_bound(x);
// //             cout<<*it<<endl;
// //         }
// //         else q.insert(x);
// //     }
// //     return 0;
// // }



// //超时了  可以优化一下 全用upper_bound (logn)
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int q;cin>>q;
//     vector<int>v;
//     v.push_back(-0x7fffffff);
//     v.push_back(0x7fffffff);
//     for(int i=1;i<=q;i++)
//     {
//         int op,x;cin>>op>>x;
//         sort(v.begin(),v.end());
        
//         if(op==1)
//         {
//             int cnt=-1;
//             for(int t:v)
//             {
//                 if(t<x)cnt++;
//             }
//             cout<<cnt+1<<endl;
//         }
//         else if(op==2)
//         {
//             int rank_=-1;
//             for(int t:v)
//             {
//                 rank_++;
//                 if(rank_==x)
//                 {
//                     cout<<t<<endl;
//                     break;
//                 }
//             }
//         }
//         else if(op==3)
//         {
//             // for(int i=0;i<v.size();i++)
//             // {
//             //     if(v[i]<x)continue;
//             //     else 
//             //     {
//             //         cout<<v[i-1]<<endl;
//             //         break;
//             //     }
//             // }
//             auto t=lower_bound(v.begin(),v.end(),x);
//             cout<<*--t<<endl;
//         }
//         else if(op==4)
//         {
//             // for(int i=0;i<v.size();i++)
//             // {

//             //     if(v[i]<=x)continue;
//             //     else
//             //     {
//             //         cout<<v[i]<<endl;
//             //         break;
//             //     }
//             // }
//             auto t=upper_bound(v.begin(),v.end(),x);
//             cout<<*t<<endl;
//         }
//         else v.push_back(x);
//     }
//     return 0;
// }
























