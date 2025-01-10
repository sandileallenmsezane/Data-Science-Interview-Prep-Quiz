#pragma once
#include "Questions.h"
#include "Review.h"
#include "ManageGame.h"

namespace QuizProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Game
	/// </summary>
	
	Questions quest;
	ManageGame manage;
	public ref class Game : public System::Windows::Forms::Form
	{

	public:
		int totalQuestions = 8;
		int clickCount = 0;
		int scoreHolder = 0;
		int AnsweredQuestion = 0;
		int navigating = 1;
		bool correctA;
		double grade = 0.0;
		int count;
	private:
		Timer^ timer3;
		TimeSpan countdownTime;

		Timer^ timer4;
		TimeSpan countdownTime2;

		int TimeStopper;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ lblScore;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;
	public: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;


	private: System::Windows::Forms::Label^ lblAnswered;

	public:
		
		Game(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			InitializeTimer();
		}

	private:
		void SwitchToTabPage1() {
			tabPage1->Visible = true;
			tabPage2->Visible = false;
		}

		void SwitchToTabPage2() {
			tabPage1->Visible = false;
			tabPage2->Visible = true;
		}

		void InitializeTimer() {
			timer3 = gcnew Timer();
			timer3->Interval = 1000; // 1 second interval
			timer3->Tick += gcnew EventHandler(this, &Game::Timer_Tick);
			countdownTime = TimeSpan::FromMinutes(4); // Change this to your desired countdown time

			// Initialize timer 2
			timer4 = gcnew Timer();
			timer4->Interval = 1000; // 1 second interval
			timer4->Tick += gcnew EventHandler(this, &Game::Timer4_Tick);
			countdownTime2 = TimeSpan::FromMinutes(2); // Change this to your desired countdown time for timer 2

			TimeStopper = 0;
		}

		void Timer_Tick(Object^ sender, EventArgs^ e) {
			countdownTime = countdownTime.Subtract(TimeSpan(0, 0, 1));

			if (countdownTime <= TimeSpan::Zero) {
				timer3->Stop();
				TimeStopper = 0;
				//Switching to feedback page after time has ended				
				SwitchToTabPage2();

			}

			UpdateTimerLabel();
		}

		void Timer4_Tick(Object^ sender, EventArgs^ e) {
			countdownTime2 = countdownTime2.Subtract(TimeSpan(0, 0, 1));
			if (countdownTime2 <= TimeSpan::Zero) {
				timer4->Stop();
				TimeStopper = 0;
				SwitchToTabPage2(); 
			}
			UpdateTimerLabel2();
		}

		void UpdateTimerLabel() {
			TimeSpan remaining;
			if (TimeStopper == 1)
				remaining = countdownTime;
			else if (TimeStopper == 2)
				remaining = countdownTime2;
			else
				remaining = TimeSpan::Zero;

			label6->Text = countdownTime.ToString("mm\\:ss");
		}
		void UpdateTimerLabel2() {
			TimeSpan remaining;
			if (TimeStopper == 1)
				remaining = countdownTime;
			else if (TimeStopper == 2)
				remaining = countdownTime2;
			else
				remaining = TimeSpan::Zero;
			label6->Text = countdownTime2.ToString("mm\\:ss");
		}

	
		public:
			void StartTimer() {
				timer3->Start();
				TimeStopper = 1;
				UpdateTimerLabel();
			}

			void StartTimer2() {
				timer4->Start();
				TimeStopper = 2;
				UpdateTimerLabel();
			}

			void StopTimer() {
				if (TimeStopper == 1) {
					timer3->Stop();
				}
				else if (TimeStopper == 2) {
					timer4->Stop();
				}
				UpdateTimerLabel();
			}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
private: System::Windows::Forms::Label^ lblCorrectAnswer;

	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->lblCorrectAnswer = (gcnew System::Windows::Forms::Label());
			this->lblScore = (gcnew System::Windows::Forms::Label());
			this->lblAnswered = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(35, 5);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(797, 58);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// radioButton1
			// 
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton1->Location = System::Drawing::Point(5, 89);
			this->radioButton1->Margin = System::Windows::Forms::Padding(2);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(526, 35);
			this->radioButton1->TabIndex = 1;
			this->radioButton1->Tag = L"1";
			this->radioButton1->Text = L"radioButton1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Click += gcnew System::EventHandler(this, &Game::CheckRadioButton);
			// 
			// radioButton2
			// 
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton2->Location = System::Drawing::Point(5, 151);
			this->radioButton2->Margin = System::Windows::Forms::Padding(2);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(526, 35);
			this->radioButton2->TabIndex = 2;
			this->radioButton2->Tag = L"2";
			this->radioButton2->Text = L"radioButton2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Click += gcnew System::EventHandler(this, &Game::CheckRadioButton);
			// 
			// radioButton3
			// 
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton3->Location = System::Drawing::Point(5, 206);
			this->radioButton3->Margin = System::Windows::Forms::Padding(2);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(529, 37);
			this->radioButton3->TabIndex = 3;
			this->radioButton3->Tag = L"3";
			this->radioButton3->Text = L"radioButton3";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Click += gcnew System::EventHandler(this, &Game::CheckRadioButton);
			// 
			// radioButton4
			// 
			this->radioButton4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioButton4->Location = System::Drawing::Point(5, 266);
			this->radioButton4->Margin = System::Windows::Forms::Padding(2);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(529, 41);
			this->radioButton4->TabIndex = 4;
			this->radioButton4->Tag = L"4";
			this->radioButton4->Text = L"radioButton4";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Click += gcnew System::EventHandler(this, &Game::CheckRadioButton);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(4, 449);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 32);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Previous";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Game::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(988, 449);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 32);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Next";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Game::Next);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1104, 14);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(62, 55);
			this->button3->TabIndex = 7;
			this->button3->Text = L">";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Game::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(10, 12);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(62, 55);
			this->button4->TabIndex = 8;
			this->button4->Text = L"1";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(83, 12);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(62, 55);
			this->button5->TabIndex = 9;
			this->button5->Text = L"2";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(158, 12);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(62, 55);
			this->button6->TabIndex = 10;
			this->button6->Text = L"3";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(233, 12);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(62, 55);
			this->button7->TabIndex = 11;
			this->button7->Text = L"4";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(10, 72);
			this->button8->Margin = System::Windows::Forms::Padding(2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(62, 55);
			this->button8->TabIndex = 12;
			this->button8->Text = L"5";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(83, 72);
			this->button9->Margin = System::Windows::Forms::Padding(2);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(62, 55);
			this->button9->TabIndex = 13;
			this->button9->Text = L"6";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(158, 72);
			this->button10->Margin = System::Windows::Forms::Padding(2);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(62, 55);
			this->button10->TabIndex = 14;
			this->button10->Text = L"7";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(233, 72);
			this->button11->Margin = System::Windows::Forms::Padding(2);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(62, 55);
			this->button11->TabIndex = 15;
			this->button11->Text = L"8";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// lblCorrectAnswer
			// 
			this->lblCorrectAnswer->AutoSize = true;
			this->lblCorrectAnswer->Location = System::Drawing::Point(4, 509);
			this->lblCorrectAnswer->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblCorrectAnswer->Name = L"lblCorrectAnswer";
			this->lblCorrectAnswer->Size = System::Drawing::Size(35, 13);
			this->lblCorrectAnswer->TabIndex = 16;
			this->lblCorrectAnswer->Text = L"label2";
			this->lblCorrectAnswer->Visible = false;
			// 
			// lblScore
			// 
			this->lblScore->AutoSize = true;
			this->lblScore->Location = System::Drawing::Point(5, 523);
			this->lblScore->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblScore->Name = L"lblScore";
			this->lblScore->Size = System::Drawing::Size(35, 13);
			this->lblScore->TabIndex = 17;
			this->lblScore->Text = L"label3";
			this->lblScore->Visible = false;
			// 
			// lblAnswered
			// 
			this->lblAnswered->AutoSize = true;
			this->lblAnswered->Location = System::Drawing::Point(5, 496);
			this->lblAnswered->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblAnswered->Name = L"lblAnswered";
			this->lblAnswered->Size = System::Drawing::Size(35, 13);
			this->lblAnswered->TabIndex = 18;
			this->lblAnswered->Text = L"label4";
			this->lblAnswered->Visible = false;
			// 
			// label5
			// 
			this->label5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label5->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 3);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(113, 63);
			this->label5->TabIndex = 19;
			this->label5->Text = L"label5";
			// 
			// timer1
			// 
			this->timer1->Interval = 1;
			this->timer1->Tick += gcnew System::EventHandler(this, &Game::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1;
			this->timer2->Tick += gcnew System::EventHandler(this, &Game::timer2_Tick);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(75, 140);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"label6";
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(2, 2);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1098, 572);
			this->tabControl1->TabIndex = 22;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->tabPage1->Controls->Add(this->panel3);
			this->tabPage1->Controls->Add(this->panel2);
			this->tabPage1->Controls->Add(this->lblScore);
			this->tabPage1->Controls->Add(this->lblAnswered);
			this->tabPage1->Controls->Add(this->lblCorrectAnswer);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(1090, 546);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"CodeQuest";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label5);
			this->panel3->Location = System::Drawing::Point(4, 63);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(118, 81);
			this->panel3->TabIndex = 21;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Silver;
			this->panel2->Controls->Add(this->radioButton1);
			this->panel2->Controls->Add(this->radioButton2);
			this->panel2->Controls->Add(this->radioButton3);
			this->panel2->Controls->Add(this->radioButton4);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel2->Location = System::Drawing::Point(126, 66);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(864, 382);
			this->panel2->TabIndex = 20;
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Silver;
			this->tabPage2->Controls->Add(this->button12);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->richTextBox2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Margin = System::Windows::Forms::Padding(2);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(2);
			this->tabPage2->Size = System::Drawing::Size(1090, 546);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Feedback";
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::Color::White;
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button12->Location = System::Drawing::Point(465, 5);
			this->button12->Margin = System::Windows::Forms::Padding(2);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(98, 28);
			this->button12->TabIndex = 22;
			this->button12->Text = L"Review";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &Game::button12_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(61, 33);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 19);
			this->label2->TabIndex = 1;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Lucida Sans Unicode", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(20, 46);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(2);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(545, 477);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = L"";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->button11);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button10);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button9);
			this->panel1->Location = System::Drawing::Point(1242, 2);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(297, 321);
			this->panel1->TabIndex = 23;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 140);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Time Left :";
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1177, 627);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->button3);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(1193, 666);
			this->Name = L"Game";
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	//Assign questions when loading
private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) {
	label5->Text = "Question1";
		quest.AssignQuestion(label1,radioButton1,radioButton2,radioButton3,radioButton4,lblCorrectAnswer);
}

//Previous question
private: System::Void Previous(System::Object^ sender, System::EventArgs^ e) {
	quest.PreviousQuestion(label1, radioButton1, radioButton2, radioButton3, radioButton4, lblCorrectAnswer);
}

// question button eventHandler
private: System::Void Next(System::Object^ sender, System::EventArgs^ e) {
	quest.AssignQuestion(richTextBox2);
	quest.NextQuestion(label1, radioButton1, radioButton2, radioButton3, radioButton4, lblCorrectAnswer);
	button2->Visible = true;
	clickCount++;
	navigating++;
	
	
	label5->Text = "Question" + navigating.ToString();

	// Check if the click count is 8
	if (navigating == 8) {
		// Disable the button
		button2->Enabled = false;
	}
}

//Button to navigate backward
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	quest.PreviousQuestion(label1, radioButton1, radioButton2, radioButton3, radioButton4, lblScore);
	
	if (navigating >=1 && !navigating<1) {
		navigating--;
		label5->Text = "Question"+navigating.ToString();
	}

	if (navigating == 1) {
		label5->Text = "1";
	}

	if (navigating <8) {
		// Disable the button
		button2->Enabled = true;
	}
	
}

////Check if the radioButton is checked
private: System::Void CheckRadioButton(System::Object^ sender, System::EventArgs^ e) {

	// Cast the sender to a RadioButton to access its properties
	 RadioButton^ radio_Button = dynamic_cast<RadioButton^>(sender);

	 // Assuming radioButton1->Tag is of type Object^
	 int tag = Convert::ToInt32(radio_Button->Tag);

	
	 correctA = quest.checkAnswer(radio_Button->Text);
	
	 if (correctA) {
		scoreHolder++;
		 
	 }
	 else if(scoreHolder>0 && !correctA ){
		
		 scoreHolder == scoreHolder;
	 }

		 lblScore->Text = scoreHolder.ToString();

	 //Keeping track of answered questions 
		 manage.ProgressControl(button4, button5, button6, button7, button8, button9, button10, button11, navigating);

	}

	   
//Animination
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (button3->Text==">") 
	{
		timer1->Start();
		button3->Text = "<";
	}
	else 
	{
		timer2->Start();
		button3->Text = ">";
	}
}

//Animinate
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	
	if (count<2) {
		Form::Width += 210;
		count++;
	}
	else {
		timer1->Stop();
	}
}

private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (count >0) {
		Form::Width -= 210;
		count--;
	}
	else {
		timer2->Stop();
	}
}
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) {
	//Terminate Time remaining
	StopTimer();
	// Calculate the grade as a percentage
	double gradePercentage = (double)scoreHolder / totalQuestions * 100;

	// Convert the grade to a string
	String^ gradeString = gcnew String(gradePercentage.ToString());

	// Display the grade in a label or any other UI element
	label6->Text = gradeString;

	grade = (scoreHolder / 8) * 100;


	String^ status;
	if (gradePercentage < 50.0) {
		status = gcnew System::String("F");
	}
	else if (gradePercentage >= 50.0 && gradePercentage < 60.0 ) {
		status = gcnew System::String("D");
	}
	else if (gradePercentage >= 60.0 && gradePercentage < 80.0) {
		status = gcnew System::String("B");
	}
	else {
		status = gcnew System::String("A");
	}

	lblScore->Text = scoreHolder.ToString();
	//lblAttemptedQ->Text = AnsweredQuestion.ToString();
	//lblGrade->Text = gradePercentage.ToString();
	

	String^ lbl = gcnew System::String(scoreHolder.ToString());
	String^ lbl4 = gcnew System::String(AnsweredQuestion.ToString());
	String^ Grade = gcnew System::String(gradePercentage.ToString());
	Review^ rv = gcnew Review(lbl, Grade, status, this);

	this->Hide();
	rv->ShowDialog();
}
//For each radioButton

};
}
