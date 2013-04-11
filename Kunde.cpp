/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Kunde.cpp
 * 
 */

#include "Kunde.h"

/* *************************************************
 * Methode: Kunde()
 ************************************************* */
Kunde::Kunde() {
    offset = 500;

}

/* *************************************************
 * Methode: Kunde()
 ************************************************* */
Kunde::Kunde(const Kunde& orig) {
    konto.kontonr = orig.GetKontoNr();
    konto.kontostand = orig.GetKontoStand();
    name = orig.GetName();
    adresse = orig.GetAdresse();
    kundennr = orig.GetKundenNr();
}

/* *************************************************
 * Methode: ~Kunde()
 ************************************************* */
Kunde::~Kunde() {
}

/* *************************************************
 * Methode: setKonto()
 ************************************************* */
void Kunde::setKonto(string bankname, int blz, int kontonummer,
        double kontostand, string waehrung) {

    this->konto.bankname = bankname;
    this->konto.blz = blz;
    this->konto.kontonr = kontonummer;
    this->konto.kontostand = kontostand;
    this->konto.waehrung = waehrung;

}

/* *************************************************
 * Methode: setKontoNr()
 ************************************************* */
void Kunde::setKontoNr(int kontonummer) {
    this->konto.kontonr = kontonummer;
}

/* *************************************************
 * Methode: GetKontoNr()
 ************************************************* */
int Kunde::GetKontoNr() const {
    return konto.kontonr;
}

/* *************************************************
 * Methode: setKontoStand()
 ************************************************* */
void Kunde::setKontoStand(double kontostand) {
    this->konto.kontostand = kontostand;
}

/* *************************************************
 * Methode: GetKontoStand()
 ************************************************* */
double Kunde::GetKontoStand() const {
    return konto.kontostand;
}

/* *************************************************
 * Methode: SetKundenNr()
 ************************************************* */
void Kunde::SetKundenNr(int kundenNr) {
    this->kundennr = kundenNr;
}

/* *************************************************
 * Methode: GetKundenNr()
 ************************************************* */
int Kunde::GetKundenNr() const {
    return kundennr;
}

/* *************************************************
 * Methode: SetAdresse()
 ************************************************* */
void Kunde::SetAdresse(string adresse) {
    this->adresse = adresse;
}

/* *************************************************
 * Methode: GetAdresse()
 ************************************************* */
string Kunde::GetAdresse() const {
    return adresse;
}

/* *************************************************
 * Methode: SetName()
 ************************************************* */
void Kunde::SetName(string name) {
    this->name = name;
}

/* *************************************************
 * Methode: GetName()
 ************************************************* */
string Kunde::GetName() const {
    return name;
}

/* *************************************************
 * Methode: GetDarlehen()
 ************************************************* */
vector<Darlehen*> Kunde::GetDarlehen() {
    return darlehen;
}

/* *************************************************
 * Methode: setDarlehen()
 ************************************************* */
void Kunde::setDarlehen(Darlehen * d) {
    darlehen.push_back(d);
}

/* *************************************************
 * Methode: GetDarlehenSize()
 ************************************************* */
int Kunde::GetDarlehenSize() {
    return darlehen.size() + offset;
}
