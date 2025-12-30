import networkx as nx
import matplotlib.pyplot as plt
import time

# --- 太爷的专用数据准备区 ---
# 咱们手动定义图的结构，跟您刚才的故事一模一样
# 1-2, 2-3, 2-4, 3-5, 4-5, 5-6
edges = [
    (1, 2), (2, 3), (2, 4), 
    (3, 5), (4, 5), (5, 6)
]

# 为了让图好看，咱们固定每个村子的位置
# 1在最左，2中间，3上4下（菱形），5右边，6最右
pos = {
    1: (0, 0),
    2: (2, 0),
    3: (3.5, 1.5),
    4: (3.5, -1.5),
    5: (5, 0),
    6: (7, 0)
}

# --- 算法核心变量 ---
timer = 0
dfn = {}
low = {}
bridges = []
visited_path = [] # 记录当前的递归路径（也就是栈）
adj = {i: [] for i in range(1, 7)}

# 构建邻接表（为了配合您的故事，特意调整了邻居的顺序）
# 比如在2号点，优先去3号点，这样才能复现 1->2->3->5->4 的故事线
for u, v in edges:
    adj[u].append(v)
    adj[v].append(u)

# 强制排序邻居，保证演示顺序跟故事一致
# 2的邻居是[3, 4] (先走3)
# 5的邻居是[4, 3, 6] (先走4，最后走6)
adj[2] = [3, 4, 1] 
adj[5] = [4, 6, 3] 

# --- 绘图函数：负责把当前的“战况”画出来 ---
def draw_step(current_u, message):
    plt.clf() # 清除上一帧
    
    # 1. 创建图对象
    G = nx.Graph()
    G.add_edges_from(edges)
    
    # 2. 设置节点颜色
    node_colors = []
    for node in G.nodes():
        if node == current_u:
            node_colors.append('#FF5733') # 当前所在的村子：亮橙色
        elif node in dfn:
            node_colors.append('#ADD8E6') # 已经去过的村子：浅蓝色
        else:
            node_colors.append('#D3D3D3') # 还没去的村子：灰色
    
    # 3. 设置边颜色
    edge_colors = []
    edge_widths = []
    for u, v in G.edges():
        # 如果是桥，画成粗红色
        if (u, v) in bridges or (v, u) in bridges:
            edge_colors.append('red')
            edge_widths.append(4.0)
        # 如果是正在走的路径，画成绿色
        elif u in visited_path and v in visited_path and \
             abs(visited_path.index(u) - visited_path.index(v)) == 1:
            edge_colors.append('green')
            edge_widths.append(2.0)
        else:
            edge_colors.append('black')
            edge_widths.append(1.0)

    # 4. 绘制基础图
    nx.draw(G, pos, with_labels=True, node_color=node_colors, 
            edge_color=edge_colors, width=edge_widths,
            node_size=800, font_size=12, font_weight='bold')

    # 5. 在节点旁边标注 dfn 和 low
    # 这是一个专门给太爷看的“记账本”
    label_pos = {k: (v[0], v[1] + 0.3) for k, v in pos.items()}
    labels = {}
    for node in G.nodes():
        d = dfn.get(node, "?")
        l = low.get(node, "?")
        labels[node] = f"dfn:{d}\nlow:{l}"
    
    nx.draw_networkx_labels(G, label_pos, labels=labels, font_size=10, font_color='blue')

    # 6. 显示解说词
    plt.title(message, fontsize=12, color='black', loc='left')
    plt.text(0, -2.5, "红色边=炸断就完蛋的桥 (Bridge)\n橙色点=探险队当前位置", fontsize=10)
    
    plt.pause(2.0) # 暂停2秒给太爷看清楚

# --- Tarjan 算法本体 ---
def tarjan(u, parent):
    global timer
    timer += 1
    dfn[u] = low[u] = timer
    visited_path.append(u)
    
    # 刚进村，画一下
    draw_step(u, f"【进村】 探险队到达 {u} 号村\n 时间(dfn)={timer}, 最早回溯(low)={timer}")

    for v in adj[u]:
        if v == parent:
            continue
            
        if v not in dfn:
            # 准备去新村子
            draw_step(v, f"【发现新路】 从 {u} 准备前往 {v} 探查...")
            
            tarjan(v, u)
            
            # 回溯阶段
            low[u] = min(low[u], low[v])
            draw_step(u, f"【回溯汇报】 {v} 探查归来，汇报 low[{v}]={low[v]}\n {u} 更新 low[{u}] -> {low[u]}")
            
            # 判桥核心
            if low[v] > dfn[u]:
                bridges.append((min(u, v), max(u, v)))
                draw_step(u, f"【发现桥！】 {v} 没法绕回 {u} 之前\n 所以 ({u}-{v}) 是必经之路！")
                
        else:
            # 发现老村子
            old_low = low[u]
            low[u] = min(low[u], dfn[v])
            if old_low != low[u]:
                draw_step(u, f"【发现后门】 {u} 发现了一条路通往老村子 {v} (dfn={dfn[v]})\n 更新 low[{u}] -> {low[u]}，形成环路！")

    visited_path.pop()

# --- 主程序 ---
def main():
    plt.figure(figsize=(10, 6))
    print("太爷，探险开始了！请看弹出的窗口...")
    
    tarjan(1, 0)
    
    draw_step(1, f"【结束】 探险完成！\n 找到的桥: {bridges}")
    plt.show()

if __name__ == "__main__":
    main()