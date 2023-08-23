// MusicPlayer.h

#pragma once

#include <SFML/Audio.hpp>
#include <deque>
#include <string>

class MusicPlayer {
private:
	sf::Music music;
	std::deque<std::string> trackQueue;
	int currentTrackIndex;

	void playCurrentTrack();

public:
	MusicPlayer();

	void playPause();
	void setVolume(float volume);
	void next();
	void previous();
	void shuffle();
	void addTrackToQueue(const std::string& trackPath);
	void removeCurrentTrack();
};
