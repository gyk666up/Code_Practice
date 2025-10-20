//没思路
#include<bits/stdc++.h>
using namespace std;
double n,p;
const int N=100005;
struct node
{
    double a,b;
}dat[N];
bool check(double x)
{
    double sum=0;//sum所需充电量
    for(int i=1;i<=n;i++)
    {
        if(dat[i].b<x*dat[i].a)
        {
            sum+=x*dat[i].a-dat[i].b;
        }
    }
    if(sum<=p*x)return true;
    else return false;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>p;
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].a>>dat[i].b;
        sum+=dat[i].a;
    }
    if(sum<=p)
    {
        cout<<-1<<endl;
        return 0;
    }

    double l=0,r=1e10;
    //枚举时间
    while(r-l>0.000001)
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l;
    // cout<<fixed<<setprecision(11)<<l;
    return 0;
}