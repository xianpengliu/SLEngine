#pragma once

#include "stdafx.h"

namespace SL
{
	class Log
	{
	public:
		static void log(const std::string& str);
		static void info(const std::string& str);
	};
}
