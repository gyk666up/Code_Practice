// //没思路
// #include<bits/stdc++.h>
// using namespace std;
// double n,p;
// const int N=100005;
// struct node
// {
//     double a,b;
// }dat[N];
// bool check(double x)
// {
//     double sum=0;//sum所需充电量
//     for(int i=1;i<=n;i++)
//     {
//         if(dat[i].b<x*dat[i].a)
//         {
//             sum+=x*dat[i].a-dat[i].b;
//         }
//     }
//     if(sum<=p*x)return true;
//     else return false;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>p;
//     double sum=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>dat[i].a>>dat[i].b;
//         sum+=dat[i].a;
//     }
//     if(sum<=p)
//     {
//         cout<<-1<<endl;
//         return 0;
//     }

//     double l=0,r=1e10;
//     //枚举时间
//     while(r-l>0.000001)
//     {
//         double mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     cout<<l;
//     // cout<<fixed<<setprecision(11)<<l;
//     return 0;
// }



// //totally wrong！
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// // int a[N];
// // int b[N];
// struct node
// {
//     double a,b;
//     bool operator<(const node&u)
//     {
//         return b/a<u.b/u.a;//坚持时间最短的优先充电
//     }
// }dat[N];
// int n,p;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>p;
//     for(int i=1;i<=n;i++)
//     {
//         //每秒消耗的电量<=p说明可以无限
//         cin>>dat[i].a>>dat[i].b;
//     }
//     sort(dat+1,dat+1+n);
//     //只有一个设备的时候才可能无限
//     if(n==1)
//     {
//         if(p>=dat[1].b)cout<<"-1";
//         else 
//         {
//             double t=1;
//             for(;;t++)
//             {
//                 if(t*p+dat[1].b<=dat[1].a*t)break;
//             }
//             cout<<t;
//         }
//     }
//     else
//     {
//         double t1=1;
//         for(;;t1++)
//         {
//             if(t1*p+dat[1].b<=dat[1].a*t1)break;
//         }
//         double t2=dat[1].b/dat[1].a;

//         cout<<min(t2,t1);
//     }

//     return 0;
// }


//这段话好好理解一下
//首先换手机充电的操作是瞬间完成，其次电量变化是连续的。这也就给了我们充一会一把手机，让它能用到我把其他手机充电到能用到相同时刻的电量的可能。
//我们可以把 $p \times x$ 想象成一桶水，手机的缺口想象成不同大小的坑。只要水的总体积大于坑的总容积，我们就能把所有坑填满，而不需要关心具体的填补顺序。
//如果你换得足够快（快到极限），在宏观上，就相当于你把这根水管拆成了 3 根小水管，同时给三个桶补水！

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n,p;
struct node
{
    int a,b;
}dat[N];
bool check(double x)
{
    double sum=0;//所需的充电量
    for(int i=1;i<=n;i++)
    {
        if(dat[i].a*x>dat[i].b)
        {
            sum+=dat[i].a*x-dat[i].b;
        }
    }
    if(sum<=p*x)return true;
    return false;
}
int main()
{
    cin>>n>>p;
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].a>>dat[i].b;
        sum+=dat[i].a;
    }
    if(sum<=p)
    {
        cout<<-1;
        return 0;
    }

    double l=0,r=1e10;
    while(r-l>0.00001)
    {
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<r;
    return 0;
}