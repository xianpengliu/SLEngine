#include "stdafx.h"
#include "Log.h"

namespace SL
{
	void Log::log(const std::string& str)
	{
		std::cout << "Log::log => " << str << std::endl;
	}

	void Log::info(const std::string& str)
	{
		std::cout << "Log::info => " << str << std::endl;
	}
}

