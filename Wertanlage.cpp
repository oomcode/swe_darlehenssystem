/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Wertanlage.cpp
 * 
 */
#include <cstdlib>

#include "Wertanlage.h"


/* *************************************************
 * Methode: setName()
 ************************************************* */
void Wertanlage::setName(string Name) {
    this->Name = Name;
}

/* *************************************************
 * Methode: getName()
 ************************************************* */
string Wertanlage::getName() const {
    return Name;
}
