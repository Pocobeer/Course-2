import numbers
import random
import matplotlib.pyplot as plt
import numpy as np
plt.style.use('_mpl-gallery')
plt.figure(figsize=(10, 6))
n = int(input("Enter the total number of numbers n: "))
m = int(round(n**0.5))
print("Number of histogram interval: ", m)
# Create lists to store histogram parameters xi and P(xi)
#xi = [10.3, 12.171, 14.043, 15.914, 17.786, 19.657, 21.529, 23.4]
Px = [0.06, 0.08, 0.16, 0.28, 0.26, 0.1, 0.06]
#Px=[]

#  Генерация случайных чисел, сумма которых равна 1
# random_sum = 0
# for i in range(m):
#     random_number = round(random.random(), 2)
#     Px.append(random_number)
#     random_sum += random_number

# # Нормализация случайных чисел
# for i in range(m):
#     Px[i] /= random_sum
xi=[]
x_min = float(input("Enter min X: "))
x_max = float(input("Enter max X: "))
delta = (x_max - x_min) / m
xi.append(x_min)
for i in range(m):
    interval_start = x_min + i * delta
    interval_end=x_min + (i+1) * delta
    round_interval_start = round(interval_start, 3)
    round_interval_end = round(interval_end, 3)
    interval_start = round_interval_start
    interval_end = round_interval_end
    xi.append(interval_end)
    print(f"Interval {i+1}: {interval_start} - {interval_end}")


# Рассчитаем центры интервалов для позиции Px
center_values = [(a + b) / 2 for a, b in zip(xi, xi[1:])]

# Рассчитаем ширину каждого столбца
width = [b - a for a, b in zip(xi, xi[1:])]

ki = []
# x = float(input(f"Enter the value of x[1] for interval: "))
# xi.append(x)
# x_i=x
# R=float(input(f"Enter the value of R: "))
# def Arr_sum():
#     sum=0
#     for i in Px:
#         sum+=Px[i]
#     return sum
# Input values of xi and P(xi) for each histogram interval
# for i in range(m):
#    p = float(input(f"Enter the value of P(xi) for interval {i+1}:"))
#    x_i=x_i+R
#    xi.append(x)
#    Px.append(p)

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



# for i in range(1,l):
#     rand_val = RND()
#     p_1=rand_val*(n-1)+1
#     p_2=rand_val*(n-1)+1
#     if p_1 != p_2:
#         b = A_l[p_1]
#         A_l[p_1]=A_l[p_2]
#         A_l[p_2] = b

for i in range(l-1, 0, -1):
    # выбор случайного индекса
    j = int(RND() * i)
    # меняем элементы местами
    A_l[i], A_l[j] = A_l[j], A_l[i]
k=0
a=0
# for i in range(0,n-1):
#     for j in range(0,n-i-1):
#         if A_l[j] > A_l[j+1]:
#             k = A_l[j]
#             A_l[j] = A_l[j+1]
#             A_l[j+1] = k
#for i in range(0,n):
#    print(A_l[i])
print(A_l)  
# Draw the histogram with the updated data
plt.bar(center_values, Px, width=width, color='skyblue', edgecolor='black')

# Set the values for the X and Y axes, and the title
plt.xlabel('Значения Xi', fontsize=12)
plt.ylabel('Частота Px', fontsize=12)
plt.title('Histogramm')

plt.xticks(center_values)
plt.yticks(Px)
plt.grid(True)

# Display the histogram
plt.show()