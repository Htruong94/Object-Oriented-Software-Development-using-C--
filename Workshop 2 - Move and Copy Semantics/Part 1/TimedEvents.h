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
		void startClock(); //modifies the start timer of the event
		void stopClock(); //modifies the end timer of the event
		void recordEvent(const char* desc); //takes desc and store it into e_Name while storing the unit of time and find and store the duration of the event
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& src);
	};
}

#endif //SDDS_TIMEDEVENTS_H
