#pragma once
#include "includes.h"
#include <unordered_set>

class Player
{
	enum GuiState : std::uint8_t
	{
		NONE = 0,
		MENU = 1,
		ALIVE = 2,
		DEAD = 3,
		SPEC = 6,
		LIMBO = 8,
		LOADING = 10
	};

public:
	char pad_0000[176]; //0x0000
	char Name[8]; //0x00B0
	char pad_00B8[1072]; //0x00B8
	uint8_t GuiState; //0x04E8
	char pad_04E9[551]; //0x04E9
	class Unit* ControlledUnit; //0x0710

	bool IsAlive() const noexcept
	{
		return GuiState == GuiState::ALIVE;
	}

	bool IsDead() const noexcept
	{
		return GuiState == GuiState::DEAD;
	}

	bool IsinHangar() const noexcept
	{
		return GuiState == GuiState::MENU;
	}
};


class Unit
{
public:
	char pad_0000[520]; //0x0000
	Vector3 BBMin; //0x0208
	Vector3 BBMax; //0x0214
	char pad_0220[1256]; //0x0220
	uint8_t ReloadTimer; //0x0708
	char pad_0709[699]; //0x0709
	Matrix3x3 RotationMatrix; //0x09C4
	Vector3 Position; //0x09E8
	char pad_09F4[1424]; //0x09F4
	float Invulnerable; //0x0F84
	char pad_0F88[256]; //0x0F88
	uint8_t UnitState; //0x1088
	char pad_1089[15]; //0x1089
	class Player* PlayerInfo; //0x1098
	char pad_10A0[64]; //0x10A0
	uint8_t TeamNum; //0x10E0
	char pad_10E1[15]; //0x10E1
	class Info* UnitInfo; //0x10F0
}; //Size: 0x10F8


class HUD
{
public:
	char pad_0000[641]; //0x0000
	bool air_to_air_indicator;
	char pad_0282[10]; //0x0282
	bool penetration_crosshair; //0x028C
	bool unit_glow; //0x028D
	bool gunner_sight_distance; //0x028E
	char pad_028F[69]; //0x028F
	bool show_bombsight; //0x02D4
};	

class Armory
{
public:
	char pad_0000[144]; //0x0000
	class WeaponPositionInfo* WeaponPositionInfo; //0x0090
	int64_t WeaponPositionInfoCount; //0x0098
	char pad_00A0[344]; //0x00A0
	class ControllableWeapon* ControllableWeapons; //0x01F8
	int64_t ControllableWeaponCount; //0x0200
	char pad_0208[400]; //0x0208
	class Weapon** Weapons; //0x0398
	int64_t WeaponCount; //0x03A0
}; //Size: 0x03A8


class WeaponPositionInfo
{
public:
	class WeaponPositionInfoInternal* InternalInfo; //0x0000
	char pad_0008[604]; //0x0008
	Vector3 Position; //0x0264
	char pad_0270[88]; //0x0270
	int32_t Padding; //0x02C8
}; //Size: 0x02CC


class ControllableWeapon
{
public:
	char pad_0000[8]; //0x0000
	class Weapon* WeaponPtr; //0x0008
	char pad_0010[72]; //0x0010
	Vector2 Rotation; //0x0058
	char pad_0060[122]; //0x0060
	int16_t ParentIndex; //0x00DA
	char pad_00DC[2]; //0x00DC
	bool UseParentPitch; //0x00DE
	char pad_00DF[425]; //0x00DF
	int32_t Padding; //0x0288
}; //Size: 0x0490


class Weapon
{
public:
	char pad_0000[36]; //0x0000
	int16_t ControllableWeaponIndex; //0x0024
	char pad_0026[106]; //0x0026
	Vector3 Forward; //0x0090
	Vector3 Up; //0x009C
	Vector3 Left; //0x00A8
}; //Size: 0x0894


class WeaponPositionInfoInternal
{
public:
	char pad_0000[52]; //0x0000
	Vector3 Position; //0x0034
	char pad_0040[92]; //0x0040
	Vector3 YawPivotPosition; //0x009C
	char pad_00A8[92]; //0x00A8
	Vector3 PitchPivotPosition; //0x0104
};

//class UnitWeapons
//{
//public:
//	char pad_0000[856]; //0x0000
//	class WeaponArray* WeaponArray; //0x0358
//	int64_t WeaponCount; //0x0360
//}; //Size: 0x0368
//static_assert(sizeof(UnitWeapons) == 0x368);
//
//class WeaponArray
//{
//public:
//	class Weapon* Weapon; //0x0000
//	char pad_0008[16]; //0x0008
//}; //Size: 0x0018
//static_assert(sizeof(WeaponArray) == 0x18);

//class Weapon
//{
//public:
//	char pad_0000[124]; //0x0000
//	Vector3 weaponBBMin; //0x007C
//	char pad_0088[36]; //0x0088
//	Vector3 weaponBBMax; //0x00AC
//	Matrix3x3 Turret_X_Rotation; //0x00B8
//	char pad_00DC[12]; //0x00DC
//	Matrix3x3 Turret_Y_Rotation; //0x00E8
//	char pad_010C[364]; //0x010C
//	class WeaponInfo* WeaponInfo; //0x0278
//	char pad_0280[604]; //0x0280
//	uint8_t CurrentSlot; //0x04DC
//	char pad_04DD[67]; //0x04DD
//	Vector3 Position; //0x0520
//}; //Size: 0x052C
//class Weapon
//{
//public:
//	char pad_0000[124]; //0x0000
//	Vector3 BBMin; //0x007C
//	char pad_0088[36]; //0x0088
//	Vector3 BBMax; //0x00AC
//	char pad_00B8[4]; //0x00B8
//	Matrix3x3 RotMatixY; //0x00BC
//	char pad_00E0[12]; //0x00E0
//	Matrix3x3 RotMatixX; //0x00EC
//	char pad_0110[12]; //0x0110
//	Matrix3x3 RotMatrixZ; //0x011C
//	char pad_0140[312]; //0x0140
//	class WeaponInfo* WeaponInfo; //0x0278
//	char pad_0280[604]; //0x0280
//	uint8_t CurrentSlot; //0x04DC
//	char pad_04DD[31]; //0x04DD
//	Matrix3x3 Rotationmatrix; //0x04FC
//	Vector3 Position; //0x0520
//}; //Size: 0x052C
//class Weapon
//{
//public:
//	char pad_0000[128]; //0x0000
//	Vector3 BBMin; //0x0080
//	char pad_008C[36]; //0x008C
//	Vector3 BBMax; //0x00B0
//	Matrix3x3 RotMatixY; //0x00BC
//	char pad_00E0[12]; //0x00E0
//	Matrix3x3 RotMatixX; //0x00EC
//	char pad_0110[12]; //0x0110
//	Matrix3x3 RotMatrixZ; //0x011C
//	char pad_0140[312]; //0x0140
//	class WeaponInfo* WeaponInfo; //0x0278
//	char pad_0280[604]; //0x0280
//	uint8_t CurrentSlot; //0x04DC
//	char pad_04DD[67]; //0x04DD
//	Vector3 Position; //0x0520
//};


//class WeaponInfo
//{
//public:
//	char pad_0000[168]; //0x0000 
//	class AmmoInfo* AmmoInfo; //0x00A8 (A8 + d8)
//	char pad_00B0[336]; //0x00B0
//}; //Size: 0x0200
//static_assert(sizeof(WeaponInfo) == 0x200);
//
//class AmmoInfo
//{
//public:
//	char pad_0000[12]; //0x0000
//	float mass; //0x000C
//	float Caliber; //0x0010
//	float Lenght; //0x0014
//	float Distance; //0x0018
//	char pad_001C[28]; //0x001C
//	float Speed; //0x0038
//	char pad_003C[140]; //0x003C
//}; //Size: 0x00C8
//static_assert(sizeof(AmmoInfo) == 0xC8);
//
//
//
//
//class Moving
//{
//public:
//	char pad_0000[84]; //0x0000
//	Vector3 Velocity; //0x0054
//	char pad_0060[48]; //0x0060
//}; //Size: 0x0090




class Info
{
public:
	char* unitName; //0x0000
	char* modelName; //0x0008
	char* modelPath; //0x0010
	char* FullName; //0x0018
	char* ShortName; //0x0020
	char pad_0028[8]; //0x0028
	char* unitType; //0x0030
	char pad_0038[428]; //0x0038
	float ZoomMulti; //0x01E4
	float AlternateMulti; //0x01E8
	char pad_01EC[16]; //0x01EC
	float ShadowMulti; //0x01FC

	bool isPlane() {
		return (strcmp(unitType, "exp_bomber") == 0 || strcmp(unitType, "exp_assault") == 0 || strcmp(unitType, "exp_fighter") == 0);
	}
	bool isDummy() {
		return (strcmp(unitType, "exp_fortification") == 0 || strcmp(unitType, "exp_structure") == 0 || strcmp(unitType, "exp_aaa") == 0 || strcmp(unitType, "dummy_plane") == 0 || strcmp(unitType, "exp_bridge") == 0);
	}
};

class EntList {
public:
	Player* players[64];
};

class Units{
public:
	std::array<Unit*, 500U> units;
};

class UnitList{
public:
	Units* unitList;
	std::uint16_t unitCount;
};