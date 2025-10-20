#include<bits/stdc++.h>
using namespace std;
//建树 以前那个pta上见过相似的题目  能写对80%但仍存在一些小问题
const int N=1e6+11;
char mid[N];
char pre[N];
struct node
{
    char val;
    node*left=NULL;
    node*right=NULL;
};
node*build(int prel,int prer,int midl,int midr)
{
    if(prel>prer)return NULL;
     node*p=new node;//注意分配内存
      p->val=pre[prel];
     int i;
     char x=pre[prel];//根节点
    for(i=midl;i<=midr;i++)
    {
        if(mid[i]==x)//根节点
        break;
    }
    i--;
    //后序遍历 左右根
    p->left=build(prel+1,i-midl+1+prel,midl,i);
    p->right=build(i-midl+prel+2,prer,i+2,midr);
    
    return p;
}
void Print(node*p)
{
    if(p==NULL)return;
    Print(p->left);
    Print(p->right);
    cout<<(p->val);
    return;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>mid+1;
    int n=0;
    for(int i=1;mid[i];i++)n++;
    cin>>pre+1;
    node*head=build(1,n,1,n);
    Print(head);
    return 0;
}