import numpy as np

# ma zwrocic juz policzone srednie itp z pomiarow
# w formacie csv
# {nazwa pliku},{n.elementow},{%.posortowanych},{sredni czas w ms},{odchylenie standardowe},

linie_pliku = []
obliczenia = []

with open("mergesort.csv", "r") as plik:
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
        
        gotowy_wiersz = [dane_opisowe[0], dane_opisowe[1], srednia, odchylenie]
        obrobione_dane.append(gotowy_wiersz)
        
        czasy_dla_setki = []
        licznik = 0

for o in obrobione_dane:
    print(o)
