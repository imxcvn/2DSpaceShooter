#pragma once

class Sound {
public:
	static Sound* instance;
	sf::SoundBuffer endBuffer;
	sf::SoundBuffer enemyBuffer;
	sf::SoundBuffer playerBuffer;
	sf::SoundBuffer clickBuffer;
	sf::SoundBuffer enterBuffer;
	sf::SoundBuffer scoreBuffer;
	sf::SoundBuffer shootBuffer;
	sf::SoundBuffer scoreScreenBuffer;
	sf::SoundBuffer typingBuffer;
	sf::SoundBuffer correctBuffer;
	sf::SoundBuffer errorBuffer;
	sf::SoundBuffer musicBuffer;
	sf::SoundBuffer deleteBuffer;
	Sound();
	void loadSounds();
};