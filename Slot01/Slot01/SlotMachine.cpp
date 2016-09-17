// �X���b�g�h�����N���X

#include "stdafx.h"
#include "Form1.h"

using namespace Slot01;

// �R���X�g���N�^
SlotMachine::SlotMachine()
{
	// �ϐ�������
	rand = gcnew Random();
	bAtari = false;

	// �t�H�[������
	fm = gcnew Form1();

	// ���[�h���X���s�i�t�H�[�����I���܂Ń��[�v�j
	//	Application::Run( fm );
	fm->Show();

	// �h����������
	InitDrum();

	// �{�^��������
	InitButton();

	// �����\��
	drum1->InitDraw();
	drum1->Draw();
	drum2->InitDraw();
	drum2->Draw();
	drum3->InitDraw();
	drum3->Draw();

	// ���b�Z�[�W���[�v�J�n
	MainLoop();
}

// �h����������
void SlotMachine::InitDrum(void)
{
	drum1 = gcnew SlotDrum();
	drum2 = gcnew SlotDrum();
	drum3 = gcnew SlotDrum();

	// �h�����P�i���[�j
	drum1->Init( 150, 120 );
	drum1->SetLocation( 50, 40 );
	fm->Controls->Add( drum1->GetPicBox() );
	// �A�C�e���ǉ�
	drum1->AddItem( 0, "gunu01.jpg" );
	drum1->AddItem( 1, "gunu02.jpg" );
	drum1->AddItem( 2, "gunu03.jpg" );
	drum1->AddItem( 3, "gunu04.jpg" );
	drum1->AddItem( 4, "gunu05.jpg" );
	drum1->AddItem( 5, "gunu06.jpg" );
	drum1->AddItem( 6, "gunu_A.jpg" );
	drum1->AddItem( 7, "gunu_B.jpg" );
	drum1->AddItem( 8, "gunu_C.jpg" );
	drum1->AddItem( 9, "gunu_D.jpg" );
	drum1->AddItem( 99, "nuko_22886.png" );

	// �h�����Q�i�����j
	drum2->Init( 180, 120 );
	drum2->SetLocation( 210, 40 );
	fm->Controls->Add( drum2->GetPicBox() );
	// �A�C�e���ǉ�
	drum2->AddItem( 0, "gunu01.jpg" );
	drum2->AddItem( 2, "gunu03.jpg" );
	drum2->AddItem( 1, "gunu02.jpg" );
	drum2->AddItem( 3, "gunu04.jpg" );
	drum2->AddItem( 5, "gunu06.jpg" );
	drum2->AddItem( 4, "gunu05.jpg" );
	drum2->AddItem( 98, "nuko_285c.jpg" );
	drum2->AddItem( 9, "gunu_D.jpg" );
	drum2->AddItem( 8, "gunu_C.jpg" );
	drum2->AddItem( 7, "gunu_B.jpg" );
	drum2->AddItem( 6, "gunu_A.jpg" );
	drum2->AddItem( 99, "nuko_22886.png" );

	// �h�����R�i�E�[�j
	drum3->Init( 160, 120 );
	drum3->SetLocation( 400, 40 );
	fm->Controls->Add( drum3->GetPicBox() );
	// �A�C�e���ǉ�
	drum3->AddItem( 0, "gunu01.jpg" );
	drum3->AddItem( 0, "gunu01.jpg" );
	drum3->AddItem( 1, "gunu02.jpg" );
	drum3->AddItem( 1, "gunu02.jpg" );
	drum3->AddItem( 2, "gunu03.jpg" );
	drum3->AddItem( 2, "gunu03.jpg" );
	drum3->AddItem( 3, "gunu04.jpg" );
	drum3->AddItem( 4, "gunu05.jpg" );
	drum3->AddItem( 5, "gunu06.jpg" );
	drum3->AddItem( 8, "gunu_C.jpg" );
	drum3->AddItem( 9, "gunu_D.jpg" );
	drum3->AddItem( 7, "gunu_B.jpg" );
	drum3->AddItem( 6, "gunu_A.jpg" );
	drum3->AddItem( 99, "nuko_22886.png" );
}

// �{�^��������
void SlotMachine::InitButton(void)
{
	// �X�^�[�g�{�^��
	button_start = (gcnew System::Windows::Forms::Button());
	button_start->Location = System::Drawing::Point(180, 2);
	button_start->Name = L"button1";
	button_start->Size = System::Drawing::Size(150, 24);
	button_start->TabIndex = 1;
	button_start->Text = L"START";
	button_start->UseVisualStyleBackColor = true;
	button_start->Click += gcnew System::EventHandler(this, &SlotMachine::button_start_Click);
	fm->Controls->Add( button_start );

	// �X�g�b�v�{�^���P
	button_stop1 = (gcnew System::Windows::Forms::Button());
	button_stop1->Location = System::Drawing::Point(60, 400);
	button_stop1->Name = L"button1";
	button_stop1->Size = System::Drawing::Size(80, 24);
	button_stop1->TabIndex = 1;
	button_stop1->Text = L"STOP";
	button_stop1->UseVisualStyleBackColor = true;
	button_stop1->Click += gcnew System::EventHandler(this, &SlotMachine::button_stop1_Click);
	fm->Controls->Add( button_stop1 );

	// �X�g�b�v�{�^���Q
	button_stop2 = (gcnew System::Windows::Forms::Button());
	button_stop2->Location = System::Drawing::Point(220, 400);
	button_stop2->Name = L"button1";
	button_stop2->Size = System::Drawing::Size(80, 24);
	button_stop2->TabIndex = 1;
	button_stop2->Text = L"STOP";
	button_stop2->UseVisualStyleBackColor = true;
	button_stop2->Click += gcnew System::EventHandler(this, &SlotMachine::button_stop2_Click);
	fm->Controls->Add( button_stop2 );

	// �X�g�b�v�{�^���R
	button_stop3 = (gcnew System::Windows::Forms::Button());
	button_stop3->Location = System::Drawing::Point(410, 400);
	button_stop3->Name = L"button1";
	button_stop3->Size = System::Drawing::Size(80, 24);
	button_stop3->TabIndex = 1;
	button_stop3->Text = L"STOP";
	button_stop3->UseVisualStyleBackColor = true;
	button_stop3->Click += gcnew System::EventHandler(this, &SlotMachine::button_stop3_Click);
	fm->Controls->Add( button_stop3 );
}

// ���C�����[�v
void SlotMachine::MainLoop(void)
{
	bool bb = true;

	// ���b�Z�[�W���[�v�J�n
	while( bb )
	{
		Application::DoEvents();

		// �h�������s
		drum1->DoDrum();
		drum2->DoDrum();
		drum3->DoDrum();
	
		// �X���b�g��~����
		if( drum1->GetMode() == DRUM_MODE_HANTEI && 
			drum2->GetMode() == DRUM_MODE_HANTEI && 
			drum3->GetMode() == DRUM_MODE_HANTEI )
		{	// ���蔻�菈��
			// �܂��A�����`�F�b�N
			int num1 = drum1->GetItemNum(1);
			int num2 = drum2->GetItemNum(1);
			int num3 = drum3->GetItemNum(1);

			if( num1 == num2 && num1 == num3 )
			{
				bAtari = true;
			}
		}

		// ����E�n�Y�������v�\���i�蔲���Ńe�L�X�g�\���̂݁B�j
		if( bAtari == true )
		{
			fm->SetLabel1( "����I�I" );
		}
		else
		{
			fm->SetLabel1( "---" );
		}

		// ���t���b�V��
		fm->Refresh();

		if( fm->Visible == false )
		{	// �E�B���h�E������ꂽ��A
			bb = false;		// �v���O�����I��
		}
	}
}

// 
// �X�^�[�g�{�^������
System::Void SlotMachine::button_start_Click(System::Object^  sender, System::EventArgs^  e)
{
	drum1->SetSpeed( 20 + rand->Next(200) );
	drum1->ModeChange( DRUM_MODE_ROLL );

	drum2->SetSpeed( 20 + rand->Next(200) );
	drum2->ModeChange( DRUM_MODE_ROLL );

	drum3->SetSpeed( 20 + rand->Next(200) );
	drum3->ModeChange( DRUM_MODE_ROLL );

	bAtari = false;		// ������
}

// �X�g�b�v�P�{�^������
System::Void SlotMachine::button_stop1_Click(System::Object^  sender, System::EventArgs^  e)
{
	// ���\�{�^���`�F�b�N
	if( drum1->GetMode() == DRUM_MODE_HANTEI )
	{	// ���ɒ�~���Ă���Ȃ�A������������������B
		drum1->SetSpeed( 12 );	// ���\���[�h����
	}
	drum1->ModeChange( DRUM_MODE_SLOWDOWN );
}

// �X�g�b�v�Q�{�^������
System::Void SlotMachine::button_stop2_Click(System::Object^  sender, System::EventArgs^  e)
{
	// ���\�{�^���`�F�b�N
	if( drum2->GetMode() == DRUM_MODE_HANTEI )
	{	// ���ɒ�~���Ă���Ȃ�A������������������B
		drum2->SetSpeed( 12 );	// ���\���[�h����
	}
	drum2->ModeChange( DRUM_MODE_SLOWDOWN );
}

// �X�g�b�v�R�{�^������
System::Void SlotMachine::button_stop3_Click(System::Object^  sender, System::EventArgs^  e)
{
	// ���\�{�^���`�F�b�N
	if( drum3->GetMode() == DRUM_MODE_HANTEI )
	{	// ���ɒ�~���Ă���Ȃ�A������������������B
		drum3->SetSpeed( 12 );	// ���\���[�h����
	}
	drum3->ModeChange( DRUM_MODE_SLOWDOWN );
}

