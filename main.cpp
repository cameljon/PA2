#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(NULL));
	int playerHP[4] = {100, 100, 100, 100};
	int round = 1;
	bool notSuicide;
	bool done = false;
    int attackWho;

	while (!done)
	{
	    //Menu for each round
	    cout << endl << "Round " << round << ": FIGHT!" << endl << endl;
	    for (int i = 0; i < 4; i++)
        {
            //Extra: HP bar
            string hpBar;
            for (int h = 0; h < playerHP[i]; h += 2)
            {
                hpBar += "#";
            }
            string npcOrYou;
            if (i == 0)
            {
                npcOrYou = "(You!)";
            }
            else
            {
                npcOrYou = "(NPC) ";
            }
            cout << "Player " << i << " " << npcOrYou << " HP: " << playerHP[i] << "\t" << hpBar << endl;
        }

        notSuicide = false;
        while (!notSuicide)
        {
            cout << endl << "Who do you want to attack? ";
            cin >> attackWho;
            if (attackWho != 0)
            {
                playerHP[attackWho] -= 5;
                cout << endl << "You attack player " << attackWho << " for 5 damage." << endl;
                notSuicide = true;
            }
            else
            {
                cout << "You can't attack yourself. Pick again!" << endl;
            }
        }

        //NPC's turn
        for (int i = 1; i < 4; i++)
        {
            //Extra: Don't attack self? Theoretical infinite loop?
            notSuicide = false;
            while (!notSuicide)
            {
                attackWho = rand() % 4;
                if (i != attackWho)
                {
                    notSuicide = true;
                }
            }
			if (playerHP[i] > 0 && playerHP[attackWho] > 0)
			{
				playerHP[attackWho] -= 5;
				cout << "Player " << i << " attacks player " << attackWho << " for 5 damage!" << endl;
			}
        }

        //Check if user is dead or all npcs are dead.
		if (playerHP[1] <= 0 && playerHP[2] <= 0 && playerHP[3] <= 0)
		{
			cout << "ALL NPCs are dead!" << endl;
			done = true;
		}
		else if (playerHP[0] <= 0)
		{
			cout << "You died!" << endl;
			done = true;
		}

        round++;
        cout << endl << "---------------------------------------------------------------------" << endl;
	}

	return 0;
}
