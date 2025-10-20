#include<bits/stdc++.h>
using namespace std;
const int N=1e5+99;
int f[N];//存每个人的实力
int n,ans=1e9;//ans记录最小组的最大人数（初始为极大值）
int siz[N],top,q[N];// siz: 各组人数；q: 各组下一个期望的实力值；top: 当前组数
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>f[i];
    sort(f+1,f+1+n);

    //q 数组的实际分组从下标 1 开始
    //！！！
    q[0]=1e9+1;  // 哨兵：避免二分查找越界（q[0]设为极大值，作为初始边界）
    
    for(int i=1;i<=n;i++)
    {
        int l=0,r=top;
    // 二分查找：找到最大的l，使得q[l] <= f[i]（即该组可以容纳f[i]）
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(f[i]>=q[mid])l=mid;
            else r=mid-1;
        }

        
    // 决定加入已有组还是新建组

        if(q[l]!=f[i])//新建组
        {
            siz[++top]=1;
            q[top]=f[i]+1;
        }
        else
        {
            siz[l]++;
            q[l]++;
        }
    }
    for(int i=1;i<=top;i++)ans=min(ans,siz[i]);
    cout<<ans<<endl;
    return 0;
}