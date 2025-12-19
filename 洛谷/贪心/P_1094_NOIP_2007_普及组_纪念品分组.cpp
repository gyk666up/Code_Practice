#include<bits/stdc++.h>
using namespace std;
const int N=3e4+11;
int a[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int w;cin>>w;
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int i=1,j=n;
    int cnt=0;
    while(i<=j)
    {
        if(i==j)
        {
            cnt++;
            break;
        }
        if(a[i]+a[j]<=w)
        {
            cnt++;//分组个数+1
            i++;
            j--;
        }
        else
        {
            //a[j]自己单独一个
            j--;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}