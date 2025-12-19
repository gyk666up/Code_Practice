//以前明明写过的题 再做还是不会写！！！！！！！
#include<bits/stdc++.h>
using namespace std;
int a[10];
int s1,s2,s3,s4;
int homework[30],dp[3000];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=1;i<=4;i++)cin>>a[i];
    int t=0;
    for(int i=1;i<=4;i++)
    {
        int sum=0;
        for(int j=1;j<=a[i];j++)
        {
            cin>>homework[j];
            sum+=homework[j];
        }
        for(int j=1;j<=a[i];j++)
        {
            for(int k=sum/2;k>=homework[j];k--)
            {
                dp[k]=max(dp[k],dp[k-homework[j]]+homework[j]);
            }
        }
         t+=sum-dp[sum/2];//累加为另一个脑子
		for(j=1;j<=sum/2;j++)
		dp[j]=0;//清零
    }
    cout<<t;
    return 0;
}

//一维
#include<bits/stdc++.h>
using namespace std;
int a[5],i,j,k,sum,t,homework[21],dp[2501];
int main(){
	for(i=1;i<=4;i++)
		cin>>a[i];
	for(i=1;i<=4;i++){
		sum=0;	
		for(j=1;j<=a[i];j++)
			{cin>>homework[j];//输入
			sum+=homework[j];}//总时间累加
		for(j=1;j<=a[i];j++)
			for(k=sum/2;k>=homework[j];k--)//只要是总和的一半
				dp[k]=max(dp[k],dp[k-homework[j]]+homework[j]);//01背包
		t+=sum-dp[sum/2];//累加为另一个脑子
		for(j=1;j<=sum/2;j++)
		dp[j]=0;//清零
	}
	cout<<t;//输出
	return 0;
}


//二维
// //动态数组也忘记了
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int s[5];  // 存储4科的题目数量
//     for (int i = 1; i <= 4; i++) {
//         cin >> s[i];
//     }

//     int total_time = 0;  // 总最短时间

//     // 处理每科
//     for (int subject = 1; subject <= 4; subject++) {
//         int n = s[subject];  // 当前科目的题目数量
//         vector<int> time(n + 1);  // 存储每道题的时间（1-based索引）
//         int sum = 0;  // 当前科目的总时间

//         // 读入题目时间并计算总和
//         for (int i = 1; i <= n; i++) {
//             cin >> time[i];
//             sum += time[i];
//         }

//         // 二维DP数组：dp[i][j]表示"考虑前i道题时，总时间不超过j的最大可能时间和"
//         // 行：0~n（题目数量），列：0~sum/2（最大容量）
//         vector<vector<int>> dp(n + 1, vector<int>(sum / 2 + 1, 0));

//         // 填充DP数组
//         for (int i = 1; i <= n; i++) {  // 遍历每道题
//             for (int j = 0; j <= sum / 2; j++) {  // 遍历所有可能的时间容量
//                 // 情况1：不选第i道题，直接继承前i-1道题的结果
//                 dp[i][j] = dp[i - 1][j];

//                 // 情况2：如果容量足够，考虑选第i道题（取两种情况的最大值）
//                 if (j >= time[i]) {
//                     dp[i][j] = max(dp[i][j], dp[i - 1][j - time[i]] + time[i]);
//                 }
//             }
//         }

//         // 当前科目的最短时间 = 总时间 - 最接近sum/2的子集和
//         total_time += sum - dp[n][sum / 2];
//     }

//     cout << total_time << endl;//处理完当前科目的所有题后 只累加1次
//     return 0;
// }


// //搜索（暴力）2^n
// #include<bits/stdc++.h>
// using namespace std;
// int s[5];
// int a[21][5];
// int Left,Right,minn,ans;
// void search(int x,int y)//x是当前科目y的第几个作业
// {
//     if(x>s[y]){
//         minn=min(minn,max(Left,Right));
//         return;
//     }

//     //左脑选
//     Left+=a[x][y];
//     search(x+1,y);
//     Left-=a[x][y];//注意回溯
    
//     //右脑选
//     Right+=a[x][y];
//     search(x+1,y);
//     Right-=a[x][y];
//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>s[1]>>s[2]>>s[3]>>s[4];
//     for(int i=1;i<=4;i++)
//     {
//         Left=Right=0;
//         minn=0x3f3f3f3f;
//         for(int j=1;j<=s[i];j++)
//         {
//             cin>>a[j][i];//注意这里的输入
//         }
//         search(1,i);
//         ans+=minn;
//     }
//     cout<<ans;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int s[5];
// int Left,Right;
// int a[5][25];
// int Min;
// void dfs(int x,int y)//x当前是第几个科目 y表示第几个习题
// {
//     // if(x>4)
//     //一次大的dfs只决定一个科目
//     if(y>s[x])
//     {
//         Min=min(Min,max(Left,Right));
//         return;
//     }

//     Left+=a[x][y];
//     dfs(x,y+1);
//     Left-=a[x][y];
    
//     Right+=a[x][y];
//     dfs(x,y+1);
//     Right-=a[x][y];

//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>s[1]>>s[2]>>s[3]>>s[4];
//     int ans=0;
//     for(int i=1;i<=4;i++)
//     {
//         Min=0x3f3f3f3f;
//         Left=0,Right=0;
//         for(int j=1;j<=s[i];j++)
//         {
//             cin>>a[i][j];
//         }
//         dfs(i,1);
//         ans+=Min;
//     }
//     cout<<ans;
//     return 0;
// }