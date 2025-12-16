// #include<bits/stdc++.h>
// using namespace std;
// int n,k;
// const int N=5e6+11;
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=0;i<n;i++)cin>>a[i];
//     nth_element(a,a+k,a+n);
//     cout<<a[k]<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e6+11;
int a[N];
void quicksort(int l,int r)
{
    int i=l,j=r,mid=a[(l+r)/2];
    do
    {
        while(a[j]>mid)j--;
        while(a[i]<mid)i++;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);

    if(k<=j)quicksort(l,j);
    else if(i<=k)quicksort(i,r);
    else 
    {
        cout<<a[j+1];
        exit(0);
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];

    quicksort(0,n-1);
    return 0;
}