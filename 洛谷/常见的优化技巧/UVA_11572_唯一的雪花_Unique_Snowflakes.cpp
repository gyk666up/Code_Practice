//这道题理解的不透彻
//给你一个序列，问 最长的连续子区间，使得区间内 所有数字都不重复。
// // #include <cstdio>
// // #include <map>
// // using namespace std;

// // map<int,int> snow;
// // int T, n, ans, last, a;

// // int main() {
// //     scanf("%d", &T);
// //     while (T--) {
// //         snow.clear();
// //         scanf("%d", &n);

// //         last = ans = 0;

// //         //(last + 1) ~ i窗口范围
// //         for (int i = 1; i <= n; i++) {
// //             scanf("%d", &a);

// //             if (snow[a] > last)
// //                 last = snow[a];
// 含义：

// snow[a[i]] = 这个雪花上一次出现的位置

// 如果它 在当前窗口内（即 > last）

// 就出现了重复

// 必须把窗口左端 跳过它上一次出现的位置
// //             ans = max(ans, i - last);
// //             snow[a] = i;
// //         }
// //         printf("%d\n", ans);
// //     }
// //     return 0;
// // }



// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     int ans=0;
//     while(t--)
//     {
//         int n;cin>>n;
//         vector<int>snow(n+1);
//         vector<int>a(n+1);
//         int last=0;
//         ans=0;
//         for(int i=1;i<=n;i++)
//         {
//             cin>>a[i];
//             if(snow[a[i]]>last)
//             {
//                 last=snow[a[i]];
//             }
//             ans=max(ans,i-last);
//             snow[a[i]]=i;//把当前雪花的“最近出现位置”更新为 i
//         }
        
//         cout<<ans;
//     }
   
//     return 0;
// }


