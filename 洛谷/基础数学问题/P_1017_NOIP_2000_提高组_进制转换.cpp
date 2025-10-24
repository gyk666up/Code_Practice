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


