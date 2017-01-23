#pragma once
#include "stdafx.h"

#include "SimConnect.h"

#define DECLARE_DISPATCH_MAP virtual void DispatchProc(SIMCONNECT_RECV* pData, DWORD cbData);

#define BEGIN_DISPATCH_MAP(type) void type::DispatchProc(SIMCONNECT_RECV* pData, DWORD cbData) { \
	switch(pData->dwID) {

#define END_DISPATCH_MAP default: break; } }

#define ADD_DISPATCH_HANDLER(key, paramtype, handler) case key: \
	handler(reinterpret_cast<paramtype *>(pData), cbData); \
	break;


#define DATA_TYPE_DEGREES "degrees"
#define DATA_TYPE_KNOTS "knots"
#define DATA_TYPE_BOOL "bool"
#define DATA_TYPE_FEET_PER_MINUTE "feet per minute"
#define DATA_TYPE_MASK "mask"
#define DATA_TYPE_ENUM "enum"

class CBaseSimConnectApp
{

	static void CALLBACK DispatchProcStatic(SIMCONNECT_RECV* pData, DWORD cbData, void *pContext)
	{
		CBaseSimConnectApp* pThis = reinterpret_cast<CBaseSimConnectApp*>(pContext);
		pThis->DispatchProc(pData, cbData);
	}

protected:
	HANDLE m_hSimConnect;
	HINSTANCE m_hInstance;
	LPCSTR m_szAppName;

	virtual HRESULT OnConnect() = 0;
	virtual void DispatchProc(SIMCONNECT_RECV* pData, DWORD cbData) = 0;

public:
	CBaseSimConnectApp(HINSTANCE, LPCSTR);
	virtual ~CBaseSimConnectApp();

	HRESULT Connect();
};

