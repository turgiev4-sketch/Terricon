#include "Engine.h"


enum E_Brick_type
{
    EBT_None,
    EBT_Yellow,
    EBT_red
};

HPEN Brick_Red_pen, Brick_Yellow_pen;
HBRUSH Brick_Red_Brush, Brick_Yellow_Brush;

const int Global_Scale = 3;
const int Height = 7;
const int Whight = 15;
const int Cell_Height = 8;
const int Cell_Whight = 16;
const int Level_X_Offset = 58;
const int Level_Y_Offset = 8;
const int Circle_Size = 6;
int Inner_Wight = 21;

char level_01[14][12] =
{
    2,2,0,0,0,0,0,0,0,0,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,
    1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,

};


void Init()
// Настройка при старте
{
    Brick_Yellow_pen = CreatePen(PS_SOLID, 0, RGB(224, 176, 16));
    Brick_Yellow_Brush = CreateSolidBrush(RGB(224, 176, 16));
    Brick_Red_pen = CreatePen(PS_SOLID, 0, RGB(224, 48, 32));
    Brick_Red_Brush = CreateSolidBrush(RGB(224, 48, 32));
}


void Draw_Brick(HDC hdc, int x, int y, E_Brick_type brick_type) {
    // Вывод кирпича          

    HPEN pen;
    HBRUSH brush;

    switch (brick_type)
    {
    case EBT_None:
    {
        return;
    }
    case EBT_Yellow:
    {
        pen = Brick_Yellow_pen;
        brush = Brick_Yellow_Brush;

        SelectObject(hdc, pen);
        SelectObject(hdc, brush);

        RoundRect(hdc, x * Global_Scale, y * Global_Scale, (x + Whight) * Global_Scale, (y + Height) * Global_Scale, 7, 7);
        break;
    }
    case EBT_red:
    {
        pen = Brick_Red_pen;
        brush = Brick_Red_Brush;

        SelectObject(hdc, pen);
        SelectObject(hdc, brush);

        RoundRect(hdc, x * Global_Scale, y * Global_Scale, (x + Whight) * Global_Scale, (y + Height) * Global_Scale, 7, 7);
        break;
    }
    }
}


void Draw_Level(HDC hdc)
{ // Вывод всех кирпичей уровня

    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            Draw_Brick(hdc, Level_X_Offset + j * Cell_Whight, Level_Y_Offset + i * Cell_Height, (E_Brick_type)level_01[i][j]);
        }
    }
}

void Draw_Platform(HDC hdc,int x,int y)
{ // Отрисовка платформы

    SelectObject(hdc, Brick_Red_pen);
    SelectObject(hdc, Brick_Red_Brush);

    Ellipse(hdc, x * Global_Scale, y * Global_Scale, (x + Circle_Size) * Global_Scale, (y + Circle_Size) * Global_Scale);
    Ellipse(hdc, (x + Inner_Wight) * Global_Scale, y * Global_Scale, (x + Circle_Size + Inner_Wight) * Global_Scale, (y + Circle_Size) * Global_Scale);

    SelectObject(hdc, Brick_Yellow_pen);
    SelectObject(hdc, Brick_Yellow_Brush);

    RoundRect(hdc, (x + 3) * Global_Scale, y * Global_Scale, (x + 4 + Inner_Wight - 1) * Global_Scale, (y + 1 + 5) * Global_Scale, 7, 7);
}

void Draw_Frame(HDC hdc)
{ // Отрисовка экрана игры

    Draw_Level(hdc);
    Draw_Platform(hdc, 100, 190);
    
   
}