#pragma once

#include "raylib.h"
#include <vector>

struct CustomerData
{
	std::vector<Texture2D> allCustomerImages
	{
		LoadTexture("ressource/Character/00_Female1.png"),
		LoadTexture("ressource/Character/00_Female2.png"),
		LoadTexture("ressource/Character/00_Male3.png"),
		LoadTexture("ressource/Character/00_Male4.png"),
		LoadTexture("ressource/Character/24_Female1.png"),
		LoadTexture("ressource/Character/24_Female2.png"),
		LoadTexture("ressource/Character/24_Male3.png"),
		LoadTexture("ressource/Character/24_Male4.png"),
		LoadTexture("ressource/Character/48_Female1.png"),
		LoadTexture("ressource/Character/48_Female2.png"),
		LoadTexture("ressource/Character/48_Male3.png"),
		LoadTexture("ressource/Character/48_Male4.png"),
		LoadTexture("ressource/Character/72_Female1.png"),
		LoadTexture("ressource/Character/72_Female2.png"),
		LoadTexture("ressource/Character/72_Male3.png"),
		LoadTexture("ressource/Character/72_Male4.png"),
	};

	float speed = 100;
	float size = 7;
};

