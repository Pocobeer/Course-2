#include <iostream>
#include "includes/all_includes.h"

#include "includes/sort_by_insert_in_linked_list.h" //3  OK
#include "includes/sort_by_shell.h"					//4  OK

#include "includes/fast_sort_rec.h"					//7  OK
#include "includes/fast_sort_iter.h"				//8  OK
#include "includes/digit_exchange_sort.h"			//9  OK

#include "includes/heapsort.h"						//11 OK
#include "includes/count_sort.h"					//12 OK

#include "includes/two_way_merge_sort.h"			//15 OK

#include "includes/list_merge_sort.h"				//17 OK

#include "includes/tester.h"


int main()
{
	setlocale(0, "");
	const int TESTS_COUNT = 100;

	vector<int> len_of_vectors = { 100, 2000, 4000, 6000, 8000,10000 }; //Здесь указать длину случайных массивов
	vector<int> MY_VEC = {};
	for (auto& len : len_of_vectors) {
		MY_VEC.clear();
		for (unsigned int i = 0; i < len; i++) {
			MY_VEC.push_back(random_int());
		}
		printf("\nКоличество тестов {%d}, длина случайного вектора {%d}\n", TESTS_COUNT, int(MY_VEC.size()));
		if (MY_VEC.size() <= 200) {
			show_vector_as_py(MY_VEC);
		}
		shell_sort* SHELL_SORT = new shell_sort(MY_VEC);		 //Сортировка Шелла
		fast_sort_rec* FASTR_SORT = new fast_sort_rec(MY_VEC);	 //Быстрая сортировка рекурсивная
		fast_sort_iter* FASTI_SORT = new fast_sort_iter(MY_VEC);	 //Быстрая сортировка итерационная
		linked_list_sort* LINKL_SORT = new linked_list_sort(MY_VEC); //Сортировка вставками в связанный список
		radix_sort* RADIX_SORT = new radix_sort(MY_VEC);		 //Сортировка цифровым обменом
		heap_sort* HEAP_SORT = new heap_sort(MY_VEC);		 //Пирамидальная сортировка
		count_sort* COUNT_SORT = new count_sort(MY_VEC);		 //Сортировка пересчётом
		two_way_merge* MERGE_SORT = new two_way_merge(MY_VEC);	 //Двухпутевое слияние
		merge_sort* SMERG_SORT = new merge_sort(MY_VEC);		 //Простое слияние

		vector<BASIC_CLASS*> vec_of_sorts = { SHELL_SORT, FASTR_SORT, FASTI_SORT, LINKL_SORT, RADIX_SORT, HEAP_SORT, COUNT_SORT, MERGE_SORT, SMERG_SORT };
		TESTER_class* TESTER = new TESTER_class(vec_of_sorts, TESTS_COUNT);
		delete SHELL_SORT, FASTR_SORT, FASTI_SORT, LINKL_SORT, RADIX_SORT, HEAP_SORT, COUNT_SORT, MERGE_SORT, SMERG_SORT, TESTER;
	}
}