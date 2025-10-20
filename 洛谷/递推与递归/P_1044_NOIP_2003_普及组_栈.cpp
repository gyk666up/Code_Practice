// #include<bits/stdc++.h>
// using namespace std;
// const int N=30;
// int dp[N][N];//当还有 i 个元素没入栈，且当前栈里有 j 个元素时，
// //剩余操作能产生的不同出栈序列总数。
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     //i 为未入栈的个数 j当前栈中的个数
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=n;j++)
//         {
//             if(!i)dp[i][j]=1;
//                         //入栈         出战
//             else if(j)dp[i][j]=dp[i-1][j+1]+dp[i][j-1];
//             else dp[i][j]=dp[i-1][j+1];
//         }
//     }
//     cout<<dp[n][0]<<endl;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

int dp[20][20];
//第一个i代表未入栈的个数，第二个数代表栈中有几个数字
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(!i)dp[i][j]=1;
            //所有元素都已入栈，剩下的操作只能是将栈中所有的元素依次弹出 只有一种情况FILO
            else if(j>0)dp[i][j]=dp[i-1][j+1]+dp[i][j-1];
            else dp[i][j]=dp[i-1][j+1];
        }
    }
    cout<<dp[n][0];
    return 0;
}