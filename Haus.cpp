/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Haus.cpp
 * 
 */

#include "Haus.h"

/* *************************************************
 * Methode: setAdresse()
 ************************************************* */
void Haus::setAdresse(string Adresse) {
    this->Adresse = Adresse;
}


/* *************************************************
 * Methode: getAdresse()
 ************************************************* */
string Haus::getAdresse() const {
    return Adresse;
}
