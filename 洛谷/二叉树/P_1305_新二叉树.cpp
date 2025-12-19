// //没思路
// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     char lc;
//     char rc;
// }dat[130];//实际上起作用的只有73-122 将字母的ASCII值作为下标  //这个很细节
// void dfs(char x)
// {
//     if(x=='*')return;
//     cout<<x;
//     dfs(dat[x].lc);
//     dfs(dat[x].rc);
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     char h1;//整个树的根节点
//     cin>>h1>>dat[h1].lc>>dat[h1].rc;

//     for(int i=2;i<=n;i++)
//     {
//         char h;
//         cin>>h>>dat[h].lc>>dat[h].rc;
//     }
//     dfs(h1);//先序遍历
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;

struct node
{
    char val;
    char left;  // 显式存储，包括*
    char right; // 显式存储，包括*
}dat[200];

map<char, bool> mp;  // 记录所有节点，用于找根节点
int n;

// 前序遍历：根→左→右
void dfs(char val)
{
    // 若当前节点是*，表示空节点，直接返回
    if(val == '*') return;
    
    cout << val;  // 输出当前节点
    
    // 查找当前节点在dat中的索引
    int next_id = -1;
    for(int i=1; i<=n; i++)
    {
        if(dat[i].val == val)
        {
            next_id = i;
            break;  // 找到后退出循环，优化效率
        }
    }
    if(next_id == -1) return;  // 未找到节点（理论上不会发生）
    
    // 递归遍历左右孩子（即使是*，也会在dfs入口判断并返回）
    dfs(dat[next_id].left);
    dfs(dat[next_id].right);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    
    for(int i=1; i<=n; i++)
    {
        char val, left, right;
        cin >> val >> left >> right;
        
        // 无论left/right是否为*，都显式赋值，避免未初始化
        dat[i].val = val;
        dat[i].left = left;
        dat[i].right = right;
        
        // 将当前节点值存入mp
        mp[val] = true;
        
        //这些孩子其实不用判断了 已经不可可能是根节点
        // // 左孩子不是*时，存入mp（表示该节点是某个节点的孩子）
        // if(left != '*')
        //     mp[left] = true;
        
        // // 右孩子不是*时，存入mp
        // if(right != '*')
        //     mp[right] = true;
    }
    
    // 删除所有作为孩子的节点，剩下的就是根节点（根节点不会是任何节点的孩子）
    for(int i=1; i<=n; i++)
    {
        // 即使left是*，也会尝试删除，但mp中没有*，无副作用
        mp.erase(dat[i].left);
        mp.erase(dat[i].right);
    }
    
    // 根节点是mp中仅剩的节点
    char root = mp.begin()->first;  // 直接取第一个（题目保证唯一）
    dfs(root);
    
    return 0;
}