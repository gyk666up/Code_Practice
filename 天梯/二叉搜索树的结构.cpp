//注意这道题和二叉搜索树的2层结点统计、L2-012 关于堆的判断
//错误的
// #include<bits/stdc++.h>
// using namespace std;
// int idx=0;
// struct node
// {
//     int val;
//     node*left=NULL;
//     node*right=NULL;
//     node(int x):val(x),left(NULL),right(NULL){}
// };
// int tre[1002];
// int length[1002];
// node*insert(node*root,int val)
// {
//     if(!root)return new node(val);
//     if(val<root->val)
//     root->left=insert(root->left,val);
//     if(val>root->val)
//     root->right=insert(root->right,val);

//     return root;
// }
// void dfs(node*root,int height)
// {
//     if(!root)return;
//     tre[++idx]=root->val;
//     length[root->val]=height;
//     if(root->left)dfs(root->left,height+1);
//     if(root->left)dfs(root->right,height+1);

// }
// int n;
// int main()
// {
//     cin>>n;
//     node*root=NULL;
//     dfs(root,1);//转化为树状数组，之后就跟之前那道题一模一样了
//     int m;cin>>m;
//     getchar();
//     while(m--)
//     {
//         string s;getline(cin,s);
//         int x,y;
       
//         if(s.find("root")!=string::npos)
//         {
//             sscanf(s.c_str(),"%d is the root",&x);
//             if(tre[1]==x)cout<<"Yes\n";
//             else cout<<"No\n";
//         }
//         else if(s.find("siblings")!=string::npos)
//         {
//             sscanf(s.c_str(),"%d and %d are siblings",&x,&y);
//             int i=1,j=1;
//             for(i=1;i<=n;i++)if(tre[i]==x)break;
//             for(j=1;j<=n;j++)if(tre[j]==y)break;
//             if(i/2==j/2)cout<<"Yes\n";
//             else cout<<"No\n";
//         }
//         else if(s.find("parent")!=string::npos)
//         {
//             sscanf(s.c_str(),"%d is the parent of %d",&x,&y);
//             int i=1,j=1;
//             for(i=1;i<=n;i++)if(tre[i]==x)break;
//             for(j=1;j<=n;j++)if(tre[j]==y)break;
//             if(i==j/2)cout<<"Yes\n";
//             else cout<<"No\n";
//         }
//         else if(s.find("left")!=string::npos)
//         {
//             sscanf(s.c_str(),"%d is the left child of %d",&x,&y);
//             int i=1,j=1;
//             for(i=1;i<=n;i++)if(tre[i]==x)break;
//             for(j=1;j<=n;j++)if(tre[j]==y)break;
//             if(i==j+1)cout<<"Yes\n";
//             else cout<<"No\n";
//         }
//         else if(s.find("right")!=string::npos)
//         {
//             sscanf(s.c_str(),"%d is the right child of %d",&x,&y);
//             int i=1,j=1;
//             for(i=1;i<=n;i++)if(tre[i]==x)break;
//             for(j=1;j<=n;j++)if(tre[j]==y)break;
//             if(i==j+2)cout<<"Yes\n";
//             else cout<<"No\n";
//         }
//         ///这个该怎么判断呢，是利用一个数组吗
//         else if(s.find("same")!=string::npos)
//         {
//             sscanf(s.c_str(),"%d and %d are on the same level",&x,&y);
//             if(length[x]==length[y])cout<<"Yes\n";
//             else cout<<"No\n";
//         }
//     }
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <map>
// #include <vector>

// using namespace std;

// // 节点结构
// struct Node {
//     int val;
//     Node *left, *right;
//     Node(int x) : val(x), left(NULL), right(NULL) {}
// };

// // 使用 map 存储节点属性，自动处理负数索引并解耦空间限制
// map<int, int> parent;      // parent[x] 存储 x 的父节点值
// map<int, int> depth;       // depth[x] 存储 x 的深度
// map<int, int> l_child;     // l_child[x] 存储 x 的左儿子值
// map<int, int> r_child;     // r_child[x] 存储 x 的右儿子值
// map<int, bool> exists;     // 记录节点是否存在于树中

// // 插入函数：递归建树并填充关系网
// Node* insert(Node* root, int val, int p, int d) {
//     if (!root) {
//         exists[val] = true;
//         parent[val] = p;
//         depth[val] = d;
//         return new Node(val);
//     }
//     // 标准 BST 规则（若题目有 <= 要求请自行修改符号）
//     if (val < root->val) {
//         root->left = insert(root->left, val, root->val, d + 1);
//         l_child[root->val] = root->left->val;
//     } else {
//         root->right = insert(root->right, val, root->val, d + 1);
//         r_child[root->val] = root->right->val;
//     }
//     return root;
// }

// int main() {
//     int n, m;
//     if (!(cin >> n)) return 0;
    
//     Node* root = NULL;
//     int first_val;
//     for (int i = 0; i < n; i++) {
//         int val; cin >> val;
//         if (i == 0) first_val = val;
//         root = insert(root, val, 0, 1); // 根节点的父亲设为 0，深度设为 1
//     }

//     cin >> m;
//     getchar(); // 吸收换行符
//     while (m--) {
//         string s;
//         getline(cin, s);
//         int x, y;
//         bool res = false;

//         // 利用 find 识别模式，利用 sscanf 提取数字
//         if (s.find("root") != string::npos) {
//             sscanf(s.c_str(), "%d is the root", &x);
//              //第一个插入的数字就是根节点方便这里直接判断
//             res = (x == first_val);
//         } 
//         else if (s.find("siblings") != string::npos) {
//             sscanf(s.c_str(), "%d and %d are siblings", &x, &y);
//             // 兄弟：父亲相同且不为根
//             res = (exists[x] && exists[y] && parent[x] == parent[y] && x != y);
//         } 
//         else if (s.find("parent") != string::npos) {
//             sscanf(s.c_str(), "%d is the parent of %d", &x, &y);
//             res = (exists[y] && parent[y] == x);
//         } 
//         else if (s.find("left child") != string::npos) {
//             sscanf(s.c_str(), "%d is the left child of %d", &x, &y);
//             res = (exists[y] && l_child[y] == x);
//         } 
//         else if (s.find("right child") != string::npos) {
//             sscanf(s.c_str(), "%d is the right child of %d", &x, &y);
//             res = (exists[y] && r_child[y] == x);
//         } 
//         else if (s.find("same level") != string::npos) {
//             sscanf(s.c_str(), "%d and %d are on the same level", &x, &y);
//             res = (exists[x] && exists[y] && depth[x] == depth[y]);
//         }

//         cout << (res ? "Yes" : "No") << endl;
//     }
//     return 0;
// }

