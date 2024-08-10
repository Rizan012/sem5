import numpy as np

def zero_one_knapsack(weights, values, capacity, n):
    # Initialize the DP matrix
    dp = np.zeros((n + 1, capacity + 1))
    
    # Fill the DP matrix
    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i] <= w:
                dp[i][w] = max(values[i] + dp[i - 1][w - weights[i]], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]
    
    return dp

# Driver Code
n = int(input("Enter number of items: "))
capacity = int(input("Enter capacity of knapsack: "))
weights = [0] * (n + 1)
values = [0] * (n + 1)

print("Enter weights:")
for i in range(1, n + 1):
    weights[i] = int(input(f"Weight of item {i}: "))

print("Enter values:")
for i in range(1, n + 1):
    values[i] = int(input(f"Value of item {i}: "))

dp_matrix = zero_one_knapsack(weights, values, capacity, n)

print("\nProfit Matrix:")
print(dp_matrix)

print(f"\nMaximum profit that can be earned: {int(dp_matrix[n][capacity])}")
