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

int NumMinArray (int data[], int beginIndex, int endIndex, int* countCompar = NULL);
int NumMaxArray (int data[], int beginIndex, int endIndex);

void SortExchange (int data[], int size, int* countSwap = NULL, int* countCompar = NULL);
void SortBubble   (int data[], int size, int* countSwap = NULL, int* countCompar = NULL);
void SortInsert   (int data[], int size, int* countSwap = NULL, int* countCompar = NULL);
void SortShell    (int data[], int size, int* countSwap = NULL, int* countCompar = NULL);
void SortGnome    (int data[], int size, int* countSwap = NULL, int* countCompar = NULL);

void Swap (int data[], int size, int num1, int num2, int* countSwap = NULL);

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
int NumMinArray (int data[], int beginIndex, int endIndex, int* countCompar /*= NULL*/)
    {
    assert (0 <= beginIndex && beginIndex < endIndex);

    int numMin = beginIndex;

    for (int i = beginIndex; i < endIndex; i++)
        {
        assert (beginIndex <= i      && i      < endIndex);
        assert (beginIndex <= numMin && numMin < endIndex);

        if (countCompar) *countCompar += 1;

        if (data[i] < data[numMin])
            {
            numMin = i;
            }
        }

    return numMin;
    }

//-----------------------------------------------------------------------------
/*
                        параметр передан        параметр передан
                        в форме значения        в форме адреса

параметр нужно
передать                ничего не нужно            ставим *
в форме значения           f (param)             f (*param)

параметр нужно
дальше передать               &                 ничего не нужно
в форме адреса           f (&param)                  f (param)

 */
//-----------------------------------------------------------------------------
void SortExchange (int data[], int size, int* countSwap /*= NULL*/, int* countCompar/* = NULL*/)
    {
     for (int n = 0; n < size; n++)
        {
        int numMin = NumMinArray (data, n, size, countCompar);

        Swap(data, size, n, numMin, countSwap);
        }
    }


//-----------------------------------------------------------------------------
void Swap (int data[], int size, int num1, int num2, int* countSwap /*= NULL*/ )
    {
    assert (0 <= num1 && num1 < size);
    assert (0 <= num2 && num2 < size);

    int temp = data[num1];
    data[num1] = data [num2];
    data[num2] = temp;

    if (countSwap != NULL) *countSwap += 1;
    }

//-----------------------------------------------------------------------------
void SortBubble (int data[], int size, int* countSwap/*= NULL*/, int* countCompar/*= NULL*/)
    {
    for (int i = 0; i < size - 1; i++)
        {
        assert (i >= 0 && i < size - 1);

        int countSwapToday = 0;

        for (int j = 0; j < size - i - 1; j++)
            {
            assert (j     >= 0 && j     < size - i - 1);
            assert (j + 1 >= 0 && j + 1 < size - i);

            *countCompar += 1;

            if (data[j] > data [j + 1])
                {
                Swap(data, size, j, j+1, countSwap);

                countSwapToday += 1;
                }
            }

        if (countSwapToday == 0) break;
        }
    }


//-----------------------------------------------------------------------------
void SortInsert (int data[],int size, int* countSwap/*= NULL*/, int* countCompar/*= NULL*/)
    {
	for (int i = 1; i < size; i++)
        {
        assert (i >= 1 && i < size);

        for(int j = i; j > 0; j--)
            {
            assert (j     >= 0 && j     <= i);
            assert (j - 1 >= 0 && j - 1 <= i);

            *countCompar += 1;

            if (data[j-1] > data[j])  Swap(data, size, j, j-1, countSwap);
            }

        }
    }

//-----------------------------------------------------------------------------
void SortShell(int data[],int size, int* countSwap/*= NULL*/, int* countCompar/*= NULL*/)
    {
    int d = size / 2;

    while (d > 0)
        {
        for (int i = 0; i < size - d; i++)
            {
            int j = i;

            assert (j     >= 0 && j < size - d);
            assert (j + d >= 0 && j < size - d);

            while (j >= 0)
                {
                *countCompar += 1;

                if (data[j] > data[j + d])   Swap (data, size, j, j + d, countSwap);

                j--;
                }
            }

        d = d / 2;
        }
    }

//-----------------------------------------------------------------------------
void SortGnome(int data[], int size, int* countSwap/*= NULL*/, int* countCompar/*= NULL*/)
    {
    int i = 1;
    int j = 2;

    while (i < size)
        {
        assert (0 <= i - 1  && i - 1 < size);
        assert (0 <= i      && i     < size);

        *countCompar += 1;

        if (data[i - 1] <= data[i])
            {
            i = j;
            j = j + 1;
            }
        else
            {
            Swap (data, size, i - 1, i, countSwap);
            i --;
            if (i == 0)
                {
                i = j;
                j ++;
                }

            }
        }
    }

