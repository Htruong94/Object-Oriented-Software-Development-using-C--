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

#ifndef EVENT_H
#define EVENT_H
extern unsigned int g_sysClock; //represents the time of the day in terms of seconds. Range of 0 to 86400

namespace sdds {
	class Event {
		char *info; //event description
		unsigned int seconds; //time passed from midnight with a value within range 0 and 86400
	public:
		Event(); //default constructor
		void display() const; //displays the information stored
		void setDescription(const char* src); //copies src to info
		Event& operator = (const Event& src); //copy assignment operator of Event class
		~Event();
	};
}

#endif