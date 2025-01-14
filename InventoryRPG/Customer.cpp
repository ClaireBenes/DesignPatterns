#include "Customer.h"
#include "raylib.h"

void Customer::Init()
{
	posX = GetScreenWidth();
	posY = 250;
}

void Customer::Update()
{
	if(posX > customerData->waitingPos)
	{
		posX -= customerData->speed * GetFrameTime();
	}
}

void Customer::Draw()
{
	DrawTextureEx(customerData->customerImages, { posX,posY }, 0, customerData->size, WHITE);

	DrawLine(posX, posY, customerData->waitingPos, posY, RED);
}

void Customer::ChangeCustomerData(std::shared_ptr<CustomerData> newData)
{
	customerData = newData;
}
