//
//  Prog1.hpp
//  first
//
//  Created by Дмитрий Емелин on 09.09.2021.
//

#ifndef Prog1_hpp
#define Prog1_hpp
#include <iostream>
#include <stdio.h>
namespace Prog1{
    struct Line{
        int k; //размер строки (количество ненулевых в строке)
        int* pos; //позиция ненулевого элемента в строке
        double *a; // massive
    };
struct Matrix {
    int m; // строки
    int n; // столбцы
    Line* matr;
};
template <class T>
int getNum(T &a){
    std:: cin >> a;
    if (!std:: cin.good() ) // Error
        return -1;
    return 1;
}
template <class T>
T* myrealloc(T* a, int n) {
    T* b = new T [n + 1];
    T* tmp = b;
    for (int i = 0; i < n; i++) {
        tmp[i] = a[i];
    }
    delete[] a;
    return b;
}

int comp(const void *a, const void *b);

inline int isgreater(double a, double b)
{
return a > b;
}
inline int isless(double a, double b)
{
return a < b;
}
Matrix* input(Matrix* rm);
void output(Matrix *rm, const char *str);
void erase(Matrix *rm);
Matrix* function(Matrix* rm);

}
#endif /* Prog1_hpp */
