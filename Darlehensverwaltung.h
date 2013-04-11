/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Darlehensverwaltung.h
 * 
 */

#ifndef DARLEHENSVERWALTUNG_H
#define	DARLEHENSVERWALTUNG_H

#include "Kunde.h"
#include "date.h"
#include "Zahlungsverwaltung.h"
#include "Kundenverwaltung.h"

class Darlehensverwaltung {
public:
    Darlehensverwaltung();
    Darlehensverwaltung(const Darlehensverwaltung& orig);
    virtual ~Darlehensverwaltung();
    Darlehen* getDarlehen(int darlehensnr);
    double betragAnlegen();

    void darlehenAnlegen(Kunde *kunde, double betrag,
            int anfangsDatumMon, int anfangsDatumYear, int laufzeit,
            double zinssatz);

    void setDarlehen(int darlehensNr, double betrag,
            date anfangsDatum, int laufzeit, double zinssatz, Kunde* kunde);

    void printDarlehenTest();
    vector<Darlehen*> getDarlehen();

private:
    vector<Darlehen*> darlehen;
    int darlehensNr;
};

#endif	/* DARLEHENSVERWALTUNG_H */

