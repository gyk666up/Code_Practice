// //关键是dp数组的含义 
// //之前做了很多次了，这一次结果还是没有写出来🙂‍↔️🤡
// #include<bits/stdc++.h>
// using namespace std;
// int dp[20][30];//dp[i][j]未入栈的个数 栈中元素的个数
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     //i、j从0开始
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=n;j++)
//         {
//             if(i==0)dp[i][j]=1;//只能弹出来了
//             else if(j-1<0)dp[i][j]=dp[i-1][j+1];//只能入栈
//             else 
//             {
//                 dp[i][j]=dp[i-1][j+1]+dp[i][j-1];
//             }
//         }
//     }
//     cout<<dp[n][0];
//     return 0;
// }

