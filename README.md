# OP-1
### Apie programą.<br>

Programa sukurta studentų vidurkiams skaičiuoti

### Įjungus programą Jums reikės:<br>

- Pasirinkti ar duomenys įkeliami iš failo ar vedami ranka.
- Suvesti kiek studentų duomenis norėsite įvesti.
- Suvesti studento vardą ir pavardę.
- Suvesti pažymius patiems arba parašius 11 pažymys bus sugeneruotas automatiškai.
- Baigus vesti vieno studento duomenis rašyti -1. Tada bus pereita prie kito studento arba pasibaigus programa pasibaigs.

Programa papildyta, kad rodytu klaidas, kurios nutinka įvedant duomenis iš failo.

(Pažymių vidurkis sudaromas vadovaujantis šia formule: galutinis = 0.4 * vidurkis + 0.6 * egzaminas)<br>
(Pažymių mediana sudaroma vadovaujantis šia formule: mediana = 0.4 * pažymių mediana + 0.6 * egzaminas)<br>

### Pasirinkus šiuos nustatymus matysite sudarytą lentelę su studentu pavardėmis, vardais ir pažymių vidurkiais ir medianomis.

- v0.1 Pradinė programos versija skaičiuojanti vidurkį pagal medianą ir pažymius.
- v0.2 Sukurta funkcija skaityti duomenis iš failo.
- v0.3 Sukurta funkcija, rodanti klaidas, nutinkančias programos eigoje.
- v0.4 Sukurtas funkcija, generuojanti atsitiktinių duomenų failą.
- v0.5 Sukurta versija su deque tipo konteineriais.
- v1.0 Optimizuota programa, veikianti sparčiau.
- v1.1 Struktūra data pakeista į class Studentai.

### Kaip įsirašyti programą?

-Įsirašykite mingw32 kompiliatorių.
-Įsijunkite cmd kaip administratorius ir nueikite į norimų konteinerių failo repozitoriją naudodami komandą CD.
-Rašykite mingw32-make run, jums susikurs .exe failas kurį galėsite paleisti savo kompiuteryje.
-Baigę darbą su programa rašykite mingw32-make clean.

### Testavimo rezultatai:

vector dalijamas i 2 konteinerius
failo dydis	nuskaitymas	rusiavimas	isvedimas	
100000	 20	0.086 s		0.2 s		0.325 s			
10000000 5	6.583 s		24.333 s	50.201 s

class O2
failo dydis	nuskaitymas	rusiavimas	isvedimas	
100000	 20	0.1 s		0.051 s		0.388 s		
10000000 5	6.125 s		15.43 s		32.111 s

class O1
failo dydis	nuskaitymas	rusiavimas	isvedimas	
100000	 20	0.1 s		0.045 s		0.362 s		
10000000 5	6.22 s		13.196 s	25.692 s

class Od
failo dydis	nuskaitymas	rusiavimas	isvedimas	
100000	 20	0.356 s		0.108 s		0.936 s		
10000000 5	22.957 s	14.082 s	44.525 s
