#include<bits/stdc++.h>
using namespace std;
const int N=1e5+66;
bool st[N];
struct node
{
    int val,id,next;
}dat[N];
vector<node>v;
int id_node[N];
int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int head,n;cin>>head>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].id>>dat[i].val>>dat[i].next;
        id_node[dat[i].id]=i;
    }
    int currid=head;
    while(currid!=-1)
    {
        int currnode=id_node[currid];
        if(!st[abs(dat[currnode].val)])
        {
            if(dat[currnode].id==head)
            printf("%05d %d ",dat[currnode].id,dat[currnode].val);
            else
            printf("%05d\n%05d %d ",dat[currnode].id,dat[currnode].id,dat[currnode].val);
            st[abs(dat[currnode].val)]=1;
        }
        else
        {
            v.push_back(dat[currnode]);
        }
        currid=dat[currnode].next;
    }
    cout<<-1<<endl;
    for(int i=0;i<v.size();i++)
    {
        if(i==0)printf("%05d %d ",v[i].id,v[i].val);
        else
        printf("%05d\n%05d %d ",v[i].id,v[i].id,v[i].val);
    }
    if(v.size())cout<<-1<<endl;
    return 0;
}
