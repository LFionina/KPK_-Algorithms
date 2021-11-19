# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

#include "SortArraySDK\SortArrayLib.h"

void Interface ();
void Button (int x, int y, const char num[], const char text[], int check, int red, int green, int blue);
void ButtonToScreen (int x);

void SortFileChange  (const char namefile[], int data[], int size, int sortType);
void SortGraphChange (const char namefile[]);


//-----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1500, 800);

    Interface();

/*
    const int k = 100;
    int data [k] = {};

    FillRandomArrayTest (data, k, 50);

    SortFileChange ("SortArraySDK\\files\\swap.txt", data, k, 1 );
    SortFileChange ("SortArraySDK\\files\\bubble.txt", data, k, 2 );
    SortFileChange ("SortArraySDK\\files\\insert.txt", data, k, 3 );
    SortFileChange ("SortArraySDK\\files\\shell.txt", data, k, 5 );

    while (!(txGetAsyncKeyState (VK_ESCAPE)))
        {
        if (txGetAsyncKeyState ('1'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            ButtonCheck(20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("Cортировка обменом");

            SortGraphChange ("SortArraySDK\\files\\swap.txt");
            }

        else if (txGetAsyncKeyState ('2'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            ButtonCheck (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("Пузырьковая сортировка");

            SortGraphChange ("SortArraySDK\\files\\bubble.txt");

            }
        else if (txGetAsyncKeyState ('3'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            ButtonCheck (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("Cортировка вставками");

            SortGraphChange ("SortArraySDK\\files\\insert.txt");

            }
        else if (txGetAsyncKeyState ('4'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            ButtonCheck (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("/// сортировка");

            FillRandomArrayTest (data, k, 50);

            }
        else if (txGetAsyncKeyState ('5'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            ButtonCheck (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("Cортировка Шелла");

            SortGraphChange ("SortArraySDK\\files\\shell.txt");

            }
        else if (txGetAsyncKeyState ('0'))
            {
            Interface();
            }

        Sleep (10);
        }
    */
    return 0;
    }



//-----------------------------------------------------------------------------
void SortGraphChange (const char namefile[])
    {
    int x = 300; int y = 700;

    int yCount_2 = y;
    int yCountSwap_2 = y;
    int x2 = x + 10;

    int yCount_1 = y;
    int yCountSwap_1 = y;
    int x1 = x + 10;

    std::fstream f;
    f.open(namefile);

 /*fopen(), fclose(), fprintf(), fscanf(),
   fgetc(), fputc(), fgets(), fputs()
 */

    if (f)
        {
        while (!f.eof())
            {
            f >> x2 >> yCount_2 >> yCountSwap_2;

            txSetColor(TX_WHITE, 2);
            txLine (x + x2*15, y + 5, x + x2*15, y - 5);

            char str[10] = "";
            sprintf (str, "%d", x2);

            txSelectFont ("Arial", 25);
            txDrawText   (x + x2*15 - 15, 710, x + x2*15 + 15, 740, str);

            txSetColor(RGB(146, 208,  80), 3);
            txLine (x1, yCount_1,     x + x2*15, y - yCount_2/3);

            txSetColor(RGB(255, 102, 255), 3);
            txLine (x1, yCountSwap_1, x + x2*15, y - yCountSwap_2/3);

            x1  = x + x2*15;
            yCount_1 = y - yCount_2/3;

            yCountSwap_1 = y - yCountSwap_2/3;

            }
         }


    f.close();
    }

//-----------------------------------------------------------------------------
void SortFileChange (const char namefile[], int data[], int size, int sortType )
    {
    std::ofstream f;
    f.open(namefile);

    int n = 5;

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

        n += 5;
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

    ButtonToScreen (30, 3);

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
void ButtonToScreen (int x, int numButton)
    {
    Button (x,         80, "1", "Обмен",     1,   0, 180, 200);
    Button (x + 1*230, 80, "2", "Пузырек",   1,  80, 130,  50);
    Button (x + 2*230, 80, "3", "Вставками", 1, 200,  50,   0);
    Button (x + 3*230, 80, "4", "Быстрая",   1, 150,  50, 100);
    Button (x + 4*230, 80, "5", "Шелла",     1, 190, 145,   0);

    Button (1260, 80, "0", "Очистить",  1, 161, 161, 161);
    }

//-----------------------------------------------------------------------------
// check = 1 не нажата,   check = -1 нажата
//-----------------------------------------------------------------------------
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

