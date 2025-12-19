// //模版题
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=1e5+11;
// int prefix[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         prefix[i]=prefix[i-1]+x;
//     }
//     int m;cin>>m;
//     while(m--)
//     {
//         int l,r;cin>>l>>r;
//         cout<<(prefix[r]-prefix[l-1])<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+11;
int a[N];
int prefix[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        prefix[i]=prefix[i-1]+a[i];
    }
    int t;cin>>t;
    while(t--)
    {
        int l,r;cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<endl;;
    }
    return 0;
}