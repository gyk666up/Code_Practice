#include<bits/stdc++.h>
using namespace std;
const int N=1e5+66;
int a[N];
int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int sum=0;
    for(int i=1;i<=n/2;i++)
    {
        sum+=a[i];
    }
    
    int all=0;
    for(int i=1;i<=n;i++)
    {
        all+=a[i];
    }
    printf("Outgoing #: %d\n",n-n/2);
    printf("Introverted #: %d\n",n/2);
    printf("Diff = %d",all-sum-sum);
    return 0;
}