//#pragma GCC optimize(2,3,"inline") //洛谷中这行代码不能用


#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x)
{
    if(x<=1)return false;
    for(int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)return false;
    }
    return true;
}
//好聪明哈哈哈
bool is_hui(int x)
{
    string s1=to_string(x);
    string s2=s1;
    reverse(s1.begin(),s1.end());
    if(s1==s2)return true;
    else return false;
}
const int N=7e7;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a,b;cin>>a>>b;
    for(int i=a;i<=b;i+=2)
    {
         if(i==2)
         {
            cout<<i<<endl;
            continue;
         }
        //偶数一定不是素数(除了2)
        if(i%2==0)continue;
        if(i==1)continue;
        
        if(!is_hui(i))continue;
        if(is_prime(i))
        {
            cout<<i<<endl;
        } 
        
    }
    return 0;
}
       
    
