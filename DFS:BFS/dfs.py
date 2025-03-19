# 깊이 우선 탐색
# 최대한 깊이 내려간 다음에 갈 수 없을 때 옆으로 


# list method

# def dfs(graph, start_node):
#     need_visited, visited = list(), list()

#     need_visited.append(start_node)

#     while need_visited:
#         node = need_visited.pop()

#         if node not in visited:
#             visited.append(node)
#             need_visited.extend(graph[node])
        
#     return visited

# deque
def dfs(graph, start_node):
    from collections import deque

    need_visited = deque()
    visited = list()

    need_visited.append(start_node)

    while need_visited:
        node = need_visited.pop()

        if node not in visited:
            visited.append(node)
            need_visited.extend(graph[node])
    
    return visited


if __name__ == "__main__":
    graph = dict()
 
    graph['A'] = ['B', 'C']
    graph['B'] = ['A', 'D']
    graph['C'] = ['A', 'G', 'H', 'I']
    graph['D'] = ['B', 'E', 'F']
    graph['E'] = ['D']
    graph['F'] = ['D']
    graph['G'] = ['C']
    graph['H'] = ['C']
    graph['I'] = ['C', 'J']
    graph['J'] = ['I']

    print(dfs(graph, 'A'))

    