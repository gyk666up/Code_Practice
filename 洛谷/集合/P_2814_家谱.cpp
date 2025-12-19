//没思路
// #include<bits/stdc++.h>
// using namespace std;
// int find(int fa)
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     while(1)
//     {
//         string fa,hai;
//         string s;cin>>s;
//         if(s[0]=='#')fa=s.substr(1);//从下标1开始到末尾
//         else if(s[0]=='+')hai=s.substr(1);

//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// //其实这个是与并查集的fa数组功能是一样的 只不过那个只能是数字 记住这种用法
// map<string,string>mp;//第一个是孩子 后面是他的父亲
// string s,s1;
// string find(string x)
// {
//     if(mp[x]==x)return x;
//     return mp[x]=find(mp[x]);
// }
// int main()
// {
//     //注意这种数据的输入 第一次输入的时候感觉无从下手很别扭
//     char ch;
//     while(cin>>ch)
//     {
//         if(ch=='$')break;
//         cin>>s;
//         if(ch=='#')//父亲（祖先）就是自己 也是初始化！！！
//         {
//             s1=s;
//             if(mp[s]=="")mp[s]=s;
//         }
//         else if(ch=='+')mp[s]=s1;
//         else
//         cout<<s<<' '<<find(s)<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
map<string,string>mp;
string fa,hai;
string find(string s)
{
    if(mp[s]==s)return s;
    else return mp[s]=find(mp[s]);
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    char ch;
    while(cin>>ch)
    {
        if(ch=='$')break;
        else if(ch=='#')
        {
            cin>>fa;

            //这样这里代码的写法
            //// 若fa未被初始化，设为自己的父节点（成为根）
            // mp[fa]=fa; //不能直接这样写 有可能这个人是另一个的孩子 但在这是父亲
            if(mp[fa]=="")mp[fa]=fa;
        }
        else if(ch=='+')
        {
            cin>>hai;
            mp[hai]=fa;
        }
        else
        {
            cin>>hai;
            cout<<hai<<" "<<find(hai)<<endl;
        }
    }
    return 0;
}