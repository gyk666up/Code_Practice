// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// string a,b;
// vector<int>add(vector<int>&A,vector<int>&B)
// {
//     vector<int>C;
//     int t=0;//进位
//     for(int i=0;i<A.size()||i<B.size();i++)
//     {
//         if(i<A.size())t+=A[i];
//         if(i<B.size())t+=B[i];
//         C.push_back(t%10);
//         t/=10;
//     }
//     if(t>0)C.push_back(t);//注意这里！！！可能还有进位
//     return C;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>a>>b;
//     vector<int>A,B;
//     for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
//     for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
//     vector<int>C=add(A,B);
//     for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// string a,b;
// vector<int>add(vector<int>&A,vector<int>&B)
// {
//     vector<int>C;
//     int t=0;
//     for(int i=0;i<A.size()||i<B.size();i++)
//     {
//         if(i<A.size())t+=A[i];
//         if(i<B.size())t+=B[i];
//         C.push_back(t%10);
//         t/=10;
//     }
//     if(t)C.push_back(t);
//     while(C.size()>1&&C.back()==0)C.pop_back();
//     return C;
// }
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>a>>b;
//     vector<int>A,B;
//     for(int i=a.size()-1;i>=0;i--)A.push_back(a[i]-'0');
//     for(int i=b.size()-1;i>=0;i--)B.push_back(b[i]-'0');
//     vector C=add(A,B);
//     for(int i=C.size()-1;i>=0;i--)cout<<C[i];
//     return 0;
// }

//2026/7/10 没毛病
#include<bits/stdc++.h>
using namespace std;
string A,B;
void add(string A,string B)
{
    vector<int>a,b;
    for(int i=A.size()-1;i>=0;i--)a.push_back(A[i]-'0');
    for(int i=B.size()-1;i>=0;i--)b.push_back(B[i]-'0');
    vector<int>c;
    int t=0;//进位
    for(int i=0;i<max(a.size(),b.size());i++)
    {
        //注意这里
        int d=t;
        //int d=a[i]+b[i]+t;
        if(i<a.size())d+=a[i];
        if(i<b.size())d+=b[i];
        c.push_back(d%10);
        t=d/10;
    }
    if(t>0)c.push_back(t);
    while(c.back()==0)c.pop_back();
    reverse(c.begin(),c.end());
    for(int i=0;i<c.size();i++)
    {
        cout<<c[i];
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>A>>B;
    add(A,B);
    
    return  0;
}