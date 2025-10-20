//到底哪里有问题啊 可行域颠倒
//注意这道题木材加工题的区别 
// 在路标设置中，随着 x 增大，需要添加的路标数减少（单调递减），所以可行域在右侧。

// 在木材加工中，随着 x 增大，能切出的段数减少（单调递减），所以可行域在左侧。
//理解题目 到底求的是最大的最小值 还是最小的最大值
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100001;
int a[N];
int L,n,k;
//使最大距离最小
//路标数量越多->最小空旷指数越小

//
//随便举个例子
//路标个数 4  3  3 | 2
//距离：   20 30 40 50  应该一个在4 和3 之间分
//如果知道距离->路标数量

bool check(int x)//x为路标的距离
{
    int cnt=0;//统计路标个数 a[0]起点 L终点
    //两路标之间的距离d 如果x恰好等于x的话 那样其实不再需要
    for(int i=1;i<=n;i++)
    {
        if(a[i]-a[i-1]>x)
        cnt+=(a[i]-a[i-1]-1)/x;//两个路标之间可以在加几个路标
    }
    cnt+=(L-a[n]-1)/x;
    if(cnt>k)return 1;
    else return 0;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>L>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    //注意如果l写成1的话有一个点通不过
    //枚举距离
    int l=0,r=L+1;
    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            l=mid;
        }
        else 
        {
            r=mid;
        }
    }
    cout<<r;;
    return 0;
}

//我的习惯可能会违背题目的意思 但并不影响做题 
//就这样吧 否则还得来回颠倒 分是否是可行域

//这道题目可费了不少时间-2025-9-13
