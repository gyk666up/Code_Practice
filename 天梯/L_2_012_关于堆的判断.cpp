//false
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+11;
int tre[N];//数组来模拟堆
int idx=1;
void up(int x)
{
    if(x==1)return ;
    if(tre[x/2]>tre[x])
    {
        swap(tre[x/2],tre[x]);
        up(x/2);
    }
    //up(tre[x/2]);
    return;
}
int main()
{
   // ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        tre[idx]=x;
        up(idx);
        idx++;
    }
    getchar();
    while(m--)
    {
        string s;getline(cin,s);
        int x,y;
        if(s.find("root")!=string::npos)
        {
            int i,j;
            sscanf(s.c_str(),"%d is the root",&x);
            //注意是x是值不是下标
            for(i=1;i<idx;i++)if(tre[i]==x)break;
            if(i==1)cout<<"T\n";
            else cout<<"F\n";
        }

        else if(s.find("siblings")!=string::npos)
        {
            int i,j;
            sscanf(s.c_str(),"%d and %d are siblings",&x,&y);
            for(i=1;i<idx;i++)if(tre[i]==x)break;
            for(j=1;j<idx;j++)if(tre[j]==y)break;
            if(tre[i/2]==tre[j/2])cout<<"T\n";
            else cout<<"F\n";
        }
        else if(s.find("parent")!=string::npos)
        {
            int i,j;
            sscanf(s.c_str(),"%d is the parent of %d",&x,&y);
           for(i=1;i<idx;i++)if(tre[i]==x)break;
            for(j=1;j<idx;j++)if(tre[j]==y)break;
            //注意这里的优先级
            cout<<((tre[j/2]==tre[i])?"T\n":"F\n");
          // if(i/2==j/2)cout<<"T\n";else cout<<"F\n";
        }
        else
        {
            int i,j;
            sscanf(s.c_str(),"%d is a child of %d",&x,&y);
            for(i=1;i<idx;i++)if(tre[i]==x)break;
            for(j=1;j<idx;j++)if(tre[j]==y)break;
            //cout<<(tre[i/2]==tre[j])?"T\n":"F\n";
             if(i/2==j)cout<<"T\n";else cout<<"F\n";
        }
    }
    return 0;
}