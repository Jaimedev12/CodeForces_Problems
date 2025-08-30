import sys
from sys import stdin
sys.setrecursionlimit(1 << 25)

def main():
    input = sys.stdin.read().split()
    ptr = 0
    N = int(input[ptr])
    ptr += 1
    M = int(input[ptr])
    ptr += 1
    
    e = list(map(int, input[ptr:ptr+N]))
    ptr += N
    
    adj = [[] for _ in range(N)]
    for _ in range(M):
        u = int(input[ptr]) - 1
        ptr += 1
        v = int(input[ptr]) - 1
        ptr += 1
        adj[u].append(v)
        adj[v].append(u)
    
    """
    1
    1
    1
    1
    1
    """

    # Sort nodes in decreasing order of energy
    sorted_nodes = sorted(range(N), key=lambda x: -e[x])
    
    parent = list(range(N))
    size = [1] * N
    
    def find(u):
        while parent[u] != u:
            parent[u] = parent[parent[u]]
            u = parent[u]
        return u
    
    def union(u, v):
        u_root = find(u)
        v_root = find(v)
        if u_root == v_root:
            return
        if size[u_root] < size[v_root]:
            u_root, v_root = v_root, u_root
        parent[v_root] = u_root
        size[u_root] += size[v_root]
    
    processed = [False] * N
    for u in sorted_nodes:
        processed[u] = True
        for v in adj[u]:
            if e[v] <= e[u] and processed[v]:
                union(u, v)
    
    result = [size[find(u)] for u in range(N)]
    print('\n'.join(map(str, result)))

if __name__ == "__main__":
    main()