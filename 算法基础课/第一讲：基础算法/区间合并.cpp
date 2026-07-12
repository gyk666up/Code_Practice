// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// typedef pair<int,int> PII;
// int n;
// vector<PII> segs;

// void merge(vector<PII> &regs){
//     vector<PII> res;
//     sort(regs.begin(),regs.end());
    
//     int st=-2e9,ed=-2e9;
//     for(auto reg:regs){
//         if(ed<reg.first){//说明两段之间没有重合的区间
//             if(st!=-2e9) res.push_back({st,ed});
//             //一个新段
//             st=reg.first;
//             ed=reg.second;
//         }else{
//             ed=max(ed,reg.second);
//         }    
//     }
    
//     if(st!=-2e9) res.push_back({st,ed});
//     regs=res;
// }

// int main(){
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int l,r;
//         cin>>l>>r;
//         segs.push_back({l,r});
//     }
    
//     merge(segs);
//     cout<<segs.size()<<endl;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// typedef pair<int,int>PII;
// vector<PII>segs;
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int l,r;cin>>l>>r;
//         segs.push_back({l,r});
//     }
//     sort(segs.begin(),segs.end());
//     int st=-0x3f3f3f3f,ed=-0x3f3f3f3f;
//     vector<PII>res;
//     for(auto it:segs)
//     {
//         if(ed<it.first)
//         {
//             if(st!=-0x3f3f3f3f)res.push_back({st,ed});
//             st=it.first;
//             ed=it.second;
//         }
//         else
//         {
//             ed=max(ed,it.second);
//         }
//     }
//     if(st!=-0x3f3f3f3f)res.push_back({st,ed});//存最后一段
//     cout<<res.size();
    
//     return 0;
// }

//再熟悉一下上面的算法
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+11;
int n;
struct node
{
    int l,r;
    bool operator<(const node&u)
    {
        return l<u.l;
    }
}range[N];
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>range[i].l>>range[i].r;
    }
    sort(range+1,range+1+n);
    int ed=-2e9;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(ed>=range[i].l)//有交点
        {
            ed=max(ed,range[i].r);
        }
        else
        {
            res++;ed=range[i].r;
        }
    }
    cout<<res;
    return 0;   
}