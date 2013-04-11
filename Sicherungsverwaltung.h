/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Sicherungsverwaltung.h
 * 
 */

#ifndef SICHERUNGSVERWALTUNG_H_H
#define SICHERUNGSVERWALTUNG_H_H

#include "Sicherheit.h"
#include "Auto.h"
#include "Haus.h"
#include "Wertanlage.h"
#include <vector>
#include <string>
#include "Kundenverwaltung.h"

class Kunde; //Forward-Deklaration

class Sicherungsverwaltung
{
	
public:
        void Anzeigen();
        void Anzeigen(int kundennr);
        bool Sicherungspruefung(double darlehenBetrag, int kundennr);

        Sicherheit* getSicherheit(int Nr);
        string getType();
        Sicherungsverwaltung();
        void AutoHinzufuegen(Kunde* k, string modell, string kennzeichen, double wert);
        void HausHinzufuegen(Kunde* k, string adresse, double wert);
        void WertanlageHinzufuegen(Kunde* k, double wert, string name);
        
        void AutoBearbeiten(Sicherheit* SNr, string modell, string kennzeichen, double wert);
        void HausBearbeiten(Sicherheit* SNr, string adresse, double wert);
        void WertanlageBearbeiten(Sicherheit* SNr, double wert, string name);
        
        vector<Sicherheit*> getSicherheiten(int knr);
        int getAnzSicherheiten(int knr);
        
        Kunde* getKunde();
        
private:
	vector<Sicherheit*> sicherheiten;
        int snr;
	
	
};

#endif
