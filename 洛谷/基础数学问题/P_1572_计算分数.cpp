//自己的思路 错的地方很多 首先分子分母不能单独拎出来 求和
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// string s;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>s;
//     int sum1=0;
//     int sum2=0;
//     //找到每个分子和分母 然后对它们求和
//     for(int i=0;i<s.size();i++)
//     {
//         int t=1;
//         if(s[i]=='-')
//         {
//             t=-1;
//             continue;
//         }
//         //找分子
//         int x=0;
//         while(isdigit(s[i]))
//         {
//             x=x*10+s[i]-'0';
//             i++;
//         }
//         if(s[i]=='/')i++;
//         int y=0;
//         while(isdigit(s[i]))
//         {
//             y=y*10+s[i]-'0';
//             i++;
//         }
//         i--;//避免跳的多 以前做的题上有过类似的形式
//         sum1+=t*x;
//         sum2+=t*y;
//     }
//     if(sum1%sum2==0)cout<<sum1/sum2;
//     else cout<<sum1<<"/"<<sum2;
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string s;cin>>s;
//     int n=s.size();

//     int i=0;
//     int p=0,q=1;
//     while(i<n)
//     {
//         int sign=1;
//         if(s[i]=='+')
//         {
//             sign=1;
//             i++;
//         }
//         else if(s[i]=='-') 
//         {
//             sign=-1;
//             i++;
//         }

//         int fenzi=0;
//         while(i<n&&isdigit(s[i]))
//         {
//             fenzi=fenzi*10+(s[i]-'0');
//             i++;
//         }
//         fenzi*=sign;//这个符号只需要乘分子、分母中的一个就可以了 乘两个相当于每乘
//         //此时应该s[i]=='/'
//         i++;
//         int fenmu=0;
//         while(i<n&&isdigit(s[i]))
//         {
//             fenmu=fenmu*10+(s[i]-'0');
//             i++;
//         }

//         int new_fenzi=p*fenmu+q*fenzi;
//         int new_fenmu=q*fenmu;
//         int g=__gcd(abs(new_fenzi),abs(new_fenmu));
        
//         new_fenmu=new_fenmu/g;
//         new_fenzi=new_fenzi/g;
//         if(new_fenmu<0)
//         {
//             new_fenmu=-new_fenmu;
//             new_fenzi=-new_fenzi;
//         }
//         p=new_fenzi;
//         q=new_fenmu;
//     }
//     if(q==1)cout<<p;
//     else cout<<p<<"/"<<q;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    int p=0,q=1;
    int n=s.size();
    int i=0;
    while(i<n)
    {
        int t=1;
        if(s[i]=='+')t=1,i++;
        //else t=-1,i++; 易错点！！!!
        else if(s[i]=='-')t=-1,i++;//这里千万不能使用else 否则会将除+以外的所有字符都识别为else t=-1
        int x=0;
        while(i<n&&isdigit(s[i]))
        {
            x=x*10+s[i]-'0';
            i++;
        }
        x*=t;
        //cout<<"X="<<x;
        if(s[i]=='/')i++;
        int y=0;
        while(i<n&&isdigit(s[i]))
        {
            y=y*10+s[i]-'0';
            i++;
        }
        int new_fenzi=p*y+x*q;
        int new_fenmu=q*y;

        int g=__gcd(abs(new_fenzi),abs(new_fenmu));

        //化简
        new_fenzi=new_fenzi/g;
        new_fenmu=new_fenmu/g;

        if(new_fenmu<0)
        {
            new_fenmu=-new_fenmu;
            new_fenzi=-new_fenzi;
        }
        p=new_fenzi;
        q=new_fenmu;
    }
    if(q==1)cout<<p;
    else cout<<p<<"/"<<q;
    return 0;
}