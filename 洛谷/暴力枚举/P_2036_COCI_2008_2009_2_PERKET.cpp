// #include<bits/stdc++.h>
// using namespace std;
// int n,s,b;
// const int N=20;
// int bitter[N],sour[N];
// int ans=0x3f3f3f3f;
// bool st[N];
// void dfs(int x)
// {
//     if(x>n)
//     {
//         int sum1=1,sum2=0;
//         bool has_tl=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(st[i])
//             {
//                 has_tl=1;
//                 sum1*=sour[i];
//                 sum2+=bitter[i];
//             }
//         }
//         if(has_tl&&ans>abs(sum1-sum2))ans=abs(sum1-sum2);
//         return ;
//     }
//     //指数型枚举 
//     st[x]=1;
//     dfs(x+1);
//     st[x]=0;
//     dfs(x+1);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>sour[i]>>bitter[i];

//     dfs(1);
//     cout<<ans;
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int n;
// const int N=20;
// int bitter[N],sour[N],st[N];
// int ans=0x3f3f3f3f;
// void dfs(int x)
// {
//     if(x>n)
//     {
//         int sum1=1,sum2=0;
//         bool has_=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(st[i]){
//                 has_=1;
//             sum1*=sour[i];
//             sum2+=bitter[i];}
//         }
//         if(has_)
//         ans=min(ans,abs(sum1-sum2));
//         return;
//     }
   
    
//         //可选可不选
//         st[x]=1;
//         dfs(x+1);

//         st[x]=0;
//         dfs(x+1);
    
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>sour[i]>>bitter[i];
//     }
//     dfs(1);
//     cout<<ans<<endl;
//     return 0;
// }






























