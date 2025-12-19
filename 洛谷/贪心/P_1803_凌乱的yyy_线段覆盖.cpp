// #include<bits/stdc++.h>
// using namespace std;
// const int N =1e6+11;
// struct node
// {
//     int start,end;
//     // bool operator<(const node&u)
//     // {
//     //     if(start!=u.start)
//     //     {
//     //         return start<u.start;
//     //     }
//     //     else return end<u.end;
//     // }

//     //上面的不对
//         bool operator<(const node&u)
//     {
//         if(end!=u.end)
//         {
//             return end<u.end;
//         }
//         else return start<u.start;
//     }
// }dat[N];
// bool xuan[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     //前一个比赛的结束时间<=后一个比赛的开始时间->才可以参加
//     for(int i=1;i<=n;i++)cin>>dat[i].start>>dat[i].end;
//     sort(dat+1,dat+1+n);
//     xuan[1]=1;
//     //第一个肯定要选
//     int s=dat[1].end;
//     for(int i=2;i<=n;i++)
//     {
//         //这个比赛的开始时间晚于上个比赛的开始时间 可以参加
//         if(dat[i].start>=s)
//         {
//             xuan[i]=1;
//             s=dat[i].end;
//         }
//     }
//     int cnt=0;
//     for(int i=1;i<=n;i++)if(xuan[i])cnt++;
//     cout<<cnt<<endl;
// }


// //no problem
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e6+11;
// int n;
// struct node
// {
//     int st,end;
//     bool operator<(const node&u)
//     {
//         return end<u.end;
//     }
// }dat[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>dat[i].st>>dat[i].end;
//     }
//     sort(dat+1,dat+1+n);
//     //第一个肯定得选上
//     int ans=1;
//     int st=dat[1].end;
//     for(int i=2;i<=n;i++)
//     {
//         if(dat[i].st>=st)
//         {
//             ans++;
//             st=dat[i].end;
//         }
//     }
//     cout<<ans;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11;
struct node
{
    int st,end;
    bool operator<(const node&u)
    {
        return end<u.end;
    }
}dat[N];
int n;
int ans;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].st>>dat[i].end;
    }
    sort(dat+1,dat+1+n);
    ans++;
    int end=dat[1].end;
    for(int i=2;i<=n;i++)
    {
        if(dat[i].st>=end)
        {
            end=dat[i].end;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}