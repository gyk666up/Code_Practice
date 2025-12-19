#include<bits/stdc++.h>
using namespace std;
const int N=20;
int n;
int s[N],b[N];
int ans=0x3f3f3f3f;
bool st[N];
void dfs(int x)
{
    if(x>n)
    {
        int sum1=1,sum2=0;
        bool has_tl=0;//题目要求必须有至少一种
        for(int i=1;i<=n;i++)
        {
            if(st[i])
            {
                has_tl=1;
                sum1*=s[i];
                sum2+=b[i];
            }
            
        }
        if(has_tl)
        ans=min(ans,abs(sum1-sum2));
        return;
    }

    //选 不选
    st[x]=1;
    dfs(x+1);

    st[x]=0;
    dfs(x+1);
    return ;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i]>>b[i];

    //指数型枚举
    dfs(1);
    cout<<ans;
    return 0;
}