/* 
 * Vorlesung: SWE - SS13
 * Projekt: Darlehenssystem
 * Datum: Maerz/April 2013
 * Autor: Dr. Frank Buehler
 * 
 * Datei: GUI.cpp
 * 
 */

#include "GUI.h"

/* *************************************************
 * Methode: bootstrapping()
 ************************************************* */
void GUI::bootstrapping() {

    // Darlehensverwaltung
    darlehensverwaltung = new Darlehensverwaltung();

    // Kundenverwaltung
    kundenverwaltung = new Kundenverwaltung();

    // Kunde 1 anlegen
    kundenverwaltung->erstelleKunde(4711, "Frank Buehler", "64295 Darmstadt, Schoefferstrasse 8b", 0);
    string bank = "h_da-Bank";
    string waehrung = "Euro";
    kundenverwaltung->setKonto(4711, bank, 50055500, 471100, 1000.0, waehrung);

    // Kunde 2 anlegen
    kundenverwaltung->erstelleKunde(4712, "James Bond", "64295 Darmstadt, Rheinstrasse 999", 0);
    kundenverwaltung->setKonto(4712, bank, 50055500, 471100, 1000.0, waehrung);

    // Sicherungsverwaltung
    sicherungsverwaltung = new Sicherungsverwaltung();

    // Zahlungsverwaltung
    zahlungsverwaltung = new Zahlungsverwaltung();

}

/* *************************************************
 * Methode: eingabeGanzzahl()
 ************************************************* */
int GUI::eingabeGanzzahl(string text) {
    int eingabe = 0;
    string e = "";

    cout << text;

    // cin >> eingabe;

    getline(cin, e);
    eingabe = atoi(e.c_str());

    cin.clear();

    return eingabe;
}

/* *************************************************
 * Methode: eingabeString()
 ************************************************* */
string GUI::eingabeString(string text) {
    string eingabe = "";

    cout << text;
    getline(cin, eingabe);

    cin.clear();

    return eingabe;
}

/* *************************************************
 * Methode: eingabeMenuepunkt()
 ************************************************* */
char GUI::eingabeMenuepunkt() {
    char eingabe = ' ';
    cin >> eingabe;

    return eingabe;
}

/* *************************************************
 * Methode: menueAnzeigen()
 ************************************************* */
void GUI::menueAnzeigen() {

    // Anwendungsstart: Controller-Objekte erzeugen
    bootstrapping();

    // Anzeige des Hauptmenues
    while (true) {
        cout << "***************************************" << endl;
        cout << "*   DarSys13: Darlehenssystem (SS13)  *" << endl;
        cout << "***************************************" << endl;

        cout << "=== Hauptmenue ===" << endl << endl;
        cout << "Bitte waehlen Sie:" << endl;
        cout << "1 - Kundenverwaltung" << endl;
        cout << "2 - Neues Darlehen anlegen" << endl;
        cout << "3 - Alle bestehenden Darlehen anzeigen (Test)" << endl;
        cout << "4 - Sicherungsverwaltung" << endl;
        cout << "9 - Softwaretests durchfuehren (Test)" << endl;
        cout << "0 - Beenden" << endl;

        // Auswahl des Men�punktes
        char eingabe = eingabeMenuepunkt();

        // Funktionen ausf�hren
        switch (eingabe) {
            case '1':
                kundenverwaltungMenu();
                break;
            case '2':
                darlehenAnlegenGUI();
                break;
            case '3':
                printDarlehen(); // Testmethode
                break;
            case '4':
                SicherheitenMenu();
                break;
            case '9':
                testsDurchfuehren(); // White-Box-Tests
                break;
            case '0':
                return;
            default:
                cout << "Fehlerhafte Eingabe" << endl;
                break;
        }

    }
}

/* *************************************************
 * Methode: darlehenAnlegenGUI()
 ************************************************* */
void GUI::darlehenAnlegenGUI() {

    cout << endl << "=== Hauptmenue / Darlehen ===" << endl << endl;
    cout << "Neues Darlehen anlegen" << endl;

    zeigeAlleKunden();

    string eingabe = eingabeString("");

    cout << "\nBitte Kundennummer eingeben." << endl;
    int kundennr = eingabeGanzzahl("Kundennummer: ");

    // Sicherheiten fuer Kunden anzeigen
    SicherheitenAnzeigen(kundennr);

    // Eingabe des Darlehensbetrag
    string betrag = eingabeString("Darlehensbetrag (Euro) = ");
    double darlehensbetrag = ::atof(betrag.c_str());


    int anfangsDatumMonat;
    int anfangsDatumJahr;
    int laufzeit;
    double zinssatz;

    // Weitere Angaben fuer Darlehen
    cout << "Anfangsdatum (Monat): ";
    cin >> anfangsDatumMonat;
    cout << "Anfangsdatum (Jahr): ";
    cin >> anfangsDatumJahr;
    cout << "Laufzeit (in Monaten): ";
    cin >> laufzeit;
    cout << "Zinssatz: ";
    cin >> zinssatz;


    // Darlehen für Kunden anlegen
    // Bei Kleindarlehensbeträge erfolgt keine Sicherheitenprüfung    
    Kunde* k = kundenverwaltung->getKunde(kundennr);
    if (darlehensbetrag < 1000.0) {
        cout << "Keine Sicherungspruefung notwendig!" << endl;
        darlehensverwaltung->darlehenAnlegen(k, darlehensbetrag, anfangsDatumMonat,
                anfangsDatumJahr, laufzeit, zinssatz);
    } else {
        if (sicherungsverwaltung->Sicherungspruefung(darlehensbetrag, kundennr)) {
            darlehensverwaltung->darlehenAnlegen(k, darlehensbetrag, anfangsDatumMonat,
                    anfangsDatumJahr, laufzeit, zinssatz);
        } else
            cout << "Marktwert der Sicherheiten nicht ausreichend!" << endl;
    }

}

/* *************************************************
 * Methode: SicherheitenAnzeigen()
 ************************************************* */
void GUI::SicherheitenAnzeigen(int kundennr) {

    cout << "Sicherheiten" << endl;

    Kunde* k = kundenverwaltung->getKunde(kundennr);
    int anz = sicherungsverwaltung->getAnzSicherheiten(kundennr);

    if (anz == 0)
        cout << "keine Sicherheiten vorhanden!" << endl;
    else {
        // Sicherheiten anzeigen // HIER Fehler? i bei 0 init aber ausgabe 0 -1??? und bei getSicherieten > zu >= geändert!
        //SVN TEST x
        for (int i = 1; i <= anz; ++i) {
            Sicherheit* s = sicherungsverwaltung->getSicherheit(i);
            cout << s->getType() << ": " << s->getWert() << " Euro " << endl;
        }
    }

}

/* *************************************************
 * Methode: printDarlehen()
 ************************************************* */
void GUI::printDarlehen() {
    darlehensverwaltung->printDarlehenTest();
}

/* *************************************************
 * Methode: zeigeAlleKunden()
 ************************************************* */
void GUI::zeigeAlleKunden() {

    int i = 0;
    while (kundenverwaltung->getKundePos(i) != NULL) {
        // Kundenobjekt holen
        Kunde* k = kundenverwaltung->getKundePos(i);

        // Kundenattribute ausgeben
        cout << "Kundennummer: " << k->GetKundenNr() << "\t";
        cout << "Kontonummer: " << k->GetKontoNr() << "\t";
        cout << "Name: " << k->GetName() << "\t";
        cout << "Adresse: " << k->GetAdresse() << "\t";
        cout << endl;

        // Naechster Kunde anzeigen
        ++i;
    }
}

/* *************************************************
 * Methode: fuegehinzuKunde()
 ************************************************* */
void GUI::fuegehinzuKunde() {
    string name, adresse;
    int girokontonr;

    // Automatische Kundennummer vergeben
    int kundennr = kundenverwaltung->getKundenAnzahl() + 1000;

    // Eingabe der restlichen Kundenattributen
    cout << "Geben Sie die Kundendaten ein: " << endl;
    name = eingabeString(" "); // Eingabepuffer enth�lt noch Zeichen \n
    name = eingabeString("Name: ");
    adresse = eingabeString("Adresse: ");
    girokontonr = eingabeGanzzahl("Kontonummer: ");

    // Kundendaten speichern
    kundenverwaltung->setKunde(name, adresse, kundennr, girokontonr);

    Kunde* k = kundenverwaltung->getKunde(kundennr);
    cout << "*********************************************************" << endl;
    cout << "Kunde " << k->GetName() << " mit Kundennummer " << kundennr << " angelegt. " << endl;
    cout << "*********************************************************" << endl << endl;

}

/* *************************************************
 * Methode: gebeausKundenDaten()
 ************************************************* */
void GUI::gebeausKundenDaten() {

    // Holen Anzahl gespeicherter Kunden
    int anz = kundenverwaltung->getKundenAnzahl();

    // Eingabe Kundennummer
    string e = eingabeString("");
    int knr = eingabeGanzzahl("Bitte Kundennummer angeben: ");

    // Suche Kunden und gebe Kundendaten aus
    Kunde* k = kundenverwaltung->getKunde(knr);

    // Wenn Kunde gefunden wurde...
    if (k != NULL) {
        cout << "Kundennummer: " << k->GetKundenNr() << endl;
        cout << "Name: " << k->GetName() << endl;
        cout << "Kontonummer: " << k->GetKontoNr() << endl;
        cout << "Kontostand: " << k->GetKontoStand() << endl;
        cout << "Adresse: " << k->GetAdresse() << endl;
        cout << endl;

    }
}

/* *************************************************
 * Methode: zeigeKundenDarlehnen()
 ************************************************* */
void GUI::zeigeKundenDarlehnen() {

    zeigeAlleKunden();

    // Bestimme Anzahl gespeicherter Kunden
    int anz = kundenverwaltung->getKundenAnzahl();

    // Eingabe Kundennummer
    string e = eingabeString("");
    int knr = eingabeGanzzahl("Bitte Kundennummer angeben: ");

    // Suche Kunden und gebe Kundendaten aus
    Kunde* k = kundenverwaltung->getKunde(knr);

    int darlehenAnz = k->GetDarlehen().size();
    if (darlehenAnz == 0) cout << "Keine Darlehen vorhanden" << endl;

    // Wenn Kunde gefunden wurde...
    if (k != NULL) {
        for (int i = 0; i < k->GetDarlehen().size(); i++) {
            cout << "Darlehensnummer: " << k->GetDarlehen().at(i)->getDarlehensNr() << endl;
            cout << "Betrag: " << k->GetDarlehen().at(i)->getBetrag() << endl;
            cout << "Anfangsdatum: " << k->GetDarlehen().at(i)->getAnfangsDatum().getDate() << endl;
            cout << "Laufzeit: " << k->GetDarlehen().at(i)->getLaufzeit() << endl;
            cout << "Zinssatz: " << k->GetDarlehen().at(i)->getZinssatz() << endl;
        }
    }
    cout << " ************" << endl;
}

/* *************************************************
 * Methode: kundenverwaltungMenu()
 ************************************************* */
void GUI::kundenverwaltungMenu() {


    // Kundenverwaltunsmenue anzeigen
    while (true) {
        cout << endl << "=== Hauptmenue / Kundenverwaltung ===" << endl << endl;
        cout << "1 Alle Kunden ausgeben" << endl;
        cout << "2 Neuen Kunden anlegen" << endl;
        cout << "3 Darlehen eines Kunden anzeigen" << endl;
        cout << "5 Kundeninformationen ausgeben" << endl;
        cout << "0 Beenden" << endl;

        // Auswahl des Men�punktes
        char eingabe = eingabeMenuepunkt();

        // Funktionen ausf�hren
        switch (eingabe) {
            case '1':
                zeigeAlleKunden();
                break;
            case '2':
                fuegehinzuKunde();
                // kundenverwaltung->KundenHinzufuegen();
                break;
            case '3':
                zeigeKundenDarlehnen();
                break;
            case '4':
                break;
            case '5':
                gebeausKundenDaten();
                break;
            case '0':
                return;
            default:
                cout << "Fehlerhafte Eingabe" << endl;
                break;
        }
    }
}

/* *************************************************
 * Methode: SicherheitenMenu()
 ************************************************* */
void GUI::SicherheitenMenu() {
    int knr_sf = 0;
    char input = ' ';
    cout << "===Untermenue Sicherheitsverwaltung===" << endl << endl;
    cout << "1 Sicherheit anzeigen" << endl;
    cout << "2 Sicherheit hinzufuegen" << endl;
    cout << "3 Sicherheit bearbeiten" << endl;
    cout << "4 Alle Sicherheiten auflisten (Test)" << endl;
    cout << "0 Zurueck " << endl;
    cin >> input;

    switch (input) {
        case '1':
            cout << "Bitte KundenNr eingeben:" << endl;
            cin >> knr_sf;
            SicherheitenAnzeigen(knr_sf);
            break;
        case '2':
            SicherheitenHinzufuegen();
            break;
        case '3':
            SicherheitenBearbeiten();
            break;
        case '4':
            sicherungsverwaltung->Anzeigen(); // Test
            break;
        case '0':
            return;
            break;
        default:
            cout << "Fehlerhafte Eingabe" << endl;
            return;
    }
}

/* *************************************************
 * Methode: SicherheitenHinzufuegen()
 ************************************************* */



/* *************************************************
 * Methode: SicherheitenHinzufuegen()
 ************************************************* */
void GUI::SicherheitenHinzufuegen() {
    char input;
    int knr;

    zeigeAlleKunden();

    cout << "Sicherheit hinzufuegen" << endl;
    cout << "Kundennummer: ";
    cin >> knr;
    Kunde* k = kundenverwaltung->getKunde(knr);

    if (k != NULL) {

        cout << "Art(Auto=1; Haus=2; Wertanlage=3): ";
        cin >> input;

        switch (input) {
            case '1':
                AutoHinzufuegen(k);
                break;
            case '2':
                HausHinzufuegen(k);
                break;
            case '3':
                WertanlageHinzufuegen(k);
                break;
            default:
                cout << "Fehlerhafte eingabe!" << endl;
        }
    }

}

/* *************************************************
 * Methode: AutoHinzufuegen()
 ************************************************* */
void GUI::AutoHinzufuegen(Kunde * k) {

    int wert;

    string modell = "", kennzeichen = "", tmpWert = "";

    string x = eingabeString("");
    modell = eingabeString("Bitte geben sie die Marke und das Modell ein:");
    kennzeichen = eingabeString("Bitte geben sie das Kennzeichen ein:");
    tmpWert = eingabeString("Bitte geben sie den Wert der Sicherheit ein:");
    wert = atoi(tmpWert.c_str());

    sicherungsverwaltung->AutoHinzufuegen(k, modell, kennzeichen, wert);
}

/* *************************************************
 * Methode: HausHinzufuegen()
 ************************************************* */
void GUI::HausHinzufuegen(Kunde * k) {

    string adresse = "", tmp = "";
    int wert;

    cout << "Bitte geben sie dieAdresse ein:";
    cin >> adresse;
    cout << "Bitte geben sie den Wert der Sicherheit ein:";
    cin >> tmp;
    wert = atoi(tmp.c_str());

    sicherungsverwaltung->HausHinzufuegen(k, adresse, wert);
}

/* *************************************************
 * Methode: WertanlageHinzufuegen()
 ************************************************* */
void GUI::WertanlageHinzufuegen(Kunde * k) {

    string name = "", tmp = "";
    int wert;
    cout << "Bitte geben sie den Namen ein:";
    cin >> name;
    cout << "Bitte geben sie den Wert der Sicherheit ein:";
    cin >> tmp;
    wert = atoi(tmp.c_str());

    sicherungsverwaltung->WertanlageHinzufuegen(k, wert, name);

}

/* *************************************************
 * Methode: SicherheitenBearbeiten()
 ************************************************* */
void GUI::SicherheitenBearbeiten() {

    string input = "";

    cout << "Bitte waehlen Sie eine Sicherheit:";
    cin >> input;

    int nr = atoi(input.c_str());
    Sicherheit* Snr = sicherungsverwaltung->getSicherheit(nr);

    if (Snr != NULL) {
        string type = Snr->getType();

        if (type == "Auto")
            AutoBearbeiten(Snr);

        if (type == "Haus")
            HausBearbeiten(Snr);

        if (type == "Wertanlage")
            WertanlageBearbeiten(Snr);
    }

}

/* *************************************************
 * Methode: AutoBearbeiten()
 ************************************************* */
void GUI::AutoBearbeiten(Sicherheit * SNr) {
    string modell = "", kennzeichen = "", tmp = "";
    int wert;
    cout << "Bitte geben sie die Marke und das Modell ein:";
    cin >> modell;
    cout << "Bitte geben sie das Kennzeichen ein:";
    cin >> kennzeichen;
    cout << "Bitte geben sie den Wert der Sicherheit ein:";
    cin >> tmp;
    wert = atoi(tmp.c_str());

    sicherungsverwaltung->AutoBearbeiten(SNr, modell, kennzeichen, wert);
}

/* *************************************************
 * Methode: HausBearbeiten()
 ************************************************* */
void GUI::HausBearbeiten(Sicherheit * SNr) {
    string adresse = "", tmp = "";
    int wert;

    cout << "Bitte geben sie dieAdresse ein:";
    cin >> adresse;
    cout << "Bitte geben sie den Wert der Sicherheit ein:";
    cin >> tmp;
    wert = atoi(tmp.c_str());

    sicherungsverwaltung->HausBearbeiten(SNr, adresse, wert);
}

/* *************************************************
 * Methode: WertanlageBearbeiten()
 ************************************************* */
void GUI::WertanlageBearbeiten(Sicherheit * SNr) {
    string name = "", tmp = "";
    int wert;
    cout << "Bitte geben sie den Namen ein:";
    cin >> name;
    cout << "Bitte geben sie den Wert der Sicherheit ein:";
    cin >> tmp;
    wert = atoi(tmp.c_str());

    sicherungsverwaltung->WertanlageBearbeiten(SNr, wert, name);
}

/* *************************************************
 * Methode: testsDurchfuehren()
 * Testmethode (White-Box Test)
 ************************************************* */
void GUI::testsDurchfuehren() {

    // Neuen Kunde anlegen
    string name = "mustermann", adresse = "musterstadt";
    int kontonr = 123, kundennr = 1000;
    kundenverwaltung->setKunde(name, adresse, kundennr, kontonr);

    // Zeiger auf Kunden holen und Sicherheit hinzufuegen
    Kunde* k1 = kundenverwaltung->getKunde(kundennr);
    cout << "Kunde " << k1->GetName() << " Kundennr. " << k1->GetKundenNr() << endl;
    double wert = 10000.0;
    sicherungsverwaltung->HausHinzufuegen(k1, adresse, wert);

    date datum1;
    datum1.setDate(2, 2012);
    double betrag = 100.0;
    int laufzeit = 10;
    double zinsen = 5.0;
    cout << "Darlehensbetrag " << betrag << " Euro " << endl;

    // Pruefen, ob Sicherheit ausreicht
    if (sicherungsverwaltung->Sicherungspruefung(betrag, kundennr)) {
        cout << "Sicherheiten fuer Darlehen ist ausreichend" << endl;
        darlehensverwaltung->setDarlehen(1, betrag, datum1, laufzeit, zinsen, k1);
    }

}
