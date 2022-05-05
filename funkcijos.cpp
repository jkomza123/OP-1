#include "funkcijos.h"

int paz=0;
int mokslsk = 0;
int vargsk = 0;
double sk;
string v;
std::vector<Studentas> mokiniai;
std::vector<Studentas> vargsiukai;
std::vector<Studentas> moksliukai;
//GENERAVIMAS

void generavimas(int s, int pz) {
    std::stringstream my_buffer;
    auto start =std::chrono::high_resolution_clock::now();
    for (int i = 0; i <= s; i++) {
        my_buffer << "Vardas" << i << ' ' << "Pavarde" << i << ' ';
        for (int j = 0; j < pz; j++) {
            my_buffer << rand() % 11 << ' ';
        }
        my_buffer << rand() % 11 << '\n';
    }
    std::ofstream out_f("studentai.txt");
    out_f << my_buffer.str();
    out_f.close();
    my_buffer.clear();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double t = (duration.count());
    cout <<"FAILO SUKURIMAS IR UZDARYMAS - " << t/1000 <<" s" << '\n';
}

//VEDAMA IS FAILO

void failotikrinimas() {
    struct nera : public std::exception {
        const char* what() const throw () {
            return " Klaida";
        }
    };
    try
    {   
        std::string eil;
        std::ifstream open_f("studentai.txt");
        std::getline(open_f, eil);
       // open_f.exceptions(std::ifstream::eofbit);
        open_f.open("studentai.txt");
        if (open_f.is_open()) {
            cout << "*Failas atidarytas ir programa pradeda duomenu apdorojima*" << std::endl;
        }
        else if (!open_f.is_open()) {
            throw nera();
        }
        if (open_f.eof())
        {
            cout << "*Failas tuscias*" << std::endl;
        }
    }
    catch (nera& e)
    {
        cout << "*Failo nera arba netinkamas failo formatas*" << e.what() << std::endl;
        _exit(1);
    }
}
void pirmaeil(std::string read_vardas) {

    std::string eil;
    std::ifstream open_f(read_vardas);
    std::getline(open_f, eil);
    int ilg = eil.size();
        for (int i = 1; i < ilg; i++) {

            if (eil[i - 1] == ' ' && eil[i] != ' ') paz++;
        }
        paz = paz - 2;
}
void skaidymas(std::vector <std::string> splited);
void eil_po_eil(std::string read_vardas, std::string write_vardas,int &b) {
    auto start = std::chrono::high_resolution_clock::now();
    std::string eil;
    std::ifstream open_f(read_vardas);
    std::vector<std::string> splited;
    while (open_f) {
        if (!open_f.eof()) {
            std::getline(open_f, eil);
            splited.push_back(eil);
            b++;
        }
        else break;
    }
    open_f.close();
    /*std::ofstream out_f(write_vardas);
    for (std::string a : splited) out_f << a;
    out_f.close();*/
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double t = (duration.count());
    cout << "FAILO NUSKAITYMAS - " << t/1000<<" s" << '\n';
    skaidymas(splited,b);
    
}

void skaidymas(std::vector <std::string> splited,int b) {
    std::string eil;
    for (int i = 1; i < b-1; i++) {
        eil = splited[i];
        std::vector<std::string> eildalys = split (eil, ' ');
        //cout << i <<std:: endl;
        Studentas mok;
        mok.setn( paz);
        mok.setvar ( eildalys[0]);
        mok.setpav ( eildalys[1]);
        //cout << mok.vardas << " " << mok.pavarde << " ";
        for (int j = 0; j < paz + 1; j++)
        {
            mok.setpaz(j);
            std::stringstream value(eildalys[j + 2]);
            if (j < paz) {
                value >> sk;
                mok.setpaz(sk);
                mok.pliusrez(mok.getpaz(j));
            }
            else value >> sk;
            mok.setegz(sk);
        }
        mokiniai.push_back(mok);
    }
    dalijimas(mokiniai, paz, vargsiukai, moksliukai);
    isvestis(mokiniai, paz,vargsiukai,moksliukai);
}
std::vector<std::string> split(std::string eil, char delimiter)
{
    std::vector<std::string> result;
    size_t start;
    size_t end = 0;

    while ((start = eil.find_first_not_of(delimiter, end)) != std::string::npos)
    {
        end = eil.find(delimiter, start);
        result.push_back(eil.substr(start, end - start));
    }

    return result;
}
void dalijimas(std::vector<Studentas>& mok, int paz, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& moksliukai) {
    auto start = std::chrono::high_resolution_clock::now();
    int i = 0;

    /*std::sort(mok.begin(), mok.end(), [](const Studentas& d1, const Studentas& d2) {
        return d1.vardass < d2.vardass;
        });*/

    for (Studentas& m : mok) {
        mok[i].setrez(mok[i].getrez() / mok[i].getn() * 0.4 + 0.6 * mok[i].getegz());
        if (mok[i].getrez() < 5) {
            vargsiukai.push_back(mok[i]);
            vargsk++;
        }
        else {
            mok.push_back(mok[i]);
            mokslsk++;
        }
        i++;
    }
    //for (int i = 0; i < mokslsk + vargsk; i++) mok.pop_front();
    mok.erase(mok.begin(),mok.begin()+mokslsk + vargsk);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double t = (duration.count());
    cout << "STUDENTU RUSIAVIMAS - " << t/1000 << " s" << '\n';
}
void isvestis(std::vector<Studentas>& mok, int paz, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& moksliukai)
{   
    std::stringstream vargsai;
    std::stringstream mokslai;
    auto start = std::chrono::high_resolution_clock::now();
    vargsai << std::setw(20) << "Vardas" <<std:: setw(20) << "Pavarde" <<std:: setw(20) << "Galutinis (Vid.)" <<std:: setw(20) << "Galutinis (Med.)" <<'\n';
    vargsai << "----------------------------------------------------------------------------------------" <<std:: endl;
    mokslai << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << '\n';
    mokslai << "----------------------------------------------------------------------------------------" << std::endl;
    int i = 0;
    
    for (Studentas& m : vargsiukai)
    {
        rikiavimas(vargsiukai, i, paz);
        vargsai << std::setw(20) << vargsiukai[i].vardass() << std::setw(20) << vargsiukai[i].pavardee() << std::setw(10) << std::fixed << std::setprecision(2) << vargsiukai[i].getrez() << std::setw(25) << std::fixed << std::setprecision(2) << vargsiukai[i].getmed() << '\n';
        i++;
    }
    i = 0;
    for (Studentas& m : mok)
    {
       rikiavimas(mok, i, paz);
       mokslai << std::setw(20) << mok[i].vardass() << std::setw(20) << mok[i].pavardee() << std::setw(10) << std::fixed << std::setprecision(2) << mok[i].getrez() << std::setw(25) << std::fixed << std::setprecision(2) << mok[i].getmed() << '\n';
       i++;
    }
    std::ofstream out_v("vargsiukai.txt");
    std::ofstream out_m("moksliukai.txt");
    out_v << vargsai.str();
    out_m << mokslai.str();
    out_v.close();
    out_m.close();
    mokiniai.clear();
    vargsiukai.clear();
    moksliukai.clear();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    double t = (duration.count());
    cout << "STUDENTU ISVEDIMAS - " << t/1000 <<" s" << '\n';
}
void rikiavimas(std::vector<Studentas>& mok, int a, int paz)
{
    int laikinas;
    for (int i = 0; i < mok[a].getn(); i++) {
        for (int j = i + 1; j < mok[a].getn(); j++)
        {
            if (mok[a].getpaz(i) > mok[a].getpaz(j))
            {
                mok[a].swappaz(i, j);
            }
        }
        if (mok[a].getn() % 2 == 0) {
            mok[a].setmed ((mok[a].getpaz(mok[a].getn() / 2) + mok[a].getpaz((mok[a].getn() / 2) - 1)) * 0.5);
        }
        else mok[a].setmed (mok[a].getpaz(mok[a].getn() / 2));
    }
}
//VEDAMA RANKA
void ivestis(Studentas& temp) {
    int p;
    cout << "Iveskite varda: "; cin >> v;
    temp.setvar(v);
    cout << "Iveskite pavarde: "; cin >> v;
    temp.setpav(v);
    for (int i = 0; i < 1000000; i++) {
        if (i == 0) cout << "______________________________________________________________________" << std::endl;
        if (i == 0) cout << "Jei norite, kad pazymys butu sugeneruotas automatiskai, rasykite '11'." << std::endl;
        if (i == 0) cout << "______________________________________________________________________" << std::endl;
        if (i == 0)cout << "Jei norite uzbaigti ivedima, rasykite '-1'." << std::endl;
        if (i == 0)cout << "___________________________________________" << std::endl;
        cout << "Iveskite " << i + 1 << "-a(-i) pazymi: ";
        cin >> p;
        if (p > 10) {
            temp.setpaz(i);
            temp.setpaz(rand() % 11);
            temp.pliusn(1);
        }
        else if (p >= 0 && p <= 10) {
            temp.setpaz(i);
            temp.setpaz(p);
            temp.pliusn(1);
        }
        else i = 10000000;

    }
    cout << "______________________________________________________________________" << std::endl;
    cout << "Jei norite, kad pazymys butu sugeneruotas automatiskai, rasykite '11'." << std::endl;
    cout << "______________________________________________________________________" << std::endl;
    cout << "Iveskite egzamino iverti: ";
    cin >> p;
    if (p > 10) temp.setegz(rand() % 11);
    else temp.setegz(p);
}
void isved(Studentas& temp) {
    cout << std::setw(20) << temp.vardass() << std::setw(20) << temp.pavardee();
    for (int i = 0; i < temp.getn(); i++) temp.pliusrez(temp.getpaz(i));
    if (temp.getn() > 0) {
        temp.setrez(temp.getrez() / temp.getn() * 0.4 + 0.6 * temp.getegz());
        cout << std::setprecision(3) << std::setw(10) << temp.getrez() << std::setprecision(3) << std::setw(25) << temp.getmed() << std::endl;
    }
    else cout << std::setprecision(3) << std::setw(10) << temp.getegz() << std::setprecision(3) << std::setw(25) << temp.getmed() << std::endl;
}
void isdest(Studentas& temp) {
    for (int i = 0; i < temp.getn(); i++) {
        for (int j = i + 1; j < temp.getn(); j++) {
            if (temp.getpaz(i) > temp.getpaz(j))
            {
                temp.swappaz(i,j);
            }
        }
    }
    if (temp.getn() % 2 == 0) {
        temp.setmed ((temp.getpaz(temp.getn() / 2) + temp.getpaz((temp.getn() / 2) - 1)) * 0.5);
    }
    else temp.setmed (temp.getpaz(temp.getn() / 2));
}