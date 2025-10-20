#include<bits/stdc++.h>
using namespace std;
const int N=1e4+11;
int ans=0;
struct node
{
    int x,y;
    //肯定是需要的力气越少越好 但还要保证力气足够 距离足够
    bool operator<(const node&u)
    {
        return y<u.y;
    }    
}dat[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,s;cin>>n>>s;
    int a,b;cin>>a>>b;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].x>>dat[i].y;
    }
    sort(dat+1,dat+1+n);
    for(int i=1;i<=n;i++)
    {
       if(dat[i].x<=a+b&&s>=dat[i].y)
        {
            ans++;
            s-=dat[i].y;
        }     
    }
    cout<<ans<<endl;
        
    
}