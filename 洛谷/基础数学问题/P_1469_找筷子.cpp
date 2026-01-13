// //MLE了. 超内存了。
// // #include<bits/stdc++.h>
// // using namespace std;
// // map<int,int>mp;
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int n;cin>>n;
// //     for(int i=0;i<n;i++)
// //     {
// //         int x;cin>>x;
// //         mp[x]++;
// //     }
// //     for(auto[x,t]:mp)
// //     {
// //         if(t%2!=0)
// //         {
// //             cout<<x;
// //             break;
// //         }
// //     }
// //     return 0;
// // }



// //k 个相同的数的异或和，当 k 为奇数时，结果是这个数本身，否则结果是 0。
// //异或：不同为1。相同为0。(位运算)
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int ans=0;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         ans^=x;
//     }
//     cout<<ans;
//     return 0;
// }




// //2025/12/19. 还记得嘿嘿 用异或😎
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// //开数组的话会mel
// // const int N=1e7+11;
// // int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     // for(int i=1;i<=n;i++)cin>>a[i];
//     int ans=0;//初始化为0
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         ans^=x;
//     }
//     cout<<ans;
//     return 0;
// }



//1 12 秒了
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int ans=0;
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        ans^=x;
    }
    cout<<ans;
    return 0;
}