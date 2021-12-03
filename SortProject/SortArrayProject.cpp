# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

#include "SortArraySDK\SortArrayLib.h"

void Interface ();
void Button (int x, int y, const char num[], const char text[], int check, int red, int green, int blue);
void ButtonToScreen (int x, int num1, int num2, int num3, int num4, int num5);

void SortFileChange  (const char namefile[], int data[], int size, int sortType);

void AnalysisExchange (int data[], int sizeArray);
void AnalysisBubble   (int data[], int sizeArray);
void AnalysisInsert   (int data[], int sizeArray);
void AnalysisQuick    (int data[], int sizeArray);
void AnalysisShell    (int data[], int sizeArray);

void PointGraf (int countSwap, int countCompar, int n, COLORREF color);

//-----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1500, 800);

    Interface();

    const int sizeArray = 500;
    int data [sizeArray] = {};

    FillRandomArrayTest (data, sizeArray, 50);

    SortFileChange ("SortArraySDK\\files\\swap.txt",   data, sizeArray, 1 );
    SortFileChange ("SortArraySDK\\files\\bubble.txt", data, sizeArray, 2 );
    SortFileChange ("SortArraySDK\\files\\insert.txt", data, sizeArray, 3 );
    SortFileChange ("SortArraySDK\\files\\shell.txt",  data, sizeArray, 5 );

    while (!(txGetAsyncKeyState (VK_ESCAPE)))
        {
        if (txGetAsyncKeyState ('1'))
            {
            AnalysisExchange (data, sizeArray);
            }
        else if (txGetAsyncKeyState ('2'))
            {
            AnalysisBubble (data, sizeArray);
            }
        else if (txGetAsyncKeyState ('3'))
            {
            AnalysisInsert (data, sizeArray);
            }
        else if (txGetAsyncKeyState ('4'))
            {
            AnalysisQuick(data, sizeArray);
            }
        else if (txGetAsyncKeyState ('5'))
            {
            AnalysisShell(data, sizeArray);
            }

        else if (txGetAsyncKeyState ('0'))
            {
            Interface();
            }


        Sleep (10);
        }

    return 0;
    }

//-----------------------------------------------------------------------------
void PointGraf (int countSwap, int countCompar, int n, COLORREF color)
    {
    txSetColor (TX_WHITE, 2);
    if (n % 50 == 0 && n <= 1000)
        {
        txLine( 60 + 5*n, 730 - 4,  60 + 5*n, 730 + 4);
        txLine(795 + 5*n, 730 - 4, 795 + 5*n, 730 + 4);

        char str[10] = "";
        sprintf (str, "%d", n);

        txSelectFont ("Arial", 25);
        txDrawText   ( 60 + 5*n - 15, 740,  60 + 5*n + 5, 760, str);
        txDrawText   (795 + 5*n - 15, 740, 795 + 5*n + 5, 760, str);
        }

    //----- сравнения----------
    txSetColor (color);
    txSetFillColor (color);
   // if (730 - countCompar > 175 /*&& 60 + 5*n < 735*/)
        txCircle (60 + 5*n, 730 - countCompar/10, 3);

    //----- перестановки----------
    txSetColor (color);
    txSetFillColor (color);
   // if (730 - countSwap   > 175 /* && 795 + 5*n < 1455*/)
        txCircle (795 + 5*n, 730 - countSwap/10, 3);
    }


//-----------------------------------------------------------------------------
void AnalysisExchange(int data[], int sizeArray)
    {
    ButtonToScreen (30, -1, 1, 1, 1, 1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, sizeArray, 50);

        SortSwap (data, n, &countSwap, &countCompar);

        PointGraf (countSwap, countCompar, n, RGB(50, 230, 250));
        }
    }
//-----------------------------------------------------------------------------
void AnalysisBubble(int data[], int sizeArray)
    {
    ButtonToScreen (30, 1, -1, 1, 1, 1);

    for (int n1 = 1; n1 < sizeArray; n1++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, n1, 50);

        SortBubble (data, n1, &countSwap, &countCompar);

        PointGraf (countSwap, countCompar, n1, RGB(130, 180, 100));
        }

    printf("hello, i sorted\n");
    }
//-----------------------------------------------------------------------------
void AnalysisInsert(int data[], int sizeArray)
    {
    ButtonToScreen (30, 1, 1, -1, 1, 1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, sizeArray, 50);

        SortInsert (data, n, &countSwap, &countCompar);

        PointGraf (countSwap, countCompar, n, RGB(250, 100, 50));
        }
    }


//-----------------------------------------------------------------------------
void AnalysisQuick(int data[], int sizeArray)
    {
    ButtonToScreen (30, 1, 1, 1, -1, 1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 10;
        int countCompar = 10;
        FillRandomArrayTest (data, sizeArray, 50);

        //SortQuick (data, n, &countSwap, &countCompar);

        PointGraf (countSwap, countCompar, n, RGB(200, 100, 150));
        }
    }


//-----------------------------------------------------------------------------
void AnalysisShell(int data[], int sizeArray)
    {
    ButtonToScreen (30, 1, 1, 1, 1, -1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, sizeArray, 50);

        SortShell (data, n, &countSwap, &countCompar);

        PointGraf (countSwap, countCompar, n, RGB(240, 195, 50));
        }
    }

//-----------------------------------------------------------------------------
void SortFileChange (const char namefile[], int data[], int size, int sortType )
    {
    std::ofstream f;
    f.open(namefile);

    int n = 1;

    for (int i = 0; i < 10; i++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, size, 50);
        /*
        switch (sortType)
            {
            case 1:
              SortSwap   (data, n, &countSwap, &countCompar);
              break;
            case 2:
              SortBubble (data, n, &countSwap, &countCompar);
              break;
            case 3:
              SortInsert (data, n, &countSwap, &countCompar);
              break;
            }
         */

        if      (sortType == 1)   SortSwap   (data, n, &countSwap, &countCompar);
        else if (sortType == 2)   SortBubble (data, n, &countSwap, &countCompar);
        else if (sortType == 3)   SortInsert (data, n, &countSwap, &countCompar);
        else if (sortType == 5)   SortShell  (data, n, &countSwap, &countCompar);

        f << n << " " << countCompar << " " << countSwap << "\n";

        n += 1;
        }

    f.close();
    }

//-----------------------------------------------------------------------------
void Interface ()
    {
    txSetFillColor (RGB (191, 191, 191));
    txClear();

    txSetColor (RGB (191, 191, 191));
    txSetFillColor (RGB (10, 10, 10));
    txRectangle ( 30, 170,  735, 770);
    txRectangle (765, 170, 1470, 770);

    txSetColor (RGB (10, 10, 10));
    txSelectFont ("Arial Black", 50, 0, FW_BOLD);
    txDrawText   (100, 5, 1400, 65, "СОРТИРОВКА МАССИВОВ");

    ButtonToScreen (30, 1, 1, 1, 1, 1);

    txSetColor(TX_WHITE, 2);
    txLine ( 50, 730,  720, 730);
    txLine ( 60, 740,   60, 180);

    txLine (785, 730, 1455, 730);
    txLine (795, 740,  795, 180);

    txSelectFont ("Arial", 30);
    txDrawText ( 40, 740,   60, 760, "0");
    txDrawText (775, 740,  795, 760, "0");

    txSetColor (RGB(210, 210, 210));
    txSelectFont ("Arial", 30, 0, FW_BOLD);
    txDrawText ( 30, 180,  735, 210, "количество сравнений");
    txDrawText (765, 180, 1470, 210, "количество перестановок");
    }

//-----------------------------------------------------------------------------
void ButtonToScreen (int x, int num1, int num2, int num3, int num4, int num5)
    {
    Button (x,         80, "1", "Обмен",     num1,   0, 180, 200);
    Button (x + 1*230, 80, "2", "Пузырек",   num2,  80, 130,  50);
    Button (x + 2*230, 80, "3", "Вставками", num3, 200,  50,   0);
    Button (x + 3*230, 80, "4", "Быстрая",   num4, 150,  50, 100);
    Button (x + 4*230, 80, "5", "Шелла",     num5, 190, 145,   0);

    Button (1260, 80, "0", "Очистить",  1, 161, 161, 161);
    }

//{-----------------------------------------------------------------------------
//! check = 1 не нажата,   check = -1 нажата
//}-----------------------------------------------------------------------------
void Button (int x, int y, const char num[], const char text[], int check, int red, int green, int blue)
    {
    txSetColor (RGB (151, 151, 151), 2);
    txSetFillColor (RGB (121, 121, 121));
    txRectangle (x + 1 + check, y + 1 + check, x + 200 + 1 + check, y + 50 + 1 + check);

    txSetFillColor (RGB (141, 141, 141));
    txRectangle (x, y, x + 200, y + 50);
    txSetFillColor (RGB (red + (1 - check)*25, green + (1 - check)*25, blue + (1 - check)*25));
    txRectangle (x, y, x + 40, y + 50);

    txSetColor (RGB (161, 161, 161), 2);
    txLine (x + 40, y, x + 40 , y + 49);

    txSetColor (RGB (10, 10, 10));
    txSelectFont ("Arial", 30, 0, FW_BOLD);
    txDrawText   (x, y, x + 40, y + 50, num);
    txDrawText   (x + 45, y, x + 200, y + 50, text);
    }



/*fopen(), fclose(), fprintf(), fscanf(),
   fgetc(), fputc(), fgets(), fputs()
 */
