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




// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int x;cin>>x;
//     string s="";
//     //先转换成二进制
//     while(x)
//     {
//         s+=x%2+'0';
//         x/=2;
//     }
//     reverse(s.begin(),s.end());
//     int n=s.size();
//     //好聪明啊（自己想到的）
//     while(n<32)
//     {
//         string s1="0";//这行代码的位置很重要
//         s1+=s;
//         s=s1;
//         n++;
//     }
//     int ans=0;
//     string before="",after="";
//     for(int i=0;i<16;i++)
//     {
//         before+=s[i];
//         after+=s[i+16];
//     }
//     after+=before;
//     for(int i=0;i<32;i++)
//     {
//         ans=ans*2+after[i]-'0';
//     }
//     cout<<ans;
//     return 0;
// }


// //2025/12/19 莫问题！
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int x;cin>>x;
//     string s;
//     while(x)
//     {
//         s+=x%2+'0';
//         x/=2;
//     }
//     reverse(s.begin(),s.end());
//     int n=s.size();
//     while(n<32)
//     {
//         string temp="0";
//         temp+=s;
//         s=temp;
//         n++;
//     }
//     //cout<<s<<" ";
//     string a;
//     for(int i=0;i<16;i++)
//     {
//         a+=s[i];
//     }
//     //cout<<"A="<<a<<endl;;
//     string b;
//     for(int i=16;i<s.size();i++)b+=s[i];
//     b+=a;
//     int all=0;
//     for(int i=0;i<b.size();i++)
//     all=all*2+b[i]-'0';

//     cout<<all;
//     return 0;
// }

//问题不大
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    string s="";
    while(n)
    {
        s+=n%2+'0';
        n/=2;
    }
    reverse(s.begin(),s.end());
    int len=s.size();
    while(len<32)
    {
        string ss="0";
        ss+=s;
        s=ss;
        len++;
    }
    string before="",after="";
    for(int i=0;i<16;i++)
    {
        before+=s[i];
        after+=s[i+16];
    }
    //cout<<before<<" "<<after;
    after+=before;
    //cout<<"after= "<<after;
    int x=0;
    //注意after是2进制的
    for(int i=0;i<after.size();i++)
    {
        x=x*2+after[i]-'0';
       // cout<<x<<" ";
    }
    cout<<x;
    return 0;
}