#include<bits/stdc++.h>
using namespace std;
const int N=3;
struct node
{
    int id,gold,silver,bronze;
    bool operator<(const node u)
    {
        if(gold!=u.gold)return gold>u.gold;
        else if(silver!=u.silver)return silver>u.silver;
        else return bronze>u.bronze;
    }
}dat[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    for(int i=0;i<=1;i++)dat[i].id=i;
    while(t--)
    {
        int c,p;cin>>c>>p;
        if(c==0)
        {
            if(p==1)dat[0].gold++;
            else if(p==2)dat[0].silver++;
            else if(p==3)dat[0].bronze++;
        }
        else 
        {
            if(p==1)dat[1].gold++;
            else if(p==2)dat[1].silver++;
            else if(p==3)dat[1].bronze++;
        }

    }
    for(int i=0;i<2;i++)cout<<dat[i].gold<<" "<<dat[i].silver<<" "<<dat[i].bronze<<endl;
    sort(dat,dat+2);
    if(dat[0].id==0)cout<<"The first win!\n";
    else cout<<"The second win!\n";
    return 0;
}