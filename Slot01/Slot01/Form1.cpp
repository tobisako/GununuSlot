#include "stdafx.h"
#include "Form1.h"

using namespace Slot01;



// �f�o�b�O�p�F�^�C�}�[
System::Void Form1::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	cliext::list<SlotDrum^>::iterator ite = lisidx.begin();
	while( ite != lisidx.end() )
	{
		(*ite)->Draw();
		this->Refresh();
		ite++;
	}
}

// �f�o�b�O�p�F�{�^���Q搉�
System::Void Form1::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	cliext::list<SlotDrum^>::iterator ite = lisidx.begin();
	while( ite != lisidx.end() )
	{
		(*ite)->Draw();
		this->Refresh();
		ite++;

/*		System::String ^ss;
		ss = "iArrow=" + iArrow;
		this->label1->Text = ss->ToString();
		ss = "iPer=" + iPer;
		this->label2->Text = ss->ToString();
*/
	}
}

// �f�o�b�O�p�F�{�^��搉�
System::Void Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	SlotDrum^ obj = gcnew SlotDrum();

	obj->Init( 150, 120 );
	obj->SetLocation( 40, 40 );
	this->Controls->Add( obj->GetPicBox() );
	obj->InitDraw();
	obj->Draw();

	lisidx.push_back( obj );

//	this->timer1->Interval = 200;
//	this->timer1->Start();

	/*
	System::Windows::Forms::PictureBox^  picBox;
	int picwidth	= 320;
	int picheight	= 200;

	// �h����
	int DrumWidth	= picwidth + 10;
	int	DrumHeight	= picheight * 3;


	Graphics^	grpPicBox;

	// �s�N�`���{�b�N�X����
	picBox = (gcnew System::Windows::Forms::PictureBox());
	picBox->Location = System::Drawing::Point(10, 10);
	picBox->Name = L"pictureBox1";
	picBox->Size = System::Drawing::Size(DrumWidth, DrumHeight);
	picBox->TabIndex = 0;
	picBox->TabStop = false;
	this->Controls->Add(picBox);

	Bitmap ^bmp = gcnew Bitmap( DrumWidth, DrumHeight );
	picBox->Image = bmp;

	grpPicBox = Graphics::FromImage(picBox->Image);

	// �{�b�N�X����������B
	Brush^ brush = gcnew SolidBrush( Color::FromArgb(0, 0, 0) );
	grpPicBox->FillRectangle( brush, 0, 0, DrumWidth, DrumHeight );

	// �C���[�W�{�b�N�X�̃T�C�Y�ύX
	Bitmap ^bmp1 = gcnew Bitmap( "gununu01.jpg" );

	// �`�挳�i�r�b�g�}�b�v�j�E�`���i�s�N�`���{�b�N�X�j�̗̈�
	RectangleF SrcRect = RectangleF(0, 0, bmp1->Width, bmp1->Height);
	RectangleF DstRect = RectangleF(0, 0, picwidth, picheight);

	grpPicBox->DrawImage(bmp1, DstRect, SrcRect, GraphicsUnit::Pixel);

	// �C���[�W�{�b�N�X�̃T�C�Y�ύX
	Bitmap ^bmp2 = gcnew Bitmap( "gununu_index_css3_002s.jpg" );

	// �r�b�g�}�b�v�̕`�挳�̗̈�
	SrcRect = RectangleF(0, 0, bmp2->Width, bmp2->Height);
	// �s�N�`���{�b�N�X�ւ̕`���
	DstRect = RectangleF(0, 200, 250, 450);

	grpPicBox->DrawImage(bmp2, DstRect, SrcRect, GraphicsUnit::Pixel);

	// �C���[�W�{�b�N�X�̃T�C�Y�ύX
	Bitmap ^bmp3 = gcnew Bitmap( "gunu_kurouto.jpg" );

	// �r�b�g�}�b�v�̕`�挳�̗̈�
	SrcRect = RectangleF(0, 0, bmp3->Width, bmp3->Height);
	// �s�N�`���{�b�N�X�ւ̕`���
	DstRect = RectangleF(0, 400, 250, 550);

	grpPicBox->DrawImage(bmp3, DstRect, SrcRect, GraphicsUnit::Pixel);
*/
}
