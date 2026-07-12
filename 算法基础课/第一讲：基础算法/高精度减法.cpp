// //这个只考虑两个非负整数相减，其他的情况可以在这个基础上改
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// bool cmp(vector<int>A,vector<int>B)
// {
//     if(A.size()!=B.size())return A.size()>B.size();
//     else
//     {
//         //位数一样，从高位判断
//         for(int i=A.size()-1;i>=0;i--)
//         {
//             if(A[i]!=B[i])
//             return A[i]>B[i];
//         }
//     }
//     //所有数字都相等
//     return true;
// }
// vector<int>sub(vector<int>A,vector<int>B)
// {
//     vector<int>C;
//     int t=0;//0 代表没有借位，1 代表有借位(当前位)
//     for(int i=0;i<A.size();i++)
//     {
//         t=A[i]-t;//t 用的很妙
//         if(i<B.size())t-=B[i];

//         C.push_back((t+10)%10);// if t>=0 A[i]-B[i]-t >0 说明这一位不用接位（t），else   需要借位（t+10） 两个可以共同表示为(t+10)%10
//         if(t<0)t=1;//当前位
//         else t=0;
//     }
//     //删去前导 0
//     while(C.size()>1&&C.back()==0)C.pop_back();
//     return C;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     string a,b;cin>>a>>b;
//     vector<int>A,B;
//     for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
//     for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');

//     vector<int>C;
//     if(cmp(A,B))//得判断A 是否大于等于 B
//     {
//         C=sub(A,B);
//         for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     }
//     else
//     {
//         C=sub(B,A);
//         cout<<"-";
//         for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// bool cmp(string a,string b)
// {
//     if(a.size()!=b.size())return a.size()>b.size();

//     for(int i=0;i<a.size();i++)
//     {
//         if(a[i]!=b[i])return a[i]>b[i];
//     }
//     return true;
// }
// vector<int>sub(vector<int>&A,vector<int>&B)
// {
//     vector<int>C;
//     int t=0;//1 代表有借位
//     for(int i=0;i<A.size();i++)
//     {
//         t=A[i]-t;
//         if(i<B.size())t-=B[i];

//         C.push_back((t+10)%10);//借和不借位合并了
//         if(t<0)t=1;//
//         else t=0;
//     }
//     while(C.size()>1&&C.back()==0)C.pop_back();
//     return C;
// }
// int main()
// {
//     string a,b;cin>>a>>b;
//     vector<int>A,B;
//     for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
//     for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
//     vector<int>C;
//     //判断是否a>b
//     if(cmp(a,b))
//     {
//         C=sub(A,B);
//         for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     }
//     else 
//     {
//         C=sub(B,A);
//         cout<<"-";
//         for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// string A,B;
// vector<int>c;
// //判断是不是 A 》=B
// bool isA()
// {
//     if(A.size()>B.size())return true;
//     else if(A.size()<B.size())return false;//这行代码刚开始也没写
//     for(int i=0;i<A.size();i++)
//     {
//         if(A[i]==B[i])continue;
//         return A[i]>B[i];
//     }
//     return true;//这行代码容易忘
// }
// void sub(string A,string B)
// {
//     vector<int>a,b;
//     for(int i=A.size()-1;i>=0;i--)a.push_back(A[i]-'0');
//     for(int i=B.size()-1;i>=0;i--)b.push_back(B[i]-'0');
    
//     int t=0;//看是否借位 t=1 结尾
//     //注意这个逻辑
//     for(int i=0;i<a.size();i++)
//     {
//         t=a[i]-t;
//         if(i<b.size())
//         {
//             t-=b[i];
//         }
//         c.push_back((t+10)%10);//这个很聪明
//         if(t<0)t=1;
//         else t=0;
//     }
//     while(c.size()>1&&c.back()==0)c.pop_back();
   
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>A>>B;
//     if(isA())sub(A,B);
//     else {
//         sub(B,A);
//         cout<<"-";
//     }
//     reverse(c.begin(),c.end());
//     for(int i=0;i<c.size();i++)cout<<c[i];
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
bool cmp(string A,string B)
{
    if(A.size()>B.size())return true;
    if(A.size()<B.size())return false;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==B[i])continue;
        return A[i]>B[i];
    }
    //全相等
    return true;
}
void sub(string A,string B)
{
    vector<int>a,b;
    for(int i=A.size()-1;i>=0;i--)a.push_back(A[i]-'0');
    for(int i=B.size()-1;i>=0;i--)b.push_back(B[i]-'0');
    vector<int>c;
    int t=0;//是否借位
    for(int i=0;i<a.size();i++)
    {
        t=a[i]-t;
        if(i<b.size())
        {
            t-=b[i];
        }
        c.push_back((t+10)%10);
        if(t<0)t=1;
        else t=0;
    }
    while(c.size()>1&&c.back()==0)c.pop_back();
    reverse(c.begin(),c.end());
    for(int i=0;i<c.size();i++)cout<<c[i];
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    string A,B;cin>>A>>B;
    if(cmp(A,B))
    {
        sub(A,B);
    }
    else 
    {
        cout<<"-";
        sub(B,A);
    }
    
    return 0;
}