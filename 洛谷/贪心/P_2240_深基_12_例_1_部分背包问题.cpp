// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     float m,v;
//    // float pervalue=v/m;
//    float pervalue;
//     bool operator<(const node u)
//     {
//         return pervalue>u.pervalue;
//     }
// }dat[200];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,t;
//     cin>>n>>t;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>dat[i].m>>dat[i].v;
//         dat[i].pervalue=dat[i].v/dat[i].m;
//     }
//     sort(dat+1,dat+1+n);
//     float value=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(t>=dat[i].m)
//         {
//             value+=dat[i].v;
//             t-=dat[i].m;
//         }
//         else
//         {
//             value+=t*dat[i].pervalue;
//             break;
//         }
//     }
//     cout<<fixed<<setprecision(2)<<value<<endl;
//     return 0;
// }


//no problem
#include<bits/stdc++.h>
using namespace std;
const int N=102;
struct node
{
    double m,v;
    bool operator<(const node&u)
    {
        return v/m>u.v/u.m;
    }
}dat[N];
int  n,t;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>t;
    
    for(int i=1;i<=n;i++)cin>>dat[i].m>>dat[i].v;
    sort(dat+1,dat+1+n);
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        if(t>dat[i].m)
        {
            t-=dat[i].m;
            ans+=dat[i].v;
        }
        else
        {
            ans+=dat[i].v/dat[i].m*t;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}