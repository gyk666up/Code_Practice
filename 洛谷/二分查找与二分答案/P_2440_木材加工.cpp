// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,k;
// const int N=1e5+11;
// int a[N];
// //段数5  3 3| 2
// //长度 1 2 3 4
// //很明显 找最后一个>=k
// bool check(int x)
// {
//    int cnt=0;
//    for(int i=1;i<=n;i++)
//    {
//         cnt+=a[i]/x;
//    }
//    //递减的 >=
//    if(cnt>=k)return 1;
//    else return false;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     int sum=0;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         sum+=a[i];
//     }
//     sort(a+1,a+1+n);
//     int l=0,r=sum/k+1;//
//     //mid是枚举长度->段数 
//     //长度越长段数越少 //跟以前的跳石头很想
//     while(l+1!=r)
//     {
//         int mid=(l+r)/2;
//         if(check(mid))l=mid;
//         else r=mid;
//     }
//     if(l>=1)cout<<l;
//     else cout<<0;

//     return 0;
// }


////问题不大
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int a[N];
int n,k;
bool check(int x)
{
    int cnt=0;
    for(int i=1;i<=n;i++)cnt+=a[i]/x;
    if(cnt>=k)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int maxa=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxa=max(maxa,a[i]);
    }
    int l=0,r=maxa+1;
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout<<l;
    return 0;
}