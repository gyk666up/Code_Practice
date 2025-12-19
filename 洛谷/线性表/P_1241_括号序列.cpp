// #include<bits/stdc++.h>
// using namespace std;
// stack<char>stk;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     //思路压入左半边
//     string s;cin>>s;
//     for(int i=0;i<s.size();i++)
//     {
//         if(s[i]=='('||s[i]=='[')stk.push(s[i]);
//         else 
//         {
//             if(s[i]==')')
//             {
//                 char top=stk.top();
//                 if(top==')')
//             }
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> match(n, -1); // 记录每个位置的配对索引，-1表示未配对
    stack<pair<char, int>> st; // 存储左括号的字符和索引

    // 第一步：遍历字符串，标记配对的括号
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == '(' || c == '[') {
            // 左括号入栈
            st.push({c, i});
        } else {
            // 右括号，检查栈顶是否有匹配的左括号
            if (!st.empty()) {
                auto top = st.top();
                // 类型匹配：')'匹配'(', ']'匹配'['
                if ((c == ')' && top.first == '(') || (c == ']' && top.first == '[')) {
                    match[i] = top.second; // 记录当前右括号的配对索引
                    match[top.second] = i; // 记录左括号的配对索引
                    st.pop(); // 弹出已匹配的左括号
                }
            }
            // 若栈空或不匹配，当前右括号未配对（match[i]保持-1）
        }
    }

    // 第二步：构建结果字符串
    string res;
    for (int i = 0; i < n; ++i) {
        if (match[i] != -1) {
            // 已配对的括号直接加入结果
            res += s[i];
        } else {
            // 未配对的括号，添加对应的匹配括号
            if (s[i] == '(' || s[i] == '[') {
                // 未配对的左括号：先加自身，再加匹配的右括号
                res += s[i];
                res += (s[i] == '(' ? ')' : ']');
            } else {
                // 未配对的右括号：先加匹配的左括号，再加自身
                res += (s[i] == ')' ? '(' : '[');
                res += s[i];
            }
        }
    }

    cout << res << endl;
    return 0;
}
