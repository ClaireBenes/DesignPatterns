#pragma once

#include "raylib.h"

struct CustomerData
{
	Texture2D customerImages = LoadTexture("ressource/Female1.png");
	float speed = 100;
	float size = 5;
	float waitingPos = 200;
};

