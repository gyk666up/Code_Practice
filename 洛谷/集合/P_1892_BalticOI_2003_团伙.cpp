// //第一眼觉得是并查集
// //又觉得是扩展并查集（感觉到位 但是还是没写出来）

// // 用 x 代表 “x 本人”，用 x + n 代表 “x 的敌人”（n 是总人数）。通过这两个 “域”，可以将对立关系转化为等价关系：
// // 若 x 和 y 是敌人，则 x 的敌人（x+n）与 y 是朋友（需合并），y 的敌人（y+n）与 x 是朋友（需合并）；
// // 若 x 和 y 是朋友，则直接合并 x 和 y。
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e3+11;
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
//     fa[yy]=xx;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=2*n;i++)fa[i]=i;
//     for(int i=1;i<=m;i++)
//     {
//         char op;int p,q;cin>>op>>p>>q;
//         if(op=='F')
//         {
//             merge(p,q);
//         }
//         else
//         {
//             merge(p+n,q);
//             merge(p,q+n);
//             //这里改变一下合并的顺序 也不用利用set了
//         }
//     }
//     int cnt=0;
//     //for(int i=1;i<=2*n;i++)if(fa[i]==i)cnt++;
//     //只统计 1~n（本人域）：因为 n+1~2n 是 “敌人域”，仅用于维护关系，不对应真实的人，真实的团伙由 “本人” 构成
//     //for(int i=1;i<=n;i++)if(fa[i]==i)cnt++;
//     //统计团伙时仅关注本人域的根节点，忽略了敌人域中根节点对应的团伙（不对的）
//     //还是不对 这时候fa数字可能失效了
//     //for(int i=1;i<=n;i++)if(find(i)==i)cnt++;


//     //理解这样写的原理
//     // 正确统计：收集所有本人节点的根，去重后计数
//     unordered_set<int> roots;
//     for(int i=1;i<=n;i++){
//         roots.insert(find(i)); // 插入每个本人节点的根（无论根在哪个域）
//     }
//     cout<<roots.size(); // 不同根的数量即团伙数
//     return 0;
//     // cout<<cnt;
//     // return 0;
// }




//这段代码直接就是对的 原因在于合并的方向
//这段代码的 “无问题” 本质是 合并方向的正确性：
//通过将敌人域节点的根合并到本人域节点，确保所有本人节点的根都在本人域内。
// #include<bits/stdc++.h>
// using namespace std;
// int s,n,m,a,b,f[2500];
// char ch;
// int find(int x){
//     if(f[x]!=x)f[x]=find(f[x]);//查找+路径压缩，如果没有祖先就回溯
//     return f[x];
// }
// int main(){
//     cin>>n>>m;
//     for(int i=1;i<=2*n;i++){
//         f[i]=i;//初始化，千万不能漏
//     }
//     for(int i=1;i<=m;i++){
//         cin>>ch>>a>>b;
//         if(ch=='F'){
//             f[find(a)]=find(b);//合并
//         }else{
//             f[find(a+n)]=find(b);
//             f[find(b+n)]=find(a);//反集合并
//         }
//     }
//     for(int i=1;i<=n;i++){
//         if(f[i]==i)s++;
//     }
//     cout<<s;//祖先数就是团伙数
// }


#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=5e3+11;
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
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        char op;int u,v;cin>>op>>u>>v;
        if(op=='F')
        {
            merge(u,v);
        }
        else
        {
            merge(u,v+n);
            merge(v,u+n);
        }
    }
    int cnt=0;
    set<int>q;
    for(int i=1;i<=n;i++)q.insert(find(i));
    cout<<q.size();
    return 0;
}