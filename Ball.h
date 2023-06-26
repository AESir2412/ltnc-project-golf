#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>
#include "Hole.h"
#include "Tile.h"
#include "Sand.h"
#include "Water.h"
#include "Ice.h"
#include "Spring.h"

#include "Entity.h"
#include "Math.h"

class Ball : public Entity
{
public:
	Ball(Vector2f p_pos, SDL_Texture* p_tex, SDL_Texture* p_pointTex, SDL_Texture* p_powerMTexFG, SDL_Texture* p_powerMTexBG, int p_index);
	Ball();
    Vector2f& getVelocity()
	{
		return velocity;
	}
    Vector2f& getInitialMousePos()
	{
		return initialMousePos;
	}
	Vector2f& getInitialBallPos()  //tu them
	{
		return initialBallPos;
	}
    std::vector<Entity> getPoints()
	{
		return points;
	}
    std::vector<Entity> getPowerBar()
	{
		return powerBar;
	}
    int getStrokes()
    {
        return strokes;
    }
    bool isWin()
    {
        return win;
    }
    void setWin(bool p_win);
    void setInitialMousePos(float x, float y);
    void setVelocity(float x, float y);
    void setLaunchedVelocity(float x, float y);
    void update(double deltaTime, bool mouseDown, bool mousePressed,
                std::vector<Tile> tiles, std::vector<Hole> holes, std::vector<Sand> sands, std::vector<Water> waters, std::vector<Ice> ices, std::vector<Spring> springs,
                Mix_Chunk* chargeSfx, Mix_Chunk* swingSfx, Mix_Chunk* holeSfx, Mix_Chunk* waterSfx, Mix_Chunk* bounceSfx);

    void setInitialBallPos(float x, float y); //tu them
private:
    Vector2f velocity;
    Vector2f target;
    Vector2f launchedVelocity;
    float velocity1D;
    float launchedVelocity1D;
    Vector2f initialMousePos;
    Vector2f initialBallPos; //tu them
    bool canMove = true;
    bool playedSwingFx = true;
    int index;
    int strokes = 0;
    int dirX = 1;
    int dirY = 1;
    bool win = false;
    float friction = 0.001;
    float frictionSand = 0.3;
    float sliperyIce = 3;
    float bouncySpring = 0.4; //giam he so nay
    std::vector<Entity> points;
    std::vector<Entity> powerBar;
    bool wasInSand = false;   //chua hoat dong chuan?, de o command ball.cpp
};
