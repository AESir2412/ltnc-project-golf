#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.h"
#include "Math.h"

class Sand: public Entity
{
    public:
    Sand(Vector2f p_pos, SDL_Texture* p_tex);

    private:
};

