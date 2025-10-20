// //这里面的小细节很多 调试了好久才过
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int x;cin>>x;
//     //先转换成二进制
//     string s="";
//     while(x)
//     {
//         s+=x%2+'0';
//         x/=2;
//     }
//     reverse(s.begin(),s.end());//注意字符串这种用法 经常忘记
//     //cout<<"S= "<<s;

//     //添加前导0
//     int len=s.size();
    
//     //注意这里的是< 并不是<=
//     while(len<32)
//     {
//         string s1="0";//注意这行代码的位置
//         s1+=s;
//         s=s1;
//         len++;
//     }

//     //cout<<"S="<<s;
//     string before="";
//     string after="";
//     for(int i=0;i<16;i++)
//     {
//         before+=s[i];
//         after+=s[i+16];
//     }
//     after+=before;
//    // cout<<after<<" ";
//     int ans=0;
//     for(int i=0;i<after.size();i++)
//     {
//         ans=ans*2+after[i]-'0';
//     }
//    cout<<ans;
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int x;cin>>x;
    string s="";
    //先转换成二进制
    while(x)
    {
        s+=x%2+'0';
        x/=2;
    }
    reverse(s.begin(),s.end());
    int n=s.size();
    //好聪明啊（自己想到的）
    while(n<32)
    {
        string s1="0";//这行代码的位置很重要
        s1+=s;
        s=s1;
        n++;
    }
    int ans=0;
    string before="",after="";
    for(int i=0;i<16;i++)
    {
        before+=s[i];
        after+=s[i+16];
    }
    after+=before;
    for(int i=0;i<32;i++)
    {
        ans=ans*2+after[i]-'0';
    }
    cout<<ans;
    return 0;
}