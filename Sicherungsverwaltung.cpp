/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: Sicherungsverwaltung.cpp
 * 
 */


#include "Sicherungsverwaltung.h"


/* *************************************************
 * Methode: Sicherungsverwaltung()
 ************************************************* */
Sicherungsverwaltung::Sicherungsverwaltung() {
    snr = 0;
}

/* *************************************************
 * Methode: Anzeigen()
 * ==> Testmethode
 ************************************************* */
void Sicherungsverwaltung::Anzeigen() {
    
    cout << "Alle Sicherheiten" << endl;
        
    for (int i = 0; i < sicherheiten.size(); i++) {
        cout << sicherheiten.at(i)->getSichNr() << ") \t\t" << sicherheiten.at(i)->getKunde()->GetName() 
                << "\t\t" << sicherheiten.at(i)->getWert() 
                << " Euro" << endl;
    }
    
    cout << endl;
}

/* *************************************************
 * Methode: Anzeigen()
 * Testmethode
 ************************************************* */
void Sicherungsverwaltung::Anzeigen(int knr) {
    
    cout << "Sicherheiten fuer Kunde " << knr << ": " << endl;
    
    for (int i = 0; i < sicherheiten.size(); i++) {
        if (sicherheiten.at(i)->getKunde()->GetKundenNr() == knr) {
            cout << "(" << sicherheiten.at(i)->getSichNr() << ") " <<
            "Wert: " << sicherheiten.at(i)->getWert() << endl;
        }
    }
}


/* *************************************************
 * Methode: getSicherheit()
 ************************************************* */
Sicherheit* Sicherungsverwaltung::getSicherheit(int Nr) {
    if (sicherheiten.size() >= Nr)
       return sicherheiten.at(Nr - 1);
    else
        return NULL;
}


/* *************************************************
 * Methode: getAnzSicherheiten()
 ************************************************* */
int Sicherungsverwaltung::getAnzSicherheiten(int knr) {
    return sicherheiten.size();
}


/* *************************************************
 * Methode: AutoHinzufuegen()
 ************************************************* */
void Sicherungsverwaltung::AutoHinzufuegen(Kunde* k, string modell, string kennzeichen, double wert) {
    Auto* tmp = new Auto();
    tmp->setKunde(k);
    tmp->setSichNr(snr++);
    tmp->setMarke(modell);
    tmp->setKennzeichen(kennzeichen);
    tmp->setWert(wert);

    sicherheiten.push_back(tmp);
}


/* *************************************************
 * Methode: HausHinzufuegen()
 ************************************************* */
void Sicherungsverwaltung::HausHinzufuegen(Kunde* k, string adresse, double wert) {
    Haus* tmp = new Haus();
    tmp->setKunde(k);
    tmp->setSichNr(snr++);
    tmp->setAdresse(adresse);
    tmp->setWert(wert);

    sicherheiten.push_back(tmp);
}


/* *************************************************
 * Methode: WertanlageHinzufuegen()
 ************************************************* */
void Sicherungsverwaltung::WertanlageHinzufuegen(Kunde* k, double wert, string name) {
    Wertanlage* tmp = new Wertanlage();
    tmp->setKunde(k);
    tmp->setSichNr(snr++);
    tmp->setName(name);
    tmp->setWert(wert);

    sicherheiten.push_back(tmp);
}


/* *************************************************
 * Methode: AutoBearbeiten()
 ************************************************* */
void Sicherungsverwaltung::AutoBearbeiten(Sicherheit* SNr, string modell, string kennzeichen, double wert) {
    Auto* tmp = static_cast<Auto*> (SNr);
    tmp->setMarke(modell);
    tmp->setKennzeichen(kennzeichen);
    tmp->setWert(wert);
}


/* *************************************************
 * Methode: HausBearbeiten()
 ************************************************* */
void Sicherungsverwaltung::HausBearbeiten(Sicherheit* SNr, string adresse, double wert) {
    Haus* tmp = static_cast<Haus*> (SNr);
    tmp->setAdresse(adresse);
    tmp->setWert(wert);
}


/* *************************************************
 * Methode: WertanlageBearbeiten()
 ************************************************* */
void Sicherungsverwaltung::WertanlageBearbeiten(Sicherheit* SNr, double wert, string name) {
    Wertanlage* tmp = static_cast<Wertanlage*> (SNr);
    tmp->setName(name);
    tmp->setWert(wert);
}


/* *************************************************
 * Methode: getSicherheiten()
 ************************************************* */
vector<Sicherheit*> Sicherungsverwaltung::getSicherheiten(int knr) {
    vector<Sicherheit*> tmp;
    for (int i = 0; i < sicherheiten.size(); i++) {
        if (sicherheiten.at(i)->getKunde()->GetKundenNr() == knr) {
            tmp.push_back(sicherheiten.at(i));
        }
    }
    return tmp;
}


/* *************************************************
 * Methode: Sicherungspruefung()
 ************************************************* */
bool Sicherungsverwaltung::Sicherungspruefung(double betrag, int kundennr){
    
    double summe = 0;
    
    // Ermittle Wert aller Sicherheiten
    for(int i = 0; i<sicherheiten.size(); i++){
        if(sicherheiten.at(i)->getKunde()->GetKundenNr() == kundennr){
            summe += sicherheiten.at(i)->getWert();
        }
    }
    
    // Fuer 50% der Darlehenssumme muss Sicherheit vorhanden sein
    // Bei kleinem Darlehensbetrag sind keine Sicherheiten erforderlich
    summe = summe * 2;
    if(betrag<=summe || betrag < 1000.0){
        return true;
    }
    else {
        return false;
    }
    
}


