#pragma once

#include "ICommand.h"

class PrepareDishes : public ICommand
{
public:
	void Execute() override;

private:
	float timeToPrepare = 2.0f;
};

