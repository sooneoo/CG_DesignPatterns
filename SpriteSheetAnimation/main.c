#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>


#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define FPS 30


int main(void) {
    InitWindow(WIN_WIDTH, WIN_HEIGHT, "Sprite sheet animation");
    SetTargetFPS(FPS);

    // load texture
    Texture2D scarfy = LoadTexture("scarfy.png");

    // position of the animation
    Vector2 position = { 0.0f, 280.0f };
    Rectangle frameRec = { 0.0f, 0.0f, (float)scarfy.width/6, (float)scarfy.height };
    int currentFrame = 0;

    // animation control
    int framesCounter = 0;
    int framesSpeed = 8;
    int direction = 1;

    while(WindowShouldClose() == false) {
        framesCounter++;

        //sprite sheet frame rate control
        if (framesCounter >= (FPS/framesSpeed)) {

            //direction of the animation move
            if(direction > 0) {
                currentFrame = (currentFrame + 1) % 6;

                if(position.x > (WIN_WIDTH - scarfy.width/6)) {
                    direction *= -1;
                    frameRec.width *= -1;
                } 

            } else {
                if(currentFrame == 0) {
                    currentFrame = 5;
                } else {
                    currentFrame = currentFrame - 1;
                }

                if(position.x < 0) {
                    frameRec.width *= -1;
                    direction *= -1;
                }
            }

            frameRec.x = (float)currentFrame*(float)scarfy.width/6;
            framesCounter = 0;
        }

        position.x += framesSpeed * direction;

        BeginDrawing();
        ClearBackground(WHITE);
        DrawTexture(scarfy, 0,0, WHITE);


        DrawTextureRec(scarfy, frameRec, position, WHITE);
        EndDrawing();
    }

    UnloadTexture(scarfy);
    CloseWindow();

    printf("program exit..\n");
    return EXIT_SUCCESS;
}

