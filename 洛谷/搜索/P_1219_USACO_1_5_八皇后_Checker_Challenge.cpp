//毫无思路啊
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4;
// int n;
// vector<int>ans[N];//第一维存方案数 第二维存具体的方案
// void dfs(int x,int y)
// {

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     dfs(1,1);
//     return 0;
// }


//DFS 的本质是 “一行一行试，试到合法就往下行走，走不通就回头换列”，对应代码中dfs(rank)的参数rank表示 “当前正在处理第rank行”。

#include<bits/stdc++.h>
using namespace std;
int m1[30];//m1[i]=1表示第i列有棋子了
int m2[30];//m2[i+j]逆对角线上的元素和为定值
int m3[30];//m3[i-j+n]主对角元素 +n是防止越界
int ans[30];
int n;
int mark=0;//方案数
//rank 行
void set_value(int rank,int line,int x)
{
    ans[rank]=line;
    m1[line]=x;
    m2[rank+line]=x;
    m3[rank-line+n]=x;
    return;
}
void dfs(int rank)
{
    if(rank>n)
    {
        mark++;
        if(mark<=3)
        {
            for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
            cout<<endl;
        }
        return;
    }
    //i是列
    for(int i=1;i<=n;i++)
    {
        if(m1[i]||m2[rank+i]||m3[rank-i+n])continue;//对应的位置已经有元素了
        set_value(rank,i,1);
        dfs(rank+1);
        set_value(rank,i,0);
        //这一这三行代码 以及为什么最后没有dfs(rank+1)的原因  加入这一行代码就表示有行是空的 不可能会符合条件的
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    dfs(1);
    cout<<mark;
    return 0;
}