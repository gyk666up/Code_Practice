#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
const int N=1e5+11;
int ans[N];//存01
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        string s;cin>>s;
        mp[s]=1;
    }
    int m;cin>>m;
    int is=0;
    for(int i=1;i<=m;i++)
    {
        string;cin>>s;
        if(mp.find(s)!=string::npos)
        {
            mp[s]++;
            ans[i]=1;
            is++;
        }
        else ans[i]=0;
    }

    for(int i=1;i<=m;i++)cout<<ans[i];
    cout<<fixed<<setprecision(2)<<100.0*is/m<<endl;

    int Max=0;
    string s;//保留最后要输出的字符串
    for(auto t:mp)
    {
        if(t.second>Max)
        {
            Max=t.second;
            s=t.first;
        }
    }
    cout<<s;
    return 0;
}