// Game.cpp : Defines the entry point for the console application.
//

#include "Stdafx.h"
#include "player.h"
#include "Monsters.h"
#include <iostream>
#include <time.h>


using namespace std;

 // here is where all the variables are delcaired 
int Respawns;
int Total_Turns;
int spawnCount=0;




const int MAX_MONSTERS=60; // this gives me the constant value of 60 monsters max

void killMonsters(Monsters *m[],Player p){   // kill monsters function.
	int x;
	int y;

		x=p.getX();   //get the playes x and y co-ordinates
		y=p.getY();

	for(int i=0;i<MAX_MONSTERS;i++) {
	if(m[i]!=NULL) {
	if(x==m[i]->getX() && y==m[i]->getY()){ // this checks the co-ordinates of the player -
		cout << "Monster Owned" << endl;    //and the monster and if it is detected on the same the monster is deleted.
	delete m[i];
		m[i]=NULL;
	break;
		}
		}
		}
		}


int main() {

	system("color 0F"); // Changing of the main games color.



	
	srand (time(NULL));

	Player p; // player re named p.
	Monsters* m[MAX_MONSTERS];
	
	int DifficultySelect;
	cout << "choose Difficulty\n";
	cout <<"1 = Easy\n Respawns = 60 \n" "Total Turns = 600\n";   // display screen for the difficutly menu.
	
	cout <<"2 = Medium\n Respawns = 40 \n" " Total Turns = 400\n";
	cout <<"3 = Hard\n Respawns = 10 \n" " Total Turns = 300\n";

		cin >> DifficultySelect;
		switch (DifficultySelect)
		{
		case 1:
			Respawns = 60;
			 Total_Turns = 600;
			 system("color B0");
			 system("cls");  // Clear screen after player has selected his/her difficulty.
			 break;

		case 2:
			Respawns = 40;
			Total_Turns = 400;
			system("color 0A"); 
			system("cls");  // Clear screen after player has selected his/her difficulty.
			break;

		case 3:
			Respawns = 10;
			Total_Turns = 300;
			system("color CF");
			system("cls");  // Clear screen after player has selected his/her difficulty.
			break;

		}



			


for(int i=0;i<MAX_MONSTERS;i++) { // array for 10 monsters.
		if(i<10) {
			m[i]=new Monsters();
		}
		else {
			m[i]=NULL;
		}
	}

//game loop
	for(int j = 0; j < Total_Turns; j++)
	{
	
	for(int i=0;i<10;i++) {
		if(m[i]!=NULL) {
			m[i]->movement();
			cout << "MONSTER  : "<< i << " : LOCATION    " ; // moving and printing the monster location.
			m[i]->printLocation();
			

		}
}
	

		p.printLocation();
		p.movement();
		p.printLocation();
		system("cls");
		killMonsters(m,p);  // printing and proving the player location and the kill comster fuction call.



		for(int i=0;i<10;i++){
			if(m[i]!=NULL) {
			m[i]->movement();
			
			}
		}
		                             // the spawn count and respawn if statment and for loop to bring in new monster to an available space 
	spawnCount++;
	if(spawnCount>=Respawns) {
		spawnCount=0;
			for(int i=0;i<MAX_MONSTERS;i++) {
			if(m[i]==NULL) {
				m[i]=new Monsters();
				break;
			}
		}
	}

	}  // end game loop

	return 0;
		}
