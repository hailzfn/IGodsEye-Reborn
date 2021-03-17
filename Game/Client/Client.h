#pragma once

#include "stdafx.h"
#include "Game\Client\Local\Local.h"
#include "Game\Client\CharacterInfo\characterInfo_t.h"

class Client
{
public:
	static Client* get();
	static uint64_t* getDecryptionKeys();
	characterInfo_t* getCharacterInfo(int characterIndex);
	characterInfo_t* getLocalCharacterInfo();
public:
	unsigned __int8 unk1[0x84848];          // 0x00
	Local* local;                           // 0x84848
	unsigned __int8 unk2[0x12F08];          // 0x84850
	characterInfo_t (*characterInfos)[155]; // 0x97758
private:
	static uint64_t keys[4];
};
