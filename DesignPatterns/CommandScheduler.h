#pragma once

#include "ICommand.h"

#include <vector>
#include <memory>

class CommandScheduler
{
public:
	void AddCommandToQueue(std::shared_ptr<ICommand> command);
	void ExecuteFirstCommand();
	void RemovePreparedCommand();
	void RemoveLastCommand();

	std::vector <std::shared_ptr<ICommand>> commandQueue{};
};

