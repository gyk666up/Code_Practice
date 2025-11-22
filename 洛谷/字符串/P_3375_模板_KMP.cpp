// //完全不会
// // #include<bits/stdc++.h>
// // using namespace std;
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     string s1,s2;cin>>s1>>s2;

// //     return 0;
// // }


// #include<iostream>
// #include<cstring>
// #define MAXN 1000010
// using namespace std;
// int kmp[MAXN];
// int la,lb,j; 
// char a[MAXN],b[MAXN];
// int main()
// {
//     cin>>a+1;
//     cin>>b+1;
//     la=strlen(a+1);
//     lb=strlen(b+1);
//     for (int i=2;i<=lb;i++)
// 	   {     
// 	   while(j&&b[i]!=b[j+1])
//         j=kmp[j];    
//        if(b[j+1]==b[i])j++;    
//         kmp[i]=j;
//        }
//     j=0;
//     for(int i=1;i<=la;i++)
// 	   {
//           while(j>0&&b[j+1]!=a[i])
//            j=kmp[j];
//           if (b[j+1]==a[i]) 
//            j++;
//           if (j==lb) {cout<<i-lb+1<<endl;j=kmp[j];}
//        }

//     for (int i=1;i<=lb;i++)
//     cout<<kmp[i]<<" ";
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const  int N=1e6+11;
// char s1[N];
// char s2[N];
// int kmp[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>s1+1>>s2+1;
//     int n=strlen(s1+1);
//     int m=strlen(s2+1);
//     int j=0;


//     // 求next数组
//     for(int i=2;i<=m;i++)
//     {
//         while(j&&s2[j+1]!=s2[i])
//         {
//             j=kmp[j];
//         }
//         if(s2[i]==s2[j+1])
//         {
//             j++;
//         }
//         kmp[i]=j;
//     }



//     for(int i=1;i<=n;i++)
//     {
//         while(j&&s2[j+1]!=s1[i])
//         {
//             j=kmp[j];
//         }
//         if(s2[j+1]==s1[i])j++;

//         if(j==m)
//         {
//             cout<<i-j+1<<endl;
//             j=kmp[j];
//         }
//     }
//     for(int i=1;i<=m;i++)cout<<kmp[i]<<" ";
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
char a[N],b[N];
int kmp[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a+1>>b+1;
    int n=strlen(a+1);
    int m=strlen(b+1);
    int j=0;
    for(int i=2;i<=m;i++)
    {
        while(j&&b[i]!=b[j+1])
        j=kmp[j];

        if(b[i]==b[j+1])j++;

        kmp[i]=j;
    }

    j=0;
    for(int i=1;i<=n;i++)
    {
        while(j&&a[i]!=b[j+1])
        {
            j=kmp[j];
        }
        if(a[i]==b[j+1])j++;

        if(j==m)
        {
            cout<<i-j+1<<endl;
            j=kmp[j];
        }
    }
    for(int i=1;i<=m;i++)cout<<kmp[i]<<" ";
    return 0;
}