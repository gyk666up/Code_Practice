// //没思路
// #include<bits/stdc++.h>
// using namespace std;
// int a[4];
// int target[4];
// void dfs(int a[],int target[])
// {

//     while(1)
//     {
        
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int t;cin>>t;
//     while(t--)
//     {
//         for(int i=1;i<=3;i++)cin>>a[i];
//         for(int i=1;i<=3;i++)cin>>target[i];
//         dfs(a,target);
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int a[5],b[5],c[5];//原始数组 目标数组 以及两种之间差值组成的数组
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        for(int i=1;i<=3;i++)cin>>a[i];
        for(int i=1;i<=3;i++)
        {
            cin>>b[i];
            c[i]=a[i]-b[i];
        }

        if(a[1]==b[1]&&a[2]==b[2]&&a[3]==b[3])
        {
            cout<<"0\n";
            continue;
        }
        //观察发现 无论如何操作前后的属性值之和是不会改变的
        if(a[1]+a[2]+a[3]!=b[1]+b[2]+b[3])
        {
            cout<<"-1\n";
            continue;
        }

        if(c[1]%20!=0||c[2]%20!=0||c[3]%20!=0)
        {
            cout<<"-1\n";
           continue;
        }
        int ax=c[1]/20;
        int by=c[2]/20;
        int cz=c[3]/20;

        // 确保有两个变化量为负（需要增加），一个为正（需要减少）
        int num=0;//大于0的个数
        num=(ax>0)+(by>0)+(cz>0);//!!!
        //如果两个正数则变成一个正数 便于统一处理
        if(num==2)
        {
            ax=-ax;
            by=-by;
            cz=-cz;
        }
        int f[3]={ax,by,cz};
        sort(f,f+3);
        
        //f[0]<f[1]<=0<f[2]
        int ans=0;//记录最少的次数
        //第一步将中间站f[1]变成0 操作2
        ans+=-f[1];

        f[0]=f[0]-f[1];
        f[2]=f[2]+2*f[1];

        //第二步将最大值变成0 通过操作1，2 
        //40 -20 -20
        //20 20  -40
        //60 0   -60
        //60的变化量（20*3） 两次操作
        ans+=f[2]/3*2;
        cout<<ans<<endl;
    }
    return 0;
}