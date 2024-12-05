// dllmain.h: объявление класса модуля.

class CLb3AutoSvrModule : public ATL::CAtlDllModuleT< CLb3AutoSvrModule >
{
public :
	DECLARE_LIBID(LIBID_Lb3AutoSvrLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_LB3AUTOSVR, "{f92f5ac9-cc34-452f-be6a-4acb94ee541d}")
};

extern class CLb3AutoSvrModule _AtlModule;
