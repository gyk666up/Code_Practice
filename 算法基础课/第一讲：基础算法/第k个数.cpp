#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+66;
int a[N];
int n,k;
void quick_select(int a[],int l,int r,int k)
{
    if(l==r)
    {
        cout<<a[l];
        return ;
    }
    int i=l-1,j=r+1;
    int x=a[(l+r)>>1];
    while(i<j)
    {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j)swap(a[i],a[j]);
    }
    //左边区间 l,j 这样区间 是到j 不是到j-1
    if(j-l+1>=k)
    {
        quick_select(a,l,j,k);
    }
    else quick_select(a,j+1,r,k-(j-l+1));

}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    quick_select(a,1,n,k);
    return 0;
}