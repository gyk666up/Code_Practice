#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int a[N];
int main()
{
    int n,l;cin>>n>>l;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int idx=1;
    while(l>=a[idx])
    {
        l++;
        idx++;
        if(idx>n)break;
    }
    cout<<l;
    return 0;
}