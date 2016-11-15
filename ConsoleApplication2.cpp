// TypeThree.cpp
//
//Basic Typing Game by Zachary Dorow 
//9/19/2016
//
//This game is to help very novice typists learn how to type.
//
//
//
#include "stdafx.h"
#include <iterator>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <fstream>
#include <direct.h>
using namespace std;

//Function Prototypes
void showMenu();
void showAge(int, double);

int main()


{
	//intro to game
	//defined constants
	int times, more, age;
	const int MIN = 5;
	double twice = 1.5;

	//user input name
	string name;
	system("COLOR 3F");
	cout << "Can you please tell me your name? ";
	getline(cin, name);
	system("CLS");
	cout << "Greetings " << name << "! Welcome to Zach's typing tutor!\n";
	Sleep(2500);
	system("CLS");
	//user input age
	cout << "How old are you? ";
	cin >> age;
	showAge(age, twice);
	Sleep(3000);
	system("CLS");
	//user input practice amount
	cout << "How many times have you practiced typing? ";
	cin >> times;
	times = times < MIN ? MIN : times;
	more = times * twice;
	cout << "When you practice " << more << " more times, you will be glad you put in the effort!\n";
	Sleep(3000);
	system("CLS");
	//fun colored welcome display
	system("COLOR 3A");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 1B");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 2B");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 1B");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 1A");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 1B");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 2A");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 2B");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 1A");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 1B");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 2A");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 2B");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 1A");
	cout << "Welcome to Zach's awesome typing tutor!!\n";
	Sleep(100);
	system("CLS");
	system("COLOR 3F");
	//Menu for game
	char menuchoice;
	bool menu = true;
	do {
		//Menu Display
		showMenu();
		cin >> menuchoice;
		switch (menuchoice)
		{
		case 'A':
		case 'a':
			system("CLS");
			cout << "READY PLAYER ONE!!\n";
			system("PAUSE");
			system("CLS");
			break;
		case 'B':
		case 'b':
			system("CLS");
			cout << "Press the letter that appears on the screen followed by the ENTER key.\n\n";
			cout << "You have 4 tries to get the correct answer.\n\n";
			cout << "The score is the incorrect answers subtracted by the correct answers.\n\n";
			cout << "The game lasts for ten rounds, but the score will contine to increase\nor decrease with each round.\n\n";
			system("PAUSE");
			system("CLS");
			break;
		case 'C':
		case 'c':
			exit(0);
			break;
		default:
			system("CLS");
			cout << "Invalid choice\n";
			cout << "Please enter \'A\', \'B\' or \'C\'...\n";
			system("PAUSE");
			system("CLS");
		}
	} while (menuchoice != 'a' && menuchoice != 'A');
	// Game start
	while (true) {
		int correct = 0;
		int incorrect = 0;
		int score;
		srand(time(NULL));
		while (true) {
			for (int round = 10; round > 0; round--) {
				int tries = 0;
				char tri;
				char c = 97 + rand() % 26;
				while (true) {
					//random letter generation and user input is above
					cout << "Please type the correct letter:\n";
					cout << c << "\n";
					cin >> tri;
					cin.ignore();

					if (tries >= 3) {
						break;
					}
					if (tri == c) {
						correct++;
						break;
					}
					else (tri != c); {
						cout << "Try again! You can do it!\n";
						Sleep(1500);
						system("CLS");
					}
					tries++;
					incorrect++;
					// check for tries
				}

				// check for tries
				if (tries >= 4) {
					cout << "!!!!!You ran out of tries!!!!!\n\n";
				}
				else {
					cout << "***Good Job!***\n";
				}
				Sleep(2000);
				system("CLS");
			}
			//totals incorrect and correct
			score = correct - incorrect;
			cout << "Your score is: " << score << "!\n";
			cout << "You got " << correct << " correct and " << incorrect << " incorrect.\n";;
			ofstream inputFile;
			_mkdir("C:\\TypingGame\\");
			inputFile.open("C:\\TypingGame\\TypingPractice.txt");
			inputFile << "This is " << name << "'s typing score!\n\n";
			inputFile << "************************************\n";
			inputFile << "        Your score is: " << score << "\n";
			inputFile << "You got " << correct << " correct and " << incorrect << " incorrect.\n";
			inputFile << "************************************\n\n";
			inputFile << "!!!!!!!Practice makes perfect!!!!!!!\n";
			inputFile.close();
			char answer;
			while (true) {
				// loop to ask user if they would like to play again.
				// get user response.
				cout << "Would you like to play again (Y/N)? ";
				cin >> answer;
				cin.ignore();

				// check for proper response.
				if (answer == 'n' || answer == 'N' || answer == 'y' || answer == 'Y') {
					break;
				}
				else {
					cout << "Please enter \'Y\' or \'N\'...\n";
				}
			}
			// check user's input and run again or exit;
			if (answer == 'n' || answer == 'N') {
				cout << "Thank you for playing!!!!\n\n";
				cout << "You can check the TypingGame folder on your C drive for a printable file of your score!\n";
				break;
			}
			else {
				system("CLS");
			}
		}
		cout << "\n\nPress Enter to exit. . . ";
		cin.ignore();
		return 0;
		exit(0);

	}
}
//MAIN Menu
void showMenu()
{
	cout << "What would you like to do?\n\n";
	cout << "A:Play typing game!\n";
	cout << "B:Display instructions.\n";
	cout << "C:Quit.\n";
}
//Age Function
void showAge(int age, double twice)
{
	cout << "When you are " << (age * twice) << ", you will be glad you learned to type!\n";
}