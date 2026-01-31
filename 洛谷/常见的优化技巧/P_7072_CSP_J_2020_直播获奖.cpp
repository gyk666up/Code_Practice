//一开始题目都没读懂
// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// const int N=1e5+66;
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];

//     return 0;
// }


//tl
// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// const int N=1e5+66;
// int a[N];
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     int now=1;
//     for(int p=1;p<=n;p++)
//     {
//         now=max(1,p*w/100);
//         cin>>a[p];
//         sort(a+1,a+p+1,greater<int>());
//         cout<<a[now]<<" ";
//     }
// }


// // //双根堆
// //双堆写法是“天然支持并列”的，不需要额外特判。题目根本不要求你维护「真实获奖人数」。
// //题目只要求分数线，并不需要把所有的人都放到队列中，👉 你只要保证「分数线 = 第 now 高的分数」即可
// #include<bits/stdc++.h>
// using namespace std;
// priority_queue<int>ma_heap;
// priority_queue<int,vector<int>,greater<int>>mi_heap;
// int n,w;
// int num;
// int now=1;
// void push(int x)
// {
//     if(mi_heap.empty()||x>=mi_heap.top())
//         mi_heap.push(x);
//     else
//         ma_heap.push(x);

//     //调整大小
//     while(mi_heap.size()>now)
//     {
//         ma_heap.push(mi_heap.top());
//         mi_heap.pop();
//     }

//     while(mi_heap.size()<now)
//     {
//         mi_heap.push(ma_heap.top());
//         ma_heap.pop();
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     //ma_heap.push(0);
//     for(int p=1;p<=n;p++)
//     {
//         now=max(1,p*w/100);//实时获奖人数
//         cin>>num;
//         push(num);
//         cout<<mi_heap.top()<<" ";
//     }
//     return 0;
// }


// #include <bits/stdc++.h>

// using namespace std;

// priority_queue<int> ma_hp;//大顶堆 
// priority_queue<int, vector<int>, greater<int> > mi_hp;//小顶堆 

// int n, w, now, num;

// void qwq()//调整获奖人数（小顶堆元素个数）
// {
// 	if (mi_hp.size()<now)
// 	{
// 		mi_hp.push(ma_hp.top());
// 		ma_hp.pop();
// 	} 
// 	if (mi_hp.size() > now)
// 	{
// 		ma_hp.push(mi_hp.top());
// 		mi_hp.pop();
// 	}
	
// } 

// void push(int num)
// {
// 	if (num >= ma_hp.top()) mi_hp.push(num);
// 		else ma_hp.push(num);
// 	qwq();
// }

// int main()
// {
// 	scanf("%d%d", &n, &w);
// 	ma_hp.push(0);//避免边界判断 
// 	for (int p = 1; p <= n; p++)
// 	{
// 		now=max(1,p*w/100);;//实时获奖人数 
// 		scanf("%d", &num);
// 		push(num);
// 		printf("%d ", mi_hp.top()); 
// 	}
// 	return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int n,w;
// priority_queue<int>ma_heap;
// priority_queue<int,vector<int>,greater<int>>mi_heap;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n>>w;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         int now=max(1,i*w/100);
//         if(mi_heap.empty()||x>=mi_heap.top())mi_heap.push(x);
//         else ma_heap.push(x);

//         if(mi_heap.size()<now)
//         {
//             mi_heap.push(ma_heap.top());
//             ma_heap.pop();
//         }
//         //else  不能写else =now 是符合条件的
//         if(mi_heap.size()>now)
//         {
//             ma_heap.push(mi_heap.top());
//             mi_heap.pop();
//         }

//         cout<<mi_heap.top()<<" ";
//     }
    
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int n,w;
priority_queue<int>ma_heap;
priority_queue<int,vector<int>,greater<int>>mi_heap;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        int now=max(1,i*w/100);

        if(mi_heap.empty()||mi_heap.top()<=x)mi_heap.push(x);
        else ma_heap.push(x);

        while(mi_heap.size()<now)
        {
            mi_heap.push(ma_heap.top());
            ma_heap.pop();
        }

        while(mi_heap.size()>now)
        {
            ma_heap.push(mi_heap.top());
            mi_heap.pop();
        }
        cout<<mi_heap.top()<<" ";
    }
    return 0;
}