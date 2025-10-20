#include<bits/stdc++.h>
using namespace std;
const int N =1e6+11;
struct node
{
    int start,end;
    // bool operator<(const node&u)
    // {
    //     if(start!=u.start)
    //     {
    //         return start<u.start;
    //     }
    //     else return end<u.end;
    // }

    //上面的不对
        bool operator<(const node&u)
    {
        if(end!=u.end)
        {
            return end<u.end;
        }
        else return start<u.start;
    }
}dat[N];
bool xuan[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    //前一个比赛的结束时间<=后一个比赛的开始时间->才可以参加
    for(int i=1;i<=n;i++)cin>>dat[i].start>>dat[i].end;
    sort(dat+1,dat+1+n);
    xuan[1]=1;
    //第一个肯定要选
    int s=dat[1].end;
    for(int i=2;i<=n;i++)
    {
        //这个比赛的开始时间晚于上个比赛的开始时间 可以参加
        if(dat[i].start>=s)
        {
            xuan[i]=1;
            s=dat[i].end;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(xuan[i])cnt++;
    cout<<cnt<<endl;
}