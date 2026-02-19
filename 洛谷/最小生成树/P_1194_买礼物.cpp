// //错误的
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1001;
// // int fa[N];
// // int a,b;
// // struct edge
// // {
// //     int x,y,w;
// //     bool operator<(const edge u)
// //     {
// //         return w<u.w;
// //     }
// // };
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

// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>a>>b;
// //     vector<edge>edges(b+1);
// //     for(int i=1;i<=b;i++)fa[i]=i;
// //     for(int i=0;i<b;i++)
// //     {
// //         cin>>edges[i].x>>edges[i].y>>edges[i].w;
// //     }
// //     //sort(edges,edges+b);
// //     sort(edges.begin(),edges.end());
// //     int ans=0;
// //     int cnt=0;
// //     for(int i=0;i<b;i++)
// //     {
// //         int x=edges[i].x;
// //         int y=edges[i].y;
// //         if(find(x)!=find(y))
// //         {
// //             merge(x,y);
// //             cnt++;
// //             ans+=edges[i].w;
// //         }
// //         if(cnt==b-1)break;
// //     }
// //     cout<<a+ans;
// //     return 0;
// // }


// // 你做 MST 题时的「一眼识别法」
// // 以后看到类似描述，直接条件反射：
// // ✅ 每个东西只需“连接一次”
// // ✅ 有“单独成本”
// // ✅ 有“成对优惠”
// // 👉 MST + 虚拟点

// // //买第一个东西一定要花 A 元
// // #include <bits/stdc++.h>
// // using namespace std;

// // struct Edge {
// //     int u, v, w;
// //     bool operator<(const Edge& e) const {
// //         return w < e.w;
// //     }
// // };

// // const int N = 505;
// // int fa[N];

// // int find(int x) {
// //     if (fa[x] == x) return x;
// //     return fa[x] = find(fa[x]);
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(nullptr);

// //     int A, B;
// //     cin >> A >> B;

// //     vector<Edge> edges;

// //     // 并查集初始化（0 ~ B）
// //     for (int i = 0; i <= B; i++) fa[i] = i;

// //     // 虚拟点 0 → i,单买 = 从“起点”连一条边,含义：作为第一个买的物品
// //     for (int i = 1; i <= B; i++) {
// //         edges.push_back({0, i, A});
// //     }

// //     // 优惠边
// //     for (int i = 1; i <= B; i++) {
// //         for (int j = 1; j <= B; j++) {
// //             int k;
// //             cin >> k;
// //              //如果 K_{i,j} = 0，表示这两样东西之间不会导致优惠,不是“免费”，而是“没有这条优惠边”,如果把k=0加进来的话，意味着可以0成本买一个东西
// //             if (i < j && k > 0) {
// //                 edges.push_back({i, j, k});
// //             }
// //         }
// //     }

// //     sort(edges.begin(), edges.end());

// //     int ans = 0, cnt = 0;

// //     for (auto &e : edges) {
// //         int fu = find(e.u);
// //         int fv = find(e.v);
// //         if (fu != fv) {
// //             fa[fu] = fv;
// //             ans += e.w;
// //             cnt++;
// //             if (cnt == B) break; // B+1 个点，需要 B 条边
// //         }
// //     }

// //     cout << ans;
// //     return 0;
// // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=520;
// // struct Edge
// // {
// //     int x,y,w;
// //     bool operator<(const Edge&u)
// //     {
// //         return w<u.w;
// //     }
// // };
// // int a,b;
// // int fa[N];
// // int find(int x)
// // {
// //     if(fa[x]==x)return x;
// //     return fa[x]=find(fa[x]);
// // }
// // void merge(int x,int y)
// // {
// //     int xx=find(x),yy=find(y);
// //     if(xx==yy)return ;
// //     fa[yy]=xx;
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>a>>b;
// //     vector<Edge>edge(b);
// //     for(int i=1;i<=b;i++)fa[i]=i;
// //     //虚拟节点
// //     for(int i=1;i<=b;i++)
// //     {
// //         edge.push_back({0,i,a});//这个用法不熟
// //     }

// //     for(int i=1;i<=b;i++)
// //     {
// //         for(int j=1;j<=b;j++)
// //         {
// //             int x;cin>>x;
// //             if(x>0)//这一行代码非常关键，i<j可加可不加 只影响效率
// //             edge.push_back({i,j,x});
// //         }
// //     }
// //     sort(edge.begin(),edge.end());

// //     int ans=0,cnt=0;
// //     for(int i=0;i<edge.size();i++)
// //     {
// //         int x=edge[i].x,y=edge[i].y,w=edge[i].w;
// //         if(find(x)!=find(y))
// //         {
// //             merge(x,y);
// //             ans+=w;
// //             cnt++;
// //         }
// //         if(cnt==b)break;
// //     }
// //     cout<<ans;
// //     return 0;
// // }

// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=520;
// // struct Edge
// // {
// //     int x,y,w;
// //     bool operator<(const Edge&u)
// //     {
// //         return w<u.w;
// //     }
// // };
// // int a,b;
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
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>a>>b;

// //     for(int i=1;i<=b;i++)fa[i]=i;
// //     vector<Edge>edge;
// //     //这里也很容易错 这一行 已经创建了 b 个“垃圾边”（值全是 0）。
// //     //后面就不能用push_back了 但可以用cin覆盖他们
// //     for(int i=1;i<=b;i++)
// //     {
// //         edge.push_back({0,i,a});
// //     }
// //     for(int i=1;i<=b;i++)
// //     {
// //         for(int j=1;j<=b;j++)
// //         {
// //             int k;cin>>k;
// //             if(i<j&&k>0)
// //             edge.push_back({i,j,k});
// //         }
// //     }
// //     sort(edge.begin(),edge.end());

// //     int ans=0;
// //     int cnt=0;
// //     for(int i=0;i<edge.size();i++)
// //     {
// //         int x=edge[i].x,y=edge[i].y,w=edge[i].w;
// //         if(find(x)!=find(y))
// //         {
// //             ans+=w;
// //             cnt++;
// //             merge(x,y);
// //         }
// //         if(cnt==b)break;
// //     }
// //     cout<<ans;
// //     return 0;
// // }

