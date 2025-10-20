// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e5+11;
// int n;
// //下标表示第几艘船
// int time[N];
// map<int,bool>mp[N];//第一维是代表第几艘船 统计有多少个国籍
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int reach;cin>>reach;
//         time[i]=reach;
//         int num;cin>>num;
//         for(int j=0;j<num;j++)
//         {
//             int x;cin>>x;
//             if(!mp.count(x))mp[i][x]=1;
//         }
//         int ans=0; int last=time[i]-(int)86400;
//         for(int j=1;j<=n;j++)
//         {
//             //第j艘船符合条件
           
//             if(time[j]<=time[i]&&time[j]>last)
//             {
//                 ans+=mp[j].size();
//             }
//             else //当前的不符合 那之后的肯定更不符合 题目已经说输入的ti是递增的
//             {
//                 cout<<ans<<endl;
//                 break;
//             }
//         }
//     }
//     return 0;
// }

//万能头文件包含time的这个函数 所以数组名就不能取time




#include<bits/stdc++.h>
using namespace std;
#define int long long  // 避免大整数溢出（时间可能达1e9，乘客数总和达3e5）
const int N=2e6+5;    // 数组大小，需覆盖最大国籍数（1e5）和乘客数

int n;                // 船的总数量
int t, k;             // t：当前船的到达时间；k：当前船的乘客数量
int na[N];            // 计数数组：na[x]表示当前窗口内国籍x的乘客总数
int ans;              // 答案：当前窗口内不同国家的总数
int x;                // 临时变量：存储当前乘客的国籍

// 结构体：存储每个乘客的信息
struct node {
    int x;  // 乘客的国籍
    int t;  // 乘客所在船的到达时间（所有乘客共享船的到达时间）
} p;
queue<node> ship;     // 队列：维护“过去24小时内”的所有乘客（按到达时间顺序）
signed main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> t >> k;//到达时间，多少乘客
		while(!ship.empty())//查人
		{
			p=ship.front();//队头开始
			if(p.t+86400<=t)//24小时
			{
				na[p.x]--;//人数减一 
                //该国籍的人数从1减到0 说明这个窗口已经没有这个国籍了
				if(na[p.x]==0)ans--;//人没了，ans--;
				ship.pop();//出队
				continue;//继续搜；
			}
			break;//搜完了// 队头未过期，后续乘客更晚到达，均未过期（时间递增）
		}
		for(int j=1;j<=k;j++)//统计
		{
			cin >> x;
			p.x=x,p.t=t;//存入结构体
			ship.push(p);//
			na[x]++;//国的人++
			if(na[x]==1)ans++;//新国家的人
		}
		cout << ans << "\n";//输出
	}
 	return 0;
}


