/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: GUI.h
 * 
 */

#ifndef GUI_H_H
#define GUI_H_H


#include <iostream>
#include <string>
#include <stdlib.h>

#include "Kundenverwaltung.h"
#include "Darlehensverwaltung.h"
#include "Zahlungsverwaltung.h"
#include "Sicherungsverwaltung.h"

using namespace std;

class GUI
{
	
public:
	void bootstrapping ( );
	void menueAnzeigen();
        int eingabeGanzzahl(std::string);
        char eingabeMenuepunkt();
        string eingabeString(string text);
        void testsDurchfuehren() ;
	
private:
        // Attribute - Controller-Objekte
	Darlehensverwaltung* darlehensverwaltung;	
	Kundenverwaltung* kundenverwaltung;
	Sicherungsverwaltung* sicherungsverwaltung;
	Zahlungsverwaltung* zahlungsverwaltung;
	
        // Methoden
        void zeigeAlleKunden();
        void fuegehinzuKunde();
        void gebeausKundenDaten();
        void zeigeKundenDarlehnen();
	void darlehenAnlegenGUI();
        void printDarlehen();
	void kundenverwaltungMenu();

        
        //Sicherheit
        void SicherheitenMenu();
        void SicherheitenBearbeiten( );
        void SicherheitenHinzufuegen( );
        void SicherheitenAnzeigen(int );
        
        void AutoHinzufuegen(Kunde* k);
        void HausHinzufuegen(Kunde* k);
        void WertanlageHinzufuegen(Kunde* k);
        
        void AutoBearbeiten(Sicherheit*);
        void HausBearbeiten(Sicherheit*);
        void WertanlageBearbeiten(Sicherheit*);
        
};

#endif

