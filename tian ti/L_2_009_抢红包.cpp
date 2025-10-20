#include<bits/stdc++.h>
using namespace std;
const int N=1e4+44;
struct node
{
    int id;
    double income;//单位是分
    int many;//抢到红包的个数
    bool operator<(const node u)
    {
        if(income!=u.income)return income>u.income;
        else if (id!=u.id)return many>u.many;
        else return id<u.id;
    }
}dat[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;cin>>k;
        dat[i].many=k;
        dat[i].id=i;
        
        for(int j=1;j<=k;j++)
        {
            int id;cin>>id;
            dat[id].many++;
            int income=0;cin>>income;
            dat[i].income-=income;
            dat[id].income+=income;
        }
    }
    sort(dat+1,dat+1+n);
    for(int i=1;i<=n;i++)
    {
        cout<<dat[i].id<<" "<<fixed<<setprecision(2)<<dat[i].income/100<<endl;
    }
    return 0;
}