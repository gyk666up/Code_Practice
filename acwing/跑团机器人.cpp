#include<bits/stdc++.h>
using namespace std;
const int N=1e3+22;
int a[N];//下标是面数 大小是个数
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    int t=1;//默认为正
    int min_v=0,max_v=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+')t=1;
        else if(s[i]=='-')t=-1;
        else if(isdigit(s[i])||s[i]=='d')
        {
            int x=0,y=0;
            if(isdigit(s[i]))
            {
                for(;isdigit(s[i]);i++)
                {
                    x=x*10+s[i]-'0';
                }
            }
            //此时如果s[i]=='d' 处理y
            if(s[i]=='d')
            {
                i++;
                for(;isdigit(s[i]);i++)
                {
                    y=y*10+s[i]-'0';
                }
            }
            i--;//避免跳过字符（两个i++,另一个是最外层for循环）！！！ 好好理解一下
            if(x==0&&y!=0)x=1;
            if(y)
            {
                a[y]+=x;
                if(t>0)
                {
                    min_v+=x*1;
                    max_v+=x*y;
                }
                else 
                {
                    min_v-=x*y;
                    max_v-=1*x;
                }
            }
            //普通数字
            else
            {
                min_v+=t*x;
                max_v+=t*x;
            }
        }
    }
    for(int i=1;i<=N;i++)if(a[i])
    {
        cout<<i<<" "<<a[i]<<endl;
    }
    cout<<min_v<<" "<<max_v<<endl;
    return 0;
}