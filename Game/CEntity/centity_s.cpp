//centity_s.cpp
#include "centity_s.h"
#include "Application.h"
#include "Game\Cryptography\Cryptography.h"

uint64_t centity_s::keys[16][4];

uint64_t* centity_s::getDecryptionKeys()
{
	if (centity_s::keys[0][0] != 0)
		return (uint64_t*)centity_s::keys;

	// Get dynamic key from memory
	uintptr_t reversed = *(uintptr_t*)(Application::BaseAddress + (uintptr_t)Dynamic::Cryptography::CEntity::DynamicKey);
	uintptr_t address = _byteswap_uint64(reversed);

#ifdef _DEBUG_ADDRESSES
	std::cout << "Dynamic Entity Encryption Key Address: " << std::hex << address << std::endl;
#endif

	uint64_t dynamicKey = *(uint64_t*)(address + (uintptr_t)Dynamic::Cryptography::CEntity::DynamicKeyOffset);

#ifdef _DEBUG_ADDRESSES
	std::cout << "Dynamic Entity Encryption Key: " << std::hex << dynamicKey << std::endl;
#endif

	centity_s::keys[0][0] = 0x45C6BDFC1F2084B3;
	centity_s::keys[0][1] = dynamicKey;
	centity_s::keys[0][2] = 0x0367AFBFA282CFA5;
	centity_s::keys[0][3] = 0x3710CAD438514C0B;

	centity_s::keys[1][0] = 0x718FA97FC4F44521;
	centity_s::keys[1][1] = 0xCED2A944038A06D1;
	centity_s::keys[1][2] = 0xC92E230315FB2095;
	centity_s::keys[1][3] = dynamicKey;

	centity_s::keys[2][0] = 0x4B3A521AE7E8426B;
	centity_s::keys[2][1] = 0x13C9E711217EA8FD;
	centity_s::keys[2][2] = dynamicKey;
	centity_s::keys[2][3] = 0x968E5536FDF49493;

	centity_s::keys[3][0] = dynamicKey;
	centity_s::keys[3][1] = 0x082057E23E7FDC3F;
	centity_s::keys[3][2] = 0xF8016FD75E797E9F;
	centity_s::keys[3][3] = 0xD673E8AC4B075799;

	centity_s::keys[4][0] = 0x286054CC37040359;
	centity_s::keys[4][1] = dynamicKey;
	centity_s::keys[4][2] = 0x897A4AB5F1DFFDE3;
	centity_s::keys[4][3] = 0x0C703E31BC186773;

	centity_s::keys[5][0] = 0x054E4F26523DE935;
	centity_s::keys[5][1] = dynamicKey;
	centity_s::keys[5][2] = 0x7E631A21F6A106C7;
	centity_s::keys[5][3] = 0x4F3F80F0D550A5F5;

	centity_s::keys[6][0] = 0x9DAFBF6EAAB6D7D5;
	centity_s::keys[6][1] = 0xA8EBDE5BC8970AA5;
	centity_s::keys[6][2] = 0x6B484B155FE30815;
	centity_s::keys[6][3] = dynamicKey;

	centity_s::keys[7][0] = 0x65A033C2D920B6F7;
	centity_s::keys[7][1] = 0xFB772F40D930FF93;
	centity_s::keys[7][2] = 0xDDD8B81BE5F22F6F;
	centity_s::keys[7][3] = dynamicKey;

	centity_s::keys[8][0] = 0x3DC53D7A329B81F9;
	centity_s::keys[8][1] = 0x54FDE2F495661BA9;
	centity_s::keys[8][2] = dynamicKey;
	centity_s::keys[8][3] = 0x37B2775BE323F279;

	centity_s::keys[9][0] = 0x9E62D6B08467961D;
	centity_s::keys[9][1] = 0x3B1A22D1DF575249;
	centity_s::keys[9][2] = 0x2BDFB5EC8F0FD701;
	centity_s::keys[9][3] = dynamicKey;

	centity_s::keys[10][0] = 0x2CAE9715B768AFEF;
	centity_s::keys[10][1] = dynamicKey;
	centity_s::keys[10][2] = 0x17F1FA2F50CA2317;
	centity_s::keys[10][3] = 0xE78101313EFB68E3;

	centity_s::keys[11][0] = 0xAB82D8DA52434295;
	centity_s::keys[11][1] = dynamicKey;
	centity_s::keys[11][2] = 0xE1C6CDC207C467EB;
	centity_s::keys[11][3] = 0x58213A89C53215CB;

	centity_s::keys[12][0] = dynamicKey;
	centity_s::keys[12][1] = 0xD2D2039BC0AF71C5;
	centity_s::keys[12][2] = 0xBE979F03FB5FBF87;
	centity_s::keys[12][3] = 0xA3104A56524B211D;

	centity_s::keys[13][0] = 0x7A43B09EBD8B4989;
	centity_s::keys[13][1] = 0xE43EF4763960837B;
	centity_s::keys[13][2] = 0xEB177541A29D6357;
	centity_s::keys[13][3] = dynamicKey;

	centity_s::keys[14][0] = dynamicKey;
	centity_s::keys[14][1] = 0x9EA2FC43F4CE6213;
	centity_s::keys[14][2] = 0x864581F23879B639;
	centity_s::keys[14][3] = 0xCA2E6CAA9EFEB48D;

	centity_s::keys[15][0] = 0x61174109A98FE5C1;
	centity_s::keys[15][1] = 0x3A64E3B362674BCD;
	centity_s::keys[15][2] = dynamicKey;
	centity_s::keys[15][3] = 0x543396A93B1934FD;

	return (uint64_t*)centity_s::keys;
}

centity_s* centity_s::get()
{
	uint64_t* keys = centity_s::getDecryptionKeys();

	uintptr_t encryptedAddress = *(uintptr_t*)(Application::BaseAddress + (uintptr_t)Dynamic::Cryptography::CEntity::Encrypted);
	encryptedAddress = *(uintptr_t*)(encryptedAddress + 0x10);

#ifdef _DEBUG_ADDRESSES
	std::cout << "Encrypted Entity Address: " << std::hex << encryptedAddress << std::endl;
#endif

#ifdef _DEBUG_ADDRESSES
	std::cout << "Peb Index: " << std::dec << Application::game->pebIndex << std::endl;
#endif
	return (centity_s*)Cryptography::decrypt(encryptedAddress, &keys[Application::game->pebIndex << 2]);
}

centity_s* centity_s::get(int index)
{
	return &(centity_s::get()[index]);
}

bool centity_s::isValid()
{
	return this->infoValid & 1;
}

bool centity_s::isStance(EntityStance stance)
{
	return ((int16_t)this->stance & (int16_t)stance) == (int16_t)stance;
}

bool centity_s::isStanding()
{
	return this->isStance(EntityStance::Standing);
}

bool centity_s::isCrouching()
{
	return this->isStance(EntityStance::Crouching);
}

bool centity_s::isCrawling()
{
	return this->isStance(EntityStance::Crawling);
}

bool centity_s::isDowned()
{
	return this->isStance(EntityStance::Downed);
}

Vector3 centity_s::getOrigin()
{
	// 74 3F 0F 57 C0 0F 57 C9 F2 0F 2A 45 C7 F2 0F 2A 4D CB
	using GetDecryptedPos_t = void(__stdcall*)(uintptr_t, Vector3*);
	static GetDecryptedPos_t GetDecryptedPos_fn = nullptr;

	auto originFunction = (*(uint32_t*)(Application::BaseAddress + (uintptr_t)Dynamic::CEntity::OriginFunction) ^ (this->originXor1) ^ *(uint64_t*)(this->originXor2));

	if (!Application::isValidPointer(originFunction))
		return Vector3();

	static fGetEntityOrigin GetEntityOrigin = (fGetEntityOrigin)(originFunction);

	Vector3 origin;
	GetEntityOrigin(this->originFunc, &origin);
	return origin;
}
