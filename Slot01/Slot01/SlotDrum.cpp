// �X���b�g�h�����N���X

#include "stdafx.h"
#include "Form1.h"
#include "SlotDrum.h"

using namespace Slot01;


/////////////////////////////////////////////////////////////////
// �X���b�g�A�C�e��

// �R���X�g���N�^
SlotItem::SlotItem()
{
}

// �摜�ݒ�
void SlotItem::SetFimename( int n, System::String ^fn )
{
	// �摜���[�h
	bmp = gcnew Bitmap( fn );
	num = n;
}

// �r�b�g�}�b�v��Ԃ�
System::Drawing::Bitmap ^SlotItem::GetBmp(void)
{
	return bmp;
}

// �ԍ���Ԃ�
int SlotItem::GetNum(void)
{
	return num;
}


/////////////////////////////////////////////////////////////////

// �h�����������i�܂��\���͂����Ȃ��܂����j
void SlotDrum::Init( int PicWidth, int PicHeight )
{
	// �l������
	iPicWidth = PicWidth;
	iPicHeight = PicHeight;
	iMaxPic = 3;				// �h�������̍ő�o�h�b���i����͂R�Œ�j
	iDrumWidth = PicWidth;
	iDrumHeight = PicHeight * iMaxPic;

	// �s�N�`���{�b�N�X����
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

// �A�C�e���ǉ�
void SlotDrum::AddItem( int n, System::String ^fn )
{
	SlotItem ^item = gcnew SlotItem();		// �A�C�e���N���X����
	item->SetFimename( n, fn );				// �t�@�C�����ݒ�
	itemidx.push_back( item );				// ���X�g�ǉ�
	iMaxItem++;
}

// ��ʕ\���pBMP�̍쐬�i�摜�S�j
void SlotDrum::SetDispBitmap(void)
{
	int iCnt;
	cliext::list<SlotItem^>::iterator ite = itemidx.begin();
	dispidx.clear();

	// �C�e���[�^��i�߂�
	for( iCnt = 0; iCnt < iArrow; iCnt++ )
	{
		ite++;
		if( ite == itemidx.end() ) ite = itemidx.begin();
	}

	// �A�C�e���I�u�W�F�N�g���擾����
	for( iCnt = 0; iCnt < 4; iCnt++ )
	{
		if( ite == itemidx.end() ) ite = itemidx.begin();
		dispidx.push_back( *ite );
		ite++;
	}
}

// �S�摜�����[�h���Ă���
void SlotDrum::LoadAllPic(void)
{
//	bmp0 = gcnew Bitmap( "gununu01.jpg" );
//	bmp1 = gcnew Bitmap( "gununu_index_css3_002s.jpg" );
//	bmp2 = gcnew Bitmap( "gunu_kurouto.jpg" );
}

// �h���������`�揈��
void SlotDrum::InitDraw(void)
{
	// �����炭�ŏ��̂P�񂾂��ł�����͂����B
	bmp = gcnew Bitmap( iDrumWidth, iDrumHeight );
	picBox->Image = bmp;
	grp = Graphics::FromImage(picBox->Image);
//	grp = picBox->CreateGraphics();

	// �{�b�N�X����������B
	brush = gcnew SolidBrush( Color::FromArgb(0, 0, 0) );
	grp->FillRectangle( brush, 0, 0, iDrumWidth, iDrumHeight );
}

// PictureBox��Ԃ��B
System::Windows::Forms::PictureBox ^SlotDrum::GetPicBox(void)
{
	return picBox;
}

// ���W�w��
void SlotDrum::SetLocation( int x, int y )
{
	iDrumLocationX = x;
	iDrumLocationY = y;
	picBox->Location = System::Drawing::Point(iDrumLocationX, iDrumLocationY);
}

// �h�����P�����h���[����B
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

	// �`�挳�i�r�b�g�}�b�v�j�E�`���i�s�N�`���{�b�N�X�j�̗̈�
	RectangleF SrcRect = RectangleF(0, 0, (float)item->GetBmp()->Width, (float)item->GetBmp()->Height);
	RectangleF DstRect = RectangleF(0, (float)iHeightIndex, (float)iPicWidth, (float)(iPicHeight));
	grp->DrawImage(item->GetBmp(), DstRect, SrcRect, GraphicsUnit::Pixel);
	// ���ł�����
	grp->DrawLine( Pens::Red, 0, 0, iPicWidth, 0 );
	grp->DrawLine( Pens::Red, 0, iPicHeight + iHeightIndex, iPicWidth, iPicHeight + iHeightIndex );

	return item->GetNum();
}

// �h�����`��
void SlotDrum::Draw( void )
{
	SetDispBitmap();	// �\���p�r�b�g�}�b�v��ݒ�B

	cliext::list<SlotItem^>::iterator ite = dispidx.begin();

	// 4�̃r�b�g�}�b�v��p�ӂ��Ă݂悤����܂����B
	int iNum, n;

	// �ԍ��z��́A
	iNum = iArrow;
	iNum = 0;

	// �C���[�W�{�b�N�X�̃T�C�Y�ύX
	n = DrawOneDrum( iNum, iPer,  *ite );
	ite++;
	iNum++;

	// �C���[�W�{�b�N�X�̃T�C�Y�ύX
	n = DrawOneDrum( iNum, iPer, *ite );
	ite++;
	iNum++;

	// �C���[�W�{�b�N�X�̃T�C�Y�ύX
	n = DrawOneDrum( iNum, iPer, *ite );
	ite++;
	iNum++;

	// �C���[�W�{�b�N�X�̃T�C�Y�ύX
	DrawOneDrum( iNum, iPer, *ite );

	// �Ō�́A�h�����S�̂���ł�����B�i�Ōザ��Ȃ���_���j
	grp->DrawLine( Pens::Red, 0, 0, iDrumWidth, 0 );
	grp->DrawLine( Pens::Red, 0, iDrumHeight, iDrumWidth, iDrumHeight );
	grp->DrawLine( Pens::Red, 0, 0, 0, iDrumHeight );
	grp->DrawLine( Pens::Red, iDrumWidth, 0, iDrumWidth, iDrumHeight );
}
// �h�����ʒu�Z�b�g�i��΍��W�j
void SlotDrum::SetDrumPos( int arrow, int per )
{
	iArrow = arrow;
	iPer = per;
}

// �h�����ړ�
void SlotDrum::MoveDrum( int per )
{
	iPer += per;

	// ���[������
	while( iPer >= 100 )	// 100�������܂ŌJ��Ԃ��B
	{
		iArrow++;
		if( iArrow >= iMaxItem) iArrow = 0;
		iPer -= 100;
	}
}

// �h�������s
void SlotDrum::DoDrum( void )
{
	switch( iMode )
	{
	case DRUM_MODE_STOP:		// ��~��
		break;
	case DRUM_MODE_ROLL:		// ������]��
		MoveDrum( iSpeed );
		break;
	case DRUM_MODE_SLOWDOWN:	// ������
		// �������W�b�N
		if( iSpeed > 100 ) iSpeed -= 8;
		else if( iSpeed > 50 ) iSpeed -= 3;
		else iSpeed --;
		if( iSpeed <= 1 ) iSpeed = 1;
		if( iSpeed == 1 && iPer == 0 )
		{
			iSpeed = 0;
			iMode = DRUM_MODE_HANTEI;	// ��~�����A���胂�[�h�֕ύX�B
		}
		MoveDrum( iSpeed );
		break;
	case DRUM_MODE_HANTEI:		// ����҂����[�h
		break;
	}

	Draw();		// �h�����E�h���[
}

// �h�����̃A�C�e���ԍ���Ԃ�
int SlotDrum::GetItemNum( int pos )
{
	cliext::list<SlotItem^>::iterator ite = dispidx.begin();

	for( int i = 0; i < pos; i++)
	{
		ite++;
	}
	return (*ite)->GetNum();
}

// ���[�h�ύX
void SlotDrum::ModeChange( int m )
{
	iMode = m;
}

// ���[�h�擾
int SlotDrum::GetMode( void )
{
	return iMode;
}

// �X�s�[�h�ݒ�
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

0%	30%	60% ���ꗦ

*/

