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
	float GetTextureWidth();

	std::shared_ptr<CustomerData> customerData;

	const float toGoPos = 200;
	float waitingPos = toGoPos;
	bool willBeDestroyed = false;

private:
	Texture2D customerImage = LoadTexture("ressource/Character/00_Female1.png");
};

