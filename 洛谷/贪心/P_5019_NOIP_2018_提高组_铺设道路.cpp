#include<bits/stdc++.h>
using namespace std;
//每次尽量包含尽可能长的区域 这个想法直接但不容易写

//这个思路好，但有点绕
//题目说是让整段道路的下陷深度都为0 那么就说明一定可以达到这种情况
// 如果一个小坑旁有一个大坑 那么填完这个小坑的同时大坑也被填了一部分，（不要管到底是从哪到哪 也就是具体的区间）还需要填补大坑剩下的部分
//先默认把a[1]填好 区间有可能是[1,2],[1,4],[1,3]等 需要a[1]次
const int N=1e5+11;
int a[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    long long ans=0;
    ans+=a[1];

    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1])ans+=a[i]-a[i-1];
    }
    cout<<ans<<endl;
    return 0;
}