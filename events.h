// Header file for Fingers game.

// Starts a 2 Player Game
void game_start(struct player player_one,
    struct player player_two,
    struct player* first_player,
    struct player* second_player);
    
// Runs the engine for 2 Player play
void pvp_game_engine(struct player* first_player, struct player* second_player);

// Runs the engine for Player vs Computer play
void bot_game_engine(struct player* first_player, struct player* second_player);

// Prints out n newlines
void spacer(int n);

// Determines if a player has won
bool check_for_win(const struct player* p1, const struct player* p2);

// Swaps p1 and p2
// void swap_players(struct player* p1, struct player* p2); (REMOVED 9:54 PM) 

// Prints out p1 and p2
void print_players(struct player* p1, struct player* p2);

// Returns a pointer to the player to go first (ADDED 10:25 PM), (MODIFIED to void return type 10:43 PM)
void random_first(struct player* p1, struct player* p2);

// Displays the current player
void print_current_player(struct player *current_player); 