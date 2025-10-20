// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+44;
// int f[N];
// //f[i]表示以i开头的序列个数 
// //f[2]=1+f[1](扩展的数列)=1+1=2;
// //f[5]=1+f[1]+f[2]=1+1+2=4
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=i/2;j++)
//         {
//             f[i]+=f[j];
//         }
//         f[i]++;
//     }
//     cout<<f[n];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=1e3+11;
int f[N];
int main()
{
    //f[i]表示以i为开头的序列的个数
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {               //注意这里是i/2 并不是i
        for(int j=1;j<=i/2;j++)
        f[i]+=f[j];
        f[i]++;//一个单数字
    }
    cout<<f[n];
}