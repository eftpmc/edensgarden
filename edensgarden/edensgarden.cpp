#include "MusicPlayer.h"
#include "YouTubeDownloader.h"  // Include the YouTubeDownloader class
#include <iostream>

int main() {
	MusicPlayer player;
	YouTubeDownloader downloader;  // Create an instance of YouTubeDownloader

	char choice;
	while (true) {
		std::cout << "\nMenu:\n";
		std::cout << "a: Play/Pause, b: Volume, c: Previous, d: Next, e: Shuffle, f: Add Track from Filesystem, g: Remove Track, h: Add Song from YouTube, i: Add Playlist from YouTube, j: Exit\n";
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
		{
			std::string videoURL;
			std::cout << "Enter YouTube video URL: ";
			std::getline(std::cin, videoURL);
			if (downloader.downloadVideo(videoURL)) {
				std::cout << "Song downloaded successfully!" << std::endl;
			}
			else {
				std::cerr << "Download failed!" << std::endl;
			}
			break;
		}
		case 'i':
		{
			std::string playlistURL;
			std::cout << "Enter YouTube playlist URL: ";
			std::getline(std::cin, playlistURL);
			if (downloader.downloadPlaylist(playlistURL)) {
				std::cout << "Playlist downloaded successfully!" << std::endl;
			}
			else {
				std::cerr << "Download failed!" << std::endl;
			}
			break;
		}
		case 'j':
			return 0;
		default:
			std::cout << "Invalid choice\n";
			break;
		}
	}

	return 0;
}
