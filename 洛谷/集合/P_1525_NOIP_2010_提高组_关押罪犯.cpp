// //让最大的冲突影响力最小

// //学到了！！
// //第一种：拓展域并查集。
// // 1. 拓展域的设计意义
// // 每个罪犯 x 有两个 “状态域”：
// // x 代表 “x 在监狱 A”；
// // x + n 代表 “x 在监狱 B”。
// // 通过这两个域，我们可以用并查集表达 “对立关系”：若 u 和 v 有仇恨，必须分在不同监狱，则：
// // 若 u 在 A（u），则 v 必须在 B（v + n）→ 合并 u 和 v + n；
// // 若 u 在 B（u + n），则 v 必须在 A（v）→ 合并 u + n 和 v。
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+22;
// struct node
// {
//     int u,v,w;//一条边对应的两个人 以及仇恨值
//     bool operator<(const node&u)
//     {
//         return w>u.w;
//     }
// }edge[N];
// int n,m;
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
//     cin>>n>>m;
//     for(int i=1;i<=2*n;i++)fa[i]=i;//注意这个是与普通并查集唯一的区别
//     for(int i=1;i<=m;i++)
//     {
//         cin>>edge[i].u>>edge[i].v>>edge[i].w;
        
//     }
//     sort(edge+1,edge+1+m);
//     for(int i=1;i<=m;i++)
//     {
//         merge(edge[i].u+n,edge[i].v);
//         merge(edge[i].u,edge[i].v+n);

//         //当处理到某个仇恨关系时，如果发现：同一个罪犯的两个分身被绑定在了一起（比如罪犯 2 的 “A 房分身 2” 和 “B 房分身 6” 在同一个集合里），
//         //这就意味着 “罪犯 2 既得住 A 房，又得住 B 房”—— 这是不可能的！
//         //if(find(edge[i].u+n)==find(edge[i].u)||find(edge[i].v)==find(edge[i].v+n))
//         //可以简化成下面这种形式
//         if(find(edge[i].u)==find(edge[i].v))
//         {
//             cout<<edge[i].w;//当前的 w 就是 “无法避免的最大冲突”，因为我们是按仇恨值从大到小处理的，更大的冲突已被成功避免。
//             //贪心
//             return 0;
//         }
//     }
//     cout<<"0";
//     return 0;
// }



// //第二种：二分答案+二分图（染色问题）（以前在acwing上见过类似的题目）
// //有点抽象？  好好理解一下

// // 假设我们猜一个值 k，如果存在一种分配方案，能让所有仇恨值 >k 的罪犯都分在不同监狱
// // （即这些冲突都能避免），那么 所有比 k 大的值也一定可行（比如 k=3512 可行，那么 k=6618 更可行，
// // 因为需要避免的冲突更少了）。反过来，如果 k 不可行（即无论怎么分，都有仇恨值 > k 的罪犯在同一监狱），那么 所有比 k 小的值也一定不可行
// // （比如 k=2534 不可行，那么 k=1805 更不可行，因为需要避免的冲突更多了）。
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+22;
// struct node
// {
//     int u,v,w;
//     bool operator<(const node&u)
//     {
//         return w<u.w;
//     }
// }edge[N];
// vector<int>e[N];
// int color[N];
// bool flg;
// int n,m;
// void dfs(int x,int c)
// {
//     if(!flg)return;
//     color[x]=c;
//     for(int i=0;i<e[x].size();i++)
//     {
//         int v=e[x][i];
//         if(!color[v])dfs(v,c^1);//相邻的结点还没染色 就将它染成与自己不同的颜色
//         else if(color[v]==c)flg=false;
//     }
    
// }
//我们要找的最小k满足 ——所有权值 > k 的边，
//必须强制分在不同组（即构成二分图），而权值≤k的边无强制约束（可分可不分）
// bool check(int pos)//检查是否为二分图 
// {
//     for(int i=1;i<=n;i++)e[i].clear();//!!注意初始化
//     //最终构建的图中，边代表 “必须分不同监狱” 的约束，后续通过 “二分图染色” 判断这张图能否分成两个独立集（对应两座监狱）—— 
//     //如果能，说明 k 可行；如果不能，说明 k 太小。
//      check(pos) 的验证范围是 edge[pos+1] ~ edge[m]
//     for(int i=pos+1;i<=m;i++)//pos+1开始的关系影响力都是大于答案的 需要在两个监狱内
//     {
//         e[edge[i].u].push_back(edge[i].v);
//         e[edge[i].v].push_back(edge[i].u);
//     }
//     flg=true;
//     memset(color,0,sizeof color);
//     for(int i=1;i<=n;i++)
//     {
//         if(!color[i])
//         {
//             dfs(i,0);
//             if(!flg)return false;
//         }
//     }
//     return true;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>edge[i].u>>edge[i].v>>edge[i].w;
//     }
//     sort(edge+1,edge+1+m);
//     //edge[r].w是答案 
//     int l=0,r=m;
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))r=mid;
//         else l=mid;
//     }
//     if(m==1)
//     {
//         cout<<0;
//         return 0;
//     }
//     else cout<<edge[r].w;
//     return 0;
// }

