#include "PrepareDishes.h"

#include "raylib.h"

void PrepareDishes::Execute()
{
	static float timeElapsed = 0.0f;
	timeElapsed += GetFrameTime();
	if(timeElapsed >= timeToPrepare)
	{
		timeElapsed -= mTimeOfCountdown;
		mCountdown--;
	}

	return ( mCountdown == 0 );
}
