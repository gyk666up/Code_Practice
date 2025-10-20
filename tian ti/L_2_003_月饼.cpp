#include<bits/stdc++.h>
using namespace std;
const int N=1011;
struct node
{
    double kuncun,totalM;
    double price;
    bool operator<(const node u)
    {
        return price>u.price;
    }
}dat[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,MAX;cin>>n>>MAX;
    for(int i=1;i<=3;i++)cin>>dat[i].kuncun;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].totalM;
        dat[i].price=dat[i].totalM/dat[i].kuncun;
    }
    sort(dat+1,dat+1+n);
    double value=0;
    for(int i=1;i<=n;i++)
    {
        if(dat[i].kuncun<MAX)
        {
            value+=dat[i].totalM;
            MAX-=dat[i].kuncun;
        }
        else 
        {
            value+=dat[i].price*MAX;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<value<<endl;
    return 0;
}