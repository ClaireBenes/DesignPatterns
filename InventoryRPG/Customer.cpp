#include "Customer.h"

void Customer::Init()
{
	posX = GetScreenWidth();
	posY = 250;
}

void Customer::Update()
{
	posX -= customerData->speed;

}

void Customer::Draw()
{
	DrawTextureEx(customerData->customerImages, { posX,posY }, 0, customerData->size, WHITE);
}

void Customer::ChangeCustomerData(std::shared_ptr<CustomerData> newData)
{
	customerData = newData;
}
