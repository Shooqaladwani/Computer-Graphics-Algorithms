#include <graphics.h>
#include <windows.h>

void circlePlot(int xc, int yc, int x, int y)
{
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void midpointCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    circlePlot(xc, yc, x, y);

    while (x < y)
    {
        x++;

        if (p < 0)
            p = p + 2 * x + 1;
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }

        circlePlot(xc, yc, x, y);
    }
}

void drawSun()
{
    midpointCircle(575, 65, 35);
    setfillstyle(SOLID_FILL, YELLOW);
    floodfill(575, 65, WHITE);
}

void drawRoad()
{
    setcolor(WHITE);

    rectangle(0, 310, 639, 360);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(10, 320, WHITE);

    rectangle(0, 360, 639, 479);
    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(10, 370, WHITE);

    for (int i = 20; i < 639; i += 80)
        line(i, 420, i + 40, 420);
}

void drawBuilding()
{
    setcolor(WHITE);

    rectangle(100, 90, 470, 310);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    floodfill(110, 100, WHITE);

    line(100, 90, 285, 40);
    line(285, 40, 470, 90);
    line(100, 90, 470, 90);

    setfillstyle(SOLID_FILL, RED);
    floodfill(285, 70, WHITE);

    rectangle(230, 120, 340, 144);
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(235, 125, WHITE);

    setcolor(BLACK);
    char universityText[] = "UNIVERSITY";
    outtextxy(242, 125, universityText);
    setcolor(WHITE);

    rectangle(250, 235, 310, 310);
    setfillstyle(SOLID_FILL, BROWN);
    floodfill(255, 240, WHITE);

    rectangle(230, 170, 240, 310);
    rectangle(320, 170, 330, 310);

    setfillstyle(SOLID_FILL, WHITE);
    floodfill(235, 175, WHITE);
    floodfill(325, 175, WHITE);

    rectangle(120, 130, 150, 160);
    rectangle(170, 130, 200, 160);
    rectangle(360, 130, 390, 160);
    rectangle(410, 130, 440, 160);

    rectangle(120, 190, 150, 220);
    rectangle(170, 190, 200, 220);
    rectangle(360, 190, 390, 220);
    rectangle(410, 190, 440, 220);

    setfillstyle(SOLID_FILL, CYAN);
    floodfill(125, 135, WHITE);
    floodfill(175, 135, WHITE);
    floodfill(365, 135, WHITE);
    floodfill(415, 135, WHITE);

    floodfill(125, 195, WHITE);
    floodfill(175, 195, WHITE);
    floodfill(365, 195, WHITE);
    floodfill(415, 195, WHITE);
}
void drawParking()
{
    setcolor(WHITE);

    rectangle(500, 245, 635, 310);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(510, 250, WHITE);

    line(535, 245, 535, 310);
    line(570, 245, 570, 310);
    line(605, 245, 605, 310);

    rectangle(525, 220, 610, 245);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(530, 225, WHITE);

    setcolor(WHITE);
    char parkingText[] = "PARKING";
    outtextxy(540, 227, parkingText);
}

void drawStudent(int x, int y)
{
    setcolor(WHITE);

    midpointCircle(x, y, 6);
    line(x, y + 6, x, y + 28);
    line(x, y + 14, x - 10, y + 23);
    line(x, y + 14, x + 10, y + 23);
    line(x, y + 28, x - 9, y + 42);
    line(x, y + 28, x + 9, y + 42);
}

void drawBus(int x)
{
    setcolor(WHITE);

    rectangle(x, 375, x + 80, 415);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(x + 5, 380, WHITE);

    rectangle(x + 10, 385, x + 28, 398);
    rectangle(x + 35, 385, x + 53, 398);
    rectangle(x + 60, 385, x + 75, 398);

    setfillstyle(SOLID_FILL, CYAN);
    floodfill(x + 15, 390, WHITE);
    floodfill(x + 40, 390, WHITE);
    floodfill(x + 65, 390, WHITE);

    circle(x + 20, 412, 8);
    circle(x + 65, 412, 8);

    setfillstyle(SOLID_FILL, DARKGRAY);
    floodfill(x + 20, 412, WHITE);
    floodfill(x + 65, 412, WHITE);
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int busX = -80;
    int page = 0;

    while (true)
    {
        setactivepage(page);
        setvisualpage(1 - page);

        setbkcolor(LIGHTBLUE);
        cleardevice();

        drawSun();
        drawRoad();
        drawBuilding();
        drawParking();
        drawBus(busX);
        drawStudent(390, 315);

        busX += 5;

        if (busX > 640)
            busX = -80;

        page = 1 - page;

        Sleep(50);
    }

    closegraph();
    return 0;
}