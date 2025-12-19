// //第一种方式 有一个点t了
// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// const int N=30;
// bool st[N];
// int a[N];
// int ans=0;
// bool is_prime(int x)
// {
//     if(x<=1)return false;
//    //这里如果写成 i<=x/i 就会超时  除法运算的耗时远高于乘法（硬件层面，除法需要更多时钟周期）
//     for(int i=2;i<=x/i;i++)
//     {
//         if(x%i==0)return false;
//     }
//     return true;
// }
// void dfs(int x)
// {
//     if(x>n)
//     {
//         int cnt=0;
//         int sum=0;
//         for(int i=1;i<=n;i++)
//         if(st[i])
//         {
//             cnt++;
//             sum+=a[i];
//         }
//         if(cnt==k&&is_prime(sum))
//         {
//             ans++;
//         }
//         return;
//     }

//     st[x]=1;
//     dfs(x+1);

//     st[x]=0;
//     dfs(x+1);
//     return;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
    
//     for(int i=1;i<=n;i++)cin>>a[i];
//     dfs(1);
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e6+11;
int a[N];
int b[N];
int ans=0;
bool is_prime(int x)
{
    if(x<=1)return false;
    //这里如果写成 i<=x/i 就会超时  除法运算的耗时远高于乘法（硬件层面，除法需要更多时钟周期）
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
void dfs(int x,int start)
{
    
    if(x>k)
    {
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            
            sum+=b[i];
        }
        if(is_prime(sum))ans++;
        return;
    }

    for(int i=start;i<=n;i++)
    {
        b[x]=a[i];
        dfs(x+1,i+1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(1,1);
    cout<<ans;
    return 0;
}




// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e6+11;
// int a[N];//存可选择的数字 
// int b[N];
// int n,k;
// int ans=0;
// //组合性枚举 
// bool is_prime(int x)
// {
// 	for(int i=2;i*i<=x;i++)
// 	{
// 		if(x%i==0)return false;
// 	}
// 	return true;
// }
// void dfs(int x,int start)
// {
// 	if(x>k)
// 	{
// 		int sum=0;
// 		for(int i=1;i<=k;i++)sum+=b[i];
// 		if(is_prime(sum))ans++;
// 		return ;
// 	}
// 	for(int i=start;i<=n;i++)
// 	{
// 		b[x]=a[i];
// 		dfs(x+1,i+1);
		
// 		b[x]=0;
// 	}
// 	return ;
// }
// int main()
// {
// 	cin>>n>>k;
// 	for(int i=1;i<=n;i++)cin>>a[i];
// 	dfs(1,1);
// 	cout<<ans;
// }