// //我去好强啊

// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// char s[N];
// int kmp[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;//这个信息其实就没有必要
//     cin>>s+1;
//     int j=0;
//     //int n=strlen(s+1);
//     for(int i=2;i<=n;i++)
//     {
//         while(j&&s[j+1]!=s[i])
//         j=kmp[j];

//         if(s[j+1]==s[i])j++;

//         //kmp[j]=j;
//         kmp[i]=j;//注意这里！！！
//     }
//     cout<<n-kmp[n];
//     return 0;
// }



