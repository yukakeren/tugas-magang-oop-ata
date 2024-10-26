#include "playlist_manager.h"

void pressEnterToContinue();

int main() {
    PlaylistManager manager;
    int choice;
    string title, artist, genre, playlistName;
    double duration;

    //infoin menu
    cout << "\nPlaylist Management Menu\n";
    cout << "1. Create Playlist\n";
    cout << "2. Switch Playlist\n";
    cout << "3. Delete Playlist\n";
    cout << "4. Add Song to Playlist\n";
    cout << "5. Remove Song from Playlist\n";
    cout << "6. Display Playlist Songs\n";
    cout << "7. Display Songs by Artist\n";
    cout << "8. Display Songs by Title\n";
    cout << "9. Display Songs by Genre\n";
    cout << "10. Display Playlist Duration\n";
    cout << "11. Show All Playlists\n";
    cout << "12. Sort Song in PLaylist By Duration \n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice != 0) {
        switch (choice) {
            case 1:
                cout << "Enter playlist name: ";
                cin.ignore();
                getline(cin, playlistName);
                manager.createPlaylist(playlistName);
                break;
            case 2:
                cout << "Enter playlist name to switch to: ";
                cin.ignore();
                getline(cin, playlistName);
                manager.switchPlaylist(playlistName);
                break;
            case 3:
                cout << "Enter playlist name to delete: ";
                cin.ignore();
                getline(cin, playlistName);
                manager.deletePlaylist(playlistName);
                break;
            case 4:
                cout << "Enter song title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter duration (minutes): ";
                cin >> duration;
                manager.addSongToPlaylist(title, artist, genre, duration);
                break;
            case 5:
                cout << "Enter song title to remove: ";
                cin.ignore();
                getline(cin, title);
                manager.removeSongFromPlaylist(title);
                break;
            case 6:
                manager.displayPlaylistSongs();
                break;
            case 7:
                cout << "Enter artist name: ";
                cin.ignore();
                getline(cin, artist);
                manager.displaySongsByArtist(artist);
                break;
            case 8:
                cout << "Enter song title: ";
                cin.ignore();
                getline(cin, title);
                manager.displaySongsByTitle(title);
                break;
            case 9:
                cout << "Enter genre: ";
                cin.ignore();
                getline(cin, genre);
                manager.displaySongsByGenre(genre);
                break;
            case 10:
                manager.displayPlaylistDuration();
                break;
            case 11:
                manager.showPlaylists();
                break;
            case 12:
                manager.sortPlaylistByDuration();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        if (choice != 0) pressEnterToContinue();
        cout << "Enter your choice: ";
        cin >> choice;
    }

    return 0;
}

void pressEnterToContinue() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}