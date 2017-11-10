#pragma once
#include<iostream>
#include<string.h>

using namespace std;
template<class T>

class Array
{
public:
	int m_size;
	int m_capacity;
	T* m_buf;
	T* m_inputKor;
	T* m_inputEn;

public:
	Array(int _cap = 10) :m_buf(NULL), m_size(0), m_capacity(_cap)
	{
		m_buf = new T[m_capacity];
	}
	~Array()
	{

	}
	//������ �����ε� []
	T operator[](int index)
	{
		return m_buf[index];
	}

	//�߰�
	void Add(T data)
	{
		m_buf[m_size++] = data;
	}

	//�� �ڿ����� ����
	void Delete()
	{
		m_buf[m_size--] = NULL;
	}

	//������ ���ۺκ�
	T Begin()
	{
		return m_buf[0];
	}

	//������ ������ �κ�
	T End()
	{
		return m_buf[m_size];
	}

	T Search(T data)
	{
		for (int i = 0; i < m_size + 1; i++)
		{
			if (data == m_buf[i])
			{
				return m_buf[i];
			}
		}
	}

	int Array::GetSize()
	{
		return m_size;
	}

};