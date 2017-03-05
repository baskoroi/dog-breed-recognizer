#pragma once

#include "Globals.h"
#include <msclr/marshal_cppstd.h>

namespace DogBreedRecognizerGroup6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RecognizerForm
	/// </summary>
	public ref class RecognizerForm : public System::Windows::Forms::Form
	{
	private:
		int highestPercentageReached;

		// fields for the neural network
		array<fann_type, 2> ^input_map;

	public:
		RecognizerForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			highestPercentageReached = 0;
			InitializeBackgroundWorker();

			input_map = gcnew array<fann_type, 2>(7, 7);
		}

	private:
		void InitializeBackgroundWorker() {
			this->recognizerBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &RecognizerForm::recognizerBackgroundWorker_DoWork);
			this->recognizerBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &RecognizerForm::recognizerBackgroundWorker_ProgressChanged);
			this->recognizerBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &RecognizerForm::recognizerBackgroundWorker_RunWorkerCompleted);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RecognizerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblName;
	private: System::Windows::Forms::Label^  lblWeight;
	private: System::Windows::Forms::Label^  lblHeight;
	private: System::Windows::Forms::Label^  lblTitle;
	private: System::Windows::Forms::ProgressBar^  progRecognizing;
	protected: 

	protected: 




	private: System::Windows::Forms::PictureBox^  picPaw;
	private: System::Windows::Forms::PictureBox^  picPreview;


	private: System::Windows::Forms::TextBox^  txtHeight;

	private: System::Windows::Forms::TextBox^  txtWeight;

	private: System::Windows::Forms::TextBox^  txtName;
	private: System::Windows::Forms::Button^  btnUpload;
	private: System::Windows::Forms::Button^  btnRecognize;
	private: System::ComponentModel::BackgroundWorker^  recognizerBackgroundWorker;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(RecognizerForm::typeid));
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lblWeight = (gcnew System::Windows::Forms::Label());
			this->lblHeight = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->progRecognizing = (gcnew System::Windows::Forms::ProgressBar());
			this->picPaw = (gcnew System::Windows::Forms::PictureBox());
			this->picPreview = (gcnew System::Windows::Forms::PictureBox());
			this->txtHeight = (gcnew System::Windows::Forms::TextBox());
			this->txtWeight = (gcnew System::Windows::Forms::TextBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->btnUpload = (gcnew System::Windows::Forms::Button());
			this->btnRecognize = (gcnew System::Windows::Forms::Button());
			this->recognizerBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picPaw))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picPreview))->BeginInit();
			this->SuspendLayout();
			// 
			// lblName
			// 
			this->lblName->AutoSize = true;
			this->lblName->Location = System::Drawing::Point(206, 70);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(35, 13);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"Name";
			// 
			// lblWeight
			// 
			this->lblWeight->AutoSize = true;
			this->lblWeight->Location = System::Drawing::Point(206, 104);
			this->lblWeight->Name = L"lblWeight";
			this->lblWeight->Size = System::Drawing::Size(41, 13);
			this->lblWeight->TabIndex = 1;
			this->lblWeight->Text = L"Weight";
			// 
			// lblHeight
			// 
			this->lblHeight->AutoSize = true;
			this->lblHeight->Location = System::Drawing::Point(206, 141);
			this->lblHeight->Name = L"lblHeight";
			this->lblHeight->Size = System::Drawing::Size(38, 13);
			this->lblHeight->TabIndex = 2;
			this->lblHeight->Text = L"Height";
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(253, 24);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(157, 24);
			this->lblTitle->TabIndex = 3;
			this->lblTitle->Text = L"Recognize Breed";
			// 
			// progRecognizing
			// 
			this->progRecognizing->Location = System::Drawing::Point(31, 184);
			this->progRecognizing->Name = L"progRecognizing";
			this->progRecognizing->Size = System::Drawing::Size(140, 23);
			this->progRecognizing->TabIndex = 4;
			// 
			// picPaw
			// 
			this->picPaw->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picPaw.Image")));
			this->picPaw->Location = System::Drawing::Point(193, 9);
			this->picPaw->Name = L"picPaw";
			this->picPaw->Size = System::Drawing::Size(54, 58);
			this->picPaw->TabIndex = 5;
			this->picPaw->TabStop = false;
			// 
			// picPreview
			// 
			this->picPreview->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picPreview->Location = System::Drawing::Point(31, 24);
			this->picPreview->Name = L"picPreview";
			this->picPreview->Size = System::Drawing::Size(140, 140);
			this->picPreview->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picPreview->TabIndex = 6;
			this->picPreview->TabStop = false;
			// 
			// txtHeight
			// 
			this->txtHeight->Enabled = false;
			this->txtHeight->Location = System::Drawing::Point(278, 139);
			this->txtHeight->Name = L"txtHeight";
			this->txtHeight->Size = System::Drawing::Size(100, 20);
			this->txtHeight->TabIndex = 7;
			// 
			// txtWeight
			// 
			this->txtWeight->Enabled = false;
			this->txtWeight->Location = System::Drawing::Point(278, 104);
			this->txtWeight->Name = L"txtWeight";
			this->txtWeight->Size = System::Drawing::Size(100, 20);
			this->txtWeight->TabIndex = 8;
			// 
			// txtName
			// 
			this->txtName->Enabled = false;
			this->txtName->Location = System::Drawing::Point(278, 70);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(100, 20);
			this->txtName->TabIndex = 9;
			// 
			// btnUpload
			// 
			this->btnUpload->Location = System::Drawing::Point(209, 184);
			this->btnUpload->Name = L"btnUpload";
			this->btnUpload->Size = System::Drawing::Size(88, 23);
			this->btnUpload->TabIndex = 10;
			this->btnUpload->Text = L"Upload Picture";
			this->btnUpload->UseVisualStyleBackColor = true;
			this->btnUpload->Click += gcnew System::EventHandler(this, &RecognizerForm::btnUpload_Click);
			// 
			// btnRecognize
			// 
			this->btnRecognize->Enabled = false;
			this->btnRecognize->Location = System::Drawing::Point(303, 184);
			this->btnRecognize->Name = L"btnRecognize";
			this->btnRecognize->Size = System::Drawing::Size(85, 23);
			this->btnRecognize->TabIndex = 11;
			this->btnRecognize->Text = L"Recognize";
			this->btnRecognize->UseVisualStyleBackColor = true;
			this->btnRecognize->Click += gcnew System::EventHandler(this, &RecognizerForm::btnRecognize_Click);
			// 
			// recognizerBackgroundWorker
			// 
			this->recognizerBackgroundWorker->WorkerReportsProgress = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"JPG image (*.jpg)|*.jpg|JPEG image (*.jpeg)|*.jpeg|PNG image (*.png)|*.png";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &RecognizerForm::openFileDialog1_FileOk);
			// 
			// RecognizerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 224);
			this->Controls->Add(this->btnRecognize);
			this->Controls->Add(this->btnUpload);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->txtWeight);
			this->Controls->Add(this->txtHeight);
			this->Controls->Add(this->picPreview);
			this->Controls->Add(this->picPaw);
			this->Controls->Add(this->progRecognizing);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->lblHeight);
			this->Controls->Add(this->lblWeight);
			this->Controls->Add(this->lblName);
			this->Name = L"RecognizerForm";
			this->Text = L"RecognizeForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picPaw))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picPreview))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnUpload_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				 // initialize picture and other necessary components
				 initializeData(openFileDialog1->FileName);

				 // reset percentage of progress bar
				 highestPercentageReached = 0;

				 // clone image for preprocessing
				 Bitmap^ tempImage = (Bitmap^)this->picPreview->Image->Clone();

				 // preprocess the image (by using trainingBackgroundWorker / async process)
				 recognizerBackgroundWorker->RunWorkerAsync(tempImage);
			 }
		 }

private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }

private: System::Void initializeData(System::String^ filename) {
			 // set image in picPreview (PictureBox)
			 this->picPreview->Image = gcnew Bitmap(filename);

			 // set weight and height of dog image
			 System::Int32^ weight = this->picPreview->Image->Width / 4;
			 System::Int32^ height = this->picPreview->Image->Height / 4;

			 System::String^ weightStr = weight->ToString();
			 System::String^ heightStr = height->ToString();

			 this->txtWeight->Text = weightStr;
			 this->txtHeight->Text = heightStr;
		 }

private: System::Void recognizerBackgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 // initialize BackgroundWorker for image preprocessing
			 BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
			 
			 // preprocess the image
			 e->Result = preprocessImage(safe_cast<Bitmap^>(e->Argument), worker, e);
		 }

/**
 * Preprocess the dog's image before recognizing it by the ANN's weights
 */
private: Bitmap^ preprocessImage(Bitmap^ image, BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) {
			 Bitmap^ result = (Bitmap^)image->Clone();

			 // grayscale
			 result = grayscale(result, worker, e);

			 // thresholding / image binarization
			 result = threshold(result, worker, e);

			 // remove noise from image
			 result = removeNoise(result, worker, e);

			 // resize / scale image
			 result = resizeImage(result, 7, 7, worker, e);

			 return result;
		 }

/**
 * Convert the image into grayscale
 */
private: Bitmap^ grayscale(Bitmap^ image, BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) {
			 Bitmap^ test = (Bitmap^)image->Clone();

			 int pixelCount = 0;
			 int totalSize = test->Width * test->Height;

			 // changed through progress of preprocessing the image
			 int percentComplete = highestPercentageReached; 

			 // constant - remains unchanged, to determine starting point of progress bar
			 int previousHighestPercentage = highestPercentageReached;

			 for (int x = 0; x < test->Width; x++) {
				 for (int y = 0; y < test->Height; y++) {
					 // convert color of each pixel into grayscale
					 Color color = test->GetPixel(x, y);
					 int mean = (color.R + color.G + color.B) / 3;
					 test->SetPixel(x, y, Color::FromArgb(mean, mean, mean));

					 // add pixelCount and report progress
					 pixelCount++;
					 percentComplete = previousHighestPercentage + (int)((float)pixelCount / (float)totalSize * 25);
					 if (percentComplete > highestPercentageReached) {
						 highestPercentageReached = percentComplete;
						 worker->ReportProgress(percentComplete);
					 }
				 }
			 }

			 return test;
		 }

private: Bitmap^ threshold(Bitmap^ image, BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) {
			 Bitmap^ test = (Bitmap^)image->Clone();

			 int pixelCount = 0;
			 int totalSize = test->Width * test->Height;
			 
			 // changes through progress of preprocessing the image
			 int percentComplete = highestPercentageReached; 

			 // constant - remains unchanged, to determine starting point of progress bar
			 int previousHighestPercentage = highestPercentageReached;

			 for (int x = 0; x < test->Width; x++) {
				 for (int y = 0; y < test->Height; y++) {
					 // convert color of each pixel into black or white	
					 Color color = test->GetPixel(x, y);
					 int alpha = color.R;
					 int newColor = (alpha < 128) ? 0 : 255;
					 test->SetPixel(x, y, Color::FromArgb(newColor, newColor, newColor));

					 // add pixelCount and report progress
					 pixelCount++;
					 percentComplete = previousHighestPercentage + (int)((float)pixelCount / (float)totalSize * 25);
					 if (percentComplete > highestPercentageReached) {
						 highestPercentageReached = percentComplete;
						 worker->ReportProgress(percentComplete);
					 }
				 }
			 }

			 return test;
		 }

private: Bitmap^ removeNoise(Bitmap^ image, BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) {
			 Bitmap^ test = (Bitmap^)image->Clone();
			 int left, right, top, bottom;
			 
			 // to determine if (left/right/top/bottom)most coordinate has been found
			 bool flag = false;
			 
			 // changes through progress of preprocessing the image
			 int percentComplete = highestPercentageReached; 

			 // find leftmost coordinate of object in image
			 for (int x = 0; x < test->Width; x++) {
				 for (int y = 0; y < test->Height; y++) {
					 Color color = test->GetPixel(x, y);
					 int alpha = color.R;

					 if (alpha == 0) {
						 left = x;
						 flag = true;
						 break;
					 }
				 }

				 if (flag) break;
			 }

			 // update progress bar
			 percentComplete = highestPercentageReached + 5;
			 highestPercentageReached = percentComplete;
			 worker->ReportProgress(percentComplete);

			 // find rightmost coordinate of object in image
			 flag = false; // reset flag
			 for (int x = test->Width - 1; x >= 0; x--) {
				 for (int y = 0; y < test->Height; y++) {
					 Color color = test->GetPixel(x, y);
					 int alpha = color.R;

					 if (alpha == 0) {
						 right = x;
						 flag = true;
						 break;
					 }
				 }

				 if (flag) break;
			 }

			 // update progress bar
			 percentComplete = highestPercentageReached + 5;
			 highestPercentageReached = percentComplete;
			 worker->ReportProgress(percentComplete);

			 // find topmost coordinate of object in image
			 flag = false; // reset flag
			 for (int y = 0; y < test->Height; y++) {
				 for (int x = 0; x < test->Width; x++) {
					 Color color = test->GetPixel(x, y);
					 int alpha = color.R;

					 if (alpha == 0) {
						 top = y;
						 flag = true;
						 break;
					 }
				 }

				 if (flag) break;
			 }

			 // update progress bar
			 percentComplete = highestPercentageReached + 5;
			 highestPercentageReached = percentComplete;
			 worker->ReportProgress(percentComplete);

			 // find bottommost coordinate of object in image
			 flag = false;
			 for (int y = test->Height - 1; y >= 0; y--) {
				 for (int x = 0; x < test->Width; x++) {
					 Color color = test->GetPixel(x, y);
					 int alpha = color.R;

					 if (alpha == 0) {
						 bottom = y;
						 flag = true;
						 break;
					 }
				 }

				 if (flag) break;
			 }

			 // update progress bar
			 percentComplete = highestPercentageReached + 5;
			 highestPercentageReached = percentComplete;
			 worker->ReportProgress(percentComplete);

			 // create noiseless image
			 Bitmap^ noiselessImg = gcnew Bitmap(right - left, bottom - top);

			 for (int x = left; x < right; x++) {
				 for (int y = top; y < bottom; y++) {
					 Color color;
					 color = test->GetPixel(x, y);
					 noiselessImg->SetPixel(x - left, y - top, color);
				 }
			 }

			 // update progress bar
			 percentComplete = highestPercentageReached + 5;
			 highestPercentageReached = percentComplete;
			 worker->ReportProgress(percentComplete);

			 return noiselessImg;
		 }

private: Bitmap^ resizeImage(Bitmap^ image, int width, int height, BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) {
			 // resize the image
			 Bitmap^ test = gcnew Bitmap(width, height);
			 Graphics^ graphics = Graphics::FromImage(test);
			 graphics->DrawImage(image, 0, 0, width, height);

			 // update progress bar
			 int percentComplete = highestPercentageReached + 25;
			 highestPercentageReached = percentComplete;
			 worker->ReportProgress(percentComplete);

			 // return the resized image
			 return test;
		 }

private: System::Void recognizerBackgroundWorker_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
			 this->progRecognizing->Value = e->ProgressPercentage;
		 }
private: System::Void recognizerBackgroundWorker_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
			 if (e->Error != nullptr) {
				 MessageBox::Show(e->Error->Message);
			 } else {
				 // replace image in picPreview with the preprocessed one
				 this->picPreview->Image = safe_cast<Bitmap^>(e->Result);
				 
				 // enable btnRecognize for recognition
				 this->btnRecognize->Enabled = true;
			 }
		 }

/**
 * Recognize image of dog
 */
private: System::Void btnRecognize_Click(System::Object^  sender, System::EventArgs^  e) {
			 // fields for image recognition
			 fann_type *input = (fann_type *)calloc(49, sizeof(fann_type));
			 fann_type *output;
			 Bitmap^ test = gcnew Bitmap(picPreview->Image);

			 // mapping the input
			 for (int i = 0; i < 7; i++) {
				 for (int j = 0; j < 7; j++) {
					 Color color = test->GetPixel(i, j);
					 input_map[i, j] = (float)color.R / (float)255;
				 }
			 }

			 int index = 0;
			 for (int i = 0; i < 7; i++) {
				 for (int j = 0; j < 7; j++) {
					 input[index++] = input_map[i, j];
				 }
			 }

			 // get output from recognition within ANN
			 output = Globals::recognizeInput(input);

			 string outputBinary = "";
			 for (int i = 0; i < 8; i++) {
				 if (output[i] < 0.5) outputBinary += "0";
				 else outputBinary += "1";
			 }

			 // message box for dog's name
			 string nameOfDog = Globals::getNameOfDog(outputBinary);
			 String^ nameOfDogText = gcnew String(nameOfDog.c_str());
			 MessageBox::Show(nameOfDogText);

			 // set txtName text to nameOfDogText
			 this->txtName->Text = nameOfDogText;
		 }
};
}
