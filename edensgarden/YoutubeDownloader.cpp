#include "YouTubeDownloader.h"
#include <cstdlib> // for system()

YouTubeDownloader::YouTubeDownloader() {}

bool YouTubeDownloader::downloadVideo(const std::string& url, const std::string& outputPath) {
	std::string command = "youtube-dl --extract-audio --audio-format mp3 -o \"" + outputPath + "%(title)s.%(ext)s\" " + url;
	int result = system(command.c_str());
	return result == 0; // assuming youtube-dl returns 0 on success
}

bool YouTubeDownloader::downloadPlaylist(const std::string& url, const std::string& outputDir) {
	// Similar command but optimized for playlists
	std::string command = "youtube-dl --yes-playlist --extract-audio --audio-format mp3 -o \"" + outputDir + "%(title)s.%(ext)s\" " + url;
	int result = system(command.c_str());
	return result == 0;
}
