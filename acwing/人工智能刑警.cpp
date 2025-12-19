#include<bits/stdc++.h>
using namespace std;
const int N=2e4+66;
int a[N][12];
string name[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
        cin>>name[i];
    }
    while(1)
    {
        int b[12]={0};
        
        for(int i=0;i<m;i++)cin>>b[i];
        if(b[0]==0)break;
        int I=-1;//记录找到的罪犯
       bool found=0;
        for(int i=1;i<=n;i++)
        {
            bool f=1;
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==b[j])continue;
                f=0;
                if(!f)break;
            }
            if(f)
            {
                found=1;
                I=i;
                break;
            }
        }
        if(found)cout<<name[I]<<endl;
          else cout<<"Pass\n";
        
    }
    
    return 0;
}