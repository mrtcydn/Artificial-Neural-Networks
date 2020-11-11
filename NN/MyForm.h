#pragma once

namespace NN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		Bitmap^ bitmap;
		int size = 4, X = 0, Y = 0, NoktaSayisi = 0, bias = 1, sinif1 = -1, sinif2 = 1;
		int* indeks = new int[size];			// indeks[] = {x , y , bias , label}
		float* zscore = new float[size];
		double* W = new double[9];

	public:


	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	public:
		MyForm(void)
		{
			InitializeComponent();
			Color color = Color::FromArgb(250, 250, 250);
			bitmap = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = bitmap;
			for (int i = 0; i < pictureBox1->Height; i++)
				for (int j = 0; j < pictureBox1->Width; j++)
				{
					bitmap->SetPixel(j, i, color);
				}
			//
			//TODO: Oluşturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanılan tüm kaynakları temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processesToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ trainingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ binaryToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ continousToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	protected:

	private:
		/// <summary>
		///Gerekli tasarımcı değişkeni.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarımcı desteği için gerekli metot - bu metodun 
		///içeriğini kod düzenleyici ile değiştirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->binaryToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->continousToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->processesToolStripMenuItem,
					this->toolStripMenuItem1
			});
			resources->ApplyResources(this->menuStrip1, L"menuStrip1");
			this->menuStrip1->Name = L"menuStrip1";
			// 
			// processesToolStripMenuItem
			// 
			this->processesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->trainingToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->processesToolStripMenuItem->Name = L"processesToolStripMenuItem";
			resources->ApplyResources(this->processesToolStripMenuItem, L"processesToolStripMenuItem");
			// 
			// trainingToolStripMenuItem
			// 
			this->trainingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->binaryToolStripMenuItem,
					this->continousToolStripMenuItem
			});
			this->trainingToolStripMenuItem->Name = L"trainingToolStripMenuItem";
			resources->ApplyResources(this->trainingToolStripMenuItem, L"trainingToolStripMenuItem");
			// 
			// binaryToolStripMenuItem
			// 
			this->binaryToolStripMenuItem->Name = L"binaryToolStripMenuItem";
			resources->ApplyResources(this->binaryToolStripMenuItem, L"binaryToolStripMenuItem");
			this->binaryToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Binary_Click);
			// 
			// continousToolStripMenuItem
			// 
			this->continousToolStripMenuItem->Name = L"continousToolStripMenuItem";
			resources->ApplyResources(this->continousToolStripMenuItem, L"continousToolStripMenuItem");
			this->continousToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Continous_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			resources->ApplyResources(this->exitToolStripMenuItem, L"exitToolStripMenuItem");
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			resources->ApplyResources(this->toolStripMenuItem1, L"toolStripMenuItem1");
			// 
			// checkBox1
			// 
			resources->ApplyResources(this->checkBox1, L"checkBox1");
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::picturebox1_MouseClick);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { resources->GetString(L"comboBox1.Items"), resources->GetString(L"comboBox1.Items1") });
			resources->ApplyResources(this->comboBox1, L"comboBox1");
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		   // Noktalari Cizme 
	private: System::Void picturebox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		X = e->X;
		Y = e->Y;

		NoktaSayisi++;  // Nokta sayisini tutmak icin

		Color color;

		W[0] = 1;  W[1] = 1; W[2] = 0;  // Agirliklar setlendi.
		int Index = comboBox1->SelectedIndex;

		if (Index == 0) {
			color = Color::FromArgb(0, 0, 205);
			for (int i = -7; i < 7; i++) {
				bitmap->SetPixel(X + i, Y, color);
			}
			for (int i = -7; i <= 7; i++)
			{
				bitmap->SetPixel(X, Y + i, color);
			}

			indeks[size - 4] = X - (pictureBox1->Width / 2);   // X değerinin tutulduğu indis
			indeks[size - 3] = (pictureBox1->Height / 2) - Y;  // Y değerinin tutulduğu indis
			indeks[size - 2] = bias;
			indeks[size - 1] = sinif1;    // Class1' e ait beklenen çıktı.
			size += 4;
		}
		
		else if (Index == 1) {
			
			color = Color::FromArgb(255, 0, 0);
			
			for (int i = -7; i < 7; i++) {
				bitmap->SetPixel(X + i, Y, color);
			}
			for (int i = -7; i <=7; i++)
			{
				bitmap->SetPixel(X, Y + i, color);
			}

			indeks[size - 4] = X - (pictureBox1->Width / 2);   // X değerinin tutulduğu indis
			indeks[size - 3] = (pictureBox1->Height / 2) - Y;  // Y değerinin tutulduğu indis
			indeks[size - 2] = bias;
			indeks[size - 1] = sinif2;    // Class2' e ait beklenen çıktı.
			size += 4;		
		}
		
		else if (Index == 2) {
			
			color = Color::FromArgb(0, 0, 0);

			for (int i = -7; i < 7; i++) {
				bitmap->SetPixel(X + i, Y, color);
			}
			for (int i = -7; i <= 7; i++)
			{
				bitmap->SetPixel(X, Y + i, color);
			}

			indeks[size - 4] = X - (pictureBox1->Width / 2);   // X değerinin tutulduğu indis
			indeks[size - 3] = (pictureBox1->Height / 2) - Y;  // Y değerinin tutulduğu indis
			indeks[size - 2] = bias;
			indeks[size - 1] = sinif2;    // Class2' e ait beklenen çıktı.
			size += 4;	
		}

		else if (Index == 3) {
			
			color = Color::FromArgb(0, 255, 0);

			for (int i = -7; i < 7; i++) {
				bitmap->SetPixel(X + i, Y, color);
			}
			for (int i = -7; i <= 7; i++)
			{
				bitmap->SetPixel(X, Y + i, color);
			}

			indeks[size - 4] = X - (pictureBox1->Width / 2);   // X değerinin tutulduğu indis
			indeks[size - 3] = (pictureBox1->Height / 2) - Y;  // Y değerinin tutulduğu indis
			indeks[size - 2] = bias;
			indeks[size - 1] = sinif2;    // Class2' e ait beklenen çıktı.
			size += 4;
		}
		
		else if (Index == -1) {
			MessageBox::Show("Please select a class!!");
		}

		pictureBox1->Image = bitmap;
	}

		   //PERCEPTRON LEARNİNG
	private: System::Void Binary_Click(System::Object^ sender, System::EventArgs^ e) {

		int sgnNet = 0, error = 1;
		float lr = 1, net = 0, x0 = 0, x1 = 0, y0 = 0 ,y1 = 0;
	
		while (error > 0) {
			error = 0;

			for (int i = 0; i < (NoktaSayisi * 4); i += 4) {

				// net = w * x;
				net = (W[0] * indeks[i]) + (W[1] * indeks[i + 1]) + (W[2] * indeks[i + 2]);

				// Class Belirleme
				if (net > 0) {
					sgnNet = 1;
				}
				else {
					sgnNet = -1;
				}

				//Hata durumunda agirliklari tekrar olusturma...
				//w^k+1 = W^k + c * (d - o) * x;
				//if (sgnNet != indeks[i + 3]) {
					W[0] += (lr * (indeks[i + 3] - sgnNet)) * indeks[i];
					W[1] += (lr * (indeks[i + 3] - sgnNet)) * indeks[i + 1];
					W[2] += (lr * (indeks[i + 3] - sgnNet)) * indeks[i + 2];
					error += Math::Abs(indeks[i + 3] - sgnNet) / 2;
				//}

				//w0*x0 + w1*x1 + w2 = 0;
				//x1 = -(wo*x0 + w2) / w1;
				x0 = -(pictureBox1->Width / 2);
				y0 = -(x0 * W[0] + W[2]) / W[1];
				x1 = (pictureBox1->Width / 2);
				y1 = -(x1 * W[0] + W[2]) / W[1];

				Color color;
				Graphics^ g;
				g = pictureBox1->CreateGraphics();
				Pen^ myPen;

				pictureBox1->Refresh();   
				for (int j = 0; j < (NoktaSayisi * 4); j += 4) {
					if (indeks[j + 3] == sinif1) {
						color = Color::FromArgb(0, 0, 205);
					}
					else if (indeks[j + 3] == sinif2) {
						color = Color::FromArgb(255, 0, 0);
					}
				}
				myPen = gcnew Pen(Color::DarkGreen, 2);
				g->DrawLine(myPen, 0.0, (pictureBox1->Height / 2) - y0, (float)(pictureBox1->Width), (pictureBox1->Height / 2) - y1);	
			}
		}
	}

			// DELTA LEARNİNG
	private:System::Void Continous_Click(System::Object^ sender, System::EventArgs^ e) {

		float fnet = 0, fnetderivative = 0, net = 0;
		float error = 1, learningRate = 0.1, x0 = 0, x1 = 0, y0 = 0, y1 = 0;
		int lamda = 1;
		float omegaKatsayi = 0;
		float avgX = 0, avgY = 0, s_deviationX = 0, s_deviationY = 0, tempX = 0, tempY = 0, sumX = 0, sumY = 0;

		Color color;
		color = Color::FromArgb(255, 255, 255);

		Graphics^ k;
		k = pictureBox1->CreateGraphics();
		Pen^ kalem2;
			
		// NORMALİZASYON
		if (checkBox1->Checked) {
			for (int i = 0; i < pictureBox1->Height; i++) {
				for (int j = 0; j < pictureBox1->Width; j++)
				{
					bitmap->SetPixel(j, i, color);
				}
			}
			for (int i = 0; i < (NoktaSayisi * 4); i += 4) {
				sumX += indeks[i];
				sumY += indeks[i + 1];
			}

			avgX = sumX / NoktaSayisi;
			avgY = sumY / NoktaSayisi;

			for (int j = 0; j < (NoktaSayisi * 4); j += 4) {
				tempX += Math::Pow((indeks[j] - avgX), 2);
				tempY += Math::Pow((indeks[j + 1] - avgY), 2);
			}

			s_deviationX = Math::Sqrt(tempX / (NoktaSayisi));
			s_deviationY = Math::Sqrt(tempY / (NoktaSayisi));

			for (int k = 0; k < (NoktaSayisi * 4); k += 4) {
				zscore[k] = (indeks[k] - avgX) / s_deviationX;
				zscore[k + 1] = (indeks[k + 1] - avgY) / s_deviationY;
				zscore[k + 2] = indeks[k + 2];
				zscore[k + 3] = indeks[k + 3];
			}
		}
			while (error > 0.1) {

				error = 0;

				for (int i = 0; i < (NoktaSayisi * 4); i += 4) {

					net = (W[0] * zscore[i]) + (W[1] * zscore[i + 1]) + (W[2] * zscore[i + 2]);

					// fnet = o (gerceklesen cikti)
					// fnet = 2/ (1 + (-lamda * net)) - 1;
					fnet = (2 / (1 + Math::Exp(-(lamda * net))) - 1);

					// fnetderivative = (1 - o^2) *0.5;
					fnetderivative = 0.5 * (1 - Math::Pow(fnet, 2));

					omegaKatsayi = (float)(learningRate * (zscore[i + 3] - fnet)) * fnetderivative;

					//w^k+1 = w^k + c * (d - o) * f'(net) * x;
					W[0] += (omegaKatsayi * zscore[i]);
					W[1] += (omegaKatsayi * zscore[i + 1]);
					W[2] += (omegaKatsayi * zscore[i + 2]);

					// error = error + (d - o)^2 * 0.5;
					error += Math::Pow((zscore[i + 3] - fnet), 2) * 0.5;

					//w0*x0 + w1*x1 + w2 = 0;g
					//x1 = -(wo*x0 + w2) / w1;
					x0 = -(pictureBox1->Width / 2);
					y0 = -(W[0] * x0 + W[2]) / W[1];
					x1 = (pictureBox1->Width / 2);
					y1 = -(W[0] * x1 + W[2]) / W[1];

					pictureBox1->Refresh();   // Çizilen doðrularýn üst üste gelmemesi için

					Pen^ pen = gcnew Pen(Color::Red, 2);
					for (int n = 0; n < NoktaSayisi * 4; n += 4) {
						if (zscore[n + 3] == sinif1) {   
							color = Color::FromArgb(0, 0, 205);
						}
						else if (zscore[n + 3] == sinif2) { 
							color = Color::FromArgb(255, 0, 0);
						}
						X = (zscore[n] * 25) + (pictureBox1->Width / 2);  
						Y = (pictureBox1->Height / 2) - (zscore[n + 1] * 25);

						for (int i = -7; i < 7; i++) {
							bitmap->SetPixel(X + i, Y, color);
						}
						for (int i = -7; i < 7; i++) {
							bitmap->SetPixel(X, Y + i, color);
						}
					}

					kalem2 = gcnew Pen(Color::DarkGreen, 2);
					k->DrawLine(kalem2, (float)0, (pictureBox1->Height / 2) - y0, (float)(pictureBox1->Width), (pictureBox1->Height / 2) - y1);
				}
			}
	}

private: System::Void multicategoryPerceptronToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}

