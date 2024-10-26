#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

//class Song
class Song {
private:
    string Title;
    string Artist;
    string Genre;
    double Duration;

public:
    // Constructor
    Song(string title, string artist, string genre, double duration)
        : Title(title), Artist(artist), Genre(genre), Duration(duration) {}

    // Getters
    string getTitle() const { return Title; }
    string getArtist() const { return Artist; }
    string getGenre() const { return Genre; }
    double getDuration() const { return Duration; }
    
    // Display song info
    void displaySong() const {
        cout << "Title: "<<Title <<"\t\t";
        cout << "Artist: "<<Artist <<"\t\t";
        cout << "Genre: "<<Genre <<"\t\t";
        cout << "Duration: "<<Duration << " minutes" << endl;
    }
};