#pragma once
#include <string>
#include <vector>

class GameManager
{
public :
	void Init();
	void Update();
	void Draw();
	void Unload();


private:

	const float timeToPrepare = 2.0f;
	float remainingTime = timeToPrepare;
};

