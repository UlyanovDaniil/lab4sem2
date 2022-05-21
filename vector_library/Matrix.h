#pragma once
#include <iostream>
#include "Vector.h"

template <class T> class TMatrix : public TVector<TVector<T>>
{
public:

	TMatrix();
	TMatrix(int l);
	TMatrix(int l, int w);
	TMatrix(TVector<TVector<T>>& fm);
	TMatrix(const TMatrix<T>& m);
	~TMatrix();

	int GetWidth();

	TMatrix<T> operator+(const TMatrix<T>& m);
	TMatrix<T> operator-(const TMatrix<T>& m);
	TMatrix<T> operator*(const TMatrix<T>& m);
	TVector<T> operator*(TVector<T>& v);
	TMatrix<T>& operator=(const TMatrix<T>& m);
	TMatrix<T>& operator=(TVector<TVector<T>>& fm);
	bool operator==(const TMatrix<T>& m);
	bool operator!=(const TMatrix<T>& m);
	TVector<T>& operator[](int i);

	void ReSize(int l, int w);
	int CountElem(T elem);
	int** MasIndex(T elem, int& x);

	template <class T>
	friend std::ostream& operator<<(std::ostream& os, TMatrix<T>& m);

	template <class T>
	friend std::istream& operator>>(std::istream& is, TMatrix<T>& m);

protected:
	int width;
};

template<class T>
inline TMatrix<T>::TMatrix()
{
	width = 0;
	this->len = 0;
	this->data = 0;
}

template<class T>
inline TMatrix<T>::TMatrix(int l)
{
	if (l <= 0)
	{
		throw "!";
	}
	this->len = l;
	width = l;
	this->data = new TVector<T>[width];
	for (int i = 0; i < width; i++)
	{
		this->data[i].ReSize(this->len);
	}
}

template<class T>
inline TMatrix<T>::TMatrix(int l, int w)
{
	if ((l <= 0) || (w <= 0))
	{
		throw "!";
	}
	this->len = l;
	width = w;
	this->data = new TVector<T>[width];
	for (int i = 0; i < width; i++)
	{
		this->data[i].ReSize(this->len);
	}
}

template<class T>
inline TMatrix<T>::TMatrix(TVector<TVector<T>>& fm)
{
	int maxl = 0;
	width = fm.GetLen();
	if (width == 0)
	{
		this->len = 0;
		this->data = 0;
	}
	else
	{
		this->data = new TVector<T>[width];
		for (int i = 0; i < width; i++)
		{
			if (fm[i].GetLen() > maxl)
			{
				maxl = fm[i].GetLen();
			}
		}
		this->len = maxl;
		for (int i = 0; i < width; i++)
		{
			this->data[i] = fm[i];
			this->data[i].ReSize(this->len);
		}
	}
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& m)
{
	this->len = m.len;
	width = m.width;
	if (m.data == 0)
	{
		this->data = 0;
	}
	else
	{
		this->data = new TVector<T>[width];
		for (int i = 0; i < width; i++)
		{
			this->data[i] = m.data[i];
		}
	}
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
	if (this->data != 0)
	{
		delete[] this->data;
		this->data = 0;
	}
	this->len = 0;
	width = 0;
}

template<class T>
inline int TMatrix<T>::GetWidth()
{
	return width;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m)
{
	TMatrix res(*this);
	if (this->len != m.len || width != m.width)
	{
		throw "!";
	}
	for (int i = 0; i < width; i++)
	{
		res.data[i] = this->data[i] + m.data[i];
	}
	return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m)
{
	TMatrix res(this->len, width);
	if (this->len != m.len || width != m.width)
	{
		throw "!";
	}
	for (int i = 0; i < width; i++)
	{
		res.data[i] = this->data[i] - m.data[i];
	}
	return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m)
{
	if (this->len != m.width)
	{
		throw "!";
	}
	TMatrix<T> res(m.len, width);
	for (int i = 0; i < this->len; i++)
	{
		for (int j = 0; j < m.len; j++)
		{
			res[i][j] = 0;
			for (int l = 0; l < m.width; l++)
			{
				res[i][j] += this->data[i][l] * m.data[l][j];
			}
		}
	}
	return res;
}

template<class T>
inline TVector<T> TMatrix<T>::operator*(TVector<T>& v)
{
	if (this->len != v.GetLen())
	{
		throw "!";
	}
	int l = width;
	TVector<T> res(l);
	for (int j = 0; j < l; j++)
	{
		res[j] = 0;
		for (int l = 0; l < this->len; l++)
		{
			res[j] += this->data[j][l] * v[l];
		}
	}
	return res;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m)
{
	this->len = m.len;
	width = m.width;
	if (m.data == 0)
	{
		this->data = 0;
	}
	else
	{
		this->data = new TVector<T>[width];
		for (int i = 0; i < width; i++)
		{
			this->data[i] = m.data[i];
		}
	}
	return *this;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(TVector<TVector<T>>& fm)
{
	int maxl = 0;
	width = fm.GetLen();
	if (width == 0)
	{
		this->len = 0;
		this->data = 0;
	}
	else
	{
		this->data = new TVector<T>[width];
		for (int i = 0; i < width; i++)
		{
			if (fm[i].GetLen() > maxl)
			{
				maxl = fm[i].GetLen();
			}
		}
		this->len = maxl;
		for (int i = 0; i < width; i++)
		{
			this->data[i] = fm[i];
			this->data[i].ReSize(this->len);
		}
	}
	return *this;
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& m)
{
	if (this->len != m.len || width != m.width)
	{
		return false;
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			if (this->data[i][j] != m.data[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix<T>& m)
{
	if (this->len != m.len || width != m.width)
	{
		return true;
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			if (this->data[i][j] != m.data[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

template<class T>
inline TVector<T>& TMatrix<T>::operator[](int i)
{
	if (this->data == 0)
	{
		throw "!";
	}
	if (i < 0 || i > width)
	{
		throw "!";
	}
	return this->data[i];
}

template<class T>
inline void TMatrix<T>::ReSize(int l, int w)
{
	TVector<T>* res = new TVector<T>[w];
	for (int i = 0; i < w; i++)
	{
		res[i].ReSize(l);
	}
	for (int i = 0; i < std::min(w, width); i++)
	{
		for (int j = 0; j < std::min(l, this->len); j++)
		{
			res[i][j] = this->data[i][j];
		}
	}
	delete[] this->data;
	this->data = res;
	this->len = l;
	width = w;
}

template<class T>
inline int TMatrix<T>::CountElem(T elem)
{
	int k = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			if (data[i][j] == elem)
			{
				k = k + 1;
			}
		}
	}
	return k;
}

template<class T>
inline int** TMatrix<T>::MasIndex(T elem, int& x)
{
	int k = 0, l = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			if (data[i][j] == elem)
			{
				k = k + 1;
			}
		}
	}
	x = k;
	int** mas = new int*[k];
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->len; j++)
		{
			if (data[i][j] == elem)
			{
				mas[l] = new int[2];
				mas[l][0] = i; mas[l][1] = j;
				l = l + 1;
			}
		}
	}
	return mas;
}

template<class T>
inline std::ostream& operator<<(std::ostream& os, TMatrix<T>& m)
{
	if (m.data == 0)
	{
		os << "";
		return os;
	}
	for (int i = 0; i < m.width - 1; i++)
	{
		os << m[i] << "\n";
	}
	os << m[m.width - 1];
	return os;
}

template<class T>
inline std::istream& operator>>(std::istream& is, TMatrix<T>& m)
{
	int l = 0, w = 0;
	is >> w >> l;
	m.ReSize(l, w);
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < l; j++)
		{
			is >> m[i][j];
		}
	}
	return is;
}