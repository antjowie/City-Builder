#include "AnimationHandler.h"
#include <math.h>

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

void AnimationHandler::AddAnim(Animation & anim)
{
	animations.push_back(anim);
}

void AnimationHandler::ChangeAnim(unsigned int animNum)
{
	if (currentAnim == animNum || animNum >= animations.size() || animNum < 0) return;

	currentAnim = animNum;

	sf::IntRect rect = frameSize;
	rect.top = rect.height * animNum;
	bounds = rect;
	elapsed = fmod(elapsed, animations.at(animNum).duration);
}

void AnimationHandler::Update(const float dt)
{
	if (currentAnim >= animations.size() || currentAnim < 0) return;

	const float duration = animations.at(currentAnim).duration;

	if (int(elapsed + dt) > int(duration)) {
		int frame = (elapsed + dt) / duration;

		frame %= animations.at(currentAnim).GetLength();

		sf::IntRect rect = frameSize;
		rect.left = rect.width* frame;
		rect.top = rect.height* currentAnim;
		bounds = rect;
	}

	elapsed += dt;
	if (elapsed > duration* animations.at(currentAnim).GetLength())
		elapsed = fmod(elapsed,duration*animations.at(currentAnim).GetLength());
}

AnimationHandler::AnimationHandler():
	elapsed(0.f),
	currentAnim(-1)
{
}

AnimationHandler::AnimationHandler(const sf::IntRect & frameSize):
	AnimationHandler()
{
	this->frameSize = frameSize;
}
