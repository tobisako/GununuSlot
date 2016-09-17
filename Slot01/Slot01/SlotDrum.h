// ドラムヘッダ
#pragma once

#include "stdafx.h"
//using namespace Slot01;

// アイテムクラス
public ref class SlotItem {
public:
	SlotItem();
	void SetFimename( int n, System::String ^fn );		// 画像ファイル名をセットする
	System::Drawing::Bitmap ^GetBmp(void);		// ビットマップを返す。
	int	GetNum(void);							// 番号を返す
private:
	System::Drawing::Bitmap ^bmp;
	int num;
};

#define MAX_DISP_SIZE	3		// ドラムは、「中央」・「上」・「下」の３エリア。
								// ここは、奇数である必要がある。
								// この場合、制御には４エリア必要になる。

// ドラムクラス
public ref class SlotDrum {
public:
	int iDrumLocationX;
	int iDrumLocationY;
	void SetLocation( int x, int y );
	int iPicWidth;
	int iPicHeight;
	int iDrumWidth;
	int iDrumHeight;
	void Init( int PicWidth, int PicHeight );
	void LoadAllPic(void);
	void AddItem( int n, System::String ^fn );		// アイテムを追加
	void InitDraw(void);
	void Draw(void);
	void SetDispBitmap(void);				// 画面表示用BMPのセット
//	void DrawOneDrum( int idx, int per );
	int DrawOneDrum( int idx, int per, SlotItem ^item );
	System::Windows::Forms::PictureBox ^GetPicBox(void);
//	System::Drawing::Bitmap ^GetDispBmp( int idx );			// ドラム表示用ビットマップを取得
	void SetDrumPos( int arrow, int per );				// ドラム位置セット（絶対座標）
	void MoveDrum( int per );							// ドラム移動
	void DoDrum(void);									// ドラム動作
	void ModeChange( int m );							// モード変更
	int GetMode(void);									// モード取得
	void SetSpeed( int speed );							// スピード設定
	int GetItemNum( int pos );							// ドラムのアイテム番号を返す
private:
	cliext::list<SlotItem^>itemidx;		// ドラム全体用に。
	cliext::list<SlotItem^>dispidx;		// 表示用に。

	System::Windows::Forms::PictureBox^  picBox;
	System::Drawing::Graphics^	grp;
	System::Drawing::Bitmap ^bmp;	// ベースとなるビットマップ
	System::Drawing::Brush^ brush;

//	System::Drawing::Bitmap ^dispbmp[MAX_DISP_SIZE + 1];	// ドラム表示用ビットマップ配列
//	cliext::list<System::Drawing::Bitmap^>itemidx;		// STL/list
//	System::Drawing::Bitmap ^dispbmp0;	// ドラム表示用ビットマップ配列
//	System::Drawing::Bitmap ^dispbmp1;	// ドラム表示用ビットマップ配列
//	System::Drawing::Bitmap ^dispbmp2;	// ドラム表示用ビットマップ配列
//	System::Drawing::Bitmap ^dispbmp3;	// ドラム表示用ビットマップ配列

	int iMaxPic;
	int iMaxItem;	// 登録アイテム数
	int iMode;		// ドラムモード
	int iArrow;		// ドラムを指示している場所。
	int iPer;		// ドラムのズレ幅（０％～９９％、みたいな。）
	int iSpeed;		// ドラム回転スピード
};

#define DRUM_MODE_STOP		0		// 停止中
#define DRUM_MODE_ROLL		1		// 高速回転中
#define DRUM_MODE_SLOWDOWN	2		// 減速中
#define DRUM_MODE_HANTEI	3		// 判定