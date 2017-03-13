#pragma once
class AnimationHandler
{
private:

public:
};

struct Animation
{
	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	unsigned int GetLength() const;

	Animation(const unsigned int startFrame, const unsigned int endFrame, const float duration);
};