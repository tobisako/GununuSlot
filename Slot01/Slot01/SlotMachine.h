// スロットマシーンヘッダ
#pragma once

#include "stdafx.h"
#include "Form1.h"
using namespace Slot01;

// スロットマシーン本体クラス
public ref class SlotMachine {
public:
	Random ^rand;
	Form1	^fm;
	System::Windows::Forms::Button^  button_start;
	System::Windows::Forms::Button^  button_stop1;
	System::Windows::Forms::Button^  button_stop2;
	System::Windows::Forms::Button^  button_stop3;
	System::Void SlotMachine::button_start_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void SlotMachine::button_stop1_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void SlotMachine::button_stop2_Click(System::Object^  sender, System::EventArgs^  e);
	System::Void SlotMachine::button_stop3_Click(System::Object^  sender, System::EventArgs^  e);

	SlotDrum	^drum1;
	SlotDrum	^drum2;
	SlotDrum	^drum3;
	SlotMachine();				// コンストラクタ
	void InitDrum(void);		// ドラム初期化
	void InitButton(void);		// ドラム初期化
	void MainLoop(void);		// メインループ
private:
	bool bAtari;				// 当りフラグ

};
