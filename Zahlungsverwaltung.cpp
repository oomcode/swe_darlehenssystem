/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Zahlungsverwaltung.cpp
 * 
 */


#include "Zahlungsverwaltung.h"

/* *************************************************
 * Methode: Zahlungsverwaltung()
 ************************************************* */
Zahlungsverwaltung::Zahlungsverwaltung() {
    
    instance = true;
    
}

/* *************************************************
 * Methode: ~Zahlungsverwaltung()
 ************************************************* */
Zahlungsverwaltung::~Zahlungsverwaltung() {
    
  instance = false;  
  
}
