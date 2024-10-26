#include <algorithm>
#include "class_song_ver2.h"

//class Playlist
class Playlist {
private:
    string Name;
    vector<Song> Songs;

public:
    // Constructor
    Playlist(string name) : Name(name) {}

    // Getter
    string getName() const { return Name; }

    // Add song to playlist
    void addSong(const Song& song) {
        Songs.push_back(song);
        cout << "Successfully added to playlist " << Name << ".\n";
    }

    // Remove song from playlist
    void removeSong(const string& title) {
        for (auto it = Songs.begin(); it != Songs.end(); ++it) {
            if (it->getTitle() == title) {
                Songs.erase(it);
                cout << "Successfully removed from playlist " << Name << ".\n";
                return;
            }
        }
        cout << "Song not found in playlist " << Name << ".\n";
    }

    // Display songs
    void listSongs() const {
        if (Songs.empty()) {
            cout << "The playlist " << Name << " is empty.\n";
            return;
        }
        cout << "Songs in playlist " << Name << ":\n";
        for (const auto& song : Songs) {
            song.displaySong();
        }
    }

    // Display songs by artist
    void displaySongsByArtist(const string& artist) const {
        bool found = false;
        for (const auto& song : Songs) {
            if (song.getArtist() == artist) {
                song.displaySong();
                found = true;
            }
        }
        if (!found) {
            cout << "No songs by " << artist << " found in playlist " << Name << ".\n";
        }
    }

    // Display songs by title
    void displaySongsByTitle(const string& title) const {
        bool found = false;
        for (const auto& song : Songs) {
            if (song.getTitle() == title) {
                song.displaySong();
                found = true;
            }
        }
        if (!found) {
            cout << "No song with title '" << title << "' found in playlist " << Name << ".\n";
        }
    }

    // Display songs by genre
    void displaySongsByGenre(const string& genre) const {
        bool found = false;
        for (const auto& song : Songs) {
            if (song.getGenre() == genre) {
                song.displaySong();
                found = true;
            }
        }
        if (!found) {
            cout << "No genre '" << genre << "' in playlist " << Name << ".\n";
        }
    }

    // Playlist duration
    void playlistDuration() const {
        double totalDuration = 0;
        for (const auto& song : Songs) {
            totalDuration += song.getDuration();
        }
        cout << "The duration of playlist " << Name << " is " << totalDuration << " minutes.\n";
    }

    // Sort song by duration
    void sortSongsByDuration() {
        sort(Songs.begin(), Songs.end(), [](const Song& a, const Song& b) {
            return a.getDuration() < b.getDuration();
        });
        cout << "Songs in playlist " << Name << " sorted by duration.\n";
    }

};

//class PlaylistManager
class PlaylistManager {
private:
    vector<Playlist> Playlists;
    int currentPlaylistIndex = -1;

public:
    void createPlaylist(const string& name) {
        Playlists.push_back(Playlist(name));
        currentPlaylistIndex = Playlists.size() - 1;
        cout << "Playlist '" << name << "' created and selected.\n";
    }

    void showPlaylists() const {
        if (Playlists.empty()) {
            cout << "No playlists available.\n";
            return;
        }
        cout << "Available playlists:\n";
        for (size_t i = 0; i < Playlists.size(); ++i) {
            cout << i + 1 << ". " << Playlists[i].getName() << endl;
        }
    }

    void switchPlaylist(const string& name) {
        for (size_t i = 0; i < Playlists.size(); ++i) {
            if (Playlists[i].getName() == name) {
                currentPlaylistIndex = i;
                cout << "Switched to playlist '" << name << "'.\n";
                return;
            }
        }
        cout << "Playlist '" << name << "' not found.\n";
    }

    void deletePlaylist(const string& name) {
        for (size_t i = 0; i < Playlists.size(); ++i) {
            if (Playlists[i].getName() == name) {
                Playlists.erase(Playlists.begin() + i);
                if (currentPlaylistIndex == i) {
                    currentPlaylistIndex = -1;
                }
                cout << "Playlist '" << name << "' deleted.\n";
                return;
            }
        }
        cout << "Playlist '" << name << "' not found.\n";
    }

    void addSongToPlaylist(const string& title, const string& artist, const string& genre, double duration) {
        if (currentPlaylistIndex == -1) {
            cout << "No playlist selected. Please create or select a playlist.\n";
            return;
        }
        Song song(title, artist, genre, duration);
        Playlists[currentPlaylistIndex].addSong(song);
    }

    void removeSongFromPlaylist(const string& title) {
        if (currentPlaylistIndex == -1) {
            cout << "No playlist selected. Please create or select a playlist.\n";
            return;
        }
        Playlists[currentPlaylistIndex].removeSong(title);
    }

    void displayPlaylistSongs() const {
        if (currentPlaylistIndex == -1) {
            cout << "No playlist selected. Please create or select a playlist.\n";
            return;
        }
        Playlists[currentPlaylistIndex].listSongs();
    }

    void displaySongsByArtist(const string& artist) const {
        if (currentPlaylistIndex == -1) {
            cout << "No playlist selected. Please create or select a playlist.\n";
            return;
        }
        Playlists[currentPlaylistIndex].displaySongsByArtist(artist);
    }

    void displaySongsByTitle(const string& title) const {
        if (currentPlaylistIndex == -1) {
            cout << "No playlist selected. Please create or select a playlist.\n";
            return;
        }
        Playlists[currentPlaylistIndex].displaySongsByTitle(title);
    }

    void displaySongsByGenre(const string& genre) const {
        if (currentPlaylistIndex == -1) {
            cout << "No playlist selected. Please create or select a playlist.\n";
            return;
        }
        Playlists[currentPlaylistIndex].displaySongsByGenre(genre);
    }

    void displayPlaylistDuration() const {
        if (currentPlaylistIndex == -1) {
            cout << "No playlist selected. Please create or select a playlist.\n";
            return;
        }
        Playlists[currentPlaylistIndex].playlistDuration();
    }

    void sortPlaylistByDuration() {
        if (currentPlaylistIndex == -1) {
            cout << "No playlist selected. Please create or select a playlist.\n";
            return;
        }
        Playlists[currentPlaylistIndex].sortSongsByDuration();
        Playlists[currentPlaylistIndex].listSongs();
    }
};