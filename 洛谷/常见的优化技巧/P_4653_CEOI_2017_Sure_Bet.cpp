//题都没读懂

// 你什么时候赚钱？
// 只有你选过、并且被点亮的灯泡
// 才会给你收益（等于它的权值）

// 假设你已经决定了一种选择方案。
// 记：
// SA = 你选的 A 权值和
// SB = 你选的 B 权值和
// k = 你选的灯泡总数
// 你关心的是：
// 收益 = min(
//     ∑Ai(选A) - |S|,
//     ∑Bi(选B) - |S|
// )
//每一组中选择一个
//既然 $S_A$ 已经遥遥领先了，再选 A 只能增加成本，对“提升最小值”毫无帮助。我们应该只选 B（只让 j++），直到 $S_B$ 追上来，或者成本增加到让收益不再增长为止。


//先跳过吧 还是没理解
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
double a[N], b[N];

bool cmp(double a, double b){return a > b;}//降序

int main(){
    int n;
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i] >> b[i];
    }
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    //a[i]：选权值最大的 i 个 A 灯泡时，A 的总收益
    for (int i=1; i<=n; i++) a[i]+=a[i-1], b[i]+=b[i-1];
    double ans = 0;
    int i=1, j=1;
    while (i<=n && j<=n){
        if(a[i] > b[j]){
            ans = max(ans, b[j]-i-j);
            j++;
        }else{
            ans = max(ans, a[i]-i-j);
            i++;
        }
    }
    printf("%.4lf", ans); 
    return 0;
}
