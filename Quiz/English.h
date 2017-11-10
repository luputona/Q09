#pragma once
#include<iostream>
#include<string.h>

using namespace std;
template<class T>
class English
{
public:
	int m_size;
	int m_capacity;
	T* m_buff;

public:
	English(int _cap = 5000) :m_buff(NULL), m_size(0), m_capacity(_cap)
	{
		m_buff = new T[m_capacity];
	}
	~English()
	{

	}
	//������ �����ε� []
	T operator[](int index)
	{
		return m_buff[index];
	}

	//�߰�
	void Add(T data)
	{
		m_buff[m_size++] = data;
	}

	//�� �ڿ����� ����
	void Delete()
	{
		m_buff[m_size--] = NULL;
	}

	//������ ���ۺκ�
	T Begin()
	{
		return m_buff[0];
	}

	//������ ������ �κ�
	T End()
	{
		return m_buff[m_size];
	}

	//�ε��� ������ ������ ������ �κ�
	T GetDataForIndex(int _index)
	{
		return m_buff[_index];
	}
	int Size()
	{
		return m_size;
	}
};