#include "Includes.h"

Sound* Sound::instance = nullptr;

Sound::Sound() {
	instance = this;
}

void Sound::loadSounds() {

	if (!std::filesystem::exists("Sound/mixkit-arcade-retro-game-over-213.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla konca gry.");
	}
	endBuffer.loadFromFile("Sound/mixkit-arcade-retro-game-over-213.wav");

	if (!std::filesystem::exists("Sound/d0e4-676a-484b-b3f5-817d482dbdef.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla przeciwnika.");
	}
	enemyBuffer.loadFromFile("Sound/d0e4-676a-484b-b3f5-817d482dbdef.wav");

	if (!std::filesystem::exists("Sound/8-bit-kit-lazer-6_B_minor.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla gracza.");
	}
	playerBuffer.loadFromFile("Sound/8-bit-kit-lazer-6_B_minor.wav");

	if (!std::filesystem::exists("Sound/mixkit-space-coin-win-notification-271.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla menu-click.");
	}
	clickBuffer.loadFromFile("Sound/mixkit-space-coin-win-notification-271.wav");

	if (!std::filesystem::exists("Sound/mixkit-negative-game-notification-249.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla enter.");
	}
	enterBuffer.loadFromFile("Sound/mixkit-negative-game-notification-249.wav");

	if (!std::filesystem::exists("Sound/affc-40a7-4b4c-8289-6c0790ff4436.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla score.");
	}
	scoreBuffer.loadFromFile("Sound/affc-40a7-4b4c-8289-6c0790ff4436.wav");

	if (!std::filesystem::exists("Sound/8-bit-explosion_F.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla shoot.");
	}
	shootBuffer.loadFromFile("Sound/8-bit-explosion_F.wav");

	if (!std::filesystem::exists("Sound/Omnious 4 cut.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla score screen.");
	}
	scoreScreenBuffer.loadFromFile("Sound/Omnious 4 cut.wav");

	if (!std::filesystem::exists("Sound/c612-354d-423b-8e8b-322eb3e9a143.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla typing.");
	}
	typingBuffer.loadFromFile("Sound/c612-354d-423b-8e8b-322eb3e9a143.wav");

	if (!std::filesystem::exists("Sound/6848-801d-4285-b762-d399c539557f.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla correct.");
	}
	correctBuffer.loadFromFile("Sound/6848-801d-4285-b762-d399c539557f.wav");

	if (!std::filesystem::exists("Sound/bdfb-3702-4f69-8dfa-c797ff1c3196.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla error.");
	}
	errorBuffer.loadFromFile("Sound/bdfb-3702-4f69-8dfa-c797ff1c3196.wav");

	if (!std::filesystem::exists("Sound/robots-pecan-pie-main-version-01-22-9282.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla muzyki.");
	}
	musicBuffer.loadFromFile("Sound/robots-pecan-pie-main-version-01-22-9282.wav");

	if (!std::filesystem::exists("Sound/mixkit-quick-jump-arcade-game-239.wav")) {
		throw std::runtime_error("Nie ma dzwieku dla delete.");
	}
	deleteBuffer.loadFromFile("Sound/mixkit-quick-jump-arcade-game-239.wav");
}
