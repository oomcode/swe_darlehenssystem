/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Sicherheit.cpp
 * 
 */


#include "Sicherheit.h"

/* *************************************************
 * Methode: Sicherheit()
 ************************************************* */
Sicherheit::Sicherheit() {
}

/* *************************************************
 * Methode: ~Sicherheit()
 ************************************************* */
Sicherheit::~Sicherheit() {
}

/* *************************************************
 * Methode: Bearbeiten()
 ************************************************* */
void Sicherheit::Bearbeiten() {
    cout << "Fehler" << endl;
}

/* *************************************************
 * Methode: setWert()
 ************************************************* */
void Sicherheit::setWert(double Wert) {
    this->Wert = Wert;
}

/* *************************************************
 * Methode: getWert()
 ************************************************* */
double Sicherheit::getWert() const {
    return Wert;
}

/* *************************************************
 * Methode: setSichNr()
 ************************************************* */
void Sicherheit::setSichNr(int SichNr) {
    this->SichNr = SichNr;
}

/* *************************************************
 * Methode: getSichNr()
 ************************************************* */
int Sicherheit::getSichNr() const {
    return SichNr;
}

/* *************************************************
 * Methode: setKunde()
 ************************************************* */
void Sicherheit::setKunde(Kunde* kunde) {
    this->kunde = kunde;
}

/* *************************************************
 * Methode: getKunde()
 ************************************************* */
Kunde* Sicherheit::getKunde() const {
    return kunde;
}
