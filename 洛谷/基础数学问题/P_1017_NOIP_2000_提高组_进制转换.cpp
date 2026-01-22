//应该和以前的做法一样吧（尽管是负数）
//wrong
//注意编程中的取余数和数学中的不一样 数学中余数是不可以小于0的 但编程不是这样子的
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,r;cin>>n>>r;
//     int x=n;
//     string s="";
//     while(x)
//     {
//         if(abs(x%r)>=10)
//         s+=abs(x%r)-10+'A';
//         else
//         s+=abs(x%r)+'0';   
//         x/=r;
//     }
//     reverse(s.begin(),s.end());
//     cout<<n<<"="<<s<<"(base"<<r<<")";
//     return 0;
// }



//取余（a % b）：结果的符号与 a（被除数）相同，数值上满足 a = (a / b) * b + (a % b)。
//除法（a / b）：结果向零取整（直接截断小数部分,截断小数部分，向 0 的方向靠近)
//由于除数为负且余数的绝对值必定小于除数的绝对值，所以余数减除数必定不为负。因此当余数为负时只需将商加 1，余数减除数就可以了。

//下面的方法好理解，本质上一致的
// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// void solve(int n)
// {
//     if(!n)return ;
//     int t=n/m,l=n%m;
//     if(l<0)
//     {
//         t++;
//         l-=m;
//     }
//     solve(t);
//     if(l<10)cout<<l;
//     //else cout<<(l-10+'A');
//     else cout<<(char)(l+55);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     cout<<n<<"=";
//     solve(n);
//     cout<<"(base"<<m<<')';
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,m;
// void solve(int n)
// {
//     if(n==0)return;
//     int t=n/m,l=n%m;
//     if(l<0)
//     {
//         t++;
//         l-=m;
//     }
//     solve(t);
//     if(l<10)
//     {
//         cout<<l;
//     }
//     //注意这个要写上char 否则可能输出的还是数字
//     else cout<<char(l-10+'A');
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>m;
//     cout<<n<<"=";

//     solve(n);
//     cout<<"(base"<<m<<")";
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n,r;
// void solve()
// {
//     int l
//     while(n)
//     {
//         n
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>r;
//     solve();

//     return 0;
// }


//余数不能为负，负了就加 |R|，并修正商
//负进制 = 除基取余 + 余数修正


// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, R;
//     cin >> n >> R;

//     int orig = n;
//     int base = R;
//     vector<int> digit;

//     if (n == 0)
//         digit.push_back(0);

//     while (n != 0)
//     {
//         int r = n % R;
//         //负数
//         if (r < 0)
//         {
//             r += abs(R);
//             n = (n - r) / R;
//         }
//         //这就是以前经常写的正数
//         else
//         {
//             n /= R;
//         }
//         digit.push_back(r);
//     }

//     cout << orig << "=";
//     for (int i = digit.size() - 1; i >= 0; i--)
//     {
//         if (digit[i] < 10) cout << char('0' + digit[i]);
//         else cout << char('A' + digit[i] - 10);
//     }
//     cout << "(base" << base << ")";
// }


// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     //有这一行代码的话 printf和cout就不要混用了，否则会导致输出乱序
//     //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n,R;cin>>n>>R;
//     int origin=n;
//     vector<int>digit;
//     if(n==0)digit.push_back(0);
//     while(n!=0)
//     {
//         int r=n%R;
//         if(r<0)
//         {
//             r+=abs(R);//向高位接一个
//             n=(n-r)/R;
//         }
//         else
//         {
//             n/=R;
//         }
//         digit.push_back(r);
//     }
//     printf("%d=",origin);
//     for(int i=digit.size()-1;i>=0;i--)
//     {
//         if(digit[i]>=10)cout<<char(digit[i]-10+'A');
//         else cout<<digit[i];
//     }

//     printf("(base%d)",R);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,R;cin>>n>>R;
    int origin=n;
    vector<int>digit;
    while(n)
    {
        int r=n%R;
        if(r<0)
        {
            r+=abs(R);
            n-=r;
        }
        digit.push_back(r);
        n/=R;
    }
    cout<<origin<<"=";
    for(int i=digit.size()-1;i>=0;i--)
    {
        if(digit[i]>=10)cout<<(char)(digit[i]-10+'A');
        else cout<<digit[i];
    }
    cout<<"(base"<<R<<")";
    return 0;
}