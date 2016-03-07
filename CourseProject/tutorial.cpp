#include <stdio.h>

#include "Texture.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGTH = 600;
const char* TITLE = "SDL Lessons";

bool init();
bool load();
void close();

SDL_Surface* loadSurface(FILE_PATH path);//

SDL_Window *window = nullptr;
SDL_Renderer *renderer = nullptr;

const int ANIMATION_FRAMES = 4;
Texture SpriteSheetTexture;
SDL_Rect spriteClips[ANIMATION_FRAMES];

SDL_Surface *windowSurface = nullptr;//

SDL_Surface* loadSurface(FILE_PATH path)
{
    SDL_Surface *loadedSurface = nullptr;
    SDL_Surface *optimizedSurface = nullptr;

    loadedSurface = IMG_Load(path);
    if (loadedSurface == nullptr) {
        return nullptr;
    }

    optimizedSurface = SDL_ConvertSurface(loadedSurface, windowSurface->format, NULL);
    if (optimizedSurface == nullptr) {
        return nullptr;
    }

    SDL_FreeSurface(loadedSurface);
    
    return optimizedSurface;
}

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error SDL initialization. %s", SDL_GetError());
        return false;
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        printf("Error IMG initialization. %s", IMG_GetError());
        return false;
    }

    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGTH, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        printf("Error. Couldn't create window. %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        printf("Error. Couldn't create renderer. %s", SDL_GetError());
        return false;
    }
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    windowSurface = SDL_GetWindowSurface(window);
    return true;
}

bool load()
{
    SDL_Color color = { 0, 0xFF, 0xFF, 0xFF };
    if (!SpriteSheetTexture.loadTexture(renderer, "foo.png", &color)) {
        printf("Error. Couldn't load image. %s", SDL_GetError());
        return false;
    }

    for (int i = 0; i < ANIMATION_FRAMES; i++) {
        spriteClips[i].h = 205;
        spriteClips[i].w = 64;
        spriteClips[i].y = 0;
        spriteClips[i].x = i * 64;
    }
    
    return true;
}

void close()
{
    SpriteSheetTexture.free();

    SDL_DestroyRenderer(renderer);
    renderer = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;

    IMG_Quit();
    SDL_Quit();

}

int main(int argc, char* argv[])
{
    if (!init()) {
        printf("\nInitialization error!\n");
        return 1;
    }
    if (!load()) {
        printf("\nLoading error!\n");
        return 1;
    }
    printf("%d", sizeof(Texture));
    bool running = true;
    SDL_Event e;    
    //
    int frame = 0;

    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym)
                {
                case SDLK_UP:
                 
                    break;
                case SDLK_DOWN:
                   
                    break;/*
                case SDLK_LEFT:
                    currentSurface = surfacesList[KEY_PRESS_SURFACE_LEFT];
                    break;
                case SDLK_RIGHT:
                    currentSurface = surfacesList[KEY_PRESS_SURFACE_RIGTH];
                    break;
                default:
                    currentSurface = surfacesList[KEY_PRESS_SURFACE_DEFAULT];
                    break;*/
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        SDL_Rect* currentClip = &spriteClips[frame / 4];

        SpriteSheetTexture.render(renderer, WINDOW_WIDTH / 2 - currentClip->w / 2, WINDOW_HEIGTH / 2 - currentClip->h / 2, currentClip, 20);

        frame++;
        if (frame / 4 >= ANIMATION_FRAMES) {
            frame = 0;
        }
      
        // temporaly
        SDL_Delay(30);
        SDL_RenderPresent(renderer);
    }
   
    close();

    return 0;
}