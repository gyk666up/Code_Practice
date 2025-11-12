// //有两个点t了
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     int ans=0;
//     int sum=1;
//     for(int i=2;i<=n;i++)
//     {
//         ans=0;        //注意这里是sqrt(i)不是sqrt(n)
//         for(int j=1;j<sqrt(i);j++)
//         {
//             if(i%j==0)ans+=2;
//         }
//         int temp=sqrt(i);
//         if(temp-sqrt(i)==0)ans++;
//         sum+=ans;
//     }
//     cout<<sum;
//     return 0;
// }



//我去👊好吊
//从数学的角度出发：1∼n 的因子个数，可以看成含有 2 这个因子的数的个数 + 含有 3 这个因子的数的个数 +⋯+ 含有 n 这个因子的数的个数。
// 在 1∼n 中含有“2”这个因子的数有  
// n/2个，含3有n/3个，以此类推，公式就出来了。
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     int ans=0;
//     for(int i=1;i<=n;i++)ans+=n/i;
//     cout<<ans;
//     return 0;
// }



//有技巧（筛）的暴力
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
int a[N];//a[i]表示含有i这个因子的个数
int n,s;
void H()
{
    for(int i=1;i<=n;i++)//i是因子
    {
        for(int j=i;j<=n;j+=i)//j是i的倍数
        a[j]++;

        s+=a[i];
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    H();//筛
    cout<<s;
    return 0;
}