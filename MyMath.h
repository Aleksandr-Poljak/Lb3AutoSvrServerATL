// MyMath.h: объявление CMyMath

#pragma once
#include "resource.h"       // основные символы



#include "Lb3AutoSvr_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Однопотоковые COM-объекты не поддерживаются должным образом платформой Windows CE, например платформами Windows Mobile, в которых не предусмотрена полная поддержка DCOM. Определите _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA, чтобы принудить ATL поддерживать создание однопотоковых COM-объектов и разрешить использование его реализаций однопотоковых COM-объектов. Для потоковой модели в вашем rgs-файле задано значение 'Free', поскольку это единственная потоковая модель, поддерживаемая не-DCOM платформами Windows CE."
#endif

using namespace ATL;


// CMyMath

class ATL_NO_VTABLE CMyMath :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CMyMath, &CLSID_MyMath>,
	public ISupportErrorInfo,
	public IDispatchImpl<IMyMath, &IID_IMyMath, &LIBID_Lb3AutoSvrLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IDispatchImpl<IVer, &IID_IVer, &LIBID_Lb3AutoSvrLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
	long m_lOp1;
public:
	CMyMath()
	{
		m_lOp1 = 1;
	}

DECLARE_REGISTRY_RESOURCEID(106)


BEGIN_COM_MAP(CMyMath)
	COM_INTERFACE_ENTRY(IMyMath)
	COM_INTERFACE_ENTRY(IVer)
	COM_INTERFACE_ENTRY2(IDispatch, IMyMath)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	
	STDMETHOD(Mul)(LONG x, LONG y, LONG* z);
	STDMETHOD(Div)(LONG x, LONG y, LONG* z);
	STDMETHOD(Add)(LONG x, LONG y, LONG* z);
	STDMETHOD(Sub)(LONG x, LONG y, LONG* z);


	STDMETHOD(GetAuthor)(BSTR name, BSTR* message);
	STDMETHOD(get_Op1)(LONG* pVal);
	STDMETHOD(put_Op1)(LONG newVal);
};

OBJECT_ENTRY_AUTO(__uuidof(MyMath), CMyMath)
