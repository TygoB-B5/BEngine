#include "FileReader.h"
#include "Core.h"

namespace BEngine
{
	std::string FileReader::OpenFile(const std::string& filepath)
	{
		// Create filestream and attempt to open file.
		std::fstream myFile;
		myFile.open(filepath, std::ios::in | std::ios::binary);

		BE_ASSERT(myFile, "Could not find file in directory: " + filepath)

		// Create string buffer to read from.
		std::stringstream buffer;
		buffer << myFile.rdbuf();

		// Close the file and free its memory.
		myFile.close();

		// Return a string from the buffer.
		return buffer.str();
	}
}