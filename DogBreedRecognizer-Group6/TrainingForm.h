#pragma once

#include <cstdlib>
#include <msclr/marshal_cppstd.h>
#include "Globals.h"

namespace DogBreedRecognizerGroup6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TrainingForm
	/// </summary>
	public ref class TrainingForm : public System::Windows::Forms::Form
	{
	private:
		int highestPercentageReached;

		// fields for the neural network
		array<fann_type, 2> ^input_map;
		array<fann_type, 2> ^output_map;
		bool trained; // whether at least one dog is trained

	public:
		TrainingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			highestPercentageReached = 0;
			InitializeBackgroundWorker();

			input_map = gcnew array<fann_type, 2>(7, 7);
			output_map = gcnew array<fann_type, 2>(24, 8);

			trained = false;
		}

	private:
		void InitializeBackgroundWorker() {
			this->trainingBackgroundWorker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &TrainingForm::trainingBackgroundWorker_DoWork);
			this->trainingBackgroundWorker->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &TrainingForm::trainingBackgroundWorker_RunWorkerCompleted);
			this->trainingBackgroundWorker->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &TrainingForm::trainingBackgroundWorker_ProgressChanged);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TrainingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblName;
	private: System::Windows::Forms::Label^  lblWeight;
	private: System::Windows::Forms::Label^  lblHeight;
	protected: 

	protected: 


	private: System::Windows::Forms::Label^  lblTitle;
	private: System::Windows::Forms::ProgressBar^  progTraining;


	private: System::Windows::Forms::Button^  btnUpload;
	private: System::Windows::Forms::Button^  btnTrain;
	private: System::Windows::Forms::TextBox^  txtName;
	private: System::Windows::Forms::TextBox^  txtWeight;
	private: System::Windows::Forms::TextBox^  txtHeight;
	private: System::Windows::Forms::PictureBox^  picPreview;







	private: System::Windows::Forms::PictureBox^  picPaw;
	private: System::ComponentModel::BackgroundWorker^  trainingBackgroundWorker;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;


	private: System::ComponentModel::IContainer^  components;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TrainingForm::typeid));
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lblWeight = (gcnew System::Windows::Forms::Label());
			this->lblHeight = (gcnew System::Windows::Forms::Label());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->progTraining = (gcnew System::Windows::Forms::ProgressBar());
			this->btnUpload = (gcnew System::Windows::Forms::Button());
			this->btnTrain = (gcnew System::Windows::Forms::Button());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->txtWeight = (gcnew System::Windows::Forms::TextBox());
			this->txtHeight = (gcnew System::Windows::Forms::TextBox());
			this->picPreview = (gcnew System::Windows::Forms::PictureBox());
			this->picPaw = (gcnew System::Windows::Forms::PictureBox());
			this->trainingBackgroundWorker = (gcnew System::ComponentModel::BackgroundWorker());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picPreview))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picPaw))->BeginInit();
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
			this->lblTitle->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lblTitle->Location = System::Drawing::Point(253, 24);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(135, 24);
			this->lblTitle->TabIndex = 3;
			this->lblTitle->Text = L"Training Breed";
			// 
			// progTraining
			// 
			this->progTraining->Location = System::Drawing::Point(31, 184);
			this->progTraining->Name = L"progTraining";
			this->progTraining->Size = System::Drawing::Size(140, 23);
			this->progTraining->TabIndex = 4;
			// 
			// btnUpload
			// 
			this->btnUpload->Location = System::Drawing::Point(209, 184);
			this->btnUpload->Name = L"btnUpload";
			this->btnUpload->Size = System::Drawing::Size(88, 23);
			this->btnUpload->TabIndex = 5;
			this->btnUpload->Text = L"Upload Picture";
			this->btnUpload->UseVisualStyleBackColor = true;
			this->btnUpload->Click += gcnew System::EventHandler(this, &TrainingForm::btnUpload_Click);
			// 
			// btnTrain
			// 
			this->btnTrain->Enabled = false;
			this->btnTrain->Location = System::Drawing::Point(303, 184);
			this->btnTrain->Name = L"btnTrain";
			this->btnTrain->Size = System::Drawing::Size(85, 23);
			this->btnTrain->TabIndex = 6;
			this->btnTrain->Text = L"Train";
			this->btnTrain->UseVisualStyleBackColor = true;
			this->btnTrain->Click += gcnew System::EventHandler(this, &TrainingForm::btnTrain_Click);
			// 
			// txtName
			// 
			this->txtName->Enabled = false;
			this->txtName->Location = System::Drawing::Point(278, 70);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(100, 20);
			this->txtName->TabIndex = 7;
			// 
			// txtWeight
			// 
			this->txtWeight->Enabled = false;
			this->txtWeight->Location = System::Drawing::Point(278, 104);
			this->txtWeight->Name = L"txtWeight";
			this->txtWeight->Size = System::Drawing::Size(100, 20);
			this->txtWeight->TabIndex = 8;
			// 
			// txtHeight
			// 
			this->txtHeight->Enabled = false;
			this->txtHeight->Location = System::Drawing::Point(278, 139);
			this->txtHeight->Name = L"txtHeight";
			this->txtHeight->Size = System::Drawing::Size(100, 20);
			this->txtHeight->TabIndex = 9;
			// 
			// picPreview
			// 
			this->picPreview->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->picPreview->Location = System::Drawing::Point(31, 24);
			this->picPreview->Name = L"picPreview";
			this->picPreview->Size = System::Drawing::Size(140, 140);
			this->picPreview->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picPreview->TabIndex = 10;
			this->picPreview->TabStop = false;
			// 
			// picPaw
			// 
			this->picPaw->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"picPaw.Image")));
			this->picPaw->Location = System::Drawing::Point(193, 9);
			this->picPaw->Name = L"picPaw";
			this->picPaw->Size = System::Drawing::Size(54, 58);
			this->picPaw->TabIndex = 11;
			this->picPaw->TabStop = false;
			// 
			// trainingBackgroundWorker
			// 
			this->trainingBackgroundWorker->WorkerReportsProgress = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"JPG image (*.jpg)|*.jpg|JPEG image (*.jpeg)|*.jpeg|PNG image (*.png)|*.png";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &TrainingForm::openFileDialog1_FileOk);
			// 
			// TrainingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 224);
			this->Controls->Add(this->picPaw);
			this->Controls->Add(this->picPreview);
			this->Controls->Add(this->txtHeight);
			this->Controls->Add(this->txtWeight);
			this->Controls->Add(this->txtName);
			this->Controls->Add(this->btnTrain);
			this->Controls->Add(this->btnUpload);
			this->Controls->Add(this->progTraining);
			this->Controls->Add(this->lblTitle);
			this->Controls->Add(this->lblHeight);
			this->Controls->Add(this->lblWeight);
			this->Controls->Add(this->lblName);
			this->Name = L"TrainingForm";
			this->Text = L"TrainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &TrainingForm::TrainingForm_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TrainingForm::TrainingForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &TrainingForm::TrainingForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picPreview))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->picPaw))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TrainingForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void btnUpload_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (this->openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				 // initialize picture and other necessary components
				 initializeData(openFileDialog1->FileName);

				 // reset percentage of progress bar
				 highestPercentageReached = 0;

				 // clone image for preprocessing
				 Bitmap^ tempImage = (Bitmap^)this->picPreview->Image->Clone();

				 // preprocess the image (by using trainingBackgroundWorker / async process)
				 trainingBackgroundWorker->RunWorkerAsync(tempImage);
			 }
		 }

private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		 }

/**
 * initialize the image, weight, and height
 */
private: System::Void initializeData(System::String^ filename) {
			 this->picPreview->Image = gcnew Bitmap(filename);

			 // set weight and height of dog image
			 System::Int32^ weight = this->picPreview->Image->Width / 4;
			 System::Int32^ height = this->picPreview->Image->Height / 4;

			 System::String^ weightStr = weight->ToString();
			 System::String^ heightStr = height->ToString();

			 this->txtWeight->Text = weightStr;
			 this->txtHeight->Text = heightStr;
		 }

/**
 * Preprocess the dog's image before learning it in the ANN
 */
private: Bitmap^ preprocessImage(Bitmap^ image, BackgroundWorker^ worker, System::ComponentModel::DoWorkEventArgs^ e) {
			 Bitmap^ result = (Bitmap^)image->Clone();

			 // grayscale
			 result = grayscale(result, worker, e);

			 // binarize/threshold the image
			 result = threshold(result, worker, e);

			 // remove noise from the image
			 result = removeNoise(result, worker, e);

			 // resize the image
			 result = resizeImage(result, 7, 7, worker, e);

			 return result;
		 }

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

private: System::Void trainingBackgroundWorker_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
			 BackgroundWorker^ worker = dynamic_cast<BackgroundWorker^>(sender);
			 
			 // preprocess the image
			 e->Result = preprocessImage(safe_cast<Bitmap^>(e->Argument), worker, e);
		 }

private: System::Void trainingBackgroundWorker_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
			 if (e->Error != nullptr) {
				 MessageBox::Show(e->Error->Message);
			 } else {
				 // replace image in picPreview with the preprocessed one
				 this->picPreview->Image = safe_cast<Bitmap^>(e->Result);
				 
				 // enable textbox for name input
				 this->txtName->Enabled = true;
				 this->btnTrain->Enabled = true;
			 }
		 }

private: System::Void trainingBackgroundWorker_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
			 this->progTraining->Value = e->ProgressPercentage;
		 }

private: System::Void btnTrain_Click(System::Object^  sender, System::EventArgs^  e) {
			 System::String^ dogName = txtName->Text;

			 // if the name field is empty
			 if (dogName->Equals("")) {
				 System::Windows::Forms::MessageBox::Show("Name must be filled.");
			 }

			 // if name has been input
			 else {
				 if (Globals::getPictureCount() < 24) {
					 trainNewDog(dogName);
				 } else {
					 MessageBox::Show("Maximum picture count reached for training.");
				 }
				 
				 Globals::incrementPictureCount();
			 }
		 }

private: System::Void trainNewDog(System::String^ dogName) {
			 Bitmap^ bmp = gcnew Bitmap(picPreview->Image);

			 // mapping the input for training
			 for (int i = 0; i < 7; i++) {
				 for (int j = 0; j < 7; j++) {
					 Color color = bmp->GetPixel(i, j);
					 input_map[i, j] = (float)color.R / (float)255;
				 }
			 }

			 // mapping the output: 
			 
			 // initialize output_map
			 for (int i = 0; i < 24; i++) {
				 for (int j = 0; j < 8; j++) {
					 output_map[i, j] = 0;
				 }
			 }
			 
			 // count (decimal) -> to binary format
			 char binaryArr[10];

			 // one-based binary, not zero-based (pictureCount is still zero-based)
			 itoa((Globals::getPictureCount() + 1), binaryArr, 2);

			 String^ binaryStr = gcnew String(binaryArr);
			 while (binaryStr->Length < 8) {
				 binaryStr = "0" + binaryStr;
			 }

			 for (int i = 0; i < 8; i++) {
				 char ch = safe_cast<char>(binaryStr[i]);
				 int val = ch - '0';
				 output_map[Globals::getPictureCount(), i] = (fann_type)val;
			 }

			 fann_train_data *data = (fann_train_data*)malloc(sizeof(fann_train_data));
			 
			 data->num_data = Globals::getPictureCount() + 1;
			 data->num_input = 49;
			 data->num_output = 8;

			 data->input = (fann_type**)calloc(7, sizeof(fann_type));
			 for (int i = 0; i < 7; i++) {
				 data->input[i] = (fann_type*)calloc(7, sizeof(fann_type));
				 for (int j = 0; j < 7; j++) {
					 data->input[i][j] = input_map[i, j];
				 }
			 }

			 data->output = (fann_type**)calloc(24, sizeof(fann_type));
			 for (int i = 0; i < 24; i++) {
				 data->output[i] = (fann_type*)calloc(8, sizeof(fann_type));
				 for (int j = 0; j < 8; j++) {
					 data->output[i][j] = output_map[i, j];
				 }
			 }

			 Globals::trainNeuralNetwork(data, 10000, 0, 0.00001);
			 
			 // save the dog's name to hash table into Globals
			 std::string convBinaryStr = msclr::interop::marshal_as<std::string>(binaryStr);
			 std::string convDogName = msclr::interop::marshal_as<std::string>(dogName);

			 Globals::insertNewDog(convBinaryStr, convDogName);
			 trained = true;

			 MessageBox::Show("Done Training");
		 }

private: System::Void TrainingForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
			 if (Globals::getAnn() && trained) {
				 Globals::saveNeuralNetwork();
			 }
		 }
private: System::Void TrainingForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		 }
};
}
