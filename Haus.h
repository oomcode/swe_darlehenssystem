/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Haus.h
 * 
 */

#ifndef HAUS_H_H
#define HAUS_H_H

#include "string.h"
#include "Sicherheit.h"
#include <string>
#include <cstdlib>

using namespace std;

class Haus: public Sicherheit
{
private:
    string Adresse;
    
public:
	virtual string getType() const{return "Haus";}
        void setAdresse(string Adresse);
        string getAdresse() const;
        
};

#endif
