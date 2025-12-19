// //读完题想用map
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// map<int,vector<int>>mp;//第一维是品种 第二位是同一种品种的奶牛的坐标
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x,id;cin>>x>>id;
//         mp[id].push_back(x);
//     }
//     //不应该是挑最大的最小的 而是找最近的点
//     int min_=1e9;
//     int max_=-1;
//     //mp.size()一共有的奶牛数量
//     // for(int i=0;i<mp.size();i++)
//     // {
//     //     vector<int>t=mp[i];
//     //     sort(t.begin(),t.end());
//     //     if(min_>t[0])min_=t[0];
//     //     if(max_<t[0])max_=t[0];
//     // }
//     for(auto m:mp)
//     {
//         vector<int>t=m.second;
//         sort(t.begin(),t.end());
//         if(min_>t[0])min_=t[0];
//         if(max_<t[0])max_=t[0];
//     }
//     cout<<max_-min_;
    
//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;

// struct Cow {
//     int x, id; // x坐标和品种ID
// };

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     int n;
//     cin >> n;
//     vector<Cow> cows(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> cows[i].x >> cows[i].id;
//     }
    
//     // 按x坐标从小到大排序
//     sort(cows.begin(), cows.end(), [](const Cow& a, const Cow& b) {
//         return a.x < b.x;
//     });
    
//     // 统计总共有多少种不同的品种
//     unordered_set<int> kinds;
//     for (const auto& cow : cows) {
//         kinds.insert(cow.id);
//     }
//     int total_kinds = kinds.size();
    
//     // 滑动窗口寻找最小成本
//     unordered_map<int, int> cnt; // 记录当前窗口中各品种的数量
//     int left = 0;
//     int current_kinds = 0; // 当前窗口中包含的品种数
//     int min_cost = INT_MAX;
    
//     for (int right = 0; right < n; ++right) {
//         int id = cows[right].id;
//         // 若当前品种是第一次加入窗口，更新当前品种数
//         if (cnt[id] == 0) {
//             current_kinds++;
//         }
//         cnt[id]++;
        
//         // 当窗口包含所有品种时，尝试缩小窗口
//         while (current_kinds == total_kinds) {
//             // 计算当前窗口的成本
//             int current_cost = cows[right].x - cows[left].x;
//             if (current_cost < min_cost) {
//                 min_cost = current_cost;
//             }
//             // 移动左指针，缩小窗口
//             int left_id = cows[left].id;
//             cnt[left_id]--;
//             // 若该品种在窗口中数量变为0，当前品种数减少
//             if (cnt[left_id] == 0) {
//                 current_kinds--;
//             }
//             left++;
//         }
//     }
    
//     cout << min_cost << endl;
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// struct Cow
// {
//     int x,id;
//     bool operator<(const Cow&u)
//     {
//         return x<u.x;
//     }
// };
// int n;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     vector<Cow>cows(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>cows[i].x>>cows[i].id;
//     }
//     sort(cows.begin(),cows.end());
//     unordered_set<int>kinds;
//     for(int i=0;i<n;i++)
//     {
//         kinds.insert(cows[i].id);
//     }
//     int m=kinds.size();
//     //滑动窗口
//     map<int,int>cnt;//统计不同品种的数量
//     int left=0;
//     int curr_kind=0;//当前窗口的种类数量
//     int min_=0x3f3f3f3f;
//     for(int r=0;r<n;r++)
//     {
//         int id=cows[r].id;
//         if(cnt[id]==0)
//         {
//             curr_kind++;
//         }
//         cnt[id]++;
//         //为什么我的这段代码得加上这个限制条件 上面的这段代码就不用
//         while(curr_kind==m)
//         {
//             int cost=cows[r].x-cows[left].x;
//             if(cost<min_)min_=cost;

//             int left_id=cows[left].id;
//             cnt[left_id]--;
//             if(cnt[left_id]==0)curr_kind--;
        
//             left++;
//         }
//     }
//     cout<<min_;
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int n;
// #define int long long
// struct Cow
// {
//     int x,id;
//     bool operator<(const Cow&u)
//     {
//         return x<u.x;
//     }
// };
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     vector<Cow>cows(n);
//     unordered_set<int>kinds;//统计不同品种的数量
//     for(int i=0;i<n;i++)
//     {
//         cin>>cows[i].x>>cows[i].id;
//         kinds.insert(cows[i].id);
//     }
//     sort(cows.begin(),cows.end());
//     int all_kinds=kinds.size();

//     int left=0;
//     map<int,int>mp;//统计不同品种的种类数
//     int curr_kinds=0;//统计当前窗口的种类数量
//     int ans=0x3f3f3f3f;
//     for(int r=0;r<n;r++)
//     {
//         int id=cows[r].id;

//         //我靠！注意这里 id这个键仍然存在 只不过键的值是0 
//         //if(mp.count(id)==0)curr_kinds++;

//         if(mp[id]==0)curr_kinds++;
//         mp[id]++;
        
//         int x=cows[r].x;
        
        


//         while(curr_kinds==all_kinds)
//         {
//             int x2=cows[left].x;
//             int id=cows[left].id;
//             ans=min(ans,x-x2);
//             mp[id]--;
//             if(mp[id]==0)curr_kinds--;
//             left++;
//         }

//     }
    
//     cout<<ans;
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;
#define int long long
struct cow
{
    int x,id;
    bool operator<(const cow&u)
    {
        return x<u.x;
    }
};
int n;
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    vector<cow>cows(n);
    //注意multiset 只有这个集合是可以允许多个一样的值存在的 其他的集合都会自动去重
    set<int>kinds;
    for(int i=0;i<n;i++)
    {
        cin>>cows[i].x>>cows[i].id;
        kinds.insert(cows[i].id);
    }
    int m=kinds.size();
    sort(cows.begin(),cows.end());
    int l=0;
    map<int,int>mp;//统计窗口中不同品种的数量
    int curr_kind=0;
    int ans=0x3f3f3f3f;
    for(int r=0;r<n;r++)
    {
        //这里面的代码顺序很重要
        int x=cows[r].x;
        int id=cows[r].id;

        if(mp[id]==0)curr_kind++;
        mp[id]++;

        //先变化最后在移动
        while(curr_kind==m)
        {
            mp[cows[l].id]--;
            ans=min(ans,cows[r].x-cows[l].x);

            if(mp[cows[l].id]==0)curr_kind--;

            l++;
        }
    }
    cout<<ans<<endl;
    return 0;
}