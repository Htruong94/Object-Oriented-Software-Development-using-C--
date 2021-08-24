// Workshop 9 - Multi-Threading
// SecureData.cpp
// 2020/11/28 - Hung Truong - 147779193 - htruong19@myseneca.ca - OOP345NAA Workshop 9

/*---------------------------------------------------------
I have done all the coding by myselfand only copied the code
that my professor provided to complete my workshopsand assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;

		// encode using key
		code(key);
		*ofs << "Data encrypted in memory\n";
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{
		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		//converter(text, key, nbytes, Cryptor());

		/*thread t1(converter, text, key, nbytes/2, Cryptor());
		thread t2(converter, text + nbytes/2, key, nbytes/2, Cryptor());
		t1.join();
		t2.join();*/
		const int numThreads{ 10 }; //change number to change the number of threads used
		auto conBind = std::bind(converter, placeholders::_1, key, nbytes/numThreads, Cryptor()); //binding syntax used above, placeholder dependent on iteration
		vector<thread> threads;
		for (int i = 0; i < numThreads; i++) {
			threads.push_back(thread(conBind, text + (nbytes*i/numThreads)));
		}

		for (auto& thread : threads) {
			thread.join();
		}
		encoded = !encoded;
	}

	void SecureData::backup(const char* file) {
		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing

			ofstream ofile(file, ios::binary);
			if (!ofile) {
				string err{ "binary file, [" + string{file} + "], for writing cannot be opened" };
				throw err;
			}

			// TODO: write data into the binary file
			//         and close the file
			ofile.write(text, nbytes);
			ofile.close();
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		ifstream infile(file, ios::binary);
		if (!infile) {
			string err{ "binary file, [" + string{file} +"], for reading cannot be opened" };
			throw err;
		}

		// TODO: - allocate memory here for the file content
		infile.seekg(0, ios::end);
		nbytes = infile.tellg();
		if (text != nullptr) {
			delete[] text;
		}
		text = new char[nbytes];

		// TODO: - read the content of the binary file
		infile.seekg(0);
		infile.read(text, nbytes);

		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
