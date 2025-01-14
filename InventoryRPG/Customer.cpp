#include "Customer.h"

void Customer::Update()
{
	//posX += customerData->speed
}

void Customer::Draw()
{
	posX = 50;
	posY = 50;
	DrawTextureEx(customerData->customerImages, { posX,posY }, 0, customerData->size, WHITE);
}

void Customer::ChangeCustomerData(std::shared_ptr<CustomerData> newData)
{
	customerData = newData;
}
