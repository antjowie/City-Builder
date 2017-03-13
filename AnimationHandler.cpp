#include "AnimationHandler.h"

unsigned int Animation::GetLength() const
{
	return endFrame - startFrame + 1;
}

Animation::Animation(const unsigned int startFrame, const unsigned int endFrame, const float duration):
	startFrame(startFrame),
	endFrame(endFrame),
	duration(duration)
{
}
