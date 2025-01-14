#pragma once

#include "raylib.h"

#include <vector>

struct DishData
{
	std::vector<Texture2D> allFoodImages
	{ 
		LoadTexture("ressource/Food/06_apple_pie_dish.png"),
		LoadTexture("ressource/Food/33_curry_dish.png"),
		LoadTexture("ressource/Food/41_eggsalad_bowl.png"),
		LoadTexture("ressource/Food/45_frenchfries_dish.png"),
		LoadTexture("ressource/Food/58_icecream_bowl.png"),
		LoadTexture("ressource/Food/72_nacho_dish.png"),
		LoadTexture("ressource/Food/74_omlet_dish.png"),
		LoadTexture("ressource/Food/80_pancakes_dish.png"),
		LoadTexture("ressource/Food/86_roastedchicken_dish.png"),
		LoadTexture("ressource/Food/91_strawberrycake_dish.png")
	};

	Texture2D foodImage = allFoodImages[0];

	float size = 5;
};
