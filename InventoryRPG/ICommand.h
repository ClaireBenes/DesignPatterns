#pragma once

class ICommand
{
public:
	virtual bool Execute() = 0;
};
