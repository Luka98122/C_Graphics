#include "libs\raylib\raylib.h"
#include <stdio.h>
#include <cstdlib>
#include <time.h>

struct particle {
    float x;
    float y;
    Color col;
    float dx;
    float dy;

};

void particle_Update(particle *entity) {
    entity->x = entity->x + entity->dx;
    entity->y = entity->y + entity->dy;

}

float frand() {
    return 0.0f;
}



void drawRect(int x, int y, int w, int h, Color col) {
    for (int i = x;i < (x + w);i++) {
        for (int j = y;j < (y + h);j++) {
            DrawPixel((int)(i), (int)(j), col);
        }
    }
}

void particle_Draw(particle entity) {
    //drawRect(entity.x, entity.y, 3, 3, entity.col);
    DrawPixel(entity.x, entity.y, entity.col);
}

int main(void)
{
    const int WIDTH = 800;
    const int HEIGHT = 450;

    const float maxDX = 5;
    const float maxDY = 5;

    Color colors[10] = {RED,BLUE,GREEN,RAYWHITE,GRAY,PURPLE,YELLOW,PINK,BROWN,BLACK};

    srand(time(nullptr));

    particle particles[10000];
    for (int i = 0;i < 10000;i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;

        float dx = (rand() %1000 )/1000.0f;
        dx = (rand() % 2) ? -dx : dx;

        float dy = (rand() % 1000) / 1000.0f;
        dy = (rand() % 2) ? -dy : dy;

        if (dy > 0) {
            int a = 2;
        }

        dx = fmod(dx, maxDX);
        dy = fmod(dy, maxDY);

        int numColor = rand() % 10;

        particle current;
        current.col = colors[numColor];
        current.x = x;
        current.y = y;
        current.dx = dx;
        current.dy = dy;
        particles[i] = current;
    }


    InitWindow(WIDTH,HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw Sprites
        for (int i = 0;i < 10000;i++) {
            particle_Update(&particles[i]);
            particle_Draw(particles[i]);
        }
        //printf("Hi!\n");

        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}