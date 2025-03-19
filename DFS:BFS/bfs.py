# 너비 우선 탐색 
# 주로 두 노드 사이에서 최단 경로 알고 싶을 때


def bfs(graph, node):
    need_visited, visited = list(), list()

    need_visited.append(node)
    
    while need_visited:
        node = need_visited[0]
        del need_visited[0]

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

    print(bfs(graph, 'A'))