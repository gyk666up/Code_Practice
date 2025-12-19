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

//2025/12/16
//这个方法很有技巧
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int a[10];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)a[i]=i;
//     do
//     {
//         for(int i=1;i<=n;i++)
//         cout<<setw(5)<<a[i];
//         cout<<endl;
//     } while (next_permutation(a+1,a+1+n));
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n;
bool st[20];
int b[20];
void dfs(int x)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<setw(5)<<b[i];
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            st[i]=1;
            b[x]=i;
            dfs(x+1);
            st[i]=0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    dfs(1);

    return 0;
}