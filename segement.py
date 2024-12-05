A = []
ST = []

def build(node, L, R):
    global A, ST
    if (L == R):
        ST[node] = A[L]

    else:
        mid = (L+R) // 2
        build(2*node, L, mid)
        build(2*node+1, mid+1, R)

        ST[node] = ST[2*node] + ST[2*node+1] # ST[node] = OP(ST[2*node], ST[2*node+1])

def update(node, L, R, idx, val):
    global A, ST
    if (L == R):
        A[idx] += val
        ST[node] += val
    
    else:
        mid = (L+R) // 2
        if L<=idx and idx<=mid:
            update(2*node, L, mid, idx, val)
        else:
            update(2*node+1, mid+1, R, idx, val)
        
        ST[node] = ST[2*node] + ST[2*node+1] # ST[node] = OP(ST[2*node], ST[2*node+1])
    
def query(node, tl, tr, l, r):
    global ST, A

    # If it lies outside of range then
    # return 0
    if r < tl or tr < l:
        return 0
    
    # If the node contains the range then
    # return the node value
    if l <= tl and tr <= r:
        return ST[node]
    
    tm = (tl + tr) // 2

    # Recursively traverse left and right and find the node
    return query(2*node, tl, tm, l, r) + query(2*node+1, tm+1, tr, l, r)  # OP(query(l->m), query(m+1->r))

# Driver code
if __name__ == '__main__':
    n = 6
    A = [0, 1, 3, 5, -2, 3]
    # Create Segement Tree
    ST = [0 for _ in range(4*n)]

    build(1, 0, n-1)
    print("Sum of values in range 0->4 are : ", query(1, 0, n-1, 0, 4))

    update(1, 0, n-1, 1, 100)
    print("Updated sum of range is ", query(1, 0, n-1, 0, 4))
