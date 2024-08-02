import random
import matplotlib.pyplot as plt

msteps = 0
qsteps = 0

def mergesort(a, l, r):
    global msteps
    if l < r:
        m = (l + r) // 2
        mergesort(a, l, m)
        mergesort(a, m + 1, r)
        merge(a, l, m, r)
        msteps += 5
    msteps += 1

def merge(a, l, m, r):
    global msteps
    i = k = l
    j = m + 1
    msteps += 2
    while i <= m and j <= r:
        if a[i] < a[j]:
            b[k] = a[i]
            i += 1
            k += 1
            msteps += 6
        else:
            b[k] = a[j]
            k += 1
            j += 1
            msteps += 6
    while i <= m:
        b[k] = a[i]
        k += 1
        i += 1
        msteps += 4
    while j <= r:
        b[k] = a[j]
        k += 1
        j += 1
        msteps += 4
    for i in range(l, r + 1):
        a[i] = b[i]
        msteps += 3
    msteps += 2

def quicksort(c, l, r):
    global qsteps
    if l < r:
        p = partition(c, l, r)
        quicksort(c, l, p - 1)
        quicksort(c, p + 1, r)
        qsteps += 4
    qsteps += 1

def partition(c, l, r):
    global qsteps
    pivot = c[l]
    x = l
    y = r
    qsteps += 3
    while x < y:
        while c[x] <= pivot:
            x += 1
            qsteps += 4
            if x > r:
                break
        while c[y] > pivot:
            y -= 1
            qsteps += 3
        if x < y:
            swap(c, x, y)
            qsteps += 2
        qsteps += 1
    swap(c, y, l)
    qsteps += 1
    return y

def swap(c, i, j):
    global qsteps
    temp = c[i]
    c[i] = c[j]
    c[j] = temp
    qsteps += 3

merge_steps = []
quick_steps = []

n = int(input("Enter the value of n: "))

for j in range(10):
    msteps = 0
    qsteps = 0
    
    a = [random.randint(0, n) for _ in range(n)]
    c = a[:]
    b = [None] * n

    mergesort(a, 0, n - 1)
    merge_steps.append(msteps)
    print(f"Merge sort Sorted: {a}")

    quicksort(c, 0, n - 1)
    quick_steps.append(qsteps)
    print(f"Quick sort Sorted: {c}")

print("Merge sort steps:", merge_steps)
print("Quick sort steps:", quick_steps)

plt.figure(figsize=(10, 5))
plt.plot(range(10), merge_steps, marker='o', label='Merge Sort Steps')
plt.plot(range(10), quick_steps, marker='o', label='Quick Sort Steps')
plt.xlabel('Trial')
plt.ylabel('Number of Steps')
plt.title('Merge Sort vs. Quick Sort Steps')
plt.legend()
plt.grid(True)
plt.show()
