#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "game.h"
using namespace std;
//TYLER ROGERS
//Othello declaration
namespace main_savitch_14{
	
	
	class space
	{
		private:
		//status 
		//0 is blank
		//1 is black
		//2 is white
		int status;
		public:
		
		space()
		{
			status = 0;
		};
		void flip()
		{
			if (status == 1)
				status = 2;
			else
				status = 1;
		};
		void set(int i)
		{
			status = i;
		};
		
		int showstat()const
		{
			return status;
		};
	};
	
	
	
	
	class othello:public game
	{
		private:
		//da board
		space boardstate[9][9];
		bool multiplayer;
		public:
		//returns the status of current board space
		int showsquare( int i, int k)const;
		//default constructor
		othello(); 
		//deconstructor
		//~othello();
		//copy constructor
		othello(const othello& orig);
		//displays board
		void display_status()const;
		//has player make a move
		void make_move(const string& move);
		//restarts the game
		void restart();
		// shows all possible moves into a queue
		void compute_moves(queue<string>& moves)const;
		// evaluates if palyer is winning by subtracting oppenent pieces from his/hers.
		int evaluate() const;
		// returns true if game is over
		bool is_game_over()const;
		// returns true if move is legal.
		bool is_legal(const string& move)const;
		//returns clone of current game
		othello* clone()const;
		//this checks if there is a possible move at the spot by checking in all directions for pieces to take ending with your own piece
		bool available( int i, int k)const ;
		//converts int int to char int
		string coordstoword(int i, int k)const;
		//the rest are checking corresponding direction
		bool nn(int i, int k)const;
		
		bool ne(int i, int k)const;
		
		bool nw(int i, int k)const;
		
		bool ss(int i, int k)const;
		
		bool se(int i, int k)const;
		
		bool sw(int i, int k)const;
		
		bool ee(int i, int k)const;
		
		bool ww(int i, int k)const;
		//flips all possible pieces
		void flipallpossible(int i,int k);
		//sets the game mode between pvp or pvc NOT NEEDED FOR PART 3
		void setgamemode()
		{
			char p;
			bool t=true;
			while (t)
			{
				cout << "Please indicate if you want to face a computer or another player locally.\n C for computer || P for Player\n\n";
				cin >> p;
				if (p != 'c' && p != 'C' && p != 'p' && p != 'P')
				{
					cout << "Please enter a valid answer.\n\n";
				}
				else
					t=false;
			}
			if (p != 'c' || p != 'C')
			{
				multiplayer = false;
			}
			if(p != 'p' || p != 'P')
			{
				multiplayer = true;
			}
			cin.sync();
		};	
		//overide to set nextmover
		virtual who next_mover( ) const
	    {
			if(moves_completed()%2 == 0)
				return(HUMAN);
			else
				return(COMPUTER);
			return (NEUTRAL); 
		};
		//overide to set lastmover
		virtual who last_mover( ) const 
	    {

			if(moves_completed()%2 == 1)
				return(HUMAN);
			else
				return(COMPUTER);
			return (NEUTRAL); 
		};
	};
	
	
	
}