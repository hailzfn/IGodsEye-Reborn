#pragma once

#include "stdafx.h"

class Bone
{
public:
	static uint64_t* getDecryptionKeys();
	static void* get();
private:
	static uint64_t keys[16][4];
};
