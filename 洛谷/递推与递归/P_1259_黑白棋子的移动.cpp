//！！！注意观察 了解移动背后的规律
//

#include <bits/stdc++.h>
using namespace std;
const int N=203;
char ch[N];

int n;
void output()
{
    for(int i=0;i<2*n+2;i++)
    cout<<ch[i];
    cout<<endl;
}
void move(int start,int end)
{
    swap(ch[start],ch[end]);

    swap(ch[start+1],ch[end+1]);
    output();
}
int main() {
    cin>>n;
    int len=n;
    for(int i=0;i<len;i++)ch[i]='o';
    for(int i=len;i<2*len;i++)ch[i]='*';
    
    ch[2*len]='-';
    ch[2*len+1]='-';
    output();
    while(1)
    {
        //移动中间的两个棋子 到最右边的空白
        move(len-1,2*len);
        len--;
        if(len==3)
        break;
        //移动最右边的两个*与--交换位置
        move(len,2*len);
    }
    //最后的几个规律难看出来 利用打表
    string st[4]={"ooo*o**--*","o--*o**oo*","o*o*o*--o*","--o*o*o*o*"};
    string ss="";
    for(int i=0;i<n-4;i++)
    ss+="o*";
    //这里最后固定是4行！！！
    for(int i=0;i<4;i++)
    cout<<st[i]<<ss<<endl;
    return 0;
}