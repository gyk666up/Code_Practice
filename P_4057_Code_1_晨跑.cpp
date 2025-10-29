//三个数的最小公倍数
//没写出来

//第一种方法
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int a,b,c;cin>>a>>b>>c;
//     //三个数的lcm就是其中两个的lcm和第三个数的lcm

//     cout<<(a*b*c)/__gcd(b,c)/__gcd(a,b*c/__gcd(b,c));//lcm(a,lcm(b,c));
//     return 0;
// }

//第二种方法
#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
int lcm(int x,int y)
{
    return x*y/gcd(x,y);
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a,b,c;cin>>a>>b>>c;
    long long ans=0;
    ans=lcm(a,lcm(b,c));
    cout<<ans;
    return 0;
}