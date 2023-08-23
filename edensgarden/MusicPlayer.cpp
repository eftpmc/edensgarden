// MusicPlayer.cpp

#include "MusicPlayer.h"
#include <iostream>
#include <algorithm>
#include <random>

MusicPlayer::MusicPlayer() : currentTrackIndex(0) {}

void MusicPlayer::playCurrentTrack() {
	if (currentTrackIndex >= 0 && static_cast<size_t>(currentTrackIndex) < trackQueue.size()) {
		if (!music.openFromFile(trackQueue[currentTrackIndex])) {
			std::cerr << "Failed to load music file: " << trackQueue[currentTrackIndex] << "\n";
		}
		else {
			music.play();
		}
	}
}

void MusicPlayer::playPause() {
	if (music.getStatus() == sf::Music::Playing) {
		music.pause();
	}
	else if (!trackQueue.empty()) {
		playCurrentTrack();
	}
}

void MusicPlayer::setVolume(float volume) {
	music.setVolume(volume);
}

void MusicPlayer::next() {
	if (!trackQueue.empty()) {
		currentTrackIndex++;
		if (static_cast<size_t>(currentTrackIndex) >= trackQueue.size()) {
			currentTrackIndex = 0;
		}
		playCurrentTrack();
	}
}

void MusicPlayer::previous() {
	if (!trackQueue.empty()) {
		if (--currentTrackIndex < 0) {
			currentTrackIndex = trackQueue.size() - 1;
		}
		playCurrentTrack();
	}
}

void MusicPlayer::shuffle() {
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(trackQueue.begin(), trackQueue.end(), g);
	currentTrackIndex = 0;
	playCurrentTrack();
}

void MusicPlayer::addTrackToQueue(const std::string& trackPath) {
	trackQueue.push_back(trackPath);
}

void MusicPlayer::removeCurrentTrack() {
	if (!trackQueue.empty()) {
		trackQueue.erase(trackQueue.begin() + currentTrackIndex);
		playCurrentTrack();
	}
}
