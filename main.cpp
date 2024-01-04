#include<iostream>
#include<string>
#include<Windows.h>		//This library is used for Sleep() function
#include<ctime>			//This library is used for generating different numbers at same time for rand() function
#include"struct.cpp" //struct.cpp stores all strutures of the program

#pragma comment(lib, "winmm.lib") //This library is for playing music



using namespace std;



//struct defined in struct.cpp
//struct datatypes
characterInfo character;	//This struct includes profile data, such as name, class, exp
inventorySys invent;		//This struct includes, inventory items/weapons
levels level;				//This struct includes,no of total user passed levels
lvl1Enemy dragon;			//This function includes health of enemies characters of Level1
lvl2Enemy phoneix;			//This function includes health of enemies characters of Level2
lvl3Enemy lvl3E;			//This function includes health of enemies characters of Level2





//Declaring Prototypes of all functions
void exitGame();		//This function exit the game
void character1();		//this function is for creating characters
void inventry();		//this is for inventory system
void charInfo(int& hlth, int& exp, int& enehlth);		//This prints user data of name, health, class, and enemy health
int  classChar(string cls);			//this function get character class an parameter and return user attack points
void selevel();						//This fuction is for displaying select level screen, where from user redirect to that level respectively


//these functions are for level 1
void lvl1();		//this prints story telling and selecting the path of level 1, On the different paths there are different enemies
void lvl1GDragon();	//this include battle with Giant Dragon
void lvl1ADragon();	//this include battle with Adult Dragon
void lvl1BDragon();	//this include battle with Baby Dragon

//these functions are for level 2
void lvl2();		//this prints story telling and selecting the path of level 2, On the different paths there are different enemies
void lvl2Bennu();	//this include battle with Bennu Phoneix
void lvl2feng();	//this include battle with Fenghuang Phoneix
void lvl2fire();	//this include battle with Fire Bird Phoneix
void lvl2huma();	//this include battle with Huma Phoneix


//these functions are for level 3
void lvl3();		//this prints story telling and selecting the path of level 3, On the different paths there are different enemies
void lvl3naga();	//this include battle with Naga
void lvl3tBird();	//this include battle with Thunder Bird
void lvl3tengue();	//this include battle with Tengue
void lvl3valkyrie();	//this include battle with Valkyrie

bool checkClear = false;	//this global variable is for only main function, we are declaring it here because
//in our game we call main function in different different situations and we don't want to 
//print welcome game message
void main() {

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);	//This function play music where back.wav is file which contain music

	if (checkClear == false) {

		string welcome = "\tWelcome to MythicVenture: A Hero's Quest\n";
		for (int i = 0; i < welcome.length(); i++) { //This loop prints welcome string in type writer effect
			cout << welcome[i];
			Sleep(70);
		}
	}


	string mainMenuSelection;

	//We used do while loop here because if any user entered wrong selection then it gets input again from the user
	do {
		if (checkClear)
			system("cls"); //this clear all logs on command prompt, we have used this condition 
		else
			checkClear = true;

		//this prints main menu
		cout << "\n\t\tMain Menu\n\t1. Start Game\n\t2. Inventory\n\t3. Characters\n\t4. Exit\n\tEnter your Choice: ";

		cin >> mainMenuSelection; //here this gets input from user

		if (mainMenuSelection == "1") {
			selevel();
			break;
		}
		else if (mainMenuSelection == "2") {

			inventry();
			break;
		}
		else if (mainMenuSelection == "3") {
			character1();
			break;
		}
		else if (mainMenuSelection == "4") {
			exitGame();
			break;
		}

	} while (mainMenuSelection != "1" || mainMenuSelection != "2" || mainMenuSelection != "3" || mainMenuSelection != "4");

}

//Exit Game function
void exitGame() {
	cout << "\n\n\n\tGame Ended!";
}



//This function is for making characters, view characters
void character1() {
	system("cls");
	string select;
	cout << "\n\t1. Create a Character\n\t2. View Character\n\t3. Exit Game\n\t4. Main Menu\n\tYour Choice: ";
	cin >> select;	//we have stored this value in string because by in any chance if user enters any string so by using string it won't give any error

	bool classCheck = true;
	string classCheckNum;




	if (select == "1")
	{

		cout << "\n\tEnter Character Name: ";
		cin >> character.characterName;


		while (classCheck)
		{
			cout << "\n\tEnter Character Class \n\t1.Warrior\t(Damage 1-15) \n\t2.Mage \t\t(Damage 16-20) \n\t3.Rogue\t\t(Damage 20-30)\n\tSelect Class: ";
			cin >> classCheckNum;

			if (classCheckNum == "1") {
				character.characterRank = "Warrior";

				break;
			}
			else if (classCheckNum == "2") {
				character.characterRank = "Mage";

				break;

			}
			else if (classCheckNum == "3") {
				character.characterRank = "Rogue";

				break;
			}
			else {
				cout << "\n\tYou have Entered Incorrect Class";
				classCheck = true;
			}
		}

		cout << "\n\tCharacter Name  :\t" << character.characterName;
		cout << "\n\tCharacter Class :\t" << character.characterRank << endl;

		cout << "\n\n\tCharacter Created\n\n";
		system("pause");
		character1();

	}
	else if (select == "2") {
		cout << "\n\tCharacter Name  :\t" << character.characterName;
		cout << "\n\tCharacter Class :\t" << character.characterRank << "\n\t";
		system("pause");
		character1();
	}
	else if (select == "3") {
		exitGame();
	}
	else if (select == "4") {
		main();
	}

	else {
		cout << "You have Entered Incorrect Choice" << endl;
		character1();
	}

}

//Display Character Information
void charInfo(int& hlth, int& exp, int& eneHlth) {
	character.characterHealth -= hlth;

	if (character.characterHealth <= 0) character.characterHealth = 0;
	if (eneHlth <= 0) eneHlth = 0;

	string details = "\n\n\tPlayer Name:\t" + character.characterName + "\n\tPlayer Class:\t" + character.characterRank + "\n\tHealth:\t\t" + to_string(character.characterHealth) + "\n\tExp Points:\t" + to_string(character.characterExp) + "\n\n\tEnemy Health: " + to_string(eneHlth);
	for (int i = 0; i < details.length(); i++) {
		cout << details[i];
		Sleep(30);
	}
}

//This function takes character class and return player attack points
int classChar(string cls) {

	int max=0, min=0;
	if (invent.weapons[0] != "" || invent.weapons[1] != "" || invent.weapons[2] != "" || invent.weapons[3] != "" || invent.weapons[4] != "") {
		if (invent.weapons[4] != "") {
			min = 99;
			max = 100;
		}
		else if (invent.weapons[3] != "") {
			min = 60;
			max = 70;
		}
		else if (invent.weapons[2] != "") {
			min = 20;
			max = 30;
		}
		else if (invent.weapons[1] != "") {
			min = 15;
			max = 25;
		}
		else if (invent.weapons[0] != "") {
			min = 10;
			max = 20;
		}
	}

	srand(time(0));


	if (cls == "Warrior") {
		//Attack max 15
		max += 15;
		min += 1;
		return rand() % (max - min + 1) + min;
	}
	else if (cls == "Mage") {
		//Attack max 20
		max += 20;
		min += 15;
		return rand() % (max - min + 1) + min;
	}
	else if (cls == "Rogue") {
		//Attack max 30
		max += 30;
		min += 20;
		return rand() % (max - min + 1) + min;
	}
}


//Inventry
void inventry() {
	system("cls");
	int select;
	cout << "\n\tYou have Exp: " << character.exp << " Points\n";

	//This loop print unlocked weapons
	for (int i = 0; i < size(invent.weapons); i++) {
		if (invent.weapons[i] != "")
			cout << "\t" << i + 1 << " " + invent.weapons[i] << endl;
	}


	// This loop pirnts locked weapons
	for (int i = 0; i < size(invent.lockedWeapons); i++) {
		if (invent.lockedWeapons[i] == "");
		else {
			cout << "\t" << i + 1 << " " + invent.lockedWeapons[i] + " Unlock in " << (i + 1) * 11 << " Points" << endl;
		}
	}

	cout << "\n\tFor Purchase Weapons, Enter Weapon Number: ";
	cout << "\n\t0. Main menu\n\t99. Exit Game\n\tEnter Option: ";
	cin >> select;
	if (select == 1) {
		if (character.exp >= 10) {
			character.exp -= 10;
			invent.weapons[0] = invent.lockedWeapons[0];
			invent.lockedWeapons[0] = "";
			inventry();
		}
	}
	else if (select == 2) {
		if (character.exp >= 20) {
			character.exp -= 20;
			invent.weapons[1] = invent.lockedWeapons[1];
			invent.lockedWeapons[1] = "";

		}
	}
	else if (select == 3) {
		if (character.exp >= 30) {
			character.exp -= 30;
			invent.weapons[2] = invent.lockedWeapons[2];
			invent.lockedWeapons[2] = "";
			inventry();
		}
	}
	else if (select == 4) {
		if (character.exp >= 40) {
			character.exp -= 40;
			invent.weapons[3] = invent.lockedWeapons[3];
			invent.lockedWeapons[3] = "";
			inventry();
		}
	}
	else if (select == 5) {
		if (character.exp >= 50) {
			character.exp -= 50;
			invent.weapons[4] = invent.lockedWeapons[4];
			invent.lockedWeapons[4] = "";
			inventry();
		}
	}
	else if (select == 0) {
		main();
	}
	else if (select == 99) {
		exitGame();
	}


}

//Select Level
void selevel() {
	string option;
	system("cls");
	do
	{
		cout << "\n\tSelect Level to Start Game\n\n";
		for (int i = 1; i <= level.lvl; i++) {
			cout << "\n\t" << i << ". level " << i << endl;
		}
		cout << "\n\t0.  Main Menu";
		cout << "\n\t99. Exit Game";
		cout << "\n\tChoose option: ";
		cin >> option;
		if (option == "0") {
			main();
		}
		else if (option == "99") {

			exitGame();
		}
		else if (level.lvl == 1) {
			if (option == "1") lvl1();

			else {
				system("cls");
				cout << "\n\tInvalid Choice";
				continue;
			}
		}
		else if (level.lvl == 2) {
			if (option == "1") lvl1();
			else if (option == "2") lvl2();

			else {
				system("cls");
				cout << "\n\tInvalid Choice";
				continue;
			}

		}
		else if (level.lvl == 3) {
			if (option == "1") lvl1();
			else if (option == "2") lvl2();
			else if (option == "3") lvl3();
			else {
				system("cls");
				cout << "\n\tInvalid Choice";
				continue;
			}
		}
		break;
	} while (true);

}


//Level1 Dragon
void lvl1() {
	system("cls");
	string choose;
	srand(time(0));
	string startingMessage = "\n\tPlayer Name:\t" + character.characterName + " \n\tPlayer Class:\t" + character.characterRank + "\n\tPlayer Health:\t" + to_string(character.characterHealth) +
		"\n\tPlayer Exp:\t" + to_string(character.characterExp) +
		" \n\n\tGame Started:\n\n\tIn the mystical land of Eldoria,\n\ta once-harmonious kingdom faces turmoil as an ancient curse unleashes mythical creatures" +
		"\n\tand dark forces upon the realm.\n\tAs chaos ensues, a valiant adventurer, recognized for their prowess, is called upon by the wise oracle.\n\n\tPress Enter to Continue Game...";

	for (int i = 0; i < startingMessage.length(); i++) {
		cout << startingMessage[i];
		Sleep(20);
	}
	cin.get();
	cin.ignore();
	string selectWays;
	do
	{
		cout << "\n\n\tThere are 3 Unknown Paths\n\tSelect b/w 1 to 3: ";

		cin >> selectWays;
		if (selectWays == "1" || selectWays == "2" || selectWays == "3") {
			int randWay = rand() % 3 + 1;
			if (randWay == 1) {
				//Baby Dragon

				lvl1BDragon();
			}
			else if (randWay == 2) {
				//Adult Dragon
				lvl1ADragon();
			}
			else {
				//Giant Dragon
				lvl1GDragon();

			}
			break;
		}
		else {
			system("cls");
			cout << "\n\tInvalid Selection";
		}
	} while (selectWays != "1" || selectWays != "2" || selectWays != "3");

}

// BabyDragon
void lvl1BDragon() {
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Baby Dragon";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {

			cout << "\n\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				dragon.baby = dragon.baby - b;
				cout << "\n\tYou Attacked " << b << " Points";
				a = 0;
				charInfo(a, b, dragon.baby);
				if (dragon.baby <= 0) {
					dragon.baby = 40;
					character.characterExp += 5;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);

					cout << "\n\n\tCongratulations...\n\tBaby Dragon Died and you have Earned 5 Exp Points.\n\n\t";
					Sleep(1500);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.exp += 5;
					system("pause");
					system("cls");
					do
					{

						cout << "\n\n\tThere are 2 Unknown Paths\n\tSelect b/w 1 to 2: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2") {
							int randWay = rand() % 2 + 1;
							if (randWay == 1) {
								//Adult Dragon
								lvl1ADragon();
							}
							else if (randWay == 2) {
								//Giant Dragon
								lvl1GDragon();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2");
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tBaby Dragon turn, Dragon is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 10 + 1;
			cout << "\n\tBaby Dragon Attacked " << a << " Points\n\t";

			charInfo(a, b, dragon.baby);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}

//Adult Dragon
void lvl1ADragon() {
	int a = 0, b = 0, i = 0;
	string choose;
	cout << "\n\tNow here is Adult Dragon";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				dragon.adult = dragon.adult - b;
				cout << "\n\tYou Attacked " << b << " Points";
				a = 0;
				charInfo(a, b, dragon.adult);
				if (dragon.adult <= 0) {
					dragon.adult = 50;
					character.characterExp += 8;
					character.exp += 8;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
					cout << "\n\n\tCongratulations...";
					Sleep(1500);
					cout << "\n\tAdult Dragon Died.\n\tYou have Earned 8 Exp Points\n\n\t";
					system("pause");
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);

					lvl1GDragon();
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				cout << "\tInvalid Choice! Try again";
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tAdult Dragon turn, Dragon is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 15 + 1;//Enemy Max attack points
			cout << "\n\tAdult Dragon Attacked " << a << " Points\n\t";

			charInfo(a, b, dragon.adult);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}

//Giant Dragon
void lvl1GDragon() {
	int a = 0, b = 0, i = 0;
	string choose;
	cout << "\n\tOh, Here is Giant Dragon";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {

			cout << "\n\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				dragon.giant = dragon.giant - b;
				cout << "\n\tYou Attacked " << b << " Points";
				a = 0;
				charInfo(a, b, dragon.giant);
				if (dragon.giant <= 0) {
					dragon.giant = 70;
					character.characterExp += 10;
					character.exp += 10;

					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
					level.lvl++;
					cout << "\n\n\tCongratulations...";
					Sleep(1500);
					cout << "\n\tGiant Dragon Died\n\tYou have Earned 10 Exp Points\n\tYou have Completed Level 1.\n\n\t";
					system("pause");
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp = 0;
					selevel();
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tGiant Dragon turn, Dragon is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 25 + 1;//Enemy max attack points 25
			cout << "\n\tGiant Dragon Attacked " << a << " Points\n\t";

			charInfo(a, b, dragon.giant);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}


//Level2
void lvl2() {

	int a = 0, b = 0;
	character.characterHealth = 100;
	system("cls");
	srand(time(0));
	string startingMessage = "\n\tPlayer Name:\t" + character.characterName + " \n\tPlayer Class:\t" + character.characterRank + "\n\tPlayer Health:\t" + to_string(character.characterHealth) +
		"\n\tPlayer Exp:\t" + to_string(character.characterExp) +
		" \n\n\tGame Started:\n\n\tDisturbed by recent events, \n\tthe Crystal Wyvern flees to the Skyward Archipelago. \n\tMounted on a magical flying creature, the adventurer soars through the skies to confront the wyvern in its crystalline nest.\n\tAerial challenges and airborne adversaries test the adventurer's skill in retrieving the shard of the hidden crystal.\n\n\tPress Enter to Continue Game...";

	for (int i = 0; i < startingMessage.length(); i++) {
		cout << startingMessage[i];
		Sleep(20);
	}
	cin.get();
	cin.ignore();

	string selectWays;
	do
	{
		cout << "\n\n\tThere are 4 Unknown Paths\n\tSelect b/w 1 to 4: ";

		cin >> selectWays;
		if (selectWays == "1" || selectWays == "2" || selectWays == "3" || selectWays == "4") {
			int randWay = rand() % 4 + 1;
			if (randWay == 1) {
				//Bennu Phoneix
				lvl2Bennu();
			}
			else if (randWay == 2) {
				//Feng Phoneix
				lvl2feng();
			}
			else if (randWay == 3) {
				//Fire Phoneix
				lvl2fire();
			}
			else {
				//Huma Phoneix
				lvl2huma();
			}
			break;
		}
		else {
			system("cls");
			cout << "\n\tInvalid Selection";
		}
	} while (selectWays != "1" || selectWays != "2" || selectWays != "3" || selectWays != "4");
}

void lvl2Bennu() {
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Bennu Phoneix";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				phoneix.bennu -= b;
				cout << "\n\tYou Attacked " << b << " Points";
				a = 0;
				charInfo(a, b, phoneix.bennu);
				if (phoneix.bennu <= 0) {
					phoneix.bennu = 70;
					character.characterExp += 10;
					character.exp += 10;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
					cout << "\n\n\tCongratulations...\n\tBennu Phoneix Died\n\tYou have Earned 10 Exp Points.\n";
					Sleep(1500);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					level.lvl++;
					system("pause");
					do
					{

						cout << "\n\n\tThere are 3 Unknown Paths\n\tSelect b/w 1 to 3: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2" || selectWays == "3") {
							int randWay = rand() % 3 + 1;
							if (randWay == 1) {
								//Feng Phoneix
								lvl2feng();
							}
							else if (randWay == 2) {
								//Fire Phoneix
								lvl2fire();
							}
							else if (randWay == 3) {
								//Huma Phoneix
								lvl2huma();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2");
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tBennu Phoneix turn, Bennu is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 15 + 1; //Enemy attacked points, max 15
			cout << "\n\tBennu Phoneix Attacked " << a << " Points\n\t";

			charInfo(a, b, phoneix.bennu);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}
void lvl2feng() {
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Fenghung Phoneix";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			cin.ignore();
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				phoneix.fenghuang -= b;
				cout << "\n\tYou Attacked " << b << " Points";
				charInfo(a, b, phoneix.fenghuang);
				if (phoneix.fenghuang <= 0) {
					phoneix.fenghuang = 60;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
					cout << "\n\n\tCongratulationS...\n\tFenghung Phoneix Died\n\tYou have Earned 12 Points\n";
					Sleep(1500);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 12;
					character.exp += 12;

					system("pause");
					do
					{

						cout << "\n\n\tThere are 2 Unknown Paths\n\tSelect between 1 to 2: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2") {
							int randWay = rand() % 2 + 1;
							if (randWay == 1) {
								//Fire Phoneix
								lvl2fire();
							}
							else if (randWay == 2) {
								//Huma Phoneix
								lvl2huma();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2");
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tFenghung Phoneix turn, Fenghung is attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tFenghung Phoneix Attacked " << a << " Points\n\t";

			charInfo(a, b, phoneix.fenghuang);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}
void lvl2fire() {
	cout << "\n\tHere is Firebird Phoneix";
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				phoneix.fireBird -= b;
				cout << "\n\tYou Attacked " << b << " Points";
				charInfo(a, b, phoneix.fireBird);
				if (phoneix.fireBird <= 0) {
					phoneix.fireBird = 65;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
					cout << "\n\n\tCongratulations...\n\tFireBird Phoneix Died\n\tYou have Earned 13 Exp Points\n";
					Sleep(1500);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 13;
					character.exp += 13;

					system("pause");
					lvl2huma();
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tFenghung Phoneix turn, Fenghung is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tFenghung Phoneix Attacked " << a << " Points\n\t";

			charInfo(a, b, phoneix.fireBird);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}
void lvl2huma() {
	cout << "\n\tOpps, Here is Huma Phoneix";
	int a = 0, b = 0, i = 0;
	string choose;
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				phoneix.huma -= b;
				cout << "\n\tYou Attacked " << b << " Points";
				charInfo(a, b, phoneix.huma);
				if (phoneix.huma <= 0) {
					phoneix.huma = 75;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 15;
					character.exp += 15;
					level.lvl++;
					cout << "\n\n\tCongratulations...\n\tHuma Phoneix Died\n\tYou have Earned 15 Exp Points\n";
					system("pause");
					character.characterExp = 0;
					selevel();
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tHuma Phoneix turn, Huma is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tHuma Phoneix Attacked " << a << " Points\n\t";

			charInfo(a, b, phoneix.huma);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}

//Level3
void lvl3() {

	int a = 0, b = 0;
	character.characterHealth = 100;
	system("cls");
	srand(time(0));
	string startingMessage = "\n\tPlayer Name:\t" + character.characterName + " \n\tPlayer Class:\t" + character.characterRank + "\n\tPlayer Health:\t" + to_string(character.characterHealth) +
		"\n\tPlayer Exp:\t" + to_string(character.characterExp) +
		" \n\n\tGame Started: \n\n\tA cosmic portal appears in the Enchanted Forest, leading to the Astral Nexus. \n\tThe adventurer explores this dimension, solving celestial puzzles and gaining the favor of astral entities. \n\tDiscovering the rogue sorcerers' plan to manipulate time, \n\tthe adventurer must safeguard a cosmic artifact from falling into the wrong hands.\n\n\tPress Enter to Continue Game...";

	for (int i = 0; i < startingMessage.length(); i++) {
		cout << startingMessage[i];
		Sleep(20);
	}
	cin.get();
	cin.ignore();

	string selectWays;
	do
	{
		cout << "\n\n\tThere are 4 Unknown Paths\n\tSelect b/w 1 to 4: ";

		cin >> selectWays;
		if (selectWays == "1" || selectWays == "2" || selectWays == "3" || selectWays == "4") {
			int randWay = rand() % 4 + 1;
			if (randWay == 1) {
				//Naga
				lvl3naga();
			}
			else if (randWay == 2) {
				//Thunder Bird
				lvl3tBird();
			}
			else if (randWay == 3) {
				//Tengue
				lvl3tengue();
			}
			else {
				//Valkyrie
				lvl3valkyrie();
			}
			break;
		}
		else {
			system("cls");
			cout << "\n\tInvalid Selection";
		}
	} while (selectWays != "1" || selectWays != "2" || selectWays != "3" || selectWays != "4");


}

void lvl3naga() {
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Naga";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				lvl3E.naga -= b;
				cout << "\n\tYou Attacked " << b << " Points";
				a = 0;
				charInfo(a, b, lvl3E.naga);
				if (lvl3E.naga <= 0) {
					lvl3E.naga = 70;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 10;
					character.exp += 10;
					cout << "\n\n\tCongratulations...\n\tNaga Died\n\tYou have Earned 10 Exp Points.\n";
					system("pause");
					do
					{

						cout << "\n\n\tThere are 3 Unknown Paths\n\tSelect between 1 to 3: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2" || selectWays == "3") {
							int randWay = rand() % 3 + 1;
							if (randWay == 1) {
								//Thunder Bird
								lvl3tBird();
							}
							else if (randWay == 2) {
								//Tengue
								lvl3tengue();
							}
							else if (randWay == 3) {
								//Valkyrie
								lvl3valkyrie();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2" || selectWays != "3");
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tNaga turn, Naga is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 15 + 1; //Enemy attacked points, max 15
			cout << "\n\tNaga Attacked " << a << " Points\n\t";

			charInfo(a, b, lvl3E.naga);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}
void lvl3tBird() {
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	cout << "\n\tHere is Thunder Bird";
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			cin.ignore();
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				lvl3E.tBird -= b;
				cout << "\n\tYou Attacked " << b << " Points";
				charInfo(a, b, lvl3E.tBird);
				if (lvl3E.tBird <= 0) {
					lvl3E.tBird = 90;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 12;
					character.exp += 12;
					cout << "\n\n\tCongratulations...\n\tThunder Bird Died\n\tYou have Earned 12 Points\n";
					system("pause");
					do
					{

						cout << "\n\n\tThere are 2 Unknown Paths\n\tSelect between 1 to 2: ";

						cin >> selectWays;
						if (selectWays == "1" || selectWays == "2") {
							int randWay = rand() % 2 + 1;
							if (randWay == 1) {
								//Tengue
								lvl3tengue();
							}
							else if (randWay == 2) {
								//Valkyrie
								lvl3valkyrie();
							}
							break;
						}
						else {
							system("cls");
							cout << "\n\tInvalid Selection";
						}
					} while (selectWays != "1" || selectWays != "2");
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tThunder Bird turn, Thunder Bird is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tThunder Bird Attacked " << a << " Points\n\t";

			charInfo(a, b, lvl3E.tBird);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}
void lvl3tengue() {
	cout << "\n\tHere is Tengue";
	int a = 0, b = 0, i = 0;
	string choose, selectWays;
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				lvl3E.tengue -= b;
				cout << "\n\tYou Attacked " << b << " Points";
				charInfo(a, b, lvl3E.tengue);
				if (lvl3E.tengue <= 0) {
					lvl3E.tengue = 100;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC); Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 13;
					character.exp += 13;
					cout << "\n\n\tCongratulations...\n\tTengue Died\n\tYou have Earned 13 Exp Points\n";
					system("pause");
					lvl3valkyrie();
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tTengue turn, Tengue is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 19 + 1; // Enemy attacked points, max 19
			cout << "\n\tTengue Attacked " << a << " Points\n\t";
			charInfo(a, b, lvl3E.tengue);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}
void lvl3valkyrie() {
	cout << "\n\tOpps, Here is Valkyrie The Most Dangerious Enemy.";
	int a = 0, b = 0, i = 0;
	string choose;
	while (character.characterHealth > 0) {

		if (i % 2 == 0) {
			cout << "\n\n\tYour turn";
			cout << "\n\t1. Attack\n\t2. Main Menu\n\t3. Exit Game\n\tChoose Option: ";
			cin >> choose;
			if (choose == "1") {
				++i;
				b = classChar(character.characterRank);
				lvl3E.valkyrie -= b;
				cout << "\n\tYou Attacked " << b << " Points";
				charInfo(a, b, lvl3E.valkyrie);
				if (lvl3E.valkyrie <= 0) {
					lvl3E.valkyrie = 120;
					PlaySound(TEXT("victory.wav"), NULL, SND_ASYNC);
					Sleep(50);
					PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
					character.characterExp += 15;
					character.exp += 15;
					cout << "\n\n\tValkyrie Died\n\tYou have Completed Game\n\tYou have Earned 15 Exp Points\n";
					system("pause");
					character.characterExp = 0;
					main();
					break;
				}
			}
			else if (choose == "2") {
				main();
				break;
			}
			else if (choose == "3") {

				exitGame();
				break;
			}
			else {
				system("cls");
				continue;

			}
		}
		else
		{
			++i;
			cout << "\n\n\tValkyrie turn, Valkyrie is Attacking.";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			b = 0;
			a = rand() % 30 + 1; // Enemy attacked points, max 30
			cout << "\n\tValkyrie Attacked " << a << " Points\n\t";

			charInfo(a, b, lvl3E.valkyrie);
			if (character.characterHealth <= 0) {
				character.characterHealth = 100;
				cout << "\n\n\tYou have lost this level.\n";
				system("pause");
				main();
				break;
			}
		}
	}
}
