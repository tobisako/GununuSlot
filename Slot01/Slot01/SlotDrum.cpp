// スロットドラムクラス

#include "stdafx.h"
#include "Form1.h"
#include "SlotDrum.h"

using namespace Slot01;


/////////////////////////////////////////////////////////////////
// スロットアイテム

// コンストラクタ
SlotItem::SlotItem()
{
}

// 画像設定
void SlotItem::SetFimename( int n, System::String ^fn )
{
	// 画像ロード
	bmp = gcnew Bitmap( fn );
	num = n;
}

// ビットマップを返す
System::Drawing::Bitmap ^SlotItem::GetBmp(void)
{
	return bmp;
}

// 番号を返す
int SlotItem::GetNum(void)
{
	return num;
}


/////////////////////////////////////////////////////////////////

// ドラム初期化（まだ表示はおこないませんよ）
void SlotDrum::Init( int PicWidth, int PicHeight )
{
	// 値初期化
	iPicWidth = PicWidth;
	iPicHeight = PicHeight;
	iMaxPic = 3;				// ドラム内の最大ＰＩＣ数（今回は３固定）
	iDrumWidth = PicWidth;
	iDrumHeight = PicHeight * iMaxPic;

	// ピクチャボックス生成
	picBox = (gcnew System::Windows::Forms::PictureBox());
	picBox->Location = System::Drawing::Point(0, 0);
	picBox->Name = L"pictureBox1";
	picBox->Size = System::Drawing::Size( iDrumWidth, iDrumHeight );
	picBox->TabIndex = 0;
	picBox->TabStop = false;
//	this->Controls->Add(picBox);
	LoadAllPic();
	iMaxItem = 0;
	iArrow = 0;
	iPer = 0;
	iMode = 0;
}

// アイテム追加
void SlotDrum::AddItem( int n, System::String ^fn )
{
	SlotItem ^item = gcnew SlotItem();		// アイテムクラス生成
	item->SetFimename( n, fn );				// ファイル名設定
	itemidx.push_back( item );				// リスト追加
	iMaxItem++;
}

// 画面表示用BMPの作成（画像４つ）
void SlotDrum::SetDispBitmap(void)
{
	int iCnt;
	cliext::list<SlotItem^>::iterator ite = itemidx.begin();
	dispidx.clear();

	// イテレータを進める
	for( iCnt = 0; iCnt < iArrow; iCnt++ )
	{
		ite++;
		if( ite == itemidx.end() ) ite = itemidx.begin();
	}

	// アイテムオブジェクトを取得する
	for( iCnt = 0; iCnt < 4; iCnt++ )
	{
		if( ite == itemidx.end() ) ite = itemidx.begin();
		dispidx.push_back( *ite );
		ite++;
	}
}

// 全画像をロードしておく
void SlotDrum::LoadAllPic(void)
{
//	bmp0 = gcnew Bitmap( "gununu01.jpg" );
//	bmp1 = gcnew Bitmap( "gununu_index_css3_002s.jpg" );
//	bmp2 = gcnew Bitmap( "gunu_kurouto.jpg" );
}

// ドラム初期描画処理
void SlotDrum::InitDraw(void)
{
	// おそらく最初の１回だけでいけるはずだ。
	bmp = gcnew Bitmap( iDrumWidth, iDrumHeight );
	picBox->Image = bmp;
	grp = Graphics::FromImage(picBox->Image);
//	grp = picBox->CreateGraphics();

	// ボックスを黒くする。
	brush = gcnew SolidBrush( Color::FromArgb(0, 0, 0) );
	grp->FillRectangle( brush, 0, 0, iDrumWidth, iDrumHeight );
}

// PictureBoxを返す。
System::Windows::Forms::PictureBox ^SlotDrum::GetPicBox(void)
{
	return picBox;
}

// 座標指定
void SlotDrum::SetLocation( int x, int y )
{
	iDrumLocationX = x;
	iDrumLocationY = y;
	picBox->Location = System::Drawing::Point(iDrumLocationX, iDrumLocationY);
}

// ドラム１つ分をドローする。
int SlotDrum::DrawOneDrum( int idx, int per, SlotItem ^item )
{
//	int iHeightIndex = idx * iPicHeight + (iPicHeight * per / 100) - iPicHeight;
	int iHeightIndex;
	int iPos;
	switch( idx )
	{
	case 0:		iPos = 3;		break;
	case 1:		iPos = 2;		break;
	case 2:		iPos = 1;		break;
	case 3:		iPos = 0;		break;
	}
	iHeightIndex = iPos * iPicHeight + (iPicHeight * per / 100) - iPicHeight;

	// 描画元（ビットマップ）・描画先（ピクチャボックス）の領域
	RectangleF SrcRect = RectangleF(0, 0, (float)item->GetBmp()->Width, (float)item->GetBmp()->Height);
	RectangleF DstRect = RectangleF(0, (float)iHeightIndex, (float)iPicWidth, (float)(iPicHeight));
	grp->DrawImage(item->GetBmp(), DstRect, SrcRect, GraphicsUnit::Pixel);
	// 線でくくる
	grp->DrawLine( Pens::Red, 0, 0, iPicWidth, 0 );
	grp->DrawLine( Pens::Red, 0, iPicHeight + iHeightIndex, iPicWidth, iPicHeight + iHeightIndex );

	return item->GetNum();
}

// ドラム描画
void SlotDrum::Draw( void )
{
	SetDispBitmap();	// 表示用ビットマップを設定。

	cliext::list<SlotItem^>::iterator ite = dispidx.begin();

	// 4つのビットマップを用意してみようじゃまいか。
	int iNum, n;

	// 番号配列は、
	iNum = iArrow;
	iNum = 0;

	// イメージボックスのサイズ変更
	n = DrawOneDrum( iNum, iPer,  *ite );
	ite++;
	iNum++;

	// イメージボックスのサイズ変更
	n = DrawOneDrum( iNum, iPer, *ite );
	ite++;
	iNum++;

	// イメージボックスのサイズ変更
	n = DrawOneDrum( iNum, iPer, *ite );
	ite++;
	iNum++;

	// イメージボックスのサイズ変更
	DrawOneDrum( iNum, iPer, *ite );

	// 最後は、ドラム全体を線でくくる。（最後じゃなきゃダメ）
	grp->DrawLine( Pens::Red, 0, 0, iDrumWidth, 0 );
	grp->DrawLine( Pens::Red, 0, iDrumHeight, iDrumWidth, iDrumHeight );
	grp->DrawLine( Pens::Red, 0, 0, 0, iDrumHeight );
	grp->DrawLine( Pens::Red, iDrumWidth, 0, iDrumWidth, iDrumHeight );
}
// ドラム位置セット（絶対座標）
void SlotDrum::SetDrumPos( int arrow, int per )
{
	iArrow = arrow;
	iPer = per;
}

// ドラム移動
void SlotDrum::MoveDrum( int per )
{
	iPer += per;

	// ロール処理
	while( iPer >= 100 )	// 100を下回るまで繰り返す。
	{
		iArrow++;
		if( iArrow >= iMaxItem) iArrow = 0;
		iPer -= 100;
	}
}

// ドラム実行
void SlotDrum::DoDrum( void )
{
	switch( iMode )
	{
	case DRUM_MODE_STOP:		// 停止中
		break;
	case DRUM_MODE_ROLL:		// 高速回転中
		MoveDrum( iSpeed );
		break;
	case DRUM_MODE_SLOWDOWN:	// 減速中
		// 減速ロジック
		if( iSpeed > 100 ) iSpeed -= 8;
		else if( iSpeed > 50 ) iSpeed -= 3;
		else iSpeed --;
		if( iSpeed <= 1 ) iSpeed = 1;
		if( iSpeed == 1 && iPer == 0 )
		{
			iSpeed = 0;
			iMode = DRUM_MODE_HANTEI;	// 停止させ、判定モードへ変更。
		}
		MoveDrum( iSpeed );
		break;
	case DRUM_MODE_HANTEI:		// 判定待ちモード
		break;
	}

	Draw();		// ドラム・ドロー
}

// ドラムのアイテム番号を返す
int SlotDrum::GetItemNum( int pos )
{
	cliext::list<SlotItem^>::iterator ite = dispidx.begin();

	for( int i = 0; i < pos; i++)
	{
		ite++;
	}
	return (*ite)->GetNum();
}

// モード変更
void SlotDrum::ModeChange( int m )
{
	iMode = m;
}

// モード取得
int SlotDrum::GetMode( void )
{
	return iMode;
}

// スピード設定
void SlotDrum::SetSpeed( int speed )
{
	iSpeed = speed;
}

/*

3	4	4
3	3	4
3	3	3
2	3	3
2	2	3
2	2	2
1	2	2
1	1	2
1	1	1

0%	30%	60% ずれ率

*/

