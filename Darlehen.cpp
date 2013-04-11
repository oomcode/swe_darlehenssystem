/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Darlehen.cpp
 * 
 */


#include "Darlehen.h"

/* *************************************************
 * Methode: Darlehen()
 ************************************************* */
Darlehen::Darlehen() {
}

/* *************************************************
 * Methode: Darlehen()
 ************************************************* */
Darlehen::Darlehen(const Darlehen& orig) {
    darlehensNr = orig.getDarlehensNr();
    betrag = orig.getBetrag();
    restBetrag = orig.getRestBetrag();
    startDate = orig.getAnfangsDatum();
    actualDate = orig.getactualDate();
    laufzeit = orig.getLaufzeit();
    zinssatz = orig.getZinssatz();
    monatlDarlehensrate = orig.getMonatlDarlehensrate();
    festeDarlehensrate = orig.isFesteDarlehensrate();
}

/* *************************************************
 * Methode: ~Darlehen()
 ************************************************* */
Darlehen::~Darlehen() {
}


/* *************************************************
 * Methode: setactualDate()
 ************************************************* */
void Darlehen::setactualDate(date date){
    this->actualDate = date;
}

/* *************************************************
 * Methode: getactualDate()
 ************************************************* */
date Darlehen::getactualDate() const {
    return actualDate;
}

/* *************************************************
 * Methode: setFesteDarlehensrate()
 ************************************************* */
void Darlehen::setFesteDarlehensrate(bool festeDarlehensrate) {
    this->festeDarlehensrate = festeDarlehensrate;
}

/* *************************************************
 * Methode: isFesteDarlehensrate()
 ************************************************* */
bool Darlehen::isFesteDarlehensrate() const {
    return festeDarlehensrate;
}

/* *************************************************
 * Methode: setMonatlDarlehensrate()
 ************************************************* */
void Darlehen::setMonatlDarlehensrate(double monatlDarlehensrate) {
    this->monatlDarlehensrate = monatlDarlehensrate;
}

/* *************************************************
 * Methode: getMonatlDarlehensrate()
 ************************************************* */
double Darlehen::getMonatlDarlehensrate() const {
    return monatlDarlehensrate;
}

/* *************************************************
 * Methode: setZinssatz()
 ************************************************* */
void Darlehen::setZinssatz(double zinssatz) {
    this->zinssatz = zinssatz;
}

/* *************************************************
 * Methode: getZinssatz()
 ************************************************* */
double Darlehen::getZinssatz() const {
    return zinssatz;
}

/* *************************************************
 * Methode: setLaufzeit()
 ************************************************* */
void Darlehen::setLaufzeit(int laufzeit) {
    this->laufzeit = laufzeit;
}

/* *************************************************
 * Methode: getLaufzeit()
 ************************************************* */
int Darlehen::getLaufzeit() const {
    return laufzeit;
}

/* *************************************************
 * Methode: setAnfangsDatum()
 ************************************************* */
void Darlehen::setAnfangsDatum(date anfangsDatum) {
    this->startDate = anfangsDatum;
}

/* *************************************************
 * Methode: getAnfangsDatum()
 ************************************************* */
date Darlehen::getAnfangsDatum() const {
    return startDate;
}

/* *************************************************
 * Methode: setRestBetrag()
 ************************************************* */
void Darlehen::setRestBetrag(double rest) {
    this->restBetrag = rest;
}

/* *************************************************
 * Methode: getRestBetrag()
 ************************************************* */
double Darlehen::getRestBetrag() const {
    return restBetrag;
}

/* *************************************************
 * Methode: setBetrag()
 ************************************************* */
void Darlehen::setBetrag(double betrag) {
    this->betrag = betrag;
}

/* *************************************************
 * Methode: getBetrag()
 ************************************************* */
double Darlehen::getBetrag() const {
    return betrag;
}

/* *************************************************
 * Methode: setDarlehensNr()
 ************************************************* */
void Darlehen::setDarlehensNr(int darlehensNr) {
    this->darlehensNr = darlehensNr;
}

/* *************************************************
 * Methode: getDarlehensNr()
 ************************************************* */
int Darlehen::getDarlehensNr() const {
    return darlehensNr;
}

/* *************************************************
 * Methode: setKunde()
 ************************************************* */
void Darlehen::setKunde(Kunde* kunde){
    this->kunde = kunde;
}

/* *************************************************
 * Methode: getKunde()
 ************************************************* */
Kunde * Darlehen::getKunde() {
    return kunde;
}

/* *************************************************
 * Methode: incIndex()
 ************************************************* */
void Darlehen::incIndex(){
    zahlungIndex++;
}

/* *************************************************
 * Methode: decIndex()
 ************************************************* */
void Darlehen::decIndex(){
    zahlungIndex--;
}

/* *************************************************
 * Methode: getIndex()
 ************************************************* */
int Darlehen::getIndex(){
    return zahlungIndex;
}

