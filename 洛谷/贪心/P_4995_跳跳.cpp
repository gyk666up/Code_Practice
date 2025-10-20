#include<bits/stdc++.h>
using namespace std;
//肯定是停在最后一个石头上耗费的体力最多 不对

//来回颠倒 最前面跳到最后面  再从最后面跳到正数第二个
//首先第一步肯定是从地面跳到最后一个
//Hn的平方>=(H1的平方+(Hn-H1)的平方)
//另外如果不是从地面跳到Hn(终点)而是跳到Hp
//也可证明Hn的平方>=(Hp的平方+(Hn-Hp)的平方)
//所以最优解就是从地面跳到最后面，再跳到第一个柱子，再跳到倒数第二个柱子
#define int long long
const int N=1e3;
int h[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>h[i];
    //注意得sort一下 否则最后一个不一定是最高的
    sort(h,h+n+1);//注意(h[0])第一个就相当于地面
    int ans=0;
    int l=0,r=n;
    while(l<r)
    {
        ans+=pow(h[r]-h[l],2);
        l++;
        ans+=pow(h[l]-h[r],2);
        r--;
    }
    cout<<ans<<endl;
    return 0;
}