//到达是哪里有问题啊
#include<bits/stdc++.h>
using namespace std;

int ans=0;
int sum=0;//需要的全部火柴数
int n;
const int N=1e4+33;
int huo[N]={6,2,5,5,4,5,6,3,7,6};
int a[4];
int getneed(int x)
{
    int need=0;
    if(x==0)return huo[0];
    while(x)
    {
        need+=huo[x%10];
        x/=10;
    }
    return need;
}
void dfs(int x)
{
    if(sum>n)return;
    if(x>3)
    {
        if(sum==n)
        {
            if(a[1]+a[2]==a[3])ans++;
        }
        return;
    }
    //指数枚举型
    for(int i=0;i<=1000;i++)
    {
        a[x]=i;
        sum+=getneed(a[x]);
        dfs(x+1);
        sum-=getneed(a[x]);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    n-=4;
    dfs(1);
    cout<<ans;
    return 0;
}




//这个是正确的
// #include<bits/stdc++.h>
// using namespace std;

// int n;
// int ans=0;
// int need[10]={6,2,5,5,4,5,6,3,7,6};
// int a[4];
// int getneed(int x)
// {
//     int need_=0;
//     if(x==0)return need[0];
//     while(x)
//     {
//         need_+=need[(x%10)];
//         x/=10;
//     }
//     return need_;
// }
// int sum=0;
// void dfs(int x)
// {
//     //指数型枚举
//     if(sum>n)return;
//     if(x>3)
//     {
//         if(sum==n&&a[1]+a[2]==a[3])ans++;
//         return;
//     }

//     for(int i=0;i<=1000;i++)
//     {
//         a[x]=i;
//         sum+=getneed(a[x]);
//         dfs(x+1);

//         sum-=getneed(a[x]);
//         a[x]=-1;
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     n-=4;
//     dfs(1);
//     cout<<ans;
//     return 0;
// }