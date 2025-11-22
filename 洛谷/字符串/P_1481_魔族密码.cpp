//字符串版最长上升子序列。
// strstr（C 风格）	找子串在主串中的地址	strstr(s[i], s[j]) == s[i]	无需手动判长度，代码简洁	逻辑间接（需理解地址），char [] 专用
// substr（string）	截取子串生成新字符串	s[i].substr(0, len_j) == s[j]	逻辑最直观（直接比前缀）	需手动判长度，代码稍长
// find（string）	找子串在主串中的索引	s[i].find(s[j]) == 0	逻辑直观，代码简洁	需手动判长度，string 专用

// #include<bits/stdc++.h>
// using namespace std;
// char s[2010][80];
// int f[2010];
// int n,ans;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>s[i];
//         f[i]=1;
//         //查找i之前的字符串 看s[i]中是否包含s[j]这个子串
//         for(int j=i-1;j>=1;j--)
//         {
//             if(strstr(s[i],s[j])==s[i])//注意这个函数 查找子串在主串中的位置（返回地址）
//             {
//                 f[i]=max(f[i],f[j]+1);
//             }
//         }
//         ans=max(f[i],ans);
//     }

//     cout<<ans;
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
char s[2003][80];
int f[2003];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        f[i]=1;
        for(int j=i-1;j>=1;j--)
        {
            if(strstr(s[i],s[j])==s[i])
            f[i]=max(f[i],f[j]+1);
        }
        ans=max(ans,f[i]);
    }
    cout<<ans;
    return 0;
}