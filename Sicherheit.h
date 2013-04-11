/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Sicherheit.h
 * 
 */
#ifndef SICHERHEIT_H_H
#define SICHERHEIT_H_H

//#include "Kunde.h"
#include <string>
#include <iostream>
using namespace std;

class Kunde;

class Sicherheit
{
    
private:
        Kunde * kunde;
	double Wert;
        
protected:
        int SichNr;
    
public:
        Sicherheit();
        virtual ~Sicherheit();
    
	virtual string getType() const { return "Sicherheit"; }

	virtual void Bearbeiten();
        void setWert(double Wert);
        double getWert() const;
        void setSichNr(int SichNr);
        int getSichNr() const;
        void setKunde(Kunde* kunde);
        Kunde* getKunde() const;
	
};

#endif
