#include "Game.hpp";
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player;
GameObject* player2;

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init( SDL_INIT_EVERYTHING ) == 0)
    {
        printf( "Subsystems initialized...\n" );

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(window)
        {
            printf( "Window created...\n" );
        }

        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer)
        {
            SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
            printf( "Renderer created...\n");
        }

        isRunning = true;

        
    } else {
        isRunning = false;
    }

    player = new GameObject("assets/player.png", renderer, 0, 0);
    player2 = new GameObject("assets/player.png", renderer, 50, 50);
}

void Game::render()
{
    SDL_RenderClear(renderer);
    player->render();
    player2->render();
    SDL_RenderPresent(renderer);
}

void Game::update()
{
    player->update();
    player2->update();
}

void Game::handleEvents()
{
    SDL_Event e;

    SDL_PollEvent(&e);

    switch (e.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        
        default:
            break;
    }
}

void Game::clean()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );

    SDL_Quit();
    printf( "Game destroyed...\n" );
}