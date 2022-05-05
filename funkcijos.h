#pragma once

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <cctype>
#include <thread>

using std::cout;
using std::cin;
using std::string;
using std::vector;


/*struct Studentas {
	string vardas, pavarde;
	std::vector <int> paz;
	int egz;
	double rezult = 0;
	double med;
	int n = 0;
};*/
// Reikia includinti visas priklausomybes: <iostream>, <string>, <vector>, "mediana.h"
class Studentas {
	// realizacija
private:
	std::string vardas;
	std::string pavarde;
	double egz;
	std::vector<double> paz;
	double rezult = 0;
	double med;
	double n = 0;

	// interfeisas
public:
	
	Studentas() : egz(0) { }  // default konstruktorius
	Studentas(std::istream& is);
	inline std::string vardass() const { return vardas; }    // get'eriai, inline
	inline std::string pavardee() const { return pavarde; }  // get'eriai, inline
	double getmed()
	{
		return med;
	};
	void setmed(double s)
	{
		med = s;
	};// get'eriai
	std::istream& readStudent(std::istream&);
	double getpaz(int i) {
		return paz[i];
	}
	double getrez() {
		return rezult;
	}
	double getegz() {
		return egz;
	}
	int getn() {
		return n;
	}
	//seteriai
	void setvar(string s) {
		vardas = s;
	}
	void setpav(string s) {
		pavarde = s;
	}
	void setn(double s) {
		n = s;
	}
	void setegz(double s) {
		egz = s;
	}
	void setpaz(double s) {
		paz.push_back(s);
	}
	void pliusrez(double s) {
		rezult = rezult + s;
	}
	void setrez(double s) {
		rezult = s;
	}
	void pliusn(double s) {
		n = n + s;
	}
	void swappaz(int a, int b) {
		int laik = paz[a];
		paz[a] = paz[b];
		paz[b] = laik;
	}
};

bool compare(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas& d1, const Studentas& d2);
bool comparePagalEgza(const Studentas&, const Studentas&);

void ivestis(Studentas& temp);
void isved(Studentas& temp);
void isdest(Studentas& temp);

void failotikrinimas();
void eil_po_eil(std::string, std::string, int &b);
void skaidymas(std::vector <std::string> splited,int b);
void pirmaeil(std::string read_vardas);
void israsymas(int b);
vector <std::string> split(std::string eil, char delimiter);
vector<Studentas> sortabc(std::vector<Studentas> mok);
void isvestis(std::vector<Studentas>& mok, int paz, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& moksliukai);
void rikiavimas(std::vector<Studentas>& mok, int a, int paz);
void dalijimas(std::vector<Studentas>& mok, int paz, std::vector<Studentas>& vargsiukai, std::vector<Studentas>& moksliukai);

void generavimas(int s,int pz);