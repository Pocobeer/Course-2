import numbers
import random
import matplotlib.pyplot as plt
import numpy as np
import flet as ft
'''
#plt.style.use('_mpl-gallery')
plt.figure(figsize=(10, 6))
n = int(input("Enter the total number of numbers n: "))#Вводим объем выборки
m = int(round(n**0.5))#Находим количество интервалов

print("Number of histogram interval: ", m)


def generate_numbers(m, n):#Функция генерации выборочных значений, попавших в интервалы
    result = []
    for _ in range(m - 1):
        num = random.randint(1, n - sum(result) - (m - len(result)))
        result.append(num)
    result.append(n - sum(result))
    return result


ki = generate_numbers(m, n)#Собственно вызов функции
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
'''

class Dispatcher:
    def __init__ (self, amount: int, x_min: float, x_max: float):
        self.n = amount
        self.x_min = x_min
        self.x_max = x_max
        self.set_count_intervals()
        self.set_ki()
        self.xi = []
        self.delta = (x_max - x_min) / self.m
        self.xi.append(x_min)
        self.intervals = []
        self.set_intervals()
        self.center_values = [(a + b) / 2 for a, b in zip(self.xi, self.xi[1:])]
        self.width = [b - a for a, b in zip(self.xi, self.xi[1:])]
        self.Px = []
        self.empir_chance()
        self.A_l = [None] * self.n
        self.set_psevdo_ints()

    
    def set_count_intervals(self):
        self.m = int(round(self.n ** 0.5))

    def get_count_intervals(self):
        return self.m

    def generate_numbers(self):
        result = []
        for _ in range(self.m - 1):
            num = random.randint(1, self.n - sum(result) - (self.m - len(result)))
            result.append(num)
        result.append(self.n - sum(result))
        return result

    def set_ki(self):
        self.ki = self.generate_numbers()

    def get_ki(self):
        return self.ki
    
    def set_intervals(self):
        for i in range(self.m):
            interval_start = self.x_min + i * self.delta
            interval_end=self.x_min + (i+1) * self.delta
            round_interval_start = round(interval_start, 3)
            round_interval_end = round(interval_end, 3)
            interval_start = round_interval_start
            interval_end = round_interval_end
            self.xi.append(interval_end)
            self.intervals.append([interval_start, interval_end])
        
    def get_intervals(self):
        return self.intervals
    
    def int_to_float(self, number):
        return float(number)

    def empir_chance(self):
        n_float = self.int_to_float(self.n)
        for i in range(self.m):
            p = (self.ki[i] / n_float)
            self.Px.append(p)
    
    def get_empir_chance(self):
        return self.Px

    def RND(self):
        return random.random()
    
    def set_psevdo_ints(self):
        l = 0

        for i in range(0, self.m):
            for j in range(0, self.ki[i]):
                random_value = self.RND()
                a = self.xi[i] + random_value * (self.xi[i+1] - self.xi[i])
                round_a = round(a, 2)
                self.A_l[l] = round_a
                l += 1


        for i in range(l-1, 0, -1):
            j = int(self.RND() * i)
            self.A_l[i], self.A_l[j] = self.A_l[j], self.A_l[i]
        
    def get_psevdo_ints(self):
        return self.A_l


def main(page: ft.Page):
    def add_clicked(e):
        amount = int(amount_field.value)
        x_min = float(x_min_field.value)
        x_max = float(x_max_field.value)

        dispatcher = Dispatcher(amount, x_min, x_max)

        tasks_view.controls.append(ft.Text(value=f"Количество интервалов: {dispatcher.get_count_intervals()}"))
        tasks_view.controls.append(ft.Text(value=f"Число выборочных значений: {dispatcher.get_ki()}"))
        intervals = dispatcher.get_intervals()
        k = 1
        for interval in intervals:
            tasks_view.controls.append(ft.Text(f"Interval {k}: {interval[0]} - {interval[1]}"))
            k += 1
        tasks_view.controls.append(ft.Text(value=f"Эмпирическая вероятность: {dispatcher.get_empir_chance()}"))
        tasks_view.controls.append(ft.Text(value=f"Полученный вариционный ряд: {dispatcher.get_psevdo_ints()}"))

        view.update()

    amount_field = ft.TextField(hint_text="Укажите объем выборки", expand=True)
    x_min_field = ft.TextField(hint_text="Укажите минимальное значение выборки", expand=True)
    x_max_field = ft.TextField(hint_text="Укажите максимальное значение выборки", expand=True)
    tasks_view = ft.Column()
    view=ft.Column(
        width=600,
        controls=[
            ft.Row(
                controls=[
                    amount_field,
                    x_min_field,
                    x_max_field,
                ],
            ),
            ft.FloatingActionButton(icon=ft.icons.ADD, on_click=add_clicked),
            tasks_view,
        ],
    )

    page.horizontal_alignment = ft.CrossAxisAlignment.CENTER
    page.add(view)

if __name__ == "__main__":
    ft.app(target=main)