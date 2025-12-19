// //t了
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;
// string citys[N];
// string country[N];
// int n;
// string GetTwo(string s)
// {
//     string res="";
//     res+=s[0];
//     res+=s[1];
//     return res;
// }
// int main()
// {
//     //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     //双重循环
//     cin>>n;
//     int cnt=0;//统计特殊的城市
//     for(int i=1;i<=n;i++)
//     {
//         cin>>citys[i]>>country[i];
//     }
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=i+1;j<=n;j++)
//         {
//             //比较i和j下标的两个城市
//             if(GetTwo(citys[i])==country[j]&&GetTwo(citys[j])==country[i])cnt++;
//         }
//     }
//     cout<<cnt;
//     return 0;
// }


// //想到使用map了 但还是不知道到底怎么用
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// map<int,int>mp[N];//mp[A][B]:城市的前两个字母是A并且州的前两个字母是B
// int n;
// int ans=0;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         string a,b;cin>>a>>b;
//         int A=a[0]*26+a[1];
//         int B=b[0]*26+b[1];
//         mp[A][B]++;
//         if(A!=B)//题目中说了同一个州不会有两个同名的城市
//         {
//             ans+=mp[B][A];// 因A≠B，两城市来自不同的州（之前的州是A，当前的州是B），满足所有条件
//         }
//     }
//     cout<<ans<<endl;
//     return 0;
// }



