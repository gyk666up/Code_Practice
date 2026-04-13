//重点看一下
//注意是如何巧妙的计算除 i 之外的其他项的乘积的
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
const int p=10007;
int a[N];//a[i],第i个对应的里面对应的常数
int pre[N];     // 前缀积
int suf[N];     // 后缀积
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    //提取出x 前面的数字 提取出 d
    //这道题简单，不用提x 前面的数字都是 1
    int num=s.size()/5;//一共有几项
    int idx=0;
    for(int i=2;i<s.size();)
    {
        int x=stoi(s.substr(i,2));
        a[++idx]=x;
        i+=5;
    }
    
    
    //选num-1项，并计算的乘积 卡到这里了 

    //$x^1$的系数 = (所有常数的乘积 / $c_1$) + (所有常数的乘积 / $c_2$) + ... + (所有常数的乘积 / $c_n$)
    //但在算法竞赛中，带取模的除法非常麻烦（需要算乘法逆元）
    
    //技巧
    //除了第 $i$ 个数以外，其他所有数的乘积”，其实就等于：
//第 $i$ 个数前面的所有数的乘积) $\times$ (第 $i$ 个数后面的所有数的乘积
    //除掉自己 = 自己的前缀积 $\times$ 自己的后缀积
    //我靠牛逼啊
    


    // 1. 预处理前缀积 (前 0 项乘积视为 1)
    pre[0] = 1;
    for(int i = 1; i <= num; i++) {
        // 注意：计算过程直接取模防溢出
        pre[i] = (pre[i - 1] * a[i]) % p;
    }
    
    // 2. 预处理后缀积 (第 num+1 项往后的乘积视为 1)
    suf[num + 1] = 1;
    for(int i = num; i >= 1; i--) {
        suf[i] = (suf[i + 1] * a[i]) % p;
    }
    
    // 3. 计算答案：累加 (前 i-1 项的乘积 * 后 i+1 项的乘积)
    int ans = 0;
    for(int i = 1; i <= num; i++)
    {
        int term = (pre[i - 1] * suf[i + 1]) % p;
        ans = (ans + term) % p;
    }
    
    // 4. 处理 C++ 中负数取模的终极奥义
    ans = (ans % p + p) % p;
    
    cout << ans << "\n";
    return 0;
}
