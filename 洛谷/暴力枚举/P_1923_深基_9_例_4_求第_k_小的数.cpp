// #include<bits/stdc++.h>
// using namespace std;
// const int N=5e6+66;
// int a[N];
// int n,k;
// void quicksort(int a[],int l,int r)
// {
//     if(l>=r)return;

//     int x=a[l],i=l-1,j=r+1;
//     while(i<j)
//     {
//         do i++;while(a[i]<x);
//         do j--;while(a[j]>x);
//         if(i<j)swap(a[i],a[j]);
//     }
//     //1<=j<=i<=r
//     if(k<=j)quicksort(a,l,j);
//     else if(i<=k)quicksort(a,j+1,r);
//     else{
//         printf("%d",a[j+1]);
//         exit(0);
//     }
// }
// int main()
// {
//    cin>>n>>k;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     quicksort(a,1,n);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
const int N=5e6+66;
int a[N];
int n,k;
void quicksort(int l,int r)
{
    int i=l,j=r,mid=a[(l+r)/2];
    do{
        while(a[j]>mid)
        j--;
        while(a[i]<mid)
        i++;
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }while(i<=j);

    if(k<=j)quicksort(l,j);
    else if(i<=k)quicksort(i,r);
    else{
        printf("%d",a[j+1]);
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