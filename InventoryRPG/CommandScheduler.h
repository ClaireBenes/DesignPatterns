#pragma once

#include "vector"

#include "ICommand.h"

class CommandScheduler
{
public:
	void AddCommandToQueue(ICommand* command);
	void ExecuteFirstCommand();
	void RemovePreparedCommand();
	void RemoveLastCommand();

	std::vector <ICommand*> commandQueue{};
};

