#include "funkcijos.h"



int main()
{
    int p, b = 0, a;
    cout << "Ar norite sugeneruoti atsitiktiniu duomenu faila?" << std::endl;
    cout << "Spauskite 0 jei norite naudoti savo duomenis, 1 jei norite, kad butu sugeneruotas atsitiktiniu duomenu failas." << std::endl;
    cin >> a;
    if (a == 1) {
        int s, pz;
        cout << "Kiek studentu norite ivesti?" << std::endl;
        cin >> s;
        cout << "Po kiek pazymiu tures studentai?" << std::endl;
        cin >> pz;
        generavimas(s,pz);
        a = 0;
    }
    if (a == 0) {
        cout << "Ar norite ivesti patys, ar duomenis ivesti is failo?" << std::endl;
        cout << "Spauskite 0 jei norite ivesti patys, 1 jei norite ivesti is failo." << std::endl;
        cin >> p;
        if (p == 0) {
            cout << "Kiek studentu norite ivesti?" << std::endl;
            cin >> b;
            Studentas* mas = new Studentas[b];
            for (Studentas* a = mas; a < mas + b; a++) {
                ivestis(*a);
            }
            for (Studentas* a = mas; a < mas + b; a++) {
                isdest(*a);
            }
            cout << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Med (Vid.)" << std::endl;
            cout << "______________________________________________________________________________" << std::endl;
            for (Studentas* a = mas; a < mas + b; a++) {
                isved(*a);
            }

            delete[] mas;
        }
        if (p == 1) {
            failotikrinimas();
            pirmaeil("studentai.txt");
            eil_po_eil("studentai.txt", "studentai_copy.txt", b);
        }
    }
}

