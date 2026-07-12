// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// int a[N],b[N];
// int main()
// {
//     int n,m,x;cin>>n>>m>>x;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int j=1;j<=m;j++)cin>>b[i];

//     int i=1;j=1;
//     while(i<=n&&j<=r)
//     {
//         if(a[i]+b[j]<x) 两个怎么现在\/
//         {

//         }
//     }
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int a[N],b[N];
// int n,m,x;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>x;
//     for(int i=0;i<n;i++)cin>>a[i];
//     for(int j=0;j<m;j++)cin>>b[j];

//     for(int i=0,j=m-1;i<n;i++)
//     {
//         while(j>=0&&a[i]+b[j]>x)j--;
//         if(a[i]+b[j]==x){
//             cout<<i<<" "<<j<<endl;
//             break;
//         }
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n,m,x;
// const int N=1e5+11;
// int a[N],b[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>x;
//     for(int i=0;i<n;i++)cin>>a[i];
//     for(int j=0;j<m;j++)cin>>b[j];
//     for(int i=0,j=m-1;i<n;i++)
//     {
//         while(a[i]+b[j]>x)j--;
//         if(a[i]+b[j]==x)
//         {
//             cout<<i<<" "<<j;
//             break;
//         }
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int a[N],b[N];
// int n,m,x;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m>>x;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=m;i++)cin>>b[i];
//     //逻辑上是对的，但是t了
//     // for(int i=1;i<=n;i++)
//     // {
//     //     int j=1;
//     //     while(a[i]+b[j]<x)j++;
//     //     if(a[i]+b[j]==x)
//     //     {
//     //         cout<<i-1<<" "<<j-1;
//     //         break;
//     //     }
//     // }
//     for(int i=1,j=m;i<=n;i++)
//     {
//         while(a[i]+b[j]>x)j--;
//         if(a[i]+b[j]==x)
//         {
//             cout<<i-1<<" "<<j-1;
//             break;
//         }
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int a[N],b[N];
int n,m,x;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    int res=0;
    for(int i=1,j=m;i<=n;i++)
    {
        while(a[i]+b[j]>x)j--;
        if(a[i]+b[j]==x)
        {
            cout<<i-1<<" "<<j-1;
            return 0;
        }
    }
    return 0;
}