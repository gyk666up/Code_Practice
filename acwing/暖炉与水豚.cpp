#include<bits/stdc++.h>
using namespace std;
const int N=1e3+11;
int n,m;
char g[N][N];
typedef pair<int,int>PII;
vector<PII>ans;
bool find_(int x,int y,char s)
{
    for(int i=max(x-1,1);i<=min(x+1,n);i++)
    {
        for(int j=max(y-1,1);j<=min(y+1,m);j++)
        {
            if(i==x&&j==y)continue;
            if(g[i][j]==s)return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>g[i][j];
    }

    //找奇怪的暖水豚
    int x=-1,y=-1;//记录这个暖水豚的位置
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            //这个位置得是暖水豚并且其周围没有暖炉
            if(g[i][j]=='w'&&find_(i,j,'m'))
            {
                x=i;
                y=j;
            }
        }
    }
    //找可能的藏的位置 这个位置是.并且其周围没有冷水豚
    for(int i=max(x-1,1);i<=min(x+1,n);i++)
    {
        for(int j=max(y-1,1);j<=min(y+1,m);j++)
        {
            if(g[i][j]=='.'&&find_(i,j,'c'))
            {
                ans.push_back({i,j});
            }
        }
    }
    //之所以不用在排序了是因为 循环的顺序和和题目要求的输出顺序是一致的
    if((x==-1&&y==-1)||ans.size()==0)
    {
        cout<<"Too cold!\n";
    }
    else 
    {
        for(const auto t:ans)
        {
            cout<<t.first<<" "<<t.second<<endl;
        }
    }

    return 0;
}