// // #include<bits/stdc++.h>
// // using namespace std;
// // #define int long long
// // signed main()
// // {
// //     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// //     //cout<<(int)'a';
// //     //相当于26进制 a（97-96）
// //     // string s;cin>>s;
// //     // int ans=0;
// //     // for(int i=0;i<s.size();i++)
// //     // {
// //     //     ans=ans*26+s[i]-96;
// //     // }
// //     // cout<<ans;
// //     return 0;
// // }



// // 本题的核心是 **“组合数的累加计数”**：
// // 长度为k的升序单词，本质是从 26 个字母中选k个的组合（因为选出来的字母按升序排列只有一种方式）。
// // 字典序的位置 = 所有更短长度的组合数总和 + 当前长度下比该单词小的组合数总和 + 1（自身的位置）。
// #include<bits/stdc++.h>
// using namespace std;
// //优化版 利用数学公式先简化再写而不是直接用阶乘
// int C(int n,int k)
// {
//     if(k==0||k==n)return 1;
//     if(k>n)return 0;
//     if(k>n-k)k=n-k;//优化，选较小的k
//     long long res=1;
//     for(int i=1;i<=k;i++)
//     {
//         res=res*(n-k+i)/i;//利用数学梯度公式化简
//     }
//     return res;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string s;cin>>s;
//     int len=s.size();

//     //检测是否升序
//     for(int i=1;i<len;i++)
//     {
//         if(s[i]<=s[i-1])
//         {
//             cout<<0<<endl;
//             return 0;
//         }
//     }


//     //计算所有更短长度的组合数之和（sum1）
//     int sum1=0;
//     for(int k=1;k<len;k++)
//     {
//         sum1+=C(26,k);
//     }

//     //计算当前长度下，比该单词更小的组合数之(sum2) 这段代码好好理解一下
//     //字母是严格升序的，也就是说不存在adc这种情况
//     int sum2=0;
//     int prev=-1;

//     for(int i=0;i<len;i++)
//     {
//         int curr=s[i]-'a';//将字母转为0-25的数字
//         //0到i位置上的字母都已经选好了
//         //从prev+1到curr-1选（len-（i+1））个字母

//。        注意这一行的代码
//         for(int c=prev+1;c<curr;c++)
//         {
//             sum2+=C(26-c-1,len-1-i);
//         }
//         prev=curr;
//     }
//     cout<<sum1+sum2+1<<endl;
//     return 0;
// }





#include<bits/stdc++.h>
using namespace std;
int C(int n,int m)
{
    if(n==m||m==0)return 1;
    else if(n<m)return 0;

    long long res=1;
    for(int i=1;i<=m;i++)
    res=res*(n-m+i)/i;
    return res;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    int len=s.size();
    for(int i=1;i<len;i++)
    {
        if(s[i]<=s[i-1])
        {
            cout<<"0";
            return 0;
        }
    }

    //选长度比它短短
    int sum1=0;
    for(int i=1;i<len;i++)
    {
        sum1+=C(26,i);
    }

    //长度一样长的
    int sum2=0;
    int prev=-1;
    for(int i=0;i<len;i++)
    {
        int curr=s[i]-'a'; //（0～25）
        //当前字母是j 后面还有25-（j-1）+1（得比j大）
        //总共选len个字母 已经选了 i+1个还有len-i-1
        for(int j=prev+1;j<curr;j++)
        {
            sum2+=C(26-j-1,len-1-i);
        }
        prev=curr;//!!!
    }
    cout<<sum1+sum2+1<<endl;
    return 0;
}






















