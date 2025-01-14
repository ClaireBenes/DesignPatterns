#pragma once

#include "GameObject.h"
#include "CustomerData.h"

#include <memory>
#include <cmath>


class Customer : public GameObject
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;

	void ChangeCustomerData(std::shared_ptr<CustomerData> newData);

	std::shared_ptr<CustomerData> customerData;
};

