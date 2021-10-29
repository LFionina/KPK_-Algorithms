//{===========================================================================
//! @file       LFioArrayLib.h
//!
//!             Библиотека алгоритмов обработки Массивов
//!
//!@author  (C) Фионина Людмила Евгеньевна, г. Самара,
//!@date          2021
//!
//!@mainpage
//!   БИБЛИОТЕКА АЛГОРИТМОВ "МАССИВЫ"
//!
//!@par   Назначение
//!
//!       Данная библиотека составлена из основных функций, которые используются
//!     для обработки массивов:
//!     - общие функции ввода и вывода массива;
//!     - функции основных алгоритмов обработки;
//!     - примеры использования функций библиотеки.
//!
//}===========================================================================

#include "TXLib.h"

void FillRandomArray     (int data[], int size, int range);
void FillRandomArrayTest (int data[], int size, int range);
void PrintArray      (int data[], int size, const char title[], int column);
void PrintArrayColor (int data[], int size, int index, int column);

int NumMinArray (int data[], int beginIndex, int endIndex);
int NumMaxArray (int data[], int beginIndex, int endIndex);

void GraphicArray (int data[], int size, int index, COLORREF colorSort, COLORREF colorBase, double widthRec);

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
//! Вывод элементов массива на консоль в цвете.
//!
//! @param data[]   data[]  - массив для вывода
//! @param size     size    - количество элементов в массиве
//! @param title[]  title[] - поясняющий текст
//! @param column   column  - количество колонок для вывода элементов
//!
//}-----------------------------------------------------------------------------
void PrintArrayColor (int data[], int size, int index, int column)
    {
    for (int i = 0; i < size; i++)
        {
        if (i % column == 0) printf ("\n");

        if (i < index)     { $m; printf ("[%2d] = ",i); printf ("%4d",data[i]); }
        else               { $c; printf ("[%2d] = ",i); $g; printf ("%4d",data[i]); }

        if (i != size - 1) { $c; printf (", ");}

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


//{-----------------------------------------------------------------------------
//! Графический вывод массива в виде столбчатой диаграммы
//!
//! @param data[]      data[]    - массив для вывода
//! @param size        size      - количество элементов в массиве
//! @param index       index     - индекс отсортированной части
//! @param colorSort   colorSort - цвет отсортированной части
//! @param colorBase   colorBase - цвет неотсортированной части
//! @param widthRec    widthRec  - ширина столбиков
//!
//}-----------------------------------------------------------------------------
void GraphicArray (int data[], int size, int index, COLORREF colorSort, COLORREF colorBase, double widthRec)
    {
    txSelectFont ("Arial", 30);

    for (int i = 0; i < size; i++)
        {
        char str[1];
        sprintf (str, "%d", i);
        txDrawText   (50 + i*widthRec, 750, 50 + i*widthRec + (widthRec - 5), 790, str);
        }

    for (int i = 0; i < size; i++)
        {
        char str[1];
        sprintf (str, "%d", i);

        if (i < index)
            {
            txSetColor (colorSort, 2);
            txSetFillColor (colorSort);
            txRectangle(50 + i*widthRec, 750, 50 + i*widthRec + (widthRec - 5), 750 - data[i]/10);
            txDrawText   (50 + i*widthRec, 750, 50 + i*widthRec + (widthRec - 5), 790, str);
            }
        else
            {
            txSetColor (colorBase, 2);
            txSetFillColor (colorBase);
            txRectangle(50 + i*widthRec, 750, 50 + i*widthRec + (widthRec - 5), 750 - data[i]/10);
            txDrawText   (50 + i*widthRec, 750, 50 + i*widthRec + (widthRec - 5), 790, str);
            }

        }
    }

