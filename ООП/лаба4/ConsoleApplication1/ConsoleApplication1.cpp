#include <iostream>
using namespace std;
const int SIZE = 10;
struct Structure {
    int StructureNumber;
    const char *StructureFirstChar;
    double StructureElement;
};
void sort_by_decrease(int* a, int b) {

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b - 1; j++) {
            if (*(a + j) < *(a + j + 1)) {
                swap(*(a + j), *(a + j + 1));
            }
        }
    }
}
double rand_num(double start, double end) {
    return rand() % (int)(end - start + 1) + start;
    //return rand() * (end - start) / RAND_MAX + start;
}
int max_abs(int* arr, int SIZE) {
    int maxabs = 0;
    for (int i = 0; i < SIZE; i++) {
        if (abs(arr[i]) > maxabs) maxabs = arr[i];
        //if (abs(*(arr+i)) > maxabs) maxabs = *(arr+i);
    }
    return maxabs;
}
int sum_elements_between_positive(int* a, int SIZE) {
    int sum = 0;
    bool f1 = false, f2 = false;
    for (int i = 0; i < SIZE; i++) {
        if (*(a+i) > 0) {
            if (f1) f2 = true;
            if (!f1) {
                f1 = true;
                continue;
            }
        }
        if (f1 && !f2) {
            sum += *(a+i);
        }
    }
    return sum;
}
void rand_matrix(double** m, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            m[i][j] = rand_num(0, 100);
        }
    }
}
void print_matrix(double** m, int rows, int columns) {
    cout << "Matrix: " << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << int(m[i][j]) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void smooth(double** m, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (i == 0) {
                if (j == 0) m[i][j] = (m[i + 1][j] + m[i][j + 1]) / 2;
                if (j == 4) m[i][j] = (m[i][j - 1] + m[i + 1][j]) / 2;
                if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i + 1][j]) / 2;
            }
            if (i ==4) {
                if (j == 0) m[i][j] = (m[i - 1][j] + m[i][j + 1]) / 2;
                if (j == 4) m[i][j] = (m[i][j - 1] + m[i - 1][j]) / 2;
                if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i - 1][j]) / 2;
            }
            if (i > 0 && i < 4) {
                if (j == 0) m[i][j] = (m[i - 1][j] + m[i][j + 1] + m[i + 1][j]) / 2;
                if (j == 4) m[i][j] = (m[i][j - 1] + m[i - 1][j] + m[i + 1][j]) / 2;
                if (j > 0 && j < 4) m[i][j] = (m[i][j + 1] + m[i][j - 1] + m[i - 1][j] + m[i + 1][j]) / 2;
            }
        }
    }
}
void print_array(int* a, int b) {
    cout << "Array: " << "\n";
    for (int i = 0; i < b; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Exrsize 1:" << endl;
    int integer = 2;
    char Char = 'C';
    wchar_t Wchar = L'A';
    float pi = 3.14;
    double pi1 = 3.141592;
    int* inter;
    char* ch;
    wchar_t* xch;
    float* Pi;
    double* Pi1;
    inter = &integer;
    ch = &Char;
    xch = &Wchar;
    Pi = &pi;
    Pi1 = &pi1;
    cout << "Adress of integer: " << &inter << endl;
    cout << "Value of integer: " << *inter << endl;
    cout << "Adress of Char: " << &ch << endl;
    cout << "Value of Char: " << *ch << endl;
    cout << "Adress of Wchar: " << &xch << endl;
    cout << "Value of Wchar: " << *xch << endl;
    cout << "Adress of pi: " << &Pi << endl;
    cout << "Value of pi: " << *Pi << endl;
    cout << "Adress of pi1: " << &Pi1 << endl;
    cout << "Value of pi1: " << *Pi1 << endl;
    cout << "Exersize 2:" << endl;
    enum Colors {r, g, b};
    cout << "Enum Colors{r, g, b}" << endl;
    Colors red = r;
    Colors* red_ptr = &red;
    cout << "r = " << red << ", adress = " << red_ptr << endl;
    cout << "Exersize 3: " << endl;
    struct Structure x, * x_ptr = &x;
    x_ptr->StructureNumber = 10;
    x.StructureElement = 3.14;
    x_ptr->StructureFirstChar = "S";
    cout << "Structure: \n" << "int StructureNumber = " << x_ptr->StructureNumber
        << "\tAdress: " << &x_ptr->StructureNumber << "\ndouble StructureElement = " << x_ptr->StructureNumber
        << "\tAdress: " << &x_ptr->StructureElement << "\nconst char *StructureFirstChar = "
        << x_ptr->StructureFirstChar << "\tAdress: " << x_ptr->StructureFirstChar << endl;
    cout << "Exersize 4: " << endl;
    float pi2 = 3.14, *pi2_ptr = &pi;
    int pi2_int = *((float*)pi2_ptr);
    cout << typeid(pi2).name() << " " << pi2 << endl << typeid(pi2_int).name() << " " << pi2_int << endl;
    cout << "Exersize 5: " << endl;
    int arr[SIZE] = {0, 1, -2, 3, -4, 5, -6, 7, -8, 9};
    int* arr_ptr = arr;
    print_array(arr_ptr, 10);
    sort_by_decrease(arr_ptr, 10);
    print_array(arr_ptr, 10);
    cout << "Exersize 6: " << endl;
    int rows = 5, columns = 5;
    double** mass = new double* [rows];
    for (int i = 0; i < rows; i++) {
        mass[i] = new double[columns];
    }
    rand_matrix(mass, rows, columns);
    print_matrix(mass, rows, columns);
    smooth(mass, rows, columns);
    print_matrix(mass, rows, columns);
    for (unsigned i{}; i < rows; i++) // delete dynamic massive
    {
        delete[] mass[i];
    }
    delete[] mass;
    cout << "Exersize 7: " << endl;
    print_array(arr_ptr, SIZE);
    cout << "Max abs number :" << max_abs(arr_ptr, SIZE) << endl;
    cout << "Exersize 8: " << endl;
    print_array(arr_ptr, SIZE);
    int(*func_ptr)(int*, int) = sum_elements_between_positive;
    int j = func_ptr(arr_ptr, SIZE);
    cout << "Summ between positive numbers: " << j << endl;
    cout << "Exersize 9: " << endl;
    int integg = 3;
    int* integg_ptr = &integg;
    void* void_ptr;
    void_ptr = integg_ptr;
    cout << "Value from void_ptr: " << *(int*)void_ptr << endl;
    *(int*)void_ptr = 250;
    struct Structure randomshit = { 1, "Ura", 3.14};
    struct Structure* struct_ptr;
    struct_ptr = &randomshit;
    cout << "\nStruct info int StructureElement  = " << (*struct_ptr).StructureElement 
        << "\nStruct info char StructureFirstChar = " << (*struct_ptr).StructureFirstChar
        << endl;
    struct Structure* void_struct;
    void_struct = struct_ptr;
    cout << "Struct info double SructureNumber = " << (*void_struct).StructureNumber << endl;
}

