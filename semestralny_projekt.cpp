/**
 * @file main.cpp
 *
 * @mainpage ALG_semestralny projekt
 *
 * @brief �vodn&aacute; str&aacute;nka dokument&aacute;cie projektu.
 *
 * T&aacute;to dokument&aacute;cia poskytuje podrobn&yacute; popis funkci&iacute; a ich o&#x010D;ak&aacute;van&eacute;ho spr&aacute;vania pri pr&aacute;ci s mno�inami ulo�en&yacute;mi v s&uacute;boroch a ich oper&aacute;ci&aacute;ch.
 *
 * @section expectations O&#x010D;ak&aacute;vania
 * - @ref citajMnozinu(const string& subor): Funkcia na&#x010D;&iacute;ta mno�inu zo s&uacute;boru a ulo�&iacute; ju do vektora.
 * - @ref vypisMnozinu(const vector<int>& mnozina): Funkcia vyp&iacute;&scaron;e prvky mno�iny na obrazovku.
 * - @ref prienikMnozin(const vector<int>& A, const vector<int>& B): Funkcia spo�&iacute;ta a vr&aacute;ti prienik dvoch mno�&iacute;n.
 *
 * @section goals Ciele
 * - Poskytn&uacute;� mo�nos� na&#x010D;&iacute;ta� mno�iny zo s&uacute;borov a vykon&aacute;va� s nimi oper&aacute;cie.
 * - Implementova&#x0165; oper&aacute;ciu prieniku mno�&iacute;n.
 * - Zabezpe�i� preh&#x013E;adnos� a efekt&iacute;vnos� k&oacute;du.
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Funkcia pre na&#x010D;&iacute;tanie mno�iny zo s&uacute;boru do vektora
/**
 * @brief Na&#x010D;&iacute;ta �&iacute;sla zo s&uacute;boru a ulo�&iacute; ich do vektora.
 * @param nazovSuboru N&aacute;zov s&uacute;boru, z ktor&eacute;ho sa maj&uacute; �&iacute;sla na&#x010D;&iacute;ta�.
 * @param mnozina Vektor, do ktor&eacute;ho sa na&#x010D;&iacute;taj&uacute; �&iacute;sla zo s&uacute;boru.
 */
void nacitajMnozinu(const string& nazovSuboru, vector<int>& mnozina) {
    ifstream subor(nazovSuboru);
    int cislo;
    while (subor >> cislo) {
        mnozina.push_back(cislo);
    }
    subor.close();
}

// Funkcia pre vytvorenie prieniku dvoch mno�&iacute;n
/**
 * @brief N&aacute;jde prienik dvoch mno�&iacute;n a vr&aacute;ti ho ako nov&yacute; vektor.
 * @param mnozina1 Prv&aacute; mno�ina.
 * @param mnozina2 Druh&aacute; mno�ina.
 * @return vector<int> Vektor obsahuj&uacute;ci prvky, ktor&eacute; s&uacute; v oboch mno�in&aacute;ch.
 */
vector<int> prienik(const vector<int>& mnozina1, const vector<int>& mnozina2) {
    vector<int> vysledok;
    // Pomocou funkcie set_intersection n&aacute;jdeme prienik dvoch trieden&yacute;ch mno�&iacute;n
    set_intersection(mnozina1.begin(), mnozina1.end(), mnozina2.begin(), mnozina2.end(), back_inserter(vysledok));
    return vysledok;
}

// Funkcia pre ulo�enie prieniku do s&uacute;boru
/**
 * @brief Ulo�&iacute; prvky vektora do s&uacute;boru.
 * @param nazovSuboru N&aacute;zov s&uacute;boru, do ktor&eacute;ho sa maj&uacute; ulo�i� prvky.
 * @param prienikMnozin Vektor obsahuj&uacute;ci prvky na ulo�enie.
 */
void ulozPrienik(const string& nazovSuboru, const vector<int>& prienikMnozin) {
    ofstream subor(nazovSuboru);
    for (int cislo : prienikMnozin) {
        subor << cislo << endl;
    }
    subor.close();
}

// Funkcia pre rozdelenie po�a a n&aacute;jdenie indexu pivotu pod�a algoritmu Hoare
/**
 * @brief Rozdel&iacute; pole na dve �asti okolo pivotu pod�a Hoareho algoritmu.
 *
 * @param pole Pole, ktor&eacute; sa m&aacute; rozdeli�.
 * @param lavy Index �av&eacute;ho okraja rozdelenia.
 * @param pravy Index prav&eacute;ho okraja rozdelenia.
 * @return long Index pivotu po rozdelen&iacute;.
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

// Funkcia pre rekurz�vne volanie algoritmu QuickSort
/**
 * @brief Rekurz&iacute;vne volanie algoritmu QuickSort na triedenie po�a.
 *
 * @param pole Pole, ktor&eacute; sa m&aacute; zatriedi�.
 * @param lavy Index �av&eacute;ho okraja triedenia.
 * @param pravy Index prav&eacute;ho okraja triedenia.
 */
void rekurzivneQuickSort(vector<long>& pole, long lavy, long pravy) {
    if (lavy < pravy) {
        long pivotovyIndex = hoareovoDelenie(pole, lavy, pravy);
        rekurzivneQuickSort(pole, lavy, pivotovyIndex);
        rekurzivneQuickSort(pole, pivotovyIndex + 1, pravy);
    }
}

// Funkcia pre triedenie po�a algoritmom QuickSort
/**
 * @brief Triedi pole algoritmom QuickSort.
 *
 * @param pole Pole, ktor&eacute; sa m&aacute; zatriedi�.
 */
void quickSort(vector<long>& pole) {
    long n = pole.size();
    rekurzivneQuickSort(pole, 0, n - 1);
}

int main() {
    // Na�&iacute;tanie mno�&iacute;n zo s&uacute;borov
    vector<int> mnozina1, mnozina2;
    nacitajMnozinu("SourceSeqA.txt", mnozina1);
    nacitajMnozinu("SourceSeqB.txt", mnozina2);

    // Vytvorenie prieniku
    vector<int> vysledok = prienik(mnozina1, mnozina2);

    // Triedenie prieniku algoritmom QuickSort
    vector<long> vysledokLong(vysledok.begin(), vysledok.end());
    quickSort(vysledokLong);

    // Ulo�enie prieniku do s&uacute;boru
    ulozPrienik("intersection.txt", vector<int>(vysledokLong.begin(), vysledokLong.end()));

    cout << "Prienik bol ulo�en&yacute; do s&uacute;boru intersection.txt" << endl;

    return 0;
}
