/* Citation and Sources...
OOP345 Workshop 1
Section: NAA
Module: event
Filename: event.cpp
Version 1.0
Author Hung Truong - 147779193 - htruong19@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/9/25 Prelimary Release
2020/9/26 Memory Leak fix
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include "event.h"

using namespace sdds;
unsigned int g_sysClock = 0;

Event::Event() {
	this->info = nullptr;//empty state
	this->seconds = g_sysClock;
}

void Event::display() const{
	static int count = 0; //count the number of iterations display was called

	int tempHH = 0; //hours
	int tempMM = 0; //minutes
	int tempSS = 0; //seconds
	std::cout << std::setw(3) << std::setfill(' ') << count+1 << ". ";
	if (this->info == nullptr || this->info[0] == '\0') {
		std::cout << "[ No Event ]" << std::endl;
	}
	else {
		tempHH = this->seconds / (60*60);
		tempMM = (this->seconds - tempHH*(60*60)) / 60;
		tempSS = this->seconds - tempHH * (60 * 60) - tempMM * 60;
		std::cout << std::setw(2) << std::setfill('0') << tempHH << ":";
		std::cout << std::setw(2) << std::setfill('0') << tempMM << ":";
		std::cout << std::setw(2) << std::setfill('0') << tempSS;
		std::cout << " -> " << info << std::endl;
	}
	count++;
}

void Event::setDescription(const char* src) {
	int i = 0;
	seconds = g_sysClock;
	delete [] info;
	if (src == nullptr || src[0] == '\0') {
		if (this->info != nullptr) {
			this->info = nullptr;
		}
	}
	else {
		for (i = 0; src[i] != '\0'; i++) {}
		if (this->info != nullptr) {
			this->info = nullptr;
		}
		this->info = new char[i+1]();
		for (int b = 0; b < i; b++) {
			this->info[b] = src[b];
		}
		this->info[i] = '\0';
	}
}

Event& Event::operator = (const Event& src) {
	int i = 0;
	delete[] info;
	if (src.info != nullptr) {
		for (i = 0; src.info[i] != '\0'; i++) {}
		info = new char[i + 1]();
		for (int b = 0; b < i; b++) {
			this->info[b] = src.info[b];
		}
		this->info[i] = '\0';

		seconds = src.seconds;
	}
	return *this;
}

Event::~Event() {
	if (g_sysClock == 86400) { //deletes only when g_sysClock equals the total amount of seconds in a day (86400) or when g_sysclock is in the beginning of the day (0) 
		if (info != nullptr) {
			delete[] info;
		}
	}
}
