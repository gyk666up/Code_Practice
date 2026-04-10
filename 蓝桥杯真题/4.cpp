// //思路是什么
// #include <iostream>
// using namespace std;

// int main() {
//     // 优化输入输出流速度
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int m;
//     cin >> m;
    
//     while (m--) {
//         long long n, k;
//         cin >> n >> k;
        
//         // k - 1 的二进制中 1 的个数
//         // __builtin_popcountll 是 C++ 编译器自带的神器函数，专门用来数 long long 二进制中 1 的个数
//         long long ones_count = __builtin_popcountll(k - 1);
        
//         // 偶数个 1 为红色，奇数个 1 为黑色
//         if (ones_count % 2 == 0) {
//             cout << "RED\n";
//         } else {
//             cout << "BLACK\n";
//         }
//     }
    
//     return 0;
// }

// #include <iostream>
// using namespace std;

// int coler(int n,int k)
// {
//   if(n==1) return 1;
//   if(k%2==1) return coler(n-1,(k+1)/2);
//   else return !coler(n-1,(k/2));
// }

// int main()
// {
//   int m;
//   scanf("%d",&m);
//   while(m--)
//   {
//     int n,k;
//     scanf("%d %d",&n,&k);
//     int res=coler(n,k);
//     puts(res==1?"RED":"BLACK");
//   }
//   return 0;
// }






#include<bits/stdc++.h>
using namespace std;
int m;
int n,k;
//1是红色
int getcolor(int n,int k)
{
    if(n==1)return 1;
    
    if(k%2==0)return !getcolor(n-1,k/2);
    else return getcolor(n-1,(k+1)/2);
}
int main()
{
    cin>>m;
    while(m--)
    {
    cin>>n>>k;
    int color=getcolor(n,k);
    if(color==1)cout<<"RED\n";
    else cout<<"BLACK\n";
    }
    
    return 0;
}