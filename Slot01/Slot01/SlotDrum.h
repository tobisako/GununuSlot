// �h�����w�b�_
#pragma once

#include "stdafx.h"
//using namespace Slot01;

// �A�C�e���N���X
public ref class SlotItem {
public:
	SlotItem();
	void SetFimename( int n, System::String ^fn );		// �摜�t�@�C�������Z�b�g����
	System::Drawing::Bitmap ^GetBmp(void);		// �r�b�g�}�b�v��Ԃ��B
	int	GetNum(void);							// �ԍ���Ԃ�
private:
	System::Drawing::Bitmap ^bmp;
	int num;
};

#define MAX_DISP_SIZE	3		// �h�����́A�u�����v�E�u��v�E�u���v�̂R�G���A�B
								// �����́A��ł���K�v������B
								// ���̏ꍇ�A����ɂ͂S�G���A�K�v�ɂȂ�B

// �h�����N���X
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
	void AddItem( int n, System::String ^fn );		// �A�C�e����ǉ�
	void InitDraw(void);
	void Draw(void);
	void SetDispBitmap(void);				// ��ʕ\���pBMP�̃Z�b�g
//	void DrawOneDrum( int idx, int per );
	int DrawOneDrum( int idx, int per, SlotItem ^item );
	System::Windows::Forms::PictureBox ^GetPicBox(void);
//	System::Drawing::Bitmap ^GetDispBmp( int idx );			// �h�����\���p�r�b�g�}�b�v���擾
	void SetDrumPos( int arrow, int per );				// �h�����ʒu�Z�b�g�i��΍��W�j
	void MoveDrum( int per );							// �h�����ړ�
	void DoDrum(void);									// �h��������
	void ModeChange( int m );							// ���[�h�ύX
	int GetMode(void);									// ���[�h�擾
	void SetSpeed( int speed );							// �X�s�[�h�ݒ�
	int GetItemNum( int pos );							// �h�����̃A�C�e���ԍ���Ԃ�
private:
	cliext::list<SlotItem^>itemidx;		// �h�����S�̗p�ɁB
	cliext::list<SlotItem^>dispidx;		// �\���p�ɁB

	System::Windows::Forms::PictureBox^  picBox;
	System::Drawing::Graphics^	grp;
	System::Drawing::Bitmap ^bmp;	// �x�[�X�ƂȂ�r�b�g�}�b�v
	System::Drawing::Brush^ brush;

//	System::Drawing::Bitmap ^dispbmp[MAX_DISP_SIZE + 1];	// �h�����\���p�r�b�g�}�b�v�z��
//	cliext::list<System::Drawing::Bitmap^>itemidx;		// STL/list
//	System::Drawing::Bitmap ^dispbmp0;	// �h�����\���p�r�b�g�}�b�v�z��
//	System::Drawing::Bitmap ^dispbmp1;	// �h�����\���p�r�b�g�}�b�v�z��
//	System::Drawing::Bitmap ^dispbmp2;	// �h�����\���p�r�b�g�}�b�v�z��
//	System::Drawing::Bitmap ^dispbmp3;	// �h�����\���p�r�b�g�}�b�v�z��

	int iMaxPic;
	int iMaxItem;	// �o�^�A�C�e����
	int iMode;		// �h�������[�h
	int iArrow;		// �h�������w�����Ă���ꏊ�B
	int iPer;		// �h�����̃Y�����i�O���`�X�X���A�݂����ȁB�j
	int iSpeed;		// �h������]�X�s�[�h
};

#define DRUM_MODE_STOP		0		// ��~��
#define DRUM_MODE_ROLL		1		// ������]��
#define DRUM_MODE_SLOWDOWN	2		// ������
#define DRUM_MODE_HANTEI	3		// ����