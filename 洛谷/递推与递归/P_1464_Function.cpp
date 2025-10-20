// #include<bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// map<string, ll> mp;  // 存储long long结果，避免溢出

// ll w(ll a, ll b, ll c) {
//     // 关键修正：用逗号分隔，确保键唯一
//     string s = to_string(a) + "," + to_string(b) + "," + to_string(c);
//     if (mp.count(s)) return mp[s];  // 命中缓存
    
//     // 条件判断（保持原逻辑）
//     if (a <= 0 || b <= 0 || c <= 0) return mp[s] = 1;
//     else if (a > 20 || b > 20 || c > 20) return mp[s] = w(20, 20, 20);
//     else if (a < b && b < c) 
//         return mp[s] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
//     else 
//         return mp[s] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
// }

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     ll a, b, c;
//     while (true) {
//         cin >> a >> b >> c;
//         if (a == -1 && b == -1 && c == -1) break;
//         // 输出格式匹配long long
//         printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// map<string,ll>mp;
// ll w(ll x,ll y,ll z)
// {
//     //防止出现重复  11 2 3 ！=1 12 3
//     string s=to_string(x)+","+to_string(y)+","+to_string(z);
//     if(mp.count(s))return mp[s];
//     if(x<=0||y<=0||z<=0)return 1;
//     //注意记忆化搜索的写法
//     else if(x>20||y>20||z>20)return mp[s]= w(20,20,20);
//     else if(x<y&&y<z)return mp[s]= w(x,y,z-1)+w(x,y-1,z-1)-w(x,y-1,z);
//     else return mp[s]=w(x-1,y,z)+w(x-1,y-1,z)+w(x-1,y,z-1)-w(x-1,y-1,z-1);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     ll a,b,c;
//     while(cin>>a>>b>>c)
//     {
//         if(a==-1&&b==-1&&c==-1)break;
//         printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
//     }
    
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[30][30][30];
bool vis[30][30][30];//注意这种记忆化搜索的方式
//vis 数组很关键 不可以直接用w数组！！！
ll mw(long long a,long long b,long long c)
{
    if(a<=0 or b<=0 or c<=0) return 1;
    if(a>20 or b>20 or c>20) return mw(20,20,20);
    if(vis[a][b][c]) return w[a][b][c];
    if(a<b and b<c)
        w[a][b][c]=mw(a,b,c-1)+mw(a,b-1,c-1)-mw(a,b-1,c);
    else
        w[a][b][c]=mw(a-1,b,c)+mw(a-1,b-1,c)+mw(a-1,b,c-1)-mw(a-1,b-1,c-1);
    vis[a][b][c]=true;
    return w[a][b][c];
}
ll dp[30][30][30];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(1)
    {
        ll a,b,c;cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1)break;
         printf("w(%lld, %lld, %lld) = %d\n",a,b,c,mw(a,b,c));
    }
    return 0;
}