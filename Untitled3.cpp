# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

#include "SortArraySDK\SortArrayLib.h"

int main ()
    {
    txCreateWindow (1500, 800);

    const int k = 20;
    int data [k] = {};

    std::ofstream f;
    f.open("1.txt");

    $y; printf("\n----- Задача сортировка обменом -----\n");

    int n = 5;

    for (int z = 0; z < 4; z++)
        {
        int countSwap = 0;
        int count = 0;

        FillRandomArrayTest (data, n, 50);
        PrintArray  (data, n, "Исходный массив", 5);

        SortShell (data, n, &countSwap, &count);


        f << n << " " << count << " " << countSwap << "\n";


        PrintArray  (data, n, "Отсортированный массив", 5);
        printf("обменов %d      сравнений   % d", countSwap, count);

        n += 5;
        }

    f.close();

    return 0;
    }
