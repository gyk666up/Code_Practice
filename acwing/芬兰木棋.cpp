//分数最大且次数最少：分数为1的在一个方向（连续）一锅端 
//分数>1 一个一个来
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+55;
typedef pair<ll,ll>PII;
map<PII,vector<pair<ll,int>>>mp;//按不同方向存储棋
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    int score=0;
    int step=0;//记录最少的次数
    for(int i=0;i<n;i++)
    {
        ll x,y,p;
        cin>>x>>y>>p;
        ll d=x*x+y*y;//直接存储距离的平方省去开根号
        ll w=abs(__gcd(x,y));//直接调用C++内置函数_gcb 最大公约数
        x/=w,y/=w;
        score+=p;
        mp[{x,y}].push_back({d,p});
    }

    for(auto it:mp)
    {
        vector<pair<ll,int>>v=it.second;
        int s=v.size();
        sort(v.begin(),v.end());
        for(int i=0;i<s;i++)
        {
            if(v[i].second!=1)step++;
            //
            else//分数为1 只处理一次（几个连续的1的情况下）
            {
               // 当前木棋是该方向的最后一个木棋  当前木棋后面有分数不为 1 的木棋
                if(i+1==s||(i+1<s&&v[i+1].second!=1))step++;
            }
        }
    }
    cout<<score<<" "<<step;
    return 0;
}