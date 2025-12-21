import matplotlib.pyplot as plt
import networkx as nx

def draw_rerooting_visualization():
    # Setup the graph
    # Node 0 is u, Node 1 is v
    # v (1) has a subtree: {1, 2, 3} -> size 3
    # u (0) has other branches: {0, 4, 5, 6} -> size 4
    # Total n = 7
    
    G = nx.Graph()
    edges = [
        (0, 1), # The edge between u and v
        (1, 2), (1, 3), # v's children
        (0, 4), (0, 5), # u's other children
        (5, 6)  # child of 5
    ]
    G.add_edges_from(edges)
    
    # Manual positions for clarity
    pos = {
        0: (0, 4),    # u (Top Center-ish)
        1: (2, 3),    # v (Right branch)
        2: (1.5, 2),  # v's child
        3: (2.5, 2),  # v's child
        4: (-1, 3),   # u's child (Left branch)
        5: (-2, 3),   # u's child (Left branch)
        6: (-2, 2)    # 5's child
    }
    
    # Define groups
    u = 0
    v = 1
    subtree_v_nodes = {1, 2, 3}
    other_nodes = {0, 4, 5, 6} # n - sz[v]
    
    # Calculate Distances for Root u
    path_lengths_u = nx.single_source_shortest_path_length(G, u)
    sum_dist_u = sum(path_lengths_u.values())
    
    # Calculate Distances for Root v
    path_lengths_v = nx.single_source_shortest_path_length(G, v)
    sum_dist_v = sum(path_lengths_v.values())
    
    sz_v = len(subtree_v_nodes)
    n = len(G.nodes)
    
    # Create plot
    fig, axes = plt.subplots(1, 2, figsize=(14, 6))
    
    # --- Plot 1: Root u ---
    ax = axes[0]
    ax.set_title(f"状态 1: 以 u (节点0) 为根\n总距离 = {sum_dist_u}", fontsize=14, fontweight='bold')
    
    # Draw edges with direction implied by root u
    # We use a BFS tree to determine edge direction for visualization
    bfs_tree_u = nx.bfs_tree(G, u)
    nx.draw_networkx_edges(G, pos, ax=ax, edge_color='gray', width=1.5)
    nx.draw_networkx_edges(bfs_tree_u, pos, ax=ax, edge_color='black', width=2, arrows=True, arrowstyle='-|>', arrowsize=20)
    
    # Draw nodes
    nx.draw_networkx_nodes(G, pos, nodelist=list(other_nodes), node_color='#FF9999', node_size=800, ax=ax, label="Rest of Tree") # Redish
    nx.draw_networkx_nodes(G, pos, nodelist=list(subtree_v_nodes), node_color='#99CCFF', node_size=800, ax=ax, label="Subtree of v") # Blueish
    nx.draw_networkx_labels(G, pos, font_color='black', font_weight='bold', ax=ax)
    
    # Annotate distances relative to u
    for node, (x, y) in pos.items():
        dist = path_lengths_u[node]
        ax.text(x, y-0.4, f"dist: {dist}", ha='center', fontsize=10, color='darkred')

    # Highlight the critical edge u->v
    mid_x_uv = (pos[0][0] + pos[1][0]) / 2
    mid_y_uv = (pos[0][1] + pos[1][1]) / 2
    ax.annotate("Root moves\nthis way", xy=(mid_x_uv, mid_y_uv), xytext=(mid_x_uv+0.5, mid_y_uv+0.5),
                arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10)


    # --- Plot 2: Root v ---
    ax = axes[1]
    expected_sum = sum_dist_u - sz_v + (n - sz_v)
    ax.set_title(f"状态 2: 以 v (节点1) 为根\n公式计算: {sum_dist_u} - {sz_v} + ({n}-{sz_v}) = {expected_sum}", fontsize=14, fontweight='bold')
    
    # Draw edges with direction implied by root v
    bfs_tree_v = nx.bfs_tree(G, v)
    nx.draw_networkx_edges(G, pos, ax=ax, edge_color='gray', width=1.5)
    nx.draw_networkx_edges(bfs_tree_v, pos, ax=ax, edge_color='black', width=2, arrows=True, arrowstyle='-|>', arrowsize=20)
    
    # Draw nodes (same colors to track groups)
    nx.draw_networkx_nodes(G, pos, nodelist=list(other_nodes), node_color='#FF9999', node_size=800, ax=ax)
    nx.draw_networkx_nodes(G, pos, nodelist=list(subtree_v_nodes), node_color='#99CCFF', node_size=800, ax=ax)
    nx.draw_networkx_labels(G, pos, font_color='black', font_weight='bold', ax=ax)
    
    # Annotate distances relative to v and change
    for node, (x, y) in pos.items():
        dist = path_lengths_v[node]
        old_dist = path_lengths_u[node]
        change = dist - old_dist
        change_str = f"{change:+d}"
        color = 'green' if change < 0 else 'red'
        ax.text(x, y-0.4, f"dist: {dist} ({change_str})", ha='center', fontsize=10, color=color, fontweight='bold')

    # Legend for groups
    import matplotlib.patches as mpatches
    blue_patch = mpatches.Patch(color='#99CCFF', label=f'v\'s Subtree (sz={sz_v})\nNodes closer to root (-1)')
    red_patch = mpatches.Patch(color='#FF9999', label=f'Rest of Tree (sz={n-sz_v})\nNodes further from root (+1)')
    ax.legend(handles=[blue_patch, red_patch], loc='lower left')

    plt.tight_layout()
    plt.save("rerooting_visualization.png")

draw_rerooting_visualization()