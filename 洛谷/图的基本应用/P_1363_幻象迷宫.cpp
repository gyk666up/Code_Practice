#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1503;
char g[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>g[i][j];
            }
        }
    }
    
    return 0;
}