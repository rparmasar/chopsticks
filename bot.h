//Constants used in selecting left or right

// Decides how to play against the player
void bot_ai(struct player* player, struct player* bot);

// Attempts to kill any hands that can be killed based on bot's hand
void kill_player(struct player* player, struct player* bot);

// Returns true if bot has lost a hand
bool is_dying(struct player* bot);