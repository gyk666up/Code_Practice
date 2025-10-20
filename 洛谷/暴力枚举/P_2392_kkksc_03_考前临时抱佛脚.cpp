// //读完这道题 脑子里就想到优先队列
// //想到之前写过的合并果子
//不对！！！ 思路不对 应该是分成两拨是两拨的差距最小
// #include<bits/stdc++.h>
// using namespace std;
// int a[30];
// int ans=0;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     for(int i=1;i<=4;i++)cin>>a[i];
//     for(int i=1;i<=4;i++)
//     {
//         priority_queue<int>q;
//         for(int j=1;j<=a[i];j++)
//         {
//             int x;cin>>x;
//             q.push(x);
//         }
//         while(q.size()>=2)
//         {
//             int x=q.top();q.pop();
//             int y=q.top();q.pop();
//             ans+=max(x,y);
            
//         }
//         //if(q.size()==1)ans+=q.top();
//         if(!q.empty())
//             ans += q.top();
//     }
//     cout<<ans<<endl;
//     return 0;
// }

// //贪心
// #include<bits/stdc++.h>
// using namespace std;
// int a[5],i,j,sum1,sum2,t,homework;
// int main(){
//     for(i=1;i<=4;i++)
//         cin>>a[i];//输入
//     for(i=1;i<=4;i++){
//     sum1=sum2=0;//两边脑子时间清零
//     for(j=1;j<=a[i];j++)
//         {cin>>homework;
//         if(sum1<=sum2) sum1+=homework;
//         else sum2+=homework;}//哪边时间短就加在哪边
//         t+=max(sum1,sum2);//取较长时间累加
//     }cout<<t;//输出
//     return 0;
// }

//贪心也不对 是动态规划
//对于每科，我们需要将题目分成两组，分别交给左右脑，使得两组的总耗时尽可能接近。
//这样并行处理时，总时间由耗时较长的一组决定，从而最小化单科总时间。
#include<bits/stdc++.h>
using namespace std;
int a[5],i,j,k,sum,t;
int homework[30],dp[3000];
int main()
{
    for( i=1;i<=4;i++)cin>>a[i];
    for( i=1;i<=4;i++)
    {
        sum=0;
        for(j=1;j<=a[i];j++)
        {
            cin>>homework[j];
            sum+=homework[j];
        }
        for(int j=1;j<=a[i];j++)
        {
            for(k=sum/2;k>=homework[j];k--)
            dp[k]=max(dp[k],dp[k-homework[j]]+homework[j]);
        }

        // 当前科目的最短时间 = 总时间 - 最接近sum/2的子集和
        t+=sum-dp[sum/2];
        for(int j=1;j<=sum/2;j++)dp[j]=0;
    }
    cout<<t;
    return 0;
}