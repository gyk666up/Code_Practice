// //还是不会做
// //第一种方法
// // #include <bits/stdc++.h>
// // using namespace std;
// // long long x,y,z,a,b,ans;
// // int main() {
// // 	cin>>x>>y;
// // 	while(x!=0&&y!=0){
// // 		z=min(x,y);	//切一个边长为min(x,y)的正方形。
// // 		ans+=4*z;
// // 		if(x==z)y-=z;
// // 		else if(y==z)x-=z;	//小的边减去边长。
// // 	}
// // 	printf("%d\n",ans);
// // 	return 0;
// // }
// //优化版
// #include<bits/stdc++.h>
// using namespace std;
// long long x,y,z,ans;
// int main() {
// 	cin>>x>>y;
// 	while(x!=0&&y!=0){
// 		z=min(x,y);
// 		if(x==z)ans+=4*(y/z)*z,y%=z;
// 		else if(y==z)ans+=4*(x/z)*z,x%=z;
//       		//一次性切下max(x,y)/min(x,y)个。
//       		//不要忘了答案也要加max(x,y)/min(x,y)次！！！
// 	}
// 	printf("%lld\n",ans);
// 	return 0;
// }


//最后的一个点t了
// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int x,y,ans;
// signed main()
// {
// 	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// 	cin>>x>>y;
// 	while(x&&y)
// 	{
// 		int z=min(x,y);
// 		if(x==z)
// 		{
// 			ans+=4*z;
// 			y-=z;
// 		}
// 		else if(y==z)
// 		{
// 			ans+=4*z;
// 			x-=z;
// 		}
// 	}
// 	cout<<ans;
// 	return 0;
// }


