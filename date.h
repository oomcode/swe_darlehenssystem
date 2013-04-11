/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: date.h
 * 
 */

#ifndef DATE
#define DATE


#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

class date {
	int month;
	int year;
	
	public:
        date( );
	string getDate( );
        void setDate(int, int);
	int getMon( ) const;
	int getYear( ) const;
	void setMon( int mon );
	void setYear( int year );
        void setDate(date);
	
};
#endif 
