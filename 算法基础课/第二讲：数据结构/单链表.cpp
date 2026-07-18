// //数组模拟单链表主要是快
// //使用结构体会使用到 new操作
// // #include<iostream>
// // using namespace std;
// // const int N=100010;
// // int idx,head,n[N],ne[N];
// // int a;
// // void add_head(int x){
// //     n[idx]=x;
// //     ne[idx]=head;
// //     head=idx++;
// // }
// // void add(int k,int x){
// //     n[idx]=x;
// //     ne[idx]=ne[k];
// //     ne[k]=idx++;
// // }
// // void remove(int k){
// //     ne[k]=ne[ne[k]];
// // }

// // int main(){

// //     head=-1;idx=0;
// //     cin>>a;
// //     while(a--){
// //         string op;
// //         int k,x;
// //         cin>>op;
// //         if(op=="D")
// //         {

// //             cin>>k;
// //             if(!k)head=ne[head];
// //             remove(k-1);
// //         }
// //         else if(op=="H")
// //         {
// //             cin>>x;
// //             add_head(x);
// //         }
// //         else if(op=="I"){
// //             int k,x;
// //             cin>>k>>x;
// //             add(k-1,x);
// //         }
// //     }
// //     for(int i=head;i!=-1;i=ne[i])
// //       cout<<n[i]<<" ";
// //     return 0;

// // }


// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=100002;
// int head,e[N],ne[N];//e[0]:1 下标为 0 的元素为 1 ，ne[0]:1 表示下标为 0 的下一个位置为 1 
// int idx=0;
// //head 指向第一个元素的下标
// //画图容易理解，本质上和结构体的方式一样，先连右键
// void add_head(int x)
// {
//     e[idx]=x;//这是第一步
//     ne[idx]=head;
//     head=idx;
//     idx++;
// }
// void add(int k,int x)
// {
//     e[idx]=x;
//     ne[idx]=ne[k-1];
//     ne[k-1]=idx;
//     idx++;
// }
// void remove(int k)
// {
//     //k=0会越界
//     ne[k-1]=ne[ne[k-1]];
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     head=-1;//注意这个初始化，这个保证最后一个位置的 ne[x]=-1
//     int m;cin>>m;
//     while(m--)
//     {
//         char op;cin>>op;
//         if(op=='H')
//         {
//             int x;cin>>x;
//             add_head(x);
//         }
//         else if(op=='D')
//         {
//             int k;cin>>k;
//             if(k==0)head=ne[head];
//             else remove(k);
//         }
//         else if(op=='I')
//         {
//             int k,x;cin>>k>>x;
//             add(k,x);
//         }
//     }
//     for(int i=head;i!=-1;i=ne[i])
//     {
//         cout<<e[i]<<" ";
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=1e6+11;
// int e[N],ne[N],head=-1;//下标就是插入的顺序 k=0 就是第一个插入的
// int idx=0;
// void add_head(int x)
// {
//     e[idx]=x;
//     ne[idx]=head;
//     head=idx;
//     idx++;
// }
// void add(int k,int x)
// {
//     e[idx]=x;
//     ne[idx]=ne[k-1];
//     ne[k-1]=idx;
//     idx++;
// } 
// void remove(int k)
// {
//     ne[k-1]=ne[ne[k-1]];
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int m;cin>>m;
//     while(m--)
//     {
//         char op;cin>>op;
//         if(op=='H')
//         {
//             int x;cin>>x;
//             add_head(x);
//         }
//         else if(op=='D')
//         {
//             int k;cin>>k;
//             if(k==0)head=ne[head];
//             else remove(k);
//         }
//         else 
//         {
//             int k,x;cin>>k>>x;
//             add(k,x);
//         }
//     }
//     for(int i=head;i!=-1;i=ne[i])
//     {
//         cout<<e[i]<<" ";
//     }
    
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=2e5+11;
// int e[N],ne[N],h=-1;//就一条链，不用
// int n;
// int idx=0;
// void add(int x)
// {
//     e[idx]=x;
//     ne[idx]=h;
//     h=idx;
//     idx++;
// }
// //第k 个插入的数坐标是 k-1
// void remove(int k)
// {
//     ne[k-1]=ne[ne[k-1]];
// }
// void insert(int k,int x)
// {
//     e[idx]=x;
//     ne[idx]=ne[k-1];
//     ne[k-1]=idx;
//     idx++;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=0;i<n;i++)
//     {
//         char op;cin>>op;
//         if(op=='H')
//         {
//             int x;cin>>x;
//             add(x);
//         }
//         else if(op=='D')
//         {
//             int k;cin>>k;
//             //删除头结点
//             if(k==0)h=ne[h];
//             else remove(k);
//         }
//         else if(op=='I')
//         {
//             int k,x;cin>>k>>x;
//             insert(k,x);
//         }
//     }
//     for(int i=h;i!=-1;i=ne[i])
//     {
//         int j=e[i];
//         cout<<j<<" ";
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+66;
int e[N],ne[N],h=-1;
int n;
int idx=0;
void add(int x)
{
    e[idx]=x;
    ne[idx]=h;
    h=idx;
    idx++;
}
void insert(int k,int x)
{
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}
void remove(int k)
{
    ne[k]=ne[ne[k]];
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        char s;cin>>s;
        if(s=='H')
        {
            int x;cin>>x;
            add(x);
        }
        else if(s=='D')
        {
            int k;cin>>k;
            // if(k==0)h=ne[0];
            if(k==0)h=ne[h];//这里的代码总写错
            else 
            {
                remove(k-1);
            }
        }
        else if(s=='I')
        {
            int k,x;cin>>k>>x;
            insert(k-1,x);
        }
    }
    for(int i=h;i!=-1;i=ne[i])
    {
        int j=e[i];
        cout<<j<<" ";
    }
    return 0;
}