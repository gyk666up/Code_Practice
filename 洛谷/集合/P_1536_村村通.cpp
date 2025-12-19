// //差不多秒了 哈哈哈哈哈哈 别一看题目长就觉得自己不会 要相信自己的实力啊
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// const int N=1e3+11;
// int fa[N];
// //就是并查集 看有几堆 如果有两堆 不就修一条路就可以了吗
// int find(int x)
// {
//     if(fa[x]!=x)
//     {
//         return fa[x]=find(fa[x]);
//     }
//     else return x;
// }
// void merge(int x,int y)
// {
//     int xx=find(x),yy=find(y);
//     if(xx==yy)return ;
//     fa[yy]=xx;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     while(1)//若干组数据
//     {
//         cin>>n>>m;
//         if(n==0)break;
//         int cnt=0;
//         for(int i=1;i<=n;i++)fa[i]=i;
//         for(int i=0;i<m;i++)
//         {
//             int u,v;cin>>u>>v;
//             merge(u,v);
//         }
//         for(int i=1;i<=n;i++)if(fa[i]==i)cnt++;
//         cout<<cnt-1<<endl;
//     }
//     return 0;
// }



