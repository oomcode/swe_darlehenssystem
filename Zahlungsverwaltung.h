/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Zahlungsverwaltung.h
 * 
 */

#ifndef ZAHLUNGSVERWALTUNG_H_H
#define ZAHLUNGSVERWALTUNG_H_H

#include <string>
#include "Darlehen.h"



using namespace std;

class Zahlungsverwaltung
{
	
public:
	Zahlungsverwaltung();
        virtual ~Zahlungsverwaltung();

private:
        bool instance;
    
};

#endif
