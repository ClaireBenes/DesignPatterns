#pragma once

#include "vector"

class ICommand;

class CommandScheduler
{
public:
	CommandScheduler();

	void AddCommandToQueue(ICommand* command);
	void ExecuteNextCommand();
	void RemovePreparedCommand();
	void RemoveLastCommand();

	static std::vector <ICommand*> commandQueue;
	static CommandScheduler* GetInstance();

private:
	static CommandScheduler* instance;
};

