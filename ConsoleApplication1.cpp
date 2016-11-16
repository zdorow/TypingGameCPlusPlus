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
int showAge(int, int, int);
void makeColor(int, int);
void makeFunDisplay();
int practice(int, int, int);
void SleepNclear();
void PauseNclear();
void ClearInput();

int main()


{
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX font;
	GetCurrentConsoleFontEx(outcon, false, &font);
	font.dwFontSize.X = 7;
	font.dwFontSize.Y = 14;
	SetCurrentConsoleFontEx(outcon, false, &font);
//intro to game
//defined constants
	int times, more, age, old;
	const int MINP = 5, MINA = 0;
	const int twice = 2;
	
//user input name
	string name;
	system("COLOR 3F");
	cout << "Can you please tell me your name? ";
	getline(cin, name);
	system("CLS");
	cout << "Greetings " << name << "! Welcome to Zach's typing tutor!\n";
	SleepNclear();
	//user input age
	cout << "How old are you? ";
	cin >> age;
	old = showAge(age, MINA, twice);
	cout << "When you are " << old << ", you will be glad you learned to type!\n";
	ClearInput();
	SleepNclear();
	cout << "How many times have you practiced typing? ";
	cin >> times;
	more = practice(times, MINP, twice);
	cout << "When you practice " << more << " more times, you will be glad you put in the effort!\n";
	SleepNclear();
	//fun colored welcome display call
	makeFunDisplay();
	system("COLOR 3F");
	ClearInput();
	//Menu for game
	char menuchoice;
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
			ClearInput();
			PauseNclear();
			break;
		case 'B':
		case 'b':
			system("CLS");
			cout << "Press the letter that appears on the screen followed by the ENTER key.\n\n";
			cout << "You have 4 tries to get the correct answer.\n\n";
			cout << "The score is the incorrect answers subtracted by the correct answers.\n\n";
			cout << "The game lasts for ten rounds, but the score will contine to increase\nor decrease with each round.\n\n";
			ClearInput();
			PauseNclear();
			break;
		case 'C':
		case 'c':
			system("CLS");
			makeFunDisplay();
			system("COLOR 3F");
			break;
		case 'D':
		case 'd':
			exit(0);
			break;
		default:
			system("CLS");
			cout << "Invalid choice\n";
			cout << "Please enter \'A\', \'B\' or \'C\'...\n";
			ClearInput();
			PauseNclear();
		}
	} while (menuchoice != 'a' && menuchoice != 'A');
// Game start
	while (true) {
		int correct = 0;
		int incorrect = 0;
		int score;
		srand(time(NULL));
//random letter generation and user guessing letter
		while (true) {
			for (int round = 10; round > 0; round--) {
				int tries = 0;
				char tri;
				char c = 97 + rand() % 26;
				while (true) {
					cout << "Please type the correct letter:\n";
					cout << c << "\n";
					cin >> tri;
					ClearInput();

					if (tries >= 3) {
						break;
					}
					if (tri == c) {
						correct++;
						break;
					}
					else (tri != c); {
						cout << "Try again! You can do it!\n";
						SleepNclear();
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
				SleepNclear();
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
{	cout << "What would you like to do?\n\n";
	cout << "A:Play typing game!\n";
	cout << "B:Display instructions.\n";
	cout << "C:Repeat color display.\n";
	cout << "D:Quit.\n";}
//Age Function
int showAge(int age, int MINA, int twice)
{	age = age < MINA ? MINA : age;
	return age * twice;}

//Display funcitons
void makeFunDisplay()
{	const int SLEEP_TIME = 100;
	for (int hex = 'B'; hex <= 'E'; hex++) {
		for (int num = '0'; num <= '9'; num++) {
			makeColor(hex, num);
			Sleep(SLEEP_TIME);}
	}
}


void makeColor(int letter, int  number) 
{	string color_str = "COLOR ";
	color_str.push_back((char)letter);
	color_str.push_back((char)number);

	// Set "Color ##"
	system("CLS");
	system(color_str.c_str());
	cout << "Welcome to Zach's awesome typing tutor!!\n";}
// Two parmaters returning one value function
int practice(int times, int MINP, int twice)
{	times = times < MINP ? MINP : times;
	return times * twice;}
void SleepNclear() {
	Sleep(2000);
	system("CLS");}
void PauseNclear() {
	system("PAUSE");
	system("CLS");}
void ClearInput() {
	cin.clear();
	cin.ignore(INT_MAX, '\n');}

