// //总权值 = (穿过 y 轴的线段数量) + (穿过 x 轴的线段数量)**。
// //代码很简单，就是有点难理
// //这道题也得重点看一下
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     int l=0,r=0,up=0,down=0;
//     for(int i=1;i<=n;i++)
//     {
//         int x,y;cin>>x>>y;
//         if(x<0)l++;
//         else r++;

//         if(y<0)down++;
//         else up++;
//     }
//     int ans=min(l,r)+min(down,up);
//     cout<<ans;
//     return 0;
// }






#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    cin>>n;
    int l=0,r=0,up=0,down=0;
    for(int i=0;i<n;i++)
    {
        int x,y;cin>>x>>y;
        if(x<0)l++;
        else r++;
        if(y<0)down++;
        else up++;
    }
    cout<<min(l,r)+min(up,down);

    return 0;
}