#include <graphics.h>
#include <stdio.h>

void drawHouse()
{
    setfillstyle(SOLID_FILL, WHITE);
    bar(150, 300, 450, 550);

    setfillstyle(SOLID_FILL, LIGHTRED);
    int roofPoints[8] = {150, 300, 300, 200, 450, 300, 150, 300};
    fillpoly(4, roofPoints);

    setfillstyle(SOLID_FILL, BROWN);
    bar(250, 400, 350, 550);

    setfillstyle(SOLID_FILL, BROWN);
    bar(200, 400, 240, 440);
    bar(360, 400, 400, 440);
    bar(200, 480, 240, 520);
    bar(360, 480, 400, 520);
}

void drawCar()
{
    setfillstyle(SOLID_FILL, RED);
    bar(100, 440, 200, 500);

    setfillstyle(SOLID_FILL, LIGHTBLUE);
    bar(110, 450, 150, 490);
    bar(160, 450, 190, 490);
}

void drawSky(int color)
{
    int skyHeight = getmaxy() * 0.8;

    setfillstyle(SOLID_FILL, color);
    bar(0, 0, getmaxx(), skyHeight);

    if (color == LIGHTBLUE)
    {
        setcolor(YELLOW);
        setfillstyle(SOLID_FILL, YELLOW);
        fillellipse(100, 100, 40, 40); // Draw sun
    }
    else if (color == BLUE)
    {
        setcolor(WHITE);
        setfillstyle(SOLID_FILL, WHITE);
        fillellipse(100, 100, 40, 40);
    }

    setfillstyle(SOLID_FILL, LIGHTGREEN);

    int mountain1[8] = {0, skyHeight, 200, skyHeight - 300, 400, skyHeight, 0, skyHeight};
    fillpoly(4, mountain1);

    int mountain2[8] = {200, skyHeight, 400, skyHeight - 300, 600, skyHeight, 200, skyHeight};
    fillpoly(4, mountain2);

    int mountain3[8] = {400, skyHeight, 600, skyHeight - 300, 800, skyHeight, 400, skyHeight};
    fillpoly(4, mountain3);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int skyColor = LIGHTBLUE;
    
    drawSky(skyColor);
    drawHouse();
    drawCar();

    getch();
    closegraph();
    return 0;
}
