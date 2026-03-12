import numpy as np
import sys
import os

# ma zwrocic juz policzone srednie itp z pomiarow
# w formacie csv
# {n.elementow},{%.posortowanych},{sredni czas w ms},{odchylenie standardowe},{rozstep miedzy q3 i q1}

linie_pliku = []
obliczenia = []
if len(sys.argv[1:]) < 2:
    print("-----Nie wprowadzono argumentow dla skryptu-----")
    print(f"python {os.path.basename(__file__)} <nazwa pliku zrodlowego> <nazwa pliku wyjsciowego>")
    sys.exit()


nazwa_pliku_surowych_danych = sys.argv[1]
nazwa_pliku_gotowych_danych = sys.argv[2]

with open(nazwa_pliku_surowych_danych, "r") as plik:
    linie_pliku = plik.readlines()

surowe_dane = []
for linia in linie_pliku:
    pola = linia.strip("\n").split(',')
    #[n.elementow, %posortowanych, czas]
    surowe_dane.append([pola[1], pola[2], pola[3]])


obrobione_dane = []
czasy_dla_setki = []
licznik = 0
dane_opisowe = [] # Przechowa [n.elementow, %posortowanych]

for jeden_rekord in surowe_dane:
    czas = float(jeden_rekord[2])
    
    if licznik == 0:
        dane_opisowe = [jeden_rekord[0], jeden_rekord[1]]
        
    czasy_dla_setki.append(czas)
    licznik += 1
    
    if licznik == 100:
        srednia = float(np.mean(czasy_dla_setki))
        odchylenie = float(np.std(czasy_dla_setki))
        kwantyl3, kwantyl1 = np.quantile(czasy_dla_setki, [0.75, 0.25])
        rozstep_miedzy_kwantylami_3_1 = float(kwantyl3 - kwantyl1)
        
        gotowy_wiersz = [dane_opisowe[0], dane_opisowe[1], srednia, odchylenie, rozstep_miedzy_kwantylami_3_1]
        obrobione_dane.append(gotowy_wiersz)
        
        czasy_dla_setki = []
        licznik = 0

with open(nazwa_pliku_gotowych_danych, "w") as gotowy_plik:
    for linia in obrobione_dane:
        for pole in linia:
            gotowy_plik.write(str(pole))
            gotowy_plik.write(',')
        gotowy_plik.write("\n")
