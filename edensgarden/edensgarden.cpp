// main.cpp

#include "MusicPlayer.h"
#include <iostream>

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
