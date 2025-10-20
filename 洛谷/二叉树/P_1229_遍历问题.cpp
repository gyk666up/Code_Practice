// 只有一个儿子 的节点 才会在知道 前序后序 的情况下有不同的中序遍历，所以将题目转化成找 只有一个儿子的节点个数。

// 可以很容易的找出这类节点在前序后序中出现的规律。（前序中出现AB，后序中出现BA，则这个节点只有一个儿子）

// 每个这类节点有两种中序遍历（及儿子在左，儿子在右）根据乘法原理中序遍历数为 2^节点个数 种

#include<bits/stdc++.h>
using namespace std;
const int N=1e3+11;
char s1[N],s2[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s1;
    cin>>s2;
    int ans=0;
    for(int i=0;i<strlen(s1);i++)
    {
        for(int j=1;j<strlen(s2);j++)
        {
            if(s1[i]==s2[j]&&s1[i+1]==s2[j-1])ans++;
        }
    }
    cout<<(1<<ans);
}