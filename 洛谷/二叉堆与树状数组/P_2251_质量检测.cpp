// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11; //这个范围要大于a数组中最大的元素
// int q[N];//单调队列 存储是是在a数组中的下标
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     int h=1,t=0;
//     for(int i=1;i<=n;i++)
//     {
//         //头子针已经不在窗口里了 最左边i-m+1
//         while(h<=t&&q[h]<=i-m)h++;

//         //有点绕这句话，仔细揣摩一下
//         // 如果当前元素a[i]比队尾下标q1[t]对应的a[q1[t]]小，
//         // 说明q1[t]对应的元素不可能成为当前或未来窗口的最小值（因为a[i]更小且位置更靠右）；
//         while(h<=t&&a[i]<a[q[t]])t--;

//         //插入新元素 存储下标而非值
//         q[++t]=i;
//         if(i>=m)cout<<a[q[h]]<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1e6+11;
// int q[N];
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     int h=1,t=0;
//     for(int i=1;i<=n;i++)
//     {
//         //.         这个是q[h]<=i-m不是q[i]<=i-m
//         while(h<=t&&q[h]<=i-m)h++;
//         while(h<=t&&a[i]<a[q[t]])t--;//a[q[t]]永远不可能是最小值 因为a[i]比它小而且还在右边
//         // q[t++]=i;
//         q[++t]=i;
//         if(i>=m)cout<<a[q[h]]<<endl;
//     }
//     return 0;
// }



