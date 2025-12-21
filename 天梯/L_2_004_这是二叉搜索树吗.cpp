//没有完全正确
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+22;
int post[N],n;
int pre[N];
int idx=0;
bool check(int l,int r) 
{
    //根节点
    int x=pre[l];
    if(l>r)return 1;
    if(l==r)
    {
        post[++idx]=pre[l];
        return true;
    }
    int i;
    //遍历左子树
    for(i=l+1;i<=r&&pre[i]<x;i++);
    int j;
    for( j=i;j<=r&&pre[j]>=x;j++);
    if(j!=r+1)return false;
    //递归检查左子树
    bool left=check(l+1,i-1);
    bool right=check(i,r);
    post[++idx]=x;
    return left&&right;
}
bool check2(int l,int r) 
{
    //根节点
    if(l>r)return 1;
    int x=pre[l];
    if(l==r)
    {
        post[++idx]=pre[l];
        return true;
    }
    int i;
    //遍历左子树
    for(i=l+1;i<=r&&pre[i]>=x;i++);
    //次数指向的就是根节点
    int j;
    for( j=i;j<=r&&pre[j]<x;j++);
    if(j!=r+1)return false;
    //递归检查左子树
    bool left=check2(l+1,i-1);
    bool right=check2(i,r);
    post[++idx]=x;
    return left&&right;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>pre[i];
    if(check(1,n))
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        {
            if(i==1)cout<<post[i];
            else cout<<" "<<post[i];
        }
        return 0;
    }
    idx=0;
    memset(post,0,sizeof post);
     if(check2(1,n))
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        {
            if(i==1)cout<<post[i];
            else cout<<" "<<post[i];
        }
    }
    else cout<<"NO\n";
    return 0;
}