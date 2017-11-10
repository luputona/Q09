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
	//연산자 오버로딩 []
	T operator[](int index)
	{
		return m_buff[index];
	}

	//추가
	void Add(T data)
	{
		m_buff[m_size++] = data;
	}

	//맨 뒤에부터 삭제
	void Delete()
	{
		m_buff[m_size--] = NULL;
	}

	//데이터 시작부분
	T Begin()
	{
		return m_buff[0];
	}

	//데이터 마지막 부분
	T End()
	{
		return m_buff[m_size];
	}

	//인덱스 가지고 데이터 얻어오는 부분
	T GetDataForIndex(int _index)
	{
		return m_buff[_index];
	}
	int Size()
	{
		return m_size;
	}
};