//Bone.cpp
#include "Bone.h"
#include "Application.h"
#include "Game\Cryptography\Cryptography.h"

uint64_t Bone::keys[16][4];

uint64_t* Bone::getDecryptionKeys()
{
	if (Bone::keys[0][0] != 0)
		return (uint64_t*)Bone::keys;

	// Get dynamic key from memory
	uintptr_t reversed = *(uintptr_t*)(Application::BaseAddress + (uintptr_t)Dynamic::Cryptography::Bone::DynamicKey);
	uintptr_t address = _byteswap_uint64(reversed);

	#ifdef _DEBUG_ADDRESSES
	std::cout << "Dynamic Bone Encryption Key Address: " << std::hex << address << std::endl;
	#endif

	uint64_t dynamicKey = *(uint64_t*)(address + (uintptr_t)Dynamic::Cryptography::Bone::DynamicKeyOffset);

	#ifdef _DEBUG_ADDRESSES
	std::cout << "Dynamic Bone Encryption Key: " << std::hex << dynamicKey << std::endl;
	#endif

	Bone::keys[0][0] = dynamicKey;
	Bone::keys[0][1] = 0x61AA8B28A7A30259;
	Bone::keys[0][2] = 0x35B5E45D206EAAC9;
	Bone::keys[0][3] = 0x119C633FAC7FCF23;

	Bone::keys[1][0] = 0xA8C11F199EC13A93;
	Bone::keys[1][1] = 0xF5F7638CFDC55167;
	Bone::keys[1][2] = dynamicKey;
	Bone::keys[1][3] = 0x721A718D1187ACC1;

	Bone::keys[2][0] = 0xD6E159CA89334543;
	Bone::keys[2][1] = 0x681848CCF5E96245;
	Bone::keys[2][2] = 0x9105C56E0CFF108B;
	Bone::keys[2][3] = dynamicKey;

	Bone::keys[3][0] = 0x3863F4F755A9A649;
	Bone::keys[3][1] = 0xE54D86D1FA0589FF;
	Bone::keys[3][2] = 0x7F8A7C361FF2C5CD;
	Bone::keys[3][3] = dynamicKey;

	Bone::keys[4][0] = 0x2967AAD12E4DA16F;
	Bone::keys[4][1] = 0xCDFE137DE9DA8301;
	Bone::keys[4][2] = dynamicKey;
	Bone::keys[4][3] = 0x24810CE58CF6C6B9;

	Bone::keys[5][0] = dynamicKey;
	Bone::keys[5][1] = 0x67F12EEDD9D39761;
	Bone::keys[5][2] = 0x08DE19AEBDD59B05;
	Bone::keys[5][3] = 0xEC6A93961FA8F873;

	Bone::keys[6][0] = 0x4438780597A94EEB;
	Bone::keys[6][1] = 0x3BBE8809CC3F72B7;
	Bone::keys[6][2] = 0x38FA51EB7FCBBC7D;
	Bone::keys[6][3] = dynamicKey;

	Bone::keys[7][0] = 0xE9D49B3D01305049;
	Bone::keys[7][1] = dynamicKey;
	Bone::keys[7][2] = 0xE0B927FAB7309C53;
	Bone::keys[7][3] = 0x04290267B5BAC5D1;

	Bone::keys[8][0] = dynamicKey;
	Bone::keys[8][1] = 0xD6D52C022C2A37CB;
	Bone::keys[8][2] = 0xDA1A7E4CD0296B33;
	Bone::keys[8][3] = 0x22311B9FC00F86A5;

	Bone::keys[9][0] = dynamicKey;
	Bone::keys[9][1] = 0x1F405F6BC4A18F7B;
	Bone::keys[9][2] = 0x440487E07F33056D;
	Bone::keys[9][3] = 0xCF454162AF401AA7;

	Bone::keys[10][0] = 0x9692A2C685432063;
	Bone::keys[10][1] = dynamicKey;
	Bone::keys[10][2] = 0xF3E2E9B91A7590F5;
	Bone::keys[10][3] = 0x9EDF8EC9C74A2AF9;

	Bone::keys[11][0] = dynamicKey;
	Bone::keys[11][1] = 0x47A96F1C16B2D603;
	Bone::keys[11][2] = 0x3316FEFB81DE7E15;
	Bone::keys[11][3] = 0xD19BB23E00DDBFB1;

	Bone::keys[12][0] = 0xA1400526A672B559;
	Bone::keys[12][1] = 0xBB09A69CDEB21043;
	Bone::keys[12][2] = dynamicKey;
	Bone::keys[12][3] = 0x930D91FC6E7543E5;

	Bone::keys[13][0] = 0x974A86EC51BACEBF;
	Bone::keys[13][1] = 0x0C6B3E501683CD73;
	Bone::keys[13][2] = 0x345EEF4342246AA5;
	Bone::keys[13][3] = dynamicKey;

	Bone::keys[14][0] = 0xE3CA5216652BC011;
	Bone::keys[14][1] = dynamicKey;
	Bone::keys[14][2] = 0x81DA790D5164E9ED;
	Bone::keys[14][3] = 0x480E7B65008571CD;

	Bone::keys[15][0] = 0x8F37B450B13DF3FF;
	Bone::keys[15][1] = 0xDE18F71EED4D44AB;
	Bone::keys[15][2] = 0xD94E3A161B64D7D3;
	Bone::keys[15][3] = dynamicKey;

	return (uint64_t*)Bone::keys;
}

void* Bone::get()
{
	uint64_t* keys = centity_s::getDecryptionKeys();
	return nullptr;
}
