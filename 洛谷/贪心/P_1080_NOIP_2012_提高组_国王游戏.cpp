// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e3+11;
// struct node
// {
//     int left,right;
//     int id;
//     bool operator<(const node&u)
//     {
//         return left<u.left;
//     }
// }dat[N];
// int ans=0x3f3f3f3f;

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     int k_left,k_right;cin>>k_left>>k_right;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>dat[i].left>>dat[i].right;
//         dat[i].id=i;
//     }
//     //尝试一下暴力  只能过少部分样例
//     do //一次循环中找最多的金币数（max） 结果是多次中最多金币数最少的(min)
//     {
//         int temp=0;
//         //前缀和 （左和右）
//         int pre_L[1002]={0};//pre_R[1002]={0};
//         pre_L[0]=k_left;
//         //pre_R[0]=k_right;

        
//         for(int i=1;i<=n;i++)
//         {
//            pre_L[i]=pre_L[i-1]*dat[i].left;
//            //前面所有大臣左手上数的乘积（不包括自己）
//             int get=pre_L[i-1]/dat[i].right;
//             temp=max(temp,get);
//         }
//         ans=min(temp,ans);
//     } while (next_permutation(dat+1,dat+1+n));
    
//     cout<<ans<<endl;
//     return 0;
// }


//得一半分
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+55;
int n;
struct node
{
    int left,right;
    bool operator<(const node &u)
    {
        return right<u.right;
    }
}dat[N];
//别管怎么排 越往后左手的乘积越多 直觉想把右手大的放到后面
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int k_left,k_right;cin>>k_left>>k_right;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].left>>dat[i].right;
    }
    sort(dat+1,dat+1+n);
    int pre[1003]={0};
    pre[0]=k_left;
    int temp=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]*dat[i].left;
        int get=pre[i-1]/dat[i].right;
        temp=max(temp,get);
    }
    cout<<temp;
    return 0;
}

//正解需要高精度  先放一放