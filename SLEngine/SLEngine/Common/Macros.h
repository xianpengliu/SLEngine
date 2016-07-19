#pragma once

#include "stdafx.h"

// namespace
#define NS_SL_BEGIN                     namespace SL {
#define NS_SL_END                       }
#define USING_NS_SL                     using namespace SL
#define NS_SL                           ::SL

// ref
#define CC_SAFE_DELETE(p)				do { delete (p); (p) = nullptr; } while(0)
#define CC_SAFE_DELETE_ARRAY(p)			do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#define CC_SAFE_FREE(p)					do { if(p) { free(p); (p) = nullptr; } } while(0)
#define CC_SAFE_RELEASE(p)				do { if(p) { (p)->release(); } } while(0)
#define CC_SAFE_RELEASE_NULL(p)			do { if(p) { (p)->release(); (p) = nullptr; } } while(0)
#define CC_SAFE_RETAIN(p)				do { if(p) { (p)->retain(); } } while(0)

// log
#if !defined(_DEBUG) || _DEBUG == 0

#define LOG(...)       do {} while (0)
#define LOGINFO(...)   do {} while (0)
#define LOGERROR(...)  do {} while (0)

#elif _DEBUG == 1

#define LOG(...)       SL::Log::log(##__VA_ARGS__)
#define LOGERROR(...)  SL::Log::log(##__VA_ARGS__)
#define LOGINFO(...)   do {} while (0)

#endif