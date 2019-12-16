#include <iostream>
#include "bitboard.h"
#include "chessboard.h"

//Using SDL
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

// Tecxture
SDL_Texture* gTexture = NULL;

using namespace std;

bool init();
void close();
void renderChessboard(ChessBoard chessboard);
SDL_Texture* loadTexture(string path);

int main(int argc, char* args[]) {
    //Initialize SDL and textures
    if (!init()) {
        return 1;
    }

    // Initialize chessboard
    BitBoard boards[8] = {65535, 18446462598732840960, 71776119061282560, 4755801206503243842, 2594073385365405732, 9295429630892703873, 1152921504606846992, 576460752303423496};
    ChessBoard chessboard {boards};

    chessboard.getWhitePawns().print();
  
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
        renderChessboard( chessboard );

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

    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "0" ) ) {
        printf( "Warning: Linear texture filtering not enabled!" );
    }

    //Create window
    gWindow = SDL_CreateWindow( "P2P Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

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

    // Load textures from disk
    gTexture = loadTexture("resources/chess pieces.png");
    if (gTexture == NULL) {
        printf("Could not load texture!");
        return false;
    }

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
const int BLACK_R = 0x50;
const int BLACK_G = 0x50;
const int BLACK_B = 0x50;

const int WHITE_R = 0xFF;
const int WHITE_G = 0xFF;
const int WHITE_B = 0xFF;

const int scale = 32;

const int sprite_scale = 16;
// Sprite sheet
SDL_Rect whitePawn   = {0*sprite_scale, 0, sprite_scale, sprite_scale};
SDL_Rect whiteKnight = {1*sprite_scale, 0, sprite_scale, sprite_scale};
SDL_Rect whiteBishop = {2*sprite_scale, 0, sprite_scale, sprite_scale};
SDL_Rect whiteRook   = {3*sprite_scale, 0, sprite_scale, sprite_scale};
SDL_Rect whiteQueen  = {4*sprite_scale, 0, sprite_scale, sprite_scale};
SDL_Rect whiteKing   = {5*sprite_scale, 0, sprite_scale, sprite_scale};

SDL_Rect blackPawn   = {0*sprite_scale, sprite_scale, sprite_scale, sprite_scale};
SDL_Rect blackKnight = {1*sprite_scale, sprite_scale, sprite_scale, sprite_scale};
SDL_Rect blackBishop = {2*sprite_scale, sprite_scale, sprite_scale, sprite_scale};
SDL_Rect blackRook   = {3*sprite_scale, sprite_scale, sprite_scale, sprite_scale};
SDL_Rect blackQueen  = {4*sprite_scale, sprite_scale, sprite_scale, sprite_scale};
SDL_Rect blackKing   = {5*sprite_scale, sprite_scale, sprite_scale, sprite_scale};

void renderChessboard(ChessBoard chessboard) {
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

    // Render each chess piece
    BitBoard whitePawns   = chessboard.getWhitePawns();
    BitBoard whiteKnights = chessboard.getWhiteKnights();
    BitBoard whiteBishops = chessboard.getWhiteBishops();
    BitBoard whiteRooks   = chessboard.getWhiteRooks();
    BitBoard whiteQueens  = chessboard.getWhiteQueens();
    BitBoard whiteKings   = chessboard.getWhiteKings();

    BitBoard blackPawns   = chessboard.getBlackPawns();
    BitBoard blackKnights = chessboard.getBlackKnights();
    BitBoard blackBishops = chessboard.getBlackBishops();
    BitBoard blackRooks   = chessboard.getBlackRooks();
    BitBoard blackQueens  = chessboard.getBlackQueens();
    BitBoard blackKings   = chessboard.getBlackKings();

    for (int i = 0; i < 64; i++) {
        SDL_Rect* sprite = NULL;

        // If i'th bit in bitboard is present, aka there's a white pawn at this index
        if ((whitePawns.value >> i) & 1) {
            sprite = &whitePawn;
        } else if ((whiteKnights.value >> i) & 1) {
            sprite = &whiteKnight;
        } else if ((whiteBishops.value >> i) & 1) {
            sprite = &whiteBishop;
        } else if ((whiteRooks.value >> i) & 1) {
            sprite = &whiteRook;
        } else if ((whiteQueens.value >> i) & 1) {
            sprite = &whiteQueen;
        } else if ((whiteKings.value >> i) & 1) {
            sprite = &whiteKing;

        } else if ((blackPawns.value >> i) & 1) {
            sprite = &blackPawn;
        } else if ((blackKnights.value >> i) & 1) {
            sprite = &blackKnight;
        } else if ((blackBishops.value >> i) & 1) {
            sprite = &blackBishop;
        } else if ((blackRooks.value >> i) & 1) {
            sprite = &blackRook;
        } else if ((blackQueens.value >> i) & 1) {
            sprite = &blackQueen;
        } else if ((blackKings.value >> i) & 1) {
            sprite = &blackKing;
        }

        if (sprite != NULL) {
            SDL_Rect dest = {i%8*scale, i/8*scale, scale, scale};
            SDL_RenderCopy(gRenderer, gTexture, sprite, &dest);
        }
    }
}

SDL_Texture* loadTexture(string path) {
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if(loadedSurface == NULL) {
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	} else {
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if(newTexture == NULL) {
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}