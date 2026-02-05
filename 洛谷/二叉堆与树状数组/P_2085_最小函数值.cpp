//没思路
//函数性质：每个函数 \(F_i(x) = A_i x^2 + B_i x + C_i\)（\(A_i > 0\)）是开口向上的二次函数，在 \(x \in \mathbb{N}^*\) 范围内单调递增（因为抛物线对称轴 \(x = -B_i/(2A_i) \leq 0\)，x≥1 时函数值随 x 增大而递增）。


//方法一
// #include<bits/stdc++.h>
// using namespace std;

// // 堆中存储的元素：函数值val、函数索引idx、当前x值
// struct Node {
//     int val, idx, x;
//     Node(int v, int i, int x_) : val(v), idx(i), x(x_) {}
//     // 重载小于号，实现小顶堆（默认是大顶堆）
//     bool operator<(const Node& other) const {
//         return val > other.val;
//     }
// };

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int n, m;
//     cin >> n >> m;
//     vector<int> A(n), B(n), C(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> A[i] >> B[i] >> C[i];
//     }

//     priority_queue<Node> pq;
//     // 初始化：将每个函数x=1时的函数值加入堆
//     for (int i = 0; i < n; ++i) {
//         int val = A[i] * 1 + B[i] * 1 + C[i]; // x=1时，x²=1
//         pq.emplace(val, i, 1);
//     }

//     vector<int> res;
//     // 取前m个最小值
//     for (int i = 0; i < m; ++i) {
//         auto top = pq.top();
//         pq.pop();
//         res.push_back(top.val);

//         //核心每次取最小后，都为该函数补充下一个候选值，保证堆里始终有 “所有函数的最新最小候选值”，这样每次取堆顶都是当前全局最小。
//         // 计算该函数x+1时的函数值，加入堆
//         int idx = top.idx;
//         int next_x = top.x + 1;
//         int next_val = A[idx] * next_x * next_x + B[idx] * next_x + C[idx];
//         pq.emplace(next_val, idx, next_x);
//     }

//     // 输出结果
//     for (int i = 0; i < m; ++i) {
//         if (i > 0) cout << " ";
//         cout << res[i];
//     }
//     cout << endl;

//     return 0;
// }


//emplace的作用是直接在容器的内存空间中构造对象—— 它接收的不是 “现成的对象”，而是对象构造函数所需的参数，然后在容器内部直接调用构造函数创建对象，不需要临时对象，也避免了拷贝 / 移动的开销。
//push的作用是将一个已经完整构造的对象（可以是左值或右值）拷贝 / 移动到容器的内存空间中。
// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     int val,idx,x;
//     //注意这种用法 初始化函数，平常没怎么用过 
//     node(int v,int i,int x_):val(v),idx(i),x(x_){};
//     //这个重载注意一下 而且是两个const必须有 这点与以往的有些许不同（priority_queue优先队列的特殊）
//     bool operator<(const node &u)const
//     {
//         return val>u.val;
//     }

// };
// int n,m;

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     vector<int>A(n),B(n),C(n);
//     for(int i=0;i<n;i++)cin>>A[i]>>B[i]>>C[i];
//     priority_queue<node>q;
//     for(int i=0;i<n;i++)
//     {
//         int val=A[i]*1+B[i]*1+C[i];
//         q.emplace(val,i,1);
//     }
//     vector<int>res;//取前m个数
//     for(int i=0;i<m;i++)
//     {
//         node top=q.top();q.pop();
//         res.push_back(top.val);

        
//         int next=top.x+1;
//         int val=A[top.idx]*next*next+B[top.idx]*next+C[top.idx];
//         //q.push(val,top.idx,next);
//         q.emplace(val,top.idx,next);
//     }
//     for(int i=0;i<m;i++)
//     {
//         cout<<res[i]<<" ";
//     }
//     return 0;
// }

// //方法二

// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <cmath>
// #include <queue>
// using namespace std;
// priority_queue<int> q;
// int n,m,a,b,c,ans[100005];
// int main(){
// 	scanf("%d%d",&n,&m);
// 	for(int i=1;i<=n;i++){
// 		scanf("%d%d%d",&a,&b,&c);
// 		for(int j=1;j<=m;j++){
// 			int k;
// 			k=a*j*j+b*j+c;//k为函数值y
// 			if(i==1) q.push(k);
// 			else{
// 				if(k<q.top()){
// 					q.push(k);
// 					q.pop();
// 				}
// 				else break;
//          //如果k已经大于第m小的数了，接下来k仍旧单调递增
//          //所以可以直接break掉，一个重要的优化
// 			}
// 		}
// 	}
// 	for(int i=1;i<=m;i++){
// 		ans[i]=q.top();
// 		q.pop();
// 	}//记得要逆着输出！
// 	for(int i=m;i>=1;i--)
// 		printf("%d ",ans[i]);	
// 	return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     //函数值。 第几个函数。 当前的x
//     int val,id,idx;
//     node(int v,int i,int idx):val(v),id(i),idx(idx){};
//     bool operator<(const node&u)const
//     {
//         return val>u.val;
//     }
// };
// const int N=1e4+66;
// int A[N],B[N],C[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     priority_queue<node>q;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>A[i]>>B[i]>>C[i];
//     }

//     //对于每个函数第一个值肯定是最小的
//     for(int i=1;i<=n;i++)
//     {
//         int val=A[i]*1+B[i]*1+C[i];
//         q.emplace(val,i,1);
//     }

//     //注意这两个的区别
//     //vector<int>res(m);
//     vector<int>res;//取前m个
//     for(int i=1;i<=m;i++)
//     {
//         node top=q.top();q.pop();
//         res.push_back(top.val);


//         //保证每个函数有一个函数值
//         int next=top.idx+1;
//         int val=A[top.id]*next*next+B[top.id]*next+C[top.id];
//         q.emplace(val,top.id,next);
//     }
// // 你初始化了大小为 m 的 vector：cpp运行
// // vector<int> res(m); // 初始包含m个默认值0的元素
// // 但后续用res.push_back(top.val)添加元素，这会导致：
// // res 前 m 个元素是初始的 0，后 m 个元素是正确的函数值；
// // 最后输出res[i]（i 从 0 到 m-1）时，实际输出的是前 m 个 0，而非正确结果。
//     for(int i=0;i<m;i++)cout<<res[i]<<" ";
//     return 0;
// }



// //不要担心参数多，参数多其实本质上来讲更容易
// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     int a,b,c;
//     int val;
//     int x;
//     node(int a,int b,int c,int val,int x){this->a=a,this->b=b,this->c=c,this->val=val,this->x=x;};
//     bool operator< (const node &u)const//两个const缺一不可
//     {
//         return val>u.val;
//     }
//     //小数在前
// };
// //priority_queue<node,vector<node>,greater<node>>q; 这个不能直接用
// priority_queue<node>q;
// int n,m;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         int a,b,c;cin>>a>>b>>c;
//         int val=a*1+b+c;
//         q.emplace(a,b,c,val,1);
//     }
//     int cnt=0;
//     while(cnt<m)
//     {
//         cnt++;
//         cout<<q.top().val<<" ";
//         int nex=q.top().x+1;
//         int a=q.top().a,b=q.top().b,c=q.top().c;//先把a，b,c表示出来，否则q.pop() 再利用q.top()来表示abc 就会出错
//         q.pop();//注意这个问题
//         int val=a*nex*nex+b*nex+c;
//         q.emplace(a,b,c,val,nex);
//     }
//     return 0;
// }


