// // //这是自己的思路 并没有用到二叉树的相关知识
// // #include<bits/stdc++.h>
// // using namespace std;
// // typedef pair<int,int>PII;
// // queue<PII>q;//存剩余的国家和对应的能力
// // int main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     int n;cin>>n;
// //     for(int i=1;i<=(int)pow(2,n);i++)
// //     {
// //         int x;cin>>x;
// //         q.push({i,x});
// //     }
// //     while(1)
// //     {
// //         if(q.size()==2)break;
// //         int country1=q.front().first,strength1=q.front().second;
// //         q.pop();
// //         int country2=q.front().first,strength2=q.front().second;
// //         q.pop();
// //         if(strength1<strength2)q.push({country2,strength2});
// //         else q.push({country1,strength1});
// //     }
// //     //剩下两个
// //     int country1=q.front().first,strength1=q.front().second;
// //     q.pop();
// //     int country2=q.front().first,strength2=q.front().second;
// //     q.pop();
// //     if(strength1<strength2)cout<<country1;
// //     else cout<<country2;
// //     return 0;
// // }


// // #include <iostream>
// // #include <vector>
// // using namespace std;

// // struct Node {
// //     int power;  // 能力值
// //     int id;     // 国家编号
// // };

// // int main() {
// //     int n;
// //     cin >> n;
// //     int m = 1 << n;  // 参赛国家数量：2^n
    
// //     // 向量大小为m+1，第0个元素占位，实际使用1~m索引
// //     vector<Node> current(m + 1);
// //     // 读取输入数据（索引从1开始）
// //     for (int i = 1; i <= m; ++i) {
// //         cin >> current[i].power;  // 读取能力值
// //         current[i].id = i;        // 国家编号与索引一致（1~m）
// //     }
    
// //     // 模拟比赛过程  注意这里的细节
// //     while (current.size() > 3) {  // 因为索引从1开始，size比实际元素多1，>3表示实际元素>2
// //         vector<Node> next;
// //         next.push_back(Node{});  // 占位，让next的索引也从1开始
        
// //         // 两两比赛（i从1开始，每次+2） 实际存的比有效的多一个
// //         for (int i = 1; i + 1 < current.size(); i += 2) {
// //             if (current[i].power > current[i+1].power) {
// //                 next.push_back(current[i]);
// //             } else {
// //                 next.push_back(current[i+1]);
// //             }
// //         }
        
// //         current = next;
// //     }
    
// //     // 决赛：当前只剩2支队伍（索引1和2）
// //     if (current[1].power > current[2].power) {
// //         cout << current[2].id << endl;  // 败者是亚军
// //     } else {
// //         cout << current[1].id << endl;
// //     }
    
// //     return 0;
// // }






// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     int id;
//     int strength;
// };
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     int m=1<<n;
//     vector<node>v(m+1);
//     for(int i=1;i<=m;i++)
//     {
//         int x;cin>>x;
//         v[i].id=i;
//         v[i].strength=x;
//     }
//     while(v.size()>3)
//     {
//         vector<node>next;
//         next.push_back(node());
//         for(int i=1;i+1<=v.size()-1;i+=2)
//         {
//             if(v[i].strength>v[i+1].strength)
//             next.push_back(v[i]);
//             else 
//             next.push_back(v[i+1]);
//         }
//         v=next;//v 是一个向量，用于存储 当前正在比赛的所有队伍（每一轮的参赛队伍）。
//             //next 是在每一轮比赛中临时创建的向量，用于存储 本轮比赛的获胜队伍（即晋级到下一轮的队伍）
//     }

//      if(v[1].strength > v[2].strength) {
//         cout << v[2].id << endl;
//     } else {
//         cout << v[1].id << endl;
//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
struct node
{
    int id;
    int s;
};
vector<node>v;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    int m=1<<n;
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        v.push_back({i,x});
    }
    while(v.size()>2)
    {
        vector<node>next;
        for(int i=0;i+1<=v.size()-1;i+=2)
        {
            if(v[i].s>v[i+1].s)next.push_back(v[i]);
            else next.push_back(v[i+1]);
        }
        v=next;
    }
    if(v[0].s>v[1].s)cout<<v[1].id;
    else cout<<v[0].id;
    return 0;
}

























