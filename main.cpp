/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, SDL_ttf, standard IO, math, and strings
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
    //Init SDL
    SDL_Init( SDL_INIT_VIDEO );
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    SDL_Window *gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    SDL_Renderer *gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    int imgFlags = IMG_INIT_PNG;
    IMG_Init( imgFlags ) & imgFlags;
    TTF_Init();

    //Init font
    TTF_Font *gFont = TTF_OpenFont( "lazy.ttf", 28 );
    SDL_Color textColor = { 0, 0, 0 };

    //Init Text
    SDL_Texture* mTexture;
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, "Hola TTF", textColor );
    mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
    SDL_Rect renderQuad = { 100, 100, textSurface->w, textSurface->h };
    SDL_FreeSurface( textSurface );

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render to screen
        SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );

        //Update screen
        SDL_RenderPresent( gRenderer );
    }


	return 0;
}
