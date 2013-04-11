/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Kundenverwaltung.cpp
 * 
 */

#include "Kundenverwaltung.h"
#include "Darlehen.h"


/* *************************************************
 * Methode: Kundenverwaltung()
 ************************************************* */
Kundenverwaltung::Kundenverwaltung() {
    kunden.clear();  // Kundenliste loeschen
}

/* *************************************************
 * Methode: Kundenverwaltung()
 ************************************************* */
Kundenverwaltung::Kundenverwaltung(const Kundenverwaltung& orig) {
}

/* *************************************************
 * Methode: ~Kundenverwaltung()
 ************************************************* */
Kundenverwaltung::~Kundenverwaltung() {
}


/* *************************************************
 * Methode: erstelleKunde()
 ************************************************* */
void Kundenverwaltung::erstelleKunde(int kundennr, string name, string adresse, int kontonr) {
        Kunde* k = new Kunde(name,adresse,kundennr,kontonr);
        kunden.push_back(k);
}

/* *************************************************
 * Methode: setKonto()
 ************************************************* */
void Kundenverwaltung::setKonto(int kundennr, string bankname, int blz, int kontonummer,
        double kontostand, string waehrung) {

    Kunde *k = getKunde(kundennr);
    k->setKonto(bankname, blz, kontonummer, kontostand, waehrung);
}


/* *************************************************
 * Methode: getKundePos()
 ************************************************* */
Kunde* Kundenverwaltung::getKundePos(int nr){
    if (nr < kunden.size())
       return kunden.at(nr);
    else
        return NULL;
}

/* *************************************************
 * Methode: getKunde()
 ************************************************* */
Kunde* Kundenverwaltung::getKunde(int kundennr){
    for(int i = 0; i<kunden.size();i++){
        if(kunden.at(i)->GetKundenNr() == kundennr)
            return kunden.at(i);
    }
}

/* *************************************************
 * Methode: getKundenAnzahl()
 ************************************************* */
int Kundenverwaltung::getKundenAnzahl() {
    return kunden.size();
}

/* *************************************************
 * Methode: setKunde()
 ************************************************* */
void Kundenverwaltung::setKunde(string name, string adresse, int kundennr, int kontonr) {
        Kunde* k = new Kunde(name,adresse,kundennr,kontonr);
        kunden.push_back(k);
}

/* *************************************************
 * Methode: getKunden()
 ************************************************* */
vector<Kunde*> Kundenverwaltung::getKunden(){
    return kunden;
}
