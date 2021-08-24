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
2020/11/09 Prelimary Release
2020/11/13 Fix errors and implement try and catch for sort function
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

				song.m_title = line.substr(0, fLength);
				line = line.substr(fLength);
				song.m_title = song.m_title.substr(song.m_title.find_first_not_of(' '), song.m_title.find_last_not_of(' ') - song.m_title.find_first_not_of(' ') + 1);

				song.m_artist = line.substr(0, fLength);
				line = line.substr(fLength);
				song.m_artist = song.m_artist.substr(song.m_artist.find_first_not_of(' '), song.m_artist.find_last_not_of(' ') - song.m_artist.find_first_not_of(' ') + 1);

				song.m_album = line.substr(0, fLength);
				line = line.substr(fLength);
				song.m_album = song.m_album.substr(song.m_album.find_first_not_of(' '), song.m_album.find_last_not_of(' ') - song.m_album.find_first_not_of(' ') + 1);

				numTemp = line.substr(0, fLength2);
				line = line.substr(fLength2);
				pos = numTemp.find_first_of("0123456789");
				if (pos != std::string::npos) {
					song.m_year = std::stod(numTemp, &pos);
				}
				else {
					song.m_year = { 0 };
				}
				
				numTemp = line.substr(0, fLength2);
				line = line.substr(fLength2);
				pos = numTemp.find_first_of("0123456789");
				if (pos != std::string::npos) {
					song.m_lengthSong = std::stod(numTemp, &pos);
				}
				else {
					song.m_lengthSong = { 0 };
				}
				
				pos = line.find_first_of("0123456789");
				if (pos != std::string::npos) {
					song.m_price = std::stod(line, &pos);
				}
				else {
					song.m_price = { 0 };
				}
				m_List.push_back(std::move(song));
			}
		}
		catch(std::string err){
			std::cerr << err << std::endl;
		}
	}

	void SongCollection::display(std::ostream& out) const {
		size_t totalTime{ 0 };

		totalTime = std::accumulate(m_List.begin(), m_List.end(), (size_t)0, [&](const size_t acc, const Song& song) {
			out << song << std::endl;
			return acc + song.m_lengthSong;
		});
		
		out << std::setw(89) << std::setfill('-')  << '\n';

		out << "| " << std::setw(77) << std::setfill(' ') << "Total Listening Time: " << totalTime / 3600 << ":";
		out << std::setw(2) << std::setfill('0') << ((totalTime%3600)/60) << ":";
		out << std::setw(2) << totalTime % 60 << std::setfill(' ') << " |";

		out << std::setw(89) << std::setfill('-') << std::endl << std::setfill(' ');
	}

	void SongCollection::sort(std::string sortName) {
		try {
			std::sort(m_List.begin(), m_List.end(), [&](
				const Song& s1, const Song& s2) {
					if (sortName == "title") {
						return s1.m_title < s2.m_title;
					}
					else if (sortName == "album") {
						return s1.m_album < s2.m_album;
					}
					else if (sortName == "length") {
						return s1.m_lengthSong < s2.m_lengthSong;
					}
					else {
						std::string err{ "Invalid sort name: " + sortName };
						throw err;
					}
				});
		}
		catch (std::string err) {
			std::cerr << err << std::endl;
		}
	}

	void SongCollection::cleanAlbum() {
		std::for_each(m_List.begin(), m_List.end(), [](Song& song) {
			if (song.m_album == "[None]") {
				song.m_album = { "" };
			}
		});
	}

	bool SongCollection::inCollection(std::string artistName) const {
		bool artist{ false };
		artist = std::any_of(m_List.begin(), m_List.end(), [&](const Song song) {
			return bool(song.m_artist == artistName);
		});
		return artist;
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artistName) const {
		std::list<Song> artistList (std::count_if(m_List.begin(), m_List.end(), [&](const Song song) ->
			bool {return song.m_artist == artistName;})); //creating container of size matching the amount of songs with matching artist
		std::copy_if(m_List.begin(), m_List.end(), artistList.begin(), [&](const Song song) ->
			bool {return song.m_artist == artistName;}); //copying object from vector to list with songs of matching artist

		return artistList;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong) {
		out << "| " << std::setw(21) << std::left << theSong.m_title;
		out << "| " << std::setw(16) << theSong.m_artist;
		out << "| " << std::setw(21) << theSong.m_album;
		if (theSong.m_year == 0) {
			out << "|" << std::setw(7) << "      ";
		}
		else {
			out << "|" << std::setw(7) << std::right << theSong.m_year;
		}
		out << " | " << theSong.m_lengthSong / 60 << ":";
		out << std::setw(2) << std::setfill('0') << theSong.m_lengthSong % 60 << std::setfill(' ');
		out << " | " << std::setprecision(2) << std::fixed << theSong.m_price << " |";
		return out;
	}
}

