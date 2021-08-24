/* Citation and Sources...
OOP345 Workshop 7
Section: NAA
Module: SongCollection
Filename: SongCollection.cpp
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

#include "SongCollection.h"

namespace sdds {
	SongCollection::SongCollection(std::string srcname) {
		std::string line{ "" };
		std::string numTemp{ "" };
		size_t pos{ 0 };

		try {
			std::ifstream file(srcname);
			if (!file) {
				std::string err{ "Incorrect file name!" };
				throw err;
			}
			while (!file.eof()) {
				std::getline(file, line);
				Song song;

				song.s_title = line.substr(0, fLength);
				line = line.substr(fLength);
				song.s_title = song.s_title.substr(song.s_title.find_first_not_of(' '), song.s_title.find_last_of("abcdefghijklmnopqrstuvwxyz[].?")+1);

				song.s_artist = line.substr(0, fLength);
				line = line.substr(fLength);
				song.s_artist = song.s_artist.substr(song.s_artist.find_first_not_of(' '), song.s_artist.find_last_of("abcdefghijklmnopqrstuvwxyz[].?") + 1);

				song.s_album = line.substr(0, fLength);
				line = line.substr(fLength);
				song.s_album = song.s_album.substr(song.s_album.find_first_not_of(' '), song.s_album.find_last_of("abcdefghijklmnopqrstuvwxyz[].?") + 1);
				
				numTemp = line.substr(0, fLength2);
				line = line.substr(fLength2);
				pos = numTemp.find_first_of("0123456789");
				if (pos != std::string::npos) {
					song.s_year = std::stod(numTemp, &pos);
				}
				else {
					song.s_year = { 0 };
				}
				
				numTemp = line.substr(0, fLength2);
				line = line.substr(fLength2);
				pos = numTemp.find_first_of("0123456789");
				if (pos != std::string::npos) {
					song.s_lengthSong = std::stod(numTemp, &pos);
				}
				else {
					song.s_lengthSong = { 0 };
				}
				
				pos = line.find_first_of("0123456789");
				if (pos != std::string::npos) {
					song.s_price = std::stod(line, &pos);
				}
				else {
					song.s_price = { 0 };
				}
				s_List.push_back(std::move(song));
			}
		}
		catch(std::string err){
			std::cerr << err << std::endl;
		}
	}

	void SongCollection::display(std::ostream& out) const {
		for (auto song : s_List) {
			out << song << std::endl;
		}
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(21) << std::left << theSong.s_title;
		out << "| " << std::setw(16) << theSong.s_artist;
		out << "| " << std::setw(21) << theSong.s_album;
		if (theSong.s_year == 0) {
			out << "|" << std::setw(7) << "      ";
		}
		else {
			out << "|" << std::setw(7) << std::right << theSong.s_year;
		}
		out << " | " << theSong.s_lengthSong / 60 << ":";
		out << std::setw(2) << std::setfill('0') << theSong.s_lengthSong % 60 << std::setfill(' ');
		out << " | " << std::setprecision(2) << std::fixed << theSong.s_price << " |";
		return out;
	}
}