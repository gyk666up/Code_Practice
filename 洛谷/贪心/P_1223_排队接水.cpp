// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+11;
// struct node
// {
//     int id;
//     int wtime;
//     bool operator<(const node u)
//     {
//         if(wtime!=u.wtime)return wtime<u.wtime;
//         else return id<u.id;
//     }
// }dat[N];
// int main()
// {
//     //要想等待时间最短：接水时间越短的放越前
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         dat[i].id=i;
//         cin>>dat[i].wtime;
//     }
//     sort(dat+1,dat+1+n);
//     double w=0;
//     for(int i=1;i<=n;i++)
//     {
//         if(i==1)cout<<dat[i].id;
//         else cout<<" "<<dat[i].id;
//     }
//     cout<<endl;
//     //等待时间是这个人前面所有人接水所用的时间
//     double sum=0;
//     sum+=dat[1].wtime;
//     for(int i=2;i<=n;i++)
//     {
//         w+=sum;
//         sum+=dat[i].wtime;
//     }
//     //这个更细节
//     // for(int i=1;i<=n;i++)   //这个循环用来计算总时间 
// 	// {
// 	// 	s+=a[i]*(n-i);
// 	// }
//     cout<<fixed<<setprecision(2)<<w/n<<endl;
//     return 0;
// }


//不难，就是等待时间好好想一下就行了
#include<bits/stdc++.h>
using namespace std;
const int N=1004;
struct node
{
    int t;
    int id;
    bool operator<(const node&u)
    {
        if(t!=u.t)return t<u.t;
        else return id<u.id;
    }
}dat[N];
int n;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //要想等待时间最短的话,用时越短的越往前放
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        dat[i].id=i;
        cin>>dat[i].t;
    }
    sort(dat+1,dat+1+n);
    for(int i=1;i<=n;i++)cout<<dat[i].id<<" ";
    cout<<endl;
    double ans=0;
    double wait=0;
    for(int i=2;i<=n;i++)
    {
        wait+=dat[i-1].t;
        ans+=wait;
    }

    
    // for(int i=1;i<=n;i++)
    // {
    //     ans+=dat[i].t*(n-i);
    // }
    cout<<fixed<<setprecision(2)<<ans/n;
    return 0;
}