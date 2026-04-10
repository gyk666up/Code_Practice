// //差分吧这应该是
// //以为自己忘了，但并没有，主要是了解背后的原理了。
// #include<bits/stdc++.h>
// using namespace std;
// int n,p;
// const int N=5e6+11;
// int a[N];
// int diff[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>p;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         diff[i]=a[i]-a[i-1];
//     }
//     int min_=102;
//     while(p--)
//     {
//         int x,y,z;cin>>x>>y>>z;
//         diff[x]+=z;
//         diff[y+1]-=z;
        
//     }
//     for(int i=1;i<=n;i++)
//     {
//          a[i]=diff[i]+a[i-1];
//          min_=min(a[i],min_);
//      }
//     cout<<min_;

//     return 0;
// }



// //2025/12/19有点忘记了
// #include<bits/stdc++.h>
// using namespace std;
// int n,p;
// const int N=5e6+11;
// int a[N];
// int diff[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>p;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>a[i];
//         diff[i]=a[i]-a[i-1];//初始化啊，还是有点忘记了
//     }
//     while(p--)
//     {
//         int x,y,z;cin>>x>>y>>z;
//         diff[x]+=z;
//         diff[y+1]-=z;
//     }
//     int mina=0x3f3f3f3f;
//     for(int i=1;i<=n;i++)
//     {
//         a[i]=diff[i]+a[i-1];
//         // cout<<" "<<a[i];
//         // cout<<endl;
//         mina=min(mina,a[i]);
//     }
//     cout<<mina;

//     return 0;
// }

