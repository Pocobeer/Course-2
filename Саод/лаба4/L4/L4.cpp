#include "includes\all_includes.h"


#include "includes\Seq_search.h"
#include "includes\Binary_search.h"
#include "includes\Fibonacci.h"
#include "includes\Tree_bin.h"
#include "includes\RBtree.h"
#include "includes\tests__.h"
#include "includes\Dig_search.h"
#include "includes\Hash_search.h"
#include "includes\Fibonacci_wo_check_i.h"
#include "includes\int_search.h"
#include "includes\AVL_search.h"


int main()
{
    setlocale(0, "");

    int TESTS_COUNT = 1000, TESTS_VECTOR_SIZE = 20000;

    vector<int> MY_VECTOR;

    wprintf(L"КОЛИЧЕСТВО ТЕСТОВ: %d\n", TESTS_COUNT);
    for (int i = 2500; i <= TESTS_VECTOR_SIZE; i *= 2) {
        wprintf(L"\nРазмер массива: %d\n", i);
        MY_VECTOR.clear();
        for (int i_ = 0; i_ != i*2; i_+=2) {
            MY_VECTOR.push_back(i_);
        }

        seq_search* SEQ_S = new seq_search(MY_VECTOR); //последовательный
        bin_search* BIN_S = new bin_search(MY_VECTOR); //бинарный
        tre_search* TRE_S = new tre_search(MY_VECTOR); //обычное дерево
        fib_search* FIB_S = new fib_search(MY_VECTOR); //поиск фибоначчи с проверкой
        RBT_search* RBT_S = new RBT_search(MY_VECTOR); //RB-дерево
        Dig_search* DSR_S = new Dig_search(MY_VECTOR); //цифровой поиск
        has_search* HSR_S = new has_search(MY_VECTOR); //поиск с хешированием
        fib_sea_wo* FSR_S = new fib_sea_wo(MY_VECTOR); //поиск фибоначчи без проверки
        //int_search* INT_S = new int_search(MY_VECTOR); //интерполяционный поиск
        //AVL_search* AVL_S = new AVL_search(MY_VECTOR); //AVL-дерево
        vector<BASIC_CLASS*> vec_bas_cl{ BIN_S, FIB_S, SEQ_S, RBT_S, DSR_S, TRE_S, HSR_S, FSR_S/*,INT_S, AVL_S */ };
        TESTS* my_tests = new TESTS{ TESTS_COUNT, MY_VECTOR, vec_bas_cl };

        delete SEQ_S, BIN_S, TRE_S, FIB_S, RBT_S, DSR_S, HSR_S, FSR_S/*, INT_S, AVL_S*/;
        delete my_tests;
    }
}
