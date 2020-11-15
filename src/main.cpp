#include "Game.hpp"

#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 480

Game* game = nullptr;

int main(int argc, char *argv[])
{

    const int FPS = 60;

    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("pong!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, false);

    while(game->running()) {
        frameStart = SDL_GetTicks();
        
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    game->clean();

    return 0;
}
