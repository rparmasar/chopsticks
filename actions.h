// Header file for Fingers game.

// Data Structure used to track players
struct player {
    int left;
    int right;
    int order; //Determines the order of play
    int split_num; //Tracks the number of splits remaining 
    int transfer_num; //Tracks the number of transfers remaining
};

// Increases the total on one of the opponent's hand by the amount on one of the hitter's hand
bool hit(struct player* target, struct player* hitter, char side, char src_side);

// Returns true if the player has only one active hand and then splits total across both hands and returns false if unable to split
bool split_revive(struct player* target);

// Transfers amt from src hand to the other hand
bool transfer(struct player* target, char src, int amt);