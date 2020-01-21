#include "actions.h"
#include "bot.h"
#include "events.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

static char l{ 'l' };
static char r{ 'r' };

void bot_ai(struct player* p1, struct player* bot)
{
    while(1) {
        kill_player(p1, bot);
        srand(time(0));
        int decider_1{ (rand() + 100) % 2 };
        int decider_2{ (rand() + 100) % 2 };
        if(!bot->left)
        {
            if(p1->left) {
                hit(p1, bot, l, r);
                break;
            }
            if(p1->right) {
                hit(p1, bot, r, r);
                break;
            }
        }
        else if(!bot->right)
        {
            if(p1->left) {
                hit(p1, bot, l, l);
                break;
            }
            if(p1->right) {
                hit(p1, bot, r, l);
                break;
            }
        }
        else if(decider_1)
        {
            if(decider_2) {
                hit(p1, bot, r, l);
                break;
            }
            else {
                hit(p1, bot, l, l);
                break;
            }
        }
        else if(!decider_1)
        {
            if(decider_2) {
                hit(p1, bot, r, r);
                break;
            }
            else {
                hit(p1, bot, l, r);
                break;
            }
        }
    }
}

void kill_player(struct player* player, struct player* bot)
{
    int pleft{ player->left };
    int pright{ player->right };
    if(pleft + bot->left >= 5) {
        hit(player, bot, l, l);
    }
    else if(pleft + bot->right >= 5) {
        hit(player, bot, r, l);
    }
    else if(pright + bot->left >= 5) {
        hit(player, bot, l, r);
    }
    else if(pright + bot->right >= 5) {
        hit(player, bot, r, r);
    }
}

bool is_dying(struct player* bot)
{
    if(!bot->right || !bot->left) {
        return true;
    }
    else {
        return false;
    }
}
