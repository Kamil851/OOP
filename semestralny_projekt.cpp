/**
 * @file main.cpp
 *
 * @mainpage ALG_semestralny projekt
 *
 * @brief Úvodná stránka dokumentácie projektu.
 *
 * Táto dokumentácia poskytuje podrobný popis funkcií a ich očakávaného správania pri práci s množinami uloženými v súboroch a ich operáciách.
 *
 * @section expectations Očakávania
 * - @ref citajMnozinu(const string& subor): Funkcia načíta množinu zo súboru a uloží ju do vektora.
 * - @ref vypisMnozinu(const vector<int>& mnozina): Funkcia vypíše prvky množiny na obrazovku.
 * - @ref prienikMnozin(const vector<int>& A, const vector<int>& B): Funkcia spočíta a vráti prienik dvoch množín.
 *
 * @section goals Ciele
 * - Poskytnúť možnosť načítať množiny zo súborov a vykonávať s nimi operácie.
 * - Implementovať operáciu prieniku množín.
 * - Zabezpečiť prehľadnosť a efektívnosť kódu.
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Funkcia pre načítanie množiny zo súboru do vektora
/**
 * @brief Načíta čísla zo súboru a uloží ich do vektora.
 * @param nazovSuboru Názov súboru, z ktorého sa majú čísla načítať.
 * @param mnozina Vektor, do ktorého sa načítajú čísla zo súboru.
 */
void nacitajMnozinu(const string& nazovSuboru, vector<int>& mnozina) {
    ifstream subor(nazovSuboru);
    int cislo;
    while (subor >> cislo) {
        mnozina.push_back(cislo);
    }
    subor.close();
}

// Funkcia pre vytvorenie prieniku dvoch množín
/**
 * @brief Nájde prienik dvoch množín a vráti ho ako nový vektor.
 * @param mnozina1 Prvá množina.
 * @param mnozina2 Druhá množina.
 * @return vector<int> Vektor obsahujúci prvky, ktoré sú v oboch množinách.
 */
vector<int> prienik(const vector<int>& mnozina1, const vector<int>& mnozina2) {
    vector<int> vysledok;
    // Pomocou funkcie set_intersection nájdeme prienik dvoch triedených množín
    set_intersection(mnozina1.begin(), mnozina1.end(), mnozina2.begin(), mnozina2.end(), back_inserter(vysledok));
    return vysledok;
}

// Funkcia pre uloženie prieniku do súboru
/**
 * @brief Uloží prvky vektora do súboru.
 * @param nazovSuboru Názov súboru, do ktorého sa majú uložiť prvky.
 * @param prienikMnozin Vektor obsahujúci prvky na uloženie.
 */
void ulozPrienik(const string& nazovSuboru, const vector<int>& prienikMnozin) {
    ofstream subor(nazovSuboru);
    for (int cislo : prienikMnozin) {
        subor << cislo << endl;
    }
    subor.close();
}

// Funkcia pre rozdelenie poľa a nájdenie indexu pivotu podľa algoritmu Hoare
/**
 * @brief Rozdelí pole na dve časti okolo pivotu podľa Hoareho algoritmu.
 *
 * @param pole Pole, ktoré sa má rozdeliť.
 * @param lavy Index ľavého okraja rozdelenia.
 * @param pravy Index pravého okraja rozdelenia.
 * @return long Index pivotu po rozdelení.
 */
long hoareovoDelenie(vector<long>& pole, long lavy, long pravy) {
    long pivot = pole[lavy];
    long i = lavy - 1;
    long j = pravy + 1;
    while (true) {
        do {
            i++;
        } while (pole[i] < pivot);
        do {
            j--;
        } while (pole[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(pole[i], pole[j]);
    }
}

// Funkcia pre rekurzívne volanie algoritmu QuickSort
/**
 * @brief Rekurzívne volanie algoritmu QuickSort na triedenie poľa.
 *
 * @param pole Pole, ktoré sa má zatriediť.
 * @param lavy Index ľavého okraja triedenia.
 * @param pravy Index pravého okraja triedenia.
 */
void rekurzivneQuickSort(vector<long>& pole, long lavy, long pravy) {
    if (lavy < pravy) {
        long pivotovyIndex = hoareovoDelenie(pole, lavy, pravy);
        rekurzivneQuickSort(pole, lavy, pivotovyIndex);
        rekurzivneQuickSort(pole, pivotovyIndex + 1, pravy);
    }
}

// Funkcia pre triedenie poľa algoritmom QuickSort
/**
 * @brief Triedi pole algoritmom QuickSort.
 *
 * @param pole Pole, ktoré sa má zatriediť.
 */
void quickSort(vector<long>& pole) {
    long n = pole.size();
    rekurzivneQuickSort(pole, 0, n - 1);
}

int main() {
    // Načítanie množín zo súborov
    vector<int> mnozina1, mnozina2;
    nacitajMnozinu("SourceSeqA.txt", mnozina1);
    nacitajMnozinu("SourceSeqB.txt", mnozina2);

    // Vytvorenie prieniku
    vector<int> vysledok = prienik(mnozina1, mnozina2);

    // Triedenie prieniku algoritmom QuickSort
    vector<long> vysledokLong(vysledok.begin(), vysledok.end());
    quickSort(vysledokLong);

    // Uloženie prieniku do súboru
    ulozPrienik("intersection.txt", vector<int>(vysledokLong.begin(), vysledokLong.end()));

    cout << "Prienik bol uložený do súboru intersection.txt" << endl;

    return 0;
}
