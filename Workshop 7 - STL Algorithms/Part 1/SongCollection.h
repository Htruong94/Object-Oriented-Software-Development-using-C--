/* Citation and Sources...
OOP345 Workshop 7
Section: NAA
Module: SongCollection
Filename: SongCollection.h
Version 1.0
Author Hung Truong - 147779193 - htruong19@myseneca.ca
Revision History
-----------------------------------------------------------
Date Reason
2020/11/07 Prelimary Release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>

namespace sdds{
	const size_t fLength = { 25 }; //fixed field size of TITLE, ARTIST, ALBUM
	const size_t fLength2 = { 5 }; //fixed field size of YEAR, LENGTH, PRICE

	struct Song { //song structure containing information on the single song
		std::string s_artist; //name of the artist
		std::string s_title; //name of the song
		std::string s_album; //name of the album
		float s_price; //price of the song
		size_t s_year; //year of release
		size_t s_lengthSong; //length of song in seconds
	};

	class SongCollection {
		std::vector<Song> s_List; //manages a collection of objects of type song
	public:
		SongCollection(std::string srcname); //custom constructor taking the name of the file taking line in format TITLE ARTIST ALBUM YEAR LENGTH PRICE
		void display(std::ostream& out) const; //prints content of the collection
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong); //free helper insertion operator that inserts one song's data
}

#endif //SDDS_SONGCOLLECTION_H

