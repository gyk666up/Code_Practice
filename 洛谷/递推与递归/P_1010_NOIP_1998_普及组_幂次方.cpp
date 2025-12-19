#include<bits/stdc++.h>
using namespace std;
void dfs(int x)
{
    if(x!=0)
    {
        //2^14 16384 2^15 32768
        for(int i=14;i>=0;i--)
        {
            if(pow(2,i)<=x)
            {
                if(i==1)cout<<2;//不是2（1）
                else if(i==0)cout<<"2(0)";
                else 
                {
                    cout<<"2(";
                    dfs(i);
                    cout<<')';
                }

                    x-=pow(2,i);
                    if(x!=0)cout<<"+";
                
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    dfs(n);
    return 0;
}