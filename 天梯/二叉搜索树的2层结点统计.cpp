// // #include <iostream>
// // #include <vector>
// // #include <algorithm>

// // using namespace std;

// // // 定义二叉树结点
// // struct Node {
// //     int val;
// //     Node *left, *right;
// //     Node(int v) : val(v), left(NULL), right(NULL) {}
// // };

// // // 统计每一层结点数的数组，N <= 1000，深度最大也只有 1000
// // int level_cnt[1005];
// // int max_depth = 0;

// // // 严格按照题目规则插入结点
// // Node* insert(Node* root, int val) {
// //     if (!root) return new Node(val);//这是递归的终点。当你顺着树往下找，直到发现一个 NULL 指针时，说明你找到了这个新数字该待的地方。
    
// //     // 注意题目要求：左子树 <= 根，右子树 > 根
// //     if (val <= root->val) {
// //         root->left = insert(root->left, val);
// // //         //我们可以把它理解为一次“父子确认”：

// // // 父节点对左儿子说：“你去帮我把这个 val 插到你的子树里。”

// // // 左儿子处理完后（可能在下面生成了新孙子），给父节点回个话：“这是处理完后的子树根节点地址，你拿好。”

// // // 父节点通过 root->left = ... 重新更新（或确认）一下左儿子的地址
// //     } else {
// //         root->right = insert(root->right, val);
// //     }
// //     return root;
// // }

// // // DFS 遍历统计层数
// // void dfs(Node* root, int depth) {
// //     if (!root) return;
    
// //     max_depth = max(max_depth, depth);
// //     level_cnt[depth]++;
    
// //     dfs(root->left, depth + 1);
// //     dfs(root->right, depth + 1);
// // }

// // int main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);

// //     int n;
// //     cin >> n;
    
// //     Node* root = NULL;
// //     for (int i = 0; i < n; i++) {
// //         int val;
// //         cin >> val;
// //         root = insert(root, val);
// //     }

// //     // 从第 1 层开始搜索
// //     dfs(root, 1);

// //     // 输出最后两层的结点数之和
// //     if (max_depth == 0) {//这个其实没有必要 最少为一层
// //         cout << 0 << endl;
// //     } else if (max_depth == 1) {
// //         cout << level_cnt[1] << endl;
// //     } else {
// //         cout << level_cnt[max_depth] + level_cnt[max_depth - 1] << endl;
// //     }

// //     return 0;
// // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1002;
// // int length[N];//记录每个深度的节点数量
// // struct node
// // {
// //     int val;
// //     node*left;
// //     node*right;
// //     node(int x):val(x),left(NULL),right(NULL){}//注意这个构造函数的写法
// // };
// // int n;
// // int maxlen=-1;
// // //这个函数好好理解一下，有点难理解
// // node*insert(node*root,int val)
// // {
// //     if(!root)return new node(val);
// //     if(val<=root->val)
// //     root->left=insert(root->left,val);

// //     if(val>root->val)
// //     root->right=insert(root->right,val);
// //     return root;
// // }
// // void dfs(node*p,int height)
// // {
// //     if(!p)return;
// //     maxlen=max(maxlen,height);
// //     length[height]++;
// //     if(p->left)dfs(p->left,height+1);
// //     if(p->right)dfs(p->right,height+1);
// // }
// // int main()
// // {
// //     cin>>n;
// //     node*root=NULL;
// //     for(int i=0;i<n;i++)
// //     {
// //         int x;cin>>x;
// //         root=insert(root,x);
// //     }
// //     dfs(root,1);
// //     if(maxlen==1)cout<<1;
// //     else 
// //     {
// //         cout<<length[maxlen]+length[maxlen-1];
// //     }
// //     return 0;
// // }

// #include<bits/stdc++.h>
// using namespace std;
// const int N=1002;
// int len[N];//统计不同高度的数量
// int n;
// int maxheight=-1;
// struct node
// {
//     int val;
//     node*left;
//     node*right;
//     node(int x):val(x),left(NULL),right(NULL){}
// };
// node*insert(node*root,int x)
// {
//     if(!root)return new node(x);//找到了一个合适的位置
//     //如果 root->left 本来就有孩子，这句赋值只是把原来的地址又赋了一遍，没变化。

//     //如果 root->left 原本是 NULL，这句赋值就会精准地把刚才 new 出来的新节点“挂”在父节点上
//     if(x<=root->val)
//     root->left=insert(root->left,x);
//     if(x>root->val)
//     root->right=insert(root->right,x);

//     return root;
// }
// void dfs(node*p,int height)
// {
//     if(!p)return;
//     maxheight=max(maxheight,height);
//     len[height]++;
//     if(p->left)dfs(p->left,height+1);
//     if(p->right)dfs(p->right,height+1);
// }
// int main()
// {
//     cin>>n;
//     node*root=NULL;

//     for(int i=0;i<n;i++)
//     {
//         int x;cin>>x;
//         root=insert(root,x);
//     }
//     dfs(root,1);
//     if(maxheight==1)
//     {
//         cout<<len[1];
//     }
//     else cout<<len[maxheight-1]+len[maxheight];
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=1002;
struct node
{
    int val;
    node*left,*right;
    node(int x):val(x),left(NULL),right(NULL){}
};
int len[N];
node*insert(node*root,int val)
{
    if(!root)return new node(val);

    if(val<=root->val)
    root->left=insert(root->left,val);
    else
    root->right=insert(root->right,val);

    return root;
}
int maxlen=-1;
int n;
void dfs(node*p,int height)
{
    if(!p)return;
    maxlen=max(height,maxlen);
    len[height]++;
    if(p->left)dfs(p->left,height+1);
    if(p->right)dfs(p->right,height+1);
    return;
}
int main()
{
    cin>>n;
    node*root=NULL;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        root=insert(root,x);
    }
    dfs(root,1);
    if(maxlen==1)
    {
        cout<<len[maxlen];
    }
    else cout<<len[maxlen]+len[maxlen-1];
    return 0;
}