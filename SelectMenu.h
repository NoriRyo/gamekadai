#pragma once

#include <vector>
#include "Vec2.h"

class SelectMenu
{
public:
	SelectMenu();
	virtual ~SelectMenu();

	// �������A�I������
	void init();
	void end();

	// �X�V
	void update();

	// �`��
	void draw();

	// �J�[�\���̏�����
	void setupCursor();

	// �\���ʒu�̐ݒ�
	void setPos(float x, float y);
	void setPos(Vec2 pos);
	// ���j���[���ڂ̒ǉ�
	void addItem(const char* text);

	// �E�C���h�E�T�C�Y�̎擾
	int getWindowWidth();
	int getWindowHeight();

private:
	class Item
	{
	public:
		Item();
		virtual ~Item();
		
		// ���j���[���ڂ̕\��	
		void draw(int x, int y);

		// �\�����镶�����ݒ�
		void setText(const char* text);
		// ������̕��Ԋu
		int getTextWidth();

	private:
		// �\�����镶����
		const char* m_text;

	};

	class Corsor
	{
	public:
		Corsor();
		virtual ~Corsor();

		// �X�V
		void update();

		// �\��
		void draw();

		void setMenuPos(Vec2 pos) { m_numePos = pos; }
		void setSize(Vec2 size) { m_size = size; }
		void setItemNum(int num) { m_itemNum = num; }
	private:
		//	���j���[�̕\���ʒu
		Vec2 m_numePos;

		// �J�[�\���T�C�Y
		Vec2 m_size;

		// ���j���[�̍��ڐ�
		int m_itemNum;
		
		// �I�����Ă��鍀�ڂ̔ԍ�
		int m_selectIndox;
	};

private:
	// �\���ʒu�i������W�j
	Vec2 m_pos;

	// ���j���[�̑I������
	std::vector<Item*> m_pItem;

	// �J�[�\��
	Corsor m_corsor;
};
