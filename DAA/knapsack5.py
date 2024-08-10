def fractionalknapsack(w, v, W, n):
    s = [0] * n
    tempw = W

    for i in range(n):
        if w[i] <= tempw:
            s[i] = 1
            tempw -= w[i]
        else:
            s[i] = tempw / w[i]
            break

    return s

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

# Driver code
w = []
v = []

n = int(input("Enter the number of items: "))
W = int(input("Enter the capacity of the knapsack: "))

print("Enter item weights:")
w = [int(input(f"Weight of item {i + 1}: ")) for i in range(n)]

print("Enter item values:")
v = [int(input(f"Value of item {i + 1}: ")) for i in range(n)]

# Calculate value-to-weight ratio
ratio = [v[i] / w[i] for i in range(n)]

# Sort items by value-to-weight ratio in descending order
for i in range(n - 1):
    for j in range(n - 1 - i):
        if ratio[j] < ratio[j + 1]:
            swap(ratio, j, j + 1)
            swap(v, j, j + 1)
            swap(w, j, j + 1)

print("\nAfter Sorting (by value/weight ratio):")
print(f"Ratios: {ratio}")
print(f"Values: {v}")
print(f"Weights: {w}")

# Find solution using the fractional knapsack approach
s = fractionalknapsack(w, v, W, n)
profit = sum(s[i] * v[i] for i in range(n))

print("\nFractional solution:", s)
print(f"Maximum profit: {profit:.2f}")
