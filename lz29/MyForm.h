#pragma once

namespace lz29 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(538, 345);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(186, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Отриманий разультат: ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"MingLiU-ExtB", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->Location = System::Drawing::Point(361, 484);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(774, 213);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Обрахувати";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(417, 243);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(558, 26);
			this->textBox1->TabIndex = 2;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(47, -36);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1407, 202);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1528, 828);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// 1. Зчитуємо текст із TextBox (припустимо, він називається textBox1)
		// і відразу переводимо в нижній регістр для надійності
		String^ word = textBox1->Text->ToLower();

		// 2. Перевіряємо, чи введено достатньо довге слово (щоб уникнути помилок індексації)
		if (word == "supermarket") {

			// Індекси літер у слові:
			// s(0) u(1) p(2) e(3) r(4) m(5) a(6) r(7) k(8) e(9) t(10)

			// Створюємо дійсні слова шляхом вирізання:

			// Слово 1: super (з 0-го індексу, 5 літер)
			String^ word1 = word->Substring(0, 5);

			// Слово 2: market (з 5-го індексу, 6 літер)
			String^ word2 = word->Substring(5, 6);

			// Слово 3: mark (з 5-го індексу, 4 літери)
			String^ word3 = word->Substring(5, 4);

			// Слово 4: park (літера 'p' + частина 'ark')
			String^ word4 = word->Substring(2, 1) + word->Substring(6, 3);

			// Слово 5: smart (літера 's' + частина 'mart')
			String^ word5 = word->Substring(0, 1) + word->Substring(5, 4);

			// 3. Виводимо результат у Label (припустимо, він називається label1)
			// \n - це символ перенесення на новий рядок, щоб слова йшли стовпчиком
			label1->Text = "Отриманий результат:\n" +
				word1 + "\n" +
				word2 + "\n" +
				word3 + "\n" +
				word4 + "\n" +
				word5;
		}
		else {
			// Якщо ввели щось інше
			label1->Text = "Будь ласка, введіть слово 'supermarket'.";
		}
	}
};
}
