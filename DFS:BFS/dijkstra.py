# 다익스트라 알고리즘 
# DP 와 비슷함 
# 최단거리는 여러 거리의 최단 거리로 이루어짐. 
# 가중치가 있음 

import heapq

def dijkstra(graph, start):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    priority_queue = [(0, start)]

    while priority_queue:
        current_distance, current_node = heapq.heappop(priority_queue)

        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

if __name__ == "__main__":
    graph = {
    'A': {'B': 1, 'C': 2},
    'B': {'A': 1, 'E': 2, 'D': 6},
    'C': {'A': 2, 'E': 3, 'F': 8},
    'D': {'B': 6, 'E': 1},
    'E': {'B': 2, 'C': 3, 'D': 1, 'F': 7},
    'F': {'C': 8, 'E': 7}
}

    print(dijkstra(graph, 'A'))