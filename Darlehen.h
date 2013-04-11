/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Darlehen.h
 * 
 */

#ifndef DARLEHEN_H
#define	DARLEHEN_H
#include "date.h"

#include "Sicherheit.h"
#include "Kunde.h"
#include <iostream>
#include <vector>

using namespace std;

class Darlehen {
public:
    Darlehen();
    Darlehen(const Darlehen& orig);

    Darlehen(int darlehensNr, double betrag,
            date anfangsDatum, int laufzeit, double zinssatz, Kunde* kunde) {
        this->zahlungIndex = 0;
        this->setBetrag(betrag);
        this->setRestBetrag(betrag);
        this->setKunde(kunde);
        this->setAnfangsDatum(anfangsDatum);
        this->setactualDate(this->getAnfangsDatum());
        this->setLaufzeit(laufzeit);
        this->setZinssatz(zinssatz);
        this->setDarlehensNr(darlehensNr);
    }

    virtual ~Darlehen();
    void setFesteDarlehensrate(bool festeDarlehensrate);
    bool isFesteDarlehensrate() const;
    void setMonatlDarlehensrate(double monatlDarlehensrate);
    double getMonatlDarlehensrate() const;
    void setZinssatz(double zinssatz);
    double getZinssatz() const;
    void setLaufzeit(int laufzeit);
    int getLaufzeit() const;
    void setAnfangsDatum(date anfangsDatum);
    date getAnfangsDatum() const;
    void setRestBetrag(double rest);
    double getRestBetrag() const;
    void setBetrag(double betrag);
    double getBetrag() const;
    void setDarlehensNr(int darlehensNr);
    int getDarlehensNr() const;
    void setSicherheiten(Sicherheit*);
    void setKunde(Kunde * kunde);
    Kunde * getKunde();
    int getIndex();
    void incIndex();
    void decIndex();
    void setactualDate(date);
    date getactualDate() const;

private:
    int darlehensNr;
    double betrag;
    double restBetrag; //betrag - tilgung (pro monat)
    Kunde * kunde;
    date startDate;
    date actualDate;
    int laufzeit;
    double zinssatz;
    int zahlungIndex;
  
    double monatlDarlehensrate;
    bool festeDarlehensrate;

    vector<Sicherheit*> sicherheiten;
};

#endif	/* DARLEHEN_H */

