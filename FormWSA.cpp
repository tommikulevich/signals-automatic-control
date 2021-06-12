// Plik naglowkowy z forma
#include "FormWSA.h"											

// Przestrzeni nazw niezbedne do tworzenia i wywolania metod (funkcji skladowych) w tym pliku (cpp)
using namespace System;											
using namespace System::Windows::Forms;


[STAThreadAttribute]										// Ten atrybut musi byc obecny w punkcie wejscia (w tym przypadku funkcji main) dowolnej aplikacji Windows Forms
void main(array<String^>^ args) {
	Application::EnableVisualStyles();						// Wywolanie niezbednych metod do zarzadzania aplikacja
	Application::SetCompatibleTextRenderingDefault(false);	// -//-

	Project3WSA::FormWSA form;								// Tworzenie zmiennej formularza (dalej - "formy") klasy FormWSA przestrzeni nazw Project3WSA
	Application::Run(% form);								// Uruchamianie formy 
}


std::fstream DATA;			// Zmienna odpowiedzialna za plik z danymi						
std::string fileName;		// Zmienna nazwy pliku

// Konstruktor formy 
Project3WSA::FormWSA::FormWSA(void) 
{
	InitializeComponent();	// Ladowanie strony komponentow
}

// Nadanie wartosci - nazwy wybranego w comboBox pliku - zmiennej fileName 
void Project3WSA::FormWSA::InitializationComboBox()
{
	switch (comboBoxFiles->SelectedIndex)
	{
	case 0:
		fileName = "outputCatapult01.log";
		break;
	case 1:
		fileName = "outputRotateB01.log";
		break;
	case 2:
		fileName = "outputPendulumOrt02.log";
		break;
	}
}

// Metoda analizujaca textBoxSamples
void Project3WSA::FormWSA::InitializationTextBox()
{
	if (textBoxSamples->Text != "") {							// Jezeli textBox nie jest pusty ...
		n = Convert::ToInt32(textBoxSamples->Text);				// ... konwertuj zawartosc na typ int ...
		DATA.seekg(11 * n * sizeof(double), std::ios::beg);		// ... i przejdz na n-ta linie pliku z danymi 
	}
	else {
		MessageBox::Show("Bledne dane! Nie udalo sie usunac prob!", "Blad", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		textBoxSamples->Text = "0";
	}
}

// Metoda analizujaca groupBoxOY z radioButtons - zapisywanie do zmiennej plotNum numeru wykresu (0 oznacza wszystkie wykresy)
void Project3WSA::FormWSA::InitializationGroupBox()
{
	if (radioButtonR->Checked == true)
		plotNum = 1;
	else if (radioButtonP->Checked == true)
		plotNum = 2;
	else if (radioButtonY->Checked == true)
		plotNum = 3;
	else
		plotNum = 0;
}

// Metoda rysowania wykresu 
void Project3WSA::FormWSA::PrintPlot()
{
	double num[12];					// Tablica do przechowywania 12 liczb z jednej linii pliku
	
	for (int i = 0; i < 12; i++)	// Cykl odczytywania 12 liczb z pliku
		if ( !(DATA >> num[i]) )	// Jezeli nie da sie dalej odczytac pliku (np koniec pliku) ...
			work = false;			// ... zakoncz 
	
	if (work) {
		chartDATA->Refresh();				// Odnowienie pola wykresu - ponownie narysowaс wszystkie elementy

		x += 0.04;							// Dodanie 1/25 do wspolrzednej X 
		y1 = num[0];						// Nadanie zmiennym y1, y2, y3 wartosci pierwszej, drugiej i trzeciej liczby linii
		y2 = num[1];						
		y3 = num[2];						

		switch (plotNum)					// Dodanie punktu do konkretnego wykresu (w zaleznosci od plotNum)
		{
		case 1 : 
			plot1->Points->AddXY(x, y1);
			break;
		case 2:
			plot2->Points->AddXY(x, y2);
			break;
		case 3:
			plot3->Points->AddXY(x, y3);
			break;
		default:
			plot1->Points->AddXY(x, y1);
			plot2->Points->AddXY(x, y2);
			plot3->Points->AddXY(x, y3);
			break;
		}

		compassAngle = num[2] * (M_PI / 180);	// Nadanie zmiennej compassAngle wartosci trzeciej liczby (Yaw) w radianach

		PrintCompass();							// Wywolanie funkcji rysowania strzalki kompasu
	}
}

// Metoda rysowania strzalki kompasu
void Project3WSA::FormWSA::PrintCompass()
{
	Pen^ redPen = gcnew Pen(Color::Red, 2.0F);						// Obiekt do rysowania linii i krzywych
	Graphics^ needle = this->pictureBoxCompass->CreateGraphics();	// Obiekt umozliwiajacy rysowanie w pictureBoxCompass

	pictureBoxCompass->Refresh();				// Odnowienie pola z kompasem - ponownie narysowaс wszystkie elementy

	xc = 65 + 65 * sin(compassAngle);			// Obliczanie punktu okregu biorac pod uwage nietypowe polozenie ukladu wspolrzednych
	yc = 65 - 65 * cos(compassAngle);			
	
	needle->DrawLine(redPen, 65, 65, xc, yc);	// Rysowanie linii od srodka pictureBoxCompass do konkretnego punktu okregu
}

// Metoda wyjscia z aplikacji (po nacisniecu przycisku wyjscia)
System::Void Project3WSA::FormWSA::exitMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();	
}

// Metoda do pokazywania informacji o autorach 
System::Void Project3WSA::FormWSA::aboutMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Autorzy:\n1. Tomash Mikulevich, 187720, ACiR3\n2. Igor Malkovskiy, 187717, ACiR3\n", "O projekcie:");
}

// Metoda startujaca - po nacisnieciu przycisku buttonPrint
System::Void Project3WSA::FormWSA::buttonPrint_Click(System::Object^ sender, System::EventArgs^ e)
{
	plot1 = chartDATA->Series[0];		// Inicjalizacja zmiennych plot1, plot2, plot3
	plot2 = chartDATA->Series[1];
	plot3 = chartDATA->Series[2];

	plot1->Points->Clear();				// Czyszczenie wszystkich punktow na wykresach
	plot2->Points->Clear();
	plot3->Points->Clear();

	InitializationComboBox();

	DATA.open(fileName, std::ios::in);	// Otwieranie pliku z danymi o nazwie fileName

	InitializationTextBox();
	InitializationGroupBox();

	x = 0;
	work = true;

	timer->Start();						// Start timera
}

// Rysowanie szkicu kompasu (bez strzalki)
System::Void Project3WSA::FormWSA::pictureBoxCompass_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	Graphics^ g = e->Graphics;
	Pen^ blackPen = gcnew Pen(Color::Black);

	g->DrawEllipse(blackPen, 0, 0, 130, 130);
	g->DrawLine(blackPen, 65, 0, 65, 130);
	g->DrawLine(blackPen, 0, 65, 130, 65);
}

// Metoda ktora wywoluje sie co 1/25 sekundy (event timer'a)
void Project3WSA::FormWSA::FormWSA_Update(Object^ object, EventArgs^ e)
{
	if (work) {
		PrintPlot();
	}
	else {
		timer->Stop();								// Zatrzymac timer
		MessageBox::Show("Zrobione!", "Wow!");
		DATA.close();								// Zamkniecie pliku z danymi
	}
}
