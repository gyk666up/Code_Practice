// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string s;int k;cin>>s>>k;
//     int i;
//     //从左找第一个 n[i] > n[i+1] 的位置。
//     //找第一个n[i]<n[i+1]的位置可以吗
//     while(k)
//     {
//         for(i=0;s[i]<=s[i+1];)//找高峰
//         {
//             i++;
//         }
//         s.erase(i,1);
//         k--;
//     }
//     while(s[0]=='0'&&s.size()>1)//处理前导零
//     {
//         s.erase(0,1);
//     }
//     cout<<s<<endl;
//     return 0;
// }


// //2025/12/17这道题仍不会
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string s;int n;cin>>s>>n;
//     while(n--)
//     {
//         int i=0;
//         while(s[i]<=s[i+1])i++;
//         s.erase(i,1);
//     }
//     while(s[0]=='0'&&s.size()>1)s.erase(0,1);
//     cout<<s;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    int k;cin>>k;
    while(k)
    {
        int i=0;
        while(s[i]<=s[i+1])i++;
        s.erase(i,1);
        k--;
    }

    //最短长度也得是1
    while(s[0]=='0'&&s.size()>1)s.erase(0,1);
    for(int i=0;i<s.size();i++)cout<<s[i];
    return 0;
}