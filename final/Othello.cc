#include <iostream>
#include <fstream>
#include <cstdlib>
#include "game.h"
#include "colors.h"
#include "Othello.h"
//TYLER ROGERS
//Othello Implamentation
using namespace std;

namespace main_savitch_14{
	//outputs certain square
	int othello::showsquare(int i,int k)const
	{
		return(boardstate[i][k].showstat());
	}
	//default constructor
	othello::othello() 
	{
		// 0 means blank space
		// 1 means white piece
		// 2 means black piece
		
		
		boardstate[4][4].set(1);
		boardstate[5][5].set(1);
		boardstate[4][5].set(2);
		boardstate[5][4].set(2);
		//boardstate[6][3].set(0);
		//boardstate[6][6].set(0);
		multiplayer = false;
	}
	//deconstructor
	//othello::~othello()
	//{
	//	
	//}
	//copy constructor
	othello::othello(const othello& orig)
	{
		for (int i=0;i>9;i++)
		{
			for(int k=0;k>9;k++)
			{
				boardstate[i][k].set(orig.showsquare(i,k));
			}
		}
	}
	//displays board
	void othello::display_status()const
	{
		string l;
		if(multiplayer==false)
		{
			if (next_mover() == COMPUTER)
			{
				l = "Computer";
			}
			else
			{
				l="Player";
			}
		}
		
		if (multiplayer == true)
		{
			if (moves_completed()%2 == 1)
			{
				l = "Player2";
			}
			else
			{
				l="Player1";
			}
		}
		
		cout << "Black = " << RED<<"$" << endl <<WHITE<< "White = " << BLUE<<"@"<<endl<<WHITE<<  "Empty spaces = " <<CYAN<<"#" << endl;
		cout <<WHITE<< "It is " << l << "'s turn.\n";
		cout <<WHITE<< "------------------------------------------\n";
		for (int k=0;k<=9;k++)
		{
			for(int i=0;i<=9;i++)
			{
				if(i == 0 || i == 9 || k== 0 || k == 9)
				{
					//border(i,k);
					cout <<WHITE;
					//I is x axis
					if (i == 0 || i == 9)
					{
						switch (k) {
							case 0:
								cout << "|   |";
								break;
							case 1:
								cout << "| A |";
								break;
							case 2:
								cout << "| B |";
								break;
							case 3:
								cout << "| C |";
								break;
							case 4:
								cout << "| D |";
								break;
							case 5:
								cout << "| E |";
								break;
							case 6:
								cout << "| F |";
								break;
							case 7:
								cout << "| G |";
								break;
							case 8:
								cout << "| H |";
								break;
							case 9:
								cout << "|   |";
								break;
						}
					}
					if (k == 0 || k == 9)
					{
						switch (i) {
							case 0:
								break;
							case 1:
								cout << " 1 |";
								break;
							case 2:
								cout << " 2 |";
								break;
							case 3:
								cout << " 3 |";
								break;
							case 4:
								cout << " 4 |";
								break;
							case 5:
								cout << " 5 |";
								break;
							case 6:
								cout << " 6 |";
								break;
							case 7:
								cout << " 7 |";
								break;
							case 8:
								cout << " 8 |";
								break;
							case 9:
								cout << "";
								break;
						}
					}
					
				}
				
				else if(boardstate[i][k].showstat() == 1)
				{
					cout << BLUE<<" @ |";
				}
				else if(boardstate[i][k].showstat() == 2)
				{
					cout <<RED<< " $ |";
				}
				else
				{
					cout <<CYAN<< " # |";
				}
				
			}
			cout << endl << WHITE<<"------------------------------------------" << endl;
		}
		cout << endl;
	}

	//has player make a move
	void othello::make_move(const string& move)
	{	
	
		if(move=="pass")
		{
			//skip
		}
		else
		{
			int l =0;
			
				if (moves_completed()%2 == 1)
				{
					l = 1;
				}
				else
				{
					l= 2;
				}
			
			
			string temp = move;
			char a,b;
			a = toupper(temp[0]);
			b = temp[1];
			int i,k;
			switch (a){
				case 'A':
					k = 1;
					break;
				case 'B':
					k = 2;
					break;
				case 'C':
					k = 3;
					break;
				case 'D':
					k = 4;
					break;
				case 'E':
					k = 5;
					break;
				case 'F':
					k = 6;
					break;
				case 'G':
					k = 7;
					break;
				case 'H':
					k = 8;
					break;
				default:
					cout<< "illegal coordinate\n\n";
					break;
			}
			switch (b){
				case '1':
					i = 1;
					break;
				case '2':
					i = 2;
					break;
				case '3':
					i = 3;
					break;
				case '4':
					i = 4;
					break;
				case '5':
					i = 5;
					break;
				case '6':
					i = 6;
					break;
				case '7':
					i = 7;
					break;
				case '8':
					i = 8;
					break;
				default:
					cout<< "illegal coordinate\n\n";
					break;
			}
			boardstate[i][k].set(l);

			flipallpossible(i,k);
		}
		game::make_move(move);
	}
		//restarts the game ********** need to fix
	void othello::restart()
	{
		// 0 means blank space
		// 1 means black piece
		// 2 means white piece
		
		for (int i=0;i>9;i++)
		{
			for(int k=0;k>9;k++)
			{
				if(i ==4 && k ==4)
				{
					boardstate[i][k].set(1);
				}
				else if(i == 5 && k == 4)
				{
					boardstate[i][k].set(2);
				}
				else if(i == 4 && k == 5)
				{
					boardstate[i][k].set(1);
				}
				else if(i == 5 && k == 5)
				{
					boardstate[i][k].set(2);
				}
				else
				{
					boardstate[i][k].set(0);
				}
				
			}
		}
	}
	// shows all possible moves into a queue
	void othello::compute_moves(queue<string>& moves) const
	{
		bool he;
		
		//cout << "DEBUGGING:\n";
		//this for loop check for vertical moves.
		for (int i=1;i<9;i++)
		{
			for (int k=1;k<9;k++)
			{
				if(boardstate[i][k].showstat() == 0)
				{
					he = available(i,k);
					if(he == true)
					{
						moves.push(coordstoword(i,k));
						//cout << moves.back() << endl;
					}
					
				}
			}
		}
		
		if(moves.empty() && last_mover() == COMPUTER)
		{
			moves.push("pass");
		}
	}
	// evaluates if palyer is winning by subtracting oppenent pieces from his/hers.
	int othello::evaluate() const
	{
		int hum = 0, robo = 0;
		
		for(int i=1;i<9;i++)
		{
			for(int k=1;k<9;k++)
			{
				if (boardstate[i][k].showstat() == 1)
					robo++;
				else if (boardstate[i][k].showstat() == 2)
					hum++;
			}
		}
		
		return (hum - robo);
	}
	// returns true if game is over
	bool othello::is_game_over()const
	{
		
		queue<string> moveh;
		
		compute_moves(moveh);
		int zero = 64;
		for(int i=1;i<9;i++)
		{
			for(int k=1;k<9;k++)
			{
				if (boardstate[i][k].showstat() == 0)
					zero--;
			}
		}
		if(zero == 0)
			return true;
		
		if(moveh.empty())
		{
			string tem = "pass";
			queue<string> moved;
			othello *temp = clone();
			temp->make_move(tem);
			temp->compute_moves(moved);
			if(moved.empty())
			{
				delete temp;
				return true;
			}
				
		}

		return false;
	}
	// returns true if move is legal.
	bool othello::is_legal(const string& move)const
	{
		
		queue<string> movess;
		compute_moves(movess);
		if(movess.back() == "pass")
		{
			return true;
		}
		
		
		string temp;
		temp = move;
		temp[0] = toupper(temp[0]);
		
		while(!movess.empty())
		{
			if (temp == movess.front())
				return true;
			else 
				movess.pop();
		}
		return false;
	}
	//returns clone of current game
	othello* othello::clone()const
	{
		othello* clonu;
		othello ha = *this;
		clonu = new othello(ha);	
		return clonu;
	}
	//converts int coordinates to char int 
	string othello::coordstoword(int i, int k)const
	{
		string temp;
		switch (k)
		{
			case 1:
				temp = "A";
				break;
			case 2:
				temp = "B";
				break;
			case 3:
				temp = "C";
				break;
			case 4:
				temp = "D";
				break;
			case 5:
				temp = "E";
				break;
			case 6:
				temp = "F";
				break;
			case 7:
				temp = "G";
				break;
			case 8:
				temp = "H";
				break;
		}
		switch (i)
		{
			case 1:
				return(temp + "1");
				break;
			case 2:
				return(temp + "2");
				break;
			case 3:
				return(temp + "3");
				break;
			case 4:
				return(temp + "4");
				break;
			case 5:
				return(temp + "5");
				break;
			case 6:
				return(temp + "6");
				break;
			case 7:
				return(temp + "7");
				break;
			case 8:
				return(temp + "8");
				break;
		}
		return ("ff");
	}
	//this checks if there is a possible move at the spot by checking in all directions for pieces to take ending with your own piece
	bool othello::available( int i, int k)const
	{
		if(nn(i,k))
			return true;
		if(ne(i,k))
			return true;
		if(nw(i,k))
			return true;
		if(ss(i,k))
			return true;
		if(se(i,k))
			return true;
		if(sw(i,k))
			return true;
		if(ee(i,k))
			return true;
		if(ww(i,k))
			return true;
		else
			return false;
	}
	
	bool othello::nn(int i, int k)const
	{
		if(k == 1)
			return false;
		if (boardstate[i][k-1].showstat() == 0)
			return false;
		int one = 2;
		if(multiplayer == false)
		{
			if (next_mover() == COMPUTER)
			{
				if (boardstate[i][k-1].showstat() == 1)
					return false;
				while(k-one > 0 && boardstate[i][k-one].showstat() != 0)
				{
					if (boardstate[i][k-one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i][k-1].showstat() == 2)
					return false;
				while(k-one > 0 && boardstate[i][k-one].showstat() != 0)
				{
					if (boardstate[i][k-one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		else if(multiplayer == true)
		{
			if (moves_completed()%2==1)
			{
				if (boardstate[i][k-1].showstat() == 1)
					return false;
				while(k-one > 0 && boardstate[i][k-one].showstat() != 0)
				{
					if (boardstate[i][k-one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i][k-1].showstat() == 2)
					return false;
				while(k-one > 0 && boardstate[i][k-one].showstat() != 0)
				{
					if (boardstate[i][k-one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		return false;
	}
	
	bool othello::ne(int i, int k)const
	{
		if(k == 1 || i == 8)
			return false;
		if (boardstate[i+1][k-1].showstat() == 0)
			return false;
		int one = 2;
		if(multiplayer == false)
		{
			if (next_mover() == COMPUTER)
			{
				if (boardstate[i+1][k-1].showstat() == 1)
					return false;
				while(k-one > 0 && i+one < 9 && boardstate[i+one][k-one].showstat() != 0)
				{
					if (boardstate[i+one][k-one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i+1][k-1].showstat() == 2)
					return false;
				while(k-one > 0 && i+one < 9 && boardstate[i+one][k-one].showstat() != 0)
				{
					if (boardstate[i+one][k-one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		else if(multiplayer == true)
		{
			if (moves_completed()%2==1)
			{
				if (boardstate[i+1][k-1].showstat() == 1)
					return false;
				while(k-one > 0 && i+one < 9 && boardstate[i+one][k-one].showstat() != 0)
				{
					if (boardstate[i+one][k-one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i+1][k-1].showstat() == 2)
					return false;
				while(k-one > 0 && i+one < 9 && boardstate[i+one][k-one].showstat() != 0)
				{
					if (boardstate[i+one][k-one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		return false;
	}
	
	bool othello::nw(int i, int k)const
	{
		if(k == 1 || i == 1)
			return false;
		if (boardstate[i-1][k-1].showstat() == 0)
			return false;
		int one = 2;
		if(multiplayer == false)
		{
			if (next_mover() == COMPUTER)
			{
				if (boardstate[i-1][k-1].showstat() == 1)
					return false;
				while(k-one > 0 && i-one < 9 && boardstate[i-one][k-one].showstat() != 0)
				{
					if (boardstate[i-one][k-one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i-1][k-1].showstat() == 2)
					return false;
				while(k-one > 0 && i-one < 9 && boardstate[i-one][k-one].showstat() != 0)
				{
					if (boardstate[i-one][k-one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		else if(multiplayer == true)
		{
			if (moves_completed()%2==1)
			{
				if (boardstate[i-1][k-1].showstat() == 1)
					return false;
				while(k-one > 0 && i-one < 9 && boardstate[i-one][k-one].showstat() != 0)
				{
					if (boardstate[i-one][k-one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i-1][k-1].showstat() == 2)
					return false;
				while(k-one > 0 && i-one < 9 && boardstate[i-one][k-one].showstat() != 0)
				{
					if (boardstate[i-one][k-one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		return false;
	}
	
	bool othello::ss(int i, int k)const
	{
		if(k == 8)
			return false;
		if (boardstate[i][k+1].showstat() == 0)
			return false;
		int one = 2;
		if (multiplayer == false)
		{
			if (next_mover() == COMPUTER)
			{
				if (boardstate[i][k+1].showstat() == 1)
					return false;
				while(k+one < 9 && boardstate[i][k+one].showstat() != 0)
				{
					if (boardstate[i][k+one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i][k+1].showstat() == 2)
					return false;
				while(k+one < 9 && boardstate[i][k+one].showstat() != 0)
				{
					if (boardstate[i][k+one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		else if (multiplayer == true)
		{
			if (moves_completed()%2==1)
			{
				if (boardstate[i][k+1].showstat() == 1)
					return false;
				while(k+one < 9 && boardstate[i][k+one].showstat() != 0)
				{
					if (boardstate[i][k+one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i][k+1].showstat() == 2)
					return false;
				while(k+one < 9 && boardstate[i][k+one].showstat() != 0)
				{
					if (boardstate[i][k+one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		return false;
	}
	
	bool othello::se(int i, int k)const
	{
		if(k == 8 || i == 8)
			return false;
		if (boardstate[i+1][k+1].showstat() == 0)
			return false;
		int one = 2;
		if(multiplayer == false)
		{
			//computer is white
			if (next_mover() == COMPUTER)
			{
				if (boardstate[i+1][k+1].showstat() == 1)
					return false;
				while(k+one > 0 && i+one < 9 && boardstate[i+one][k+one].showstat() != 0)
				{
					if (boardstate[i+one][k+one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			//player is black
			else 
			{
				if (boardstate[i+1][k+1].showstat() == 2)
					return false;
				while(k+one > 0 && i+one < 9 && boardstate[i+one][k+one].showstat() != 0)
				{
					if (boardstate[i+one][k+one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		if(multiplayer == true)
		{
			
			if (moves_completed()%2==1)
			{
				if (boardstate[i+1][k+1].showstat() == 1)
					return false;
				while(k+one > 0 && i+one < 9 && boardstate[i+one][k+one].showstat() != 0)
				{
					if (boardstate[i+one][k+one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			
			else 
			{
				if (boardstate[i+1][k+1].showstat() == 2)
					return false;
				while(k+one > 0 && i+one < 9 && boardstate[i+one][k+one].showstat() != 0)
				{
					if (boardstate[i+one][k+one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		return false;
	}
	
	bool othello::sw(int i, int k)const
	{
		if(k == 8 || i == 1)
			return false;
		if (boardstate[i-1][k+1].showstat() == 0)
			return false;
		int one = 2;
		if (multiplayer == false)
		{
			if (next_mover() == COMPUTER)
			{
				if (boardstate[i-1][k+1].showstat() == 1)
					return false;
				while(k+one > 0 && i-one < 9 && boardstate[i-one][k+one].showstat() != 0)
				{
					if (boardstate[i-one][k+one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i-1][k+1].showstat() == 2)
					return false;
				while(k+one > 0 && i-one < 9 && boardstate[i-one][k+one].showstat() != 0)
				{
					if (boardstate[i-one][k+one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		if (multiplayer == true)
		{
			if (moves_completed()%2==1)
			{
				if (boardstate[i-1][k+1].showstat() == 1)
					return false;
				while(k+one > 0 && i-one < 9 && boardstate[i-one][k+one].showstat() != 0)
				{
					if (boardstate[i-one][k+one].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i-1][k+1].showstat() == 2)
					return false;
				while(k+one > 0 && i-one < 9 && boardstate[i-one][k+one].showstat() != 0)
				{
					if (boardstate[i-one][k+one].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		return false;
	}
	
	bool othello::ee(int i, int k)const
	{
		if(i == 8)
			return false;
		if (boardstate[i+1][k].showstat() == 0)
			return false;
		int one = 2;
		if(multiplayer==false)
		{
			if (next_mover() == COMPUTER)
			{
				if (boardstate[i+1][k].showstat() == 1)
					return false;
				while(i+one < 9 && boardstate[i+one][k].showstat() != 0)
				{
					if (boardstate[i+one][k].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i+1][k].showstat() == 2)
					return false;
				while(i+one < 9 && boardstate[i+one][k].showstat() != 0)
				{
					if (boardstate[i+one][k].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		if(multiplayer==true)
		{
			if (moves_completed()%2==1)
			{
				if (boardstate[i+1][k].showstat() == 1)
					return false;
				while(i+one < 9 && boardstate[i+one][k].showstat() != 0)
				{
					if (boardstate[i+one][k].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i+1][k].showstat() == 2)
					return false;
				while(i+one < 9 && boardstate[i+one][k].showstat() != 0)
				{
					if (boardstate[i+one][k].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		return false;
	}
	
	bool othello::ww(int i, int k)const
	{
		if(i == 1)
			return false;
		if (boardstate[i-1][k].showstat() == 0)
			return false;
		int one = 2;
		if(multiplayer==false)
		{
			if (next_mover() == COMPUTER)
			{
				if (boardstate[i-1][k].showstat() == 1)
					return false;
				while(i-one < 9 && boardstate[i-one][k].showstat() != 0)
				{
					if (boardstate[i-one][k].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i-1][k].showstat() == 2)
					return false;
				while(i-one < 9 && boardstate[i-one][k].showstat() != 0)
				{
					if (boardstate[i-one][k].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		if(multiplayer==true)
		{
			if (moves_completed()%2==1)
			{
				if (boardstate[i-1][k].showstat() == 1)
					return false;
				while(i-one < 9 && boardstate[i-one][k].showstat() != 0)
				{
					if (boardstate[i-one][k].showstat() == 1)
						return true;
					
					one++;
				}
			}
			else 
			{
				if (boardstate[i-1][k].showstat() == 2)
					return false;
				while(i-one < 9 && boardstate[i-one][k].showstat() != 0)
				{
					if (boardstate[i-one][k].showstat() == 2)
						return true;
					
					one++;
				}
			}
		}
		return false;
	}
	//flips all the possible pieces from the piece that was just placed
	void othello::flipallpossible(int i, int k)
	{
		int l ;
			if (next_mover() == COMPUTER)
			{
				l = 1;
			}
			else
			{
				l=2;
			}
		
		
		if(nn(i,k))
		{
			int one=1;
			while(k-one > 0 && k-one < 9 && boardstate[i][k-one].showstat() != 0)
			{
				if (boardstate[i][k-one].showstat() == l)
					one = 100;
				else
					boardstate[i][k-one].flip();
				one++;
			}
		}
		if(ne(i,k))
		{
			int one = 1;
			while(k-one > 0 && k-one < 9 && i+one < 9 && i+one > 0 && boardstate[i+one][k-one].showstat() != 0)
			{
				if (boardstate[i+one][k-one].showstat() == l)
					one=100;
				else 
					boardstate[i+one][k-one].flip();
				one++;
			}
		}
		if(nw(i,k))
		{
			int one=1;
			while(k-one > 0 && k-one < 9 && i-one < 9 && i-one > 0 && boardstate[i-one][k-one].showstat() != 0)
			{
				if (boardstate[i-one][k-one].showstat() == l)
					one=100;
				else 
					boardstate[i-one][k-one].flip();
				one++;
			}
		}
		if(ss(i,k))
		{
			int one=1;
			while(k+one > 0 && k+one < 9 && boardstate[i][k+one].showstat() != 0)
			{
				if (boardstate[i][k+one].showstat() == l)
					one = 100;
				else
					boardstate[i][k+one].flip();
				one++;
			}
		}
		if(se(i,k))
		{
			int one=1;
			while(k+one > 0 && k+one < 9 && i+one < 9 && i+one > 0 && boardstate[i+one][k+one].showstat() != 0)
			{
				if (boardstate[i+one][k+one].showstat() == l)
					one = 100;
				else
					boardstate[i+one][k+one].flip();
				one++;
			}
		}
		if(sw(i,k))
		{
			int one=1;
			while(k+one > 0 && k+one < 9 && i-one < 9 && i-one > 0 && boardstate[i-one][k+one].showstat() != 0)
			{
				if (boardstate[i-one][k+one].showstat() == l)
					one = 100;
				else
					boardstate[i-one][k+one].flip();
				one++;
			}
		}
		if(ee(i,k))
		{
			int one=1;
			while(i+one < 9 && i+one > 0 && boardstate[i+one][k].showstat() != 0)
			{
				if (boardstate[i+one][k].showstat() == l)
					one = 100;
				else
					boardstate[i+one][k].flip();
				one++;
			}
		}
		if(ww(i,k))
		{
			int one=1;
			while(i-one < 9 && i-one > 0 && boardstate[i-one][k].showstat() != 0)
			{
				if (boardstate[i-one][k].showstat() == l)
					one = 100;
				else
					boardstate[i-one][k].flip();
				one++;
			}
		}
	}
	
	
}