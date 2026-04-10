#include<bits/stdc++.h>
using namespace std;
const int N=1e7+11;
bool is_prime[N];
int cnt;
// bool is_prime(int x)
// {
//     if(x<=1)return false;
//     for(int i=2;i*i<=x;i++)
//     {
//         if(x%i==0)return false;
//     }
//     return true;
// }
int main()
{
    memset(is_prime,1,sizeof is_prime);
    is_prime[0]=is_prime[1]=0;
    for(int i=2;i<=N;i++)
    {
        if(is_prime[i])
        {
            for(int j=2;i*j<=N;j++)
            is_prime[i*j]=0;
        }
    }
    for(int i=1;i<=N;i++)
    {
        if(is_prime[i])cnt++;
        if(cnt==2025)
        {
            // cout<<is_prime[i]<<endl;
            cout<<i<<endl;
            break;
        }
    }
    // for(int i=2;i<=N;i++)
    // {
    //     if(is_prime(i))cnt++;
    //     if(cnt==2025)
    //     {
    //         cout<<i;
    //         break;
    //     }
    // }
    return 0;
}