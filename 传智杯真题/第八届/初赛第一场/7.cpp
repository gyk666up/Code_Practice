// //这道题重点看一下，
// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int main() {
//     // 优化输入输出速度
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//         string s;cin >> s ;
//         long long ans = 0;
//         int last_d = -1;
//         int last_r = -1;
//         int last_e = -1;

//         //i 是右端点
//         for (int i = 0; i < s.length(); ++i) {
//             // 更新字符最后一次出现的下标
//             if (s[i] == 'd') last_d = i;
//             if (s[i] == 'r') last_r = i;
//             if (s[i] == 'e') last_e = i;

//             //last_d < L <= min(last_r, last_e)合法的范围
//             // 计算合法的左端点数量 
//             int valid_L_count = min(last_r, last_e) - last_d;
            
//             // 如果大于0，说明有合法的子串
//             if (valid_L_count > 0) {
//                 ans += valid_L_count;
//             }
//         }

//         cout << ans << "\n";
    

//     return 0;
// }




//太巧妙了，好好理解一下
#include<bits/stdc++.h>
using namespace std;
#define int long long
int lastr=-1,lastd=-1,laste=-1;
signed main()
{
    string s;cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='r')lastr=i;
        if(s[i]=='d')lastd=i;
        if(s[i]=='e')laste=i;

        int valid=min(lastr,laste)-lastd;
        if(valid>0)
        {
            ans+=valid;
        }
    }
    cout<<ans;
    return 0;
}



























