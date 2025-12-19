#include<bits/stdc++.h>
using namespace std;
const int N=100;
char g[N][N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    while(m--)
    {
        string s;cin>>s;
        int zi=0,mu=0;
        if(s.find('/')!=string::npos)
        {
            for(int i=0;s[i]!='/';i++)
            {
                zi=zi*10+s[i]-'0';
            }
            i++;
            for(;s[i];i++)
            {
                mu=mu*10+s[i]-'0';
            }
        }
        else if(s.find(';')!=string::npos)
        {
            for(int i=0;s[i]!=';';i++)
            {
                zi=zi*10+s[i]-'0';
            }
            i++;
            for(;s[i];i++)
            {
                mu=mu*10+s[i]-'0';
            }
        }
        //普通数字
        else{
            int sum=stoi(s);
            int zi=sum/100;
            int mu=sum%100;
        }
        g[zi][mu]='#';
    }
    for(int n;i>=1;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(g[i][j])cout<<g[i][j];
            else cout<<".\n";
        }
    }
    return 0;
}