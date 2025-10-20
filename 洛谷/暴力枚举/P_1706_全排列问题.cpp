// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=1e4+11;
// int b[N];
// bool st[N];
// void dfs(int x)
// {
//     if(x>n)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             printf("%5d",b[i]);
//         }
//         cout<<endl;
//         return;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!st[i])
//         {
//             st[i]=1;
//             b[x]=i;
//             dfs(x+1);

//             st[i]=0;
//         }
//     }
// }
// int main()
// {
//     //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     dfs(1);
//     return 0;
// }

