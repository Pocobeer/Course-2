import numbers
import random
#import matplotlib.pyplot as plt
#import numpy as np
#plt.style.use('_mpl-gallery')
n = int(input("Enter the total number of numbers n: "))
m = int(input("Enter the number of histogram intervals m: "))

# Create lists to store histogram parameters xi and P(xi)
xi = [10.3, 12.171, 14.043, 15.914, 17.786, 19.657, 21.529, 23.4]
Px = [0.2, 0.02, 0.2, 0.18, 0.26, 0.04, 0.1]
ki = []
# Input values of xi and P(xi) for each histogram interval
#for i in range(m):
#    x = float(input(f"Enter the value of xi for interval {i+1}: "))
#    p = float(input(f"Enter the value of P(xi) for interval {i+1}: "))
#    xi.append(x)
#    Px.append(p)

#x=[10.3, 12.171, 14.043, 15.914, 17.786, 19.657, 21.529, 23.4]
#y = [0.2, 0.02, 0.2, 0.18, 0.26, 0.04, 0.1]
#if len(x) > len(y):
#    x = x[:-1]
#fig, ax = plt.subplots()
#ax.bar(x, y, width=1, edgecolor="white", linewidth=0.7)

#ax.set(xlim=(0, 8), xticks=np.arange(1, 8),
 #      ylim=(0, 8), yticks=np.arange(1, 8))

#plt.show()50
for i in range(0,m):
    k = int(n*Px[i])
    ki.append(k)

print("Total number of numbers n:", n)
print("Number of histogram intervals m:", m)
print("Histogram parameters xi:", xi)
print("Histogram parameters P(xi):", Px)
print("Values of ki:", ki)
l=0
A_l = [None]*n
def RND():
    return random.random()
for i in range(0, m):
    for j in range(0, ki[i]):
        random_value = RND()
        a = xi[i] + random_value * (xi[i+1] - xi[i])
        round_a = round(a, 2)
        A_l[l] = round_a
        l += 1



for i in range(1,l):
    rand_val = RND()
    p_1=rand_val*(n-1)+1
    p_2=rand_val*(n-1)+1
    if p_1 != p_2:
        b = A_l[p_1]
        A_l[p_1]=A_l[p_2]
        A_l[p_2] = b
k=0
a=0
for i in range(0,n-1):
    for j in range(0,n-i-1):
        if A_l[j] > A_l[j+1]:
            k = A_l[j]
            A_l[j] = A_l[j+1]
            A_l[j+1] = k
for i in range(0,n):
    print(A_l[i])
    a+=1
print(a)
