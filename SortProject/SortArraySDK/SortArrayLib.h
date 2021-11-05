//{===========================================================================
//! @file       SortArrayLib.h
//!
//!             Библиотека алгоритмов сортировки Массивов
//!
//!@author  (C) Фионина Людмила Евгеньевна, г. Самара,
//!@date          2021
//!
//}===========================================================================

#include "TXLib.h"

void FillRandomArray     (int data[], int size, int range);
void FillRandomArrayTest (int data[], int size, int range);
void PrintArray          (int data[], int size, const char title[], int column);

int NumMinArray (int data[], int beginIndex, int endIndex);
int NumMaxArray (int data[], int beginIndex, int endIndex);

void SortSwap   (int data[], int size, int* countSwap, int* count);
void SortBubble (int data[], int size, int* countSwap, int* count);

//{-----------------------------------------------------------------------------
//! Задает массив случайнами числами из диапазона [-a, a].
//!
//! @param data[]    data[] - одномерный массив
//! @param sizeFont  size   - размер массива (количество элементов)
//! @param range     range  - длина диапазона
//!
//! @par  Пример использования:
//! @code
//!         FillRandomArray (data, 20, 100);
//! @endcode
//}-----------------------------------------------------------------------------
void FillRandomArray (int data[], int size, int range)
    {
    for (int i = 0; i < size; i++)
        {
        data[i] = rand() % range - range / 2;
        }
    }

//{-----------------------------------------------------------------------------
//! Задает массив случайнами числами, где последняя цифра = индексу элемента в массиве.
//!
//! @param data[]    data[] - одномерный массив
//! @param sizeFont  size   - размер массива (количество элементов)
//! @param range     range  - число для задания количества сотен
//!
//! @par  Пример использования:
//! @code
//!         FillRandomArrayTest (data, 20, 100);
//! @endcode
//}-----------------------------------------------------------------------------
void FillRandomArrayTest (int data[], int size, int range)
    {
    for (int i = 0; i < size; i++)
        {
        data[i] = rand() % range * 100 + i;
        }
    }

//{-----------------------------------------------------------------------------
//! Вывод элементов массива на консоль.
//!
//! @param data[]   data[]  - массив для вывода
//! @param size     size    - количество элементов в массиве
//! @param title[]  title[] - поясняющий текст
//! @param column   column  - количество колонок для вывода элементов
//!
//}-----------------------------------------------------------------------------
void PrintArray (int data[], int size, const char title[], int column)
    {
    $y; printf ("\n%s:", title);

    for (int i = 0; i < size; i++)
        {
        if (i % column == 0) printf ("\n");

        $c; printf ("[%2d] = ",i);
        $g; printf ("%4d",data[i]);
        if (i != size - 1)
            {
            $c; printf (", ");
            }
        }

    printf ("\n");
    }

//{-----------------------------------------------------------------------------
//! Поиск индекса максимального элемента массива.
//!
//! @param data[]   data[]  - массив для вывода
//! @param size     size    - количество элементов в массиве
//!
//}-----------------------------------------------------------------------------
int NumMaxArray (int data[], int beginIndex, int endIndex)
    {
    int numMax = beginIndex;
    int maxElem = data[numMax];

    for (int i = beginIndex; i < endIndex; i++)
        {
        assert (i >= beginIndex && i < endIndex);

        if (data[i] > maxElem)
            {
            maxElem = data[i];
            numMax = i;
            }
        }
    return numMax;
    }

//{-----------------------------------------------------------------------------
//! Поиск индекса минимального элемента массива.
//!
//! @param data[]   data[]  - массив для вывода
//! @param size     size    - количество элементов в массиве
//!
//}-----------------------------------------------------------------------------
int NumMinArray (int data[], int beginIndex, int endIndex)
    {
    int numMin = beginIndex;
    int minElem = data[numMin];

    for (int i = beginIndex; i < endIndex; i++)
        {
        assert (i >= beginIndex && i < endIndex);

        if (data[i] < minElem)
            {
            minElem = data[i];
            numMin = i;
            }
        }
    return numMin;
    }

//-----------------------------------------------------------------------------
void SortSwap (int data[], int size, int* countSwap, int* count)
    {
     for (int j = 0; j < size; j++)
        {
        int numMin = j;
        int minElem = data[numMin];

        for (int i = j; i < size; i++)
            {
            assert (i >= j && i < size);

            if (data[i] < minElem)
                {
                minElem = data[i];
                numMin = i;

                *count += 1;
                }
            else
                {
                *count += 1;
                }
            }
        *countSwap += 1;
        data[numMin] = data [j];
        data[j] = minElem;
        }
    }


//-----------------------------------------------------------------------------
void SortBubble (int data[], int size, int* countSwap, int* count)
    {
    for (int i = 0; i < size - 1; i++)
        {
        assert (i >= 0 && i < size - 1);

        for (int j = 0; j < size - i - 1; j++)
            {
            assert (j     >= 0 && j     < size - i - 1);
            assert (j + 1 >= 0 && j + 1 < size - i);

            if (data[j] > data [j + 1])
                {
                int temp = data [j];
                data[j] = data[j + 1];
                data[j + 1] = temp;

                *countSwap += 1;
                *count += 1;
                }
            else
                {
                *count += 1;
                }
            }
        }
    }
