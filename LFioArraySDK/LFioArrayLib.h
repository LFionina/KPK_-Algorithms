//{===========================================================================
//! @file       LFioArrayLib.h
//!
//!             ���������� ���������� ��������� ��������
//!
//!@author  (C) ������� ������� ����������, �. ������,
//!@date          2021
//!
//!@mainpage
//!   ���������� ���������� "�������"
//!
//!@par   ����������
//!
//!       ������ ���������� ���������� �� �������� �������, ������� ������������
//!     ��� ��������� ��������:
//!     - ����� ������� ����� � ������ �������;
//!     - ������� �������� ���������� ���������;
//!     - ������� ������������� ������� ����������.
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
//! ����� ��������� ������� �� ������� � �����.
//!
//! @param data[]   data[]  - ������ ��� ������
//! @param size     size    - ���������� ��������� � �������
//! @param title[]  title[] - ���������� �����
//! @param column   column  - ���������� ������� ��� ������ ���������
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


//{-----------------------------------------------------------------------------
//! ����������� ����� ������� � ���� ���������� ���������
//!
//! @param data[]      data[]    - ������ ��� ������
//! @param size        size      - ���������� ��������� � �������
//! @param index       index     - ������ ��������������� �����
//! @param colorSort   colorSort - ���� ��������������� �����
//! @param colorBase   colorBase - ���� ����������������� �����
//! @param widthRec    widthRec  - ������ ���������
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

