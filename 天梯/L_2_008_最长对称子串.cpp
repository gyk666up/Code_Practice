// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     string s;getline(cin,s);
//     int Max_le=-1;
//     for(int i=0;i<s.size();i++)
//     {
//         //以单个字符为中心
//         int l=i-1,r=i+1;
//         while(l>=0&&r<s.size()&&s[l]==s[r])
//         {
//             l--,r++;
//         }
//         //注意这行代码！！！
//         r--,l++;
//         Max_le=max(Max_le,r-l+1);

//         l=i,r=i+1;
//         while(l>=0&&r<s.size()&&s[l]==s[r])
//         {
//             l--,r++;
//         }
//         //！！！
//         r--,l++;
//         Max_le=max(Max_le,r-l+1);
//     }
//     cout<<Max_le<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;getline(cin,s);
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        //以单个字符为中心向两边扩展
        int l=i-1,r=i+1;
        while(i>=0&&r<s.size()&&s[l]==s[r])
        {
            l--,r++;
        }
        r--;l++;
        ans=max(ans,r-l+1);
        r=i+1,l=i;
        while(l>=0&&r<s.size()&&s[l]==s[r])
        {
            l--,r++;
        }
        r--;l++;
        ans=max(ans,r-l+1);
        
    }
    cout<<ans;
    return 0;
}