#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>

#include "RenderWindow.h"
#include "Entity.h"
#include "Ball.h"
#include "Tile.h"
#include "Hole.h"
#include "Sand.h"
#include "Water.h"
#include "Ice.h"
#include "Spring.h"

bool init()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
	if (!(TTF_Init()))
		std::cout << "TTF_init has failed. Error: " << SDL_GetError() << std::endl;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	return true;
}

bool SDLinit = init();

SDL_Renderer* renderer;

RenderWindow window("Golfin' Around", 640, 480);

SDL_Texture* ball = window.loadTexture("res/gfx/ball.png");
SDL_Texture* Aplus = window.loadTexture("res/gfx/A+.png");
SDL_Texture* penguin = window.loadTexture("res/gfx/penguin.png");
SDL_Texture* tvhsv = window.loadTexture("res/gfx/tvhsv.png");
SDL_Texture* japit = window.loadTexture("res/gfx/japit.png");
SDL_Texture* anya = window.loadTexture("res/gfx/anya.png");

SDL_Texture* holeTexture = window.loadTexture("res/gfx/hole.png");
SDL_Texture* pointTexture = window.loadTexture("res/gfx/point.png");

/**tiles**/
SDL_Texture* tileDarkTexture32_1 = window.loadTexture("res/gfx/tile32_dark_1.png");
SDL_Texture* tileDarkTexture32_2 = window.loadTexture("res/gfx/tile32_dark_2.png");
SDL_Texture* tileDarkTexture32_3 = window.loadTexture("res/gfx/tile32_dark_3.png");
SDL_Texture* tileDarkTexture32_4 = window.loadTexture("res/gfx/tile32_dark_4.png");
SDL_Texture* tileDarkTexture32_5 = window.loadTexture("res/gfx/tile32_dark_5.png");
SDL_Texture* tileDarkTexture32_6 = window.loadTexture("res/gfx/tile32_dark_6.png");
SDL_Texture* tileDarkTexture32_7 = window.loadTexture("res/gfx/tile32_dark_7.png");
SDL_Texture* tileDarkTexture32_8 = window.loadTexture("res/gfx/tile32_dark_8.png");
SDL_Texture* tileDarkTexture32_9 = window.loadTexture("res/gfx/tile32_dark_9.png");
SDL_Texture* tileDarkTexture32_10 = window.loadTexture("res/gfx/tile32_dark_10.png");

SDL_Texture* tileDarkTexture64_1 = window.loadTexture("res/gfx/tile64_dark_1.png");
SDL_Texture* tileDarkTexture64_2 = window.loadTexture("res/gfx/tile64_dark_2.png");
SDL_Texture* tileDarkTexture64_3 = window.loadTexture("res/gfx/tile64_dark_3.png");
SDL_Texture* tileDarkTexture64_4 = window.loadTexture("res/gfx/tile64_dark_4.png");
SDL_Texture* tileDarkTexture64_5 = window.loadTexture("res/gfx/tile64_dark_5.png");
SDL_Texture* tileDarkTexture64_6 = window.loadTexture("res/gfx/tile64_dark_6.png");
SDL_Texture* tileDarkTexture64_7 = window.loadTexture("res/gfx/tile64_dark_7.png");
SDL_Texture* tileDarkTexture64_8 = window.loadTexture("res/gfx/tile64_dark_8.png");
SDL_Texture* tileDarkTexture64_9 = window.loadTexture("res/gfx/tile64_dark_9.png");
SDL_Texture* tileDarkTexture64_10 = window.loadTexture("res/gfx/tile64_dark_10.png");

SDL_Texture* tileLightTexture32_1 = window.loadTexture("res/gfx/tile32_light_1.png");
SDL_Texture* tileLightTexture32_2 = window.loadTexture("res/gfx/tile32_light_2.png");
SDL_Texture* tileLightTexture32_3 = window.loadTexture("res/gfx/tile32_light_3.png");
SDL_Texture* tileLightTexture32_4 = window.loadTexture("res/gfx/tile32_light_4.png");
SDL_Texture* tileLightTexture32_5 = window.loadTexture("res/gfx/tile32_light_5.png");
SDL_Texture* tileLightTexture32_6 = window.loadTexture("res/gfx/tile32_light_6.png");
SDL_Texture* tileLightTexture32_7 = window.loadTexture("res/gfx/tile32_light_7.png");
SDL_Texture* tileLightTexture32_8 = window.loadTexture("res/gfx/tile32_light_8.png");
SDL_Texture* tileLightTexture32_9 = window.loadTexture("res/gfx/tile32_light_9.png");
SDL_Texture* tileLightTexture32_10 = window.loadTexture("res/gfx/tile32_light_10.png");

SDL_Texture* tileLightTexture64_1 = window.loadTexture("res/gfx/tile64_light_1.png");
SDL_Texture* tileLightTexture64_2 = window.loadTexture("res/gfx/tile64_light_2.png");
SDL_Texture* tileLightTexture64_3 = window.loadTexture("res/gfx/tile64_light_3.png");
SDL_Texture* tileLightTexture64_4 = window.loadTexture("res/gfx/tile64_light_4.png");
SDL_Texture* tileLightTexture64_5 = window.loadTexture("res/gfx/tile64_light_5.png");
SDL_Texture* tileLightTexture64_6 = window.loadTexture("res/gfx/tile64_light_6.png");
SDL_Texture* tileLightTexture64_7 = window.loadTexture("res/gfx/tile64_light_7.png");
SDL_Texture* tileLightTexture64_8 = window.loadTexture("res/gfx/tile64_light_8.png");
SDL_Texture* tileLightTexture64_9 = window.loadTexture("res/gfx/tile64_light_9.png");
SDL_Texture* tileLightTexture64_10 = window.loadTexture("res/gfx/tile64_light_10.png");


/*****/
SDL_Texture* ballShadowTexture = window.loadTexture("res/gfx/ball_shadow.png");
SDL_Texture* bgTextureLight = window.loadTexture("res/gfx/bg_light.png");
SDL_Texture* uiBgTexture = window.loadTexture("res/gfx/UI_bg.png");
SDL_Texture* levelTextBgTexture = window.loadTexture("res/gfx/levelText_bg.png");
SDL_Texture* powerMeterTexture_FG = window.loadTexture("res/gfx/powermeter_fg.png");
SDL_Texture* powerMeterTexture_BG = window.loadTexture("res/gfx/powermeter_bg.png");
SDL_Texture* powerMeterTexture_overlay = window.loadTexture("res/gfx/powermeter_overlay.png");
SDL_Texture* title_BG  = window.loadTexture("res/gfx/title_bg.png");
SDL_Texture* logoSDL = window.loadTexture("res/gfx/sdl.png");
SDL_Texture* logoTexture = window.loadTexture("res/gfx/logo.png");
SDL_Texture* click2start = window.loadTexture("res/gfx/click2start.png");
SDL_Texture* endscreenOverlayTexture = window.loadTexture("res/gfx/end.png");
SDL_Texture* splashBgTexture = window.loadTexture("res/gfx/splashbg.png");
SDL_Texture* helpMenu = window.loadTexture("res/gfx/help.png");
SDL_Texture* chooseBallMenu = window.loadTexture("res/gfx/chooseBall.png");
SDL_Texture* loseScreen = window.loadTexture("res/gfx/lose.png");

SDL_Texture* playWhenHovered = window.loadTexture("res/gfx/play_hovered.png");
SDL_Texture* helpWhenHovered = window.loadTexture("res/gfx/help_hovered.png");

SDL_Texture* sand32 = window.loadTexture("res/gfx/sand32.png");
SDL_Texture* ice32 = window.loadTexture("res/gfx/ice32.png");
SDL_Texture* sand64 = window.loadTexture("res/gfx/sand64.png");
SDL_Texture* ice64 = window.loadTexture("res/gfx/ice64.png");
SDL_Texture* waterTexture64 = window.loadTexture("res/gfx/water_64.png");
SDL_Texture* waterTexture32 = window.loadTexture("res/gfx/water_32.png");
SDL_Texture* spring64 = window.loadTexture("res/gfx/spring64.png");
SDL_Texture* spring32 = window.loadTexture("res/gfx/spring32.png");


Mix_Chunk* chargeSfx = Mix_LoadWAV("res/sfx/charge.mp3");
Mix_Chunk* swingSfx = Mix_LoadWAV("res/sfx/swing.mp3");
Mix_Chunk* holeSfx = Mix_LoadWAV("res/sfx/hole.mp3");
Mix_Chunk* waterSfx = Mix_LoadWAV("res/sfx/water.mp3");
Mix_Chunk* bounceSfx = Mix_LoadWAV("res/sfx/bounce.mp3");
Mix_Chunk* openingSfx = Mix_LoadWAV("res/sfx/SUPERCELL.mp3");
Mix_Chunk* loseSfx = Mix_LoadWAV("res/sfx/lose.mp3");
Mix_Chunk* winSfx = Mix_LoadWAV("res/sfx/win.mp3");

Mix_Music* lobbyMusic = Mix_LoadMUS("res/sfx/SPYxFAMILY.mp3");

SDL_Color white = { 255, 255, 255 };
SDL_Color black = { 0, 0, 0 };
TTF_Font* font32 = TTF_OpenFont("res/font/font.ttf", 32);
TTF_Font* font48 = TTF_OpenFont("res/font/font.ttf", 48);
TTF_Font* font24 = TTF_OpenFont("res/font/font.ttf", 24);


SDL_Event event;

int state = 0; //0 = title screen, 1 = game, 2 = end screen

Uint64 currentTick = SDL_GetPerformanceCounter();
Uint64 lastTick = 0;
double deltaTime = 0;

int ballType = 0;

bool gameRunning = true;
bool mouseDown = false;
bool mousePressed = false;

bool swingPlayed = false;
bool secondSwingPlayed = false;

void waitUntilKeyPressed();

//check ball skin
bool checkGolfBall = false;
bool checkAPlus = false;
bool checkPenguin = false;
bool checkTVHSV = false;
bool checkJAPIT = false;
bool checkAnya = false;

Ball ballsGolf[1] = {Ball(Vector2f(24 + 32*1, 24 + 32*7), ball, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0)};
Ball ballsAPlus[1] = {Ball(Vector2f(24 + 32*1, 24 + 32*7), Aplus, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0)};
Ball ballsPenguin[1] = {Ball(Vector2f(24 + 32*1, 24 + 32*7), penguin, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0)};
Ball ballsTVHSV[1] = {Ball(Vector2f(24 + 32*1, 24 + 32*7), tvhsv, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0)};
Ball ballsJAPIT[1] = {Ball(Vector2f(24 + 32*1, 24 + 32*7), japit, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0)};
Ball ballsAnya[1] = {Ball(Vector2f(24 + 32*1, 24 + 32*7), anya, pointTexture, powerMeterTexture_FG, powerMeterTexture_BG, 0)};


void titleScreen()
{
	if (SDL_GetTicks() < 2000)
	{
	    //first screen
		if (!swingPlayed)
		{
			Mix_PlayChannel(-1, openingSfx, 0);
			swingPlayed = true;
		}
		//Get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;

            case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                gameRunning = false;
                break;
                }
			}
		}

		window.clear();
		window.render(0, 0, title_BG);
		window.render(75, 110, logoSDL);
		window.renderCenter(0, -80 + 3, "A Game made with", font32, black);
		window.renderCenter(0, -80, "A Game made with", font32, white);
		window.display();
		SDL_Delay(1000);
	}
	else
	{
	    //second title screen
		if (!secondSwingPlayed)
		{
//			Mix_PlayChannel(-1, swingSfx, 0);
			Mix_PlayMusic(lobbyMusic, -1);
			secondSwingPlayed = true;
		}
		lastTick = currentTick;
		currentTick = SDL_GetPerformanceCounter();
		deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

        bool insidePlay = false;
        bool insideChooseBall = false;
        bool insideHelp = false;
        //render cai nay truoc de luc sau chi can thay doi cai hien va k hien
        window.clear();
        window.render(0, 0, bgTextureLight);
		window.render(168, 240 - 170 - 50 + 4*SDL_sin(SDL_GetTicks()*(3.14/1500)), logoTexture); //sin pi
        window.render(0, 0, click2start);
//		else if (insidePlay) window.render(0, 0, playWhenHovered);
//		else if (insideHelp) window.render(0, 0, helpWhenHovered);

		//Get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;

			// cac menu	trong title
            case SDL_MOUSEMOTION:
                {
                    int x, y;
                    SDL_GetMouseState(&x, &y);

                    int play_x0 = 179, play_y0 = 279, play_x1 = 460, play_y1 = 330;
                    int chooseBall_x0 = 179, chooseBall_y0 = 343, chooseBall_x1 = 460, chooseBall_y1 = 395;
                    int help_x0 = 179, help_y0 = 407, help_x1 = 460, help_y1 = 458;

                    if (x > play_x0 && x < play_x1 && y > play_y0 && y < play_y1) {
                        insidePlay = true;
                    }
                    else if (x > chooseBall_x0 && x < chooseBall_x1 && y > chooseBall_y0 && y < chooseBall_y1) {
                        insideChooseBall = true;
                    }
                    else if (x > help_x0 && x < help_x1 && y > help_y0 && y < help_y1) {
                        insideHelp = true;
                    }


                    SDL_Delay(100);
                }
                break;

            // thoat khoi title va vao game
			case SDL_MOUSEBUTTONDOWN:
			    {
			        int x, y;
                    SDL_GetMouseState(&x, &y);

                    int play_x0 = 179, play_y0 = 279, play_x1 = 460, play_y1 = 330;
                    int chooseBall_x0 = 179, chooseBall_y0 = 343, chooseBall_x1 = 460, chooseBall_y1 = 395;
                    int help_x0 = 179, help_y0 = 407, help_x1 = 460, help_y1 = 458;

                    if (x > play_x0 && x < play_x1 && y > play_y0 && y < play_y1) {
                        insidePlay = true;
                    }
                    else if (x > chooseBall_x0 && x < chooseBall_x1 && y > chooseBall_y0 && y < chooseBall_y1) {
                        insideChooseBall = true;
                    }
                    else if (x > help_x0 && x < help_x1 && y > help_y0 && y < help_y1) {
                        insideHelp = true;
                    }

                    if (insidePlay && event.button.button == SDL_BUTTON_LEFT)
                    {
                        Mix_FreeMusic(lobbyMusic);
                        Mix_PlayChannel(-1, holeSfx, 0);
                        state = 1;
                    }

                    if (insideChooseBall && event.button.button == SDL_BUTTON_LEFT)
                    {
                    // Ball Selection *******************************************************//
                        window.clear();
                        window.render(0, 0, bgTextureLight);
                        window.render(0, 0, chooseBallMenu);
                        window.display();
                        waitUntilKeyPressed();

                    }
                    //******************************//

                    if (insideHelp && event.button.button == SDL_BUTTON_LEFT)
                    {
                        window.clear();
                        window.render(0, 0, bgTextureLight);
                        window.render(0, 0, helpMenu);
                        window.display();
                        waitUntilKeyPressed();
                    }
			    }
				break;

            //chon ball
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_1:
                    checkGolfBall = true;
                    std::cout << "Key 1 detected!" << std::endl;
                    std::cout << ">> Ball chosen: Golf Ball" << std::endl;
                    break;
                case SDLK_2:
                    checkAPlus = true;
                    std::cout << "Key 2 detected!" << std::endl;
                    std::cout << ">> Ball chosen: A+ Ball" << std::endl;
                    break;
                case SDLK_3:
                    checkPenguin = true;
                    std::cout << "Key 3 detected!" << std::endl;
                    std::cout << ">> Ball chosen: Penguin Ball" << std::endl;
                    break;
                case SDLK_4:
                    checkTVHSV = true;
                    std::cout << "Key 4 detected!" << std::endl;
                    std::cout << ">> Ball chosen: TVHSV Ball" << std::endl;
                    break;
                case SDLK_5:
                    checkJAPIT = true;
                    std::cout << "Key 5 detected!" << std::endl;
                    std::cout << ">> Ball chosen: JAPIT Ball" << std::endl;
                    break;
                case SDLK_6:
                    checkAnya = true;
                    std::cout << "Key 6 detected!" << std::endl;
                    std::cout << ">> Ball chosen: Anya...? Ball" << std::endl;
                    break;
                }

            break;
			}
		}

        window.renderCenter(0, 240 - 46 - 48 + 3 - 16*5, "PLAY", font32, black);
		window.renderCenter(0, 240 - 46 - 48 - 16*5, "PLAY", font32, white);
        window.renderCenter(0, 240 + 18 - 48 + 3 - 16*5, "CHOOSE BALL", font32, black);
		window.renderCenter(0, 240 + 18 - 48 - 16*5, "CHOOSE BALL", font32, white);
		window.renderCenter(0, 240 + 80 - 48 + 3 - 16*5, "HELP", font32, black);
		window.renderCenter(0, 240 + 80 - 48 - 16*5, "HELP", font32, white);
		window.display();
	}
}


//std::vector<Hole> holes = {Hole(Vector2f(0, 0), holeTexture), Hole(Vector2f(0, 0), holeTexture)};
std::vector<Hole> holes = {Hole(Vector2f(24 + 32*17, 22 + 32*7), holeTexture)};

//load obstacles
std::vector<Tile> loadTiles(int level)
{
	std::vector<Tile> temp = {};
	switch(level)
	{
		case 0:

		break;
		case 1:


		break;
		case 2:
			temp.push_back(Tile(Vector2f(32*3, 32*0), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*4, 32*0), tileDarkTexture32_2));
			temp.push_back(Tile(Vector2f(32*5, 32*0), tileDarkTexture32_2));
			temp.push_back(Tile(Vector2f(32*6, 32*0), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*3, 32*1), tileDarkTexture32_4));
			temp.push_back(Tile(Vector2f(32*4, 32*1), tileDarkTexture32_5));
			temp.push_back(Tile(Vector2f(32*5, 32*1), tileDarkTexture32_8));
			temp.push_back(Tile(Vector2f(32*6, 32*1), tileDarkTexture32_9));
			temp.push_back(Tile(Vector2f(32*3, 32*2), tileDarkTexture32_4));
			temp.push_back(Tile(Vector2f(32*4, 32*2), tileDarkTexture32_6));
			temp.push_back(Tile(Vector2f(32*3, 32*3), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*4, 32*3), tileDarkTexture32_9));

			temp.push_back(Tile(Vector2f(32*13, 32*0), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*14, 32*0), tileDarkTexture32_2));
			temp.push_back(Tile(Vector2f(32*15, 32*0), tileDarkTexture32_2));
			temp.push_back(Tile(Vector2f(32*16, 32*0), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*13, 32*1), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*14, 32*1), tileDarkTexture32_8));
			temp.push_back(Tile(Vector2f(32*15, 32*1), tileDarkTexture32_5));
			temp.push_back(Tile(Vector2f(32*16, 32*1), tileDarkTexture32_6));
			temp.push_back(Tile(Vector2f(32*15, 32*2), tileDarkTexture32_4));
			temp.push_back(Tile(Vector2f(32*16, 32*2), tileDarkTexture32_6));
			temp.push_back(Tile(Vector2f(32*15, 32*3), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*16, 32*3), tileDarkTexture32_9));

			temp.push_back(Tile(Vector2f(32*7, 32*4), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*8, 32*4), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*6, 32*5), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*7, 32*5), tileDarkTexture32_5));
			temp.push_back(Tile(Vector2f(32*8, 32*5), tileDarkTexture32_9));
			temp.push_back(Tile(Vector2f(32*6, 32*6), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*7, 32*6), tileDarkTexture32_9));

			temp.push_back(Tile(Vector2f(32*11, 32*4), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*12, 32*4), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*11, 32*5), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*12, 32*5), tileDarkTexture32_5));
			temp.push_back(Tile(Vector2f(32*13, 32*5), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*12, 32*6), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*13, 32*6), tileDarkTexture32_9));

			temp.push_back(Tile(Vector2f(32*6, 32*8), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*7, 32*8), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*6, 32*9), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*7, 32*9), tileDarkTexture32_5));
			temp.push_back(Tile(Vector2f(32*8, 32*9), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*7, 32*10), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*8, 32*10), tileDarkTexture32_9));

			temp.push_back(Tile(Vector2f(32*12, 32*8), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*13, 32*8), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*11, 32*9), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*12, 32*9), tileDarkTexture32_5));
			temp.push_back(Tile(Vector2f(32*13, 32*9), tileDarkTexture32_9));
			temp.push_back(Tile(Vector2f(32*11, 32*10), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*12, 32*10), tileDarkTexture32_9));

			temp.push_back(Tile(Vector2f(32*3, 32*11), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*4, 32*11), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*3, 32*12), tileDarkTexture32_4));
			temp.push_back(Tile(Vector2f(32*4, 32*12), tileDarkTexture32_6));
			temp.push_back(Tile(Vector2f(32*3, 32*13), tileDarkTexture32_4));
			temp.push_back(Tile(Vector2f(32*4, 32*13), tileDarkTexture32_5));
			temp.push_back(Tile(Vector2f(32*5, 32*13), tileDarkTexture32_2));
			temp.push_back(Tile(Vector2f(32*6, 32*13), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*3, 32*14), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*4, 32*14), tileDarkTexture32_8));
			temp.push_back(Tile(Vector2f(32*5, 32*14), tileDarkTexture32_8));
			temp.push_back(Tile(Vector2f(32*6, 32*14), tileDarkTexture32_9));

			temp.push_back(Tile(Vector2f(32*15, 32*11), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*16, 32*11), tileDarkTexture32_3));
			temp.push_back(Tile(Vector2f(32*15, 32*12), tileDarkTexture32_4));
			temp.push_back(Tile(Vector2f(32*16, 32*12), tileDarkTexture32_6));
			temp.push_back(Tile(Vector2f(32*13, 32*13), tileDarkTexture32_1));
			temp.push_back(Tile(Vector2f(32*14, 32*13), tileDarkTexture32_2));
			temp.push_back(Tile(Vector2f(32*15, 32*13), tileDarkTexture32_5));
			temp.push_back(Tile(Vector2f(32*16, 32*13), tileDarkTexture32_6));
			temp.push_back(Tile(Vector2f(32*13, 32*14), tileDarkTexture32_7));
			temp.push_back(Tile(Vector2f(32*14, 32*14), tileDarkTexture32_8));
			temp.push_back(Tile(Vector2f(32*15, 32*14), tileDarkTexture32_8));
			temp.push_back(Tile(Vector2f(32*16, 32*14), tileDarkTexture32_9));

		break;
		case 3:
            temp.push_back(Tile(Vector2f(32*1, 32*0), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*0), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*4, 32*0), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*5, 32*0), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*6, 32*0), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*8, 32*0), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*9, 32*0), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*10, 32*0), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*11, 32*0), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*12, 32*0), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*0), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*0), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*0), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*16, 32*0), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*0), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*1, 32*1), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*1), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*1, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*5, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*6, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*7, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*8, 32*2), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*9, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*10, 32*2), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*12, 32*2), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*2), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*2), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*18, 32*2), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*2), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*0, 32*3), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*1, 32*3), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*3), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*10, 32*3), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*12, 32*3), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*3), tileLightTexture32_10));

            temp.push_back(Tile(Vector2f(32*3, 32*4), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*5, 32*4), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*6, 32*4), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*7, 32*4), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*8, 32*4), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*10, 32*4), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*11, 32*4), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*12, 32*4), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*4), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*4), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*16, 32*4), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*4), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*4), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*0, 32*5), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*1, 32*5), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*2, 32*5), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*5), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*5, 32*5), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*8, 32*5), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*5), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*5), tileLightTexture32_10));

            temp.push_back(Tile(Vector2f(32*5, 32*6), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*6, 32*6), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*7, 32*6), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*8, 32*6), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*9, 32*6), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*10, 32*6), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*11, 32*6), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*12, 32*6), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*6), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*6), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*16, 32*6), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*6), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*18, 32*6), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*6), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*0, 32*7), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*1, 32*7), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*2, 32*7), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*7), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*7), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*7), tileLightTexture32_10));

            temp.push_back(Tile(Vector2f(32*0, 32*8), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*1, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*4, 32*8), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*5, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*6, 32*8), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*7, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*9, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*11, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*12, 32*8), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*8), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*16, 32*8), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*8), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*8), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*7, 32*9), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*9, 32*9), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*9), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*9), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*9), tileLightTexture32_10));

            temp.push_back(Tile(Vector2f(32*0, 32*10), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*1, 32*10), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*10), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*4, 32*10), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*5, 32*10), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*6, 32*10), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*7, 32*10), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*9, 32*10), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*10, 32*10), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*11, 32*10), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*12, 32*10), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*10), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*10), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*10), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*1, 32*11), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*11), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*7, 32*11), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*11, 32*11), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*11), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*11), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*11), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*18, 32*11), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*11), tileLightTexture32_10));

            temp.push_back(Tile(Vector2f(32*0, 32*12), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*1, 32*12), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*5, 32*12), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*7, 32*12), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*8, 32*12), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*9, 32*12), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*11, 32*12), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*12), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*12), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*12), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*18, 32*12), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*19, 32*12), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*2, 32*13), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*3, 32*13), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*5, 32*13), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*12), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*17, 32*12), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*18, 32*12), tileDarkTexture32_10));

            temp.push_back(Tile(Vector2f(32*5, 32*14), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*6, 32*14), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*7, 32*14), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*9, 32*14), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*10, 32*14), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*11, 32*14), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*12, 32*14), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*13, 32*14), tileDarkTexture32_10));
            temp.push_back(Tile(Vector2f(32*14, 32*14), tileLightTexture32_10));
            temp.push_back(Tile(Vector2f(32*15, 32*14), tileDarkTexture32_10));


		break;
		case 4:

//			temp.push_back(Tile(Vector2f(32*2 + 32*10, 32*2), tileLightTexture32));
//			temp.push_back(Tile(Vector2f(32*5 + 32*10, 32*11), tileLightTexture32));

		break;
	}
	return temp;
}

std::vector<Sand> loadSands(int level)
{
	std::vector<Sand> temp = {};
	switch(level)
	{
		case 0:

//            temp.push_back(Sand(Vector2f(64*3, 64*3), sand));
//            temp.push_back(Sand(Vector2f(64*3, 64*4), sand));
//            temp.push_back(Sand(Vector2f(64*4, 64*4), sand));
		break;
		case 1:
              temp.push_back(Sand(Vector2f(64*7, 64*4), sand64));
		break;
		case 2:

		break;
		case 3:

		break;

		case 4:
        break;
	}
	return temp;
}

std::vector<Water> loadWaters(int level)
{
	std::vector<Water> temp = {};
	switch(level)
	{
		case 0:


		break;
		case 1:
            for (int i=0; i<=9; i++) temp.push_back(Water(Vector2f(64*i, 64*0), waterTexture64));
            for (int i=0; i<=2; i++) temp.push_back(Water(Vector2f(64*i, 64*1), waterTexture64));
            for (int i=7; i<=9; i++) temp.push_back(Water(Vector2f(64*i, 64*1), waterTexture64));
            for (int i=0; i<=2; i++) temp.push_back(Water(Vector2f(64*i, 64*2), waterTexture64));
            for (int i=7; i<=9; i++) temp.push_back(Water(Vector2f(64*i, 64*2), waterTexture64));
            for (int i=0; i<=1; i++) temp.push_back(Water(Vector2f(64*i, 64*3), waterTexture64));
            for (int i=8; i<=9; i++) temp.push_back(Water(Vector2f(64*i, 64*3), waterTexture64));
            for (int i=9; i<=10; i++) {
                for (int j=7; j<=8; j++) temp.push_back(Water(Vector2f(32*i, 32*j), waterTexture32));
            }
            temp.push_back(Water(Vector2f(64*0, 64*4), waterTexture64));
            temp.push_back(Water(Vector2f(64*9, 64*4), waterTexture64));
            temp.push_back(Water(Vector2f(64*4, 64*4), waterTexture64));
            temp.push_back(Water(Vector2f(64*5, 64*4), waterTexture64));
            for (int i=3; i<=6; i++) {
                for (int j=5; j<=7; j++) temp.push_back(Water(Vector2f(64*i, 64*j), waterTexture64));
            }
            for (int i=5; i<=14; i++) temp.push_back(Water(Vector2f(32*i, 32*14), waterTexture32));

		break;
		case 2:
            temp.push_back(Water(Vector2f(32*9, 32*4), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*4), waterTexture32));

		    temp.push_back(Water(Vector2f(32*9, 32*5), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*5), waterTexture32));

		    temp.push_back(Water(Vector2f(32*8, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*9, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*11, 32*6), waterTexture32));

            temp.push_back(Water(Vector2f(32*6, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*7, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*8, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*9, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*11, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*12, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*13, 32*7), waterTexture32));

		    temp.push_back(Water(Vector2f(32*8, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*9, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*11, 32*8), waterTexture32));

		    temp.push_back(Water(Vector2f(32*9, 32*9), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*9), waterTexture32));

		    temp.push_back(Water(Vector2f(32*9, 32*10), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*10), waterTexture32));

		    temp.push_back(Water(Vector2f(64*0, 64*0), waterTexture64));
		    temp.push_back(Water(Vector2f(64*0, 64*1), waterTexture64));
		    temp.push_back(Water(Vector2f(32*2, 32*0), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*1), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*2), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*3), waterTexture32));

		    temp.push_back(Water(Vector2f(32*17, 64*0), waterTexture64));
		    temp.push_back(Water(Vector2f(32*17, 64*1), waterTexture64));
		    temp.push_back(Water(Vector2f(32*19, 32*0), waterTexture32));
		    temp.push_back(Water(Vector2f(32*19, 32*1), waterTexture32));
		    temp.push_back(Water(Vector2f(32*19, 32*2), waterTexture32));
		    temp.push_back(Water(Vector2f(32*19, 32*3), waterTexture32));

		    temp.push_back(Water(Vector2f(64*0, 32*11), waterTexture64));
		    temp.push_back(Water(Vector2f(64*0, 32*13), waterTexture64));
		    temp.push_back(Water(Vector2f(32*2, 32*11), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*12), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*13), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*14), waterTexture32));

		    temp.push_back(Water(Vector2f(32*17, 32*11), waterTexture64));
		    temp.push_back(Water(Vector2f(32*17, 32*13), waterTexture64));
		    temp.push_back(Water(Vector2f(32*19, 32*11), waterTexture32));
		    temp.push_back(Water(Vector2f(32*19, 32*12), waterTexture32));
		    temp.push_back(Water(Vector2f(32*19, 32*13), waterTexture32));
		    temp.push_back(Water(Vector2f(32*19, 32*14), waterTexture32));
		break;
		case 3:

		break;

		case 4:
		    for (int i=2; i<=16; i++) temp.push_back(Water(Vector2f(32*i, 32*0), waterTexture32));
		    temp.push_back(Water(Vector2f(32*0, 32*0), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*0), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*1), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*1), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*1), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*1), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*2), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*2), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*2), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*2), waterTexture32));
		    for (int i=4; i<=14; i++) temp.push_back(Water(Vector2f(32*i, 32*2), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*3), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*3), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*3), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*3), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*3), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*3), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*4), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*4), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*4), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*4), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*4), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*4), waterTexture32));
		    for (int i=6; i<=12; i++) temp.push_back(Water(Vector2f(32*i, 32*4), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*5), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*5), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*5), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*5), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*5), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*5), waterTexture32));
            temp.push_back(Water(Vector2f(32*6, 32*5), waterTexture32));
		    temp.push_back(Water(Vector2f(32*12, 32*5), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*6), waterTexture32));
            temp.push_back(Water(Vector2f(32*6, 32*6), waterTexture32));
		    temp.push_back(Water(Vector2f(32*12, 32*6), waterTexture32));
		    for (int i=8; i<=10; i++) temp.push_back(Water(Vector2f(32*i, 32*6), waterTexture32));


		    temp.push_back(Water(Vector2f(32*0, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*7), waterTexture32));
            temp.push_back(Water(Vector2f(32*6, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*12, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*8, 32*7), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*7), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*8), waterTexture32));
            temp.push_back(Water(Vector2f(32*6, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*12, 32*8), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*8), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*9), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*9), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*9), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*9), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*9), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*9), waterTexture32));
            temp.push_back(Water(Vector2f(32*6, 32*9), waterTexture32));
		    temp.push_back(Water(Vector2f(32*12, 32*9), waterTexture32));
		    temp.push_back(Water(Vector2f(32*10, 32*9), waterTexture32));
		    for (int i=6; i<=10; i++) temp.push_back(Water(Vector2f(32*i, 32*9), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*10), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*10), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*10), waterTexture32));
		    temp.push_back(Water(Vector2f(32*12, 32*10), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*10), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*10), waterTexture32));
            temp.push_back(Water(Vector2f(32*18, 32*10), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*11), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*11), waterTexture32));
		    temp.push_back(Water(Vector2f(32*4, 32*11), waterTexture32));
		    temp.push_back(Water(Vector2f(32*12, 32*11), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*11), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*11), waterTexture32));
            temp.push_back(Water(Vector2f(32*18, 32*11), waterTexture32));
		    for (int i=4; i<=12; i++) temp.push_back(Water(Vector2f(32*i, 32*11), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*12), waterTexture32));
		    temp.push_back(Water(Vector2f(32*2, 32*12), waterTexture32));
		    temp.push_back(Water(Vector2f(32*14, 32*12), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*12), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*12), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*13), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*13), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*13), waterTexture32));
		    for (int i=2; i<=14; i++) temp.push_back(Water(Vector2f(32*i, 32*13), waterTexture32));

		    temp.push_back(Water(Vector2f(32*0, 32*14), waterTexture32));
		    temp.push_back(Water(Vector2f(32*16, 32*14), waterTexture32));
		    temp.push_back(Water(Vector2f(32*18, 32*14), waterTexture32));


        break;
	}
	return temp;
}

std::vector<Ice> loadIces(int level)
{
	std::vector<Ice> temp = {};
	switch(level)
	{
		case 0:

		break;
		case 1:
            temp.push_back(Ice(Vector2f(64*3 , 64*2), ice64));
            temp.push_back(Ice(Vector2f(64*4 , 64*2), ice64));
            temp.push_back(Ice(Vector2f(64*5 , 64*2), ice64));
            temp.push_back(Ice(Vector2f(64*6 , 64*2), ice64));
		break;
		case 2:

		break;
		case 3:

		break;

		case 4:
        break;
	}
	return temp;
}

std::vector<Spring> loadSprings(int level)
{
	std::vector<Spring> temp = {};
	switch(level)
	{
		case 0:

		break;
		case 1:
            for (int i=3; i<=6; i++) temp.push_back(Spring(Vector2f(64*i, 64*1), spring64));

		break;
		case 2:
            temp.push_back(Spring(Vector2f(32*7, 32*0), spring32));
            temp.push_back(Spring(Vector2f(32*8, 32*0), spring32));
            temp.push_back(Spring(Vector2f(32*9, 32*0), spring32));
            temp.push_back(Spring(Vector2f(32*10, 32*0), spring32));
            temp.push_back(Spring(Vector2f(32*11, 32*0), spring32));
            temp.push_back(Spring(Vector2f(32*12, 32*0), spring32));

            temp.push_back(Spring(Vector2f(32*7, 32*14), spring32));
            temp.push_back(Spring(Vector2f(32*8, 32*14), spring32));
            temp.push_back(Spring(Vector2f(32*9, 32*14), spring32));
            temp.push_back(Spring(Vector2f(32*10, 32*14), spring32));
            temp.push_back(Spring(Vector2f(32*11, 32*14), spring32));
            temp.push_back(Spring(Vector2f(32*12, 32*14), spring32));
		break;
		case 3:

		break;

		case 4:
        break;
	}
	return temp;
}

int level = 0;
std::vector<Tile> tiles = loadTiles(level);
std::vector<Sand> sands = loadSands(level);
std::vector<Water> waters = loadWaters(level);
std::vector<Ice> ices = loadIces(level);
std::vector<Spring> springs = loadSprings(level);

//bool gameRunning = true;
//bool mouseDown = false;
//bool mousePressed = false;
//
//bool swingPlayed = false;
//bool secondSwingPlayed = false;


//SDL_Event event;
//
//int state = 0; //0 = title screen, 1 = game, 2 = end screen
//
//Uint64 currentTick = SDL_GetPerformanceCounter();
//Uint64 lastTick = 0;
//double deltaTime = 0;


//load level/ ending screen etc
void loadLevel(int level)
{
	if (level > 4)
	{
		state = 2;
		return;
	}

    tiles = loadTiles(level);
    sands = loadSands(level);
    waters = loadWaters(level);
    ices = loadIces(level);
    springs = loadSprings(level);

    /***Cac ham set vi tri bong va lo ***/
    if (checkGolfBall || (!(checkGolfBall) && !(checkAPlus) && !(checkPenguin) && !(checkTVHSV) && !(checkJAPIT) && !(checkAnya)))
    {
        ballsGolf[0].setVelocity(0, 0);
        ballsGolf[0].setScale(1, 1);
        ballsGolf[0].setWin(false);

        switch (level)
        {
            case 0:
                ballsGolf[0].setPos(24 + 32*1, 24 + 32*7);

                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 1:
                ballsGolf[0].setPos(95, 383);

                holes.at(0).setPos(640-95, 383);
            break;
            case 2:
                ballsGolf[0].setPos(72, 230);


                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 3:
                ballsGolf[0].setPos(24 + 32*0, 24 + 32*13);

                holes.at(0).setPos(24 + 32*18, 24 + 32*0);
            break;
            case 4:
                ballsGolf[0].setPos(8 + 32*1, 6 + 32*0);

                holes.at(0).setPos(8 + 32*9, 6 + 32*7);
            break;
        }
    }

    if (checkAPlus)
    {
        ballsAPlus[0].setVelocity(0, 0);
        ballsAPlus[0].setScale(1, 1);
        ballsAPlus[0].setWin(false);

        switch (level)
        {
            case 0:
                ballsAPlus[0].setPos(24 + 32*1, 24 + 32*7);

                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 1:
                ballsAPlus[0].setPos(95, 383);

                holes.at(0).setPos(640-95, 383);
            break;
            case 2:
                ballsAPlus[0].setPos(72, 230);


                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 3:
                ballsAPlus[0].setPos(24 + 32*0, 24 + 32*13);

                holes.at(0).setPos(24 + 32*18, 24 + 32*0);
            break;
            case 4:
                ballsAPlus[0].setPos(8 + 32*1, 6 + 32*0);

                holes.at(0).setPos(8 + 32*9, 6 + 32*7);
            break;
        }
    }

    if (checkPenguin)
    {
        ballsPenguin[0].setVelocity(0, 0);
        ballsPenguin[0].setScale(1, 1);
        ballsPenguin[0].setWin(false);

        switch (level)
        {
            case 0:
                ballsPenguin[0].setPos(24 + 32*1, 24 + 32*7);

                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 1:
                ballsPenguin[0].setPos(95, 383);

                holes.at(0).setPos(640-95, 383);
            break;
            case 2:
                ballsPenguin[0].setPos(72, 230);


                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 3:
                ballsPenguin[0].setPos(24 + 32*0, 24 + 32*13);

                holes.at(0).setPos(24 + 32*18, 24 + 32*0);
            break;
            case 4:
                ballsPenguin[0].setPos(8 + 32*1, 6 + 32*0);

                holes.at(0).setPos(8 + 32*9, 6 + 32*7);
            break;
        }
    }

    if (checkTVHSV)
    {
        ballsTVHSV[0].setVelocity(0, 0);
        ballsTVHSV[0].setScale(1, 1);
        ballsTVHSV[0].setWin(false);

        switch (level)
        {
            case 0:
                ballsTVHSV[0].setPos(24 + 32*1, 24 + 32*7);

                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 1:
                ballsTVHSV[0].setPos(95, 383);

                holes.at(0).setPos(640-95, 383);
            break;
            case 2:
                ballsTVHSV[0].setPos(72, 230);


                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 3:
                ballsTVHSV[0].setPos(24 + 32*0, 24 + 32*13);

                holes.at(0).setPos(24 + 32*18, 24 + 32*0);
            break;
            case 4:
                ballsTVHSV[0].setPos(8 + 32*1, 6 + 32*0);

                holes.at(0).setPos(8 + 32*9, 6 + 32*7);
            break;
        }
    }

    if (checkJAPIT)
    {
        ballsJAPIT[0].setVelocity(0, 0);
        ballsJAPIT[0].setScale(1, 1);
        ballsJAPIT[0].setWin(false);

        switch (level)
        {
            case 0:
                ballsJAPIT[0].setPos(24 + 32*1, 24 + 32*7);

                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 1:
                ballsJAPIT[0].setPos(95, 383);

                holes.at(0).setPos(640-95, 383);
            break;
            case 2:
                ballsJAPIT[0].setPos(72, 230);


                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 3:
                ballsJAPIT[0].setPos(24 + 32*0, 24 + 32*13);

                holes.at(0).setPos(24 + 32*18, 24 + 32*0);
            break;
            case 4:
                ballsJAPIT[0].setPos(8 + 32*1, 6 + 32*0);

                holes.at(0).setPos(8 + 32*9, 6 + 32*7);
            break;
        }
    }

    if (checkAnya)
    {
        ballsAnya[0].setVelocity(0, 0);
        ballsAnya[0].setScale(1, 1);
        ballsAnya[0].setWin(false);

        switch (level)
        {
            case 0:
                ballsAnya[0].setPos(24 + 32*1, 24 + 32*7);

                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 1:
                ballsAnya[0].setPos(95, 383);

                holes.at(0).setPos(640-95, 383);
            break;
            case 2:
                ballsAnya[0].setPos(72, 230);


                holes.at(0).setPos(24 + 32*17, 22 + 32*7);

            break;
            case 3:
                ballsAnya[0].setPos(24 + 32*0, 24 + 32*13);

                holes.at(0).setPos(24 + 32*18, 24 + 32*0);
            break;
            case 4:
                ballsAnya[0].setPos(8 + 32*1, 6 + 32*0);

                holes.at(0).setPos(8 + 32*9, 6 + 32*7);
            break;
        }
    }

}

const char* getStrokeText()
{
//	int biggestStroke = 0;
//	if (balls[1].getStrokes() > balls[0].getStrokes())
//	{
//		biggestStroke = balls[1].getStrokes();
//	}
//	else
//	{
//		biggestStroke = balls[0].getStrokes();
//	}
    int biggestStroke;
    if (checkGolfBall || (!(checkGolfBall) && !(checkAPlus) && !(checkPenguin) && !(checkTVHSV) && !(checkJAPIT) && !(checkAnya))) biggestStroke = ballsGolf[0].getStrokes();
    if (checkAPlus) biggestStroke = ballsAPlus[0].getStrokes();
    if (checkPenguin) biggestStroke = ballsPenguin[0].getStrokes();
    if (checkTVHSV) biggestStroke = ballsTVHSV[0].getStrokes();
    if (checkJAPIT) biggestStroke = ballsJAPIT[0].getStrokes();
    if (checkAnya) biggestStroke = ballsAnya[0].getStrokes();
	std::string s = std::to_string(biggestStroke);
    s = "STROKE: " + s;
	return s.c_str();
}

const char* getLevelText(int side)
{
	int tempLevel = level + 1;
	std::string s = std::to_string(tempLevel);
	s = "HOLE: " + s;
	return s.c_str();
}

void transition()
{
    if (level <= 4) {
        window.clear();
        window.render(0, 0, title_BG);
        window.render(640/2 - 132/2, 480/2 + 18 - 32, levelTextBgTexture);   //can ra giua r tru 1 nua hinh
        window.renderCenter(0, 0 + 3, getLevelText(0), font24, black);
        window.renderCenter(0, 0, getLevelText(0), font24, white);
        window.display();
        SDL_Delay(1000);
    }
}

void update()
{

	lastTick = currentTick;
	currentTick = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

	mousePressed = false;
	//Get our controls and events
	while (SDL_PollEvent(&event))
	{
		switch(event.type)
		{
		case SDL_QUIT:
			gameRunning = false;
			break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                gameRunning = false;
            }
            break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = true;
				mousePressed = true;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			if (event.button.button == SDL_BUTTON_LEFT)
			{
				mouseDown = false;
			}
			break;
		}
	}

	if (state == 1)
	{
	    /**Cac ham update bong qua thoi gian va chuyen giao khi bong thu nho (vao lo)**/
	    if (checkGolfBall || (!(checkGolfBall) && !(checkAPlus) && !(checkPenguin) && !(checkTVHSV) && !(checkJAPIT) && !(checkAnya)))
        {
            for (Ball& b : ballsGolf)
            {
                b.update(deltaTime, mouseDown, mousePressed, tiles, holes, sands, waters, ices, springs, chargeSfx, swingSfx, holeSfx, waterSfx, bounceSfx);
            }
    //		if (balls[0].getScale().x < -1 && balls[1].getScale().x < -1)
            if (ballsGolf[0].getScale().x < -1)
            {
                level++;
                transition();
                loadLevel(level);
            }
        }

        if (checkAPlus)
        {
            for (Ball& b : ballsAPlus)
            {
                b.update(deltaTime, mouseDown, mousePressed, tiles, holes, sands, waters, ices, springs, chargeSfx, swingSfx, holeSfx, waterSfx, bounceSfx);
            }
    //		if (balls[0].getScale().x < -1 && balls[1].getScale().x < -1)
            if (ballsAPlus[0].getScale().x < -1)
            {
                level++;
                transition();
                loadLevel(level);
            }
        }

        if (checkPenguin)
        {
            for (Ball& b : ballsPenguin)
            {
                b.update(deltaTime, mouseDown, mousePressed, tiles, holes, sands, waters, ices, springs, chargeSfx, swingSfx, holeSfx, waterSfx, bounceSfx);
            }
    //		if (balls[0].getScale().x < -1 && balls[1].getScale().x < -1)
            if (ballsPenguin[0].getScale().x < -1)
            {
                level++;
                transition();
                loadLevel(level);
            }
        }

        if (checkTVHSV)
        {
            for (Ball& b : ballsTVHSV)
            {
                b.update(deltaTime, mouseDown, mousePressed, tiles, holes, sands, waters, ices, springs, chargeSfx, swingSfx, holeSfx, waterSfx, bounceSfx);
            }
    //		if (balls[0].getScale().x < -1 && balls[1].getScale().x < -1)
            if (ballsTVHSV[0].getScale().x < -1)
            {
                level++;
                transition();
                loadLevel(level);
            }
        }

        if (checkJAPIT)
        {
            for (Ball& b : ballsJAPIT)
            {
                b.update(deltaTime, mouseDown, mousePressed, tiles, holes, sands, waters, ices, springs, chargeSfx, swingSfx, holeSfx, waterSfx, bounceSfx);
            }
    //		if (balls[0].getScale().x < -1 && balls[1].getScale().x < -1)
            if (ballsJAPIT[0].getScale().x < -1)
            {
                level++;
                transition();
                loadLevel(level);
            }
        }

        if (checkAnya)
        {
            for (Ball& b : ballsAnya)
            {
                b.update(deltaTime, mouseDown, mousePressed, tiles, holes, sands, waters, ices, springs, chargeSfx, swingSfx, holeSfx, waterSfx, bounceSfx);
            }
    //		if (balls[0].getScale().x < -1 && balls[1].getScale().x < -1)
            if (ballsAnya[0].getScale().x < -1)
            {
                level++;
                transition();
                loadLevel(level);
            }
        }

	}
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

void graphics()
{
	window.clear();
	window.render(0, 0, bgTextureLight);
	//chu y thu tu load query
	for (Hole& h : holes)
	{
		window.render(h);
	}
	for (Sand& s : sands)
    {
        window.render(s);
    }
    for (Water& w : waters)
    {
        window.render(w);
    }
    for (Ice& i : ices)
    {
        window.render(i);
    }
    for (Spring& s : springs)
    {
        window.render(s);
    }
    /**ham render khi win, render diem**/
    if (checkGolfBall || (!(checkGolfBall) && !(checkAPlus) && !(checkPenguin) && !(checkTVHSV) && !(checkJAPIT) && !(checkAnya)))
    {
        for (Ball& b : ballsGolf)
        {
            if (!b.isWin())
            {
                window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
            }
            for (Entity& e : b.getPoints())
            {
                window.render(e);
            }
            window.render(b);
        }
    }
    if (checkAPlus)
    {
        for (Ball& b : ballsAPlus)
        {
            if (!b.isWin())
            {
                window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
            }
            for (Entity& e : b.getPoints())
            {
                window.render(e);
            }
            window.render(b);
        }
    }
    if (checkPenguin)
    {
        for (Ball& b : ballsPenguin)
        {
            if (!b.isWin())
            {
                window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
            }
            for (Entity& e : b.getPoints())
            {
                window.render(e);
            }
            window.render(b);
        }
    }
    if (checkTVHSV)
    {
        for (Ball& b : ballsTVHSV)
        {
            if (!b.isWin())
            {
                window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
            }
            for (Entity& e : b.getPoints())
            {
                window.render(e);
            }
            window.render(b);
        }
    }
    if (checkJAPIT)
    {
        for (Ball& b : ballsJAPIT)
        {
            if (!b.isWin())
            {
                window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
            }
            for (Entity& e : b.getPoints())
            {
                window.render(e);
            }
            window.render(b);
        }
    }
    if (checkAnya)
    {
        for (Ball& b : ballsAnya)
        {
            if (!b.isWin())
            {
                window.render(b.getPos().x, b.getPos().y + 4, ballShadowTexture);
            }
            for (Entity& e : b.getPoints())
            {
                window.render(e);
            }
            window.render(b);
        }
    }

	for (Tile& t : tiles)
	{
		window.render(t);
	}

    /**Render power bar**/
    if (checkGolfBall || (!(checkGolfBall) && !(checkAPlus) && !(checkPenguin) && !(checkTVHSV) && !(checkJAPIT) && !(checkAnya)))
    {
        for (Ball& b : ballsGolf)
        {
            for (Entity& e : b.getPowerBar())
            {
                window.render(e);
            }
            window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
        }
    }
    if (checkAPlus)
    {
         for (Ball& b : ballsAPlus)
        {
            for (Entity& e : b.getPowerBar())
            {
                window.render(e);
            }
            window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
        }
    }
    if (checkPenguin)
    {
        for (Ball& b : ballsPenguin)
        {
            for (Entity& e : b.getPowerBar())
            {
                window.render(e);
            }
            window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
        }
    }
    if (checkTVHSV)
    {
        for (Ball& b : ballsTVHSV)
        {
            for (Entity& e : b.getPowerBar())
            {
                window.render(e);
            }
            window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
        }
    }
    if (checkJAPIT)
    {
        for (Ball& b : ballsJAPIT)
        {
            for (Entity& e : b.getPowerBar())
            {
                window.render(e);
            }
            window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
        }
    }
    if (checkAnya)
    {
        for (Ball& b : ballsAnya)
        {
            for (Entity& e : b.getPowerBar())
            {
                window.render(e);
            }
            window.render(b.getPowerBar().at(0).getPos().x, b.getPowerBar().at(0).getPos().y, powerMeterTexture_overlay);
        }
    }

	//render text,
	if (state != 2)
	{
		window.render(640/2 - 132/2, 480 - 32, levelTextBgTexture);   //can ra giua r tru 1 nua hinh
		window.renderCenter(0, 240 - 16 + 3, getLevelText(0), font24, black);
		window.renderCenter(0, 240 - 16, getLevelText(0), font24, white);

		window.render(640/2 - 196/2, 0, uiBgTexture);
		window.renderCenter(0, -240 + 16 + 3, getStrokeText(), font24, black);
		window.renderCenter(0, -240 + 16, getStrokeText(), font24, white);
	}
	else
	{
	    //result win
	    Mix_PlayChannel(-1, winSfx, 0);
		window.render(0, 0, endscreenOverlayTexture);
		window.renderCenter(0, 3 - 32, "YOU COMPLETED THE COURSE!", font48, black);
		window.renderCenter(0, -32, "YOU COMPLETED THE COURSE!", font48, white);
		window.renderCenter(0, 3 + 32, getStrokeText(), font32, black);
		window.renderCenter(0, 32, getStrokeText(), font32, white);
	}

    /**check result (lose)*/
    if (checkGolfBall || (!(checkGolfBall) && !(checkAPlus) && !(checkPenguin) && !(checkTVHSV) && !(checkJAPIT) && !(checkAnya)))
    {
        if (ballsGolf[0].getStrokes() == 100) {
            Mix_PlayChannel(-1, loseSfx, 0);
            window.render(0, 0, endscreenOverlayTexture);
            window.renderCenter(0, 3 - 32, "YOU LOSE!", font48, black);
            window.renderCenter(0, -32, "YOU LOSE!", font48, white);
            window.renderCenter(0, 3 + 32, "Better luck next time!", font32, black);
            window.renderCenter(0, 32, "Better luck next time!", font32, white);
            gameRunning = false;
        }
    }
    if (checkAPlus)
    {
        if (ballsAPlus[0].getStrokes() == 100) {
            Mix_PlayChannel(-1, loseSfx, 0);
            window.render(0, 0, endscreenOverlayTexture);
            window.renderCenter(0, 3 - 32, "YOU LOSE!", font48, black);
            window.renderCenter(0, -32, "YOU LOSE!", font48, white);
            window.renderCenter(0, 3 + 32, "Better luck next time!", font32, black);
            window.renderCenter(0, 32, "Better luck next time!", font32, white);
            gameRunning = false;
        }
    }
    if (checkPenguin)
    {
        if (ballsPenguin[0].getStrokes() == 100) {
            Mix_PlayChannel(-1, loseSfx, 0);
            window.render(0, 0, endscreenOverlayTexture);
            window.renderCenter(0, 3 - 32, "YOU LOSE!", font48, black);
            window.renderCenter(0, -32, "YOU LOSE!", font48, white);
            window.renderCenter(0, 3 + 32, "Better luck next time!", font32, black);
            window.renderCenter(0, 32, "Better luck next time!", font32, white);
            gameRunning = false;
        }
    }
    if (checkTVHSV)
    {
        if (ballsTVHSV[0].getStrokes() == 100) {
            Mix_PlayChannel(-1, loseSfx, 0);
            window.render(0, 0, endscreenOverlayTexture);
            window.renderCenter(0, 3 - 32, "YOU LOSE!", font48, black);
            window.renderCenter(0, -32, "YOU LOSE!", font48, white);
            window.renderCenter(0, 3 + 32, "Better luck next time!", font32, black);
            window.renderCenter(0, 32, "Better luck next time!", font32, white);
            gameRunning = false;
        }
    }
    if (checkJAPIT)
    {
        if (ballsJAPIT[0].getStrokes() == 100) {
            Mix_PlayChannel(-1, loseSfx, 0);
            window.render(0, 0, endscreenOverlayTexture);
            window.renderCenter(0, 3 - 32, "YOU LOSE!", font48, black);
            window.renderCenter(0, -32, "YOU LOSE!", font48, white);
            window.renderCenter(0, 3 + 32, "Better luck next time!", font32, black);
            window.renderCenter(0, 32, "Better luck next time!", font32, white);
            gameRunning = false;
        }
    }
    if (checkAnya)
    {
        if (ballsAnya[0].getStrokes() == 100) {
            Mix_PlayChannel(-1, loseSfx, 0);
            window.render(0, 0, endscreenOverlayTexture);
            window.renderCenter(0, 3 - 32, "YOU LOSE!", font48, black);
            window.renderCenter(0, -32, "YOU LOSE!", font48, white);
            window.renderCenter(0, 3 + 32, "Better luck next time!", font32, black);
            window.renderCenter(0, 32, "Better luck next time!", font32, white);
            gameRunning = false;
        }
    }

	window.display();
}


void game()
{
	if (state == 0)
	{
		titleScreen();
	}
	else
	{
        update();
        graphics();
    }
}


int main(int argc, char* args[])
{
	loadLevel(level);
	while (gameRunning)
	{
		game();
	}

    waitUntilKeyPressed();
	window.cleanUp();
	TTF_CloseFont(font32);
	TTF_CloseFont(font24);
	SDL_Quit();
	TTF_Quit();
	return 0;
}
