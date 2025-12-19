// //怎么感觉有点像扩展并查集
// 代码错误点	正确做法
// 未读入 i,j,e	必须用 cin>>i>>j>>e 读入约束数据
// i,j 直接用做大数组索引	离散化：映射到 1~2n 的小范围
// 边读边处理约束	先收集所有约束，再先处理 e=1，后检查 e=0
// 误用扩展并查集处理 e=0	不等约束无需合并，仅检查是否在同一集合
// fa 初始化范围错误	按离散化后的大小（m）初始化
// 输出大小写错误	严格输出 YES 或 NO（全大写）
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
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

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)
//     {
//         int n;cin>>n;
//         for(int i=1;i<=2*n;i++)fa[i]=i;
//         bool flg=1;
//         for(int k=0;k<n;k++)
//         {
//             if(!flg)break;
//             int i,j,e;cin>>i>>j>>e;
//             if(e==1)
//             {
//                 merge(i,j);
//             }
//             else
//             {
//                 merge(i,j+n);
//                 merge(j,i+n);

//                 if(find(i)==find(j))
//                 {
//                     cout<<"NO\n";
//                     flg=0;
//                 }
//             }
//         }
//         if(flg)cout<<"YES\n";
//     }
    
//     return 0;
// }



//正解
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;  // 最多2e5个离散化后的值
// int fa[N];
// vector<pair<int, int>> eq;  // 存储e=1的约束（i,j的离散化后值）
// vector<pair<int, int>> neq; // 存储e=0的约束（i,j的离散化后值）
// vector<int> all;  // 存储所有出现的i,j，用于离散化

// int find(int x) {
//     if(fa[x]==x) return x;
//     return fa[x]=find(fa[x]);
// }

// void merge(int x, int y) {
//     int xx=find(x), yy=find(y);
//     if(xx!=yy) fa[yy]=xx;
// }

// // 离散化函数：将x映射到1~m的连续整数
// int discretize(int x) {
//     return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
// }

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int t; cin>>t;
//     while(t--) {
//         int n; cin>>n;
//         // 初始化：清空上一轮的约束和离散化数据
//         eq.clear(); neq.clear(); all.clear();
//         for(int k=0;k<n;k++) {
//             int i,j,e; cin>>i>>j>>e;  // 正确读入变量
//             // 收集所有i,j，用于后续离散化
//             all.push_back(i); all.push_back(j);
//             if(e==1) {
//                 eq.emplace_back(i,j);  // 存储相等约束
//             } else {
//                 neq.emplace_back(i,j); // 存储不等约束
//             }
//         }
//         // 离散化：去重+排序，确保每个值映射唯一
//         sort(all.begin(), all.end());
//         all.erase(unique(all.begin(), all.end()), all.end());
//         int m=all.size();  // 离散化后的最大索引
//         // 初始化并查集（按离散化后的大小）
//         for(int i=1;i<=m;i++) fa[i]=i;
//         // 第一步：处理所有相等约束
//         for(auto [i,j] : eq) {
//             int x=discretize(i), y=discretize(j);
//             merge(x,y);
//         }
//         // 第二步：检查所有不等约束
//         bool flg=1;
//         for(auto [i,j] : neq) {
//             int x=discretize(i), y=discretize(j);
//             if(find(x)==find(y)) {  // 已合并却不等，冲突
//                 flg=0;
//                 break;
//             }
//         }
//         // 正确输出大小写
//         cout<<(flg?"YES":"NO")<<'\n';
//     }
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// vector<pair<int,int>>eq;
// vector<pair<int,int>>neq;
// vector<int> all;  // 存储所有出现的i,j，用于离散化
// const int N=2e5+11;
// int fa[N];
// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return;
//      fa[yy]=xx;
// }
// int discretize(int x)//转为 1-based 索引
// {
//     return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)
//     {
//         int n;cin>>n;
//         // for(int i=1;i<=n;i++)fa[i]=i;
//         eq.clear();neq.clear();all.clear();
//         for(int i=0;i<n;i++)
//         {
//             int a,b,e;cin>>a>>b>>e;
//             all.push_back(a);
//             all.push_back(b);
//             if(e==1)eq.push_back({a,b});
//             else neq.push_back({a,b});
//         }
       
//         //这行代码的核心是 **“排序后去重”**：很常见
// // 先通过 sort 使相同元素相邻；
// // 再通过 unique 将重复元素移到末尾；
// // 最后通过 erase 彻底删除重复元素，只保留唯一值。
//         sort(all.begin(),all.end());
//         all.erase(unique(all.begin(),all.end()),all.end());
//         int m=all.size();

//         for(int i=1;i<=m;i++)fa[i]=i;
//         //必须先处理完e=1

//          bool flg=1;
//         for(pair<int,int> t:eq)
//         {
//             int x=discretize(t.first);
//             int y=discretize(t.second);
//             merge(x,y);
//         }
//         for(pair<int,int>t:neq)
//         {
//             int x=discretize(t.first);
//             int y=discretize(t.second);
//             if(find(x)==find(y))
//             {
//                 cout<<"NO\n";
//                 flg=0;
//                 break;
//             }
//         }
//         if(flg)cout<<"YES\n";
//     }
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>eq;
vector<pair<int,int>>neq;
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
    if(xx==yy)return;
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
        int n;cin>>n;
        eq.clear();neq.clear();//all也得清空
        all.clear();
        for(int i=0;i<n;i++)
        {
            int a,b,e;cin>>a>>b>>e;
            all.push_back(a);
            all.push_back(b);
            if(e==1)eq.push_back({a,b});
            else neq.push_back({a,b});
        }
        //收集元素→排序→去重→确定 m（去重后大小）→初始化 fa
        sort(all.begin(),all.end());
        int m=all.size();
        
        all.erase(unique(all.begin(),all.end()),all.end());

        for(int i=1;i<=m;i++)fa[i]=i;
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
        cout<<(flg?"YES\n":"NO\n");
    }
    return 0;
}