#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Game.h"
#include <numeric>
#include <cstdlib> 
#include <fstream>
#include <sstream>
#include <ctime>
#include <list>
#include <random>
#include <stdexcept>

class ManageGame
{

public:
	void ProgressControl(System::Windows::Forms::Button^ Q1,
		System::Windows::Forms::Button^ Q2, System::Windows::Forms::Button^ Q3,
		System::Windows::Forms::Button^ Q4, System::Windows::Forms::Button^ Q5,
		System::Windows::Forms::Button^ Q6, System::Windows::Forms::Button^ Q7,
		System::Windows::Forms::Button^ Q8,int navigator) {

		//Keeping track of answered questions 
		if (navigator == 1) {
			Q1->BackColor = System::Drawing::Color::DarkGray;

		}

		if (navigator == 2) {
			Q2->BackColor = System::Drawing::Color::DarkGray;
		}

		if (navigator == 3) {
			Q3->BackColor = System::Drawing::Color::DarkGray;
		}

		if (navigator == 4) {
			Q4->BackColor = System::Drawing::Color::DarkGray;
		}

		if (navigator == 5) {
			Q5->BackColor = System::Drawing::Color::DarkGray;
		}

		if (navigator == 6) {
			Q6->BackColor = System::Drawing::Color::DarkGray;
		}

		if (navigator == 7) {
			Q7->BackColor = System::Drawing::Color::DarkGray;
		}

		if (navigator == 8) {
			Q8->BackColor = System::Drawing::Color::DarkGray;
		}

	}


};


