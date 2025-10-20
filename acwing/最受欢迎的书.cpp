#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
struct node
{
    int all;//全部的书 最后还可以借的书
    int jie;//借的次数
    bool operator<(const node &u)
    {
        return jie>u.jie;
    }
}dat[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,d;cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>dat[i].all;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<d;j++)
        {
            int jie,huan;cin>>jie>>huan;
            dat[i].jie+=jie;
            //注意易错点：
            //dat[i].all-=jie+huan是错误的
            //等价于dat[i].all=dat[i].all-(jie+huan);
            dat[i].all=dat[i].all-jie+huan;
        }
    }
    //sort(dat+1,dat+1+n);
    int res=-1;//最多借的数量
    for(int i=1;i<=n;i++)
    {
        res=max(res,dat[i].jie);
    }
    for(int i=1;i<=n;i++)
    {
        if(dat[i].jie==res)cout<<dat[i].all<<"*\n";
        else cout<<dat[i].all<<endl;
    }
    return 0;
}