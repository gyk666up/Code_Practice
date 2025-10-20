// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e4+11;
// int Mar[N];//火星人的初始排列
// int final[N];//最终结果
// int res=0;
// int n,m; 

// bool st[N];
// void dfs(int x)
// {
//     if(x>n)
//     {
//         res++;
//         if(res==m+1)
//         {
//             for(int i=1;i<=n;i++)
//             {
//                 if(i==1)cout<<final[i];
//                 else cout<<" "<<final[i];
//             }
//             cout<<endl;
//             exit(0);
//         }
//         return;
//     }
//     //这个很重要
//     //保证从给定的顺序向后找
//     for(int i=1;i<=n;i++)
//     {
//         if(!res)i=Mar[x];//!!!
//         if(!st[i])
//         {
//             st[i]=1;
//             //final[x]=Mar[i];
//             final[x]=i;
//             dfs(x+1);

//             st[i]=0;
//         }
//     }

// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)cin>>Mar[i];
//     dfs(1);
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (m--) next_permutation(a.begin(), a.end());
    for (int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? "\n" : " ");
    return 0;
}