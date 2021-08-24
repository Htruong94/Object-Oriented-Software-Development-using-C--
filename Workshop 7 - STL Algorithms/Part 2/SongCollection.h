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
2020/11/09 Prelimary Release
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
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>

namespace sdds{
	const size_t fLength = { 25 }; //fixed field size of TITLE, ARTIST, ALBUM
	const size_t fLength2 = { 5 }; //fixed field size of YEAR, LENGTH, PRICE

	struct Song { //song structure containing information on the single song
		std::string m_artist; //name of the artist
		std::string m_title; //name of the song
		std::string m_album; //name of the album
		float m_price; //price of the song
		size_t m_year; //year of release
		size_t m_lengthSong; //length of song in seconds
	};

	class SongCollection {
		std::vector<Song> m_List; //manages a collection of objects of type song
	public:
		SongCollection(std::string srcname); //custom constructor taking the name of the file taking line in format TITLE ARTIST ALBUM YEAR LENGTH PRICE
		void display(std::ostream& out) const; //prints content of the collection
		void sort(std::string sortName); //sorts m_List according to the string parameter's name
		void cleanAlbum(); //remove [none] from album and replace with empty string
		bool inCollection(std::string artistName) const; //returns true if a song in m_List has the artist given by the string parameter, else false
		std::list<Song> getSongsForArtist(std::string artistName) const; //stores song in a list if the song artist matches artistName and returns the list
	};

	std::ostream& operator<<(std::ostream& out, const Song& theSong); //free helper insertion operator that inserts one song's data
}

#endif //SDDS_SONGCOLLECTION_H

