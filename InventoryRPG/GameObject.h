#pragma once

#include "raylib.h"

#include <memory>
#include <cmath>

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;

	float posX, posY;
	float size;
};

