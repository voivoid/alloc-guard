#pragma once

#include <crtdbg.h>

class AllocGuard
{
public:
	AllocGuard() : prev_hook( _CrtSetAllocHook( &alloc_hook ) )
	{
	}

	~AllocGuard()
	{
		_CrtSetAllocHook( prev_hook );
	}

private:
	static int alloc_hook( const int allocType,
		                   void* const /*userData*/,
		                   const size_t /*size*/,
		                   const int /*blockType*/,
		                   const long /*requestNumber*/,
		                   const unsigned char* const /*filename*/,
		                   const int /*lineNumber*/ )
	{
		if (allocType == _HOOK_ALLOC || allocType == _HOOK_REALLOC)
		{
			throw;
		}
		return 1;
	}

private:
	_CRT_ALLOC_HOOK prev_hook;
};