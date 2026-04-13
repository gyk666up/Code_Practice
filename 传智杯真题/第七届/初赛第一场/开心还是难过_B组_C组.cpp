#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    getline(cin,s);
    int cnt1=0,cnt2=0;
    for(int i=0;i<s.size();i++)
    {
        if(i+2<s.size()&&s.substr(i,3)==":-)")cnt1++;
        else if(i+2<s.size()&&s.substr(i,3)==":-(")cnt2++;
    }
    if(cnt1==0&&cnt2==0)cout<<"None\n";
    else if(cnt1>cnt2)cout<<"Happy\n";
    else if(cnt1==cnt2)cout<<"Just so so\n";
    else if(cnt1<cnt2)cout<<"Sad\n";
    return 0;
}