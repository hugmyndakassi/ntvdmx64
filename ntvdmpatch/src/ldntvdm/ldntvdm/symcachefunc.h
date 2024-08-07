/*Project: ldntvdm
* Module : symcachefunc
* Author : leecher@dose.0wnz.at
* Descr. : Definition of private Symbols to cache. 
* Changes: 31.04.2022  - Split to seperate header file
*/
#include "injector32.h"

#define _E(x) {x,L##x}

static REGKEY_PAIR m_aSymsKERNEL32[] =
{
#ifndef NEED_BASEVDM
	_E("BaseCreateVDMEnvironment"),
	_E("BaseGetVdmConfigInfo"),
	_E("BaseCheckVDM"),
#endif
#if defined(TARGET_WIN7)
_E("BasepProcessInvalidImage"),
_E("BaseIsDosApplication"),
#endif // TARGET_WIN7
#if defined(TARGET_WINXP)
_E("NtVdm64CreateProcess"),
_E("BaseIsDosApplication"),
_E("BaseCreateStack"),
_E("BaseFormatObjectAttributes"),
_E("BasepIsProcessAllowed"),
_E("BasePushProcessParameters"),
_E("BasepIsRealtimeAllowed"),
_E("BaseInitializeContext"),
_E("BaseStaticServerData"),
_E("StuffStdHandle"),
_E("BasepFreeAppCompatData"),
_E("BasepReplaceProcessThreadTokens"),
_E("BasepCheckBadapp"),
_E("BasepCheckWinSaferRestrictions"),
#ifndef _WIN64
_E("CsrBasepCreateProcess"),
#endif
_E("BuildSubSysCommandLine"),
#endif // TARGET_WINXP
{ NULL, NULL }
};

#if defined(_WIN64) && !defined(TARGET_WINXP) && (defined(TARGET_WIN7) || defined(HOOK_CONHOSTV2))
static REGKEY_PAIR m_aSymsCONHOST[] =
{
#if defined(TARGET_WIN7)
	_E("dwConBaseTag"),
	_E("FindProcessInList"),
	_E("CreateConsoleBitmap"),
#endif
#if defined(HOOK_CONHOSTV2)
	_E("ShouldUseConhostV2"),
#endif
{ NULL, NULL }
};
#endif
#ifdef TARGET_WIN11
static REGKEY_PAIR m_aSymsCONHOSTV1[] =
{
	_E("InitializeCustomCP"),
	{ NULL, NULL }
};
#endif
#ifdef NEED_APPINFO
static REGKEY_PAIR m_aSymsAPPINFO[] =
{
	_E("AiOpenWOWStubs"),
	{ NULL, NULL }
};
#endif
#ifdef USE_MAP0DRV
static REGKEY_PAIR m_aSymsNTOSKRNL[] =
{
	_E("MiAllocateVad"),
	_E("MiInsertVadCharges"),
	_E("MiInsertVad"),
	_E("MiInsertPrivateVad"),
	{ NULL, NULL }
};
#endif
#ifdef METHOD_HOOKLDR
static REGKEY_PAIR m_aSymsNTDLL[] =
{
	_E("LdrpInitializeProcess"),
	{ NULL, NULL }
};
#endif
#undef _E

#ifdef _WIN64
REGKEY_SYMS g_aSyms64[] = {
#else
REGKEY_SYMS g_aSyms32[] = {
#endif
{ "kernel32.dll", L"kernel32.dll", m_aSymsKERNEL32, FALSE },
#if defined(_WIN64) && !defined(TARGET_WINXP) && (defined(TARGET_WIN7) || defined(HOOK_CONHOSTV2)) // consbmp.c fix
{ "conhost.exe", L"conhost.exe", m_aSymsCONHOST, FALSE },
#endif
#if defined(TARGET_WIN11) && defined(_WIN64)
{ "conhostV1.dll", L"conhostV1.dll", m_aSymsCONHOSTV1, FALSE },
#endif
#ifdef NEED_APPINFO
{ "appinfo.dll", L"appinfo.dll", m_aSymsAPPINFO, FALSE },
#endif
#ifdef USE_MAP0DRV
// NB: Assume that we are on Win 8 or above where there aren't any different kernels anymore, just ntoskrnl.exe, otherwise, this won't work!
{ "ntoskrnl.exe", L"ntoskrnl.exe", m_aSymsNTOSKRNL, TRUE },
#endif
#ifdef METHOD_HOOKLDR
{ "ntdll.dll", L"ntdll.dll", m_aSymsNTDLL, FALSE },
#endif
};


