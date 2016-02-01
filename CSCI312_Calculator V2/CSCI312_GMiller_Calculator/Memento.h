#pragma once

template <class T>
class Memento
{
private: 
	T m_data;

public:
	Memento<T>();
	Memento<T>(T value);
	T getData() const;
	void setData(T value);
};

template <class T>
Memento<T>::Memento()
{
	this->m_data = default(T);  // Set the default value based upon the type passed 
}

template <class T>
Memento<T>::Memento(T value)
{
	this->m_data = value;
}

template <class T>
T Memento<T>::getData() const
{
	return m_data;
}

template <class T>
void Memento<T>::setData(T value)
{
	m_data = value;
}
