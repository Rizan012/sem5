def job_sequencing(jobs, deadlines, profits, n):
    schedule = [0] * (max(deadlines) + 1)
    
    for i in range(n):
        deadline = deadlines[i]
        for k in range(deadline, 0, -1):
            if schedule[k] == 0:
                schedule[k] = jobs[i]
                break
    
    return schedule[1:]

# Driver code
n = int(input("Enter the number of jobs: "))
jobs = list(range(1, n + 1))
deadlines = [int(input(f"Enter deadline for Job {i+1}: ")) for i in range(n)]
profits = [int(input(f"Enter profit for Job {i+1}: ")) for i in range(n)]

# Sorting jobs by profit in descending order
jobs, deadlines, profits = zip(*sorted(zip(jobs, deadlines, profits), key=lambda x: x[2], reverse=True))

print("\nJobs after sorting by profit:")
print(f"Jobs: {jobs}")
print(f"Deadlines: {deadlines}")
print(f"Profits: {profits}")

scheduled_jobs = job_sequencing(jobs, deadlines, profits, n)
print("\nScheduled Jobs:", scheduled_jobs)

# Profit Calculation
total_profit = sum(profits[i-1] for i in scheduled_jobs if i != 0)
print(f"Total Profit: {total_profit}")
