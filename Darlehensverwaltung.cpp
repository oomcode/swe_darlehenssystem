/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Darlehensverwaltung.cpp
 * 
 */

#include "Zahlungsverwaltung.h"
#include "Darlehensverwaltung.h"


/* *************************************************
 * Methode: Darlehensverwaltung()
 ************************************************* */
Darlehensverwaltung::Darlehensverwaltung() {
    darlehensNr = 1000;
}

/* *************************************************
 * Methode: Darlehensverwaltung()
 ************************************************* */
Darlehensverwaltung::Darlehensverwaltung(const Darlehensverwaltung& orig) {
}

/* *************************************************
 * Methode: ~Darlehensverwaltung()
 ************************************************* */
Darlehensverwaltung::~Darlehensverwaltung() {
}

/* *************************************************
 * Methode: betragAnlegen()
 ************************************************* */
double Darlehensverwaltung::betragAnlegen() {
    // Standardbetrag fuer Darlehen
    return 123.45;
}

/* *************************************************
 * Methode: darlehenAnlegen()
 ************************************************* */
void Darlehensverwaltung::darlehenAnlegen(Kunde *kunde, double betrag,
        int anfangsDatumMon, int anfangsDatumYear, int laufzeit,
        double zinssatz) {

    date anfangsDatum;
    
    // Naechste Darlehensnummer
    darlehensNr++;

    anfangsDatum.setDate(anfangsDatumMon, anfangsDatumYear);
    
    // Bestimme Darlehensnummer
    darlehensNr = kunde->GetDarlehen().size() + 1;
    
    // Darlehen fuer Kunden anlegen
    setDarlehen(darlehensNr, betrag, anfangsDatum, laufzeit, zinssatz, kunde);
}

/* *************************************************
 * Methode: setDarlehen()
 ************************************************* */
void Darlehensverwaltung::setDarlehen(int darlehensNr, double betrag,
        date anfangsDatum, int laufzeit, double zinssatz, Kunde* k) {

    // Darlehen erzeugen
    Darlehen* d = new Darlehen(darlehensNr, betrag, anfangsDatum, laufzeit, zinssatz, k);

    // und Kunden zuordnen
    k->setDarlehen(d);
    
    // Darlehen speichern
    darlehen.push_back(d);
}

/* *************************************************
 * Methode: getDarlehen()
 ************************************************* */
Darlehen* Darlehensverwaltung::getDarlehen(int darlehensnr) {
    for (int i = 0; i < darlehen.size(); i++) {
        if (darlehen.at(i)->getDarlehensNr() == darlehensnr) {
            return darlehen.at(i);
        }
    }
}

/* *************************************************
 * Methode: getDarlehen()
 ************************************************* */
vector<Darlehen*> Darlehensverwaltung::getDarlehen() {
    return darlehen;
}


/* *************************************************
 * Methode: printDarlehenTest()
 * Testmethode (White-Box-Test)
 ************************************************* */
void Darlehensverwaltung::printDarlehenTest() {

    for (int i = 0; i < darlehen.size(); i++) {
        cout << "Darlehensnummer: " << darlehen.at(i)->getDarlehensNr() << "\t";
        cout << "Name: " << darlehen.at(i)->getKunde()->GetName() << "\t";
        cout << "Darlehensbetrag: " << darlehen.at(i)->getBetrag() << endl;
    }

}
