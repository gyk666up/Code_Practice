#include<bits/stdc++.h>
using namespace std;
const int N=30;
struct node
{
    int id;
    int score;
}dat[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    int tmp=n;
    while(tmp--)
    {
        for(int i=1;i<=20;i++)
        {
            int p,k;cin>>p>>k;
            if(p==1) dat[i].score+=12+k;
            else if(p==2)dat[i].score+=9+k;
            else if(p==3)dat[i].score+=7+k;
            else if(p==4)dat[i].score+=5+k;
            else if(p==5)dat[i].score+=4+k;
            else if(6<=p&&p<=7)dat[i].score+=3+k;
            else if(p>=8&&p<=10)dat[i].score+=2+k;
            else if(p>=11&&p<=15)dat[i].score+=1+k;
            else dat[i].score+=k;
        }
    }
    for(int i=1;i<=20;i++)
    {
        cout<<i<<" "<<dat[i].score<<endl;
    }
    return 0;
}