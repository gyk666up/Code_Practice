// //之前做过还是不熟啊
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// #define int long long
// const int N=5e5+11;
// int a[N];
// int ans;
// void merge_sort(int l,int r)
// {
//     if(l>=r)return ;

//     int mid=(l+r)/2;
//     merge_sort(l,mid),merge_sort(mid+1,r);

//     int i=l,j=mid+1;
//     vector<int>temp(r-l+1);
//     int k=0;
//     while(i<=mid&&j<=r)
//     {
//         if(a[i]<=a[j])
//         {
//             temp[k++]=a[i++];
//         }
//         else//a[i]>a[j] 说明从i到mid都是符合条件的
//         {
//             ans+=mid-i+1;
//             temp[k++]=a[j++];
//         }
//     }
//     while(i<=mid)temp[k++]=a[i++];
//     while(j<=r)temp[k++]=a[j++];

    
//     for(int i=0;i<k;i++)a[l+i]=temp[i];
// }
// signed  main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     merge_sort(1,n);
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+11;
int a[N];
int n;
int ans=0;
void merge_sort(int l,int r)
{
    if(l>=r)return ;
    int mid=(l+r)/2;

    int i=l,j=mid+1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    vector<int>temp(r-l+1);
    int k=0;
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