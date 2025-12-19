// // #include<bits/stdc++.h>
// // using namespace std;
// // int main()
// // {
// //     int n;char x;cin>>n>>x;
// //     string s1,s2="";cin>>s1;
// //    //s2[0] = x;  // 错误：空字符串无法通过索引0访问
// //    s2+=x;
// //     for(int i=0;i<s1.size();i++)
// //     {
// //        if(s1[i]=='0')
// //        {
// //         if(islower(s2[i]))
// //         {
// //             s2+=toupper(s2[i]);
// //         }
// //         else 
// //         {
// //             s2+=tolower(s2[i]);
// //         }
// //        }
// //        else 
// //        {
// //             if(islower(s2[i]))
// //             {
// //                 if((s2[i])!='a')
// //                 {
// //                     s2+=char(s2[i]-1);
// //                 }
// //             }
// //             if(isupper(s2[i]))
// //             {
// //                 if((s2[i])!='Z')
// //                 {
// //                     s2+=char(s2[i]+1);
// //                 }
// //             }
// //        }
// //     }
// //     cout<<s2;
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     char x;
//     cin >> n >> x;
    
//     string rule, result;
//     cin >> rule;
    
//     result += x;  // 初始化结果字符串
    
//     for(int i=0; i<rule.size(); i++)
//     {
//         char current = result.back();  // 当前字符
        
//         if(rule[i] == '0')  // 规则0：切换大小写
//         {
//             if(islower(current))
//                 result += toupper(current);
//             else
//                 result += tolower(current);
//         }
//         else  // 规则1：生成前后字母
//         {
//             if(islower(current))
//             {
//                 if(current != 'a')  // 非a的小写字母
//                     result += char(current - 1);
//                 else
//                     result += current;  // a无前字母，保持不变
//             }
//             else if(isupper(current))
//             {
//                 if(current != 'Z')  // 非Z的大写字母
//                     result += char(current + 1);
//                 else
//                     result += current;  // Z无后字母，保持不变
//             }
//         }
//     }
    
//     cout << result << endl;
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;
const int N=1e4+55;
char t[N];
int main()
{
    int n ;char m;cin>>n>>m;
    string s="";
    for(int i=0;i<n;i++)cin>>t[i];
    s+=m;
    for(int i=0;i<n;i++)
    {
        if(islower(s[i]))
        {
            if(t[i]=='0')
            {
                s+=toupper(s[i]);
            }
            else
            {
                if(t[i]=='1'&&s[i]!='a')
                {
                    s+=char(s[i]-1);
                }
            }
        }
        else
        {
            if(t[i]=='0')
            {
                s+=tolower(s[i]);
            }
            else
            {
                if(t[i]=='1'&&s[i]!='Z')
                {
                    s+=char(s[i]+1);
                }
            }
        }
    }
    cout<<s<<endl;
    return 0;
}

















