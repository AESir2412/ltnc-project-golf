#include "Ball.h"
#include "Entity.h"
#include "Math.h"
#include "Tile.h"
#include "Hole.h"
#include "Sand.h"

#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

Ball::Ball(Vector2f p_pos, SDL_Texture* p_tex, SDL_Texture* p_pointTex, SDL_Texture* p_powerMTexFG, SDL_Texture* p_powerMTexBG, int p_index)
:Entity(p_pos, p_tex)
{
//    index = p_index;
    points.push_back(Entity(Vector2f(-64, -64), p_pointTex));
    powerBar.push_back(Entity(Vector2f(-64, -64), p_powerMTexBG));
    powerBar.push_back(Entity(Vector2f(-64, -64), p_powerMTexFG));
}

void Ball::setVelocity(float x, float y)
{
    velocity.x = x;
    velocity.y = y;
}

void Ball::setLaunchedVelocity(float x, float y)
{
    launchedVelocity.x = x;
    launchedVelocity.y = y;
}

void Ball::setInitialMousePos(float x, float y)
{
    initialMousePos.x = x;
    initialMousePos.y = y;
}

void Ball::setWin(bool p_win)
{
    win = p_win;
}

void Ball::setInitialBallPos(float x, float y)   //tu them
{
    initialBallPos.x = x;
    initialBallPos.y = y;
}


void Ball::update(double deltaTime, bool mouseDown, bool mousePressed,
                  std::vector<Tile> tiles,std::vector<Hole> holes, std::vector<Sand> sands, std::vector<Water> waters, std::vector<Ice> ices, std::vector<Spring> springs,
                  Mix_Chunk* chargeSfx, Mix_Chunk* swingSfx, Mix_Chunk* holeSfx, Mix_Chunk* waterSfx, Mix_Chunk* bounceSfx)
{
    if (win)
    {
        //move ball towards center
        if (getPos().x < target.x)
        {
            setPos(getPos().x += 0.1*deltaTime, getPos().y);
        }
        else if (getPos().x > target.x)
        {
            setPos(getPos().x -= 0.1*deltaTime, getPos().y);
        }
        if (getPos().y < target.y)
        {
            setPos(getPos().x, getPos().y += 0.1*deltaTime);
        }
        else if (getPos().y > target.y)
        {
            setPos(getPos().x, getPos().y -= 0.1*deltaTime);
        }
        //shrink ball
        setScale(getScale().x - 0.001*deltaTime, getScale().y - 0.001*deltaTime);
        return;
    }

    //check ball if it's in the hole, make sound too
    for (Hole h : holes)
    {
        if (getPos().x + 4 > h.getPos().x && getPos().x + 16 < h.getPos().x + 20 && getPos().y + 4 > h.getPos().y && getPos().y + 16 < h.getPos().y + 20)
        {
            Mix_PlayChannel(-1, holeSfx, 0);
            setWin(true);
            target.x = h.getPos().x ;
            target.y = h.getPos().y + 3;
        }
    }


    //make swing sound when click, set initial position for MOUSE AND BALL (extra)
    if (mousePressed && canMove)
    {
//        Mix_PlayChannel(-1, chargeSfx, 0);
        playedSwingFx = false;
        int mouseX = 0;
	    int mouseY = 0;
	    SDL_GetMouseState(&mouseX, &mouseY);
        setInitialMousePos(mouseX, mouseY);

        //cho cai water
        int ballX = getPos().x;
        int ballY = getPos().y;
        setInitialBallPos(ballX, ballY);
    }

    //get second position to make velocity, make power meter, arrow pointer,..., collision, water, sand....
    if (mouseDown && canMove)
    {
        // mouse dragging
        int mouseX = 0;
	    int mouseY = 0;
	    SDL_GetMouseState(&mouseX, &mouseY);
        setVelocity((mouseX - getInitialMousePos().x)/-150, (mouseY - getInitialMousePos().y)/-150);  // chay theo ham rieng biet khoang cach, k lien quan toi sands
        setLaunchedVelocity((mouseX - getInitialMousePos().x)/-150, (mouseY - getInitialMousePos().y)/-150);
        velocity1D = SDL_sqrt(SDL_pow(abs(getVelocity().x), 2) + SDL_pow(abs(getVelocity().y), 2));
        launchedVelocity1D = velocity1D;

        //arrow pointer
        points.at(0).setPos(getPos().x, getPos().y + 8 - 32); // ve tam bong
        points.at(0).setAngle(SDL_atan2(velocity.y, velocity.x)*(180/3.1415) + 90); //hg mui ten

        dirX = velocity.x/abs(velocity.x);
        dirY = velocity.y/abs(velocity.y);

        //power bar
        powerBar.at(0).setPos(getPos().x + 32 + 8, getPos().y - 32);
        powerBar.at(1).setPos(getPos().x + 32 + 8 + 4, getPos().y - 32 + 4 + 32 - 32*powerBar.at(1).getScale().y);
        if (velocity1D > 1)
        {
            velocity1D = 1;
            launchedVelocity1D = 1;
        }
        powerBar.at(1).setScale(1, velocity1D/1); //bao nhieu phan cua 1
    }
    else
    {
        //ball start rolling here

        //make swing sound
        if (!playedSwingFx)
        {
            Mix_PlayChannel(-1, swingSfx, 0);
            playedSwingFx = true;
            strokes++;
        }

        points.at(0).setPos(-64, -64);
        powerBar.at(0).setPos(-64, -64);
        powerBar.at(1).setPos(-64, -64);
        canMove = false;

//        if (wasInSand)
//        {
//           setPos(getPos().x + getVelocity().x*frictionSand, getPos().y + getVelocity().y*frictionSand); //update khong theo delta time, theo sand
//        } else {
        setPos(getPos().x + getVelocity().x*deltaTime, getPos().y + getVelocity().y*deltaTime); //update vi tri ball theo delta time
//        }

        if (getVelocity().x > 0.0001 || getVelocity().x < -0.0001 || getVelocity().y > 0.0001 || getVelocity().y < -0.0001) //neu van toc lon hon 0, tinh toan vantoc moi
        {
            //float xDir = velocity.x/abs(velocity.x);
            //float yDir = velocity.y/abs(velocity.y);

            //velocity.x = (abs(velocity.x) - friction*deltaTime)*xDir;
            //velocity.y = (abs(velocity.y) - friction*deltaTime)*yDir;

            //friction neu v>0
            if (velocity1D > 0)
            {
                velocity1D -= friction*deltaTime;
            }
            else
            {
                velocity1D = 0;
            }

            //update velocity theo cai goc^' hoac sand/ice
//            if (wasInSand) {
//                velocity.x = (velocity1D/launchedVelocity1D)*abs(launchedVelocity.x)*dirX*0.5;
//                velocity.y = (velocity1D/launchedVelocity1D)*abs(launchedVelocity.y)*dirY*0.5;
//            }
//            else {
                velocity.x = (velocity1D/launchedVelocity1D)*abs(launchedVelocity.x)*dirX;
                velocity.y = (velocity1D/launchedVelocity1D)*abs(launchedVelocity.y)*dirY;
//            }


        }
        else
        {
            //neu van toc bang 0, reset all
            setVelocity(0,0);
            int mouseX = 0;
	        int mouseY = 0;
            SDL_GetMouseState(&mouseX, &mouseY);
            setInitialMousePos(mouseX, mouseY);
            canMove = true;
        }

        //border map collision detection
        if (getPos().x + getCurrentFrame().w > 640)  //trc do split map la 640/(2-index)
        {
            setVelocity(-abs(getVelocity().x), getVelocity().y);
            dirX = -1;
        }
        else if (getPos().x < 0 )  //trc do split map la 0 + (index*320)
        {
            setVelocity(abs(getVelocity().x), getVelocity().y);
            dirX = 1;
        }
        else if (getPos().y + getCurrentFrame().h > 480)
        {
            setVelocity(getVelocity().x, -abs(getVelocity().y));
            dirY = -1;
        }
        else if (getPos().y < 0)
        {
           setVelocity(getVelocity().x, abs(getVelocity().y));
            dirY = 1;
        }

        //rectangle collision detection
        for (Tile& t : tiles)
	    {
		    float newX = getPos().x + getVelocity().x*deltaTime;
            float newY = getPos().y;

//            if (newX + 16 > t.getPos().x && newX < t.getPos().x + t.getCurrentFrame().w && newY + 16 > t.getPos().y && newY < t.getPos().y + t.getCurrentFrame().h - 3)
//            {
//                Mix_PlayChannel(-1, tileCollisionSfx, 0);
//            }

            if (newX + 16 > t.getPos().x && newX < t.getPos().x + t.getCurrentFrame().w && newY + 16 > t.getPos().y && newY < t.getPos().y + t.getCurrentFrame().h - 3)
            {
                setVelocity(getVelocity().x*-1, getVelocity().y);
                dirX *= -1;
            }

            newX = getPos().x;
            newY = getPos().y + getVelocity().y*deltaTime;
            if (newX + 16 > t.getPos().x && newX < t.getPos().x + t.getCurrentFrame().w && newY + 16 > t.getPos().y && newY < t.getPos().y + t.getCurrentFrame().h - 3)
            {
                setVelocity(getVelocity().x, getVelocity().y*-1);
                dirY *= -1;
            }
	    }

	    //circular collision detection - Phai tao array vector ms
//	    for (Tile& t : tiles)
//        {
//            bool CircleCollision32 = false;
//            bool CircleCollision64 = false;
//
//            float centerBall_X = getPos().x + 8;
//            float centerBall_Y = getPos().y + 8;
//            float centerCircleTile32_X = t.getPos().x + 16;
//            float centerCircleTile32_Y = t.getPos().y + 16;
//            float centerCircleTile64_X = t.getPos().x + 32;
//            float centerCircleTile64_Y = t.getPos().y + 32;
//        }

        //sandy sand sand - Van toc dang sai khi ra khoi cat
        for (Sand& s: sands)
        {
            float newX = getPos().x + getVelocity().x*deltaTime;
            float newY = getPos().y;

            if (newX + 16 > s.getPos().x && newX < s.getPos().x + s.getCurrentFrame().w && newY + 16 > s.getPos().y && newY < s.getPos().y + s.getCurrentFrame().h - 3)
            {
                setVelocity(getVelocity().x*frictionSand, getVelocity().y);
            }

            newX = getPos().x;
            newY = getPos().y + getVelocity().y*deltaTime;
            if (newX + 16 > s.getPos().x && newX < s.getPos().x + s.getCurrentFrame().w && newY + 16 > s.getPos().y && newY < s.getPos().y + s.getCurrentFrame().h - 3)
            {
                setVelocity(getVelocity().x, getVelocity().y*frictionSand);
            }

//            if (newX + 16 > s.getPos().x && newX < s.getPos().x + s.getCurrentFrame().w && newY + 16 > s.getPos().y && newY < s.getPos().y + s.getCurrentFrame().h - 3)
//            {
//                wasInSand = true;
//            }
        }

        //water wet wet
        for (Water& w: waters)
        {
            float newX = getPos().x + getVelocity().x*deltaTime;
            float newY = getPos().y;

            float initial_X = getInitialBallPos().x;
            float initial_Y = getInitialBallPos().y;

            //tao tieng water splash
            //phai copy 2 lan cai mix chunk (chac do cai X, Y thay doi nen cham vao canh 2 ben va canh o tren neu dat 1 cai chi ra tieng 1 cho
            if (newX + 16 > w.getPos().x && newX < w.getPos().x + w.getCurrentFrame().w && newY + 16 > w.getPos().y && newY < w.getPos().y + w.getCurrentFrame().h - 3)
            {
                Mix_PlayChannel(-1, waterSfx, 0);
            }

            //reset ve cho cu
            if (newX + 16 > w.getPos().x && newX < w.getPos().x + w.getCurrentFrame().w && newY + 16 > w.getPos().y && newY < w.getPos().y + w.getCurrentFrame().h - 3)
            {
                setPos(initial_X, initial_Y);
                setVelocity(0, 0);
            }

            //****for Y****

            newX = getPos().x;
            newY = getPos().y + getVelocity().y*deltaTime;

            //again
             if (newX + 16 > w.getPos().x && newX < w.getPos().x + w.getCurrentFrame().w && newY + 16 > w.getPos().y && newY < w.getPos().y + w.getCurrentFrame().h - 3)
            {
                Mix_PlayChannel(-1, waterSfx, 0);
            }

            if (newX + 16 > w.getPos().x && newX < w.getPos().x + w.getCurrentFrame().w && newY + 16 > w.getPos().y && newY < w.getPos().y + w.getCurrentFrame().h - 3)
            {
                setPos(initial_X, initial_Y);
                setVelocity(0, 0);
            }

        }

        //icy ice ice - speed up
        for (Ice& i: ices)
        {
            float newX = getPos().x + getVelocity().x*deltaTime;
            float newY = getPos().y;

            if (newX + 16 > i.getPos().x && newX < i.getPos().x + i.getCurrentFrame().w && newY + 16 > i.getPos().y && newY < i.getPos().y + i.getCurrentFrame().h - 3)
            {
                setVelocity(getVelocity().x*sliperyIce, getVelocity().y);
            }

            newX = getPos().x;
            newY = getPos().y + getVelocity().y*deltaTime;
            if (newX + 16 > i.getPos().x && newX < i.getPos().x + i.getCurrentFrame().w && newY + 16 > i.getPos().y && newY < i.getPos().y + i.getCurrentFrame().h - 3)
            {
                setVelocity(getVelocity().x, getVelocity().y*sliperyIce);
            }
        }

        //spring bouncy bounce
        for (Spring& s : springs)
	    {
		    float newX = getPos().x + getVelocity().x*deltaTime;
            float newY = getPos().y;

            if (newX + 16 > s.getPos().x && newX < s.getPos().x + s.getCurrentFrame().w && newY + 16 > s.getPos().y && newY < s.getPos().y + s.getCurrentFrame().h - 3)
            {
                Mix_PlayChannel(-1, bounceSfx, 0);
            }

            if (newX + 16 > s.getPos().x && newX < s.getPos().x + s.getCurrentFrame().w && newY + 16 > s.getPos().y && newY < s.getPos().y + s.getCurrentFrame().h - 3)
            {
                setVelocity(getVelocity().x*-1, getVelocity().y);
                velocity1D += bouncySpring;
                dirX *= -1;
            }

            //****for Y****

            newX = getPos().x;
            newY = getPos().y + getVelocity().y*deltaTime;

            if (newX + 16 > s.getPos().x && newX < s.getPos().x + s.getCurrentFrame().w && newY + 16 > s.getPos().y && newY < s.getPos().y + s.getCurrentFrame().h - 3)
            {
                Mix_PlayChannel(-1, bounceSfx, 0);
            }


            if (newX + 16 > s.getPos().x && newX < s.getPos().x + s.getCurrentFrame().w && newY + 16 > s.getPos().y && newY < s.getPos().y + s.getCurrentFrame().h - 3)
            {
                setVelocity(getVelocity().x, getVelocity().y*-1);
                velocity1D += bouncySpring;
                dirY *= -1;
            }
	    }

    }

}
