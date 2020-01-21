#include "actions.h"
#include "events.h"
#include <iostream>

using namespace std;

bool hit(struct player* target, struct player* hitter, char side, char src_side) 
{
    if((side == 'l' || side == 'L') && target->left) {
        {
            if(src_side == 'l' || src_side == 'L') {
                target->left += hitter->left;
            }
            if(src_side == 'r' || src_side == 'R'){ // right hand selected from hitter
                target->left += hitter->right;
            }
        }
        if(target->left >= 5) {
            target->left = 0;
            return true;
        }
    }
    else if ((side == 'r' || side == 'R') && target->right) { // right hand selected
        {
            if(src_side == 'r' || src_side == 'R') {
                target->right += hitter->right;
            }
            if(src_side == 'l' || src_side == 'L') { // src_side = left
                target->right += hitter->left;
            }
        }
        if(target->right >= 5) {
            target->right = 0;
            return true;
        }
    }
    else {
        cout << "Unable to hit" << endl;
        return false;
    }
}

bool split_revive(struct player* target)
{
    if(target->split_num && !target->right && target->left) { //edited 12:17 AM
        int temp = target->left / 2;
        target->right = temp;
        target->left -= temp;
        --(target->split_num);
        return true;
    }
    else if(target->split_num && !target->left && target->right) { //edited 12:22 AM
        int temp = target->right / 2;
        target->left = temp;
        target->left -= temp;
        --(target->split_num);
        return true;
    }
    else {
        cout << "Error: Cannot Split!" << endl;
        return false;
    }
}

bool transfer(struct player* target, char src, int amt)
{
    if(target->transfer_num && (src == 'L' || src == 'l') && (target->right + amt) < 5) {
        if(target->right == 0) {
            cout << "Error: Cannot transfer to dead hand!" << endl;
            return false;
        }
        target->left -= amt;
        target->right += amt;
        --(target->transfer_num);
        return true;
    }
    else if(target->transfer_num && (src == 'R' || src == 'r') && (target->left + amt) < 5) {
        if(target->left == 0) {
            cout << "Error: Cannot transfer to dead hand!" << endl;
            return false;
        }
        target->right -= amt;
        target->left += amt;
        --(target->transfer_num);
        return true;
    }
    else {
        cout << "Error: Unable to Transfer!" << endl;
        return false;
    }
}
