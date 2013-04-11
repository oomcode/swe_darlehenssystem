/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Wertanalge.h
 * 
 */

#ifndef WERTANLAGE_H_H
#define WERTANLAGE_H_H

#include "Sicherheit.h"
#include "string.h"
class Wertanlage: public Sicherheit
{
    private:
        string Name;
        
    public:
	virtual string getType() const {return "Wertanlage";}

        void setName(string Name);
        string getName() const;
};

#endif
