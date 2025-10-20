#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;int k;cin>>s>>k;
    int i;
    //从左找第一个 n[i] > n[i+1] 的位置。
    //找第一个n[i]<n[i+1]的位置可以吗
    while(k)
    {
        for(i=0;s[i]<=s[i+1];)//找高峰
        {
            i++;
        }
        s.erase(i,1);
        k--;
    }
    while(s[0]=='0'&&s.size()>1)//处理前导零
    {
        s.erase(0,1);
    }
    cout<<s<<endl;
    return 0;
}