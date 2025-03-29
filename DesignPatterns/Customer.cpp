#include "Customer.h"

#include "GameManager.h"

void Customer::Init()
{
	//Choose new random image
	float randomImages = rand() % customerData->allCustomerImages.size();
	customerImage = customerData->allCustomerImages[randomImages];

	posX = GetScreenWidth();
	posY = 250;
}

void Customer::Update()
{
	//Go to a certain pos
	if(posX > waitingPos)
	{
		posX -= customerData->speed * GetFrameTime();
	}
	//Will be destroyed if at a certain pos and ready to be destroyed
	else if(willBeDestroyed)
	{
		gameManager->EraseObject(shared_from_this());
	}
}

void Customer::Draw()
{
	DrawTextureEx(customerImage, { posX,posY }, 0, customerData->size, WHITE);
}

void Customer::ChangeCustomerData(std::shared_ptr<CustomerData> newData)
{
	customerData = newData;
}

float Customer::GetTextureWidth()
{
	return customerImage.width;
}
