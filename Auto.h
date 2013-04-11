/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Auto.h
 * 
 */

#ifndef AUTO_H_H
#define AUTO_H_H

#include "Sicherheit.h"
#include <string>
class Auto: public Sicherheit
{
    private:
        string Kennzeichen;
        string Marke;
        string Seriennr;
        
    public:
	virtual string getType() const{return "Auto";}
        void setSeriennr(string Seriennr);
        string getSeriennr() const;
        void setMarke(string Marke);
        string getMarke() const;
        void setKennzeichen(string Kennzeichen);
        string getKennzeichen() const;
};

#endif
