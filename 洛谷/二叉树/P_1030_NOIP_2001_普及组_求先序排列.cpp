// //和前面的美国血统_American_Heritage简直一模一样
// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     char val;
//     node*left=NULL;
//     node*right=NULL;
// };
// const int N=10;
// char mid[N];
// char post[N];
// node*build(int midl,int midr,int postl,int postr)
// {
//     if(postl>postr)return NULL;
//     node*p=new node;
//     p->val=post[postr];
//     char x=post[postr];
//     int i=0;
//     for(i=midl;mid[i]!=x;i++);
//     i--;
//     p->left=build(midl,i,postl,postl+i-midl);
//     p->right=build(i+2,midr,postl+i-midl+1,postr-1);
//     return p;
// }
// void Print(node*p)
// {
//     if(p==NULL)return;
//     cout<<p->val;
//     Print(p->left);
//     Print(p->right);
//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>mid+1;
//     cin>>post+1;
//     int n=strlen(mid+1);
//     node*head=build(1,n,1,n);
//     Print(head);
//     return 0;
// }




