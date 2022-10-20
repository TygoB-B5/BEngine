#pragma once
#include "bepch.h"

namespace BEngine
{

	class FileReader
	{
	public:
		static std::string ReadFile(const std::string& filepath);
	};

	class FileWriter
	{
	public:
		static void WriteFile(const std::string& filepath, const std::string& data);
	};
}