# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

#include "SortArraySDK\SortArrayLib.h"

//{-----------------------------------------------------------------------------
//!     структуры
//}-----------------------------------------------------------------------------

struct WindowSystemCoordinate
    {
    double xWindow;
    double yWindow;
    double sizeWindowX;
    double sizeWindowY;
    double indent;

    double x0, y0;

    double width;
    double height;

    char text[30];

    void Draw();
    };

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
struct Button
    {
    double x, y;
    double widthButton;
    double heightButton;

    char num[2];
    char text[10];

    int check;

    int red;
    int green;
    int blue;

    void Draw ();
    };

//{-----------------------------------------------------------------------------
//!     функции классов
//}-----------------------------------------------------------------------------
void WindowSystemCoordinate::Draw()
    {
    txSetColor (RGB (191, 191, 191));
    txSetFillColor (RGB (10, 10, 10));
    txRectangle (xWindow,  yWindow,  xWindow + sizeWindowX, yWindow - sizeWindowY);

    txSetColor(TX_WHITE, 2);
    txLine (xWindow + indent/2, y0,                 x0 + width, y0);          // OX
    txLine (x0,                 yWindow - indent/2, x0,          y0 - height); // OY


    txSelectFont ("Arial", indent*0.9);
    txDrawText (x0 - indent, y0,   x0, y0+indent, "0");


    txSetColor (RGB(210, 210, 210));
    txSelectFont ("Arial", indent, 0, FW_BOLD);
    txDrawText ( x0, y0 - height,  x0 + width, y0 - height + indent, text);
    }

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Button::Draw ()
    {

    txSetColor (RGB (151, 151, 151), 2);
    txSetFillColor (RGB (121, 121, 121));
    txRectangle (x + 1 + check,               y + 1 + check,
                 x + widthButton + 1 + check, y + heightButton + 1 + check);

    txSetFillColor (RGB (141, 141, 141));
    txRectangle (x, y, x + widthButton, y + heightButton);
    txSetFillColor (RGB (red + (1 - check)*25, green + (1 - check)*25, blue + (1 - check)*25));
    txRectangle (x, y, x + widthButton/5, y + heightButton);

    txSetColor (RGB (161, 161, 161), 2);
    txLine (x + widthButton/5, y, x + widthButton/5 , y + heightButton-1);

    txSetColor (RGB (10, 10, 10));
    txSelectFont ("Arial", heightButton*0.7-5, 0, FW_BOLD);
    txDrawText   (x, y, x + widthButton/5, y + heightButton, num);
    txDrawText   (x + widthButton/5+5, y, x + widthButton, y + heightButton, text);
    }

//=============================================================================

void Interface (double xWindow, double sizeWindowX,
                double yWindow, double sizeWindowY,
                double indent,
                double widthButton, double heightButton);

void DrawButtons (double x, double widthButton, double heigthButton, double indent,
                  int num1, int num2, int num3, int num4, int num5);

void SortFileChange  (const char namefile[], int data[], int size, int sortType);

void AnalysisExchange (int data[], int sizeArray, double xWindow,     double yWindow,
                                                  double widthButton, double heightButton,
                                                  double indent,      double scale,
                                                  double sizeWindowX);

void AnalysisBubble   (int data[], int sizeArray, double xWindow,     double yWindow,
                                                  double widthButton, double heightButton,
                                                  double indent,      double scale,
                                                  double sizeWindowX);

void AnalysisInsert   (int data[], int sizeArray, double xWindow,     double yWindow,
                                                  double widthButton, double heightButton,
                                                  double indent,      double scale,
                                                  double sizeWindowX);

void AnalysisGnome    (int data[], int sizeArray, double xWindow,     double yWindow,
                                                  double widthButton, double heightButton,
                                                  double indent,      double scale,
                                                  double sizeWindowX);

void AnalysisShell    (int data[], int sizeArray, double xWindow,     double yWindow,
                                                  double widthButton, double heightButton,
                                                  double indent,      double scale,
                                                  double sizeWindowX);

void AbscisMarker (int n, double x0, double y0, double sizeText, double scale);
void PointGraf (int count, int n, COLORREF color, double x0, double y0, double indent, double scale);

//-----------------------------------------------------------------------------
int main ()
    {
    const int sizeArray = 300;
    int data [sizeArray] = {};

    txCreateWindow (1500, 800);

    double xWindow = txGetExtentX () * 0.02;
    double sizeWindowX = (txGetExtentX () - txGetExtentX ()*0.06) / 2;

    double yWindow = txGetExtentY () - txGetExtentX () * 0.02;
    double sizeWindowY = txGetExtentY () -  txGetExtentY () * 0.2 - txGetExtentX () * 0.02;

    double indent = txGetExtentX () * 0.02;

    double widthButton  = (txGetExtentX () - indent*7) / 6 ;
    double heightButton = txGetExtentY () * 0.06 ;

    double scale = sizeWindowX / sizeArray;

    RECT areaSwap   = { ROUND(xWindow + 0*(widthButton + indent)), 80, ROUND(xWindow + 0*(widthButton + indent) + widthButton), 80 + ROUND(heightButton) };
    RECT areaBubble = { ROUND(xWindow + 1*(widthButton + indent)), 80, ROUND(xWindow + 1*(widthButton + indent) + widthButton), 80 + ROUND(heightButton) };
    RECT areaInsert = { ROUND(xWindow + 2*(widthButton + indent)), 80, ROUND(xWindow + 2*(widthButton + indent) + widthButton), 80 + ROUND(heightButton) };
    RECT areaGnome  = { ROUND(xWindow + 3*(widthButton + indent)), 80, ROUND(xWindow + 3*(widthButton + indent) + widthButton), 80 + ROUND(heightButton) };
    RECT areaShell  = { ROUND(xWindow + 4*(widthButton + indent)), 80, ROUND(xWindow + 4*(widthButton + indent) + widthButton), 80 + ROUND(heightButton) };
    RECT areaClear  = { ROUND(xWindow + 5*(widthButton + indent)), 80, ROUND(xWindow + 5*(widthButton + indent) + widthButton), 80 + ROUND(heightButton) };

    Interface(xWindow, sizeWindowX, yWindow, sizeWindowY, indent, widthButton, heightButton);

    FillRandomArrayTest (data, sizeArray, 50);

    SortFileChange ("SortArraySDK\\files\\swap.txt",   data, sizeArray, 1 );
    SortFileChange ("SortArraySDK\\files\\bubble.txt", data, sizeArray, 2 );
    SortFileChange ("SortArraySDK\\files\\insert.txt", data, sizeArray, 3 );
    SortFileChange ("SortArraySDK\\files\\shell.txt",  data, sizeArray, 5 );

    while (!(txGetAsyncKeyState (VK_ESCAPE)))
        {
        if ( areaSwap.left <= txMouseX() && txMouseX() <= areaSwap.right  &&
             areaSwap.top  <= txMouseY() && txMouseY() <= areaSwap.bottom && txMouseButtons() == 1 )           //(txGetAsyncKeyState ('1'))
            {
            AnalysisExchange (data, sizeArray, xWindow, yWindow, widthButton, heightButton, indent, scale, sizeWindowX);
            }

        else if ( areaBubble.left <= txMouseX() && txMouseX() <= areaBubble.right  &&
                  areaBubble.top  <= txMouseY() && txMouseY() <= areaBubble.bottom && txMouseButtons() == 1 )  //(txGetAsyncKeyState ('2'))
            {
            AnalysisBubble   (data, sizeArray, xWindow, yWindow, widthButton, heightButton, indent, scale, sizeWindowX);
            }

        else if ( areaInsert.left <= txMouseX() && txMouseX() <= areaInsert.right  &&
                  areaInsert.top  <= txMouseY() && txMouseY() <= areaInsert.bottom && txMouseButtons() == 1 )    //(txGetAsyncKeyState ('3'))
            {
            AnalysisInsert   (data, sizeArray, xWindow, yWindow, widthButton, heightButton, indent, scale, sizeWindowX);
            }

        else if ( areaGnome.left <= txMouseX() && txMouseX() <= areaGnome.right  &&
                  areaGnome.top  <= txMouseY() && txMouseY() <= areaGnome.bottom && txMouseButtons() == 1 )     //(txGetAsyncKeyState ('4'))
            {
            AnalysisGnome    (data, sizeArray, xWindow, yWindow, widthButton, heightButton, indent, scale, sizeWindowX);
            }

        else if ( areaShell.left <= txMouseX() && txMouseX() <= areaShell.right  &&
                  areaShell.top  <= txMouseY() && txMouseY() <= areaShell.bottom && txMouseButtons() == 1 )     //(txGetAsyncKeyState ('5'))
            {
            AnalysisShell    (data, sizeArray, xWindow, yWindow, widthButton, heightButton, indent, scale, sizeWindowX);
            }

        else if ( areaClear.left <= txMouseX() && txMouseX() <=  areaClear.right &&
                  areaClear.top  <= txMouseY() && txMouseY() <= areaClear.bottom && txMouseButtons() == 1 )     //(txGetAsyncKeyState ('0'))
            {
            Interface (xWindow, sizeWindowX, yWindow, sizeWindowY, indent, widthButton, heightButton);
            }


        Sleep (10);
        }

    return 0;
    }


//-----------------------------------------------------------------------------
void AbscisMarker (int n, double x0, double y0, double sizeText, double scale)
    {
    txSetColor (TX_WHITE, 2);

    txLine(x0 + scale*n, y0 - 4,  x0 + scale*n, y0 + 4);

    char str[10] = "";
    sprintf (str, "%d", n);

    txSelectFont ("Arial", sizeText);
    txDrawText   (x0 + scale*n - 15, y0 + 5,  x0 + scale*n + 15, y0 + sizeText, str);
    }

//-----------------------------------------------------------------------------
void PointGraf (int count, int n, COLORREF color, double x0, double y0, double indent, double scale)
    {
    double sizeWinX    = (txGetExtentX () - txGetExtentX ()*0.06) / 2 - 5;
    double sizeWinY    = (txGetExtentY() - txGetExtentY()*0.2 - txGetExtentX()*0.02);
    double borderRight = x0 - indent + sizeWinX;

    txSetColor (TX_WHITE, 2);
    if (x0 + scale*n <= borderRight)
        {
        if (n % 50 == 0)  AbscisMarker (n, x0, y0, indent-8, scale);

        txSetColor (color);
        txSetFillColor (color);

        if (y0 - count/10 >=  y0 - sizeWinY + indent + 10)
            {
            txCircle (x0 + scale*n, y0 - count/10, 3);
            }
        }
    }

//-----------------------------------------------------------------------------
void AnalysisExchange(int data[], int sizeArray, double xWindow,     double yWindow,
                                                 double widthButton, double heightButton,
                                                 double indent,      double scale,
                                                 double sizeWindowX)
    {
    DrawButtons (xWindow, widthButton, heightButton, indent, -1, 1, 1, 1, 1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, sizeArray, 50);

        SortExchange (data, n, &countSwap, &countCompar);

        PointGraf (countSwap,   n, RGB(50, 230, 250), xWindow + indent, yWindow - indent, indent, scale);
        PointGraf (countCompar, n, RGB(50, 230, 250), xWindow + sizeWindowX + 2*indent, yWindow - indent, indent, scale);
        }
    }

//-----------------------------------------------------------------------------
void AnalysisBubble(int data[], int sizeArray, double xWindow,     double yWindow,
                                               double widthButton, double heightButton,
                                               double indent,      double scale,
                                               double sizeWindowX)
    {
    DrawButtons (xWindow, widthButton, heightButton, indent, 1, -1, 1, 1, 1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, n, 50);

        SortBubble (data, n, &countSwap, &countCompar);

        PointGraf (countSwap,   n, RGB(130, 180, 100), xWindow + indent, yWindow - indent, indent, scale);
        PointGraf (countCompar, n, RGB(130, 180, 100), xWindow + sizeWindowX + 2*indent, yWindow - indent, indent, scale);
        }
    }
//-----------------------------------------------------------------------------
void AnalysisInsert(int data[], int sizeArray, double xWindow,     double yWindow,
                                               double widthButton, double heightButton,
                                               double indent,      double scale,
                                               double sizeWindowX)
    {
    DrawButtons (xWindow, widthButton, heightButton, indent, 1, 1, -1, 1, 1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, sizeArray, 50);

        SortInsert (data, n, &countSwap, &countCompar);

        PointGraf (countSwap,   n, RGB(250, 100, 50), xWindow + indent,                 yWindow - indent, indent, scale);
        PointGraf (countCompar, n, RGB(250, 100, 50), xWindow + sizeWindowX + 2*indent, yWindow - indent, indent, scale);
        }
    }


//-----------------------------------------------------------------------------
void AnalysisGnome(int data[], int sizeArray, double xWindow,     double yWindow,
                                              double widthButton, double heightButton,
                                              double indent,      double scale,
                                              double sizeWindowX)
    {
    DrawButtons (xWindow, widthButton, heightButton, indent, 1, 1, 1, -1, 1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 0;
        int countCompar = 0;

        FillRandomArrayTest (data, sizeArray, 50);

        SortGnome    (data, n, &countSwap, &countCompar);

        PointGraf (countSwap,   n, RGB(200, 100, 150), xWindow + indent,               yWindow - indent, indent, scale);
        PointGraf (countCompar, n, RGB(200, 100, 150), xWindow + sizeWindowX + 2*indent, yWindow - indent, indent, scale);
        }
    }


//-----------------------------------------------------------------------------
void AnalysisShell(int data[], int sizeArray, double xWindow,     double yWindow,
                                              double widthButton, double heightButton,
                                              double indent,      double scale,
                                              double sizeWindowX)
    {
    DrawButtons (xWindow, widthButton, heightButton, indent, 1, 1, 1, 1, -1);

    for (int n = 1; n < sizeArray; n++)
        {
        int countSwap = 0;
        int countCompar = 0;
        FillRandomArrayTest (data, sizeArray, 50);

        SortShell (data, n, &countSwap, &countCompar);

        PointGraf (countSwap,   n, RGB(240, 195, 50), xWindow + indent, yWindow - indent, indent, scale);
        PointGraf (countCompar, n, RGB(240, 195, 50), xWindow + sizeWindowX + 2*indent, yWindow - indent, indent, scale);
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


        if      (sortType == 1)   SortExchange (data, n, &countSwap, &countCompar);
        else if (sortType == 2)   SortBubble   (data, n, &countSwap, &countCompar);
        else if (sortType == 3)   SortInsert   (data, n, &countSwap, &countCompar);
        else if (sortType == 5)   SortShell    (data, n, &countSwap, &countCompar);

        f << n << " " << countCompar << " " << countSwap << "\n";

        n += 1;
        }

    f.close();
    }

//-----------------------------------------------------------------------------

void Interface (double xWindow, double sizeWindowX, double yWindow, double sizeWindowY, double indent, double widthButton, double heightButton)
    {
    txSetFillColor (RGB (191, 191, 191));
    txClear();

    txSetColor (RGB (191, 191, 191));
    txSetFillColor (RGB (10, 10, 10));

    WindowSystemCoordinate windowCompar = { xWindow,
                                            yWindow,
                                            sizeWindowX,
                                            sizeWindowY,
                                            indent,
                                            xWindow + indent,
                                            yWindow - indent,
                                            sizeWindowX - 1.5*indent,
                                            sizeWindowY - 1.5*indent,
                                            "количество сравнений" };
    windowCompar.Draw();

    WindowSystemCoordinate windowSwap   = { xWindow + sizeWindowX + indent,
                                            yWindow,
                                            sizeWindowX,
                                            sizeWindowY,
                                            indent,
                                            xWindow + sizeWindowX + 2*indent,
                                            yWindow - indent,
                                            sizeWindowX - 1.5*indent,
                                            sizeWindowY - 1.5*indent,
                                            "количество перестановок" };
    windowSwap.Draw();

    txSetColor (RGB (10, 10, 10));
    txSelectFont ("Arial Black", indent*1.7, 0, FW_BOLD);
    txDrawText   (txGetExtentX()/5, 5, txGetExtentX() - txGetExtentX()/5, 5 + indent*1.7, "СОРТИРОВКА МАССИВОВ");

    DrawButtons (xWindow, widthButton, heightButton, indent, 1, 1, 1, 1, 1);

    }


//-----------------------------------------------------------------------------
void DrawButtons (double x, double widthButton, double heightButton, double indent, int num1, int num2, int num3, int num4, int num5)
    {
    Button btnSwap   = {x + 0*(widthButton+indent), 80, widthButton, heightButton, "1", "Обмен",     num1,   0, 180, 200};
    Button btnBubble = {x + 1*(widthButton+indent), 80, widthButton, heightButton, "2", "Пузырек",   num2,  80, 130,  50};
    Button btnInsert = {x + 2*(widthButton+indent), 80, widthButton, heightButton, "3", "Вставками", num3, 200,  50,   0};
    Button btnQuick  = {x + 3*(widthButton+indent), 80, widthButton, heightButton, "4", "Гномья",   num4, 150,  50, 100};
    Button btnShell  = {x + 4*(widthButton+indent), 80, widthButton, heightButton, "5", "Шелла",     num5, 190, 145,   0};

    btnSwap.Draw ();
    btnBubble.Draw ();
    btnInsert.Draw ();
    btnQuick.Draw ();
    btnShell.Draw ();

    Button btnClear = {x + 5*(widthButton+indent), 80, widthButton, heightButton, "0", "Очистить",  1, 161, 161, 161};
    btnClear.Draw ();
    }




/*fopen(), fclose(), fprintf(), fscanf(),
   fgetc(), fputc(), fgets(), fputs()
 */
