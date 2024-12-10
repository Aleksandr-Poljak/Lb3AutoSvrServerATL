// MyMath.cpp: реализация CMyMath

#include "pch.h"
#include "MyMath.h"


// CMyMath

STDMETHODIMP CMyMath::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IMyMath
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CMyMath :: Mul(LONG x, LONG y, LONG* z)
{
	*z = (x)*y;

	return S_OK;
}

STDMETHODIMP CMyMath::Div(LONG x, LONG y, LONG* z)
{
	*z = x / y;

	return S_OK;
}

STDMETHODIMP CMyMath::Add(LONG x, LONG y, LONG* z)
{
	*z = x + y;

	return S_OK;
}

STDMETHODIMP CMyMath::Sub(LONG x, LONG y, LONG* z)
{
	*z = x - y;

	return S_OK;
}


STDMETHODIMP CMyMath::GetAuthor(BSTR name, BSTR* message)
{
	CComBSTR textBSTR("Welcome, ");
	textBSTR.Append(name);
	*message = textBSTR;

	return S_OK;
}


STDMETHODIMP CMyMath::get_Op1(LONG* pVal)
{
	
	*pVal = m_lOp1;

	return S_OK;
}


STDMETHODIMP CMyMath::put_Op1(LONG newVal)
{
	
	m_lOp1 = newVal;

	return S_OK;
}
