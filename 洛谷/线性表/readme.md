2025/9/15-2025/9/18

## 二维动态数组 （不熟）

希望创建一个包含 N 个 vector<int> 的数组，且每个 vector 初始化为大小 N+1、元素全为 0，可以这样做：
### 第一种
#include <vector>
using namespace std;
const int N = 5; // 必须是常量表达式
vector<int> v[N];

int main() {
    // 循环初始化每个vector
    for (int i = 0; i < N; ++i) {
        v[i].resize(N + 1, 0); // 调整大小并初始化元素为0
    }
    return 0;
}

### 第二种
#include <vector>
using namespace std;

int main() {
    int N = 5; // 可以是变量
    // 创建一个包含N个vector的vector，每个子vector大小为N+1，元素为0
    vector<vector<int>> v(N, vector<int>(N + 1, 0));
    return 0;
}

## 双端队列不熟练[text](../../P_1996_约瑟夫问题.cpp)

## 链表极其不熟练
队列安排这道题需重点掌握一下

双向链表的删除操作需要考虑三种情况：
删除中间节点：同时调整前驱的 right 和后继的 left；
删除头节点：除了调整后继的 left，还需要更新头节点标识；
删除尾节点：只需要调整前驱的 right（无需处理后继，因为后继为 NULL）

验证栈的序列这道题也不熟！！！记住能够得到 所有出栈可能的情况的代码


总结：感觉这章的题并不难但真正完整做下来的题目很少