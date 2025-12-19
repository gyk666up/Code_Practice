// //感觉题目难 怎么就是做不出来呢

//思路不对
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=200;
// deque<int>q;
// bool st[N];//标记已经死的人
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         q.push_back(i);
//     }
//     int times=q.size();
//     while(times--)
//     {
//        // memset(st,0,sizeof st);
//         int id=0;
//         for(int i=1;i<=q.size();)
//         {
//             if(!st[q[i]])
//             {
//                 id++;
//                 if(id==m)
//                 {
//                 st[q[i]]=1;
//                 cout<<q[m]<<endl;
//                 break;
//                 }
//             }
//             i++;
//             i%=q.size();
//         }
        
//     }
//     return 0;
// }

//思路有点巧妙啊
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    queue<int>q;
    for(int i=1;i<=n;i++)q.push(i);
    while(!q.empty())
    {
        //将前m-1个人移动到队尾
        for(int i=1;i<m;i++)
        {
            q.push(q.front());
            q.pop();
        }
        //数到m的人现在在队首
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}