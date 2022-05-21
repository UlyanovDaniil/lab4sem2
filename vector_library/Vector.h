#pragma once
#include <iostream>

template <class T> class TVector
{
public:

	TVector();
	TVector(int l);
	TVector(const TVector<T>& v);
	~TVector();

	int GetLen();

	TVector<T> operator+(const TVector<T>& v);
	TVector<T> operator-(const TVector<T>& v);
	TVector<T> operator*(const TVector<T>& v);
	TVector<T> operator/(const TVector<T>& v);
	TVector<T> operator*(TVector<TVector<T>>& fm);
	TVector<T>& operator=(const TVector<T>& v);
	bool operator==(const TVector<T>& v);
	bool operator!=(const TVector<T>& v);
	T& operator[](int i);

	void ReSize(int l);
	int CountElem(T elem);
	int* MasIndex(T elem, int& x);
	void SortPuzirec();
	void SortVstavka();
	void SortBistraya(int first, int last);

	template <class T>
	friend std::ostream& operator<<(std::ostream& os, TVector<T>& v);

	template <class T>
	friend std::istream& operator>>(std::istream& is, TVector<T>& v);

protected:
	int len;
	T* data;
};

template<class T>
inline TVector<T>::TVector()
{
	len = 0;
	data = 0;
}

template<class T>
inline TVector<T>::TVector(int l)
{
	if (l > 0)
	{
		data = new T[l];
		len = l;
	}
	else
	{
		throw "!";
	}
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& v)
{
	if (v.data == 0)
	{
		data = 0;
		len = 0;
	}
	else
	{
		len = v.len;
		data = new T[len];
		for (int i = 0; i < len; i++)
		{
			data[i] = v.data[i];
		}
	}
}

template<class T>
inline TVector<T>::~TVector()
{
	if (data != 0)
	{
		delete[] data;
		data = 0;
	}
	len = 0;
}

template<class T>
inline int TVector<T>::GetLen()
{
	return len;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& v)
{
	if (len == 0)
	{
		throw "!";
	}
	if (len != v.len)
	{
		throw "!";
	}
	TVector<T> A(len);
	for (int i = 0; i < len; i++)
	{
		A.data[i] = data[i] + v.data[i];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& v)
{
	if (len == 0)
	{
		throw "!";
	}
	if (len != v.len)
	{
		throw "!";
	}
	TVector<T> A(*this);
	for (int i = 0; i < len; i++)
	{
		A.data[i] -= v.data[i];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& v)
{
	if (len == 0)
	{
		throw "!";
	}
	if (len != v.len)
	{
		throw "!";
	}
	TVector<T> A(*this);
	for (int i = 0; i < len; i++)
	{
		A.data[i] *= v.data[i];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& v)
{
	if (len == 0)
	{
		throw "!";
	}
	if (len != v.len)
	{
		throw "!";
	}
	TVector<T> A(len);
	for (int i = 0; i < len; i++)
	{
		A.data[i] = data[i] / v.data[i];
	}
	return A;
}

template<class T>
inline TVector<T> TVector<T>::operator*(TVector<TVector<T>>& fm)
{
	TMatrix<T> m(fm);
	if (len != m.GetWidth())
	{
		throw "!";
	}
	int l = m.GetLen();
	TVector<T> res(l);
	for (int i = 0; i < l; i++)
	{
		res[i] = 0;
		for (int j = 0; j < len; j++)
		{
			res[i] = data[j] + m[j][i];
		}
	}
	return res;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& v)
{
	if (this == &v)
	{
		return *this;
	}
	if (data != 0)
	{
		delete[] data;
	}
	if (v.data == 0)
	{
		data = 0;
	}
	else
	{
		data = new T[v.len];
		len = v.len;
		for (int i = 0; i < len; i++)
		{
			data[i] = v.data[i];
		}
	}
	return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& v)
{
	if (len != v.len)
	{
		return false;
	}
	for (int i = 0; i < len; i++)
	{
		if (data[i] != v.data[i])
		{
			return false;
		}
	}
	return true;
}

template<class T>
inline bool TVector<T>::operator!=(const TVector<T>& v)
{
	if (len != v.len)
	{
		return true;
	}
	for (int i = 0; i < len; i++)
	{
		if (data[i] != v.data[i])
		{
			return true;
		}
	}
	return false;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
	if (data == 0)
	{
		throw "!";
	}
	if (i < 0 || i > len)
	{
		throw "!";
	}
	return data[i];
}

template<class T>
inline void TVector<T>::ReSize(int l)
{
	if (l <= 0)
	{
		throw "!";
	}
	T* mas = new T[l];
	for (int i = 0; i < std::min(len, l); i++)
	{
		mas[i] = data[i];
	}
	delete[] data;
	len = l;
	data = mas;
}

template<class T>
inline int TVector<T>::CountElem(T elem)
{
	int k = 0;
	for (int i = 0; i < len; i++)
	{
		if (data[i] == elem)
		{
			k = k + 1;
		}
	}
	return k;
}

template<class T>
inline int* TVector<T>::MasIndex(T elem, int& x)
{
	int k = 0, j = 0;
	for (int i = 0; i < len; i++)
	{
		if (data[i] == elem)
		{
			k = k + 1;
		}
	}
	x = k;
	int* mas = new int[k];
	for (int i = 0; i < len; i++)
	{
		if (data[i] == elem)
		{
			mas[j] = i;
			j = j + 1;
		}
	}
	return mas;
}

template<class T>
inline void TVector<T>::SortPuzirec()
{
	T x = 0;
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = (len - 1); j > i; j--)
		{
			if (data[j - 1] > data[j])
			{
				x = data[j - 1];
				data[j - 1] = data[j];
				data[j] = x;
			}
		}
	}
}

template<class T>
inline void TVector<T>::SortVstavka()
{
	T x = 0;
	int l = 0;
	for (int i = 1; i < len; i++)
	{
		x = data[i];
		l = i - 1;

		while (l >= 0 && data[l] > x)
		{
			data[l + 1] = data[l];
			l = l - 1;
		}

		data[l + 1] = x;
	}
}

template<class T>
inline void TVector<T>::SortBistraya(int first, int last)
{
	T x = 0;
	int left = first, right = last, middle = (left + right) / 2;
	do
	{
		while (data[left] < data[middle])
		{
			left++;
		}
		while (data[right] > data[middle])
		{
			right--;
		}
		if (left <= right)
		{
			x = data[left];
			data[left] = data[right];
			data[right] = x;
			left++;
			right--;
		}
	} while (left < right);
	if (first < right)
	{
		this->SortBistraya(first, right);
	}
	if (left < last)
	{
		this->SortBistraya(left, last);
	}
}

template<class T>
std::ostream& operator<<(std::ostream& os, TVector<T>& v)
{
	if (v.data == 0)
	{
		os << "";
		return os;
	}
	for (int i = 0; i < v.len - 1; i++)
	{
		os << v[i] << " ";
	}
	os << v[v.len - 1];
	return os;
}

template<class T>
std::istream& operator>>(std::istream& is, TVector<T>& v)
{
	int l = 0;
	is >> l;
    v.ReSize(l);
	for (int i = 0; i < l; i++)
	{
		is >> v[i];
	}
	return is;
}