#include <stdio.h>

#include "game.h"

int main()
{
    t_game * g = game_init();
for (int tour = 0; tour < 5; tour = tour + 1) {
    if (g->player->score <5)
    {
      game_end(g);
      if (is_game_finished(g))
      {
      printf("Le jeu est terminé");
      }
      return 0;
    } else {
      printf("\nManche numéro : %d\n\n",tour);
      game_loop(g);
    }
    }
    printf("\nLe jeu est terminé");
    return 0;
}

void game_loop(t_game * g)
{
  print_player_coins(g->player); // Afficher le nombre de jetons du joueur
  broker_new_hand(g); // Le croupier pioche
  player_new_hand(g); // Le joueur pioce
  print_player_hand(g->player); // Afficher la main du joueur
  broker_place_bet(g); // Le croupier mise
  player_place_bet(g); // Le joueur mise
  int p_hand = sum_player_hand(g->player); /* Le joueur choisi la valeur de ses Valets
  et cette function "return" le score du joueur */
  print_turn_results(g, p_hand); /* Afficher le score du croupier et du joueur
  (le score du joueur doit être donné par la
  variable p_hand) */

  int card = player_ask_cards(g);
  if (g->broker > p_hand)
{
  player_lost(g);
  game_end(g);
} else if ((p_hand > g->broker && p_hand < 21) || (card == 6 && p_hand < 21))
{
  player_win(g);
  game_end(g);
} else if (p_hand == 21)
{
  player_jackpot(g);
  game_end(g);
} else if (p_hand > 21)
{
  player_breakthrough(g);
  game_end(g);
}
if (g->player->score <=0)
{
  game_end(g);
}
if (is_game_finished(g))
{
  printf("La manche est terminé\n");
}
}