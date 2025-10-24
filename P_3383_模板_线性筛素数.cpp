// #include<bits/stdc++.h>
// using namespace std;
// int n,q;
// const int N=1e8+1;
// bool is_prime[N];
// int prime[N];
// map<int,int>mp;//记录素数的位置和大小
// void solve()
// {
//     memset(is_prime,1,sizeof is_prime);
//     is_prime[0]=is_prime[1]=0;
//     // for(int i=2;i<=n;i++)
//     // {
//     //     if(is_prime[i])
//     //     {
//     //         for(int j=2;i*j<=n;j++)
//     //         {
//     //             is_prime[i*j]=0;
//     //         }
//     //     }
//     // }

//     //优化版
//     for(int i=2;i*i<=n;i++)
//     {
//         if(is_prime[i])
//         {
//             for(int j=i*i;j<=n;j+=i)
//             {
//                 is_prime[j]=false;
//             }
//         }
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>q;
//     solve();

//     int id=1;

//     //这样写怎么会超时
//     // for(int i=2;i<=n;i++)
//     // {
//     //     if(is_prime[i])mp[id++]=i;//这里容易写错mp[id++]=is_prime[i];
//     // }

//     for(int i=2;i<=n;i++)
//     {
//         if(is_prime[i])prime[id++]=i;
//     }
//     while(q--)
//     {
//         int k;cin>>k;
//         // cout<<mp[k]<<endl;
//         cout<<prime[k]<<endl;
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int n,q;
const int N=1e8+1;
bool is_prime[N];
int prime[N];//注意是int类型 不是bool
void find_is_prime()
{
    memset(is_prime,1,sizeof is_prime);
    is_prime[0]=is_prime[1]=0;
    
    for(int i=2;i*i<=n;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                is_prime[j]=0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>q;
    find_is_prime();

    int id=0;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            id++;
            prime[id]=i;
        }
    }
    while(q--){
        int k;cin>>k;cout<<prime[k]<<endl;
    }
    
    return 0;
}