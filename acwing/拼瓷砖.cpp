#include<bits/stdc++.h>
using namespace std;
const int N=1e3+1;
char g[N][N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)cin>>g[i][j];
    }
    map<pair<char,int>,int>cnt;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(g[i][j]=='*')continue;
            char s=g[i][j];
            int t=0;
            while(1)
            {
                int f=1;
                if(g[i+t][j+t]=='*'||i+t>=n+1||j+t>=m+1||!f)break;

                for(int u=i,v=j+t;u<=i+t;u++)
                {
                    if(g[u][v]!=s)f=0;
                }
                for(int u=i+t,v=j;v<=j+t;v++)
                {
                    if(g[u][v]!=s)f=0;
                }
                if(f)
                {
                   for(int u=i,v=j+t;u<=i+t;u++)
                    {
                         g[u][v]='*';
                     }
                      for(int u=i+t,v=j;v<=j+t;v++)
                    {
                         g[u][v]='*';
                     }
                }
                t++;
                cnt[make_pair(s,t)]++;
            }
        }
    }
    cout << cnt.size() << endl;
    for(const auto& item : cnt) 
    {
        // 濞戞搩鍘介弸鍐╂綇閹惧啿姣夌紒鈧潪鎵紣闁挎冻鎷�
        printf("濡増绮忔竟锟� = %c; 濠㈠爢鍐瘓 = %d; 闁轰椒鍗抽崳锟� = %d\n", item.first.first, item.first.second, item.second);
    }

    return 0;
}
