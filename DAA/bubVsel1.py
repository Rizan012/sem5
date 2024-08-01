import random
import matplotlib.pyplot as plt

def bubblesort(a):
    steps = 0
    n = len(a)
    for i in range(n):
        for j in range(n - i - 1):
            steps += 1  # Comparison step
            if a[j] > a[j + 1]:
                a[j], a[j + 1] = a[j + 1], a[j]
                steps += 3  # 1 step for each swap (total of 3 steps for the swap)
    return steps

def selectionsort(b):
    steps = 0
    n = len(b)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            steps += 1  # Comparison step
            if b[j] < b[min_index]:
                min_index = j
                steps += 1  # Assignment step for new minimum
        if min_index != i:
            b[i], b[min_index] = b[min_index], b[i]
            steps += 3  # 1 step for each swap (total of 3 steps for the swap)
    return steps

# Initialize arrays for recording steps
bubble_steps = []
selection_steps = []

# Input size
n = int(input("Enter the value of n: "))

# Generate and sort arrays
for j in range(10):
    # Initialize new lists for each iteration
    a = [random.randint(0, n) for _ in range(n)]
    b = a[:]

    # Perform bubble sort and record steps
    bsteps = bubblesort(a)
    bubble_steps.append(bsteps)
    print(f"Bubble sort Sorted: {a}")

    # Perform selection sort and record steps
    ssteps = selectionsort(b)
    selection_steps.append(ssteps)
    print(f"Selection sort Sorted: {b}")

# Print steps for both sorting algorithms
print("Bubble sort steps:", bubble_steps)
print("Selection sort steps:", selection_steps)

# Plot the results
plt.figure(figsize=(10, 5))
plt.plot(range(10), bubble_steps, marker='o', label='Bubble Sort Steps')
plt.plot(range(10), selection_steps, marker='o', label='Selection Sort Steps')
plt.xlabel('Trial')
plt.ylabel('Number of Steps')
plt.title('Bubble Sort vs. Selection Sort Steps')
plt.legend()
plt.grid(True)
plt.show()
