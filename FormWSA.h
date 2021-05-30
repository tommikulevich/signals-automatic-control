#pragma once

#define _USE_MATH_DEFINES

#include<fstream>
#include<sstream>
#include<cmath>

namespace Project3WSA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for FormWSA
	/// </summary>
	public ref class FormWSA : public System::Windows::Forms::Form
	{
	public:
		FormWSA(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormWSA()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitMenuItem;
	protected:

	protected:



	private: System::Windows::Forms::Label^ labelWest;
	private: System::Windows::Forms::Label^ labelEast;
	private: System::Windows::Forms::Label^ labelSouth;
	private: System::Windows::Forms::Label^ labelNorth;
	private: System::Windows::Forms::Label^ labelDirection;
	private: System::Windows::Forms::Label^ labelSamples;
	private: System::Windows::Forms::TextBox^ textBoxSamples;
	private: System::Windows::Forms::PictureBox^ pictureBoxCompass;
	private: System::Windows::Forms::GroupBox^ groupBoxOY;
	private: System::Windows::Forms::RadioButton^ radioButtonY;
	private: System::Windows::Forms::RadioButton^ radioButtonP;
	private: System::Windows::Forms::RadioButton^ radioButtonR;
	private: System::Windows::Forms::Button^ buttonPrint;
	private: System::Windows::Forms::GroupBox^ groupBoxWykres;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartDATA;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->labelWest = (gcnew System::Windows::Forms::Label());
			this->labelEast = (gcnew System::Windows::Forms::Label());
			this->labelSouth = (gcnew System::Windows::Forms::Label());
			this->labelNorth = (gcnew System::Windows::Forms::Label());
			this->labelDirection = (gcnew System::Windows::Forms::Label());
			this->labelSamples = (gcnew System::Windows::Forms::Label());
			this->textBoxSamples = (gcnew System::Windows::Forms::TextBox());
			this->pictureBoxCompass = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxOY = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonY = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonP = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonR = (gcnew System::Windows::Forms::RadioButton());
			this->buttonPrint = (gcnew System::Windows::Forms::Button());
			this->groupBoxWykres = (gcnew System::Windows::Forms::GroupBox());
			this->chartDATA = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->menuStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCompass))->BeginInit();
			this->groupBoxOY->SuspendLayout();
			this->groupBoxWykres->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDATA))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip
			// 
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->aboutMenuItem, this->exitMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(715, 24);
			this->menuStrip->TabIndex = 0;
			this->menuStrip->Text = L"menuStrip";
			// 
			// aboutMenuItem
			// 
			this->aboutMenuItem->Name = L"aboutMenuItem";
			this->aboutMenuItem->Size = System::Drawing::Size(79, 20);
			this->aboutMenuItem->Text = L"O projekcie";
			this->aboutMenuItem->Click += gcnew System::EventHandler(this, &FormWSA::aboutMenuItem_Click);
			// 
			// exitMenuItem
			// 
			this->exitMenuItem->Name = L"exitMenuItem";
			this->exitMenuItem->Size = System::Drawing::Size(59, 20);
			this->exitMenuItem->Text = L"Wyjście";
			this->exitMenuItem->Click += gcnew System::EventHandler(this, &FormWSA::exitMenuItem_Click);
			// 
			// labelWest
			// 
			this->labelWest->AutoSize = true;
			this->labelWest->BackColor = System::Drawing::SystemColors::Control;
			this->labelWest->Location = System::Drawing::Point(519, 139);
			this->labelWest->Name = L"labelWest";
			this->labelWest->Size = System::Drawing::Size(18, 13);
			this->labelWest->TabIndex = 22;
			this->labelWest->Text = L"W";
			// 
			// labelEast
			// 
			this->labelEast->AutoSize = true;
			this->labelEast->BackColor = System::Drawing::SystemColors::Control;
			this->labelEast->Location = System::Drawing::Point(669, 139);
			this->labelEast->Name = L"labelEast";
			this->labelEast->Size = System::Drawing::Size(14, 13);
			this->labelEast->TabIndex = 21;
			this->labelEast->Text = L"E";
			// 
			// labelSouth
			// 
			this->labelSouth->AutoSize = true;
			this->labelSouth->BackColor = System::Drawing::SystemColors::Control;
			this->labelSouth->Location = System::Drawing::Point(597, 212);
			this->labelSouth->Name = L"labelSouth";
			this->labelSouth->Size = System::Drawing::Size(14, 13);
			this->labelSouth->TabIndex = 20;
			this->labelSouth->Text = L"S";
			// 
			// labelNorth
			// 
			this->labelNorth->AutoSize = true;
			this->labelNorth->BackColor = System::Drawing::SystemColors::Control;
			this->labelNorth->Location = System::Drawing::Point(597, 65);
			this->labelNorth->Name = L"labelNorth";
			this->labelNorth->Size = System::Drawing::Size(15, 13);
			this->labelNorth->TabIndex = 19;
			this->labelNorth->Text = L"N";
			// 
			// labelDirection
			// 
			this->labelDirection->AutoSize = true;
			this->labelDirection->Location = System::Drawing::Point(543, 225);
			this->labelDirection->Name = L"labelDirection";
			this->labelDirection->Size = System::Drawing::Size(125, 13);
			this->labelDirection->TabIndex = 18;
			this->labelDirection->Text = L"Aktualny kierunek robota";
			// 
			// labelSamples
			// 
			this->labelSamples->AutoSize = true;
			this->labelSamples->Location = System::Drawing::Point(138, 365);
			this->labelSamples->Name = L"labelSamples";
			this->labelSamples->Size = System::Drawing::Size(158, 13);
			this->labelSamples->TabIndex = 17;
			this->labelSamples->Text = L"Ile pierwszych probek odrzucic: ";
			// 
			// textBoxSamples
			// 
			this->textBoxSamples->Location = System::Drawing::Point(302, 362);
			this->textBoxSamples->Name = L"textBoxSamples";
			this->textBoxSamples->Size = System::Drawing::Size(39, 20);
			this->textBoxSamples->TabIndex = 16;
			this->textBoxSamples->Text = L"0";
			// 
			// pictureBoxCompass
			// 
			this->pictureBoxCompass->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pictureBoxCompass->Location = System::Drawing::Point(538, 81);
			this->pictureBoxCompass->Name = L"pictureBoxCompass";
			this->pictureBoxCompass->Size = System::Drawing::Size(130, 130);
			this->pictureBoxCompass->TabIndex = 15;
			this->pictureBoxCompass->TabStop = false;
			this->pictureBoxCompass->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormWSA::pictureBoxCompass_Paint);
			// 
			// groupBoxOY
			// 
			this->groupBoxOY->Controls->Add(this->radioButtonY);
			this->groupBoxOY->Controls->Add(this->radioButtonP);
			this->groupBoxOY->Controls->Add(this->radioButtonR);
			this->groupBoxOY->Location = System::Drawing::Point(109, 307);
			this->groupBoxOY->Name = L"groupBoxOY";
			this->groupBoxOY->Size = System::Drawing::Size(284, 49);
			this->groupBoxOY->TabIndex = 13;
			this->groupBoxOY->TabStop = false;
			this->groupBoxOY->Text = L"OY:";
			// 
			// radioButtonY
			// 
			this->radioButtonY->AutoSize = true;
			this->radioButtonY->Location = System::Drawing::Point(232, 19);
			this->radioButtonY->Name = L"radioButtonY";
			this->radioButtonY->Size = System::Drawing::Size(46, 17);
			this->radioButtonY->TabIndex = 2;
			this->radioButtonY->TabStop = true;
			this->radioButtonY->Text = L"Yaw";
			this->radioButtonY->UseVisualStyleBackColor = true;
			// 
			// radioButtonP
			// 
			this->radioButtonP->AutoSize = true;
			this->radioButtonP->Location = System::Drawing::Point(113, 19);
			this->radioButtonP->Name = L"radioButtonP";
			this->radioButtonP->Size = System::Drawing::Size(49, 17);
			this->radioButtonP->TabIndex = 1;
			this->radioButtonP->TabStop = true;
			this->radioButtonP->Text = L"Pitch";
			this->radioButtonP->UseVisualStyleBackColor = true;
			// 
			// radioButtonR
			// 
			this->radioButtonR->AutoSize = true;
			this->radioButtonR->Location = System::Drawing::Point(6, 19);
			this->radioButtonR->Name = L"radioButtonR";
			this->radioButtonR->Size = System::Drawing::Size(43, 17);
			this->radioButtonR->TabIndex = 0;
			this->radioButtonR->TabStop = true;
			this->radioButtonR->Text = L"Roll";
			this->radioButtonR->UseVisualStyleBackColor = true;
			// 
			// buttonPrint
			// 
			this->buttonPrint->Location = System::Drawing::Point(170, 278);
			this->buttonPrint->Name = L"buttonPrint";
			this->buttonPrint->Size = System::Drawing::Size(171, 23);
			this->buttonPrint->TabIndex = 12;
			this->buttonPrint->Text = L"Naszkicowac i pokazac kompas";
			this->buttonPrint->UseVisualStyleBackColor = true;
			this->buttonPrint->Click += gcnew System::EventHandler(this, &FormWSA::buttonPrint_Click);
			// 
			// groupBoxWykres
			// 
			this->groupBoxWykres->Controls->Add(this->chartDATA);
			this->groupBoxWykres->Location = System::Drawing::Point(12, 27);
			this->groupBoxWykres->Name = L"groupBoxWykres";
			this->groupBoxWykres->Size = System::Drawing::Size(470, 245);
			this->groupBoxWykres->TabIndex = 23;
			this->groupBoxWykres->TabStop = false;
			this->groupBoxWykres->Text = L"Wykres";
			// 
			// chartDATA
			// 
			chartArea1->Name = L"ChartArea1";
			this->chartDATA->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chartDATA->Legends->Add(legend1);
			this->chartDATA->Location = System::Drawing::Point(7, 20);
			this->chartDATA->Name = L"chartDATA";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->IsVisibleInLegend = false;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			this->chartDATA->Series->Add(series1);
			this->chartDATA->Size = System::Drawing::Size(457, 219);
			this->chartDATA->TabIndex = 0;
			this->chartDATA->Text = L"Wykres";
			// 
			// FormWSA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(715, 420);
			this->Controls->Add(this->groupBoxWykres);
			this->Controls->Add(this->labelWest);
			this->Controls->Add(this->labelEast);
			this->Controls->Add(this->labelSouth);
			this->Controls->Add(this->labelNorth);
			this->Controls->Add(this->labelDirection);
			this->Controls->Add(this->labelSamples);
			this->Controls->Add(this->textBoxSamples);
			this->Controls->Add(this->pictureBoxCompass);
			this->Controls->Add(this->groupBoxOY);
			this->Controls->Add(this->buttonPrint);
			this->Controls->Add(this->menuStrip);
			this->MainMenuStrip = this->menuStrip;
			this->MaximizeBox = false;
			this->Name = L"FormWSA";
			this->Text = L"Projekt 3 - Wizualizacja Sygnałów Automatyki";
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxCompass))->EndInit();
			this->groupBoxOY->ResumeLayout(false);
			this->groupBoxOY->PerformLayout();
			this->groupBoxWykres->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDATA))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	//private: double x, y, xc, yc;
	//private: int n = 0;
	//private: double column1, column2, column3;
	//private: double compassAngle;

	private: void PrintPlot(double &compassAngle);
	private: void PrintCompass(double compassAngle);

	private: System::Void exitMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void aboutMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonPrint_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void pictureBoxCompass_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
};
}
