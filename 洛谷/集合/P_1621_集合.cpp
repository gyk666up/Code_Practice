// // //想到了并查集
// // //这样写两个点t了 主要是两个for循环耗时久
// // #include<bits/stdc++.h>
// // using namespace std;
// // int a,b,p;
// // const int N=1e5+11;
// // int fa[N];
// // int ans=0;
// // bool is_prime(int x)
// // {
// //     if(x<=1)return false;

// //     for(int i=2;i*i<=x;i++)
// //     {
// //         if(x%i==0)return false;
// //     }
// //     return true;
// // }
// // bool has_yin(int x,int y)
// // {
// //     for(int i=p;i<=min(x,y);i++)
// //     {
// //         if(x%i==0&&y%i==0&&is_prime(i))return 1;
// //     }
// //     return false;
// // }
// // int find(int x)
// // {
// //     if(fa[x]==x)return x;
// //     else return fa[x]=find(fa[x]);
// // }
// // void merge(int x,int y)
// // {
// //     int xx=find(x),yy=find(y);
// //     if(xx==yy)return;
// //     else fa[yy]=xx;
// // }
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     cin>>a>>b>>p;
// //     for(int i=a;i<=b;i++)fa[i]=i;

// //     for(int i=a;i<=b;i++)
// //     {
// //         for(int j=i+1;j<=b;j++)
// //         {
// //             //如果这两个有共质因数就放到一个集合
// //             if(has_yin(i,j))
// //             {
// //                 merge(i,j);
// //             }
// //         }
// //     }

// //     for(int i=a;i<=b;i++)if(fa[i]==i)ans++;
// //     cout<<ans;
// //     return 0;
// // }



// //优化
// #include<bits/stdc++.h>
// using namespace std;

// const int MAX_N = 1e5 + 11; // 题目中 b ≤ 1e5，固定最大范围
// int fa[MAX_N];              // 并查集数组（全局定义，默认初始化为0，后续按需初始化）
// bool is_prime[MAX_N];       // 标记是否为质数（埃氏筛用）

// // 并查集查找（带路径压缩）
// int find(int x) {
//     if (fa[x] == x) return x;
//     return fa[x] = find(fa[x]);
// }

// // 并查集合并
// void merge(int x, int y) {
//     int xx = find(x);
//     int yy = find(y);
//     if (xx != yy) {
//         fa[yy] = xx;
//     }
// }

// // 埃氏筛：预处理 [2, max_num] 内的所有质数
// // void sieve(int max_num) {
// //     memset(is_prime, true, sizeof(is_prime));
// //     is_prime[0] = is_prime[1] = false; // 0和1不是质数
// //     for (int i = 2; i * i <= max_num; ++i) {
// //         if (is_prime[i]) { // 若i是质数，标记其所有倍数为非质数
// //             for (int j = i * i; j <= max_num; j += i) {
// //                 is_prime[j] = false;
// //             }
// //         }
// //     }
// // }
// //上面是更优化的版本
// void sieve(int max_num)
// {
//     memset(is_prime,true,sizeof is_prime);
//     is_prime[0]=is_prime[1]=false;

//     for(int i=2;i<=max_num;i++)
//     {
//         if(is_prime[i])
//         {
                //注意这里得从2开始
//             for(int j=2;j*i<=max_num;j++)
//             {
//                 is_prime[i*j]=false;
//             }
//         }
//     }
// }
// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int a, b, p;
//     cin >> a >> b >> p;

//     // 1. 初始化并查集：仅初始化 [a,b] 区间（其他区间无需处理）
//     for (int i = a; i <= b; ++i) {
//         fa[i] = i;
//     }

//     // 2. 埃氏筛预处理 ≤b 的所有质数（因为最大的可能公共质因数不超过b）
//     sieve(b);

//     // 3. 对每个 ≥p 的质数 q，合并其在 [a,b] 内的所有倍数
//     for (int q = p; q <= b; ++q) {
//         if (!is_prime[q]) continue; // 只处理质数 q
//         //((a + q - 1) / q) * q 是整数 “向上取整” 的常用技巧。
//         // 找到 [a,b] 内第一个 q 的倍数（向上取整到 q 的倍数）
//         //a=10, q=3：(10+3-1)/3 = 12/3=4，4*3=12（10~20 中第一个 3 的倍数是 12）；
//          int start = ((a + q - 1) / q) * q;
//         // q 的倍数从 q 开始，max(start, q) 就是为了 “守住这个底线”。
//         start = max(start, q); // 确保 start ≥ q（质数的最小倍数是自身）
//         // 合并该质数的所有倍数（start, start+q, start+2q, ... ≤b）
//         for (int x = start + q; x <= b; x += q) {
//             merge(start,x); // 只需和第一个倍数合并，即可让所有倍数在同一集合
//         }
//     }

//     // 4. 统计 [a,b] 内的集合数量（根节点数量）
//     int ans = 0;
//     for (int i = a; i <= b; ++i) {
//         if (find(i) == i) { // 注意：必须用 find(i)，因为路径压缩可能未完全生效
//             ans++;
//         }
//     }

//     cout << ans << endl;
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int a,b,p;
// const int N=1e5+11;
// bool is_prime[N];
// int fa[N];

// int find(int x)
// {
//     if(fa[x]==x)return x;
//     return fa[x]=find(fa[x]);
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return;
//     fa[yy]=xx;
// }
// void sieve(int x)
// {
//     memset(is_prime,1,sizeof is_prime);
//     is_prime[0]=is_prime[1]=0;
//     for(int i=2;i<=b;i++)
//     {
//         if(is_prime[i])
//         {
//             for(int j=2;i*j<=b;j++)
//             {
//                 is_prime[j*i]=0;
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>a>>b>>p;
//     for(int i=a;i<=b;i++)fa[i]=i;
//     sieve(b);

//     // 我之前的思路是找到两个数 然后判断有没有公共质因数 
//     //这个思路是 先找到质数然后将在a和b范围内的数字全部都合并
//     for(int q=p;q<=b;q++)
//     {
//         if(!is_prime[q])continue;

//         int start=((a+q-1)/q)*q;
//         start=max(start,q);
//         for(int x=start+q;x<=b;x+=q)
//         {
//             merge(start,x);
//         }
//     }
//     int ans=0;
//     for(int i=a;i<=b;i++)
//     {
//         if(find(i)==i)ans++;
//     }
//     cout<<ans;
//     return 0;
// }























