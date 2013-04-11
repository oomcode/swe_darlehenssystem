/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Kunde.h
 * 
 */

#ifndef KUNDE_H
#define	KUNDE_H
#include <string>
#include <vector>
#include "Darlehen.h"

using namespace std;

class Darlehen;

class Kunde {
public:
    Kunde();
    Kunde(string name, string adresse, int kundennr, int kontonr){
        this->SetName(name);
        this->SetAdresse(adresse);
        this->SetKundenNr(kundennr);
        this->setKontoNr(kontonr);
        this->setKontoStand(0.0);
        darlehen.clear();
    };
    
    Kunde(const Kunde& orig);
    virtual ~Kunde();
    
    void setKonto(string, int, int, double, string);
    void setKontoNr(int kontonr);
    void setKontoStand(double kontostand);
    int GetKontoNr() const;
    double GetKontoStand() const;
    void SetKundenNr(int kundenNr);
    int GetKundenNr() const;
    void SetAdresse(string adresse);
    string GetAdresse() const;
    void SetName(string name);
    string GetName() const;
    vector<Darlehen*> GetDarlehen();
    int GetDarlehenSize();
    void setDarlehen(Darlehen * darlehen);
    
private:
    // Kundenattribute
    int kundennr;
    string name;
    string adresse;
    int offset;
    
    // Jeder Kunde besitzt ein Konto
    struct Konto {
        string bankname;
        int blz;
        int kontonr;
        double kontostand;
        string waehrung;   // euro, dollar etc.
    } konto;
    
    // Ein Kunde kann viele Darlehen besitzen
    vector<Darlehen*> darlehen;    
};

#endif	/* KUNDE_H */

