// #include<bits/stdc++.h>
// using namespace std;
// #define int long long 
// const int N=1e5+11;
// int a[N];
// signed main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)cin>>a[i];
//     int ans=0;
//     for(int i=1;i<=n;i++)
//     {
//         ans+=a[i];
//         if(i%2==1)
//         cout<<a[(1+i)/2]<<endl;
//     }
//     return 0;
// }


// //刚开始理解错题目的意思了 题目的意思是奇数数列的中位数，并不一定在中间，因为没按照顺序排
//用这种数据结构并不能得到结果
// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+11;
// int tre[N];
// int id=1;
// void up(int x)
// {
//     if(x==1)return;
//     if(tre[x]<tre[x/2])
//     {
//         swap(tre[x],tre[x/2]);
//         up(x/2);
//     }
// }
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     int n;cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         tre[id]=x;
//         up(id);
//         id++;
//         if(i%2==1)
//         {
//             cout<<tre[(i+1)/2]<<endl;
//         }
//     }
    
//     return 0;
// }



// 双堆法的本质是把所有已输入的元素，分成「左半部分」和「右半部分」：
// 大根堆（max_heap）：专门存「左半部分的元素」—— 这些元素是所有元素里较小的一半。
// 大根堆的堆顶是「左半部分最大的元素」（因为大根堆的特性是 “顶最大”）。
// 小根堆（min_heap）：专门存「右半部分的元素」—— 这些元素是所有元素里较大的一半。
// 小根堆的堆顶是「右半部分最小的元素」（因为小根堆的特性是 “顶最小”）。
// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     priority_queue<int> max_heap;                  // 大顶堆（左半部分，默认是大顶堆）
//     priority_queue<int, vector<int>, greater<int>> min_heap;  // 小顶堆（右半部分）
//     int n; cin >> n;
//     for (int i = 1; i <= n; ++i) {
//         int x; cin >> x;
//         // 先插入大顶堆
//         max_heap.push(x);
//         // 平衡两个堆的大小（大顶堆最多比小顶堆多1个元素）
//         if (max_heap.size() > min_heap.size() + 1) {
//             min_heap.push(max_heap.top());
//             max_heap.pop();
//         }
//         // 保证大顶堆顶 ≤ 小顶堆顶（左半部分 ≤ 右半部分）
//         if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
//             int a = max_heap.top(), b = min_heap.top();
//             max_heap.pop(), min_heap.pop();
//             max_heap.push(b), min_heap.push(a);
//         }
//         // 奇数个元素时，输出大顶堆顶（中位数）
//         if (i % 2 == 1) {
//             cout << max_heap.top() << endl;
//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;
// int n;
// int main()
// {
//     ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//     cin>>n;
//     priority_queue<int>left_heap;
//     priority_queue<int,vector<int>,greater<int>>right_heap;
//     for(int i=1;i<=n;i++)
//     {
//         int x;cin>>x;
//         left_heap.push(x);

//         if(left_heap.size()>right_heap.size()+1)
//         {
//             right_heap.push(left_heap.top());
//             left_heap.pop();
//         }
//         //要保证右根堆不为空 否则会报错 左根堆不会空的
//         //保证左根堆的堆顶《=右根堆的堆顶
//         if(!right_heap.empty()&&left_heap.top()>right_heap.top())
//         {
//             int a=left_heap.top();int b=right_heap.top();
//             left_heap.pop();right_heap.pop();
//             left_heap.push(b);
//             right_heap.push(a);
//         }
//         if(i%2==1)
//         cout<<left_heap.top()<<endl;
//     }
//     return 0;
// }

