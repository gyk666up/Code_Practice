// #include<bits/stdc++.h>
// using namespace std;
// const int N=109;
// string name[N];
// char rank[N];//与上面的一一对应
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,m;cin>>n>>m;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>name[i]>>rank[i];
//     }

//     while(m--)
//     {
//         string s;cin>>s;bool f=0;
//         //直接有 不需要拆开
//         for(int i=1;i<=n;i++)
//         {
//             if(s==name[i])
//             {
//                 f=1;
//                 cout<<rank[i]<<endl;
//                 break;
//             }
//         }
//         if(f)continue;
        
//         //拆分两个 并检查情况是否唯一
//         int I=-1,J=-1;//记录拆分的情况
//         int cnt=0;//记录情况数
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(name[i]+name[j]==s)
//                 {
//                     I=i,J=j;
//                     cnt++;
//                 }
//             }
//         }
//         //这里有一个小细节 如果是单引号 可能会输出数字
//         //17418 是字符串"D\n"首地址的十进制表示
//         //if(cnt!=1)cout<<'D\n';
//        if(cnt!=1)cout<<"D\n";
//         else cout<<rank[I]<<rank[J]<<endl;
//     }
//     return 0;
// }