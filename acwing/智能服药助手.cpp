#include<bits/stdc++.h>
using namespace std;
const int N=1e3+66;
struct node
{
    int last;//上一次服药时间
    int gap;
    bool first;//记录是否是第一次喝药 主要用来判断是否需要判断与上一次喝药的时间
}dat[N];
int n,m;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>dat[i].gap;
    while(m--)
    {
        int t,k;cin>>t>>k;
        for(int i=0;i<k;i++)
        {
            int x;cin>>x;
            //没喝过 那么第一次就一定可以喝
            if(!dat[x].first)
            {
                dat[x].first=1;
                dat[x].last=t;
            }
            //如果不是第一次
            else
            {
                //相隔时间太短 不能喝
                if(t-dat[x].last<dat[x].gap)
                printf("Don't take %d at %d!\n",x,t);
                else
                {
                    dat[x].last=t;
                }
            }
        }
    }
    return 0;
}