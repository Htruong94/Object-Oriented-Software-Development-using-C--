/* Citation and Sources...
OOP345 Workshop 2
Section: NAA
Module: TimedEvents
Filename: TimedEvents.cpp
Version 1.0
Author Hung Truong - 147779193 - htruong19@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/10/3 Prelimary Release
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
#include <chrono>
#include <iomanip>
#include "TimedEvents.h"

namespace sdds {
	TimedEvents::TimedEvents() {
		numRec = { 0 };
		st_time = {  };
		ed_time = {  };
	}

	void TimedEvents::startClock() {
		st_time = { std::chrono::steady_clock::now() };
	}

	void TimedEvents::stopClock() {
		ed_time = { std::chrono::steady_clock::now() };
	}
	void TimedEvents::recordEvent(const char* desc) {
		if (numRec < MAX_NUM_OBJ) {
			obj[numRec].e_Name = desc;
			obj[numRec].unitTime = "nanoseconds";
			obj[numRec].te_Dura = ed_time - st_time;
			numRec++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& src) {
		os << "--------------------------" << std::endl;
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;

		for (size_t i = 0; i < src.numRec; i++) {
			os << std::setw(20) << std::left << src.obj[i].e_Name;
			os << std::setw(12) << std::right << std::chrono::duration_cast<std::chrono::nanoseconds>(src.obj[i].te_Dura).count();
			os << " " << src.obj[i].unitTime << std::endl;
		}

		os << "--------------------------" << std::endl;
		return os;
	}
}