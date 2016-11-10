#pragma once
extern "C" {
	#include "main.h"
}

#include <msclr/marshal_cppstd.h>

namespace App_Grain {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	

	/// <summary>
	/// Summary for UI
	/// </summary>
	public ref class UI : public System::Windows::Forms::Form
	{
	public:UI(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
		fileDialog->Filter = "BMP Files (*.bmp)|*.bmp";
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOpenFile;
	private: System::Windows::Forms::OpenFileDialog^  fileDialog;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::Button^  btnEncrypt;
	private: System::Windows::Forms::Button^  btnDecrypt;
	private: System::Windows::Forms::TextBox^  txtPath;


	protected:

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
			this->btnOpenFile = (gcnew System::Windows::Forms::Button());
			this->fileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->btnEncrypt = (gcnew System::Windows::Forms::Button());
			this->btnDecrypt = (gcnew System::Windows::Forms::Button());
			this->txtPath = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// btnOpenFile
			// 
			this->btnOpenFile->Location = System::Drawing::Point(13, 13);
			this->btnOpenFile->Name = L"btnOpenFile";
			this->btnOpenFile->Size = System::Drawing::Size(75, 23);
			this->btnOpenFile->TabIndex = 0;
			this->btnOpenFile->Text = L"File";
			this->btnOpenFile->UseVisualStyleBackColor = true;
			this->btnOpenFile->Click += gcnew System::EventHandler(this, &UI::btnOpenFile_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox->Location = System::Drawing::Point(13, 70);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(1056, 510);
			this->pictureBox->TabIndex = 1;
			this->pictureBox->TabStop = false;
			// 
			// btnEncrypt
			// 
			this->btnEncrypt->Location = System::Drawing::Point(94, 13);
			this->btnEncrypt->Name = L"btnEncrypt";
			this->btnEncrypt->Size = System::Drawing::Size(75, 23);
			this->btnEncrypt->TabIndex = 2;
			this->btnEncrypt->Text = L"Encrypt";
			this->btnEncrypt->UseVisualStyleBackColor = true;
			this->btnEncrypt->Click += gcnew System::EventHandler(this, &UI::btnEncrypt_Click);
			// 
			// btnDecrypt
			// 
			this->btnDecrypt->Location = System::Drawing::Point(175, 13);
			this->btnDecrypt->Name = L"btnDecrypt";
			this->btnDecrypt->Size = System::Drawing::Size(75, 23);
			this->btnDecrypt->TabIndex = 3;
			this->btnDecrypt->Text = L"Decrypt";
			this->btnDecrypt->UseVisualStyleBackColor = true;
			this->btnDecrypt->Click += gcnew System::EventHandler(this, &UI::btnDecrypt_Click);
			// 
			// txtPath
			// 
			this->txtPath->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->txtPath->Location = System::Drawing::Point(13, 44);
			this->txtPath->Name = L"txtPath";
			this->txtPath->Size = System::Drawing::Size(481, 20);
			this->txtPath->TabIndex = 4;
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1081, 592);
			this->Controls->Add(this->txtPath);
			this->Controls->Add(this->btnDecrypt);
			this->Controls->Add(this->btnEncrypt);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->btnOpenFile);
			this->Name = L"UI";
			this->Text = L"UI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void btnOpenFile_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Image^ img = Image::FromFile(fileDialog->FileName);

			pictureBox->Image = img;

		}
	}

	private: System::Void btnEncrypt_Click(System::Object^  sender, System::EventArgs^  e)
	{
		bmpInfoHeader header;
		char *body = NULL;
		String^ dirRaw = txtPath->Text;
		IntPtr tmpHandle = Marshal::StringToHGlobalAnsi(dirRaw);
		char *dir = static_cast<char*>(tmpHandle.ToPointer());
		/*char* dir = "C:\\Users\\a0717016\\Desktop\\test.bmp";*/
		//char* dir = txtPath->Text;
		abrir_imagen(dir, &header, &body);

		encriptar_imagen(dir, body, header);
	}

	private: System::Void btnDecrypt_Click(System::Object^  sender, System::EventArgs^  e) 	
	{
		bmpInfoHeader header;
		char *body = NULL;
		String^ dirRaw = txtPath->Text;
		IntPtr tmpHandle = Marshal::StringToHGlobalAnsi(dirRaw);
		char *dir = static_cast<char*>(tmpHandle.ToPointer());
		/*char* dir = "C:\\Users\\a0717016\\Desktop\\test.bmp";*/
		//char* dir = txtPath->Text;
		abrir_imagen(dir, &header, &body);

		desencriptar_imagen(dir, body, header);
	}
};
}
