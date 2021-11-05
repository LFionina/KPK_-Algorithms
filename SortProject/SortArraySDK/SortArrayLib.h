//{===========================================================================
//! @file       SortArrayLib.h
//!
//!             ���������� ���������� ���������� ��������
//!
//!@author  (C) ������� ������� ����������, �. ������,
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
//! ������ ������ ���������� ������� �� ��������� [-a, a].
//!
//! @param data[]    data[] - ���������� ������
//! @param sizeFont  size   - ������ ������� (���������� ���������)
//! @param range     range  - ����� ���������
//!
//! @par  ������ �������������:
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
//! ������ ������ ���������� �������, ��� ��������� ����� = ������� �������� � �������.
//!
//! @param data[]    data[] - ���������� ������
//! @param sizeFont  size   - ������ ������� (���������� ���������)
//! @param range     range  - ����� ��� ������� ���������� �����
//!
//! @par  ������ �������������:
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
//! ����� ��������� ������� �� �������.
//!
//! @param data[]   data[]  - ������ ��� ������
//! @param size     size    - ���������� ��������� � �������
//! @param title[]  title[] - ���������� �����
//! @param column   column  - ���������� ������� ��� ������ ���������
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
//! ����� ������� ������������� �������� �������.
//!
//! @param data[]   data[]  - ������ ��� ������
//! @param size     size    - ���������� ��������� � �������
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
//! ����� ������� ������������ �������� �������.
//!
//! @param data[]   data[]  - ������ ��� ������
//! @param size     size    - ���������� ��������� � �������
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
