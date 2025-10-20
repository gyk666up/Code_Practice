// 大网格由四个小网格组成，公主藏在其中一个小网格里；
// 对每个小网格，若公主在里面，就继续拆分成更小的套娃；
// 若公主不在，就补一块 “连接毯”，把这个小网格变成一个 “伪套娃”（缺口作为新的 “伪公主位置”），继续拆分。

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,len;
int k;
//网格的边长
ll get_length(int x)
{
    ll sum=1;
    for(int i=1;i<=x;i++)
    sum*=2;
    return sum;
}
void solve(ll x,ll y,ll a,ll b,ll l)
{
    if(l==1)return;

    //公主在左上角  拐角在右下，覆盖右上的左下、左下的右上、右下的左上。
    //覆盖的区域就有点像伪公主，不可以放地毯
    if(x-a<=l/2-1&&y-b<=l/2-1)
    {
     printf("%lld %lld 1\n",a+l/2,b+l/2); //这行不容易理解
       solve(x,y,a,b,l/2);
       solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
       solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
       solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    //左下
    else if(x-a<=l/2-1&&y-b>l/2-1)
    {
        printf("%lld %lld 2\n",a+l/2,b+l/2-1);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(x,y,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else if(x-a>l/2-1&&y-b<=l/2-1)
    {
       printf("%lld %lld 3\n",a+l/2-1,b+l/2);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(x,y,a+l/2,b,l/2);
        solve(a+l/2,b+l/2,a+l/2,b+l/2,l/2);
    }
    else
    {
        printf("%lld %lld 4\n",a+l/2-1,b+l/2-1);
        solve(a+l/2-1,b+l/2-1,a,b,l/2);
        solve(a+l/2-1,b+l/2,a,b+l/2,l/2);
        solve(a+l/2,b+l/2-1,a+l/2,b,l/2);
        solve(x,y,a+l/2,b+l/2,l/2);
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>k>>x>>y;
    len=get_length(k);
    solve(x,y,1,1,len);
    return 0;
}

// 右上子网格的缺口：位于其 左下角落 → 坐标 (a+l/2-1, b+l/2)（右上子网格的最后一行，第一列）；
// 左下子网格的缺口：位于其 右上角落 → 坐标 (a+l/2, b+l/2-1)（左下子网格的第一行，最后一列）；
// 右下子网格的缺口：位于其 左上角落 → 坐标 (a+l/2, b+l/2)（右下子网格的第一行，第一列）。