#include<bits/stdc++.h>
using namespace std;
const int N=34;
int mid[N],post[N];
int a[N];
struct node
{
    int val;
    node*left=NULL,*right=NULL;
};
node*build(int midl,int midr,int postl,int postr)
{
    node*p=new node;
    if(midl>midr)return NULL;
    //根节点
    p->val=post[postr];
    int x=post[postr];
    int i;
    for( i=midl;i<=midr&&mid[i]!=x;i++);
    //这次mid[midl]==x

    p->left=build(midl,i-1,postl,postl+i-1-midl);
    p->right=build(i+1,midr,postl+i-midl,postr-1);
    return p;
}
void bfs(node*p)
{
    queue<node*>q;
    q.push(p);
    while(q.size())
    {
        node*temp=q.front();q.pop();
        if(temp==p)cout<<temp->val;
        else cout<<" "<<temp->val;
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>post[i];
    for(int i=1;i<=n;i++)cin>>mid[i];
    node*p=build(1,n,1,n);
    bfs(p);
    return 0;
}