// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// int a[N],b[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     //一个正循环 一个逆循环
//    // 对比看一下是否一下如果一样则输出yes 
//    int q;cin>>q;
//    while(q--)
//    {
//      int n;cin>>n;
//      for(int i=1;i<=n;i++)cin>>a[i];
//      for(int i=1;i<=n;i++)cin>>b[i];
//      bool flg=1;
//      for(int i=1,j=n;i<=n,j>=1;i++,j--)
//      {
//         if(b[j]==a[i])continue;
//         flg=0;
//      }
//      cout<<(flg?"Yes\n":"No\n");
//    }
// }

//理解出错了
//入栈和出栈不一定是完全相反的 也可以先部分入栈
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int poped[N],pushed[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int q;cin>>q;
    while(q--)
    {
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>pushed[i];
        for(int i=1;i<=n;i++)cin>>poped[i];
        stack<int>stk;

        int j=1;
        //遍历出栈的所有可能
        for(int i=1;i<=n;i++)
        {
            int x=pushed[i];
            stk.push(x);
            //入栈一个元素后，可能触发「连续多次出栈」（栈顶元素可能连续匹配出栈序列的多个元素），
            //必须使用while 不能使用if 如果入1 2 3  出3 2 1
            while(stk.size()&&stk.top()==poped[j])
            {
                stk.pop();
                j++;
            }
        }
        //注意这里是j+1
        if(j==n+1)cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}