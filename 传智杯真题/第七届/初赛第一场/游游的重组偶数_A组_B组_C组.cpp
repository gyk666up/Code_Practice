#include<bits/stdc++.h>
using namespace std;
int q;
int main()
{
    cin>>q;
    while(q--)
    {
        int x;cin>>x;
        if(x%2==0)
        {
            cout<<x<<endl;
            continue;
        }
        string s=to_string(x);
        string temp="";
        //把其中的一位偶数移到最后一位
        for(int i=0;i<s.size();i++)
        {
            //不能有前导 0
            if((s[i]-'0')%2==0&&s[i+1]!='0')
            {
                temp=s[i];
                s.erase(i,1);//同时把这个数字删去
                break;
            }
        }
        //if((temp[0]-'0')%2==0)
        if(temp!="")
        {
            s+=temp;
            cout<<s<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}