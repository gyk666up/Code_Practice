#include<bits/stdc++.h>
using namespace std;
const int N=1e3+11;
int a[N],b[N],c[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    int m;cin>>m;
    int now1=1,now2=1,now3=1;
    int ans=0;
    while(m--)
    {
        int x1,x2,x3;cin>>x1>>x2>>x3;
        now1=(now1-1+x1%n)%n+1;
        now2=(now2-1+x2%n)%n+1;
        now3=(now3-1+x3%n)%n+1;
        //  now1 = (now1 - 1 + (x1 % n) + n) % n + 1;
        // now2 = (now2 - 1 + (x2 % n) + n) % n + 1;
        // now3 = (now3 - 1 + (x3 % n) + n) % n + 1;
        if(a[now1]==b[now2]&&b[now2]==c[now3])ans+=200;
        else if(a[now1]==b[now2]||b[now2]==c[now3]||a[now1]==c[now3])ans+=100;
        else if(a[now1]+1==b[now2]&&b[now2]+1==c[now3])ans+=200;
        else
        {
            vector<int>v;
            v.push_back(a[now1]);
            v.push_back(b[now2]);
            v.push_back(c[now3]);
            sort(v.begin(),v.end());
            if(v[0]+1==v[1]&&v[1]+1==v[2])ans+=100;
        }
    }
    cout<<ans;
    return 0;    
}