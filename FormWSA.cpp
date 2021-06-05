#include "FormWSA.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project3WSA::FormWSA form;
	Application::Run(% form);
}


Project3WSA::FormWSA::FormWSA(void) 
{
	InitializeComponent();
}

void Project3WSA::FormWSA::PrintPlot()
{
	int n;
	double x = 0, y1, y2, y3;
	double column1, column2, column3;
	double compassAngle;

	std::fstream DATA;
	std::string fileName;
	std::string line;

	Series^ plot1 = chartDATA->Series[0];
	Series^ plot2 = chartDATA->Series[1];
	Series^ plot3 = chartDATA->Series[2];

	plot1->Points->Clear();
	plot2->Points->Clear();
	plot3->Points->Clear();

	switch (comboBoxFiles->SelectedIndex)
	{
	case 0 :
		fileName = "outputCatapult01.log";
		break;
	case 1 :
		fileName = "outputRotateB01.log";
		break;
	case 2 :
		fileName = "outputPendulumOrt02.log";
		break;
	}

	DATA.open(fileName, std::ios::in);

	if (textBoxSamples->Text != "") {
		n = Convert::ToInt32(textBoxSamples->Text);
		DATA.seekg(11 * n * sizeof(double), std::ios::beg);
	}
	else {
		MessageBox::Show("Bledne dane! Nie udalo sie usunac prob!", "Blad", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		textBoxSamples->Text = "0";
	}

	while (std::getline(DATA, line)) {
		std::istringstream iss(line);
		
		iss >> column1 >> column2 >> column3;

		chartDATA->Refresh();

		x += 0.04;
		y1 = column1;
		y2 = column2;
		y3 = column3;

		if (radioButtonR->Checked == true)
			plot1->Points->AddXY(x, y1);
		else if (radioButtonP->Checked == true) 
			plot2->Points->AddXY(x, y2);
		else if (radioButtonY->Checked == true)
			plot3->Points->AddXY(x, y3);
		else {
			plot1->Points->AddXY(x, y1);
			plot2->Points->AddXY(x, y2);
			plot3->Points->AddXY(x, y3);
		}

		compassAngle = column3 * (M_PI / 180);

		PrintCompass(compassAngle);
		System::Threading::Thread::Sleep(40);
	}

	DATA.close();
}

void Project3WSA::FormWSA::PrintCompass(double compassAngle)
{
	double xc, yc;

	Pen^ redPen = gcnew Pen(Color::Red, 2.0F);
	Graphics^ needle = this->pictureBoxCompass->CreateGraphics();

	pictureBoxCompass->Refresh();

	xc = 65 + 65 * sin(compassAngle);
	yc = 65 - 65 * cos(compassAngle);
	
	needle->DrawLine(redPen, 65, 65, xc, yc);
}


System::Void Project3WSA::FormWSA::exitMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}

System::Void Project3WSA::FormWSA::aboutMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("Autorzy:\n1. Tomash Mikulevich, 187720, ACiR3\n2. Igor Malkovskiy, 187717, ACiR3\n", "O projekcie:");

	return System::Void();
}

System::Void Project3WSA::FormWSA::buttonPrint_Click(System::Object^ sender, System::EventArgs^ e)
{
	PrintPlot();

	return System::Void();
}

System::Void Project3WSA::FormWSA::pictureBoxCompass_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	Graphics^ g = e->Graphics;
	Pen^ blackPen = gcnew Pen(Color::Black);

	g->DrawEllipse(blackPen, 0, 0, 130, 130);
	g->DrawLine(blackPen, 65, 0, 65, 130);
	g->DrawLine(blackPen, 0, 65, 130, 65);

	return System::Void();
}
