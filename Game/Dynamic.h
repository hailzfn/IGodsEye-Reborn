#pragma once
#include <stdint.h>

namespace Dynamic
{
	enum class Game : uintptr_t
	{
		Loaded = 0xfa1ff70,
	};

	enum class D3D12 : uintptr_t
	{
		SwapChain = 0x126a1598,
		CommandQueue = 0x1269c228,
	};

	enum class Functions : uintptr_t
	{
		G_RunFrame = 0x16cf2e0,
		ExecuteSingleCommand = 0x1755cd0,
		Dvar_FindMalleableVar = 0x1930720,
		Dvar_FindVar = 0x1930800,
	};

	namespace Cryptography
	{
		enum class Client : uintptr_t
		{
			Encrypted = 0x10d18b08,
			DynamicKey = 0x3b5f2f1,
			DynamicKeyOffset = 0xb,
		};

		enum class ClientKeys : uint64_t
		{
			Key0 = 0xB85FEB87B2ED98A5,
			Key1 = 0xDAA241F44A5F67EF,
			Key2 = 0x1609193EACCF4F77,
		};

		enum class CEntity : uintptr_t
		{
			Encrypted = 0x10d177d8,
			DynamicKey = 0x3b5f25d,
			DynamicKeyOffset = 0x15,
		};

		enum class Bone : uintptr_t
		{
			Encrypted = 0x0,
			DynamicKey = 0x0,
			DynamicKeyOffset = 0x11,
		};
	}

	enum class Camera : uintptr_t
	{
		RefDef = 0x10d1b3c0,
	};

	enum class Character : uintptr_t
	{
		NameArray = 0x10d26078,
		NameOffset = 0x4c70,
	};

	enum class CEntity : uintptr_t
	{
		OriginFunction = 0x57C4B48,
	};
}
