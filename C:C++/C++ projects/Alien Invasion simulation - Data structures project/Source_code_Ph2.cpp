#include "Game.h"
#include <conio.h>


using namespace std;

int main()
{

	Game* game_ptr = new Game;

	char user_mode_answer = 0;
	char continue_key = 0;

	cout << "Please enter the mode you want to run the simulation with. (i for interactive or s for silent)" << endl;

	while ( (user_mode_answer != 'i') && (user_mode_answer != 's'))
		cin >> user_mode_answer;

	if (user_mode_answer == 'i')
	{
		game_ptr->set_battle_mode(INTERACTIVE);
		cout << "Interactive mode is On" << endl;
	}
	else if (user_mode_answer == 's')
	{
		game_ptr->set_battle_mode(SILENT);
		cout << "Silent mode is On" << endl;
	}

	game_ptr->LoadFromFile("strong_Earth_strong_Aliens_In6.txt");

	while (game_ptr->get_Timestep() <= 40)
	{
		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "Current Timestep " << game_ptr->get_Timestep() << endl;

		game_ptr->get_generator()->create_unit(game_ptr);
		game_ptr->Armies_Attack(); 
		game_ptr->heal_damaged_Earth_units();
		game_ptr->Check_killed_UML();

		if (game_ptr->get_battle_mode() == INTERACTIVE)
			game_ptr->Print_Killed_list();

		game_ptr->set_Timestep(game_ptr->get_Timestep() + 1);

		if (game_ptr->get_battle_mode() == INTERACTIVE)
		{
			cout << " Press any key to move to next timestep" << endl;
			continue_key = _getch();
			cout << "================================================================" << endl;
		}
	}

	while (game_ptr->get_battle_result() == Draw)
	{
		int time_step = game_ptr->get_Timestep();

		if (time_step == 500)
			break;

		if (game_ptr->get_battle_mode() == INTERACTIVE)
			cout << "Current Timestep " << time_step << endl;

		game_ptr->get_generator()->create_unit(game_ptr);
		game_ptr->Armies_Attack();
		game_ptr->heal_damaged_Earth_units();
		game_ptr->Check_killed_UML();

		if (game_ptr->get_battle_mode() == INTERACTIVE)
			game_ptr->Print_Killed_list();

		game_ptr->set_Timestep(game_ptr->get_Timestep() + 1);

		game_ptr->check_winner();

		if (game_ptr->get_battle_mode() == INTERACTIVE)
		{
			cout << " Press any key to move to next timestep" << endl;
			continue_key = _getch();
			cout << "================================================================" << endl;
		}
	}

	cout << "Battle has ended " << endl;
	game_ptr->GenerateOutputFile("output6.txt");
	cout << "Output file generated" << endl; 

	return 0;
}