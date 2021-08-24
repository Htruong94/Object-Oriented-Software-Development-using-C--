#include <iostream>
#include <chrono>
#include <iomanip>
#include "TimedEvents.h"

using namespace sdds;

TimedEvents::TimedEvents() {
	numRec = { 0 };
	st_time = { std::chrono::steady_clock::now() };
	ed_time = { std::chrono::steady_clock::now() };
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
		std::cout << std::endl << numRec << " : " << obj[numRec].e_Name << " : " << obj[numRec].unitTime << " : " << std::chrono::duration_cast<std::chrono::nanoseconds>(obj[numRec].te_Dura).count() << std::endl;
		numRec++;
	}
}

std::ostream& sdds::operator<<(std::ostream& os, const TimedEvents& src) {
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
