import numbers
import random
import matplotlib.pyplot as plt
import numpy as np
#plt.style.use('_mpl-gallery')
plt.figure(figsize=(10, 6))
n = int(input("Enter the total number of numbers n: "))
m = int(round(n**0.5))
print("Number of histogram interval: ", m)
def generate_numbers(m, n):
    result = []
    for _ in range(m - 1):
        num = random.randint(1, n - sum(result) - (m - len(result)))
        result.append(num)
    result.append(n - sum(result))
    return result
ki = generate_numbers(m, n)

print("Values of ki:", ki)
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

Px = []
def int_to_float(number):
    return float(number)
def float_to_int(number):
    return int(number)
n_float = int_to_float(n)
for i in range(m):
    p = (ki[i]/n_float)
    Px.append(p)
print("Histogram parameters P(xi):", Px)
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
for i in range(l-1, 0, -1):
    # выбор случайного индекса
    j = int(RND() * i)
    # меняем элементы местами
    A_l[i], A_l[j] = A_l[j], A_l[i]

print(A_l) 
choice = input("Select the graph to display (1 - histogram, 2 - dot plot): ")

if choice == "1":
    # Вывод гистограммы
    plt.bar(center_values, Px, width=width, color='skyblue', edgecolor='black')
    plt.xlabel('Значения Xi', fontsize=12)
    plt.ylabel('Частота Px', fontsize=12)
    plt.title('Гистограмма')
    
    plt.xticks(center_values)
    plt.yticks(Px)
    plt.grid(True)
    plt.show()

elif choice == "2":
    # Вывод графика по точкам
    plt.plot(center_values, Px, marker='o', color='skyblue', linestyle='-', linewidth=2)
    plt.xlabel('Значения Xi', fontsize=12)
    plt.ylabel('Частота Px', fontsize=12)
    plt.title('График')
    
    plt.grid(True)
    plt.show()

else:
    print("Incorrect selection. Please enter 1 or 2 to select a schedule.")
