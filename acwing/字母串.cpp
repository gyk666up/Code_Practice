#include<bits/stdc++.h>
using namespace std;
bool f(string s)
{
    for(int i=0;i+1<s.size();i++)
    {
        if(islower(s[i]))
        {
            if(s[i]!='a')
            {
                if(s[i+1]!=toupper(s[i])&&s[i+1]!=s[i]-1)return false;
            }else
            {
                if(s[i+1]!='A')return false;
            }
        }
        else
        {
            if(s[i]!='Z')
            {
                if(s[i+1]!=tolower(s[i])&&s[i+1]!=s[i]+1)return false;
            }
            else
            {
                if(s[i+1]!='z')return false;
            }
        }
    }
    return true;
}
void solve()
{
    string s;cin>>s;
    if(f(s))cout<<"Y\n";
    else cout<<"N\n";
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}