# m, n = map(int, input().split())
# d = n - m  # 计算蜂房距离
# a, b = 1, 1  # 初始化斐波那契的前两项（f(1)=1, f(2)=1）
# # for _ in range(d - 1):  # 递推 d-1 次得到第 d+1 项
# #     a, b = b, a + b
# # print(b)

# for i in range(2,n-m+1):
#     c=a+b
#     a=b
#     b=c
# print(b)



m,n=map(int,input().split())
d=n-m
a,b=1,1
for i in range(d-1):
    a,b=b,a+b
print(b)