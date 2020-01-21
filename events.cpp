#include "actions.h"
#include "bot.h"
#include "events.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void pvp_game_engine(struct player* first_player, struct player* second_player)
{
    while(1) {
        spacer(5);
        print_current_player(first_player);
        cout << "H - Hit" << endl;
        cout << "S - Split" << endl;
        cout << "T - Transfer" << endl;
        cout << "Q - Quit" << endl;
        spacer(5);
        print_players(first_player, second_player);
        char input{};
        spacer(5);
        cin >> input;
        if(input == 'H' || input == 'h') {
            cout << "Choose a hand to hit:" << endl;
            cout << "L - Left" << endl;
            cout << "R - Right" << endl;
            char input1{};
            cin >> input1;
            cout << "Choose which of your hands you'd like to hit with:" << endl;
            cout << "L - Left" << endl;
            cout << "R - Right" << endl;
            char input2{};
            cin >> input2;
            bool retval = hit(second_player, first_player, input1, input2);
            if(!retval) {
                continue; // Keep player's turn active if an error is encountered
            }
            if(check_for_win(first_player, second_player)) {
                break;
            }
            swap(first_player, second_player);
            continue;
        }
        if(input == 'S' || input == 's') {
            bool retval = split_revive(first_player);
            if(!retval) {
                continue; // Keep player's turn active if an error is encountered
            }
            swap(first_player, second_player);
            continue;
        }
        if(input == 'T' || input == 't') {
            cout << "Enter which hand you would like to transfer from" << endl;
            char src{};
            cin >> src;
            cout << "Enter how many you would like to transfer" << endl;
            int amt{};
            cin >> amt;
            bool retval = transfer(first_player, src, amt);
            if(!retval) {
                continue; // Keep player's turn active if an error is encountered
            }
            if(check_for_win(first_player, second_player)) {
                break;
            }
            swap(first_player, second_player);
            continue;
        }
        if(input == 'Q') {
            break;
        }
    }
}

void bot_game_engine(struct player* first_player, struct player* second_player)
{
    while(1) {
        spacer(5);
        if(first_player->order == 1) {
            print_current_player(first_player);
            cout << "H - Hit" << endl;
            cout << "S - Split" << endl;
            cout << "T - Transfer" << endl;
            cout << "Q - Quit" << endl;
            spacer(5);
            print_players(first_player, second_player);
            char input{};
            spacer(5);
            cin >> input;
            if(input == 'H' || input == 'h') {
                cout << "Choose a hand to hit:" << endl;
                cout << "L - Left" << endl;
                cout << "R - Right" << endl;
                char input1{};
                cin >> input1;
                cout << "Choose which of your hands you'd like to hit with:" << endl;
                cout << "L - Left" << endl;
                cout << "R - Right" << endl;
                char input2{};
                cin >> input2;
                bool retval = hit(second_player, first_player, input1, input2);
                /*if(!retval) {
                    continue; // Keep player's turn active if an error is encountered
                }*/
                if(check_for_win(first_player, second_player)) {
                    break;
                }
                cout << "1st: b " << first_player->order << endl;
                swap(first_player, second_player);
                cout << "1st: a" << first_player->order << endl;
                continue;
            }
            if(input == 'S' || input == 's') {
                bool retval = split_revive(first_player);
                if(!retval) {
                    continue; // Keep player's turn active if an error is encountered
                }
                swap(first_player, second_player);
                continue;
            }
            if(input == 'T' || input == 't') {
                cout << "Enter which hand you would like to transfer from" << endl;
                char src{};
                cin >> src;
                cout << "Enter how many you would like to transfer" << endl;
                int amt{};
                cin >> amt;
                bool retval = transfer(first_player, src, amt);
                if(!retval) {
                    continue; // Keep player's turn active if an error is encountered
                }
                if(check_for_win(first_player, second_player)) {
                    break;
                }
                swap(first_player, second_player);
                continue;
            }
            if(input == 'Q') {
                break;
            }
        }
        else {
            bot_ai(second_player, first_player);
            cout << "BOT HAS PLAYED!" << endl;
            if(check_for_win(first_player, second_player)) {
                break;
            }
            swap(first_player, second_player);
            continue;
        }
    }
}

void spacer(int n)
{
    for(int i = 0; i < n; ++i) {
        cout << endl;
    }
}

bool check_for_win(const struct player* p1, const struct player* p2)
{
    if(!p1->left && !p1->right) {
        cout << "Congrats Player 1!" << endl;
        cout << "You've won!" << endl;
        spacer(5);
        cout << "Thanks for playing!" << endl;
        return true;
    }
    else if(!p2->left && !p2->right) {
        cout << "Congrats Player 2!" << endl;
        cout << "You've won!" << endl;
        spacer(5);
        cout << "Thanks for playing!" << endl;
        return true;
    }
    else {
        return false;
    }
}

void print_players(struct player* p1, struct player* p2)
{
    cout << "========================================" << endl;
    cout << "CURRENT PLAYER:" << endl;
    if(p1->left) {
        cout << "LEFT: " << p1->left << endl;
    }
    if(p1->right) {
        cout << "RIGHT: " << p1->right << endl;
    }
    cout << "========================================" << endl;
    cout << "OPPONENT PLAYER:" << endl;
    if(p2->left) {
        cout << "LEFT: " << p2->left << endl;
    }
    if(p2->right) {
        cout << "RIGHT: " << p2->right << endl;
    }
    cout << "========================================" << endl;
}

void random_first(struct player* p1, struct player* p2)
{
    srand(time(0));
    int first_player{ (rand() % 2) + 1 };
    if(first_player == 1) {
        p1->order = 1;
        p2->order = 2;
    }
    else { // if (first_player == 2) {
        p1->order = 2;
        p2->order = 1;
    }
}

void print_current_player(struct player* current_player)
{
    cout << "Current Player: PLAYER " << current_player->order << endl;
}
