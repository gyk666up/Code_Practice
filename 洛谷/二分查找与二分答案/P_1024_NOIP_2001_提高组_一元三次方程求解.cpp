// //会写二分 但不知道如何从小到大用二分找到三个根
// #include<bits/stdc++.h>
// using namespace std;
// double a,b,c,d;
// map<double,bool>st;//判断这个根是否出现过 出现过的话 继续找
// bool check(double x)
// {
//     if(a*pow(x,3)+b*pow(x,2)+c*x+d<=0)
//     {
//         if(a*pow(x,3)+b*pow(x,2)+c*x+d==0)
//         {
//             if(!st.count(x))
//             { 
//                 st[x]=1;
//                 return 1;
               
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }
//     else return false;
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>a>>b>>c>>d;
//     bool first=1;
//     //三个二分查找
    
//     //取合适的精度就可以了 如何精度太高的话 可以会tle
//     for(int i=1;i<=3;i++)
//     {
//         double l=-101,r=101;
//         while(l+1!=r)
//         {
//             double mid=(l+r)/2;
//             if(check(mid))l=mid;
//             else r=mid;
//         }
//         if(first)
//         {
//             first=0;
//             cout<<l;
//         }
//         else
//         {
//             cout<<" "<<l;
//         }
        
//     }
//     return 0;
// }

// //这道题不熟 重点掌握！！！
// //暴力 枚举
// #include <iostream>
// #include <cstdio>
// using namespace std;
// int main()
// {
//    double a,b,c,d;
//    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
//    for(double i=-100;i<=100;i+=0.001)
//    {
//       double j=i+0.001;
//       double y1=a*i*i*i+b*i*i+c*i+d;
//       double y2=a*j*j*j+b*j*j+c*j+d;
//       if(y1>=0&&y2<=0||y1<=0&&y2>=0)
//       {
//          double x=(i+j)/2;
//          printf("%.2lf ",x);
//       }
//    }
// }

// //这个方案也好聪明啊 
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// 	double a,b,c,d;
// 	cin>>a>>b>>c>>d;
// 	for(double i=-100;i<=100;i+=0.00001){//注意精度
// 		if(abs((i*i*i*a)+(i*i*b)+(i*c)+d)<0.00001){//根据公式找到大概的值
// 			cout<<fixed<<setprecision(2)<<i<<" ";//保留两位小数输出
// 		}
// 	}
// 	return 0;
// }



// 2025.12.18 这道题掌握的不好 重点复习
//
// 不对
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// 	int a,b,c,d;cin>>a>>b>>c>>d;
// 	for(double i=-100;i<=100;i+=0.0001)
// 	{
// 		if(a*i*i*i+b*i*i+c*i+d<=0&&a*(i+1)*(i+1)*(i+1)+b*(i+1)*(i+1)+c*(i+1)+d>=0)
// 		{
// 			cout<<fixed<<setprecision(2)<<i<<" ";
// 			i+=1;
// 		}
// 	}
// 	return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// 	double a,b,c,d;cin>>a>>b>>c>>d;
// 	for(double i=-100;i<=100;i+=0.00001)
// 	{
// 		if(abs(a*i*i*i+b*i*i+c*i+d)<0.00001)
// 		{
// 			cout<<fixed<<setprecision(2)<<i<<" ";
// 		}
// 	}
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;
double a,b,c,d;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>a>>b>>c>>d;
    for(double i=-100;i<=100;i+=0.0001)
    {
        if(abs(a*i*i*i+b*i*i+c*i+d)<0.0001)
        {
            cout<<fixed<<setprecision(2)<<i<<" ";
        }
    }
    return 0;
}