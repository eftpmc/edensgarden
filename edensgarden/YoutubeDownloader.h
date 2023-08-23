class YouTubeDownloader {
private:
	const std::string outputPath = "downloads/";  // Save files in a "downloads" directory

	bool executeCommand(const std::string& command) {
		int result = system(command.c_str());
		return result == 0;  // return true if command executed successfully
	}

public:
	bool downloadVideo(const std::string& url) {
		std::string command = "yt-dlp --extract-audio --audio-format mp3 -o \"" + outputPath + "%(title)s.%(ext)s\" " + url;
		return executeCommand(command);
	}

	bool downloadPlaylist(const std::string& url) {
		std::string command = "yt-dlp --yes-playlist --extract-audio --audio-format mp3 -o \"" + outputPath + "%(title)s.%(ext)s\" " + url;
		return executeCommand(command);
	}
};
