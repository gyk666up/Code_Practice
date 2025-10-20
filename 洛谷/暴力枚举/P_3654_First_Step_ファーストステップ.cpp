#include<bits/stdc++.h>
using namespace std;
const int N=105;
char a[N][N];
int r,c,k;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>r>>c>>k;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)cin>>a[i][j];
    }
    bool f=1;
    int ans=0;
    for(int i=1;i<=r;i++)//横向搜索
    {
        for(int j=1;j<=c;j++)
        {
            f=1;
            for(int s=0;s<k;s++)
            {
                if(a[i+s][j]!='.')
                {
                    f=0;
                    break;
                }
            }
            if(f)ans++;
        }
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            f=1;
            for(int s=0;s<k;s++)
            {
                if(a[i][j+s]!='.')
                {
                    f=0;
                    break;
                }
            }
            if(f)ans++;
        }
    }
    //!!! 因为k==1的时候横向和纵向一样 算了两次 因此需要减一次
    if(k==1)
    cout<<ans/2;
    else cout<<ans;
    return 0;
}

//还有更加巧妙的方法