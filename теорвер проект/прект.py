import numbers
import random
import matplotlib.pyplot as plt
import numpy as np
#plt.style.use('_mpl-gallery')
plt.figure(figsize=(10, 6))
n = int(input("Enter the total number of numbers n: "))#Вводим объем выборки
m = int(round(n**0.5))#Находим количество интервалов
print("Number of histogram interval: ", m)
# def generate_numbers(m, n):#Функция генерации выборочных значений, попавших в интервалы
#     result = []
#     for _ in range(m - 1):
#         num = random.randint(1, n - sum(result) - (m - len(result)))
#         result.append(num)
#     result.append(n - sum(result))
#     return result
# ki = generate_numbers(m, n)#Собственно вызов функции
ki=[5, 7, 12, 10, 7, 5, 4]
print("Values of ki:", ki)
xi=[]#Массив значений оси x
x_min = float(input("Enter min X: "))#Вводим минимальный x
x_max = float(input("Enter max X: "))#Вводим максимальный x
delta = (x_max - x_min) / m # Длина интервала
xi.append(x_min)#Заносим минимальный x в массив
for i in range(m):#Цикл рссчета интервалов
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

Px = []#Массив эмпирической вероятности
def int_to_float(number):#Функция для того чтобы преобразовать n из int в float
    return float(number)
n_float = int_to_float(n)
for i in range(m):#Цикл расчета эмпирической вероятности
    p = (ki[i]/n_float)
    Px.append(p)
print("Histogram parameters P(xi):", Px)
l=0
A_l = [None]*n#Массив псевдослучайных n чисел
def RND():
    return random.random()
for i in range(0, m):#Получаем псевдослучайные числа которые входят в i-й интервал
    for j in range(0, ki[i]):
        random_value = RND()
        a = xi[i] + random_value * (xi[i+1] - xi[i])
        round_a = round(a, 2)
        A_l[l] = round_a
        l += 1
for i in range(l-1, 0, -1):#Цикл пермешивания псевдослучайных чисел
    # выбор случайного индекса
    j = int(RND() * i)
    # меняем элементы местами
    A_l[i], A_l[j] = A_l[j], A_l[i]

print(A_l)#Вывод псевдослучайных чисел 
choice = input("Select the graph to display (1 - histogram, 2 - dot plot): ")#Выбор,каким графиком показать 

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
