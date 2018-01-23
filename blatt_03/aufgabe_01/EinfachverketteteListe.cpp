#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Definition der Nutzdatenklasse für die verkettete Liste
class CData
{
    string anyData;       // Nutzdatum
public:
    CData(const char* pT);
    void PrintIt() const;
};
// Definition der Memberfunktionen
// Konstruktor
CData::CData(const char* pT): anyData(pT)
{
}
// Ausgabe des Nutzdatums
void CData::PrintIt() const
{
    cout << "Nutzdatum: " << anyData << endl;
}

// Definition der Klasse für die verkettete Liste
class VList
{
    VList *pNext;           // Zeiger auf Nachfolger
    CData *pData;           // Zeiger auf Nutzdatum
    // private Konstruktor damit Liste nicht direkt
    // angelegt werden kann!
    VList();
    // private Destruktor, wird über statische Memberfunktion aufgerufen
    ~VList();
public:
    static VList& CreateList();            // Liste anlegen
    static void DeleteList(VList& list);   // Liste entfernen
    bool Add2List(CData *pD);              // Element zur Liste hinzufügen
    void PrintList() const;                // Elemente in der Liste ausgeben
};
// Definition der Memberfunktionen
// Konstruktor, ist private!
VList::VList()
{
    // Listenzeiger initialisieren (ist immer gut!)
    pData = nullptr;
    pNext = nullptr;
}
// Destruktor, ist private!
VList::~VList()
{
    // Entfernt Nutzdatum
    delete pData;
}
// Erzeugt Liste
VList& VList::CreateList()
{
    // Erstes Listenelement explizit anlegen und
    // Referenz darauf zurückliefern
    return *(new VList);
}
// Entfernt Liste
void VList::DeleteList(VList& list)
{
    // Zeiger auf das zu löschende Listenelement definieren
    VList *pDelElement;
    // Zeiger auf Nachfolger ablegen
    pDelElement = list.pNext;
    // So lange noch Nachfolger vorhanden sind
    while (pDelElement != nullptr)
    {
        // Zeiger auf den Nachfolger des Nachfolger merken
        list.pNext = pDelElement->pNext;
        // Nachfolger löschen
        delete pDelElement;
        // Nachfolger ist nun übernächstes Listenelement
        pDelElement = list.pNext;
    }
    // Zum Schluss erstes Listenelement löschen
    delete &list;
}
// Fügt Objekt zur Liste hinzu
bool VList::Add2List(CData *pD)
{
    // Falls nur erstes Listenelement vorhanden
    if (pData == nullptr)
        // Nutzdaten gleich ablegen
        pData = pD;
    // sonst Listenende suchen
    else
    {
        // Hilfszeiger zum Durchlaufen der Liste
        VList *pElement = this;
        // Suche nun letztes Listenelement
        while (pElement->pNext != nullptr)
            pElement = pElement->pNext;
        // Neues Element an bisher letztes anhängen
        pElement->pNext = new VList;
        // Fehler abfangen
        if (pElement->pNext == nullptr)
            return false;
        // Noch Nutzdaten im neuen letzten Listenelement ablegen
        pElement->pNext->pData = pD;
    }
    return true;
}
// Gibt Liste aus
void VList::PrintList() const
{
    // Falls Liste leer, fertig
    if (pData == nullptr)
        return;
    // Hilfszeiger zum Durchlaufen der Liste definieren
    // und auf erstes Element in der Liste setzen
    const VList *pElement = this;
    // Nun komplette Liste durchlaufen
    do
    {
        // Nutzdaten des akt. Elements ausgeben
        pElement->pData->PrintIt();
        // Neues akt. Element ist Nachfolger
        pElement = pElement->pNext;
    } while (pElement != nullptr);
}

// main() Funktion
int main()
{
    // Verkettete Liste erzeugen
    // Geht nicht direkt, da ctor private ist!
    VList& myList = VList::CreateList();

    // Liste mit 10 Elementen füllen
    for (int index=0; index<10; index++)
    {
        // Etwas Text für das Nutzdatum erzeugen
        std::ostringstream os;
        os << "Eintrag Nr. " << index;
        // Nutzdatum an Liste anfügen
        myList.Add2List(new CData(os.str().c_str()));
    }

    // Ganze Liste ausgeben
    myList.PrintList();

    // Liste nun wieder löschen
    // Nicht über dtor, da dtor private ist!
    VList::DeleteList(myList);

}