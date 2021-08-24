/* Citation and Sources...
OOP345 Workshop 2
Section: NAA
Module: TimedEvents
Filename: TimedEvents.h
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


#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <chrono>
#include <iostream>

namespace sdds {
	const int MAX_NUM_OBJ = 7;

	class TimedEvents {
		std::size_t numRec; //stores the number of records
		std::chrono::steady_clock::time_point st_time; //start time of the current event taken in nanoseconds
		std::chrono::steady_clock::time_point ed_time; //end time of the current event taken in nanoseconds
		struct { //no name structure that contains an array of records
			const char* e_Name; //event name
			const char* unitTime; //predefined units of time
			std::chrono::steady_clock::duration te_Dura; //duration of the recorded event
		} obj[MAX_NUM_OBJ];
	public:
		TimedEvents(); //default contructor of TimedEvents class
		void startClock(); //modifies the start timer of the event to the current time
		void stopClock(); //modifies the end timer of the event to the current time
		void recordEvent(const char* desc); //takes desc and store it into e_Name while storing the unit of time and find and store the duration of the event
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& src); //friend insertion operator
	};
}

#endif //SDDS_TIMEDEVENTS_H
