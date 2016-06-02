/*!
* file: MultiString.h
* MultiString class definition
* written: 01/05/2012
* Copyright (c) 2012 by Yu.Zorin
*/
#pragma once
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

class MultiString {
public:
	//constructors destructor
	MultiString() {
		str_nmb = 0;
		buf = NULL;
	};
	MultiString(int n) {
		buf = new char*[str_nmb = n];
		for (int i = 0; i < str_nmb; i++)
			buf[i] = this->buf[i];
	};
	~MultiString() {
		delete[] buf;
	};

	//add function
	char *strcpy(char* k, const char* src) {
		if (src != NULL) {
			char * d = k;
			while (*d++ = *src++);
			return k;
		};
	}

	//Methods
	char * operator[] (int nindex) const {
		return buf[nindex];
	};
	MultiString & operator+=(const MultiString &src) {
		if (src.str_nmb > 0) {
			int sizeThis = str_nmb;
			int sizeSrc = src.str_nmb;
			int size = sizeThis + sizeSrc;
			char **buf1 = new char*[sizeThis];
			for (int i = 0; i < size; i++)
				buf1[i] = buf[i];
			delete[] buf;
			buf = new char*[str_nmb = size];
			for (int i = 0; i < sizeThis; i++)
				buf[i] = buf1[i];
			for (int i = 0; i < sizeSrc; i++)
				buf[sizeThis + i] = src.buf[i];
			delete[] buf1;
		}
		return *this;
	};
	MultiString& MergeMultiStringexcl(const MultiString &src) {
		if (src.str_nmb > 0) {
			int sizeThis = str_nmb;
			int sizeSrc = src.str_nmb;
			int size = 0;
			char **buf1 = new char*[sizeThis];
			char **buf2 = new char*[sizeSrc];
			for (int i = 0; i < sizeThis; i++)
				buf1[i] = buf[i];
			for (int i = 0; i < sizeSrc; i++) {
				for (int j = 0; j < sizeThis; j++)
					if (*buf[j] == *src.buf[i]) {
						break;
					}
					else if ((j == sizeThis - 1) && (*buf[j] != *src.buf[i])) {
						size++;
					}
			}
			delete[] buf;
			buf = new char*[str_nmb = size + sizeThis];
			for (int i = 0; i < sizeThis; i++)
				buf[i] = buf1[i];
			for (int i = 0; i < size; i++)
				buf[sizeThis + i] = src.buf[i];
			delete[] buf1;
			delete[] buf2;
		}
		return *this;
	}
	int Find(const char *pszsub) const {
		for (int i = 0; i < str_nmb; i++)
			if (strcmp(buf[i], pszsub) == 0)
				return i;
		return -1;
	}
	int Getlength() const {
		return str_nmb;
	}
	bool Isempty() const {
		if (buf == NULL)
			return true;
		return false;
	}
	void Empty() {
		buf = '\0';
		str_nmb = 0;
	}
	void Setat(int nindex, const char* str) {
		if (buf != NULL) {
			this->buf[nindex] = new char[(strlen(str) + 1)];
			strcpy(this->buf[nindex], str);
		}
	}
	void Printstr(int nindex) const {
		if ((buf != NULL) && (nindex < str_nmb)) {
			cout << "buf[" << nindex << "] = " << *buf[nindex] << ";\n";
		}
		else {
			cout << "Error, vector size = " << str_nmb << ";\n";
		}
	};
private:
	//forbidden copy constructor
	MultiString(const MultiString & ms) {};

	//attributes
	char **buf;//pointer to vector
	int str_nmb;//strings number
};