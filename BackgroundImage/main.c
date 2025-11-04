#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>

#define IMG "assets/img/"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Background image");    
    SetTargetFPS(144);
    SetConfigFlags(FLAG_VSYNC_HINT);

    Texture2D background_texture = LoadTexture(IMG "background.jpg");

    int monitor = GetCurrentMonitor();
    int monitor_width = GetMonitorWidth(monitor);
    int monitor_height = GetMonitorHeight(monitor);
    
    while(WindowShouldClose() == false) {
        if(IsKeyPressed(KEY_F11) == true) {
            /* 
             * funkce ToggleFullscreen neaktualizuje velikost okna, to způsobí
             * že se poměry stran obrázku rozhodí
             * proto je třeba nastavit i rozměr okna
             */ 
            //ToggleFullscreen();
            if(IsWindowState(FLAG_FULLSCREEN_MODE) == false) {
                SetWindowSize(monitor_width, monitor_height); 
                SetWindowState(FLAG_FULLSCREEN_MODE);
            } else {
                SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
                ClearWindowState(FLAG_FULLSCREEN_MODE);
            }

        }

        printf("%dx%d\n", GetScreenWidth(), GetScreenHeight());
        BeginDrawing();
        ClearBackground(WHITE);
        
        if(IsWindowState(FLAG_FULLSCREEN_MODE) == false) {
            DrawTexturePro(
                    background_texture
                    , (Rectangle) {0, 0, background_texture.width, background_texture.height}
                    , (Rectangle) {0, 0, GetScreenWidth(), GetScreenHeight()}
                    , (Vector2) {0, 0}
                    , 0
                    , WHITE);
        } else {
            DrawTexturePro(
                    background_texture
                    , (Rectangle) {0, 0, background_texture.width, background_texture.height}
                    , (Rectangle) {0, 0, monitor_width, monitor_height}
                    , (Vector2) {0, 0}
                    , 0
                    , WHITE);
        }
        
        DrawFPS(10, 10);
        EndDrawing();
    }

    UnloadTexture(background_texture);
    CloseWindow();

    printf("program exit..\n");
    return EXIT_SUCCESS;
}


