#include "actions.h"
#include "bot.h"
#include "events.h"
#include <iostream>

using namespace std;

int main()
{
    while(1) {
        cout << "FINGERS:" << endl;
        cout << "Press P for 2 Player" << endl;
        cout << "Press C for Computer Battle" << endl;
        char input{};
        cin >> input;
        if(input == 'P' || input == 'p') {
            cout << "Random First Player?" << endl;
            cout << "Y - Yes" << endl;
            cout << "N - No" << endl;
            cout << "If no, player one goes first by default" << endl;
            char random_input{};
            cin >> random_input;
            struct player player_one {
                1, 1, 1, 3, 3
            };
            struct player player_two {
                1, 1, 2, 3, 3
            };
            struct player* first_player{ &player_one };
            struct player* second_player{ &player_two };
            if(random_input == 'y' || random_input == 'Y') {
                random_first(first_player, second_player);
            }
            pvp_game_engine(first_player, second_player);
        }
        if(input == 'C' || input == 'c') {
            cout << "Go First?" << endl;
            cout << "Y - Yes" << endl;
            cout << "N - No" << endl;
            // cout << "If no, player goes first by default" << endl;
            char random_input{};
            cin >> random_input;
            struct player player_one {
                1, 1, 1, 3, 3
            };
            struct player bot {
                1, 1, 'b', 3, 3
            };
            struct player* first_player{ &player_one };
            struct player* second_player{ &bot };
            if(random_input == 'y' || random_input == 'Y') {
                bot_game_engine(first_player, second_player);
            }
            else {
                swap(first_player, second_player);
                bot_game_engine(first_player, second_player);
            }
        }
        if(input == 'Q' || input == 'q') {
            break;
        }
    }
}
