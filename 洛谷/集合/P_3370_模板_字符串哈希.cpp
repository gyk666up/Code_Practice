//map
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=1e4+11;
// string words[N];
// map<string,bool>mp;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         cin>>words[i];
//         mp[words[i]]=1;
//     }
//     cout<<mp.size();

//     return 0;
// }

// //set//自动去重
// #include<bits/stdc++.h>
// using namespace std;
// set<string>q;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         string s;cin>>s;
//         q.insert(s);
//     }
//     cout<<q.size();
//     return 0;
// }


//哈希

// //哈希
// #include<bits/stdc++.h>
// using namespace std;
// const int mod=1000;
// const int N=10000;
// vector<string>mp[N];
// int ans=0;
// void judge(string s)
// {
//     int x=0;                        //注意这里并不需要减去-'0'这是字符转数字的做法
//     for(int i=0;i<s.size();i++)x=(x*130+s[i])%mod;
//     //它不是唯一的选择（131、127 等更优），但完全能满足题目需求，是 “性价比高” 的合理决策。
//     //130并没有什么特殊的含义
//     for(int i=0;i<mp[x].size();i++)
//     {
//         string j=mp[x][i];
//         if(j==s)return ;
//     }
//     mp[x].push_back(s);
//     ans++;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     string s;
//     for(int i=0;i<n;i++)
//     {
//         cin>>s;
//         judge(s);
//     }
//     cout<<ans;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int p=1e3;
const int N=1e4;
vector<string>v[N];
int ans=0;
void judge(string s)
{
    int x=0;
    for(int i=0;i<s.size();i++)
    {
        x=(x*130+s[i])%p;
    }
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==s)return ;
    }
    v[x].push_back(s);
    ans++;

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        judge(s);
    }
    cout<<ans<<endl;
    return 0;
}





