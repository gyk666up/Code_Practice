#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;cin>>s;
    vector<int>ans;
    while(s.size())
    {
        for(int len=1;len<=10;len++)
        {
            //注意这里是大于不是>=  len 是长度
            if(0+len>s.size())
            {
                cout<<ans.size()<<endl;
                for(int i=0;i<ans.size();i++)
                {
                    cout<<ans[i]<<" ";
                }
                return 0;
            }
            //string temp=s.substr(0,len);//这这只是二进制
            int x=0;
            for(int i=0;i<len;i++)
            {
                x=x*2+s[i]-'0';
            }
            s.erase(0,len);
            
            //for(int i=0;i<temp.size();i++)x=x*2+temp[i]-'0';
            //cout<<x<<" ";
            ans.push_back(x);
        }
    }
    return 0;
}