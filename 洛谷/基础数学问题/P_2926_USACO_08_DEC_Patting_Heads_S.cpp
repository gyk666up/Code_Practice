// //注意是谁除谁
// //题目的意思都理解错了🙅 只要Ai%Aj==0就拍头不是都拍 而且的话 不是一拍就回去，是全都判断一遍（走完一圈）才回去
// // #include<bits/stdc++.h>
// // using namespace std;
// // int n;
// // const int N=1e5+11;
// // int num[N];
// // int ans[N];
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n;
// //     for(int i=1;i<=n;i++)cin>>num[i];
// //     for(int i=1;i<=n;i++)
// //     {
// //         int t=num[i];
// //         int cnt=0;
// //         for(int j=(i+1)%n;j<=n;j=(j+1)%n)
// //         {
// //             if(j==i)continue;
// //             cnt++;
// //             if(num[j]%num[i]==0)
// //             {
// //                 ans[i]=cnt;
// //                 break;
// //             }
            
// //         }
// //     }
// //     for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;//A[i]最大1e6
// int cnt[N];//统计每个约束出现的次数
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     vector<int>A(n,0);
//     //注意如果写出vector<int>A(n,0)会有n个0在里面 后续再有数据放到A(如果是push_back的话)中并不影响A中开始放的0 因此那样写是错误的 可以直接cin>>A[i]这样写就会覆盖之前的0
//     for(int i=0;i<n;i++)
//     {
//         cin>>A[i];
//         cnt[A[i]]++;
//     }

//     for(int x:A)
//     {
//         int ans=0;
//         //这样找因数很高效 x的两个因数1个>=d一个<=d 分别是d和x/d
//         for(int d=1;d*d<=x;d++)
//         {
//             if(x%d==0)
//             {
//                 ans+=cnt[d];
//                 //注意这两行代码的位置以及作用
//                 if(d!=x/d)
//                 {
//                     ans+=cnt[x/d];
//                 }
//             }
            
//         }
//         //排除自己
//         cout<<ans-1<<endl;
//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// int cnt[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     vector<int>A(n,0);
//     for(int i=0;i<n;i++)
//     {
//         cin>>A[i];
//         cnt[A[i]]++;
//     }
//     for(int x:A)
//     {
//         //寻找x的因数 两个因数一个一定>=sqrt(x),一个<=sqrt(x)
//         int ans=0;//统计最后的拍头次数
//         for(int i=1;i*i<=x;i++)
//         {
//             if(x%i==0)
//             {
//                 ans+=cnt[i];
//                 if(i!=x/i)ans+=cnt[x/i];
//             }
//         }
//         //减去自身
//         ans--;
//         cout<<ans<<endl;
//     }

//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1000005;
int a[N],cnt[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        int ans=0;
        for(int d=1;d*d<=x;d++)
        {
            if(x%d==0)
            {
                ans+=cnt[d];
                if(x/d!=d)
                {
                ans+=cnt[x/d];
                }
            }
            
        }
        ans--;
        cout<<ans<<endl;
    }

    return 0;
}