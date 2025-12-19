#include<bits/stdc++.h>
using namespace std;
//这段代码看似对 其实错误还挺大的 map会重复往vector力加元素
//想到用map 每个单词为一个map 值为位置
const int N=1e3+11;
bool st[N];
map<string,vector<int>>mp;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;

     //
    for(int i=1;i<=n;i++)
    {
        int all;cin>>all;
        for(int j=0;j<all;j++)
        {
            string words;cin>>words;
            mp[words].push_back(i);
        }
    }
    int m;cin>>m;
    while(m--)
    {

        string s; cin >> s;
        //注意这种map<string,vector<int>>mp的遍历方式 
        // 方式1：范围for循环（更简洁）
        if(mp[s].size()==0)
        {
            cout<<endl;//空行不是空格
            continue;
        }
        memset(st,0,sizeof st);
        bool first=1;
        // for (int num : mp[s]) {
        //     if(st[num]){
        //         continue;
        //     }
        //     else{
        //         st[num]=1;
        //         if(first)
        //     {
        //         cout<<num;
        //         first=0;
        //        // continue;
        //     }
        //     else{
        //         cout <<" "<<num;
        //     }
        //     }
        // }
        //  cout << endl;

        // 方式2：迭代器循环
        //如果auto 不可以用就这样写
        for (vector<int>::iterator it = mp[s].begin(); it != mp[s].end(); ++it) {
        
            int num = *it; // *it是int，直接使用
             if(first)
            {
                cout<<num;
                first=0;
                continue;
            }
            cout << " "<< num ;
        }
        cout << endl;
    }
    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// map<string,vector<int>>mp;
// const int N=1e3+11;
// bool st[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int all;cin>>all;
//         for(int j=0;j<all;j++)
//         {
//             string words;cin>>words;
//             mp[words].push_back(i);
//         }
//     }
//     int m;cin>>m;
//     for(int i=1;i<=m;i++)
//     {
//         memset(st,0,sizeof st);
//         string s;cin>>s;
//         bool first=1;
//         for(int num:mp[s])
//         {
//             if(st[num])continue;
//             else
//             {
//                 if(first)
//                 {
//                     st[num]=1;
//                     first=0;
//                     cout<<num;
//                 }
//                 else
//                 {
//                     st[num]=1;
//                     cout<<" "<<num;
//                 }
//             }
//         }
//         cout<<endl;
//     }
//     return 0;
// }