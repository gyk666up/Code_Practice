// //单调队列一次只能维护一种极值

//错误的
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// int a[N];
// int q[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t=1,w=0;
//     int n,k;cin>>n>>k;
//     vector<int>min_,max_;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         while(t<=w&&q[t]<=i-k)t++;
//         while(t<=w&&a[q[w]]<a[i])w--;

//         q[++w]=i;
//         if(i>=k)
//         {
//             min_.push_back(a[q[w]]);
//             max_.push_back(a[q[t]]);
//         }
//     }
//     for(int i=0;i<min_.size();i++)cout<<min_[i]<<" ";
//     cout<<endl;

//     for(int i=0;i<max_.size();i++)cout<<max_[i]<<" ";
//     cout<<endl;
//     return 0;
// }


//递增队列维护最小值，递减队列维护最大值
//为什么这个一定对(简明版)
//qmin(最小值队列)队列里对应的 a[]单调递增·队头永远是当前窗口最小值
//qmax(最大值队列)队列里对应的 a[]单调递减·队头永远是当前窗口最大值
//在单调队列里：
// 👉 只有「队头」一定是当前窗口的答案
// 👉 队尾只是“候选人”，永远不能直接用来输出
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e6 + 5;
// int a[N];

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, k;
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++) {
//         cin >> a[i];
//     }

//     deque<int> qmin, qmax;  // 存下标

//     // 输出最小值
//     for (int i = 1; i <= n; i++) {
//         // 维护最小值：单调递增
//         while (!qmin.empty() && a[qmin.back()] > a[i])
//             qmin.pop_back();
//         qmin.push_back(i);

//         // 弹出窗口外元素
//         if (!qmin.empty() && qmin.front() <= i - k)
//             qmin.pop_front();

//         if (i >= k)
//             cout << a[qmin.front()] << " ";
//     }
//     cout << '\n';

//     // 输出最大值
//     for (int i = 1; i <= n; i++) {
//         // 维护最大值：单调递减
//         while (!qmax.empty() && a[qmax.back()] < a[i])
//             qmax.pop_back();
//         qmax.push_back(i);

//         // 弹出窗口外元素
//         if (!qmax.empty() && qmax.front() <= i - k)
//             qmax.pop_front();

//         if (i >= k)
//             cout << a[qmax.front()] << " ";
//     }
//     cout << '\n';

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
int a[N];
int q[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,k;cin>>n>>k;
    int t=1,w=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    for(int i=1;i<=n;i++)
    {
        while(t<=w&&q[t]<=i-k)t++;
        //递增队列 队头是最小值
        while(t<=w&&a[q[w]]>a[i])w--;

        q[++w]=i;
        if(i>=k)
        cout<<a[q[t]]<<" ";
    }
    cout<<endl;
    t=1,w=0;
    for(int i=1;i<=n;i++)
    {
        while(t<=w&&q[t]<=i-k)t++;
        //递增队列 队头是最小值
        while(t<=w&&a[q[w]]<a[i])w--;

        q[++w]=i;
        if(i>=k)
        cout<<a[q[t]]<<" ";
    }
    return 0;
}

