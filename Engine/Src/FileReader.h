#pragma once
#include "bepch.h"

namespace BEngine
{

	class FileReader
	{
	public:
		static std::string OpenFile(const std::string& filepath);
	};

}