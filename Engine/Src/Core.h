#pragma once

#ifdef BENGINE_EXPORT
#define BENGINE_API __declspec(dllexport)
#else
#define BENGINE_API __declspec(dllimport)
#endif
