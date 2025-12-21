#include<bits/stdc++.h>
using namespace std;
const int N=1e4+66;
struct node
{
    double score;
    bool operator<(const node &u)
    {
        return score>u.score;
    }
}dat[N];
int n,k,m;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        double sum=0;
        int max_=0,min_=0x3f3f3f3f;
        for(int j=0;j<k;j++)
        {
            double x;cin>>x;
            max_=max(max_,x);
            min_=min(min_,x);
            sum+=x;
        }
        sum-=max_;
        sum-=min_;
        dat[i].score=sum/(k-2);
    }
    sort(dat+1,dat+1+n);
    int m;cin>>m;
    for(int i=1;i<=m;i++)
    {
        if(i==1)
        cout<<fixed<<setprecision(2)<<dat[i].score;
        else
        cout<<fixed<<setprecision(2)<<<<" "<<dat[i].score;
 
    }
}