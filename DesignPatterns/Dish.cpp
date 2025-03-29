#include "Dish.h"

#include "CommandScheduler.h"
#include "GameManager.h"

Dish::Dish(float newTimeToPrepare, int newID)
{
	timeToPrepare = newTimeToPrepare;
	id = newID;
}

void Dish::Init()
{
	//Choose new random image
	float randomImages = rand() % dishData->allFoodImages.size();
	foodImage = dishData->allFoodImages[randomImages];
	posY = 370;
}

void Dish::Update()
{
}

void Dish::Draw()
{
	DrawTextureEx(foodImage, { posX,posY }, 0, dishData->size, WHITE);
}

void Dish::OnNotify()
{
	//Erase object when dish is finished
	printf("DISH %i IS FINISHED !!\n", id);

	//Find location of the dish in allDishes array -> replace it with nullptr
	auto& allDishes = gameManager->allDishes;
	auto it = std::find(allDishes.begin(), allDishes.end(), shared_from_this());
	if (it == allDishes.end())
	{
		return;
	}

	*it = nullptr;

	gameManager->EraseObject(shared_from_this());
}

Texture2D Dish::GetFoodImage()
{
	return foodImage;
}

void Dish::ChangeDishData(std::shared_ptr<DishData> newData)
{
	dishData = newData;
}
