#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <chrono>


using namespace std;


int random_int(int left = 0, int right = 999) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(left, right);
	return dist(gen);
}

template <typename T>
ostream& operator<<(ostream& stream, vector<T>& vec) {
	for (auto& a : vec) {
		stream << a << " ";
	} stream << endl;
	return stream;
}
template <typename T>
ostream& operator<<(ostream& stream, vector<vector<T>>& vec) {
	for (auto& a : vec) {
		stream << a;
	} stream << endl;
	return stream;
}

class Timer {
public:
	Timer() : start(std::chrono::high_resolution_clock::now()) {}
	float elapsed() {
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		return duration.count();
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

vector<pair<int, int>> move_slon = { {-9,-9}, {-9,9}, {9,9}, {9,-9} };
vector<pair<int, int>> move_kon = { {1,2}, {2,1}, {2,-1}, {1, -2}, {-1,-2}, {-2,-1}, {-2,1}, {-1,2} };

class reshenie {
private:
	size_t size = 0;
	vector<vector<int>> doska{ size, vector<int>(size, 0)};			// Инициализируем доску размером size * size, дефолтное значение в поле = 0
	struct archiepiskop {
		int pos_x = 0;
		int pos_y = 0;
		archiepiskop(){}
		archiepiskop(int x, int y): pos_x(x), pos_y(y) {}
		void set_pos(int x, int y) {
			pos_x = x;
			pos_y = y;
		}
		friend ostream& operator<<(ostream& stream, archiepiskop* arch) {
			stream << "x: " << arch->pos_x << " y: " << arch->pos_y << endl;
			return stream;
		}
		friend ostream& operator<<(ostream& stream, archiepiskop arch) {
			stream << "x: " << arch.pos_x << " y: " << arch.pos_y << endl;
			return stream;
		}
		bool operator==(archiepiskop& other) {
			return this->pos_x == other.pos_x && this->pos_y == other.pos_y;
		}
		friend bool operator ==(vector<archiepiskop> &cur, vector<archiepiskop> &vec) {
			if (cur.size() != vec.size()) {
				return false;
			}
			for (auto& c : cur) {
				for (auto& v : vec) {
					if (c == v) {
						return false;
					}
				}
			}
			return true;
		}
	};
	bool is_uniq_arch(archiepiskop* arch) {		// Проверка на уникальность архиепископа среди векторов архиепископов
		for (auto& a : all_arch) {
			if (a == arch) {
				return false;
			}
		}
		return true;
	}
	void set_rand_coord(archiepiskop* arch) {
		arch->set_pos(random_int(0, size - 1), random_int(0, size - 1));
	}
	void set_rand_coord(vector<archiepiskop*> arch_) {
		for (auto& arch : arch_)
			set_rand_coord(arch);
	}
	vector<archiepiskop*> all_arch{};
	void set_attack(archiepiskop *arch) {		// Устанавливаем все поля, которые покрываются архиепископом
		int cur_x = arch->pos_x;
		int cur_y = arch->pos_y;
		//printf("Текущее положение x:y = %d:%d\n", cur_x, cur_y);
		for (auto& [x, y] : move_slon) {
			for (int i = -9; i < 9; i++) {
				if (cur_x + i < size && cur_x + i >= 0 && cur_y + i < size && cur_y + i >= 0) {
					doska[cur_x + i][cur_y + i] = 1;
				}
				if (cur_x - i < size && cur_x - i >= 0 && cur_y + i < size && cur_y + i >= 0) {
					doska[cur_x - i][cur_y + i] = 1;
				}
			}
		}
		for (auto& [x, y] : move_kon) {
			if (cur_x + x >= 0 && cur_x + x < size && cur_y + y >= 0 && cur_y + y < size) {
				doska[cur_x + x][cur_y + y] = 1;
			}
		}
	}
	void reset_attack() {				// Сбрасываем доску до нулей
		for (auto& pos_x : doska) {
			for (auto& pos_y : pos_x) {
				pos_y = 0;
			}
		}
	}
	bool all_covered() {			// Возвращает true, если все поля доски покрываются архиепископами
		for (auto& x : doska) {
			for (auto& y : x) {
				if (y == 0) {
					return false;
				}
			}
		}
		return true;
	}
	bool in_pos(vector<archiepiskop*> arch, int x, int y) { // Вспомогательная функция для operator<<..
		bool in = false;
		for (auto& ar: arch) {
			if (ar->pos_x == x && ar->pos_y == y) {
				return true;
			}
		}
		return false;
	}

	vector<vector<archiepiskop>> resheniya {};

	bool check_is_uniq(vector<archiepiskop*>& arch) { // Проверка на уникальность вектора решений
		int count_of_diff = 0;
		for (auto& resh : resheniya) {
			for (auto& temp : resh) {
				for (auto& ar : arch) {
					if (temp == *ar) {
						count_of_diff++;
					}
				}
			}
		}
		int dif = arch.size() - 1 - count_of_diff;
		if (dif >= 1) {
			return true;
		}
		return false;
	}
	bool check_for_all_resh_is_uniq() {		// Дополнительная проверка на уникальность каждого решения. Допускает 1 соответствие
		int diff = 0;
		for (int i = 0; i < resheniya.size() - 1; i++) {
			for (int j = 0; j < resheniya.size() - 1 - i; j++) {
				if (resheniya[j] == resheniya[i]) {
					diff++;
				}
			}
		}
		int dif = resheniya[resheniya.size() - 1].size() - 1 - diff;
		if (dif >= 1) {
			return true;
		}
		return false;
	}
public:
	int all_attempts = 0;
	int count_of_resh = 0;

	/*
	по горизонтали идёт y координата
	O  -> y_coord
	|
	v
	x_coord
	по вертикали x координата
	То есть это стандартная сетка, повёрнутая на 90 градусов по часовой стрелке
	*/
	reshenie(int size) : size(size) {
		bool need_continue = false;							// Необходимый параметр. Если в процессе поиска нашли минимальное количество архиепископов, то не ищем с бОльшим количеством
		Timer my_timer;										// Инициализация таймера
		for (int i = size/2; i < size && !need_continue;) {	// Вместо int i = x, можно указать любое число, количество архиепископов само подсосётся
			int attempts = 0;
			archiepiskop* temp_arch = new archiepiskop(random_int(0, size - 1), random_int(0, size - 1)); // Создаём архиепископа с случайными координатами
			while (!is_uniq_arch(temp_arch)) {															  // Проверка на уникальность архиепископа
				temp_arch->set_pos(random_int(0, size - 1), random_int(0, size - 1));					  // Если не уникальный, то пересоздаётся
			}
			all_arch.push_back(temp_arch);

			while (i > all_arch.size()) {			// Проверка на количество архиепископов. Можно в верхнем цикле указывать кастомное количество, а не считать с нуля
				archiepiskop* temp_arch = new archiepiskop(random_int(0, size - 1), random_int(0, size - 1));
				while (!is_uniq_arch(temp_arch)) {
					temp_arch->set_pos(random_int(0, size - 1), random_int(0, size - 1));	// Если координаты архиепископа уже существуют, то перебираем до несуществующих
				}
				all_arch.push_back(temp_arch);
			}
			
			while (attempts < i*i*500000) {
				for (auto& a : all_arch) {
					set_attack(a);						  // Устанавливаем все позиции, куда достают архиепископы
				}
				if (all_covered()) {					  // Если все позиции доски закрываются архиепископами
					if (check_is_uniq(all_arch)) {		  // Проверка на уникальность текущего хода
						if (count_of_resh < 5)			  // Выводим только первые 5 решений
							cout << *this << endl;		  // Если уникальный ход, то он выводится на экран
						vector<archiepiskop> temp_arch{}; 
						for (auto& a : all_arch) {
							temp_arch.push_back(*a);	  // Засовываем в временный вектор значения координат архиепископов
						}
						resheniya.push_back(temp_arch);	  // Добавляем в вектор решений полученный результат
						count_of_resh++;				  // Увеличиваем счётчик решений (альтернативный вариант, в operator<<... используется размер вектора решений)
					}
					need_continue = true;				  // Устанавливаем, что нашли минимальное количество архиепископов
				}
				set_rand_coord(all_arch);		// Сбрасываем положение архиепископов, устанавливаем их рандомно
				reset_attack();					// Сбрасываем поля доски до нулей
				attempts++;
				all_attempts++;
			}
			i++;
		}
		printf("Времени затрачено: %f\n", my_timer.elapsed());	
		//cout << check_for_all_resh_is_uniq();					// Дополнительная проверка на уникальность решений. Допускается ровно одно схождение
																// Если 5 архиепископов будут на одной и той же позиции, а шестой будет на другой,
																// То будет считаться как новое уникальное решение
	}
	friend ostream& operator<<(ostream& stream, reshenie &resh) {
		int y = 0;
		int x = 0;
		for (auto& a : resh.doska) {
			for (auto& b : a) {
				bool founded = resh.in_pos(resh.all_arch, x, y);
				if (!founded) {
					stream << b << " ";
				}
				else {
					stream << "\x1B[34m" << b <<"\033[0m ";			// Подсветка архиепископа синим цветом
				}
				if (y >= resh.size - 1) {
					y = 0;
					x++;
					continue;
				}
				y++;

			}
			stream << endl;
		}
		stream << "Количество решений: " << resh.resheniya.size()+1 << endl;
		//stream << "Количество попыток: " << resh.all_attempts << endl;	// Расскомментировать, если нужно выводить количество попыток
		return stream;
	}
	~reshenie() {
		for (auto& arch : all_arch) {
			delete arch;
		}
	}
};
