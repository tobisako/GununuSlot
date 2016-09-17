#include "stdafx.h"
#include "Form1.h"

using namespace Slot01;



// デバッグ用：タイマー
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

// デバッグ用：ボタン２謳歌
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

// デバッグ用：ボタン謳歌
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

	// ドラム
	int DrumWidth	= picwidth + 10;
	int	DrumHeight	= picheight * 3;


	Graphics^	grpPicBox;

	// ピクチャボックス生成
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

	// ボックスを黒くする。
	Brush^ brush = gcnew SolidBrush( Color::FromArgb(0, 0, 0) );
	grpPicBox->FillRectangle( brush, 0, 0, DrumWidth, DrumHeight );

	// イメージボックスのサイズ変更
	Bitmap ^bmp1 = gcnew Bitmap( "gununu01.jpg" );

	// 描画元（ビットマップ）・描画先（ピクチャボックス）の領域
	RectangleF SrcRect = RectangleF(0, 0, bmp1->Width, bmp1->Height);
	RectangleF DstRect = RectangleF(0, 0, picwidth, picheight);

	grpPicBox->DrawImage(bmp1, DstRect, SrcRect, GraphicsUnit::Pixel);

	// イメージボックスのサイズ変更
	Bitmap ^bmp2 = gcnew Bitmap( "gununu_index_css3_002s.jpg" );

	// ビットマップの描画元の領域
	SrcRect = RectangleF(0, 0, bmp2->Width, bmp2->Height);
	// ピクチャボックスへの描画先
	DstRect = RectangleF(0, 200, 250, 450);

	grpPicBox->DrawImage(bmp2, DstRect, SrcRect, GraphicsUnit::Pixel);

	// イメージボックスのサイズ変更
	Bitmap ^bmp3 = gcnew Bitmap( "gunu_kurouto.jpg" );

	// ビットマップの描画元の領域
	SrcRect = RectangleF(0, 0, bmp3->Width, bmp3->Height);
	// ピクチャボックスへの描画先
	DstRect = RectangleF(0, 400, 250, 550);

	grpPicBox->DrawImage(bmp3, DstRect, SrcRect, GraphicsUnit::Pixel);
*/
}
