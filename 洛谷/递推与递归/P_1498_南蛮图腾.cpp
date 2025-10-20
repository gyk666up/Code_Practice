#include<bits/stdc++.h>
using namespace std;
char a[3000][3000];
int h=2,w=4;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //思路：先构成最原始的图形 然后向下向右平移
    //最后向上平移
    int n;cin>>n;

    //还要注意一点，整个矩阵要预先赋值成空格，否则是NULL，
    //这两个在本地输出显示是一样的，但在洛谷上会判错，
    memset(a,' ',sizeof(a));
    a[1][1]=a[1][4]=' ';
    a[1][2]=a[2][1]='/';
    a[1][3]=a[2][4]='\\'; //两个\\才表示\ 一个是转义字符
    a[2][2]=a[2][3]='_';
    for(int i=0;i<n-1;i++)
    {
        //向右向下
        for(int j=1;j<=h;j++)
        {
            for(int k=1;k<=w;k++)
            {
                a[j+h][k]=a[j+h][k+w]=a[j][k];
                //注意还要把原来的删到
                a[j][k]=' ';
            }
        }

        //左下的移动到右上（中间）
        for(int j=1;j<=h;j++)
        {
            for(int k=1;k<=w;k++)
            {
                a[j][k+w/2]=a[j+h][k];
            }
        }
        w*=2,h*=2;
    }
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}