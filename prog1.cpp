# 1-//
//  main.cpp
//  first
//
//  Created by Дмитрий Емелин on 09.09.2021.
//

#include <iostream>
#include "Prog1.hpp"
using namespace Prog1;

int main()
{
    Matrix matr1 = { 0, 0, nullptr };
    Matrix matr2 = { 0, 0, nullptr };
    if (!input(&matr1))
        return 1;
    output(&matr1, "Source matrix");
    //rebuild_matrix(&matr1, &matr2);
    output(&matr2, "Final matrix");
    erase(&matr1);
    erase(&matr2);
    return 0;
}

//
//  Prog1.cpp
//  first
//
//  Created by Дмитрий Емелин on 09.09.2021.
//

#include "Prog1.hpp"
#include <cmath>
namespace Prog1{

Matrix *input(Matrix *rm) {
    const char *pr = "";
    int m, n;
    do {
        std::cout << pr << std::endl;
        std::cout << "Enter number of lines: ";
        pr = "You are wrong, repeat please";
        if (getNum(m) < 0)
            return nullptr;
        std::cout << "Enter number of columns: ";
        if (getNum(n) < 0)
            return nullptr;
    } while (m < 1 || n < 1);

    rm->m = m;
    rm->n = n;
    try {
        rm->matr = new Line[m];
    }
    catch (std::bad_alloc &ba) {
        std::cout << "------ Too many items in matrix: " << ba.what() << std::endl;
        erase(rm);
        return nullptr;
    }

    for (int i = 0; i < m; i++) {
        try {
            rm->matr[i].a = new double[1];
            rm->matr[i].pos = new int[1];
        }
        catch (std::bad_alloc &ba) {
            std::cout << "------ Too many items in matrix: " << ba.what() << std::endl;
            erase(rm);
            return nullptr;
        }
        std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
        int k = 0;
        for (int j = 0; j < rm->n; j++) {
            int a;
            if (getNum(a) < 0) {
                erase(rm);
                return nullptr;
            }
            if (a != 0) {
                rm->matr[i].a = myrealloc(rm->matr[i].a, k);
                rm->matr[i].pos = myrealloc(rm->matr[i].pos, k);
                rm->matr[i].a[k] = a;
                rm->matr[i].pos[k] = j;
                k++;
            }
        }
        rm->matr[i].k = k;
    }
    return rm;
}
void output(Matrix *rm, const char *str) {
    std::cout << str << std::endl;
    if (str[0] == 'S') {
        for (int i = 0; i < rm->m; i++) {
            int k;
            int j = 0;
            for (; j < rm->matr[i].k; j++) {
                if (j == 0 && rm->matr[i].pos[j] != 0)
                    k = rm->matr[i].pos[j];
                else
                    k = rm->matr[i].pos[j] - rm->matr[i].pos[j - 1] - 1;

                while (k > 0) {
                    std::cout << '0' << ' ';
                    k--;
                }
                std::cout << rm->matr[i].a[j] << ' ';
            }
            j--;
            k = rm->n - rm->matr[i].pos[j] - 1;

            while (k > 0) {
                std::cout << '0' << ' ';
                k--;
            }
            std::cout << std::endl;
        }
    } else {
        for (int i = 0; i < rm->m; i++) {
            for (int j = 0; j < rm->matr[i].k; j++)
                std::cout << rm->matr[i].a[j] << " ";
            std::cout << std::endl;
        }
    }
}

void erase(Matrix *rm) {
    int i;
    for (i = 0; i < rm->m; i++) {
        for(int j = 0; j < rm->matr[i].k-1; j++){
            delete[] rm->matr[i].pos;
            delete[] rm->matr[i].a;
            
        }
    }

    delete[] rm->matr;
}

int comp(const void *a, const void *b) {
    const long double *fa = (const long double *) a;
    const long double *fb = (const long double *) b;
    if (*fa > *fb) return 1;
    if (*fa < *fb) return -1;

    if (*fa == *fb) {
      //return -memcmp(fa, fb, sizeof *fa); if -0.0, 0.0 order important.
      return 0;
    }
    // At least one of *fa or *fb is NaN
    // is *fa a non-NaN?
    if (!isnan(*fa)) return -1;
    if (!isnan(*fb)) return 1;

    // both NaN
    return 0;
    // return -memcmp(fa, fb, tbd size); if NaN order important.
  }

Matrix* function(Matrix* rm){
    Line* cal = rm->matr;
    if (cal->a[0] <= 0){
        for ( int i = 0; i < rm->n; i++)
        qsort(cal[i].a, rm->m, sizeof (double),  comp);
            }
    
    return rm;
    
    
}

}
