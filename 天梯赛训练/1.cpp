#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int tre[N];
int n,m;
int idx=1;
void up(int x)
{
    if(x==1)return;
    if(tre[x/2]>tre[x])
    {
        swap(tre[x/2],tre[x]);//背后的逻辑
        up(x/2);
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            tre[idx]=x;
            up(idx);
            idx++;
        }
    getchar();
    for(int i=0;i<m;i++)
        {
            string s;getline(cin,s);
            int x,y;
            if(s.find("root")!=string::npos)
            {
                sscanf(s.c_str(),"%d is the root",&x);
                if(tre[1]==x)cout<<"T\n";
                else cout<<"F\n";
            }
            else if(s.find("siblings")!=string::npos)
            {
                sscanf(s.c_str(),"%d and %d are siblings",&x,&y);

                    int i=0,j=0;
                //不要在初始化了
                    for( i=1;i<=idx;i++)
                    {
                        if(tre[i]==x)break;
                    }
                    for( j=1;j<=idx;j++)if(tre[j]==y)break;
                if(tre[i/2]==tre[j/2])cout<<"T\n";
                else cout<<"F\n";
            }
            else if(s.find("parent")!=string::npos)
            {
                sscanf(s.c_str(),"%d is the parent of %d",&x,&y);
                int i=0,j=0;
                for( i=1;i<idx;i++)if(tre[i]==x)break;
                for( j=1;j<idx;j++)if(tre[j]==y)break;
                if(j/2==i)cout<<"T\n";
                else cout<<"F\n";
            }
            else
            {
                sscanf(s.c_str(),"%d is a child of %d",&x,&y);
                int i=0,j=0;
                for( i=1;i<idx;i++)if(tre[i]==x)break;
                for( j=1;j<idx;j++)if(tre[j]==y)break;
                if(i/2==j)cout<<"T\n";
                else cout<<"F\n";
            }
        }
    return 0;
}