import numpy as np

def MatrixChain(p):
    n = len(p)
    m = np.zeros((n, n))
    s = np.zeros((n, n), dtype=int)

    for l in range(2, n):
        for i in range(1, n - l + 1):
            j = i + l - 1
            m[i][j] = float('inf')
            for k in range(i, j):
                cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]
                if cost < m[i][j]:
                    m[i][j] = cost
                    s[i][j] = k
    
    return m, s

# Driver Code
n = int(input("Enter the number of matrices: "))
p = [int(input(f"Enter dimension {i + 1}: ")) for i in range(n + 1)]

m, s = MatrixChain(p)

print("\nMatrix M (Minimum number of multiplications):")
print(m[1:n, 1:n])

print("\nMatrix S (Split points for optimal multiplication):")
print(s[1:n, 1:n])

print(f"\nMinimum number of multiplications required: {int(m[1][n - 1])}")
