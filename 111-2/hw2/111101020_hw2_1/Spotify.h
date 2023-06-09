#ifndef SPOTIFY_H
#define SPOTIFY_H
#include <fstream>
#include <iostream>
#include <vector>

#include "Song.h"
#include "User.h"
using namespace std;
// Add any Boolean Function for sorting you need

class Spotify {
   private:
    User *curr_user;             // points to the current user, NULL at first
    vector<User *> users;        // store all users information
    vector<const Song *> songs;  // store the songs provided in streaming service

    void addSong();        // add new song into songs
    void createUser();     // create new user
    void logIN();          // log in to specific user
    void logOUT();         // log out from current user
    void printSongList();  // list all songs in device  (sort by song length)
    void printUserList();  // list all users in device
    void scene1() {
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::::::::::::::'######::'########:::'#######::'########:'####:'########:'##:::'##:::::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::::::::'##... ##: ##.... ##:'##.... ##:... ##..::. ##:: ##.....::. ##:'##::::::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::::::::::::: ##:::..:: ##:::: ##: ##:::: ##:::: ##::::: ##:: ##::::::::. ####:::::::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::::::::. ######:: ########:: ##:::: ##:::: ##::::: ##:: ######:::::. ##::::::::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::::::::::::::..... ##: ##.....::: ##:::: ##:::: ##::::: ##:: ##...::::::: ##::::::::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::::::::'##::: ##: ##:::::::: ##:::: ##:::: ##::::: ##:: ##:::::::::: ##::::::::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::::::::. ######:: ##::::::::. #######::::: ##::::'####: ##:::::::::: ##::::::::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::::::::::::::......:::..::::::::::.......::::::..:::::....::..:::::::::::..:::::::::::::::::::::::::::::::" << endl;
        cout << "               __   __                                         __       __         ___                              " << endl;
        cout << "   | .   |    /  \\ / _`    | |\\ |                             /  \\ .   /  \\ |  | |  |                               " << endl;
        cout << "   | .   |___ \\__/ \\__>    | | \\|                             \\__X .   \\__X \\__/ |  |                               " << endl;
        cout << "                                                                                                                           " << endl;
        cout << "               __   __      __   __        __                  __       __   __   ___      ___  ___          __   ___  __  " << endl;
        cout << " /\\  .    /\\  |  \\ |  \\    /__` /  \\ |\\ | / _`                /  ` .   /  ` |__) |__   /\\   |  |__     |  | /__` |__  |__) " << endl;
        cout << "/~~\\ .   /~~\\ |__/ |__/    .__/ \\__/ | \\| \\__>                \\__, .   \\__, |  \\ |___ /~~\\  |  |___    \\__/ .__/ |___ |  \\ " << endl;
        cout << "                                                                                                                           " << endl;
        cout << " __              __  ___     __   __        __   __                            __  ___          __   ___  __   __          " << endl;
        cout << "/__` .   |    | /__`  |     /__` /  \\ |\\ | / _` /__`          |  | .   |    | /__`  |     |  | /__` |__  |__) /__`         " << endl;
        cout << ".__/ .   |___ | .__/  |     .__/ \\__/ | \\| \\__> .__/          \\__/ .   |___ | .__/  |     \\__/ .__/ |___ |  \\ .__/         " << endl
             << endl;
    }
    void scene2() {
        cout << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::'##::::'##::'######::'########:'########:::::'########:::::'###:::::'######:::'########:::::::::::::::::" << endl;
        cout << ":::::::::::::::::: ##:::: ##:'##... ##: ##.....:: ##.... ##:::: ##.... ##:::'## ##:::'##... ##:: ##.....::::::::::::::::::" << endl;
        cout << ":::::::::::::::::: ##:::: ##: ##:::..:: ##::::::: ##:::: ##:::: ##:::: ##::'##:. ##:: ##:::..::: ##:::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::: ##:::: ##:. ######:: ######::: ########::::: ########::'##:::. ##: ##::'####: ######:::::::::::::::::::" << endl;
        cout << ":::::::::::::::::: ##:::: ##::..... ##: ##...:::: ##.. ##:::::: ##.....::: #########: ##::: ##:: ##...::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::: ##:::: ##:'##::: ##: ##::::::: ##::. ##::::: ##:::::::: ##.... ##: ##::: ##:: ##:::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::. #######::. ######:: ########: ##:::. ##:::: ##:::::::: ##:::: ##:. ######::: ########:::::::::::::::::" << endl;
        cout << ":::::::::::::::::::.......::::......:::........::..:::::..:::::..:::::::::..:::::..:::......::::........::::::::::::::::::" << endl;
        cout << " __            __   __         __       ___                                                                               " << endl;
        cout << "/  \\ .   |    /  \\ / _`       /  \\ |  |  |                                                                                " << endl;
        cout << "\\__/ .   |___ \\__/ \\__>       \\__/ \\__/  |                                                                                " << endl;
        cout << "                                                                                                                          " << endl;
        cout << "               __   __             __  ___                                                                                " << endl;
        cout << " /\\  .    /\\  |  \\ |  \\    |    | /__`  |                                                                                 " << endl;
        cout << "/~~\\ .   /~~\\ |__/ |__/    |___ | .__/  |                                                                                 " << endl;
        cout << "                                                                                                                          " << endl;
        cout << " __       __        __   __   __   ___            __  ___                                                                 " << endl;
        cout << "/  ` .   /  ` |__| /  \\ /  \\ /__` |__     |    | /__`  |                                                                  " << endl;
        cout << "\\__, .   \\__, |  | \\__/ \\__/ .__/ |___    |___ | .__/  |                                                                  " << endl
             << endl;
    }
    void scene3() {
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::::::::'########::'##::::::::::'###::::'##:::'##:'##:::::::'####::'######::'########::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::: ##.... ##: ##:::::::::'## ##:::. ##:'##:: ##:::::::. ##::'##... ##:... ##..:::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::: ##:::: ##: ##::::::::'##:. ##:::. ####::: ##:::::::: ##:: ##:::..::::: ##:::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::: ########:: ##:::::::'##:::. ##:::. ##:::: ##:::::::: ##::. ######::::: ##:::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::: ##.....::: ##::::::: #########:::: ##:::: ##:::::::: ##:::..... ##:::: ##:::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::: ##:::::::: ##::::::: ##.... ##:::: ##:::: ##:::::::: ##::'##::: ##:::: ##:::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::::::: ##:::::::: ########: ##:::: ##:::: ##:::: ########:'####:. ######::::: ##:::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::::::::..:::::::::........::..:::::..:::::..:::::........::....:::......::::::..::::::::::::::::::::::::::" << endl;
        cout << " __       __                                                   " << endl;
        cout << "|__) .   |__) |     /\\  \\ /                                    " << endl;
        cout << "|    .   |    |___ /~~\\  |                                     " << endl;
        cout << "                                                               " << endl;
        cout << "               __   __      __   __        __                  " << endl;
        cout << " /\\  .    /\\  |  \\ |  \\    /__` /  \\ |\\ | / _`                 " << endl;
        cout << "/~~\\ .   /~~\\ |__/ |__/    .__/ \\__/ | \\| \\__>                 " << endl;
        cout << "                                                               " << endl;
        cout << " __       __   ___        __        ___     __   __        __  " << endl;
        cout << "|__) .   |__) |__   |\\/| /  \\ \\  / |__     /__` /  \\ |\\ | / _` " << endl;
        cout << "|  \\ .   |  \\ |___  |  | \\__/  \\/  |___    .__/ \\__/ | \\| \\__> " << endl;
        cout << "                                                               " << endl;
        cout << " __       __   __      __        __                            " << endl;
        cout << "|__) .   / _` /  \\    |__)  /\\  /  ` |__/                      " << endl;
        cout << "|__) .   \\__> \\__/    |__) /~~\\ \\__, |  \\                      " << endl
             << endl;
    }
    void scene4() {
        cout << ":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::'##::::'##:'##::::'##::'######::'####::'######::::'########:'####:'##::::'##:'########::::::::::::::::::" << endl;
        cout << "::::::::::::::::::: ###::'###: ##:::: ##:'##... ##:. ##::'##... ##:::... ##..::. ##:: ###::'###: ##.....:::::::::::::::::::" << endl;
        cout << "::::::::::::::::::: ####'####: ##:::: ##: ##:::..::: ##:: ##:::..::::::: ##::::: ##:: ####'####: ##::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::: ## ### ##: ##:::: ##:. ######::: ##:: ##:::::::::::: ##::::: ##:: ## ### ##: ######::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::: ##. #: ##: ##:::: ##::..... ##:: ##:: ##:::::::::::: ##::::: ##:: ##. #: ##: ##...:::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::: ##:.:: ##: ##:::: ##:'##::: ##:: ##:: ##::: ##:::::: ##::::: ##:: ##:.:: ##: ##::::::::::::::::::::::::" << endl;
        cout << "::::::::::::::::::: ##:::: ##:. #######::. ######::'####:. ######::::::: ##::::'####: ##:::: ##: ########::::::::::::::::::" << endl;
        cout << ":::::::::::::::::::..:::::..:::.......::::......:::....:::......::::::::..:::::....::..:::::..::........:::::::::::::::::::" << endl;
        cout << "               ___     ___     __   __        __" << endl;
        cout << "|\\ | .   |\\ | |__  \\_/  |     /__` /  \\ |\\ | / _`   " << endl;
        cout << "| \\| .   | \\| |___ / \\  |     .__/ \\__/ | \\| \\__>   " << endl;
        cout << "                                                    " << endl;
        cout << " __       __   __   ___          __   __        __  " << endl;
        cout << "|__) .   |__) |__) |__  \\  /    /__` /  \\ |\\ | / _` " << endl;
        cout << "|    .   |    |  \\ |___  \\/     .__/ \\__/ | \\| \\__> " << endl;
        cout << "                                                    " << endl;
        cout << " __       __   __      __        __                 " << endl;
        cout << "|__) .   / _` /  \\    |__)  /\\  /  ` |__/           " << endl;
        cout << "|__) .   \\__> \\__/    |__) /~~\\ \\__, |  \\           " << endl
             << endl;
    }

   public:
    Spotify(string file);
    ~Spotify();
    void controlManual();  // controller of the whole device
    // Add any Accessor & Mutator functions, or friend class declaration you need
};
#endif
