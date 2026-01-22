// // //超时
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // #define int long long
// // // const int N=1e6+11;
// // // int l,r;
// // // int cnt=0;
// // // void solve()
// // // {
// // //     //本来一开始想欧式筛法 但数组的范围不够

// // //     for(int i=l;i<=r;i++)
// // //     {
// // //         bool flg=1;//判断i是不是素数
// // //         for(int j=2;j*j<=i;j++)
// // //         {
// // //             if(i%j==0)
// // //             {
// // //                 flg=0;
// // //                 break;
// // //             }
// // //         }
// // //         if(flg)
// // //         cnt++;
// // //     }
// // //     return ;
// // // }
// // // signed main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>l>>r;
// // //     solve();
// // //     cout<<cnt;
// // //     return 0;
// // // }


// // //爆内存了
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // const int N=1e8+11;
// // // bool is_prime[N];
// // // // const int p=1e6;
// // // // //想用区间压缩方法～！但会影响这个算法啊。(其实就是不会写了)
// // // signed main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     int l,r;cin>>l>>r;
// // //     memset(is_prime,1,sizeof is_prime);
// // //     is_prime[0]=is_prime[1]=0;
// // //     for(int i=1;i*i<=r;i++)
// // //     {
// // //         if(is_prime[i])
// // //         for(int j=i*i;j<=r;j+=i)
// // //         {
// // //             is_prime[j]=0;
// // //         }
// // //     }
// // //     int cnt=0;
// // //     for(int j=l;j<=r;j++)
// // //     {
// // //         if(is_prime[j])cnt++;
// // //     }
// // //     cout<<cnt;
// // //     return 0;
// // // }



// // //埃氏筛的区间优化版
// // //牢牢记住 先明白背后的筛选原理
// // #include<bits/stdc++.h>
// // using namespace std;
// // int l,r;
// // #define int long long
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>l>>r;
// //     // 不超过√R的素数即可筛除[L,R]内的所有合数
// //     //任何一个合数 x（大于 1 的非素数），都至少有一个质因数（素数因子）不大于 \(\sqrt{x}\)。
// //     int max_n=sqrt(r);
// //     vector<bool>prime_small(max_n+1,true);
// //     vector<bool>prime_range(r-l+1,true);

// //     if(l==1)prime_range[0]=0;
// //     prime_small[0]=prime_small[1]=0;
// //     for(int i=2;i<=max_n;i++)
// //     {
// //         //先筛选出<=sqrt(r)的素数 用这些素数去选出在(l,r)区间内的合数
// //         if(prime_small[i])
// //         {
// //             for(int j=i*i;j<=max_n;j+=i)
// //             {
// //                 prime_small[j]=0;
// //             }

// //             int start=max(i*i,(l+i-1)/i*i);//用来保证从区间 [L, R] 的第一个有效倍数开始标记
// //             for(int j=start;j<=r;j+=i)
// //             prime_range[j-l]=false;
// //         }
// //     }
// //     int cnt=0;
// //     for(int i=l;i<=r;i++)
// //     {
// //         if(prime_range[i-l])cnt++;
// //     }
// //     cout<<cnt;
// //     return 0;
// // }






// // #include<bits/stdc++.h>
// // using namespace std;

// // #define int long long
// // const int N=1e6+11;
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int l,r;cin>>l>>r;
// //     int max_n=sqrt(r);
// //     //这里得是max_n+1
// //     vector<int>prime_small(max_n+1,1);

// //     //这个数组的大小可不是随便取的 而是正好是l-r区间的长度
// //     vector<int>prime_range(r-l+1,1);

// //     //是这样写 还是上面那种
// //     if(l==1)prime_range[1-l]=0;
// //     prime_small[0]=prime_small[1]=0;
// //     //先筛选出<=sqrt(r)的素数
// //     for(int i=2;i*i<=r;i++)
// //     {
// //         if(prime_small[i])
// //         {
// //             for(int j=i*i;j<=sqrt(r);j+=i)
// //             {
// //                 prime_small[j]=0;
// //             }

// //             int start=max((l+i-1)/i*i,i*i);
// //             for(int j=start;j<=r;j+=i)
// //             {
// //                 prime_range[j-l]=0;
// //             }
// //         }
// //     }
// //     int cnt=0;
// //     for(int i=l;i<=r;i++)
// //     {
// //         if(prime_range[i-l])cnt++;
// //     }
// //     cout<<cnt;
// //     return 0;
// // }





// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int l,r;cin>>l>>r;
// //     int maxn=sqrt(r);
// //     //注意默认值是1！！！  这里初始大小为maxn+1
// //     vector<int>prime_small(maxn+1,1);
// //     vector<int>prime_range(r-l+1,1);

// //     prime_small[0]=prime_small[1]=0;
// //     if(l==1)prime_range[0]=0;
// //     for(int i=1;i<=maxn;i++)
// //     {
// //         if(prime_small[i])
// //         {
// //             for(int j=i*i;j<=maxn;j+=i)
// //             {
// //                 prime_small[j]=0;
// //             }
// //             int start=max(i*i,(l+i-1)/i*i);

// //             for(int j=start;j<=r;j+=i)
// //             {
// //                 prime_range[j-l]=0;
// //             }
// //         }
// //     }
// //     int cnt=0;
// //     for(int i=l;i<=r;i++)
// //     {
// //         if(prime_range[i-l])cnt++;
// //     }

// //     cout<<cnt;
// //     return 0;
// // }


// //思路先筛选出<=sqrt(r)的素数 然后用这些素数筛选出l~r的素数
// //任何一个合数都有一个<=sqrt(r)的素因数
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int l,r;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>l>>r;
//     int maxn=sqrt(r);
//     vector<bool>prime_small(maxn+1,1);
//     vector<bool>prime_range(r-l+1,1);


//     prime_small[0]=prime_small[1]=0;
//     if(l==1)
//     {
//         prime_range[0]=0;
//     }

//     //注意i的范围 j的范围
//     for(int i=2;i<=maxn;i++)
//     {
//         if(prime_small[i])
//         {
//             for(int j=i*i;j<=maxn;j+=i)
//             {
//                 prime_small[j]=0;
//             }

//             int start=max(i*i,(l+i-1)/i*i);

//             for(int j=start;j<=r;j+=i)
//             {
//                 prime_range[j-l]=0;
//             }
//         }
//     }
//     int cnt=0;
//     for(int i=l;i<=r;i++)
//     {
//         if(prime_range[i-l])cnt++;
//     }
//     cout<<cnt;
//     return 0;
// }


//先筛选出sprt(r)内的素数，再筛选出（l,r）内的素数
#include<bits/stdc++.h>
using namespace std;
#define int long long
int l,r;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>l>>r;
    int maxn=sqrt(r);
    vector<bool>prime_small(maxn+1,1);
    vector<bool>prime_range(r-l+1,1);

    if(l==1)prime_range[0]=0;
    prime_small[0]=prime_small[1]=0;
    for(int i=2;i<=maxn;i++)
    {
        if(prime_small[i])
        {
            for(int j=i*i;j<=maxn;j+=i)
            {
                prime_small[j]=0;
            }
            int start=max((l+i-1)/i*i,i*i);
            for(int j=start;j<=r;j+=i)
            {
                prime_range[j-l]=0;
            }
        }
    }
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        if(prime_range[i-l])ans++;
    }
    cout<<ans;
    return 0;
}