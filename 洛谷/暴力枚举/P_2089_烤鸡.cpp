#include<bits/stdc++.h>
using namespace std;
int n;
int res=0;//方案数
const int N=1e5+44;
int a[N][12];//前面是对应的方案数 后一维度对应的是可能的情况
int b[12];
void dfs(int x,int ans)//美味程度
{
    if(x>10)
    {
        if(ans==n){
        res++;
        //需要先将结果存起来 才能满足题目要求的输出顺序
        for(int i=1;i<=10;i++)
        a[res][i]=b[i];
        }
        return ;
    }
    for(int i=1;i<=3;i++)
    {   
        b[x]=i;
        dfs(x+1,ans+i);
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    dfs(1,0);
    cout<<res<<endl;
    for(int i=1;i<=res;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(j==1)
            cout<<a[i][j];
            else cout<<" "<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}