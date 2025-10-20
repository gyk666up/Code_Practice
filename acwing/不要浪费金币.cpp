#include<bits/stdc++.h>
using namespace std;
const int N=1e3+66;
int n,m;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int now=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(now+x>m)
        {
            now=0;
            cnt++;
            now+=x;
            ///!!!
            if(now>m)now=m;
        }
        else now+=x;
        
    }
    cout<<cnt<<endl;
    return 0;
}