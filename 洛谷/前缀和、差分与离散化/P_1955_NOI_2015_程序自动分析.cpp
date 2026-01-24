// // // //想法是正确的 但是不允许 数组开不到那么大
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // const int N=1e8+11;
// // // //并查集 判断是否在e=1 里面的
// // // int fa[N];
// // // int find(int x)
// // // {
// // //     if(fa[x]==x)return x;
// // //     return fa[x]=find(fa[x]);
// // // }
// // // void merge(int x,int y)
// // // {
// // //     int xx=find(x),yy=find(y);
// // //     if(xx==yy)return ;
// // //     fa[yy]=xx;
// // // }
// // // int main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     int t;cin>>t;
// // //     while(t--)
// // //     {
// // //         int n;cin>>n;
// // //         vector<pair<int,int>>v;
// // //         for(int i=1;i<=n;i++)fa[i]=i;
// // //         for(int i=0;i<n;i++)
// // //         {
// // //             int x,y,e;cin>>x>>y>>e;
// // //             if(e==1)
// // //             {
// // //                 merge(x,y);
// // //             }
// // //             else
// // //             {
// // //                 v.push_back({x,y});
// // //             }
// // //         }
// // //         bool flg=1;
// // //         for(int i=0;i<v.size();i++)
// // //         {
// // //             int x=v[i].first;
// // //             int y=v[i].second;
// // //             if(find(x)==find(y))
// // //             {
// // //                 flg=0;
// // //                 break;
// // //             }
// // //         }
// // //         if(flg)cout<<"YES\n";
// // //         else cout<<"NO\n";
// // //     }
// // //     return 0;
// // // }


// // //将大的数字转化成索引
// // #include<bits/stdc++.h>
// // using namespace std;
// // vector<pair<int,int>>eq;
// // vector<pair<int,int>>neq;
// // vector<int>all;
// // const int N=2e5+11;
// // int fa[N];
// // int find(int x)
// // {
// //     if(fa[x]==x)return x;
// //     return fa[x]=find(fa[x]);
// // }
// // void merge(int x,int y)
// // {
// //     int xx=find(x),yy=find(y);
// //     if(xx==yy)return;
// //     fa[yy]=xx;
// // }
// // int discretize(int x)
// // {
// //     return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int t;cin>>t;
// //     while(t--)
// //     {
// //         int n;cin>>n;
// //         eq.clear();neq.clear();//all也得清空
// //         all.clear();
// //         for(int i=0;i<n;i++)
// //         {
// //             int a,b,e;cin>>a>>b>>e;
// //             all.push_back(a);
// //             all.push_back(b);
// //             if(e==1)eq.push_back({a,b});
// //             else neq.push_back({a,b});
// //         }
// //         //收集元素→排序→去重→确定 m（去重后大小）→初始化 fa
// //         sort(all.begin(),all.end());
        
        
// //         all.erase(unique(all.begin(),all.end()),all.end());
// //         int m=all.size();

// //         for(int i=1;i<=m;i++)fa[i]=i;
// //         for(int i=0;i<eq.size();i++)
// //         {
// //             int x=discretize(eq[i].first);
// //             int y=discretize(eq[i].second);
// //             merge(x,y);
// //         }
// //         bool flg=1;
// //         for(int i=0;i<neq.size();i++)
// //         {
// //             int x=discretize(neq[i].first);
// //             int y=discretize(neq[i].second);
// //             if(find(x)==find(y))
// //             {
// //                 flg=0;
// //                 break;
// //             }
// //         }
// //         cout<<(flg?"YES\n":"NO\n");
// //     }
// //     return 0;
// // }




// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;
// vector<pair<int,int>>eq;
// vector<pair<int,int>>neq;
// vector<int>all;
// int fa[N];
// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }

// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return ;
//     fa[yy]=xx;
// }
// int discretize(int x)
// {
//     //判断x的下标（下标是从1开始的）
//     return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)
//     {
//         int n;cin>>n;
//         all.clear();
//         eq.clear();neq.clear();
//         for(int i=0;i<n;i++)
//         {
//             int x,y,e;cin>>x>>y>>e;
//             if(e==1)eq.push_back({x,y});
//             else neq.push_back({x,y});
//             all.push_back(x);
//             all.push_back(y);
//         }
//         sort(all.begin(),all.end());
//         all.erase(unique(all.begin(),all.end()),all.end());
//         int m=all.size();
//         for(int i=1;i<=m;i++)fa[i]=i;
//         for(int i=0;i<eq.size();i++)
//         {
//             int x=discretize(eq[i].first);
//             int y=discretize(eq[i].second);
//             merge(x,y);
//         }
//         bool flg=1;
//         for(int i=0;i<neq.size();i++)
//         {
//             int x=discretize(neq[i].first);
//             int y=discretize(neq[i].second);
//             if(find(x)==find(y))
//             {
//                 flg=0;
//                 break;
//             }
//         }
//         cout<<(flg?"YES\n":"NO\n");
//     }
//     return 0;
// }




//这道题还是不会
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
vector<PII>eq;
vector<PII>neq;
vector<int>all;
const int N=2e5+11;
int fa[N];
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    if(xx==yy)return ;
    fa[yy]=xx;
}
int discretize(int x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        eq.clear();
        neq.clear();
        all.clear();
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {
            int a,b,e;cin>>a>>b>>e;
            if(e==1)
            {
                eq.push_back({a,b});
            }
            else
            neq.push_back({a,b});

            all.push_back(a);
            all.push_back(b);
        }
        sort(all.begin(),all.end());

        all.erase(unique(all.begin(),all.end()),all.end());

        int m=all.size();
        for(int i=1;i<=m;i++)fa[i]=i;//并查集注意初始化
        for(int i=0;i<eq.size();i++)
        {
            int x=discretize(eq[i].first);
            int y=discretize(eq[i].second);
            merge(x,y);
        }

        bool flg=1;
        for(int i=0;i<neq.size();i++)
        {
            int x=discretize(neq[i].first);
            int y=discretize(neq[i].second);

            if(find(x)==find(y))
            {
                flg=0;
                break;
            }
        }
        if(flg)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}