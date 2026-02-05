//我的思路：wrong
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// struct node
// {
//     int id;
//     char sex;
//     node(char s,int i):sex(s),id(i){};
// };
// const int N=2e5+11;
// char sex[N];
// int  id[N];
// //两个堆 左面的是大根堆 右面的是小根堆  
// priority_queue<node>le;
// priority_queue<node,vector<node>,greater<node>>re;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)cin>>sex[i];
//     for(int i=1;i<=n;i++)cin>>id[i];
//     for(int i=1;i<=n;i++)
//     {
//         if(sex[i]=='B')le.emplace(sex[i],id[i]);
//         else re.emplace(sex[i],id[i]);
//     }
//     while(le.size()&&re.size())
//     {
//         node man=le.top();
//         node woman=re.top();
//     }
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int diff;   // 技术差绝对值
//     int l;      // 左元素下标（1-based）
//     int r;      // 右元素下标
//     int id1;    // 左元素编号
//     int id2;    // 右元素编号
//     // 优先队列排序规则：小顶堆（diff小优先，diff相同则l小优先）
//     bool operator<(const Node& other) const {
//         if (diff != other.diff) return diff > other.diff;
//         return l > other.l;
//     }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;
//     string s;
//     cin >> s;
//     s = " " + s;  // 转为1-based索引
//     vector<int> a(n + 1);
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//     }

//     // 初始化双向链表
//     vector<int> left(n + 2, 0), right(n + 2, 0);
//     for (int i = 1; i <= n; ++i) {
//         left[i] = i - 1;
//         right[i] = i + 1;
//     }
//     right[n] = 0;  // 最后一个元素无右邻居

//     // 初始化优先队列（堆）
//     priority_queue<Node> pq;
//     for (int i = 1; i < n; ++i) {
//         if (s[i] != s[i + 1]) {
//             int diff = abs(a[i] - a[i + 1]);
//             pq.push({diff, i, i + 1, i, i + 1});
//         }
//     }

//     vector<pair<int, int>> res;  // 存储结果
//     vector<bool> deleted(n + 2, false);  // 标记元素是否已删除

//     while (!pq.empty()) {
//         auto node = pq.top();
//         pq.pop();
//         int l = node.l;
//         int r = node.r;

//         // 检查当前对是否有效：元素未删除且仍相邻
//         if (deleted[l] || deleted[r] || right[l] != r || left[r] != l) {
//             continue;
//         }

//         // 有效，记录结果
//         res.emplace_back(node.id1, node.id2);
//         // 标记元素为已删除
//         deleted[l] = true;
//         deleted[r] = true;

//         // 更新双向链表：连接l的左邻居和r的右邻居
//         int ll = left[l];
//         int rr = right[r];
//         if (ll != 0) right[ll] = rr;
//         if (rr != 0) left[rr] = ll;

//         // 检查新形成的相邻对（ll和rr）是否为异性，若是则加入堆
//         if (ll != 0 && rr != 0 && s[ll] != s[rr]) {
//             int diff = abs(a[ll] - a[rr]);
//             pq.push({diff, ll, rr, ll, rr});
//         }
//     }

//     // 输出结果
//     cout << res.size() << '\n';
//     for (auto& p : res) {
//         cout << p.first << " " << p.second << '\n';
//     }

//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     int diff;
//     int l,r;//左右元素下标
//     int id1,id2;//左右元素编号


//     //如果感觉有点绕的话，就可以想着说跟sort是相反的
//     bool operator<(const node&u)const
//     {
//         if(diff!=u.diff)return diff>u.diff;
//         return l>u.l;
//     }
//     node(int d,int x,int y,int xx,int yy):diff(d),l(x),r(y),id1(xx),id2(yy){};
// };
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     string s;cin>>s;
//     s=" "+s;
//     vector<int>a(n+1);
//     for(int i=1;i<=n;i++)cin>>a[i];
//     priority_queue<node>q;
//     for(int i=1;i<n;i++)
//     {
//         if(s[i]!=s[i+1])
//         {
//             int diff=abs(a[i]-a[i+1]);
//             q.emplace(diff,i,i+1,i,i+1);
//         }
//     }
//     vector<int>left(n+2);
//     vector<int>right(n+2);
//     for(int i=1;i<=n;i++)
//     {
//         left[i]=i-1;
//         right[i]=i+1;
//     }
//     right[n]=0;

//     vector<pair<int,int>>v;
//     vector<int>deleted(n+2);//判断节点是否还是有效的
//     while(q.size())
//     {
//         auto node=q.top();
//         q.pop();
//         int l=node.l;
//         int r=node.r;

//         if(deleted[l]||deleted[r]||left[r]!=l||right[l]!=r)continue;
        
//         //v.push_back({l,r});
//         v.push_back({node.id1,node.id2});
//         deleted[l]=1;
//         deleted[r]=1;


//         int ll=left[l];
//         int rr=right[r];
//         if(ll)right[ll]=rr;
//         if(rr)left[rr]=ll;

//         if(ll!=0&&rr!=0&&s[ll]!=s[rr])
//         {
//             int diff=abs(a[ll]-a[rr]);
//             q.emplace(diff,ll,rr,ll,rr);
//         }
//     }
//     cout<<v.size()<<endl;
//     for(int i=0;i<v.size();i++)
//     {
//         cout<<v[i].first<<" "<<v[i].second<<endl;
//     }
//     return 0;
// }

// //理解整个代码的逻辑，即使再长的代码也没有问题
// #include<bits/stdc++.h>
// using namespace std;
// int n;
// struct node
// {
//     int diff;
//     int l,r;
//     int id1,id2;
//     bool operator<(const node&u)const
//     {
//         if(diff!=u.diff)return diff>u.diff;
//         else return l>u.l;
//     }
// };
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     string s;cin>>s;
//     s=" "+s;
//     vector<int>a(n+1);
//     for(int i=1;i<=n;i++)cin>>a[i];

//     priority_queue<node>q;
//     //初始化队列
//     for(int i=1;i<n;i++)
//     {
//         if(s[i]!=s[i+1])
//         {
//             int diff=abs(a[i]-a[i+1]);
//             q.push({diff,i,i+1,i,i+1});
//         }
//     }

//     vector<int>left(n+2);
//     vector<int>right(n+2);
//     for(int i=1;i<=n;i++)
//     {
//         left[i]=i-1;
//         right[i]=i+1;
//     }
//     right[n]=0;//最右边和最左边的节点邻居节点是空

//     vector<pair<int,int>>res;//存结果
//     vector<int>deleted(n+1,false);//标记节点是否还可用
//     while(q.size())
//     {
//         node top=q.top();q.pop();
//         int l=top.l;
//         int r=top.r;
//         if(deleted[l]||deleted[r]||right[l]!=r||left[r]!=l)
//         {
//             continue;
//         }
//         res.push_back({top.id1,top.id2});

//         //删除符合的节点
//         deleted[l]=1;
//         deleted[r]=1;

//         int ll=left[l];
//         int rr=right[r];
//         if(ll!=0)left[rr]=ll;
//         if(rr!=0)right[ll]=rr;

//         //判断是否新符合条件
//         if(ll&&rr&&left[rr]==ll&&right[ll]==rr)
//         {
//             int diff=abs(a[ll]-a[rr]);
//             q.push({diff,ll,rr,ll,rr});
//         }
//     }
//     cout<<res.size()<<endl;
//     for(int i=0;i<res.size();i++)
//     {
//         auto t=res[i];
//         cout<<t.first<<" "<<t.second<<endl;
//     }
//     return 0;
// }




// //2026/2/4 还是不会写第一遍
// #include<bits/stdc++.h>
// using namespace std;
// const int N=2e5+11;
// int n;
// char s[N];
// int a[N];
// struct node
// {
//     int diff;
//     int l,r;//左右元素的下标
//     int id1,id2;//左右元素的编号 编号不会变 但是左右元素的下标是可以变化的
//     bool operator<(const node&u)const
//     {
//         if(diff!=u.diff)return diff>u.diff;
//         else return l>u.l;
//     }
// };//排序和sort相反
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     for(int i=1;i<=n;i++)cin>>s[i];
//     for(int i=1;i<=n;i++)cin>>a[i];
//     priority_queue<node>q;
//     for(int i=1;i+1<=n;i++)
//     {
//         if(s[i]!=s[i+1])
//         {
//             int diff=abs(a[i]-a[i+1]);
//             q.push({diff,i,i+1,i,i+1});
//         }
//     }
//     vector<int>le(n+2),ri(n+2);
//     for(int i=1;i<=n;i++)
//     {
//         le[i]=i-1;
//         ri[i]=i+1;
//     }
//     ri[n]=0;
//     vector<pair<int,int>>res;
//     vector<bool>deleted(n+2);
//     while(q.size())
//     {
//         auto t=q.top();
//         q.pop();
//         int l=t.l,r=t.r;
//         // if(!deleted[l]&&!deleted[r])
//         // {
//         //     res.push_back({l,r});
//         // }

//         if(deleted[l]||deleted[r])continue;
//         res.push_back({l,r});
//         deleted[l]=deleted[r]=1;

//         int ll=le[l];
//         int rr=ri[r];

//         if(ll!=0)ri[ll]=rr;
//         if(rr!=0)le[rr]=ll;

//         // if(s[ll]!=s[rr])
//         // {
//         //     int diff=abs(a[ll]-a[rr]);
//         //     q.push({diff,ll,rr,ll,rr});
//         // }

//         //判断是否新符合条件
//         if(ll&&rr&&le[rr]==ll&&ri[ll]==rr)
//         {
//             if(s[ll]!=s[ee])
//             {
//                 int diff=abs(a[ll]-a[rr]);
//                  q.push({diff,ll,rr,ll,rr});
//             }
//         }
//     }
//     cout<<res.size()<<endl;
//     for(auto t:res)
//     {
//         cout<<t.first<<" "<<t.second<<endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+11;
char s[N];
int a[N];
int le[N];
int ri[N];
struct node
{
    int diff;
    int id1,id2;//左右元素的编号
    int l,r;//左右元素的下标
    bool operator<(const node&u)const
    {
        if(diff!=u.diff)return diff>u.diff;
        else return l>u.l;
    }
};
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    priority_queue<node>q;
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)cin>>a[i];

    for(int i=1;i+1<=n;i++)
    {  
        if(s[i]!=s[i+1])
        {
            int diff=abs(a[i]-a[i+1]);
            q.push({diff,i,i+1,i,i+1});
        }
    }

    for(int i=1;i<=n;i++)
    {
        le[i]=i-1;
        ri[i]=i+1;
    }
    ri[n]=0;

    vector<int>deleted(n+2);//标记这个元素是否已经出去了
    vector<pair<int,int>>res;
    while(q.size())
    {
        auto t=q.top();q.pop();
        int diff=t.diff;
        int l=t.l,r=t.r;
        if(deleted[l]||deleted[r])continue;
    
        res.push_back({l,r});
        deleted[l]=deleted[r]=1;
        int ll=le[l],rr=ri[r];

        if(ll!=0)
        {
            ri[ll]=rr;
        }
        if(rr!=0)
        {
            le[rr]=ll;
        }

        if(ll&&rr)
        {
            if(s[ll]!=s[rr])
            {
                int diff=abs(a[ll]-a[rr]);
                q.push({diff,ll,rr,ll,rr});
            }
        }    
    }
    cout<<res.size()<<endl;
    for(auto t:res)
    {
        cout<<t.first<<" "<<t.second<<endl;
    }

    return 0;
}