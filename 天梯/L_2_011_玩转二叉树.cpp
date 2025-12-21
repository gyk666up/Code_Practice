#include<bits/stdc++.h>
using namespace std;
const int N=100;
int mid[N],pre[N];
struct node
{
    int val;
    node*left=NULL;
    node*right=NULL;
};
node*build(int midl,int midr,int prel,int prer)
{
    //注意14行和15行两行代码的孙秀也很关键
    if(midl>midr)return NULL;
    node*p=new node;
    // if(midl==midr)
    // {
    //     p->val=pre[prel];
    // }

    p->val=pre[prel];//存根节点
    int x=pre[prel];//记录根节点
    int i;
    for(i=midl;i<=midr&&mid[i]!=x;i++);

    p->left=build(midl,i-1,prel+1,prel+i-midl);
    p->right=build(i+1,midr,prel+1+i-midl,prer);
    return p;
}
void MirrorSwap(node*p)
{
    if(p==NULL)return;//返回条件不能忘记！！！
    swap(p->left,p->right);
    MirrorSwap(p->left);
    MirrorSwap(p->right);
    return;
}
void bfs(node*p)
{
    queue<node*>q;
    q.push(p);
    while(q.size())
    {
        node*s=q.front();q.pop();
        if(s->val==p->val)cout<<(p->val);
        else cout<<" "<<s->val;
        if(s->left)q.push(s->left);
        if(s->right)q.push(s->right);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>mid[i];
    for(int i=1;i<=n;i++)cin>>pre[i];

    node*p=build(1,n,1,n);
    MirrorSwap(p);
    bfs(p);

    return 0;
}