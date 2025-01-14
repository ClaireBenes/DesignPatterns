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
}

void Dish::Update()
{
	posX = GetScreenWidth() / 2; - foodImage.width;
	posY = 50;
}

void Dish::Draw()
{
	DrawTextureEx(foodImage, { posX,posY }, 0, dishData->size, WHITE);
}

void Dish::OnNotify()
{
	//Erase object when dish is finished
	printf("DISH %i IS FINISHED !!\n", id);
	UnloadTexture(foodImage);
	gameManager->EraseObject(shared_from_this());
}

void Dish::ChangeDishData(std::shared_ptr<DishData> newData)
{
	dishData = newData;
}
