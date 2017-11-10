#pragma once
#include<iostream>
#include<string.h>

using namespace std;
template<class T>
class Korean
{
public:
	int m_size;
	int m_capacity;
	T* m_buff;

public:
	Korean(int _cap = 50) : m_buff(NULL), m_capacity(_cap), m_size(0)
	{
		m_buff = new T[m_capacity];
	}
	~Korean()
	{
		//delete[] m_buff;
	}
	T operator[](int _index)
	{
		return m_buff[_index];
	}

	//������ �߰�
	void Add(T _data)
	{
		m_buff[m_size++] = _data;
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