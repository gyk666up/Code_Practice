#include<bits/stdc++.h>
using namespace std;
const int N=2e6+11;
//部分背包问题 找最划算的
struct node
{
    double p;
    double w;
    bool operator<(const node&u)
    {
        return p<u.p;
    }
}dat[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>dat[i].p>>dat[i].w;
    }
    sort(dat+1,dat+1+m);
    double cost=0;
    for(int i=1;i<=n;i++)
    {
        if(n>=dat[i].w)
        {
            n-=dat[i].w;
            cost+=dat[i].w*dat[i].p;
        }
        else //不需要全部了 只需要一部分
        {
            cost+=dat[i].p*n;
            break;
        }
    }
    //注意这里输出的必须是整数否则 会输出2e+06
    cout<<(int)cost<<endl;
    return 0;
}