//t了很多个点
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e6+11;
// int n,k;
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n-k+1;i++)
//     {
//         //if(k+i==n)break;
//         cout<<*max_element(a+i,a+k+i)<<endl;
//     }
//     return 0;
// }


//这种方法之前见过类似的
//单调队列
// #include <iostream>
// #include <cstdio>
// using namespace std;

// const int Max = 2000006;
// int a[Max];
// int q[Max];

// int main() {
//     int n, k;
//     scanf("%d%d", &n, &k);

//     for (int i = 1; i <= n; ++i)
//         scanf("%d", &a[i]);

//     int t = 1, w = 0;   // ✅ 正确初始化：空队列

//     for (int i = 1; i <= n; ++i) {
//         // 1. 弹出窗口外元素
//         while (t <= w && q[t] <= i - k)
//             t++;

//         // 2. 维护单调递减 插入的元素比最后一个元素大而且还在他后面 所有最后一个数永远不可能输出
//         while (t <= w && a[q[w]] < a[i])
//             w--;

//         // 3. 入队
//         q[++w] = i;

//         // 4. 输出
//         if (i >= k)
//             printf("%d\n", a[q[t]]);
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e6+11;
// int a[N];
// int q[N];//不是值，而是“下标队列”，用来维护滑动窗口里的候选最大值
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t=1,w=0;//首尾指针
//     int n,k;cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     for(int i=1;i<=n;i++)
//     {
//         //超过窗口范围的删去
//         while(t<=w&&q[t]<=i-k)t++;

//         while(t<=w&&a[q[w]]<a[i])w--;

//         // a[++q[w]]=i;

//         q[++w]=i;
//        // if(i>=k)cout<<i;
//        if(i>=k)
//        cout<<a[q[t]]<<endl;
//     }
//     return 0;
// }

// //单调递减队列 队头是最大值
// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// const int N=2e6+11;
// int q[N];
// int a[N];
// int t=1,w=0;//首尾指针
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         while(t<=w&&q[t]<=i-k)
//         {
//             t++;
//         }

//         while(t<=w&&a[q[w]]<a[i])
//         {
//             w--;
//         }
//         q[++w]=i;
//         if(i>=k)
//         {
//             cout<<a[q[t]]<<endl;
//         }
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=2e6+11;
int q[N];
int a[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    int t=1,w=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        while(t<=w&&q[t]<=i-k)t++;

        while(t<=w&&a[q[w]]<a[i])w--;

        q[++w]=i;

        if(i>=k)
        {
            cout<<a[q[t]]<<endl;
        }

    }
    return 0;
}