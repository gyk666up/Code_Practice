// // //暴力
// // // #include<bits/stdc++.h>
// // // using namespace std;
// // // int n;
// // // const int N=5e5+11;
// // // int a[N];
// // // int main()
// // // {
// // //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// // //     cin>>n;
// // //     for(int i=1;i<=n;i++)cin>>a[i];

// // //     int ans=0;
// // //     for(int i=1;i<=n;i++)
// // //     {
// // //         for(int j=i+1;j<=n;j++)
// // //         {
// // //             if(a[i]>=a[j])
// // //             {
// // //                 ans++;
// // //             }
// // //         }
// // //     }
// // //     cout<<ans;
// // //     return 0;
// // // }


// // #include<bits/stdc++.h>
// // using namespace std;
// // typedef long long ll; // 逆序对数量可能很大，需用long long

// // ll merge_sort(vector<int>& a, int l, int r) {
// //     if (l >= r) return 0;
// //     int mid = (l + r) / 2;
// //     ll cnt = merge_sort(a, l, mid) + merge_sort(a, mid+1, r); // 统计左右子数组逆序对
    
// //     // 合并两个有序子数组
// //     vector<int> temp(r-l+1);
// //     int i = l, j = mid+1, k = 0;
// //     while (i <= mid && j <= r) {
// //         if (a[i] <= a[j]) {
// //             temp[k++] = a[i++];
// //         } else {
// //             temp[k++] = a[j++];
// //             cnt += mid - i + 1; // 左数组i~mid都大于a[j]，逆序对+mid-i+1
// //         }
// //     }
// //     // 处理剩余元素
// //     while (i <= mid) temp[k++] = a[i++];
// //     while (j <= r) temp[k++] = a[j++];
// //     // 拷贝回原数组
// //     for (int p = 0; p < temp.size(); p++) a[l+p] = temp[p];
// //     return cnt;
// // }

// // int main() {
// //     ios::sync_with_stdio(0), cin.tie(0);
// //     int n; cin >> n;
// //     vector<int> a(n);
// //     for (int i = 0; i < n; i++) cin >> a[i];
// //     cout << merge_sort(a, 0, n-1) << endl;
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int n;
// const int N=5e5+11;
// int a[N];
// int merge_sort(int l,int r)
// {
//     //这行代码非常关键，缺少这行代码直接就会导致mle
//     //当子数组长度为 1（l == r）或非法（l > r）时，应该返回 0（没有逆序对），否则递归会无限调用自身，最终导致栈溢出崩溃。
//     if(l>=r)return 0;
//     int mid=(l+r)/2;
//     int cnt=merge_sort(l,mid)+merge_sort(mid+1,r);

//     vector<int>temp(r-l+1);
//     int i=l,j=mid+1,k=0;
//     while(i<=mid&&j<=r)
//     {
//         if(a[i]<=a[j])
//         {
//             //这里的i++别忘记
//             temp[k++]=a[i++];
//         }
//         else
//         {
//             temp[k++]=a[j++];
//             cnt+=mid-i+1;//此时a[i]>a[j]满足逆序的条件
//         }
//     }
//     while(i<=mid)temp[k++]=a[i++];
//     while(j<=r)temp[k++]=a[j++];

//     for(int i=0;i<temp.size();i++)a[l+i]=temp[i];

//     return cnt;//注意⚠️要有返回值 否则会无限递归下去
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     int ans=merge_sort(1,n);
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans;
const int N=5e5+11;
int a[N];
void merge_sort(int l,int r)
{
    if(l>=r)return ;

    int mid=(l+r)/2;
    merge_sort(l,mid),merge_sort(mid+1,r);

    int i=l,j=mid+1;
    int k=0;
    vector<int>temp(r-l+1);
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else
        {
            ans+=mid-i+1;
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)temp[k++]=a[i++];
    while(j<=r)temp[k++]=a[j++];

    for(int i=0;i<k;i++)a[l+i]=temp[i];
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    merge_sort(1,n);
    cout<<ans;
    return 0;
}