// //int 是2e9 longlong 是2e18

// //思路存在问题
// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // string n;int k;
// // // const int p=1000;
// // // int id(int x)
// // // {
// // //     return x%p;
// // // }
// // map<int,vector<int>>mp;
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>n>>k;
// //     while(k--)
// //     {
// //         int x,y;cin>>x>>y;
// //         mp[x].push_back(y);
// //     }
// //     int ans=1;
// //     for(int i=0;i<n.size();i++)
// //     {
// //         int x=n[i]-'0';
// //         //算上自己就有n+1种 可能变、不变
// //         ans*=(mp[x].size()+1);
// //     }
// //     cout<<ans;
// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// /*
//  高精度整数：用 vector 存，每一位存一个十进制数字
//  低位在前（小端）
// */
// struct BigInt {
//     vector<int> d;

//     BigInt(int x = 0) {
//         if (x == 0) d.push_back(0);
//         while (x) {
//             d.push_back(x % 10);
//             x /= 10;
//         }
//     }

//     // 乘以一个 int（👉 模拟“竖式乘法”）
//     void mul(int x) {
//         int carry = 0;
//         for (int i = 0; i < (int)d.size(); i++) {
//             int t = d[i] * x + carry;
//             d[i] = t % 10;
//             carry = t / 10;
//         }
//         while (carry) {
//             d.push_back(carry % 10);
//             carry /= 10;
//         }
//     }
//     //有可能会新开一位
//     void print() {
//         for (int i = d.size() - 1; i >= 0; i--)
//             cout << d[i];
//         cout << '\n';
//     }
// };

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     string n;
//     int k;
//     cin >> n >> k;

//     bool reach[10][10] = {0};

//     // 自己到自己（0 次变换）
//     for (int i = 0; i <= 9; i++)
//         reach[i][i] = true;

//     // 读规则
//     for (int i = 0; i < k; i++)
//     {
//         int x, y;
//         cin >> x >> y;
//         reach[x][y] = true;
//     }

//     // Floyd 求传递闭包（只有 10 个点）
//     for (int mid = 0; mid <= 9; mid++)
//         for (int i = 0; i <= 9; i++)
//             for (int j = 0; j <= 9; j++)
//                 if (reach[i][mid] && reach[mid][j])
//                     reach[i][j] = true;

//     // cnt[d]：数字 d 能变成多少种
//     int cnt[10] = {0};
//     for (int i = 0; i <= 9; i++)
//         for (int j = 0; j <= 9; j++)
//             if (reach[i][j])
//                 cnt[i]++;

//     // 高精度答案
//     BigInt ans(1);

//     for (char c : n)
//     {
//         int d = c - '0';
//         ans.mul(cnt[d]);
//     }

//     ans.print();
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// string n;
// int k;
// bool reach[13][13];
// int cnt[13];
// struct BigInt
// {
//     vector<int>d;
//     BigInt(int x)
//     {
//         if(x==0)d.push_back(0);
//         while(x)
//         {
//             d.push_back(x%10);
//             x/=10;
//         }
//     }//不用写；

//     void mul(int x)
//     {
//         int carry=0;
//         for(int i=0;i<(int)d.size();i++)
//         {
//             int t=d[i]*x+carry;
//             d[i]=t%10;
//             carry=t/10;
//         }
//         while(carry)
//         {
//             d.push_back(carry%10);
//             carry/=10;
//         }
//     }
//     void print()
//     {
//         for(int i=d.size()-1;i>=0;i--)cout<<d[i];
//         cout<<endl;
//     }
// };

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>k;
//     for(int i=0;i<=9;i++)
//     {
//         reach[i][i]=1;
//     }

//     for(int i=0;i<k;i++)
//     {
//         int x,y;cin>>x>>y;
//         reach[x][y]=true;
//     }
    
//     for(int k=0;k<=9;k++)
//     {
//         for(int i=0;i<=9;i++)
//         {
//             for(int j=0;j<=9;j++)
//             {
//                 if(reach[i][k]&&reach[k][j])reach[i][j]=1;
//             }
//         }
//     }
//     for(int i=0;i<=9;i++)
//     {
//         for(int j=0;j<=9;j++)
//         {
//             if(reach[i][j])cnt[i]++;
//         }
//     }
//     BigInt ans(1);
//     for(char c:n)
//     {
//         int d=c-'0';
//         ans.mul(cnt[d]);
//     }
//     ans.print();//!!!
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
string n;
int k;
const int N=10;
int reach[N][N];
int cnt[N];//每个数字有多少种可能
struct BigInt
{
    vector<int>d;
    BigInt(int x)
    {
        if(x==0)d.push_back(0);
        while(x)
        {
            d.push_back(x%10);
            x/=10;
        }
    }

    void mul(int x)
    {
        int carry=0;
        for(int i=0;i<d.size();i++)
        {
            int t=d[i]*x+carry;
            carry=t/10;
            d[i]=t%10;//这行代码差点忘了 ^_^😄
        }
        while(carry)
        {
            d.push_back(carry%10);
            carry/=10;
        }
    }
    void print()
    {
        for(int i=d.size()-1;i>=0;i--)cout<<d[i];
    }
};
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {
        int x,y;cin>>x>>y;
        reach[x][y]=1;
    }
    //这里容易写错，是从0开始的
    for(int i=0;i<=9;i++)reach[i][i]=1;
    for(int k=0;k<=9;k++)
    {
        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<=9;j++)
            {
                //注意这一行代码和上面代码的区别
                // if(reach[i][k]&&reach[k][j])reach[i][j]=1;
                reach[i][j]|=reach[i][k]&&reach[k][j];
                //但是reach[i][j]|=reach[i][k]&&reach[k][j];不对

            }
        }
    }
    for(int i=0;i<=9;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(reach[i][j])cnt[i]++;
        }
    }
    BigInt ans(1);
    //这个是n
    for(int i=0;i<n.size();i++)
    {
        int d=n[i]-'0';
        ans.mul(cnt[d]);
    }
    ans.print();
    return 0;
}