
//解析时间错误
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+55;
int zhu[N];
int pei[N],tang[N];
int n1,n2,n3;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n1>>n2>>n3;
    for(int i=1;i<=n1;i++)cin>>zhu[i];
    for(int i=1;i<=n2;i++)cin>>pei[i];
    for(int i=1;i<=n3;i++)cin>>tang[i];
    getchar();
    string s;getline(cin,s);
    int hh1,mm1,hh2,mm2;
    int m;//候选个数
    //(s.c_str(),"%02d:%02d %02d:%02d %d",&hh1,&mm1,&hh2,&mm2,&m);
     sscanf(s.c_str(),"%02d:%02d %02d:%02d %d",&hh1,&mm1,&hh2,&mm2,&m);
    //cout<< hh1<<" "<<mm1<<" "<<hh2<<" "<<mm2<<" "<<m;
    int times=0;//总共的时间(分钟)
    if(mm2-mm1>=0)times=(hh2-hh1)*60+(mm2-mm1);
    else times=(hh2-hh1-1)*60+(mm2+60-mm1);
    
    while(m--)
    {
        int k;cin>>k;
        int needs=0;//记录需要的时间
        bool z=0,p=0,t=0;
        for(int i=0;i<k;i++)
        {
            string s;cin>>s;
            if(s[0]=='T')
            {
                t=1;
                needs+=tang[s[1]-'0'];
            }
            else if(s[0]=='Z')
            {
                z=1;
                needs+=zhu[s[1]-'0'];
            }
            else if(s[0]=='P')
            {
                p=1;
                needs+=pei[s[1]-'0'];
            }
        }
        if(z&&p&&t&&needs<=times)cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}