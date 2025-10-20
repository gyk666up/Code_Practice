// //爆内存（这种方法）
// // #include<bits/stdc++.h>
// // using namespace std;
// // typedef long long ll;
// // string s;ll n;
// // void dfs(int x)
// // {
// //     if(x==n+1)
// //     {
// //         return;
// //     }
// //     string temp=s;
// //     int length=s.size();
// //     // string wei=s[s.size()-1];
// //     // string shou=s[0];

// //     //这样可以直接交换吗？
// //     //可以！！！
// //     不对吧 曲解题目的意思了
// //     swap(s[length-1],s[0]);
// //     temp+=s;
// //     s=temp;
// //     dfs(x+1);
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>s;
// //     cin>>n;
// //     dfs(1);
// //     cout<<(s[s.size()-1]);
// //     return 0;
// // }



// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string s; long long n;
//     cin>>s>>n;
//     long long len=s.size();
//     while(len<n)
//     {
//         len*=2;
//     }

//     while(len>s.size())
//     {
//         long long half=len/2;
//         if(n>half)
//         {
//             //n在后半段
//             n-=half;
//             if(n==1)
//             {
//                 //对应前半段的最后一个字符
//                 n=half;
//             }
//             else
//             {
//                 //对应前半段的n-1的位置  理解旋转的含义
//                 n--;
//             }
//         }
//         len=half;
//     }
//     //(0-based索引)
//     cout<<s[n-1]<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;long long n;
    cin>>s>>n;
    long long len=s.size();
    while(len<n)
    {
        len*=2;
    }

    while(len>s.size())
    {
        long long half=len/2;
        if(n>half)
        {
            n-=half;
            if(n==1)
            {
                n=half;
            }
            else
            {
                n--;
            }

        }
        len=half;
    }
    cout<<s[n-1]<<endl;
    return 0;
}