//我靠好聪明啊自己
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n,k;
char a[N];
int main()
{
    cin>>n>>k;
    int da=0,xiao=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(isupper(a[i]))da++;
        else xiao++;
    }
    if(k>=xiao)//把小写全变成大写
    {
        k-=xiao;
        //把剩余的k 对一个字母进行操作，这样最多损失一个吧
        //奇数变化，偶数不变化
        if(k%2==1)cout<<n-1;
        else cout<<n;
    }
    else 
    {
        cout<<da+k;
    }
    return 0;
}