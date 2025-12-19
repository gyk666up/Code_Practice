#include<bits/stdc++.h>
using namespace std;
const int N=1002;
// int a[N];
map<int,bool>mp;//判断这个单词是否在队列中 辅助查找单词 因为队列不能直接遍历
queue<int>q;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int m,n;cin>>m>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(!mp.count(x))
        {
            if(mp.size()<=m-1)
            {
                mp[x]=1;
                q.push(x);
            }
            else
            {
               // mp[x]=0;
                mp.erase(q.front());//这才是删除元素
                q.pop();
                
                mp[x]=1;
                q.push(x);
            }
            cnt++;
        }
        
    }
    cout<<cnt;
    return 0;
}