//其实思路没有问题就是超内存了
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// vector<int>v[N];//第一维寄包柜的编号 第二维是柜子的编号
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,q;cin>>n>>q;
//     for(int i=1;i<=n;i++)
//     {
//         v[i].resize(100*N+1,0);
//     }
//     while(q--)
//     {
//         int id;cin>>id;
//         if(id==1)
//         {
//             int i,j,k;cin>>i>>j>>k;
//             v[i][j]=k;
//         }
//         else 
//         {
//             int i,j;cin>>i>>j;
//             cout<<v[i][j]<<endl;
//         }
//     }
//     return 0;
// }


//用map做映射 对用map数据结构的代码优化时可以从unordered_map下手，后者用的是哈希表
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
map<int,int>mp[N];//!!!注意这种用法
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,q;cin>>n>>q;
    while(q--)
    {
        int id;cin>>id;
        if(id==1)
        {
            int i,j,k;cin>>i>>j>>k;
            mp[i][j]=k;
        }
        else 
        {
            int i,j;cin>>i>>j;
            cout<<mp[i][j]<<endl;
        }
    }
    return 0;
}