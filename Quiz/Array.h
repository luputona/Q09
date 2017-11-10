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
	//연산자 오버로딩 []
	T operator[](int index)
	{
		return m_buf[index];
	}

	//추가
	void Add(T data)
	{
		m_buf[m_size++] = data;
	}

	//맨 뒤에부터 삭제
	void Delete()
	{
		m_buf[m_size--] = NULL;
	}

	//데이터 시작부분
	T Begin()
	{
		return m_buf[0];
	}

	//데이터 마지막 부분
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