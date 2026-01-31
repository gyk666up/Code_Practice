// // //有一个点t了
// // #include<bits/stdc++.h>
// // using namespace std;
// // const int N=8e4+11;
// // int a[N];
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int n;cin>>n;
// //     for(int i=1;i<=n;i++)cin>>a[i];
// //     int ans=0;
// //     //优化的思想 如果后面的比前面的大之间加上前面的+1不久行了吗 不对啊
// //     int before=0;;
// //     for(int i=n;i>=1;i--)
// //     {
// //         bool flg=1;
// //         int j=i+1;
// //         int temp=0;
// //         while(j<=n&&a[j]<a[i])
// //         {
// //             temp++;
// //             j++;
// //         }
// //         ans+=temp;
// //     }
// //     cout<<ans;
// //     return 0;
// // }


// 👉 “右侧第一个不小于自己的位置” + 区间计数
// 这种问题的标准解法就是——✅ 单调栈（Monotonic Stack）
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     long long ans = 0;
//     stack<long long> st;

//     for (int i = 1; i <= n; i++) {
//         long long h;
//         cin >> h;

//         while (!st.empty() && st.top() <= h) {
//             st.pop();
//         }

//         ans += st.size();
//         st.push(h);
//     }

//     cout << ans << '\n';
//     return 0;
// }





// //单调栈
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     stack<int>stk;
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         int h;cin>>h;
//         while(stk.empty()==0&&stk.top()<=h)
//         {
//             stk.pop();
//         }
//         ans+=stk.size();//前面有多少个位置能看到这个羊
//         stk.push(h);
//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans=0;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    stack<int>stk;
    for(int i=1;i<=n;i++)
    {
        int h;cin>>h;
        while(stk.size()&&stk.top()<=h)
        {
            stk.pop();
        }
        ans+=stk.size();

        stk.push(h);
    }
    cout<<ans;
    return 0;
}