//感觉可以写出来啊 怎么写不出来啊
//还是没理解题目的意思
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3;
// int nums[N];//数字
// char S[N];//运算符
// int id1=1,id2=1;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string s;cin>>s;
//     for(int i=0;i<s.size();i++)
//     {
//         if(isdigit(s[i]))
//         {
//             int num=0;
//             for(;isdigit(s[i]);i++)
//             {
//                 num=num*10+s[i]-'0';
//             }
//         }
//         else if(s[i]=='.')i++;
//         else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*')
//         {

//         }
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
stack<int>q;
string s;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            int num=0;
            for(;isdigit(s[i]);i++)
            num=num*10+s[i]-'0';
            q.push(num);
             i--;
            //这个i--非常细节！！！ 防止跳过元素 比如 3后面是. 循环到.时不符合条件退出循环 整个大循环i++跳过一个元素 所以用i--来抵消一次
        }
        else if(s[i]=='+')
        {
            int j=q.top();q.pop();
            int k=q.top();q.pop();
            q.push(k+j);//注意顺序
        }
        else if(s[i]=='-')
        {
            int j=q.top();q.pop();
            int k=q.top();q.pop();
            q.push(k-j);
        }
        else if(s[i]=='*')
        {
            int j=q.top();q.pop();
            int k=q.top();q.pop();
            q.push(k*j);
        }
        else if(s[i]=='/')
        {
            int j=q.top();q.pop();
            int k=q.top();q.pop();
            q.push(k/j);
        }
    }
    cout<<q.top();
    return 0;
}
