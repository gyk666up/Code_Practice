// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // queue<int>q;
// // // int n,m;
// // // //怎么做的做的像链表呢
// // // void c_right(int x,int y)//将编号为x的同学查到y的右边
// // // {
// // //     //如果y是最后一个人 直接进队就行了
// // //     if(y==q.size())
// // //     {
// // //         q.push(x);
// // //     }
    
// // //     else 
// // //     {
// // //         //为了将x放到y的右边 将y变成队首
// // //         queue<int>temp=q;
// // //         while(q.front()!=y)
// // //         {
// // //             q.push(q.front());
// // //             q.pop();
// // //         }
// // //         //此时y是队首
// // //         q.push(x);

// // //     }
// // // }
// // // int main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     q.push(1);
// // //     cin>>n;
// // //     for(int i=2;i<=n;i++)
// // //     {
// // //         int k,p;cin>>k>>p;
// // //         if(p==1)c_right(i,k);
// // //         else c_left(i,k);
// // //     }
// // //     cin>>m;
// // //     return 0;
// // // }




// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=1e5+11;
// // struct node
// // {
// //     node*next=NULL;
// //     node*prev=NULL;
// //     int val;
// // }dat[N];
// // int n,m;
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     node*head=new node;
// //     node*newnode=new node;
// //     newnode->prev=head;
// //     newnode->val=1;
// //     head->next=newnode;
// //     cin>>n;
// //     for(int i=2;i<=n;i++)
// //     {
// //         node*Nnode=new node;
// //         Nnode->val=i;
// //         int k,p;cin>>k>>p;
// //         node*id=head;
// //         while(id->val!=k)
// //         {
// //             id=id->next;
// //         }
// //         //此时id==k
// //         if(p==1)
// //         {
// //             Nnode->next=id->next;
// //             Nnode->prev=id;
// //             id->next=Nnode;
// //         }
// //         id=id->prev;
// //         else
// //         {

// //         }
// //     }
// //     return 0;
// // }





// // //使用链表！~！！
// // #include<cstdio>
// // struct node{
// //     int n;//保存节点的值
// //     node *left,*right;//左边右边各一个
// //     node(int t){//构造函数
// //         left=right=NULL;
// //         n=t;
// //     }
// // }*p[100010],*q;
// // int main(){
// //     int m,n,i,j,k,u=1,v;
// //     p[1]=new node(1);
// //     scanf("%d",&n);
// //     for(i=2;i<=n;i++){
// //         scanf("%d%d",&j,&k);
// //         p[i]=new node(i);
// //         if(k){//插入过程
// //             if(p[j]->right){
// //                 p[j]->right->left=p[i];
// //                 p[i]->right=p[j]->right;    
// //             }
// //             p[j]->right=p[i];
// //             p[i]->left=p[j];
// //         }
// //         else{
// //             if(p[j]->left){
// //                 p[j]->left->right=p[i];
// //                 p[i]->left=p[j]->left;    
// //             }
// //             p[j]->left=p[i];
// //             p[i]->right=p[j];
// //             if(j==u)u=i;//用u来记录链表开端
// //         }
// //     }
// //     scanf("%d",&m);
// //     for(i=1;i<=m;i++){//删除过程
// //         scanf("%d",&k);
// //         if(p[k]->left)
// //             p[k]->left->right=p[k]->right;
// //         if(p[k]->right){
// //             p[k]->right->left=p[k]->left;
// //             if(k==u)
// //                 u=p[k]->right->n;
// //         }
// //         p[k]->left=p[k]->right=NULL;
// //     }
// //     q=p[u];
// //     while(q){//循环直到q为空
// //         printf("%d ",q->n);
// //         q=q->right;
// //     }
// //     return 0;
// // }










// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// struct node
// {
//     int val;
//     node*left,*right;//注意第二个*容易忽略 
//     node(int t)
//     {
//         val=t;
//         left=right=NULL;
//     }
// }*p[N],*q;//node *p[100010], *q;  // p[i]：指向编号为i的同学的节点（快速定位节点）；q：遍历链表用的临时指针
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;
//     cin>>n;
//     p[1]=new node(1);
//     int u=1; //u 始终指向链表的「头节点」（队列最左边的同学）
//     for(int i=2;i<=n;i++)
//     {
//         p[i]=new node(i);
//         int j,k;cin>>j>>k;
//         if(k)//右插
//         {
//             if(p[j]->right)
//             {
//                 p[i]->right=p[j]->right;
//                 p[j]->right->left=p[i];
//             }
//             p[i]->left=p[j];
//             p[j]->right=p[i];
//         }
//         else
//         {
//             if(p[j]->left)
//             {
//                 p[j]->left->right=p[i];
//                 p[i]->left=p[j]->left;
//             }
//             p[i]->right=p[j];
//             p[j]->left=p[i];
//             if(j==u)u=i;//  if(j == u) u = i; // 正确：无论j是否有左邻居，只要j是头节点就更新
//         }
//     }
//     cin>>m;
//     for(int i=1;i<=m;i++)
//     {
//         int k;cin>>k;
//         node*del=p[k];
//     // 步骤1：让删除节点的左邻居和右邻居“互相连接”，跳过删除节点
//         if(del->left!=NULL)//
//         {
//             del->left->right=del->right;// 左邻居的右指针 → 删除节点的右邻居
//             //del->right->left=del->left;//得分开判断
//         }
//         if(del->right!=NULL)
//         {
//             del->right->left=del->left;
//             //特殊情况：如果删除的是头节点，则更新头节点为其右邻居
//             if(k==u)u=del->right->val;
//         }
//         // 步骤2：将删除节点的左右指针设为NULL，标记为“已删除”（后续操作会忽略）
//          del->left = del->right = NULL;
//     }
//     q = p[u];  // q指向头节点
//     while(q != NULL){  // 直到遍历到链表末尾（NULL）
//     printf("%d ", q->val);  // 输出当前节点编号
//     q = q->right;         // 移动到右邻居
//     }
//     return 0;
// }













#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
struct node
{
    int val;
    node*left,*right;
    node(int t)
    {
        val=t;
        left=right=NULL;
    }
}*p[N],*q;//*q指向头节点 遍历的时候用
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    int u=1;//头节点的下标
    p[1]=new node(1);
    for(int i=2;i<=n;i++)
    {
        int j,k;cin>>j>>k;
        
        p[i]=new node(i);
        if(k==1){
        if(p[j]->right)
        {
            p[j]->right->left=p[i];
            p[i]->right=p[j]->right;
        }
        p[i]->left=p[j];
        p[j]->right=p[i];
    }
    else{
        if(p[j]->left)
        {
            p[j]->left->right=p[i];
            p[i]->left=p[j]->left;
            
        }
        p[j]->left=p[i];
        p[i]->right=p[j];
        if(j==u)u=i;
    }
    }
    int m;cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;cin>>x;
        node*del=p[x];
        if(p[x]==NULL)continue;
        if(del->left)
        {
            del->left->right=del->right;
        }
        if(del->right)
        {
            del->right->left=del->left;
            if(del==p[u])u=del->left->val;
        }
        del->left=del->right=NULL;
        p[x]=NULL;
    }
    q=p[u];
    while(q)
    {
        cout<<q->val<<" ";
        q=q->right;
    }
    return 0;
}


