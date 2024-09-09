#include <windows.h>
#include "skcrypt.h"

#define UWORLD 0x102F69D8
#define STATICFIND 0xDEC29C

#include "util.h"
#include "SDKclasses.h"
#include "lazy_importer.h"
#include "FKeys.h"
#include "SDKfuncs.h"

#define RPONT(base, offset) (Util::ReadMemory<void*>((PBYTE)base + offset))
#define mpe 3.14159265358979323846264338327950288419716939937510582f
void cup(void* skedmerx, void* robot);
bool genetic_2(uint64_t Object, void* HookFunction, void** HookOrig, DWORD Index);
//bool genetic_4(void* Object, void* HookFunction, void** HookOrig, DWORD Index);
void(*species)(void* skedmerx, void* robot);
//bool(*zamane)(void* aqqqoe, void* xxder, FVector eerora, bool sthe);
//void** lamp = nullptr;
void operamom();
void Prudentius(void* concern);
uintptr_t bendAddr = 0;
void* bend = nullptr;
void* retired = nullptr;
void* cumen = nullptr;
void* leaflet = nullptr;
void* funt = nullptr;
//void* sugar = nullptr;
//void* halt = nullptr;
int doubt = 0, solve = 0, curobt = 1, /*shetok = 1,*/ vance = 2, clrV = 2, clrI = 3, clrD = 4, comerl = 5, scwbone = 1, smgcwbone = 1, acwbone = 1, xepd = 250, skei = 1, curtab = 0, specia = 0/*, vfley = 0*/, bstel = 0/*, vfboost = 0*/, radeo = 1, ldstr = 0, lpckr = 0, PToggle = 0, MToggle = 1, bouksthikz = 3, poqex = 20, poqey = 30, poqes = 170, dutsiz = 2, scwsm = 5, acwsm = 5, smgcwsm = 5, scwfov = 500, smgcwfov = 500, acwfov = 500;
bool whore = false, pancak = false, skidu = true, /*radeo = true,*/ ezbtx = true, barh = true/*, saylnt = false*/, grozair = false, cwfov = false, cwsm = false, nbmde = true, cwbone = false, gump = true, dsklt = true, aatkn = true, cqchk = true, vcheq = true, vcheqclose = false, /*nezb = true,*/ buxx = true, plate = true, miniezp = true, klzz = true, gorner = true, lezp = true, lineezpaim = false;
uint8_t chosrar = uint8_t(EFortItemTier::II);
FVector2D vHeadBoneOut, vNeckBoneOut, pelvisOut, vUpperArmLeftOut, vUpperArmRightOut, vLeftHandOut, vRightHandOut, vLeftHandOut1, vRightHandOut1, vRightThighOut, vLeftThighOut, vRightCalfOut, vLeftCalfOut, vLeftLowCalfOut, vRightLowCalfOut, leftFeet2d, rightFeet2d, leftFoot2d, rightFoot2d, leftFeetFinger2d, rightFeetFinger2d;
//FVector manz;
//DWORD hotchockOffs;
//uint64_t hotchockRet;

bool checkMe()
{
	//set bend
	bend = Util::ReadMemory<void*>((PBYTE)bendAddr);
	if (!bend) return false;

	auto gameInstance = RPONT(bend, 0x1B8);
	if (!gameInstance) return false;

	auto localPlayers = RPONT(gameInstance, 0x38);
	if (!localPlayers) return false;

	leaflet = RPONT(localPlayers, 0);
	if (!leaflet) return false;

	//Set player contoller
	retired = RPONT(leaflet, 0x30);
	if (!retired) return false;

	//if (sugar) sugar = nullptr;
	//if (halt) halt = nullptr;

	if (PToggle && WasInputKeyJustPressed(retired, geyz::PToggle)) pancak = !pancak;

	if (pancak) return false;

	//Everything went well
	return true;
}

void ComeIn() {
	const char* usnm = "SZaLCbvy4KnvVpxGBpzQ";
	for (size_t i = 0; i < LI_FN(strlen).safe_cached()(usnm); i++)
	{
		if (usnm[i] != '~') {
			size_t sz = LI_FN(strlen).safe_cached()(pnlusrn);
			if (sz + 1 < 21)
			{
				pnlusrn[sz] = usnm[i];
				pnlusrn[sz + 1] = '\0';
			}
		}
	}

	//AllocConsole();
	//FILE* doodoo;
	//freopen_s(&doodoo, "CONOUT$", "w", stdout);
	//printf("\n\nKylo Debugging Enabled.\n");

	HMODULE ntdll = LI_FN(LoadLibraryA).safe_cached()(xMe("ntdll.dll"));

	MemCpy = (MemCpy_t)LI_FN(GetProcAddress).safe_cached()(ntdll, xMe("memcpy"));
	//MemMove = (MemMove_t)LI_FN(GetProcAddress).safe_cached()(ntdll, xMe("memmove"));
	//MemSet = (MemSet_t)LI_FN(GetProcAddress).safe_cached()(ntdll, xMe("memset"));

	auto gGameBase = (BYTE*)Util::imageBase();
	/*LI_FN(sprintf).safe_cached()(precede, xMe("ImageBase: 0x%X"), gGameBase);
	LI_FN(MessageBoxA).safe_cached()(0, precede, 0, 0);

	return;*/

	uintptr_t StaticFindObjectAddr = (uintptr_t)gGameBase + STATICFIND;
	StaticFindFirstObject_t = decltype(StaticFindFirstObject_t)(StaticFindObjectAddr);

	//uintptr_t LOSAddr = (uintptr_t)gGameBase + 0x23960000;
	//zamane = (decltype(zamane))LOSAddr;

	//funt = FindMyObject(xMe(L"Burbank:Burbank"));

	//LI_FN(sprintf).safe_cached()(precede, xMe("funt: 0x%X"), funt);
	//LI_FN(MessageBoxA).safe_cached()(0, precede, 0, 0);

	//return;
	//uintptr_t ProcessEventAddr = (uintptr_t)gGameBase + 0xDA1244;
	//ProcessEvent_t = decltype(ProcessEvent_t)(ProcessEventAddr);

	bendAddr = (uintptr_t)gGameBase + UWORLD;
	bend = Util::ReadMemory<void*>((PBYTE)bendAddr);

	//hotchockOffs = 0xF7;
	//hotchockRet = (uint64_t)gGameBase + 0x8CDF4CA;

	//result = FIND_PATTERN_IMAGE(gGameBase, "\x48\x8B\xC4\x48\x89\x58\x20\x55\x56\x57\x41\x54\x41\x55\x41\x56\x41\x57\x48\x8D\xA8\xCC\xCC\xCC\xCC\x48\x81\xEC\xCC\xCC\xCC\xCC\x0F\x29\x70\xB8\x0F\x29\x78\xA8\x44\x0F\x29\x40\xCC\x48\x8B\x05\xCC\xCC\xCC\xCC\x48\x33\xC4\x48\x89\x85\xCC\xCC\xCC\xCC\x45\x8A\xE9");
	//zamane = (decltype(zamane))result;

	//set bend
	if (!checkMe()) return;

	UINT8* gameViewport = Util::ReadMemory< UINT8* >((PBYTE)leaflet + 0x78);

	if (!gameViewport) return;

	genetic_2((uint64_t)gameViewport, cup, (void**)&species, 110);
}

//BOOL WINAPI entry_dll(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved) {
	if (dwReason == 1)
		ComeIn();

	return true;
}

typedef struct _stab {
	union {
		struct {
			double A, B, C;
			double D, E, F;
			double G, H, I;
			double J, K, L;
		};
		double m[4][3];
	};
} stab;

stab stabbing(FRotator rot)
{
	double radPitch = rot.Pitch * mpe / 180.f;
	double radYaw = rot.Yaw * mpe / 180.f;
	double radRoll = rot.Roll * mpe / 180.f;

	double SP = STATIC_Sin(radPitch);
	double CP = STATIC_Cos(radPitch);
	double SY = STATIC_Sin(radYaw);
	double CY = STATIC_Cos(radYaw);
	double SR = STATIC_Sin(radRoll);
	double CR = STATIC_Cos(radRoll);

	stab stabbing;
	stabbing.m[0][0] = CP * CY;
	stabbing.m[0][1] = CP * SY;
	stabbing.m[0][2] = SP;

	stabbing.m[1][0] = SR * SP * CY - CR * SY;
	stabbing.m[1][1] = SR * SP * SY + CR * CY;
	stabbing.m[1][2] = -SR * CP;

	stabbing.m[2][0] = -(CR * SP * CY + SR * SY);
	stabbing.m[2][1] = CY * SR - CR * SP * SY;
	stabbing.m[2][2] = CR * CP;

	return stabbing;
}

bool dpske(FVector bendloc)
{
	FRotator rot = GetCameraRotation(cumen);

	stab tempstabbing = stabbing(rot);

	FVector vAxisX = FVector(tempstabbing.m[0][0], tempstabbing.m[0][1], tempstabbing.m[0][2]);
	FVector vAxisY = FVector(tempstabbing.m[1][0], tempstabbing.m[1][1], tempstabbing.m[1][2]);
	FVector vAxisZ = FVector(tempstabbing.m[2][0], tempstabbing.m[2][1], tempstabbing.m[2][2]);

	FVector vDelta = bendloc - GetCameraLocation(cumen);
	FVector vTransformed = FVector(vDelta.Dot(vAxisY), vDelta.Dot(vAxisZ), vDelta.Dot(vAxisX));

	float fov_angle = GetFOVAngle(cumen);

	if (vTransformed.Z < 1.f || STATIC_Tan(fov_angle * (float)mpe / 360.f) == 0.f) return false;

	return true;
}

bool swing(void* concern, FVector realbendLocation, FVector2D* relfoxation) {
	auto relfox = K2_Project(concern, realbendLocation);

	if (!dpske(realbendLocation)) return false;

	*relfoxation = FVector2D(relfox.X, relfox.Y);

	return true;
}


void processSwing(void* concern, FVector realbendLocation, FVector2D* boneScreenLocation, double* minDistance, FVector* closestBoneScreenLocation, int cstmskei) {
	if (swing(concern, realbendLocation, boneScreenLocation)) {
		if (cstmskei == 4) {
			FVector2D offset = *boneScreenLocation - FVector2D(doubt / 2, solve / 2);
			double distance = STATIC_Sqrt(offset.X * offset.X + offset.Y * offset.Y);

			if (distance < *minDistance) {
				*minDistance = distance;
				*closestBoneScreenLocation = realbendLocation;
			}
		}
	}
}

FVector GetTheBone(void* mepr, int cstmskei) {
	if (cstmskei == 1) return GetSocketLocation(mepr, geyz::HeadName);
	else if (cstmskei == 2) return GetSocketLocation(mepr, geyz::NeckName);
	else if (cstmskei == 3) return GetSocketLocation(mepr, geyz::ChestName);
	else return GetSocketLocation(mepr, geyz::HeadName);
}

FVector GAB(void* Canvas, void* molpe, int cstmskei) {
	auto TopHeadBone = GetSocketLocation(molpe, geyz::HeadName);

	auto Pelvis = GetSocketLocation(molpe, geyz::PelvisName);
	auto NeckBone = GetSocketLocation(molpe, geyz::NeckName);
	auto Upperarm_l = GetSocketLocation(molpe, geyz::Upperarm_lName);
	auto Upperarm_r = GetSocketLocation(molpe, geyz::Upperarm_rName);
	auto Lowerarm_l = GetSocketLocation(molpe, geyz::Lowerarm_lName);
	auto Lowerarm_r = GetSocketLocation(molpe, geyz::Lowerarm_rName);
	auto Hand_l = GetSocketLocation(molpe, geyz::Hand_lName);
	auto Hand_r = GetSocketLocation(molpe, geyz::Hand_rName);
	auto Thigh_r = GetSocketLocation(molpe, geyz::Thigh_rName);
	auto Thigh_l = GetSocketLocation(molpe, geyz::Thigh_lName);
	auto Calf_r = GetSocketLocation(molpe, geyz::Calf_rName);
	auto Calf_l = GetSocketLocation(molpe, geyz::Calf_lName);
	auto LowerCalf_l = GetSocketLocation(molpe, geyz::LowerCalf_lName);
	auto LowerCalf_r = GetSocketLocation(molpe, geyz::LowerCalf_rName);
	auto Foot_r = GetSocketLocation(molpe, geyz::Foot_rName);
	auto Foot_l = GetSocketLocation(molpe, geyz::Foot_lName);
	auto Toe_r = GetSocketLocation(molpe, geyz::Toe_rName);
	auto Toe_l = GetSocketLocation(molpe, geyz::Toe_lName);

	double minDistance = 1000; // initialize to maximum double value
	FVector closes = GetTheBone(molpe, cstmskei);

	processSwing(Canvas, TopHeadBone, &vHeadBoneOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, NeckBone, &vNeckBoneOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Pelvis, &pelvisOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Upperarm_l, &vUpperArmLeftOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Upperarm_r, &vUpperArmRightOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Lowerarm_l, &vLeftHandOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Lowerarm_r, &vRightHandOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Hand_l, &vLeftHandOut1, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Hand_r, &vRightHandOut1, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Thigh_r, &vRightThighOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Thigh_l, &vLeftThighOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Calf_r, &vRightCalfOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Calf_l, &vLeftCalfOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, LowerCalf_l, &vLeftLowCalfOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, LowerCalf_r, &vRightLowCalfOut, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Foot_l, &leftFeet2d, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Foot_r, &rightFeet2d, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Toe_l, &leftFeetFinger2d, &minDistance, &closes, cstmskei);
	processSwing(Canvas, Toe_r, &rightFeetFinger2d, &minDistance, &closes, cstmskei);

	return closes;
}

void John(void* canvas, int x, int y, int radius, int numsides, FLinearColor color)
{
	double Step = mpe * 2.0 / numsides;
	int Count = 0;
	FVector2D V[128];
	for (double a = 0; a < mpe * 2.0; a += Step)
	{
		double X1 = (double)radius * STATIC_Cos(a) + (double)x;
		double Y1 = (double)radius * STATIC_Sin(a) + (double)y;
		double X2 = (double)radius * STATIC_Cos(a + Step) + (double)x;
		double Y2 = (double)radius * STATIC_Sin(a + Step) + (double)y;
		V[Count].X = X1;
		V[Count].Y = Y1;
		V[Count + 1].X = X2;
		V[Count + 1].Y = Y2;
		K2_DrawLine(canvas, FVector2D(V[Count].X, V[Count].Y), FVector2D(X2, Y2), 1.5f, color);
	}
}

FRotator poler(FVector zaz, FVector daz) {
	FVector dalte = zaz - daz;
	FRotator ongle;
	double hpm = STATIC_Sqrt(dalte.X * dalte.X + dalte.Y * dalte.Y);
	ongle.Yaw = STATIC_Atan(dalte.Y / dalte.X) * 57.295779513082f;
	ongle.Pitch = (STATIC_Atan(dalte.Z / hpm) * 57.295779513082f) * -1.f;
	if (dalte.X >= 0.f) ongle.Yaw += 180.f;
	return ongle;
}

bool isNotName(const wchar_t* plrname) {
	if (plrname[0] == 80 && plrname[1] == 108 && plrname[2] == 97 && plrname[3] == 121 && plrname[4] == 101 && plrname[5] == 114
		&& plrname[6] == 80 && plrname[7] == 97 && plrname[8] == 119 && plrname[9] == 110 && plrname[10] == 95)
		return true;

	else if (plrname[0] == 66 && plrname[1] == 80 && plrname[2] == 95 && plrname[3] == 80 && plrname[4] == 108 && plrname[5] == 97 && plrname[6] == 121 && plrname[7] == 101 && plrname[8] == 114
		&& plrname[9] == 80 && plrname[10] == 97 && plrname[11] == 119 && plrname[12] == 110 && plrname[13] == 95)
		return true;

	return false;
}

FRotator Zkeg(FRotator huha, FRotator endRotation, int cwsmComerl)
{
	FRotator ret = endRotation;

	ret.Pitch -= huha.Pitch;
	ret.Yaw -= huha.Yaw;

	//clamp
	if (ret.Yaw < -180.0f)
		ret.Yaw += 360.0f;

	if (ret.Yaw > 180.0f)
		ret.Yaw -= 360.0f;

	if (ret.Pitch < -74.0f)
		ret.Pitch = -74.0f;

	if (ret.Pitch > 74.0f)
		ret.Pitch = 74.0f;

	ret.Pitch = (ret.Pitch / cwsmComerl) + huha.Pitch;
	ret.Yaw = (ret.Yaw / cwsmComerl) + huha.Yaw;

	return ret;
}

//bool (*hotchock_t)(void*, FVector*, FRotator*) = nullptr;
//void hotchock(void* Controller, FVector* Location, FRotator* Rotation)
//{
//	hotchock_t(Controller, Location, Rotation);
//	/*
//	auto thurst = RPONT(sugar, 0x8f8);
//	if (!thurst) return;
//
//	auto LastFireAbilityTime = Util::ReadMemory<float>((PBYTE)thurst + 0xe28);
//	if (LastFireAbilityTime != otlb) {
//		printf("ret: 0x%X\n", (uint64_t)_ReturnAddress() - Util::imageBase());
//		otlb = LastFireAbilityTime;
//	}
//	*/
//	if (saylnt && halt) {
//		if ((uint64_t)_ReturnAddress() == hotchockRet) {
//			FVector ver = Util::ReadMemory<FVector>(Location);
//			FRotator vaze = poler(ver, manz);
//			Util::WriteMemory<FRotator>(Rotation, vaze);
//		}
//	}
//}

void DrawBoneLine(void* object, const struct FVector2D& ScreenPositionA, const struct FVector2D& ScreenPositionB, float Thickness, const struct FLinearColor& RenderColor, float& minX, float& maxX, float& minY, float& maxY)
{
	if (dsklt) K2_DrawLine(object, ScreenPositionA, ScreenPositionB, Thickness, RenderColor);

	minX = min((float)ScreenPositionA.X, minX);
	minX = min((float)ScreenPositionB.X, minX);

	maxX = max((float)ScreenPositionA.X, maxX);
	maxX = max((float)ScreenPositionB.X, maxX);

	minY = min((float)ScreenPositionA.Y, minY);
	minY = min((float)ScreenPositionB.Y, minY);

	maxY = max((float)ScreenPositionA.Y, maxY);
	maxY = max((float)ScreenPositionB.Y, maxY);
}

void LootESP(void* concern, void* sugar, FVector cpoe)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortniteGame:FortPickup"));

	TArray<void*> loot;
	STATIC_GetAllActorsOfClass(bend, fn, &loot);

	for (int i = 0; i < loot.Num(); i++)
	{
		auto Loot = loot[i];
		if (!Loot) continue;

		FVector sousouman = K2_GetActorLocation(Loot);
		FVector dazppe = FVector(cpoe.X - sousouman.X, cpoe.Y - sousouman.Y, cpoe.Z - sousouman.Z);
		double sakter = dazppe.X * dazppe.X + dazppe.Y * dazppe.Y + dazppe.Z * dazppe.Z;
		double diztan = STATIC_Sqrt(sakter) / 100;
		FVector2D serien;

		if (lpckr) {
			if (WasInputKeyJustPressed(retired, geyz::LPicker)) {
				ServerHandlePickup(sugar, Loot, 0.1f, FVector(), true);
			}
		}

		if (ldstr) {
			if (WasInputKeyJustPressed(retired, geyz::LDestroyer)) {
				FFortPickupRequestInfo aa;
				aa.FlyTime = 0.1f;
				aa.bIsVisualOnlyPickup = true;
				ServerHandlePickupInfo(sugar, Loot, aa);
			}
		}

		if (!skidu) continue;

		auto ItemDefinition = GetPrimaryItemDefinition(Loot);
		if (ItemDefinition) {
			FText DisplayName = Util::ReadMemory<FText>((PBYTE)ItemDefinition + 0x98);
			auto LootName = DisplayName.GetText();

			//get loot name
			if (!LootName) continue;
			auto isAmmo = LootName != NULL && STATIC_Contains(LootName, xMe(L"Ammo"), false, false);
			auto isBrick = LootName != NULL && STATIC_Contains(LootName, xMe(L"Brick"), false, false);
			auto isWood = LootName != NULL && STATIC_Contains(LootName, xMe(L"Wood"), false, false);
			auto isMetal = LootName != NULL && STATIC_Contains(LootName, xMe(L"Metal"), false, false);
			auto isStone = LootName != NULL && STATIC_Contains(LootName, xMe(L"Stone"), false, false);
			auto isGold = LootName != NULL && STATIC_Contains(LootName, xMe(L"Gold"), false, false);
			auto isBounty = LootName != NULL && STATIC_Contains(LootName, xMe(L"Bounty"), false, false);
			if (isAmmo || isBrick || isWood || isMetal || isStone || isGold || isBounty) continue;

			auto rarity = GetTier(ItemDefinition);
			if (rarity < EFortItemTier(chosrar)) continue;
			auto ItemColor = GetItemColor(rarity);

			auto mysoil = STATIC_Concat_StrStr(xMe(L"["), LootName);
			mysoil = STATIC_Concat_StrStr(mysoil, xMe(L" "));
			mysoil = STATIC_Concat_StrStr(mysoil, STATIC_Conv_IntToString((int)diztan));
			mysoil = STATIC_Concat_StrStr(mysoil, xMe(L"m]"));

			if (swing(concern, sousouman, &serien))
			{
				auto size = K2_TextSize(concern, funt, mysoil, FVector2D(0.50f, 0.50f));
				auto textLocation = FVector2D(serien.X - (size.X / 2), serien.Y);
				K2_DrawText(concern, funt, mysoil, textLocation, FVector2D(0.50f, 0.50f), ItemColor, 1.0f, FLinearColor(), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1));
			}
		}
	}
}

//bool isVisible(void* mesh)
//{
//	if (!mesh) return false;
//	float fLastSubmitTime = Util::ReadMemory<float>((PBYTE)mesh + 0x358); //lastSubmitTime = PrimitiveComponent.BoundsScale + 0x4
//	if (!fLastSubmitTime) return false;
//	float fLastRenderTimeOnScreen = Util::ReadMemory<float>((PBYTE)mesh + 0x35C); //lastSubmitTime + 0x4
//	if (!fLastRenderTimeOnScreen) return false;
//	const float fVisionTick = 0.06f;
//	bool bVisible = fLastRenderTimeOnScreen + fVisionTick >= fLastSubmitTime;
//	return bVisible;
//}

SpecialStruct GetColorFromOption(int num) {
	SpecialStruct skid;
	if (num == 1) {
		skid.name = STATIC_Concat_StrStr(xMe(L"S"), xMe(L"YN"));
		skid.color = FLinearColor(185, 160, 87, 1.0f);
	}
	else if (num == 2) {
		skid.name = STATIC_Concat_StrStr(xMe(L"C"), xMe(L"YAN"));
		skid.color = FLinearColor(3, 252, 252, 1.0f);
	}
	else if (num == 3) {
		skid.name = STATIC_Concat_StrStr(xMe(L"PURP"), xMe(L"LE"));
		skid.color = FLinearColor(169, 3, 252, 1.0f);
	}
	else if (num == 4) {
		skid.name = STATIC_Concat_StrStr(xMe(L"YEL"), xMe(L"LOW"));
		skid.color = FLinearColor(252, 235, 3, 1.0f);
	}
	else if (num == 5) {
		skid.name = STATIC_Concat_StrStr(xMe(L"GRE"), xMe(L"EN"));
		skid.color = FLinearColor(0, 255, 0, 1.0f);
	}
	else if (num == 6) {
		skid.name = STATIC_Concat_StrStr(xMe(L"RE"), xMe(L"D"));
		skid.color = FLinearColor(255, 0, 0, 1.0f);
	}
	return skid;
}

void cumin(void* concern) {
	if (!checkMe()) return;

	GetViewportSize(retired, &doubt, &solve);

	auto restoration = STATIC_GetFortPlayerPawns(bend);

	cumen = RPONT(retired, 0x340);

	auto cpoe = GetCameraLocation(cumen);

	auto quap = GetCameraRotation(cumen);

	auto sugar = K2_GetPawn(retired);

	double cbreakfastestDistance = 1000, cbrpelfastestDisterer = 1000, zepd = 111;
	void* Pothalt = NULL, * halt = NULL;
	FVector2D serien, breh, closestBreh, PotclosestBreh;
	FVector Potmanz, sousoumanz, manz;
	int viz = 0, tot = 0, cwsmComerl = comerl, cstmfuv = xepd, cstmskei = skei;

	if (sugar) {
		if ((cwsm || cwfov)) {
			auto CurrentWeapon = RPONT(sugar, 0x908);
			if (CurrentWeapon) {
				auto corr = STATIC_GetObjectName(CurrentWeapon);
				// shotguns
				if (corr.IsValid() && STATIC_Contains(corr, xMe(L"shotgun"), false, false)) {
					cwsmComerl = scwsm;
					cstmfuv = scwfov;
					cstmskei = scwbone;
				}
				// SMG
				else if (corr.IsValid() && STATIC_Contains(corr, xMe(L"smg"), false, false)) {
					cwsmComerl = smgcwsm;
					cstmfuv = smgcwfov;
					cstmskei = smgcwbone;
				}
				// ARs
				else if (corr.IsValid() && STATIC_Contains(corr, xMe(L"assault"), false, false)) {
					cwsmComerl = acwsm;
					cstmfuv = acwfov;
					cstmskei = acwbone;
				}
			}
		}

		//if (saylnt) genetic_4(retired, hotchock, (void**)&hotchock_t, hotchockOffs);

		if (lezp || lpckr || ldstr) {
			LootESP(concern, sugar, cpoe);
		}

		//if (vfley) {
		//	auto CurrentVehicle = RPONT(sugar, 0x2428);
		//	if (CurrentVehicle) {
		//		if (IsInputKeyDown(retired, geyz::FLKey)) { //forward
		//			float addition = 10.0f;
		//			if (IsInputKeyDown(retired, geyz::FLKeyBoost)) {
		//				addition = 80.0f;
		//			}
		//			ClientTeleportVehicleToLoc(CurrentVehicle, K2_GetActorLocation(CurrentVehicle) + GetActorForwardVector(CurrentVehicle) * addition);
		//			K2_SetActorRotation(CurrentVehicle, quap, true);
		//		}
		//	}
		//}

		/*if (bstel) {
			auto Building = GetTargetedBuilding(retired);
			if (Building) {
				FVector sousouman = K2_GetActorLocation(Building);
				FRotator sousoumanx = K2_GetActorRotation(Building);
				FVector dazppe = FVector(cpoe.X - sousouman.X, cpoe.Y - sousouman.Y, cpoe.Z - sousouman.Z);
				double sakter = dazppe.X * dazppe.X + dazppe.Y * dazppe.Y + dazppe.Z * dazppe.Z;
				double diztan = STATIC_Sqrt(sakter) / 100;

				if (swing(concern, sousouman, &serien))
				{
					if (WasInputKeyJustPressed(retired, geyz::WSteal)) {
						whore = !whore;
					}

					if (whore) {
						K2_DrawText(concern, funt, xMe(L"(Auto steal)"), serien, FVector2D(0.50f, 0.50f), FLinearColor(255, 0, 0, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1));

						FCreateBuildingActorData skid;
						skid.BuildLoc = sousouman;
						skid.BuildRot = sousoumanx;
						skid.bMirrored = true;
						skid.SyncKey = 0.1f;

						FBuildingClassData BuildingClassData;
						BuildingClassData.BuildingClass = Building;
						BuildingClassData.PreviousBuildingLevel = 0;
						BuildingClassData.UpgradeLevel = 1;

						skid.BuildingClassData = BuildingClassData;
						ServerCreateBuildingActor(retired, skid);
					}
					else
						K2_DrawText(concern, funt, xMe(L"(Press to steal)"), serien, FVector2D(0.50f, 0.50f), FLinearColor(255, 0, 0, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1));
				}
			}
		}*/
	}

	for (int i = 0; i < restoration.Num(); i++) {
		void* burial = restoration[i];
		if (!burial) continue;

		if (STATIC_OnSameTeam(sugar, burial)) continue;
		if (IsDead(burial)) continue;

		tot = tot + 1;
		auto mepr = RPONT(burial, 0x310);

		auto rooter = GetSocketLocation(mepr, geyz::RootName);

		auto sousouman = GetSocketLocation(mepr, geyz::NeckName);

		FVector dazppe = FVector(cpoe.X - sousouman.X, cpoe.Y - sousouman.Y, cpoe.Z - sousouman.Z);
		double sakter = dazppe.X * dazppe.X + dazppe.Y * dazppe.Y + dazppe.Z * dazppe.Z;

		double diztan = STATIC_Sqrt(sakter) / 100;

		//bool vender = vcheq ? zamane(retired, burial, FVector(), false) : true;
		//bool vender = vcheq ? isVisible(mepr) : true;
		//bool vender = vcheq ? STATIC_CheckLineOfSightToActorWithChannel(cpoe, burial, ECollisionChannel::ECC_Visibility, sugar) : true;

		sousoumanz = GAB(concern, mepr, cstmskei);

		bool vender = vcheq ? STATIC_CheckLineOfSightToActorWithChannel(sousoumanz, sugar, ECollisionChannel::ECC_Visibility, burial) : true;

		if (diztan < cbrpelfastestDisterer) {
			cbrpelfastestDisterer = diztan;
			if (diztan < 10) {
				if (gump) {
					zepd = 900;
				}
				if (vcheqclose) {
					vender = true;
				}
			}
		}

		if (vender) viz = viz + 1;
		//auto blce = vender ? FLinearColor(75, 201, 175, 1.f) : FLinearColor(185, 160, 87, 1.0f);
		auto blce = vender ? GetColorFromOption(clrV).color : GetColorFromOption(clrI).color;

		bool foxhunter = swing(concern, sousouman, &serien) && swing(concern, rooter, &breh);

		if (foxhunter) {
			auto burialDBNO = IsDBNO(burial);

			if (skidu) {//visuals toggle
				//if (burialDBNO) blce = FLinearColor(237, 255, 13, 1.0f);
				if (burialDBNO) blce = GetColorFromOption(clrD).color;

				float minX = FLT_MAX;
				float maxX = -FLT_MAX;
				float minY = FLT_MAX;
				float maxY = -FLT_MAX;

				DrawBoneLine(concern, FVector2D(vHeadBoneOut.X, vHeadBoneOut.Y), FVector2D(vNeckBoneOut.X, vNeckBoneOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(pelvisOut.X, pelvisOut.Y), FVector2D(vNeckBoneOut.X, vNeckBoneOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vUpperArmLeftOut.X, vUpperArmLeftOut.Y), FVector2D(vNeckBoneOut.X, vNeckBoneOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vUpperArmRightOut.X, vUpperArmRightOut.Y), FVector2D(vNeckBoneOut.X, vNeckBoneOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vLeftHandOut.X, vLeftHandOut.Y), FVector2D(vUpperArmLeftOut.X, vUpperArmLeftOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vRightHandOut.X, vRightHandOut.Y), FVector2D(vUpperArmRightOut.X, vUpperArmRightOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vLeftHandOut.X, vLeftHandOut.Y), FVector2D(vLeftHandOut1.X, vLeftHandOut1.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vRightHandOut.X, vRightHandOut.Y), FVector2D(vRightHandOut1.X, vRightHandOut1.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vLeftThighOut.X, vLeftThighOut.Y), FVector2D(pelvisOut.X, pelvisOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vRightThighOut.X, vRightThighOut.Y), FVector2D(pelvisOut.X, pelvisOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vLeftCalfOut.X, vLeftCalfOut.Y), FVector2D(vLeftThighOut.X, vLeftThighOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(vRightCalfOut.X, vRightCalfOut.Y), FVector2D(vRightThighOut.X, vRightThighOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(leftFeet2d.X, leftFeet2d.Y), FVector2D(vLeftCalfOut.X, vLeftCalfOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(rightFeet2d.X, rightFeet2d.Y), FVector2D(vRightCalfOut.X, vRightCalfOut.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(leftFeet2d.X, leftFeet2d.Y), FVector2D(leftFeetFinger2d.X, leftFeetFinger2d.Y), 1.3f, blce, minX, maxX, minY, maxY);
				DrawBoneLine(concern, FVector2D(rightFeet2d.X, rightFeet2d.Y), FVector2D(rightFeetFinger2d.X, rightFeetFinger2d.Y), 1.3f, blce, minX, maxX, minY, maxY);

				if (minX < doubt && maxX > 0 && minY < solve && maxY > 0) {
					auto headNeckDistance = STATIC_Sqrt((vHeadBoneOut.X - vNeckBoneOut.X) * (vHeadBoneOut.X - vNeckBoneOut.X) + (vHeadBoneOut.Y - vNeckBoneOut.Y) * (vHeadBoneOut.Y - vNeckBoneOut.Y));
					auto topLeft = FVector2D(minX - (headNeckDistance / 2), minY - (headNeckDistance / 2));
					auto bottomRight = FVector2D(maxX + (headNeckDistance / 2), maxY + (headNeckDistance / 2));
					auto topRight = FVector2D(maxX + (headNeckDistance / 2), minY - (headNeckDistance / 2));
					auto bottomLeft = FVector2D(minX - (headNeckDistance / 2), maxY + (headNeckDistance / 2));
					auto centerTop = FVector2D((topLeft.X + bottomRight.X) / 2.0f, topLeft.Y);

					if (buxx) {
						if (!gorner)
							K2_DrawBox(concern, topLeft, bottomRight - topLeft, (float)bouksthikz, blce);
						else {
							auto theAdditionY = (bottomRight.Y - topLeft.Y) / (4.f + 1);
							auto theAdditionX = (bottomRight.X - topLeft.X) / 4.f;
							K2_DrawLine(concern, topLeft, FVector2D(topLeft.X, topLeft.Y + theAdditionY), (float)bouksthikz, blce); // Top Left Y
							K2_DrawLine(concern, topLeft, FVector2D(topLeft.X + theAdditionX, topLeft.Y), (float)bouksthikz, blce); // Top Left X
							K2_DrawLine(concern, topRight, FVector2D(topRight.X, topRight.Y + theAdditionY), (float)bouksthikz, blce); // Top Right Y
							K2_DrawLine(concern, topRight, FVector2D(topRight.X - theAdditionX, topRight.Y), (float)bouksthikz, blce); // Top Right X
							K2_DrawLine(concern, bottomLeft, FVector2D(bottomLeft.X, bottomLeft.Y - theAdditionY), (float)bouksthikz, blce); // Bottom Left Y
							K2_DrawLine(concern, bottomLeft, FVector2D(bottomLeft.X + theAdditionX, bottomRight.Y), (float)bouksthikz, blce); // Bottom Left X
							K2_DrawLine(concern, bottomRight, FVector2D(bottomRight.X, bottomRight.Y - theAdditionY), (float)bouksthikz, blce); // Bottom Right Y
							K2_DrawLine(concern, bottomRight, FVector2D(bottomRight.X - theAdditionX, bottomRight.Y), (float)bouksthikz, blce); // Bottom Right X
						}
					}

					if (ezbtx || plate || klzz) {
						auto plrstt = STATIC_AttemptGetPlayerStateForPawn(burial);
						FString mysoil;
						if (ezbtx) {
							mysoil = STATIC_Concat_StrStr(mysoil, xMe(L"["));
							mysoil = STATIC_Concat_StrStr(mysoil, STATIC_Conv_IntToString((int)diztan));
							mysoil = STATIC_Concat_StrStr(mysoil, xMe(L"M]"));
						}
						if (plrstt && sugar) {
							if (plate) {
								auto platty = GetPlatform(plrstt);
								if (STATIC_IsEmpty(platty)) {
									platty = STATIC_Concat_StrStr(platty, xMe(L"BOT"));
								}
								mysoil = STATIC_Concat_StrStr(mysoil, xMe(L"["));
								mysoil = STATIC_Concat_StrStr(mysoil, platty);
								mysoil = STATIC_Concat_StrStr(mysoil, xMe(L"]"));
							}
							if (klzz) {
								mysoil = STATIC_Concat_StrStr(mysoil, xMe(L"["));
								mysoil = STATIC_Concat_StrStr(mysoil, STATIC_Conv_IntToString(GetKillScore(plrstt)));
								mysoil = STATIC_Concat_StrStr(mysoil, xMe(L"K]"));
							}
						}
						auto size = K2_TextSize(concern, funt, mysoil, FVector2D(0.50f, 0.50f));
						auto textLocation = FVector2D(centerTop.X - (size.X / 2), bottomRight.Y + 1.f);
						K2_DrawText(concern, funt, mysoil, textLocation, FVector2D(0.50f, 0.50f), blce, 1.0f, FLinearColor(), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1));
					}
				}
			}

			serien -= FVector2D(doubt / 2, solve / 2);
			double notc = STATIC_Sqrt(serien.X * serien.X + serien.Y * serien.Y);
			if (vender) {
				if (notc < (gump ? zepd : cstmfuv)) {
					if (notc < cbreakfastestDistance) {
						cbreakfastestDistance = notc;
						//check if player is knocked out
						if (burialDBNO) {
							Pothalt = burial;
							Potmanz = sousoumanz;
							PotclosestBreh = breh;
						}
						else {
							halt = burial;
							manz = sousoumanz;
							closestBreh = breh;
						}
					}
				}
			}
		}
	}

	if (aatkn && !halt && Pothalt) {
		halt = Pothalt;
		manz = Potmanz;
		closestBreh = PotclosestBreh;
	}

	// aim toggle
	//if (WasInputKeyJustPressed(retired, geyz::F1)) { radeo = !radeo; }

	// esp text
	if (WasInputKeyJustPressed(retired, geyz::F2)) { skidu = !skidu; }

	// smooth++
	if (WasInputKeyJustPressed(retired, geyz::F6)) { if (chosrar != 9) { chosrar++; } }

	// smooth--
	if (WasInputKeyJustPressed(retired, geyz::F5)) { if (chosrar != 1) { chosrar--; } }

	// toggle menu
	if (WasInputKeyJustPressed(retired, geyz::MToggle)) { barh = !barh; }

	if (skidu) {
		if (vance) {
			John(concern, doubt / 2, solve / 2, (gump ? (int)zepd : cstmfuv), 45, GetColorFromOption(vance).color);
		}
	}

	if (skidu && cqchk && tot > 0) {
		auto mysoil = STATIC_Concat_StrStr(xMe(L"ENEMIES: "), STATIC_Conv_IntToString(tot));
		mysoil = STATIC_Concat_StrStr(mysoil, xMe(L" - VISIBLE: "));
		mysoil = STATIC_Concat_StrStr(mysoil, STATIC_Conv_IntToString(viz));
		auto size = K2_TextSize(concern, funt, mysoil, FVector2D(0.50f, 0.50f));
		K2_DrawText(concern, funt, mysoil, FVector2D(doubt / 2 - (size.X / 2), 2.50f), FVector2D(0.50f, 0.50f), FLinearColor(185, 160, 87, 1.f), 1.0f, FLinearColor(0, 0, 0, 1.0), FVector2D(), false, false, true, FLinearColor(0, 0, 0, 1.0f));
	}

	if (barh) {
		Prudentius(concern);
	}

	if (grozair) {
		// X
		K2_DrawLine(concern, FVector2D(doubt / 2 - 10, solve / 2), FVector2D(doubt / 2 + 10, solve / 2), 1.5f, FLinearColor(185, 160, 87, 1.f));
		K2_DrawLine(concern, FVector2D(doubt / 2, solve / 2 - 10), FVector2D(doubt / 2, solve / 2 + 10), 1.5f, FLinearColor(185, 160, 87, 1.f));
	}

	if (lineezpaim && closestBreh.X) K2_DrawLine(concern, FVector2D(doubt / 2, solve), closestBreh, 1.2f, FLinearColor(185, 160, 87, 1.f));

	if (!halt || !sugar || !radeo) return;

	if (IsInputKeyDown(retired, geyz::AKey)) {
		FRotator huha = poler(cpoe, manz);
		if (cwsmComerl > 0) huha = Zkeg(quap, huha, cwsmComerl);
		huha.Pitch = huha.Pitch - quap.Pitch;
		huha.Yaw = huha.Yaw - quap.Yaw;
		huha.Roll = 0;
		Util::WriteMemory<FRotator>((PBYTE)retired + 0x518, huha);
	}
}

void cup(void* skedmerx, void* robot)
{
	if (!globalObject) operamom();

	globalObject = skedmerx;

	if (robot) cumin(robot);

	species(skedmerx, robot);
}

uint64_t CustomVTABLE[512];
uint64_t Page = 0;
bool genetic_2(uint64_t Object, void* HookFunction, void** HookOrig, DWORD Index)
{
	if (!Page)
		Page = (uint64_t)LI_FN(VirtualAlloc).safe_cached()(0, 1, MEM_COMMIT, PAGE_EXECUTE_READWRITE);

	void* ObjectVTable = Util::ReadMemory<void*>((PBYTE)Object);
	if (ObjectVTable == CustomVTABLE)
		return false;

	MemCpy(CustomVTABLE, ObjectVTable, sizeof(CustomVTABLE));

	uint8_t HookTemplate[14] = { 0xFF, 0x25, 0, 0, 0, 0 };

	*(void**)&HookTemplate[6] = HookFunction;
	MemCpy((void*)Page, HookTemplate, sizeof(HookTemplate));

	*(uint64_t*)&HookTemplate[6] = CustomVTABLE[Index];
	MemCpy((void*)(Page + sizeof(HookTemplate)), HookTemplate, sizeof(HookTemplate));

	*HookOrig = (void*)(Page + sizeof(HookTemplate));
	CustomVTABLE[Index] = Page;

	uint64_t VT = (uint64_t)CustomVTABLE;
	Util::WriteMemory<uint64_t>((PBYTE)Object, VT);

	return true;
}

void Nike(void* concern, FVector2D* Rudolf, int* id, const wchar_t* Kai/*optionName*/, int Meshulam/*type*/, bool* Soudeh = nullptr/*toggle*/, int* optionValue = nullptr, int increaseBy = 1, int min = 0, int max = 0, FKey& specia2 = geyz::AKey) {
	// type 1 is toggle
	// type 2 is float increase/decrease

	*Rudolf += FVector2D(0, 35);
	*id += 1;
	K2_DrawText(concern, funt, Kai, *Rudolf, FVector2D(0.7f, 0.7f), FLinearColor(255, 255, 255, 1), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor());

	auto Pio = *Rudolf + FVector2D(380, 4) + FVector2D(62, 0) + FVector2D(20, 0); /*initOn*/
	auto Elchanan = *Rudolf + FVector2D(380, 4) - FVector2D(60, 0) + FVector2D(20, 0); /*initOff*/
	auto Asclepius = FLinearColor(255, 255, 255, 1.f); /*color On*/
	auto lhami = FLinearColor(255, 255, 255, 1.f); /*color off*/
	auto Inna = FLinearColor(255, 255, 255, 1); /*onOffTextColor*/

	if (curobt == *id) {
		Asclepius = FLinearColor(185, 160, 87, 1.f);
		lhami = FLinearColor(224, 2, 2, 1.f);
		if (Meshulam == 2) {
			Inna = (*optionValue != 0) ? Asclepius : lhami;
			if (max > 299.f) {
				if (IsInputKeyDown(retired, geyz::Right) || IsInputKeyDown(retired, geyz::Gamepad_DPad_Right)) { if (*optionValue != max) { *optionValue += increaseBy; } }
				if (IsInputKeyDown(retired, geyz::Left) || IsInputKeyDown(retired, geyz::Gamepad_DPad_Left)) { if (*optionValue != min) { *optionValue -= increaseBy; } }
			}
			else {
				if (WasInputKeyJustPressed(retired, geyz::Right) || WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Right)) {
					if (*optionValue != max) {
						*optionValue += increaseBy;
						//if (*id == 2) {
						if (specia == 68) {
							if (*optionValue == 1)
								specia2 = geyz::Insert;
							else if (*optionValue == 2)
								specia2 = geyz::Home;
							else if (*optionValue == 3)
								specia2 = geyz::PageUp;
							else if (*optionValue == 4)
								specia2 = geyz::PageDown;
							else if (*optionValue == 5)
								specia2 = geyz::End;
							else if (*optionValue == 6)
								specia2 = geyz::Delete;
							else if (*optionValue == 7)
								specia2 = geyz::Escape;
							else if (*optionValue == 8)
								specia2 = geyz::LeftShift;
							else if (*optionValue == 9)
								specia2 = geyz::LeftControl;
							else if (*optionValue == 10)
								specia2 = geyz::CapsLock;
							else if (*optionValue == 11)
								specia2 = geyz::Tab;
							else if (*optionValue == 12)
								specia2 = geyz::Gamepad_DPad_Up;
							else if (*optionValue == 13)
								specia2 = geyz::Gamepad_DPad_Down;
							else if (*optionValue == 14)
								specia2 = geyz::Gamepad_DPad_Left;
							else if (*optionValue == 15)
								specia2 = geyz::Gamepad_DPad_Right;
							else if (*optionValue == 16)
								specia2 = geyz::F1;
							else if (*optionValue == 17)
								specia2 = geyz::F2;
							else if (*optionValue == 18)
								specia2 = geyz::F3;
							else if (*optionValue == 19)
								specia2 = geyz::F4;
							else if (*optionValue == 20)
								specia2 = geyz::F5;
							else if (*optionValue == 21)
								specia2 = geyz::F6;
							else if (*optionValue == 22)
								specia2 = geyz::F7;
							else if (*optionValue == 23)
								specia2 = geyz::F8;
							else if (*optionValue == 24)
								specia2 = geyz::F9;
							else if (*optionValue == 25)
								specia2 = geyz::F10;
							else if (*optionValue == 26)
								specia2 = geyz::F11;
							else if (*optionValue == 27)
								specia2 = geyz::F12;
						}
						else if (specia == 2) {
							if (*optionValue == 1)
								specia2 = geyz::RightClick;
							else if (*optionValue == 2)
								specia2 = geyz::LeftClick;
							else if (*optionValue == 3)
								specia2 = geyz::MiddleMouseButton;
							else if (*optionValue == 4)
								specia2 = geyz::ThumbMouseButton;
							else if (*optionValue == 5)
								specia2 = geyz::ThumbMouseButton2;
							else if (*optionValue == 6)
								specia2 = geyz::Z;
							else if (*optionValue == 7)
								specia2 = geyz::LeftShift;
							else if (*optionValue == 8)
								specia2 = geyz::LeftControl;
							else if (*optionValue == 9)
								specia2 = geyz::V;
							else if (*optionValue == 10)
								specia2 = geyz::B;
							else if (*optionValue == 11)
								specia2 = geyz::CapsLock;
							else if (*optionValue == 12)
								specia2 = geyz::Tab;
							else if (*optionValue == 13)
								specia2 = geyz::X;
							else if (*optionValue == 14)
								specia2 = geyz::C;
							else if (*optionValue == 15)
								specia2 = geyz::Gamepad_LeftTrigger;
							else if (*optionValue == 16)
								specia2 = geyz::Gamepad_DPad_Up;
							else if (*optionValue == 17)
								specia2 = geyz::Gamepad_DPad_Down;
							else if (*optionValue == 18)
								specia2 = geyz::Gamepad_DPad_Left;
							else if (*optionValue == 19)
								specia2 = geyz::Gamepad_DPad_Right;
							else if (*optionValue == 20)
								specia2 = geyz::F1;
							else if (*optionValue == 21)
								specia2 = geyz::F2;
							else if (*optionValue == 22)
								specia2 = geyz::F3;
							else if (*optionValue == 23)
								specia2 = geyz::F4;
							else if (*optionValue == 24)
								specia2 = geyz::F5;
							else if (*optionValue == 25)
								specia2 = geyz::F6;
							else if (*optionValue == 26)
								specia2 = geyz::F7;
							else if (*optionValue == 27)
								specia2 = geyz::F8;
							else if (*optionValue == 28)
								specia2 = geyz::F9;
							else if (*optionValue == 29)
								specia2 = geyz::F10;
							else if (*optionValue == 30)
								specia2 = geyz::F11;
							else if (*optionValue == 31)
								specia2 = geyz::F12;
						}
					}
				}
				if (WasInputKeyJustPressed(retired, geyz::Left) || WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Left)) {
					if (*optionValue != min) {
						*optionValue -= increaseBy;
						//if (*id == 2) {
						if (specia == 68) {
							if (*optionValue == 1)
								specia2 = geyz::Insert;
							else if (*optionValue == 2)
								specia2 = geyz::Home;
							else if (*optionValue == 3)
								specia2 = geyz::PageUp;
							else if (*optionValue == 4)
								specia2 = geyz::PageDown;
							else if (*optionValue == 5)
								specia2 = geyz::End;
							else if (*optionValue == 6)
								specia2 = geyz::Delete;
							else if (*optionValue == 7)
								specia2 = geyz::Escape;
							else if (*optionValue == 8)
								specia2 = geyz::LeftShift;
							else if (*optionValue == 9)
								specia2 = geyz::LeftControl;
							else if (*optionValue == 10)
								specia2 = geyz::CapsLock;
							else if (*optionValue == 11)
								specia2 = geyz::Tab;
							else if (*optionValue == 12)
								specia2 = geyz::Gamepad_DPad_Up;
							else if (*optionValue == 13)
								specia2 = geyz::Gamepad_DPad_Down;
							else if (*optionValue == 14)
								specia2 = geyz::Gamepad_DPad_Left;
							else if (*optionValue == 15)
								specia2 = geyz::Gamepad_DPad_Right;
							else if (*optionValue == 16)
								specia2 = geyz::F1;
							else if (*optionValue == 17)
								specia2 = geyz::F2;
							else if (*optionValue == 18)
								specia2 = geyz::F3;
							else if (*optionValue == 19)
								specia2 = geyz::F4;
							else if (*optionValue == 20)
								specia2 = geyz::F5;
							else if (*optionValue == 21)
								specia2 = geyz::F6;
							else if (*optionValue == 22)
								specia2 = geyz::F7;
							else if (*optionValue == 23)
								specia2 = geyz::F8;
							else if (*optionValue == 24)
								specia2 = geyz::F9;
							else if (*optionValue == 25)
								specia2 = geyz::F10;
							else if (*optionValue == 26)
								specia2 = geyz::F11;
							else if (*optionValue == 27)
								specia2 = geyz::F12;
						}
						else if (specia == 2) {
							if (*optionValue == 1)
								specia2 = geyz::RightClick;
							else if (*optionValue == 2)
								specia2 = geyz::LeftClick;
							else if (*optionValue == 3)
								specia2 = geyz::MiddleMouseButton;
							else if (*optionValue == 4)
								specia2 = geyz::ThumbMouseButton;
							else if (*optionValue == 5)
								specia2 = geyz::ThumbMouseButton2;
							else if (*optionValue == 6)
								specia2 = geyz::Z;
							else if (*optionValue == 7)
								specia2 = geyz::LeftShift;
							else if (*optionValue == 8)
								specia2 = geyz::LeftControl;
							else if (*optionValue == 9)
								specia2 = geyz::V;
							else if (*optionValue == 10)
								specia2 = geyz::B;
							else if (*optionValue == 11)
								specia2 = geyz::CapsLock;
							else if (*optionValue == 12)
								specia2 = geyz::Tab;
							else if (*optionValue == 13)
								specia2 = geyz::X;
							else if (*optionValue == 14)
								specia2 = geyz::C;
							else if (*optionValue == 15)
								specia2 = geyz::Gamepad_LeftTrigger;
							else if (*optionValue == 16)
								specia2 = geyz::Gamepad_DPad_Up;
							else if (*optionValue == 17)
								specia2 = geyz::Gamepad_DPad_Down;
							else if (*optionValue == 18)
								specia2 = geyz::Gamepad_DPad_Left;
							else if (*optionValue == 19)
								specia2 = geyz::Gamepad_DPad_Right;
							else if (*optionValue == 20)
								specia2 = geyz::F1;
							else if (*optionValue == 21)
								specia2 = geyz::F2;
							else if (*optionValue == 22)
								specia2 = geyz::F3;
							else if (*optionValue == 23)
								specia2 = geyz::F4;
							else if (*optionValue == 24)
								specia2 = geyz::F5;
							else if (*optionValue == 25)
								specia2 = geyz::F6;
							else if (*optionValue == 26)
								specia2 = geyz::F7;
							else if (*optionValue == 27)
								specia2 = geyz::F8;
							else if (*optionValue == 28)
								specia2 = geyz::F9;
							else if (*optionValue == 29)
								specia2 = geyz::F10;
							else if (*optionValue == 30)
								specia2 = geyz::F11;
							else if (*optionValue == 31)
								specia2 = geyz::F12;
						}
					}
				}
			}
		}
		else {
			Inna = *Soudeh ? Asclepius : lhami;

			if (WasInputKeyJustPressed(retired, geyz::Right) || WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Right)) { *Soudeh = true; }
			if (WasInputKeyJustPressed(retired, geyz::Left) || WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Left)) { *Soudeh = false; }
		}
	}

	// Toggle Text
	//if (*id == 2) {
	/*if (specia == 1) {
		char* skid = xMe("OFF");
		if (*optionValue == 1) skid = xMe("MOUSE");
		else if (*optionValue == 2) skid = xMe("MEMORY");
		LI_FN(sprintf).safe_cached()(precede, xMe("%s"), skid);
	}
	else*/
	FString skid;
	if (specia == 2) {
		if (*optionValue == 0) skid = xMe(L"OFF");
		else if (*optionValue == 1) skid = xMe(L"RMB");
		else if (*optionValue == 2) skid = xMe(L"LMB");
		else if (*optionValue == 3) skid = xMe(L"MMB");
		else if (*optionValue == 4) skid = xMe(L"TMB");
		else if (*optionValue == 5) {
			//skid = xMe(L"TMB2");//
			skid = STATIC_Concat_StrStr(xMe(L"TMB"), xMe(L"2"));
		}
		else if (*optionValue == 6) skid = xMe(L"Z");
		else if (*optionValue == 7) {
			//skid = xMe(L"LSHIFT");//
			skid = STATIC_Concat_StrStr(xMe(L"LSH"), xMe(L"IFT"));
		}
		else if (*optionValue == 8) {
			//skid = xMe(L"LCONTROL");//
			skid = STATIC_Concat_StrStr(xMe(L"LCON"), xMe(L"TROL"));
		}
		else if (*optionValue == 9) skid = xMe(L"V");
		else if (*optionValue == 10) skid = xMe(L"B");
		else if (*optionValue == 11) {
			//skid = xMe(L"CAPS");//
			skid = STATIC_Concat_StrStr(xMe(L"CA"), xMe(L"PS"));
		}
		else if (*optionValue == 12) skid = xMe(L"TAB");
		else if (*optionValue == 13) skid = xMe(L"X");
		else if (*optionValue == 14) skid = xMe(L"C");
		else if (*optionValue == 15) skid = xMe(L"L2");
		else if (*optionValue == 16) {
			//skid = xMe(L"DPad UP");//
			skid = STATIC_Concat_StrStr(xMe(L"DPad "), xMe(L"UP"));
		}
		else if (*optionValue == 17) {
			//skid = xMe(L"DPad DOWN");//
			skid = STATIC_Concat_StrStr(xMe(L"DPad "), xMe(L"DOWN"));
		}
		else if (*optionValue == 18) {
			//skid = xMe(L"DPad LEFT");//
			skid = STATIC_Concat_StrStr(xMe(L"DPad "), xMe(L"LEFT"));
		}
		else if (*optionValue == 19) {
			//skid = xMe(L"DPad RIGHT");//
			skid = STATIC_Concat_StrStr(xMe(L"DPad "), xMe(L"RIGHT"));
		}
		else if (*optionValue == 20) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"1"));
		}
		else if (*optionValue == 21) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"2"));
		}
		else if (*optionValue == 22) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"3"));
		}
		else if (*optionValue == 23) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"4"));
		}
		else if (*optionValue == 24) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"5"));
		}
		else if (*optionValue == 25) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"6"));
		}
		else if (*optionValue == 26) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"7"));
		}
		else if (*optionValue == 27) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"8"));
		}
		else if (*optionValue == 28) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"9"));
		}
		else if (*optionValue == 29) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"10"));
		}
		else if (*optionValue == 30) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"11"));
		}
		else if (*optionValue == 31) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"12"));
		}
	}
	else if (specia == 68) {
		if (*optionValue == 0) skid = xMe(L"OFF");
		if (*optionValue == 1) skid = STATIC_Concat_StrStr(xMe(L"INS"), xMe(L"ERT"));
		else if (*optionValue == 2) skid = STATIC_Concat_StrStr(xMe(L"HO"), xMe(L"ME"));
		else if (*optionValue == 3) skid = STATIC_Concat_StrStr(xMe(L"PAGE "), xMe(L"UP"));
		else if (*optionValue == 4) skid = STATIC_Concat_StrStr(xMe(L"PAGE "), xMe(L"DOWN"));
		else if (*optionValue == 5) skid = STATIC_Concat_StrStr(xMe(L"EN"), xMe(L"D"));
		else if (*optionValue == 6) skid = STATIC_Concat_StrStr(xMe(L"DEL"), xMe(L"ETE"));
		else if (*optionValue == 7) skid = STATIC_Concat_StrStr(xMe(L"ESC"), xMe(L"APE"));
		else if (*optionValue == 8) skid = STATIC_Concat_StrStr(xMe(L"LSH"), xMe(L"IFT"));
		else if (*optionValue == 9) skid = STATIC_Concat_StrStr(xMe(L"LCON"), xMe(L"TROL"));
		else if (*optionValue == 10) skid = STATIC_Concat_StrStr(xMe(L"CA"), xMe(L"PS"));
		else if (*optionValue == 11) skid = xMe(L"TAB");
		else if (*optionValue == 12) {
			skid = STATIC_Concat_StrStr(xMe(L"DPad "), xMe(L"UP"));
		}
		else if (*optionValue == 13) {
			//skid = xMe(L"DPad DOWN");//
			skid = STATIC_Concat_StrStr(xMe(L"DPad "), xMe(L"DOWN"));
		}
		else if (*optionValue == 14) {
			//skid = xMe(L"DPad LEFT");//
			skid = STATIC_Concat_StrStr(xMe(L"DPad "), xMe(L"LEFT"));
		}
		else if (*optionValue == 15) {
			//skid = xMe(L"DPad RIGHT");//
			skid = STATIC_Concat_StrStr(xMe(L"DPad "), xMe(L"RIGHT"));
		}
		else if (*optionValue == 16) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"1"));
		}
		else if (*optionValue == 17) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"2"));
		}
		else if (*optionValue == 18) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"3"));
		}
		else if (*optionValue == 19) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"4"));
		}
		else if (*optionValue == 20) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"5"));
		}
		else if (*optionValue == 21) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"6"));
		}
		else if (*optionValue == 22) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"7"));
		}
		else if (*optionValue == 23) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"8"));
		}
		else if (*optionValue == 24) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"9"));
		}
		else if (*optionValue == 25) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"10"));
		}
		else if (*optionValue == 26) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"11"));
		}
		else if (*optionValue == 27) {
			skid = STATIC_Concat_StrStr(xMe(L"F"), xMe(L"12"));
		}
	}
	else if (specia == 3) {
		if (*optionValue == 1) skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"HEAD"));
		if (*optionValue == 2) skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"NECK"));
		if (*optionValue == 3) skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"BODY"));
		if (*optionValue == 4) skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"CLOSEST"));
	}
	else if (specia == 69) {
		if (*optionValue != 0) {
			skid = STATIC_Concat_StrStr(xMe(L""), GetColorFromOption(*optionValue).name);
			Inna = GetColorFromOption(*optionValue).color;
		}
		else {
			skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"OFF"));
		}
	}
	else if (Meshulam == 2) {
		skid = STATIC_Concat_StrStr(xMe(L""), STATIC_Conv_IntToString(*optionValue));
	}
	else {
		skid = STATIC_Concat_StrStr(xMe(L""), *Soudeh ? xMe(L"ON") : xMe(L"OFF"));
	}

	double Silvia = (Pio.X - Elchanan.X) + 20/*20 is the width of arrow button*/; /*distanceBetweenRedGreen*/
	auto size = K2_TextSize(concern, funt, skid, FVector2D(0.7f, 0.7f));
	K2_DrawText(concern, funt, skid, FVector2D(Elchanan.X + (Silvia / 2) - (size.X / 2), Rudolf->Y), FVector2D(0.7f, 0.7f), Inna, 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor());

	float Adelina = 0.5;
	float Adelinay = 1.0;
	for (int i = 0; i < 20; i++)
	{
		K2_DrawLine(concern, Pio, Pio + FVector2D(0, 20) + FVector2D(Adelinay, 0) - FVector2D(0, Adelina), 1.0f, Asclepius);
		K2_DrawLine(concern, Elchanan + FVector2D(20, 0), Elchanan + FVector2D(20, 20) - FVector2D(Adelinay, 0) - FVector2D(0, Adelina), 1.0f, lhami);
		Adelina += 0.5;
		Adelinay += 1.0;
	}
	K2_DrawLine(concern, Pio, Pio + FVector2D(20, 10), 1.0f, Asclepius);
	K2_DrawLine(concern, Pio, Pio + FVector2D(0, 20), 1.0f, Asclepius);
	K2_DrawLine(concern, Pio + FVector2D(0, 20), Pio + FVector2D(20, 10), 1.0f, Asclepius);
	K2_DrawLine(concern, Elchanan + FVector2D(20, 0), Elchanan + FVector2D(20, 20), 1.0f, lhami);
	K2_DrawLine(concern, Elchanan + FVector2D(20, 0), Elchanan + FVector2D(0, 10), 1.0f, lhami);
	K2_DrawLine(concern, Elchanan + FVector2D(20, 20), Elchanan + FVector2D(0, 10), 1.0f, lhami);
}

void dlemxxd(void* concern, FVector2D initial_pos, double width, double height, FLinearColor color)
{
	for (float i = 0.0f; i < height; i += 1.0f)
		K2_DrawLine(concern, FVector2D(initial_pos.X, initial_pos.Y + i), FVector2D(initial_pos.X + width, initial_pos.Y + i), 1.0f, color);
}

void Prudentius(void* concern) {
	auto Rayko = FVector2D(511, 600); //Menu Size
	auto Enheduanna = FVector2D(20, (solve / 2) - (Rayko.Y / 2)); //Menu Pos
	auto Rudolf = Enheduanna + FVector2D(10, 60); //Option Pos
	int tutl = 0;
	// Menu background
	dlemxxd(concern, Enheduanna, Rayko.X - 2, Rayko.Y - 2, FLinearColor(28, 29, 37, 1.f));
	// Menu Title Rect
	// Title rect
	dlemxxd(concern, Enheduanna, Rayko.X - 2, 45, FLinearColor(12, 13, 16, 1.f));
	// Line around all Menu
	K2_DrawBox(concern, Enheduanna, FVector2D(Rayko.X - 2, Rayko.Y - 2), 1.0f, FLinearColor(12, 13, 16, 1.f));
	// Menu Title Text
	auto size = K2_TextSize(concern, funt, xMe(L"SYNDICATE"), FVector2D(1.1f, 1.0f));
	K2_DrawText(concern, funt, xMe(L"SYNDICATE"), Enheduanna + FVector2D((Rayko.X / 2) - (size.X / 2), 3), FVector2D(1.1f, 1.0f), FLinearColor(185, 160, 87, 1), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor());

	// Tabs rect
	dlemxxd(concern, Enheduanna + FVector2D(0, 50), Rayko.X - 2, 35, FLinearColor(12, 13, 16, 1.f));
	// Tabs
	{
		auto UnselectedTab = FLinearColor(255, 255, 255, 1.f); /*color On*/
		auto SelectedTab = FLinearColor(185, 160, 87, 1); /*color On*/
		if (curobt == 0) {
			if (WasInputKeyJustPressed(retired, geyz::Right) || WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Right)) {
				if (curtab != 3) curtab++;
			}
			if (WasInputKeyJustPressed(retired, geyz::Left) || WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Left)) {
				if (curtab != 0) curtab--;
			}
		}
		if (curtab == 0) dlemxxd(concern, Enheduanna + FVector2D(0, 50), 127.25, 35, FLinearColor(28, 29, 37, 1.f));
		if (curtab == 0) K2_DrawLine(concern, Enheduanna + FVector2D(0, 50), Enheduanna + FVector2D(127.25, 50), 1.f, FLinearColor(5, 5, 5, 1.f));
		size = K2_TextSize(concern, funt, xMe(L"AIMBOT"), FVector2D(0.7f, 0.7f));
		K2_DrawText(concern, funt, xMe(L"AIMBOT"), Enheduanna + FVector2D((127.25 / 2) - (size.X / 2), 54), FVector2D(0.7f, 0.7f), ((curobt == 0) && (curtab == 0)) ? SelectedTab : UnselectedTab, 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor());

		if (curtab == 1) dlemxxd(concern, Enheduanna + FVector2D(127.25, 50), 127.25, 35, FLinearColor(28, 29, 37, 1.f));
		if (curtab == 1) K2_DrawLine(concern, Enheduanna + FVector2D(127.25, 50), Enheduanna + FVector2D(127.25 * 2, 50), 1.f, FLinearColor(5, 5, 5, 1.f));
		size = K2_TextSize(concern, funt, xMe(L"WEAPONS"), FVector2D(0.7f, 0.7f));
		K2_DrawText(concern, funt, xMe(L"WEAPONS"), Enheduanna + FVector2D(127.25 + (127.25 / 2) - (size.X / 2), 54), FVector2D(0.7f, 0.7f), ((curobt == 0) && (curtab == 1)) ? SelectedTab : UnselectedTab, 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor());

		if (curtab == 2) dlemxxd(concern, Enheduanna + FVector2D(127.25 * 2, 50), 127.25, 35, FLinearColor(28, 29, 37, 1.f));
		if (curtab == 2) K2_DrawLine(concern, Enheduanna + FVector2D(127.25 * 2, 50), Enheduanna + FVector2D(127.25 * 3, 50), 1.f, FLinearColor(5, 5, 5, 1.f));
		size = K2_TextSize(concern, funt, xMe(L"VISUALS"), FVector2D(0.7f, 0.7f));
		K2_DrawText(concern, funt, xMe(L"VISUALS"), Enheduanna + FVector2D(127.25 * 2 + (127.25 / 2) - (size.X / 2), 54), FVector2D(0.7f, 0.7f), ((curobt == 0) && (curtab == 2)) ? SelectedTab : UnselectedTab, 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor());

		if (curtab == 3) dlemxxd(concern, Enheduanna + FVector2D(127.25 * 3, 50), 127.25, 35, FLinearColor(28, 29, 37, 1.f));
		if (curtab == 3) K2_DrawLine(concern, Enheduanna + FVector2D(127.25 * 3, 50), Enheduanna + FVector2D(127.25 * 4, 50), 1.f, FLinearColor(5, 5, 5, 1.f));
		size = K2_TextSize(concern, funt, xMe(L"MISC"), FVector2D(0.7f, 0.7f));
		K2_DrawText(concern, funt, xMe(L"MISC"), Enheduanna + FVector2D(127.25 * 3 + (127.25 / 2) - (size.X / 2), 54), FVector2D(0.7f, 0.7f), ((curobt == 0) && (curtab == 3)) ? SelectedTab : UnselectedTab, 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor());

	}
	// Draw Options
	specia = 0;
	if (curtab == 0) {
		//Nike(concern, &Rudolf, &tutl, xMe(L"ENABLE AIMBOT (F1)"), 1, &radeo);
		//Nike(concern, &Rudolf, &tutl, xMe(L"AIM LOCK"), 1, &aemluk);
		//Nike(concern, &Rudolf, &tutl, xMe(L"WEAKSPOT AIM"), 1, &weekaem);
		specia = 2;
		Nike(concern, &Rudolf, &tutl, xMe(L"AIM KEY"), 2, 0, &radeo, 1, 0, 19, geyz::AKey);
		specia = 3;
		Nike(concern, &Rudolf, &tutl, xMe(L"AIM BONE"), 2, 0, &skei, 1, 1, 4);
		specia = 0;
		Nike(concern, &Rudolf, &tutl, xMe(L"AIM SMOOTHING"), 2, 0, &comerl, 1, 0, 50);
		//Nike(concern, &Rudolf, &tutl, xMe(L"SILENT"), 1, &saylnt);
		Nike(concern, &Rudolf, &tutl, xMe(L"AIM FOV SIZE"), 2, 0, &xepd, 1, 1, 900);
		Nike(concern, &Rudolf, &tutl, xMe(L"AUTO AIM FOV SIZE"), 1, &gump);
		Nike(concern, &Rudolf, &tutl, xMe(L"VISIBLE CHECK"), 1, &vcheq);
		Nike(concern, &Rudolf, &tutl, xMe(L"CLOSE ENEMIES AIM"), 1, &vcheqclose);
		Nike(concern, &Rudolf, &tutl, xMe(L"AIM AT KNOCKED"), 1, &aatkn);
		Nike(concern, &Rudolf, &tutl, xMe(L"AIM LINE ESP"), 1, &lineezpaim);
	}
	else if (curtab == 1) {
		Nike(concern, &Rudolf, &tutl, xMe(L"CUSTOM WEAPON SMOOTHING"), 1, &cwsm);
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] SHOTGUN SMOOTHING"), 2, 0, &scwsm, 1, 0, 50);
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] SMG SMOOTHING"), 2, 0, &smgcwsm, 1, 0, 50);
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] AR SMOOTHING"), 2, 0, &acwsm, 1, 0, 50);
		Nike(concern, &Rudolf, &tutl, xMe(L"CUSTOM WEAPON FOV"), 1, &cwfov);
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] SHOTGUN FOV"), 2, 0, &scwfov, 1, 1, 900);
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] SMG FOV"), 2, 0, &smgcwfov, 1, 1, 900);
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] AR FOV"), 2, 0, &acwfov, 1, 1, 900);
		Nike(concern, &Rudolf, &tutl, xMe(L"CUSTOM WEAPON AIM BONE"), 1, &cwbone);
		specia = 3;
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] SHOTGUN AIM BONE"), 2, 0, &scwbone, 1, 1, 4);
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] SMG AIM BONE"), 2, 0, &smgcwbone, 1, 1, 4);
		Nike(concern, &Rudolf, &tutl, xMe(L"[-] AR AIM BONE"), 2, 0, &acwbone, 1, 1, 4);
		specia = 0;
	}
	else if (curtab == 2) {
		Nike(concern, &Rudolf, &tutl, xMe(L"ALL VISUALS (F2)"), 1, &skidu);
		//Nike(concern, &Rudolf, &tutl, xMe(L"MAX VISUALS DISTANCE"), 2, 0, &maxdiz, 1, 10, 300);
		Nike(concern, &Rudolf, &tutl, xMe(L"BOX ESP"), 1, &buxx);
		Nike(concern, &Rudolf, &tutl, xMe(L"CORNER BOX"), 1, &gorner);
		Nike(concern, &Rudolf, &tutl, xMe(L"BOX THICKNESS"), 2, 0, &bouksthikz, 1, 1, 5);
		Nike(concern, &Rudolf, &tutl, xMe(L"SKELETON"), 1, &dsklt);
		//Nike(concern, &Rudolf, &tutl, xMe(L"SKELETON THICKNESS"), 2, 0, &dskltthik, 1, 1, 3);
		specia = 69;
		Nike(concern, &Rudolf, &tutl, xMe(L"SHOW FOV CIRCLE"), 2, 0, &vance, 1, 0, 6);
		specia = 0;
		Nike(concern, &Rudolf, &tutl, xMe(L"DISTANCE ESP"), 1, &ezbtx);
		Nike(concern, &Rudolf, &tutl, xMe(L"PLATFORM ESP"), 1, &plate);
		Nike(concern, &Rudolf, &tutl, xMe(L"KILLS ESP"), 1, &klzz);
		Nike(concern, &Rudolf, &tutl, xMe(L"LOOT ESP (F5/F6)"), 1, &lezp);
		specia = 69;
		Nike(concern, &Rudolf, &tutl, xMe(L"VISIBLE COLOR"), 2, 0, &clrV, 1, 1, 6);
		Nike(concern, &Rudolf, &tutl, xMe(L"INVISIBLE COLOR"), 2, 0, &clrI, 1, 1, 6);
		Nike(concern, &Rudolf, &tutl, xMe(L"DOWNED COLOR"), 2, 0, &clrD, 1, 1, 6);
		specia = 0;
		//Nike(concern, &Rudolf, &tutl, xMe(L"WEAPON ESP"), 1, &wepezb);
		//specia = 4;
		//Nike(concern, &Rudolf, &tutl, xMe(L"LOOT MINIMUM RARITY"), 2, 0, &chosrar, 1, 1, 7);
		//specia = 0;
	}
	else if (curtab == 3) {
		//Nike(concern, &Rudolf, &tutl, xMe(L"VEHICLE FLY"), 2, 0, &vfley, 1, 0, 31, geyz::FLKey);
		//Nike(concern, &Rudolf, &tutl, xMe(L"VEHICLE FLY BOOST"), 2, 0, &vfboost, 1, 0, 31, geyz::FLKeyBoost);
		//Nike(concern, &Rudolf, &tutl, xMe(L"WALL STEALER"), 2, 0, &bstel, 1, 0, 31, geyz::WSteal);
		specia = 68;
		Nike(concern, &Rudolf, &tutl, xMe(L"MENU KEY"), 2, 0, &MToggle, 1, 1, 27, geyz::MToggle);
		Nike(concern, &Rudolf, &tutl, xMe(L"PANIC KEY"), 2, 0, &PToggle, 1, 0, 27, geyz::PToggle);
		specia = 2;
		Nike(concern, &Rudolf, &tutl, xMe(L"INSTANT LOOT PICKER"), 2, 0, &lpckr, 1, 0, 31, geyz::LPicker);
		Nike(concern, &Rudolf, &tutl, xMe(L"INSTANT LOOT DESTROYER"), 2, 0, &ldstr, 1, 0, 31, geyz::LDestroyer);
		specia = 0;
		Nike(concern, &Rudolf, &tutl, xMe(L"CROSSHAIR"), 1, &grozair);
		Nike(concern, &Rudolf, &tutl, xMe(L"CAUTION CHECK"), 1, &cqchk);
	}

	// menu control
	if (WasInputKeyJustPressed(retired, geyz::Up) || WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Up)) {
		if (curobt != 0) curobt--;
	}
	if (WasInputKeyJustPressed(retired, geyz::Down) || WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Down)) if (curobt != tutl) curobt++;
}

FName InsKe(FString Keyname) {
	return STATIC_Conv_StringToName(retired, Keyname);
}

void operamom() {
	funt = FindMyObject(xMe(L"Burbank:Burbank"));

	// Special keys stuff
	geyz::Insert = FKey(InsKe(xMe(L"Insert")));
	geyz::MToggle = geyz::Insert;

	geyz::PageUp = FKey(InsKe(xMe(L"PageUp")));
	geyz::PageDown = FKey(InsKe(xMe(L"PageDown")));
	geyz::Home = FKey(InsKe(xMe(L"Home")));
	geyz::End = FKey(InsKe(xMe(L"End")));
	geyz::Delete = FKey(InsKe(xMe(L"Delete")));
	geyz::Escape = FKey(InsKe(xMe(L"Escape")));

	// Mouse buttons
	geyz::LeftClick = FKey(InsKe(xMe(L"LeftMouseButton")));
	geyz::RightClick = FKey(InsKe(xMe(L"RightMouseButton")));
	geyz::MiddleMouseButton = FKey(InsKe(xMe(L"MiddleMouseButton")));
	geyz::ThumbMouseButton2 = FKey(InsKe(xMe(L"ThumbMouseButton2")));
	geyz::ThumbMouseButton = FKey(InsKe(xMe(L"ThumbMouseButton")));

	// Up/Down/Left/Right Keys
	geyz::Up = FKey(InsKe(xMe(L"Up")));
	geyz::Down = FKey(InsKe(xMe(L"Down")));
	geyz::Left = FKey(InsKe(xMe(L"Left")));
	geyz::Right = FKey(InsKe(xMe(L"Right")));
	geyz::LeftShift = FKey(InsKe(xMe(L"LeftShift")));
	geyz::LeftControl = FKey(InsKe(xMe(L"LeftControl")));
	geyz::AKey = geyz::RightClick;

	// FKeys
	geyz::F1 = FKey(InsKe(xMe(L"F1")));
	geyz::F2 = FKey(InsKe(xMe(L"F2")));
	geyz::F3 = FKey(InsKe(xMe(L"F3")));
	geyz::F4 = FKey(InsKe(xMe(L"F4")));
	geyz::F5 = FKey(InsKe(xMe(L"F5")));
	geyz::F6 = FKey(InsKe(xMe(L"F6")));
	geyz::F7 = FKey(InsKe(xMe(L"F7")));
	geyz::F8 = FKey(InsKe(xMe(L"F8")));
	geyz::F9 = FKey(InsKe(xMe(L"F9")));
	geyz::F10 = FKey(InsKe(xMe(L"F10")));
	geyz::F11 = FKey(InsKe(xMe(L"F11")));
	geyz::F12 = FKey(InsKe(xMe(L"F12")));

	// Controller Stuff
	geyz::Gamepad_DPad_Up = FKey(InsKe(xMe(L"Gamepad_DPad_Up")));
	geyz::Gamepad_DPad_Down = FKey(InsKe(xMe(L"Gamepad_DPad_Down")));
	geyz::Gamepad_DPad_Left = FKey(InsKe(xMe(L"Gamepad_DPad_Left")));
	geyz::Gamepad_DPad_Right = FKey(InsKe(xMe(L"Gamepad_DPad_Right")));
	geyz::Gamepad_LeftTrigger = FKey(InsKe(xMe(L"Gamepad_LeftTrigger")));

	// keys
	geyz::Z = FKey(InsKe(xMe(L"Z")));
	geyz::V = FKey(InsKe(xMe(L"V")));
	geyz::B = FKey(InsKe(xMe(L"B")));
	geyz::CapsLock = FKey(InsKe(xMe(L"CapsLock")));
	geyz::Tab = FKey(InsKe(xMe(L"Tab")));
	geyz::X = FKey(InsKe(xMe(L"X")));
	geyz::C = FKey(InsKe(xMe(L"C")));

	geyz::HeadName = InsKe(xMe(L"head"));
	geyz::RootName = InsKe(xMe(L"Root"));
	geyz::NeckName = InsKe(xMe(L"neck_01"));
	geyz::LowerNeckName = InsKe(xMe(L"clavicle_l"));
	geyz::ChestName = InsKe(xMe(L"spine_03"));
	geyz::PelvisName = InsKe(xMe(L"pelvis"));
	geyz::Upperarm_lName = InsKe(xMe(L"upperarm_l"));
	geyz::Upperarm_rName = InsKe(xMe(L"upperarm_r"));
	geyz::Lowerarm_lName = InsKe(xMe(L"lowerarm_l"));
	geyz::Lowerarm_rName = InsKe(xMe(L"lowerarm_r"));
	geyz::Hand_lName = InsKe(xMe(L"hand_l"));
	geyz::Hand_rName = InsKe(xMe(L"hand_r"));
	geyz::Thigh_lName = InsKe(xMe(L"thigh_l"));
	geyz::Thigh_rName = InsKe(xMe(L"thigh_r"));
	geyz::Calf_lName = InsKe(xMe(L"calf_l"));
	geyz::Calf_rName = InsKe(xMe(L"calf_r"));
	geyz::LowerCalf_lName = InsKe(xMe(L"calf_twist_02_l"));
	geyz::LowerCalf_rName = InsKe(xMe(L"calf_twist_02_r"));
	geyz::Foot_lName = InsKe(xMe(L"ik_foot_l"));
	geyz::Foot_rName = InsKe(xMe(L"ik_foot_r"));
	geyz::Toe_lName = InsKe(xMe(L"ball_l"));
	geyz::Toe_rName = InsKe(xMe(L"ball_r"));
}