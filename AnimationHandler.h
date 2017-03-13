#pragma once

#include "SFML\Graphics.hpp"
#include <vector>

struct Animation
{
	unsigned int startFrame;
	unsigned int endFrame;

	float duration;

	unsigned int GetLength() const;

	Animation(const unsigned int startFrame, const unsigned int endFrame, const float duration);
};

class AnimationHandler
{
private:
	std::vector<Animation> animations;

	float elapsed;

public:
	// Selection of the texture that should be displayed
	sf::IntRect bounds;
	sf::IntRect frameSize;

	void AddAnim(Animation& anim);
	void ChangeAnim(unsigned int animNum);
	void Update(const float dt);

	AnimationHandler();
	AnimationHandler(const sf::IntRect& frameSize);
};