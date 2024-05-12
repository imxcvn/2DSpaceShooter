#include "Includes.h"

sf::Rect<float> GameObject::getGlobalBounds() const {
	sf::Rect<float> localBounds = getLocalBounds();
	localBounds.left += px;
	localBounds.top += py;
	return localBounds;
}