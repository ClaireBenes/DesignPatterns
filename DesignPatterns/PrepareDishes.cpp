#include "PrepareDishes.h"

#include "raylib.h"

PrepareDishes::PrepareDishes(std::shared_ptr<Dish> newDish)
{
	dish = newDish;
	currentCookingTime = dish->timeToPrepare;
	onCooked.AddObserver(newDish);

	printf("Scheduled a dish preparation with ID %i\n", dish->id);
}

bool PrepareDishes::Execute()
{
	float dt = GetFrameTime();
	currentCookingTime -= dt;

	if(currentCookingTime <= 0.0f)
	{
		onCooked.Notify();
		printf("onCooked from PrepareDishes of dish ID %i\n", dish->id);
		return true;
	}

	return false;
}
