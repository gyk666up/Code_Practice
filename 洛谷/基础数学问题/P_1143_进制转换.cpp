// //要做到闭着眼睛都得写出来
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     string s;cin>>s;
//     int all=0;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]>='A'&&s[i]<='F')
//         all=all*n+s[i]-'A'+10;
//         else 
//         all=all*n+s[i]-'0';
//     }
//     // cout<<all<<endl;
//     int m;cin>>m;
//     string after="";
//     while(all)
//     {
        
//         int x=all%m;
//         if(x>=10)
//         {
//             after+=x-10+'A';
//         }
//         else
//         {
//             after+=x+'0';
//         }
//         all/=m;
//     }
//     //after.reserve();
//     reverse(after.begin(), after.end());  // 正确反转字符串
//     cout<<after;
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     string s;cin>>s;
//     int m;cin>>m;
//     int x=0;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]-'A'>=0)
//         x=x*n+s[i]-'A'+10;
//         else 
//         x=x*n+s[i]-'0';
//     }
//     string res="";
//     while(x)
//     {
//         if(x%m<10)
//         res+=x%m+'0';
//         else
//         res+=x%m-10+'A';

//         x/=m;
//     }
//     reverse(res.begin(),res.end());
//     cout<<res;
//     return 0;
// }


























//秒了 2025/12/19
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    int m;cin>>m;
    int res=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        res=res*n+s[i]-'0';
        else
        res=res*n+s[i]-'A'+10;
    }

    string ss;
    while(res)
    {
        if(res%m<=9)
        ss+=res%m+'0';
        else ss+=res%m-10+'A';
        res/=m;
    }
    reverse(ss.begin(),ss.end());
    for(int i=0;i<ss.size();i++)
    {
        cout<<ss[i];
    }
    return 0;
}