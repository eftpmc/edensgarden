#include <SFML/Audio.hpp>
#include <iostream>
#include <deque>
#include <algorithm>
#include <random>

class MusicPlayer {
private:
	sf::Music music;
	std::deque<std::string> trackQueue;
	int currentTrackIndex = 0;

	void playCurrentTrack() {
		if (currentTrackIndex >= 0 && static_cast<size_t>(currentTrackIndex) < trackQueue.size()) {
			if (!music.openFromFile(trackQueue[currentTrackIndex])) {
				std::cerr << "Failed to load music file: " << trackQueue[currentTrackIndex] << "\n";
			}
			else {
				music.play();
			}
		}
	}

public:
	void playPause() {
		if (music.getStatus() == sf::Music::Playing) {
			music.pause();
		}
		else if (!trackQueue.empty()) {
			playCurrentTrack();
		}
	}

	void setVolume(float volume) {
		music.setVolume(volume);
	}

	void next() {
		if (!trackQueue.empty()) {
			currentTrackIndex++;
			if (static_cast<size_t>(currentTrackIndex) >= trackQueue.size()) {
				currentTrackIndex = 0;
			}
			playCurrentTrack();
		}
	}

	void previous() {
		if (!trackQueue.empty()) {
			if (--currentTrackIndex < 0) {
				currentTrackIndex = trackQueue.size() - 1;
			}
			playCurrentTrack();
		}
	}

	void shuffle() {
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(trackQueue.begin(), trackQueue.end(), g);
		currentTrackIndex = 0;
		playCurrentTrack();
	}

	void addTrackToQueue(const std::string& trackPath) {
		trackQueue.push_back(trackPath);
	}

	void removeCurrentTrack() {
		if (!trackQueue.empty()) {
			trackQueue.erase(trackQueue.begin() + currentTrackIndex);
			playCurrentTrack();
		}
	}
};

int main() {
	MusicPlayer player;

	char choice;
	while (true) {
		std::cout << "\nMenu:\n";
		std::cout << "a: Play/Pause, b: Volume, c: Previous, d: Next, e: Shuffle, f: Add Track, g: Remove Track, h: Exit\n";
		std::cin >> choice;
		std::cin.ignore();  // To consume the newline character

		switch (choice) {
		case 'a':
			player.playPause();
			break;
		case 'b':
			float volume;
			std::cout << "Enter volume (0 to 100): ";
			std::cin >> volume;
			player.setVolume(volume);
			break;
		case 'c':
			player.previous();
			break;
		case 'd':
			player.next();
			break;
		case 'e':
			player.shuffle();
			break;
		case 'f':
		{
			std::string trackPath;
			std::cout << "Enter path of the track to add to queue: ";
			std::getline(std::cin, trackPath);
			player.addTrackToQueue(trackPath);
			break;
		}
		case 'g':
			player.removeCurrentTrack();
			break;
		case 'h':
			return 0;
		default:
			std::cout << "Invalid choice\n";
			break;
		}
	}

	return 0;
}
