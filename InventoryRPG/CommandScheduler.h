#pragma once

#include "vector"

#include "ICommand.h"

class CommandScheduler
{
public:
	CommandScheduler();

	void AddCommandToQueue(ICommand* command);
	void ExecuteNextCommand();
	void RemovePreparedCommand();
	void RemoveLastCommand();

	std::vector <ICommand*> commandQueue{};

	static CommandScheduler* GetInstance();

private:
	static CommandScheduler* instance;
};

