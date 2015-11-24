//#if (defined(WIN32) || defined(WIN64))
#ifdef INFSDKNET_EXPORTS

#ifndef INFSDK_API
#define INFSDK_API  __declspec(dllexport)
#endif

#else

#ifndef INFSDK_API
#define INFSDK_API  __declspec(dllimport)
#endif

#endif

#define CALLBACK __stdcall
#define STDCALL  __stdcall  //__cdecl

//#endif