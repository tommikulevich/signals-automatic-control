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

std::fstream DATA;
std::string fileName;

Project3WSA::FormWSA::FormWSA(void) 
{
	InitializeComponent();
}

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

void Project3WSA::FormWSA::InitializationTextBox()
{
	if (textBoxSamples->Text != "") {
		n = Convert::ToInt32(textBoxSamples->Text);
		DATA.seekg(11 * n * sizeof(double), std::ios::beg);
	}
	else {
		MessageBox::Show("Bledne dane! Nie udalo sie usunac prob!", "Blad", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		textBoxSamples->Text = "0";
	}
}

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

void Project3WSA::FormWSA::PrintPlot()
{
	double num[12];
	
	for (int i = 0; i < 12; i++) 
		if ( !(DATA >> num[i]) )
			work = false;
	
	if (work) {
		chartDATA->Refresh();

		x += 0.04;
		y1 = num[0];
		y2 = num[1];
		y3 = num[2];

		switch (plotNum)
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

		compassAngle = num[2] * (M_PI / 180);

		PrintCompass();
	}
}

void Project3WSA::FormWSA::PrintCompass()
{
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
}

System::Void Project3WSA::FormWSA::buttonPrint_Click(System::Object^ sender, System::EventArgs^ e)
{
	plot1 = chartDATA->Series[0];
	plot2 = chartDATA->Series[1];
	plot3 = chartDATA->Series[2];

	plot1->Points->Clear();
	plot2->Points->Clear();
	plot3->Points->Clear();

	InitializationComboBox();

	DATA.open(fileName, std::ios::in);

	InitializationTextBox();
	InitializationGroupBox();

	x = 0;
	work = true;

	timer->Start();
}

System::Void Project3WSA::FormWSA::pictureBoxCompass_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	Graphics^ g = e->Graphics;
	Pen^ blackPen = gcnew Pen(Color::Black);

	g->DrawEllipse(blackPen, 0, 0, 130, 130);
	g->DrawLine(blackPen, 65, 0, 65, 130);
	g->DrawLine(blackPen, 0, 65, 130, 65);
}

void Project3WSA::FormWSA::FormWSA_Update(Object^ object, EventArgs^ e)
{
	if (work) {
		PrintPlot();
	}
	else {
		timer->Stop();
		MessageBox::Show("Zrobione!", "Wow!");
		DATA.close();
	}
}
