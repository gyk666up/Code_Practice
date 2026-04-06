// //思路：只要栈顶元素<目标元素，就一直压入栈，（这是判断是否》max—size），while 结束后判断栈顶元素是否等于 x 如果不等于肯定不行
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int m,n,k;cin>>m>>n>>k;
//     while(k--)
//     {
//         vector<int>target(n);
//         for(int i=0;i<n;i++)cin>>target[i];

//         stack<int>s;

//         int curr_push=1;//即将要压入栈的数字
//         bool f=1;
//         for(int i=0;i<n;i++)
//         {
//             int x=target[i];
//             while(s.empty()||s.top()<x)
//             {
//                 s.push(curr_push);
//                 curr_push++;
//                 //不能放到这里 否则这个容量检查可能会被这个的 break 跳过
//                 //if(curr_push>n)break;//没有要压入栈的数字了
//                 if(s.size()>m)
//                 {
//                     f=0;
//                     break;
//                 }
//                 //这个位置
//                 if(curr_push>n)break;//没有要压入栈的数字了
//             }
//             //顶还是不是 x （要牢记获取 top 元素之前要判断一下 s.empty在 C++ 中，凡是见到 top() 或 pop()，前面必须紧跟一个 !empty() 或者在同一行逻辑里用 empty() || 做短路保护）
//             if(!f||s.empty()||s.top()!=x)
//             {
//                 f=0;
//                 break;
//             }

//             s.pop();
//         }
//         if(f)cout<<"YES\n";
//         else cout<<"NO\n";
//     }
//     return 0;
// }


//还是不熟
//思路：如果不是 top<x 一直压入 退出 while 后判断栈顶元素是否是x 如果不是的话 肯定就不符合
#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int a[N];
int main()
{
    int m,n,k;cin>>m>>n>>k;
    while(k--)
    {
        for(int i=0;i<n;i++)cin>>a[i];
        stack<int>s;
        bool f=1;
        int curr_push=1;//即将压入栈的数字
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            while(s.empty()||s.top()<x)
            {
                s.push(curr_push);
                if(s.size()>m)
                {
                    f=0;
                    break;
                }
                curr_push++;
                if(curr_push>n)break;//没有可以压入栈的元素了
            }

            if(!f||s.empty()||s.top()!=x)
            {
                f=0;
                break;
            }
            s.pop();//说明此时栈顶元素是x，可以弹出
        }
        if(f)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}