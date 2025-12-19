#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int>score(n);
        for(int i=0;i<n;i++)
        {
            int x,y;cin>>x>>y;
            if(x==1&&y==0)socre[i]=3;
            else if(x==1&&y==1||x==0&&y==0)score[i]=2;
            else score[i]=1;
        }

        vector<int>(n);
        for(int i=0;i<n;i++)
        {
            int idx;cin>>idx;
            //将排名转化成分数 排名的下标是从1开始的
            order[i]=score[idx-1];
        }
        //寻找最长非上升子序列
        vector<int>dp;
        for(int i=0;i<n;i++)
        {
            auto it=upper_bound(dp.begin(),dp.end(),s,greater<int>)//找第一个<=s的元素
            if(it==dp.end)//没找到 那么就说明前面的都比它大 因此可以直接放到末尾
            dp.push_back(*it);
            else{// 5 3 s=4 那末就将4替换成3 前面的数字越大最长非上升子序列的可能长度就越大
                s=*it;
            }
        }
        cout<<n-dp.size()<<endl;
    }
    return 0;
}