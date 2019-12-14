#include <iostream>
#include "bitboard.h"
#include "chessboard.h"

// int main(int argc, char **argv) 
// {
//     BitBoard boards[8] = {65535, 18446462598732840960, 71776119061282560, 4755801206503243842, 2594073385365405732, 9295429630892703873, 1152921504606846992, 576460752303423496};
//     ChessBoard chessboard {boards};
//     //BitBoard bitboard { 18446462598732906495 };
//     //BitBoard filter { 89888890099 };
//     //BitBoard stuff = filter & bitboard;

//     chessboard.getWhitePawns().print();

// /*
//     bitboard.print();
//     std::cout << "\n";
//     filter.print();
//     std::cout << "\n";
//     stuff.print();*/
//     return 0;
// }

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

using namespace std;

bool init();
void close();
void renderChessboard();

int main(int argc, char* args[]) {
  //Initialize SDL
  if(!init()) {
    return 1;
  }
  //Main loop flag
  bool quit = false;

  //Event handler
  SDL_Event e;

  //While application is running
  while( !quit ) {
    //Handle events on queue
    while( SDL_PollEvent( &e ) != 0 ) {
      //User requests quit
      if( e.type == SDL_QUIT ) {
        quit = true;
      }
    }

    // Clear screen
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( gRenderer );

    // Render Chessboard
    renderChessboard();

    //Update screen
    SDL_RenderPresent( gRenderer );
  }

  close();

  return 0;
}

bool init() {
  //Initialize SDL
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    return false;
  }

  //Create window
  gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

  if( gWindow == NULL ) {
    printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
    return false;
  }

  //Create renderer for window
  gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
  if( gRenderer == NULL ) {
    printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
    return false;
  }

  //Initialize renderer color
  SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
  
  return true;
}

void close() {
  //Destroy window    
  SDL_DestroyRenderer( gRenderer );
  SDL_DestroyWindow( gWindow );
  gWindow = NULL;
  gRenderer = NULL;

  //Quit SDL subsystems
  SDL_Quit();
}

// Colors for the chess board
const int BLACK_R = 0x00;
const int BLACK_G = 0x00;
const int BLACK_B = 0x00;

const int WHITE_R = 0xFF;
const int WHITE_G = 0xFF;
const int WHITE_B = 0xFF;

const int scale = 32;

void renderChessboard() {
  // Render area white
  SDL_SetRenderDrawColor( gRenderer, WHITE_R, WHITE_G, WHITE_B, 0xFF );
  SDL_Rect area = { 0, 0, scale*8, scale*8 };
  SDL_RenderFillRect( gRenderer, &area );

  // Render black squares ontop
  SDL_SetRenderDrawColor( gRenderer, BLACK_R, BLACK_G, BLACK_B, 0xFF );		

  for (int i = 0; i < 32; i++) {
    // i%8*2 is x position, i/8 is y position
    // when y is even offset one to the right
    int y = i/4;
    int x = i%4*2+y%2;

    SDL_Rect square = { scale*x, scale*y, scale, scale };

    // Render
    SDL_RenderFillRect( gRenderer, &square );
  }
}