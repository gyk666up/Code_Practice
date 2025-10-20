#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=30;
int a[N];
bool st[N];
int ans=0;
bool is_prime(int x)
{
   if(x<=1)return false;
    for(int i=2;i<=x/i;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
void dfs(int x)
{
    if(x>n)
    {
        int cnt=0;//记录选的个数
        int temp=0;//选的数的和
        for(int i=1;i<=n;i++)
        {
            if(st[i])
            {
                temp+=a[i];
                cnt++;
            }
        }
        if(cnt==k&&is_prime(temp))ans++;

        return;
    }

    //对于x位置上的数 选 不选
    //组合型枚举
    // st[a[x]]=1;(根据数字来)
    //上面这个写的有问题 如果数据中出现重复的就不会选了 1 1 1  （看上面的for循环）
    st[x]=1;//(根据位置来)
    dfs(x+1);

    st[x]=0;
    dfs(x+1);
    return ;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1);
    cout<<ans;
    return 0;
}