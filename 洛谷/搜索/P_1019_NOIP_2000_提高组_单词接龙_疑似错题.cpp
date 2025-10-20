// //以前写过的 还是不会！！！

// #include<bits/stdc++.h>
// using namespace std;
// int n;

// const int N=30;
// int g[N][N];//g[i][k]第i个字符是否能接到第j个字符（0） 
// string words[N];
// int used[N];//记录单词出现的次数 
// int res=0;//最长的长度 
// void dfs(string dragon,int x)
// {
// 	res=max(res,(int)dragon.size());
// 	used[x]++;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(g[x][i]&&used[i]<2)//如果used[i]=2 说明已经使用了两次 不可以再使用了 
// 		dfs(dragon+words[i].substr(g[x][i]),i);//注意substr如果只有一个参数说明直接到末尾 
// 	}
// 	 used[x]--;
// }
// int main()
// {
// 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>words[i];
// 	}
// 	char start;cin>>start;
// 	//计算两个单词的公共部分  包括自身 
// 	for(int i=0;i<n;i++)
// 	{
// 		for(int j=0;j<n;j++)
// 		{
// 			string a=words[i],b=words[j];
// 			for(int k=1;k<min(a.size(),b.size());k++)
// 			{
// 				if(a.substr(a.size()-k,k)==b.substr(0,k))
// 				{
// 					g[i][j]=k;
// 					break;
// 				}
// 			}
// 		 } 
// 	}
	
	
// 	for(int i=0;i<n;i++)
// 	{
// 		if(words[i][0]==start)
// 		{
// 			dfs(words[i],i);//!!!
// 		}
// 	}
// 	cout<<res;
// 	return 0; 
// } 

#include<bits/stdc++.h>
using namespace std;
const int N=30;
int g[N][N];
int n;
string words[N];
int used[N];//统计每个单词用了多少遍
int res=0;
void dfs(string dragon,int x)
{
    if(res<dragon.size())res=dragon.size();
    
    used[x]++;
    for(int i=1;i<=n;i++)
    {
        if(g[x][i]&&used[i]<2)
        {
            dfs(dragon+words[i].substr(g[x][i]),i);//删去开头的可以合并的单词 
        }
    }
    used[x]--;//回溯
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>words[i];
    char start;cin>>start;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            string a=words[i],b=words[j];
            for(int k=1;k<min(a.size(),b.size());k++)//k表示可以合并的单词
            {
                if(a.substr(a.size()-k,k)==b.substr(0,k))
                {
                    g[i][j]=k;
                    break;//一定要break 因为合并的是首尾的单词
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(words[i][0]==start)
        {
            dfs(words[i],i);
        }
    }
    cout<<res;
    return  0;
}