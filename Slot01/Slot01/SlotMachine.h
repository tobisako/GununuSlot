// �X���b�g�}�V�[���w�b�_
#pragma once

#include "stdafx.h"
#include "Form1.h"
using namespace Slot01;

// �X���b�g�}�V�[���{�̃N���X
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
	SlotMachine();				// �R���X�g���N�^
	void InitDrum(void);		// �h����������
	void InitButton(void);		// �h����������
	void MainLoop(void);		// ���C�����[�v
private:
	bool bAtari;				// ����t���O

};
