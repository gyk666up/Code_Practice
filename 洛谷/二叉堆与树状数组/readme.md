___
遇到小根堆就用priority_queue<int,vector<int>,greater<int>>q;


工具	对a < b的解读	目标	实现 “小值优先” 的逻辑
sort	a排在b前面（升序）	排序整个序列	return a < b（小值在前）
priority_queue	b优先级比a高（大顶堆）	维护堆顶的最高优先级	return a > b（小值优先）

![alt text](image.png)