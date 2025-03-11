# 크루스칼은 신장트리여야함.
# 모든 노드를 포함하면서 사이클이 존재하지 않아야함. 
# 1-2-3-4, 4-5, 4-6 이런 방식으로 
# 간선의 개수는 node - 1 임. 노드가 5개 일 때, 간선의 개수는 4개 

# 특정 원소가 속한 집합을 찾기
def find_parent(parent, x):
	# 루트 노드를 찾을 때까지 재귀 호출
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]
    
# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

if __name__ == "__main__":
    v, e = map(int, input().split())
    parent = [0] * (v+1)

    edges = []
    result = 0

    for i in range(1, v + 1):
        parent[i] = i
    
    for _ in range(e):
        a, b, cost = map(int, input().split())
        edges.append((cost, a, b))

    edges.sort()

    for edge in edges:
        cost, a, b = edge
        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            result += cost
        
    print(result)


# input
# 7 9
# 1 2 29
# 1 5 75
# 2 3 35
# 2 6 34
# 3 4 7
# 4 6 23
# 4 7 13
# 5 6 53
# 6 7 25