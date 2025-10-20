#include<bits/stdc++.h>
using namespace std;
const int N=1e5+33;
struct node
{
    int length,width,height;
    string color;
}dat[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dat[i].length>>dat[i].width>>dat[i].height;
        cin>>dat[i].color;
    }
    int k;cin>>k;
    while(k--)
    {
        int x,y,z;cin>>x>>y>>z;
        bool f=0;
        for(int i=1;i<=n;i++)
        {
            if(x==dat[i].length&&y==dat[i].width&&z==dat[i].height)
            {
                f=1;
                cout<<dat[i].color<<endl;
                break;
            }
        }
        if(f)continue;
        cout<<"Not Found\n";
    }
    return 0;
}