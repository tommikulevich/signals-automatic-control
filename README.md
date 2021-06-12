# 📈 Wizualizacja Sygnałów Automatyki 
### 📜 Opis
Przedstawiamy program umożliwiający wczytywanie, przetwarzanie i wizualizacje danych aktualnego położenia kątowego (roll, pitch, yaw) **robota mobilnego**! Oprócz rysowania *wykresu* położenia od czasu program rysuje prosty *kompas* i wyświetla aktualny kierunek robota (na początku ruchu robot był skierowany na północ). Istnieje również możliwość wyboru pliku z danymi, odrzucenia przerwszych *n* próbek oraz wyboru, co powinna reprezentować oś OY.

> Program został zrealizowany w środowisku Visual Studio 2019 za pomocą Windows Forms (CRL Project with .NET Framework 4.7.2).

### 🎯 Jak uruchomić?
Aby uruchomić program i zapewnić poprawne jego działanie, należy:
1. Upewnić się, że w Visual Studio 2019 jest zainstalowany **C++/CLI support for v142 build tools**.
	Pomóc: https://docs.microsoft.com/en-us/cpp/dotnet/dotnet-programming-with-cpp-cli-visual-cpp?view=msvc-160
2. Wejść w *Project->Project3WSA Properties->Configuration Properties->Linker->System* i zmienić wartość *SubSystem* na **Windows (/SUBSYSTEM:WINDOWS)**.

![Image alt](https://github.com/jwszol-classes/tp-2021-tommikulevich/raw/master/Screen1.png)

3. Wejść w *Project->Project3WSA Properties->Configuration Properties->Linker->Advanced* i zmienić wartość *Entry point* na **main**. 

![Image alt](https://github.com/jwszol-classes/tp-2021-tommikulevich/raw/master/Screen2.png)

4. W przypadku blędów przy uruchamianiu spróbować wejść w folder z projektem, otworzyć ustawienia pliku *FormWSA.resx* i zaznaczyć opcję **Unblock** (jeżeli taka opcja jest).  

*Dodatkowo:* jeżeli przy pierwszym otwarzaniu projektu zamiast formy wyświetla się błąd, należy ponownie uruchomić Visual Studio.

### 💻 Zasady działania 
Windows Forms jest bardzo przyjemnym narzędziem do robienia GUI. Mamy dużo różnych ustawień elementów okna, które niekoniecznie musimy ręcznie wpisywać w kod. 
Działanie programu można określić w kilku krokach:
- Start programu - wyświetlanie elementów okna, rysowanie kompasu bez strzałki.
- Użytkownik wybiera różne opcje i naciska przycisk **Naszkocowac i pokazac kompas**.
- Program przetwarza wybrane opcje.
- Program wczytuje 1 linię z pliku oraz dodaje punkt do wykresu. Strzałka kompasu zmienia swój kierunek. To wszystko powtarza się co 1/25 sekundy (imitacja, że sensor podaje dane z częstotliwością 25 Hz). 
- Gdy plik zostanie w pełni odczytany, wyświetli się odpowiedni komunikat i można ponownie zacząc wizualizację, ale np danych z innego pliku.

Warto zwrócić uwagę również na to, że tylko położenie **Yaw** wpływa na pozycję strzałki kompasu (patrz zdjęcie).

![Image alt](https://github.com/jwszol-classes/tp-2021-tommikulevich/raw/master/Image_RPY.jpg)

### 💪 Autorzy
- **Tomash Mikulevich** | 187720 | ACiR3  
- **Igor Malkovskiy** | 187717 | ACiR3
