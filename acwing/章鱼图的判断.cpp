#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m;cin>>n>>m;
    vector<int>in(n+10),g[n+10],st(n+10);
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        in[a]++,in[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //检查树结构
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            if(in[i]==1)
            {
                st[i]=1;
                queue<int>q;
                q.push(i);
                while(q.size())
                {
                    int t=q.front();q.pop();
                    for(int j=0;j<g[t].size();j++)
                    {
                        int k=g[t][j];
                        if(!st[k])
                        {
                            if(in[k]==2)
                            {
                                q.push(k);
                            }
                            else if(in[k]>2)
                            {
                                in[k]--;
                            }
                        }
                    }
                }
            }
            //孤立点
            else
            {
                st[i]=1;
            }

        }
    }

    int huan=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(!st[i])
        {
            st[i]=1;
            queue<int>q;
            int last=cnt;
            q.push(i);
            bool f=1;
           
            while(q.size())
            {
                int t=q.front();q.pop();
                 cnt++;
                for(int j=0;j<g[t].size();j++)
                {
                    int k=g[t][j];
                    if(!st[k])
                    {
                        if(in[k]==2)
                        {
                            q.push(k);
                            st[k]=1;
                        }
                        else
                        {
                            f=0;
                        }
                    }
                }
            }
            if(!f)cnt=last;
            huan+=f;

            
        }
        
    }
    if(huan==1)cout<<"Yes "<<cnt<<endl;
        else cout<<"No "<<huan<<endl;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}