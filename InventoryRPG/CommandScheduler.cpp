#include "CommandScheduler.h"
#include "ICommand.h"

CommandScheduler::CommandScheduler()
{
	instance = this;
}

void CommandScheduler::AddCommandToQueue(ICommand* command)
{
	commandQueue.push_back(command);
}

void CommandScheduler::ExecuteNextCommand()
{
	commandQueue.front()->Execute();
}

void CommandScheduler::RemovePreparedCommand()
{
	commandQueue.erase(commandQueue.begin());
}

void CommandScheduler::RemoveLastCommand()
{
	commandQueue.erase(commandQueue.begin() + commandQueue.size());
}

CommandScheduler* CommandScheduler::GetInstance()
{
	return instance;
}
