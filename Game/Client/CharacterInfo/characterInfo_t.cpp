//characterInfo_t.cpp
#include "characterInfo_t.h"
#include "Application.h"

bool characterInfo_t::isValid()
{
	return this->infoValid == 1;
}

std::string characterInfo_t::getName()
{
	uintptr_t address = *(uintptr_t*)(Application::BaseAddress + (uintptr_t)Dynamic::Character::NameArray);
	#ifdef _DEBUG_ADDRESSES
		static bool printedName = false;
		if (!printedName)
		{
			std::cout << "Character Name Address: " << std::hex << address << std::endl;
			printedName = true;
		}
	#endif

	address += (uintptr_t)Dynamic::Character::NameOffset;
	address += ((this->entityNum + (this->entityNum * 8)) << 0x4);
	address += 0x04;
	return std::string((char*)address);
}

centity_s* characterInfo_t::getEntity()
{
	return centity_s::get(this->entityNum);
}
