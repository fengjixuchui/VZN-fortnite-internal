#pragma once
#include <math.h>

void* globalObject;
void* (*StaticFindFirstObject_t)(void* Class, WCHAR* Name, UINT64 Options, UINT64 AmbiguousMessageVerbosity, const TCHAR* InCurrentOperation);
//void(*AltProcessEvent)(void* object, void* function, void* params);

//template<typename T>
//T* FindMyObject(const wchar_t* ObjectName)
//{
//	return reinterpret_cast<T*>(StaticFindFirstObject_t, (UINT64)0, (UINT64)ObjectName, 0, 0, 0);
//}

void* FindMyObject(const wchar_t* ObjectName)
{
	return StaticFindFirstObject_t(0, (WCHAR*)ObjectName, 0, 0, 0);
}

//Spoof VFTable Return Address
//template<typename... Args>
//void VCall2(PVOID Class, int Index, Args... AddArgs) {
//	return RetSpoof<void>((Util::ReadMemory<PVOID*>(Class))[Index], Class, AddArgs...);
//}
//
template<typename Fn>
inline Fn GetVFunction(const void* instance, std::size_t index)
{
	auto OldTable = Util::ReadMemory<const void**>((PBYTE)instance);

	auto NewTable = OldTable;

	return reinterpret_cast<Fn>(NewTable[index]);
}

inline void ProcessEvent(void* object, void* function, void* parms)
{
	return GetVFunction<void(*)(void*, void*, void*)>(object, 77)(object, function, parms);
}

void* GetMaterialy(void* object)
{
	return GetVFunction<void*(*)(void*)>(object, 87)(object);
}

FName STATIC_Conv_StringToName(const struct FString& InString)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetStringLibrary:Conv_StringToName"));

	static void* fno = NULL;
	if (!fno)
		fno = FindMyObject(xMe(L"Engine.Default__KismetStringLibrary"));
	
	UKismetStringLibrary_Conv_StringToName_Params params;
	params.InString = InString;

	ProcessEvent(fno, fn, &params);

	return params.ReturnValue;
}

struct FString STATIC_Conv_NameToString(const struct FName& InName)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetStringLibrary:Conv_NameToString"));

	UKismetStringLibrary_Conv_NameToString_Params params;
	params.InName = InName;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void GetViewportSize(void* object, int* SizeX, int* SizeY)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerController:GetViewportSize"));

	APlayerController_GetViewportSize_Params params;

	ProcessEvent(object, fn, &params);

	if (SizeX != nullptr)
		*SizeX = params.SizeX;
	if (SizeY != nullptr)
		*SizeY = params.SizeY;
}

TArray<void*> STATIC_GetFortPlayerPawns(void* WorldContextObject)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:GetFortPlayerPawns"));

	UFortKismetLibrary_GetFortPlayerPawns_Params params;
	params.WorldContextObject = WorldContextObject;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

bool IsProjectileWeapon(void* _object)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortWeapon:IsProjectileWeapon"));

	AFortWeapon_IsProjectileWeapon_Params params;

	ProcessEvent(_object, fn, &params);

	return params.ReturnValue;
}

void* GetOwnerPlayerController(void* _object)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortProjectileBase:GetOwnerPlayerController"));

	AFortProjectileBase_GetOwnerPlayerController_Params params;

	ProcessEvent(_object, fn, &params);

	return params.ReturnValue;
}

void SetCollisionResponseToAllChannels(void* _this, TEnumAsByte<ECollisionResponse> NewResponse)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PrimitiveComponent:SetCollisionResponseToAllChannels"));

	UPrimitiveComponent_SetCollisionResponseToAllChannels_Params params;
	params.NewResponse = NewResponse;

	ProcessEvent(_this, fn, &params);
}

void SetCollisionResponseToChannel(void* _this, TEnumAsByte<ECollisionChannel> Channel, TEnumAsByte<ECollisionResponse> NewResponse)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PrimitiveComponent:SetCollisionResponseToChannel"));

	UPrimitiveComponent_SetCollisionResponseToChannel_Params params;
	params.Channel = Channel;
	params.NewResponse = NewResponse;

	ProcessEvent(_this, fn, &params);
}

uint8_t GetWeaponDataItemType(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortWeapon:GetWeaponDataItemType"));

	AFortWeapon_GetWeaponDataItemType_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

struct FString STATIC_GetHumanReadableName(void* Actor)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:GetHumanReadableName"));

	UFortKismetLibrary_GetHumanReadableName_Params params;
	params.Actor = Actor;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

FVector GetCameraLocation(void* object)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerCameraManager:GetCameraLocation"));

	APlayerCameraManager_GetCameraLocation_Params params;

	ProcessEvent(object, fn, &params);

	return params.ReturnValue;
}

void* K2_GetPawn(void* object)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Controller:K2_GetPawn"));

	AController_K2_GetPawn_Params params;

	ProcessEvent(object, fn, &params);

	return params.ReturnValue;
}

bool STATIC_OnSameTeam(void* ActorA, void* ActorB)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:OnSameTeam"));

	UFortKismetLibrary_OnSameTeam_Params params;
	params.ActorA = ActorA;
	params.ActorB = ActorB;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

bool IsDead(void* object)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPawn:IsDead"));

	AFortPawn_IsDead_Params params;

	ProcessEvent(object, fn, &params);

	return params.ReturnValue;
}

double STATIC_Sqrt(double A)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:Sqrt"));

	UKismetMathLibrary_Double_Params params;
	params.A = A;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

double STATIC_Atan(double A)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:Atan"));

	UKismetMathLibrary_Double_Params params;
	params.A = A;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

double STATIC_Abs(double A)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:Abs"));

	UKismetMathLibrary_Double_Params params;
	params.A = A;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void K2_DrawLine(void* object, const struct FVector2D& ScreenPositionA, const struct FVector2D& ScreenPositionB, float Thickness, const struct FLinearColor& RenderColor)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Canvas:K2_DrawLine"));

	UCanvas_K2_DrawLine_Params params;
	params.ScreenPositionA = ScreenPositionA;
	params.ScreenPositionB = ScreenPositionB;
	params.Thickness = Thickness;
	params.RenderColor = RenderColor;

	ProcessEvent(object, fn, &params);
}


FVector2D K2_TextSize(void* object, void* RenderFont, const struct FString& RenderText, const struct FVector2D& Scale)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Canvas:K2_TextSize"));

	UCanvas_K2_TextSize_Params params;
	params.RenderFont = RenderFont;
	params.RenderText = RenderText;
	params.Scale = Scale;

	ProcessEvent(object, fn, &params);

	return params.ReturnValue;
}

void K2_DrawText(void* object, void* RenderFont, const struct FString& RenderText, const struct FVector2D& ScreenPosition, const struct FVector2D& Scale, const struct FLinearColor& RenderColor, double Kerning, const struct FLinearColor& ShadowColor, const struct FVector2D& ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, const struct FLinearColor& OutlineColor)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Canvas:K2_DrawText"));

	UCanvas_K2_DrawText_Params params;
	params.RenderFont = RenderFont;
	params.RenderText = RenderText;
	params.ScreenPosition = ScreenPosition;
	params.Scale = Scale;
	params.RenderColor = RenderColor;
	params.Kerning = Kerning;
	params.ShadowColor = ShadowColor;
	params.ShadowOffset = ShadowOffset;
	params.bCentreX = bCentreX;
	params.bCentreY = bCentreY;
	params.bOutlined = bOutlined;
	params.OutlineColor = OutlineColor;

	ProcessEvent(object, fn, &params);
}

bool WasInputKeyJustPressed(void* _this, const struct FKey& Key)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerController:WasInputKeyJustPressed"));

	APlayerController_FKey_Params params;
	params.Key = Key;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

bool WasInputKeyJustReleased(void* _this, const struct FKey& Key)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerController:WasInputKeyJustReleased"));

	APlayerController_FKey_Params params;
	params.Key = Key;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

bool IsInputKeyDown(void* _this, const struct FKey& Key)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerController:IsInputKeyDown"));

	APlayerController_FKey_Params params;
	params.Key = Key;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

double STATIC_Sin(double A)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:Sin"));

	UKismetMathLibrary_Double_Params params;
	params.A = A;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

double STATIC_Cos(double A)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:Cos"));

	UKismetMathLibrary_Double_Params params;
	params.A = A;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

double STATIC_Atan2(double Y, double X)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:Atan2"));

	UKismetMathLibrary_Atan2_Params params;
	params.Y = Y;
	params.X = X;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

FRotator GetCameraRotation(void* object)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerCameraManager:GetCameraRotation"));

	APlayerCameraManager_GetCameraRotation_Params params;

	ProcessEvent(object, fn, &params);

	return params.ReturnValue;
}

float GetFOVAngle(void* object)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerCameraManager:GetFOVAngle"));

	APlayerCameraManager_GetFOVAngle_Params params;

	ProcessEvent(object, fn, &params);

	return params.ReturnValue;
}

double STATIC_Tan(double A)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:Tan"));

	UKismetMathLibrary_Double_Params params;
	params.A = A;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

double STATIC_Round(double A)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:Round"));

	UKismetMathLibrary_Double_Params params;
	params.A = A;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

FVector K2_Project(void* object, const struct FVector& WorldLocation)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Canvas:K2_Project"));

	UCanvas_K2_Project_Params params;
	params.WorldLocation = WorldLocation;

	ProcessEvent(object, fn, &params);

	return params.ReturnValue;
}

FVector GetSocketLocation(void* object, const struct FName& InSocketName)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"SceneComponent:GetSocketLocation"));

	USceneComponent_GetSocketLocation_Params params;
	params.InSocketName = InSocketName;

	ProcessEvent(object, fn, &params);

	return params.ReturnValue;
}

void K2_DrawBox(void* object, const struct FVector2D& ScreenPosition, const struct FVector2D& ScreenSize, float Thickness, const struct FLinearColor& RenderColor)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Canvas:K2_DrawBox"));

	UCanvas_K2_DrawBox_Params params;
	params.ScreenPosition = ScreenPosition;
	params.ScreenSize = ScreenSize;
	params.Thickness = Thickness;
	params.RenderColor = RenderColor;

	ProcessEvent(object, fn, &params);
}

void STATIC_GetAllActorsOfClass(void* WorldContextObject, void* ActorClass, TArray<void*>* OutActors)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"GameplayStatics:GetAllActorsOfClass"));

	UGameplayStatics_GetAllActorsOfClass_Params params;
	params.WorldContextObject = WorldContextObject;
	params.ActorClass = ActorClass;

	ProcessEvent(globalObject, fn, &params);

	if (OutActors != nullptr)
		*OutActors = params.OutActors;
}

void AddControllerPitchInput(void* _this, double Val)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Pawn:AddControllerPitchInput"));

	APawn_AddControllerPitchInput_Params params;
	params.Val = (float)Val;

	ProcessEvent(_this, fn, &params);
}

void AddControllerYawInput(void* _this, double Val)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Pawn:AddControllerYawInput"));

	APawn_AddControllerPitchInput_Params params;
	params.Val = (float)Val;

	ProcessEvent(_this, fn, &params);
}

void AddPitchInput(void* _this, double Val)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerController:AddPitchInput"));

	APawn_AddControllerPitchInput_Params params;
	params.Val = (float)Val;

	ProcessEvent(_this, fn, &params);
}

void AddYawInput(void* _this, double Val)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerController:AddYawInput"));

	APawn_AddControllerPitchInput_Params params;
	params.Val = (float)Val;

	ProcessEvent(_this, fn, &params);
}

struct FVector K2_GetActorLocation(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Actor:K2_GetActorLocation"));

	AActor_K2_GetActorLocation_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

struct FRotator K2_GetActorRotation(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Actor:K2_GetActorRotation"));

	AActor_K2_GetActorRotation_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

int GetLootTier(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"BuildingContainer:GetLootTier"));

	ABuildingContainer_GetLootTier_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

struct FString GetPlatform(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerState:GetPlatform"));

	AFortPlayerState_GetPlatform_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

int GetKillScore(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerStateAthena:GetKillScore"));

	AFortPlayerStateAthena_GetKillScore_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

struct FString STATIC_GetObjectName(void* Object)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetSystemLibrary:GetObjectName"));

	UKismetSystemLibrary_GetObjectName_Params params;
	params.Object = Object;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void STATIC_GetFortPawnsInRange( void* WorldContextObject, const struct FVector& SourcePosition, float Range, bool bDo2DCheck, TArray< void*>* OutFortPawns)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary.GetFortPawnsInRange"));

	UFortKismetLibrary_GetFortPawnsInRange_Params params;
	params.WorldContextObject = WorldContextObject;
	params.SourcePosition = SourcePosition;
	params.Range = Range;
	params.bDo2DCheck = bDo2DCheck;

	ProcessEvent(globalObject, fn, &params);

	if (OutFortPawns != nullptr)
		*OutFortPawns = params.OutFortPawns;
}

struct AFortPlayerController_ServerDropAllItems_Params
{
	void* IgnoreItemDef;                                            // (ConstParm, Parm, ZeroConstructor)
};
void ServerDropAllItems(void* _this, void* IgnoreItemDef)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerController:ServerDropAllItems"));

	AFortPlayerController_ServerDropAllItems_Params params;
	params.IgnoreItemDef = IgnoreItemDef;

	ProcessEvent(_this, fn, &params);
}

struct UFortKismetLibrary_GetFortPlayerControllerFromActor_Params
{
	void* Actor;                                                    // (Parm, ZeroConstructor)
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};
void* STATIC_GetFortPlayerControllerFromActor(void* Actor)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:GetFortPlayerControllerFromActor"));

	UFortKismetLibrary_GetFortPlayerControllerFromActor_Params params;
	params.Actor = Actor;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

struct AFortPlayerController_GetTargetedBuilding_Params
{
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};
void* GetTargetedBuilding(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerController.GetTargetedBuilding"));

	AFortPlayerController_GetTargetedBuilding_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}


bool GetMousePosition(void* _this, float* LocationX, float* LocationY)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerController:GetMousePosition"));

	APlayerController_GetMousePosition_Params params;

	ProcessEvent(_this, fn, &params);

	if (LocationX != nullptr)
		*LocationX = params.LocationX;
	if (LocationY != nullptr)
		*LocationY = params.LocationY;

	return params.ReturnValue;
}

bool IsBotControlled(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Pawn:IsBotControlled"));

	APawn_IsBotControlled_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

struct FVector GetActorForwardVector(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Actor:GetActorForwardVector"));

	AActor_GetActorForwardVector_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void ClientTeleportVehicleToLoc(void* _this, const struct FVector& TeleportLocation)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortAthenaVehicle:ClientTeleportVehicleToLoc"));

	AFortAthenaVehicle_ClientTeleportVehicleToLoc_Params params;
	params.TeleportLocation = TeleportLocation;

	ProcessEvent(_this, fn, &params);
}

bool IsDrivingVehicle(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerPawn:IsDrivingVehicle"));

	AFortPlayerPawn_IsDrivingVehicle_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}


bool K2_SetActorRotation(void* _this, const struct FRotator& NewRotation, bool bTeleportPhysics)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Actor:K2_SetActorRotation"));

	AActor_K2_SetActorRotation_Params params;
	params.NewRotation = NewRotation;
	params.bTeleportPhysics = bTeleportPhysics;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

bool K2_SetActorLocation(void* _this, const struct FVector& NewLocation, bool bSweep, bool bTeleport)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Actor:K2_SetActorLocation"));

	AActor_K2_SetActorLocation_Params params;
	params.NewLocation = NewLocation;
	params.bSweep = bSweep;
	params.bTeleport = bTeleport;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

bool K2_SetActorLocationAndRotation(void* _this, const struct FVector& NewLocation, const struct FRotator& NewRotation, bool bSweep, bool bTeleport, void* SweepHitResult)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Actor:K2_SetActorLocationAndRotation"));

	AActor_K2_SetActorLocationAndRotation_Params params;
	params.NewLocation = NewLocation;
	params.NewRotation = NewRotation;
	params.bSweep = bSweep;
	params.bTeleport = bTeleport;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

struct FRotator STATIC_RInterpTo(const struct FRotator& Current, const struct FRotator& Target, float DeltaTime, float InterpSpeed)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:RInterpTo"));

	UKismetMathLibrary_RInterpTo_Params params;
	params.Current = Current;
	params.Target = Target;
	params.DeltaTime = DeltaTime;
	params.InterpSpeed = InterpSpeed;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

float STATIC_GetWorldDeltaSeconds(void* WorldContextObject)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"GameplayStatics:GetWorldDeltaSeconds"));

	UGameplayStatics_GetWorldDeltaSeconds_Params params;
	params.WorldContextObject = WorldContextObject;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

struct FRotator STATIC_FindLookAtRotation(const struct FVector& Start, const struct FVector& Target)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMathLibrary:FindLookAtRotation"));

	UKismetMathLibrary_FindLookAtRotation_Params params;
	params.Start = Start;
	params.Target = Target;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

bool IsDBNO(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPawn:IsDBNO"));

	AFortPawn_IsDBNO_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}
/*
UObject* SC_FortPlayerPawn()
{
	static UClass* obj = 0;
	if (!obj)
		obj = FindMyObject<UClass>(xMe(L"FortniteGame:FortPlayerPawnAthena"));

	return obj;
}

UObject* SC_FortProjectileAthena()
{
	static UClass* obj = 0;
	if (!obj)
		obj = FindMyObject<UClass>(xMe(L"FortniteGame:FortProjectileAthena"));

	return obj;
}
*/
/*
bool ProjectWorldLocationToScreen(void* _this, const struct FVector& WorldLocation, bool bPlayerViewportRelative, struct FVector2D* ScreenLocation)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerController:ProjectWorldLocationToScreen"));

	APlayerController_ProjectWorldLocationToScreen_Params params;
	params.WorldLocation = WorldLocation;
	params.bPlayerViewportRelative = bPlayerViewportRelative;

	ProcessEvent(_this, fn, &params);

	if (ScreenLocation != nullptr)
		*ScreenLocation = params.ScreenLocation;

	return params.ReturnValue;
}
*/

EFortItemTier GetTier(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortItemDefinition:GetTier"));

	UFortItemDefinition_GetTier_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

FLinearColor GetItemColor(EFortItemTier tier)
{
	switch (tier)
	{
	case EFortItemTier::I:
		return FLinearColor(123, 123, 123, 0.95f);
	case EFortItemTier::II:
		return FLinearColor(58, 121, 19, 0.95f);
	case EFortItemTier::III:
		return FLinearColor(18, 88, 162, 0.95f);
	case EFortItemTier::IV:
		return FLinearColor(189, 63, 250, 0.95f);
	case EFortItemTier::V:
		return FLinearColor(255, 118, 5, 0.95f);
	case EFortItemTier::VI:
		return FLinearColor(220, 160, 30, 0.95f);
	case EFortItemTier::VII:
		return FLinearColor(0, 225, 252, 0.95f);
	default:
		return FLinearColor(123, 123, 123, 0.95f);
	}
}

void* GetPrimaryItemDefinition(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPickup:GetPrimaryItemDefinition"));

	AFortPickup_GetPrimaryItemDefinition_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void ServerHandlePickupInfo(void* _this, void* PickUp, const struct FFortPickupRequestInfo& Params)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerPawn:ServerHandlePickupInfo"));

	AFortPlayerPawn_ServerHandlePickupInfo_Params params;
	params.PickUp = PickUp;
	params.Params = Params;

	ProcessEvent(_this, fn, &params);
}

void ServerHandlePickup(void* _this, void* PickUp, float InFlyTime, const struct FVector& InStartDirection, bool bPlayPickupSound)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(L"FortPlayerPawn:ServerHandlePickup");

	AFortPlayerPawn_ServerHandlePickup_Params params;
	params.PickUp = PickUp;
	params.InFlyTime = InFlyTime;
	params.InStartDirection = InStartDirection;
	params.bPlayPickupSound = bPlayPickupSound;

	ProcessEvent(_this, fn, &params);
}

struct FString STATIC_Conv_IntToString(int inInt)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetStringLibrary:Conv_IntToString"));

	UKismetStringLibrary_Conv_IntToString_Params params;
	params.inInt = inInt;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

struct FString STATIC_Concat_StrStr(const struct FString& A, const struct FString& B)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetStringLibrary:Concat_StrStr"));

	UKismetStringLibrary_Concat_StrStr_Params params;
	params.A = A;
	params.B = B;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

FString GetItemTierName(EFortItemTier tier)
{
	switch (tier)
	{
	case EFortItemTier::I:
		return STATIC_Concat_StrStr(xMe(L"Com"), xMe(L"mon"));
	case EFortItemTier::II:
		return STATIC_Concat_StrStr(xMe(L"Unco"), xMe(L"mmon"));
	case EFortItemTier::III:
		return STATIC_Concat_StrStr(xMe(L"Ra"), xMe(L"re"));
	case EFortItemTier::IV:
		return STATIC_Concat_StrStr(xMe(L"Ep"), xMe(L"ic"));
	case EFortItemTier::V:
		return STATIC_Concat_StrStr(xMe(L"Lege"), xMe(L"ndary"));
	case EFortItemTier::VI:
		return STATIC_Concat_StrStr(xMe(L"Myt"), xMe(L"hic"));
	case EFortItemTier::VII:
		return STATIC_Concat_StrStr(xMe(L"Exo"), xMe(L"tic"));
	default:
		return STATIC_Concat_StrStr(xMe(L"Com"), xMe(L"mon"));
	}
}

bool STATIC_IsEmpty(const struct FString& InString)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetStringLibrary.IsEmpty"));

	UKismetStringLibrary_IsEmpty_Params params;
	params.InString = InString;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

bool STATIC_Contains(const struct FString& SearchIn, const struct FString& Substring, bool bUseCase, bool bSearchFromEnd)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetStringLibrary:Contains"));

	UKismetStringLibrary_Contains_Params params;
	params.SearchIn = SearchIn;
	params.Substring = Substring;
	params.bUseCase = bUseCase;
	params.bSearchFromEnd = bSearchFromEnd;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void* STATIC_GetClosestBuildingActorFromArray(void* Actor, TArray<void*> ArrayOfBuildings)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:GetClosestBuildingActorFromArray"));

	UFortKismetLibrary_GetClosestBuildingActorFromArray_Params params;
	params.Actor = Actor;
	params.ArrayOfBuildings = ArrayOfBuildings;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void ServerCreateBuildingActor(void* _this, const struct FCreateBuildingActorData& CreateBuildingData)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerController:ServerCreateBuildingActor"));

	AFortPlayerController_ServerCreateBuildingActor_Params params;
	params.CreateBuildingData = CreateBuildingData;

	ProcessEvent(_this, fn, &params);
}

bool STATIC_CheckLineOfSightToActorWithChannel(const struct FVector& SourcePos, void* Target, TEnumAsByte<ECollisionChannel> TargetFilterChannel, void* Source)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:CheckLineOfSightToActorWithChannel"));
	
	UFortKismetLibrary_CheckLineOfSightToActorWithChannel_Params params;
	params.SourcePos = SourcePos;
	params.Target = Target;
	params.TargetFilterChannel = TargetFilterChannel;
	params.Source = Source;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

bool STATIC_CheckPlayerLineOfSightToPawn(void* SourcePawn, void* TargetPawn)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary.CheckPlayerLineOfSightToPawn"));

	UFortKismetLibrary_CheckPlayerLineOfSightToPawn_Params params;
	params.SourcePawn = SourcePawn;
	params.TargetPawn = TargetPawn;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

bool K2_TeleportTo(void* _this, const struct FVector& DestLocation, const struct FRotator& DestRotation)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Actor:K2_TeleportTo"));

	AActor_K2_TeleportTo_Params params;
	params.DestLocation = DestLocation;
	params.DestRotation = DestRotation;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

bool STATIC_GetActorPvPTeamIndex(void* Actor, unsigned char* TeamIndex)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:GetActorPvPTeamIndex"));

	UFortKismetLibrary_GetActorPvPTeamIndex_Params params;
	params.Actor = Actor;

	ProcessEvent(globalObject, fn, &params);

	if (TeamIndex != nullptr)
		*TeamIndex = params.TeamIndex;

	return params.ReturnValue;
}

void* STATIC_AttemptGetPlayerStateForPawn(void* FortPawn)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:AttemptGetPlayerStateForPawn"));

	UFortKismetLibrary_AttemptGetPlayerStateForPawn_Params params;
	params.FortPawn = FortPawn;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void* STATIC_GetFirstLocalFortPlayerController(void* WorldContextObject, bool bIncludeNonSpectators, bool bIncludeSpectators)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortKismetLibrary:GetFirstLocalFortPlayerController"));

	UFortKismetLibrary_GetFirstLocalFortPlayerController_Params params;
	params.WorldContextObject = WorldContextObject;
	params.bIncludeNonSpectators = bIncludeNonSpectators;
	params.bIncludeSpectators = bIncludeSpectators;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void* GetClientSettings(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortLocalPlayer:GetClientSettings"));

	UFortLocalPlayer_GetClientSettings_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

float GetHUDScale(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortClientSettingsRecord:GetHUDScale"));

	UFortClientSettingsRecord_GetHUDScale_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}
//
//struct UKismetMathLibrary_GetForwardVector_Params
//{
//	struct FRotator                                    InRot;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
//	struct FVector                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
//};
//
//struct FVector STATIC_GetForwardVector(const struct FRotator& InRot)
//{
//	static void* fn = NULL;
//	if (!fn)
//		fn = FindMyObject(xMe(L"KismetMathLibrary.GetForwardVector"));
//
//	UKismetMathLibrary_GetForwardVector_Params params;
//	params.InRot = InRot;
//
//	ProcessEvent(globalObject, fn, &params);
//
//	return params.ReturnValue;
//}

struct FRotator GetControlRotation(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Pawn.GetControlRotation"));

	APawn_GetControlRotation_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

//struct AActor_K2_GetRootComponent_Params
//{
//	void* ReturnValue;                                              // (ExportObject, Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference)
//};
//void* K2_GetRootComponent(void* _this)
//{
//	static void* fn = NULL;
//	if (!fn)
//		fn = FindMyObject(xMe(L"Actor.K2_GetRootComponent"));
//
//	AActor_K2_GetRootComponent_Params params;
//
//	ProcessEvent(_this, fn, &params);
//
//	return params.ReturnValue;
//}
//
//struct USceneComponent_K2_SetRelativeRotation_Params
//{
//	struct FRotator                                    NewRotation;                                              // (Parm, ZeroConstructor, IsPlainOldData)
//	bool                                               bSweep;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
//	void*                                  SweepHitResult;                                           // (Parm, OutParm, IsPlainOldData)
//	bool                                               bTeleport;                                                // (Parm, ZeroConstructor, IsPlainOldData)
//};
//void K2_SetRelativeRotation(void* _this, const struct FRotator& NewRotation, bool bSweep, bool bTeleport)
//{
//	static void* fn = NULL;
//	if (!fn)
//		fn = FindMyObject(xMe(L"SceneComponent.K2_SetRelativeRotation"));
//
//	USceneComponent_K2_SetRelativeRotation_Params params;
//	params.NewRotation = NewRotation;
//	params.bSweep = bSweep;
//	params.bTeleport = bTeleport;
//
//	ProcessEvent(_this, fn, &params);
//}


void* GetMaterial(void* _this, int MaterialIndex)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PrimitiveComponent.GetMaterial"));

	UStaticMesh_GetMaterial_Params params;
	params.MaterialIndex = MaterialIndex;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

struct FLinearColor STATIC_GetVectorParameterValue(void* WorldContextObject, void* Collection, const struct FName& ParameterName)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PrimitiveComponent.GetVectorParameterValue"));

	UKismetMaterialLibrary_GetVectorParameterValue_Params params;
	params.WorldContextObject = WorldContextObject;
	params.Collection = Collection;
	params.ParameterName = ParameterName;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void PawnStartFire(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPawn.PawnStartFire"));

	APlayerController_StartFire_Params params;
	params.FireModeNum = 0;

	ProcessEvent(_this, fn, &params);
}

void PawnStopFire(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPawn.PawnStopFire"));

	APlayerController_StartFire_Params params;
	params.FireModeNum = 0;

	ProcessEvent(_this, fn, &params);
}

void SetVectorParameterValue(void* _this, const struct FName& ParameterName, const struct FLinearColor& Value)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"MaterialInstanceDynamic.SetVectorParameterValue"));

	UMaterialInstanceDynamic_SetVectorParameterValue_Params params;

	params.ParameterName = ParameterName;
	params.Value = Value;

	ProcessEvent(_this, fn, &params);
}

void ApplyPawnHighlight(void* _this, void* Source, FLinearColor InnerCol, FLinearColor OuterCol)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PlayerPawn_Athena_C.ApplyPawnHighlight"));

	FPawnHighlight HitGlow;
	HitGlow.FresnelBrightness_23_52B0F96447FF640F47DF2895B0602E92 = 0.f;
	HitGlow.FresnelExponent_24_B427CF0C441AA37ED49833BF7579DE6D = 0;
	HitGlow.Inner_21_4CC2801147EA190DE16F59B34F36853E = { (float)InnerCol.R, (float)InnerCol.G, (float)InnerCol.B, (float)InnerCol.A };//{ 1.f, 0.f, 0.f, 1.f };//{ (float)col.R, (float)col.G, (float)col.B, (float)col.A };
	HitGlow.Outer_22_5A1D7D0543D303E8B54B66A7F7BD2E2E = { (float)OuterCol.R, (float)OuterCol.G, (float)OuterCol.B, (float)OuterCol.A };//{ 0.f, 1.f, 0.f, 1.f };//{ (float)col.R, (float)col.G, (float)col.B, (float)col.A };
	HitGlow.Priority_28_E2E1B5344846E187B9C11B863A7F0698 = 0.f;
	HitGlow.UsesPulse_25_E29229F64E540F0617E4C4987AD77605 = 0.f;

	APlayerPawn_Athena_C_ApplyPawnHighlight_Params params;
	params.Source = Source;
	params.HitGlow = HitGlow;

	ProcessEvent(_this, fn, &params);
}

TArray<void*> GetMaterials(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"MeshComponent.GetMaterials"));

	UMeshComponent_GetMaterials_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void SetMaterial(void* _this, int ElementIndex, void* Material)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PrimitiveComponent.SetMaterial"));

	UPrimitiveComponent_SetMaterial_Params params;
	params.ElementIndex = ElementIndex;
	params.Material = Material;

	ProcessEvent(_this, fn, &params);
}
int GetNumMaterials(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"PrimitiveComponent.GetNumMaterials"));

	UPrimitiveComponent_GetNumMaterials_Params params;

	ProcessEvent(_this, fn, &params);

	return params.num;
}

void* GetBaseMaterial(void* _this)
{

	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"MaterialInterface.GetBaseMaterial"));

	UMaterialInterface_GetBaseMaterial_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void* STATIC_CreateDynamicMaterialInstance(void* WorldContextObject, void* Parent)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetMaterialLibrary.CreateDynamicMaterialInstance"));

	UKismetMaterialLibrary_CreateDynamicMaterialInstance_Params params;
	params.WorldContextObject = WorldContextObject;
	params.Parent = Parent;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void K2_CopyMaterialInstanceParameters(void* _this, void* Source)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"MaterialInstanceDynamic.K2_CopyMaterialInstanceParameters"));

	UMaterialInstanceDynamic_K2_CopyMaterialInstanceParameters_Params params;
	params.Source = Source;

	ProcessEvent(_this, fn, &params);
}

TEnumAsByte<EFortWeaponCoreAnimation> GetCoreAnimation(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortWeapon.GetCoreAnimation"));

	AFortWeapon_GetCoreAnimation_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void* GetCurrentWeapon(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPawn.GetCurrentWeapon"));

	AFortPawn_GetCurrentWeapon_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void* STATIC_GetPlayerCameraManager(void* gworld)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"GameplayStatics.GetPlayerCameraManager"));
	
	UGameplayStatics_GetPlayerCameraManager_Params params;
	params.WorldContextObject = gworld;
	params.PlayerIndex = 0;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void* STATIC_GetPlayerController(void* gworld)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"GameplayStatics.GetPlayerController"));
	
	UGameplayStatics_GetPlayerController_Params params;
	params.WorldContextObject = gworld;
	params.PlayerIndex = 0;

	ProcessEvent(globalObject, fn, &params);

	return params.ReturnValue;
}

void* STATIC_GetGameInstance(void* WorldContextObject)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"GameplayStatics.GetGameInstance"));

	static void* fno = NULL;
	if (!fno)
		fno = FindMyObject(xMe(L"Engine.Default__GameplayStatics"));

	UGameplayStatics_GetGameInstance_Params params;
	params.WorldContextObject = WorldContextObject;

	ProcessEvent(fno, fn, &params);

	return params.ReturnValue;
}

struct FVector GetLocationUnderReticle(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerController.GetLocationUnderReticle"));

	AFortPlayerController_GetLocationUnderReticle_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void StopMovementImmediately(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"MovementComponent.StopMovementImmediately"));
	
	UMovementComponent_StopMovementImmediately_Params params;

	ProcessEvent(_this, fn, &params);
}

void MoveInterpolationTarget(void* _this, const struct FVector& NewLocation, const struct FRotator& NewRotation)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"ProjectileMovementComponent:MoveInterpolationTarget"));
	
	UProjectileMovementComponent_MoveInterpolationTarget_Params params;
	params.NewLocation = NewLocation;
	params.NewRotation = NewRotation;

	ProcessEvent(_this, fn, &params);
}

bool STATIC_LineTraceSingle(void* world, const struct FVector& Start, const struct FVector& End)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"KismetSystemLibrary.LineTraceSingle"));

	UKismetSystemLibrary_LineTraceSingle_Params params;
	params.WorldContextObject = world;
	params.Start = Start;
	params.End = End;
	params.TraceChannel = ETraceTypeQuery::TraceTypeQuery2;
	params.bTraceComplex = true;
	params.ActorsToIgnore = TArray<void*>();
	params.DrawDebugType = EDrawDebugTrace::None;
	params.bIgnoreSelf = true;
	params.TraceColor = FLinearColor();
	params.TraceHitColor = FLinearColor();
	params.DrawTime = 0.0f;

	ProcessEvent(globalObject, fn, &params);

	return !params.ReverseReturnValue;

	//if (WasInputKeyJustPressed(retired, geyz::F1)) {
	//	system(xMe("cls"));
	//	uint8_t* startAddress = reinterpret_cast<uint8_t*>(&params.ReturnValue);
	//	bool value = *(static_cast<bool*>(PVOID(startAddress + i)));

	//	for (int i = 0; i < 500; ++i)
	//	{
	//		bool value = *(static_cast<bool*>(PVOID(startAddress + i)));
	//		if (value)
	//		{
	//			printf("offset: %d\n", i);
	//		}
	//	}
	//}
}

FVector GetVelocity(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"Actor.GetVelocity"));

	AActor_GetVelocity_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

float GetProjectileSpeed(void* _this, float ChargePercent)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortWeapon.GetProjectileSpeed"));

	AFortWeapon_GetProjectileSpeed_Params params;
	params.ChargePercent = ChargePercent;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

float GetChargePercent(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortWeapon.GetChargePercent"));

	AFortWeapon_GetChargePercent_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

SpecialStruct GetColorFromOption(int num) {
	SpecialStruct skid;
	if (num == 1) {
		skid.name = STATIC_Concat_StrStr(xMe(L"ORA"), xMe(L"NGE"));
		skid.color = FLinearColor(255, 140, 0, 1.0f);
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
	else if (num == 7) {
		skid.name = STATIC_Concat_StrStr(xMe(L"WHI"), xMe(L"TE"));
		skid.color = FLinearColor(255, 255, 255, 1.0f);
	}
	return skid;
}

void* GetVehicleActor(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortPlayerPawn.GetVehicleActor"));

	AFortPlayerPawn_GetVehicleActor_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

float GetGravityScale(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortProjectileBase.GetGravityScale"));

	AFortProjectileBase_GetGravityScale_Params params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void* GetWeaponData(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"FortWeapon.GetWeaponData"));

	struct {
		void* ReturnValue;
	} params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

FVector GetLastUpdateVelocity(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"CharacterMovementComponent.GetLastUpdateVelocity"));

	struct {
		struct FVector ReturnValue;
	} params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}

void* K2_GetWorldSettings(void* _this)
{
	static void* fn = NULL;
	if (!fn)
		fn = FindMyObject(xMe(L"World.K2_GetWorldSettings"));

	struct {
		void* ReturnValue;
	} params;

	ProcessEvent(_this, fn, &params);

	return params.ReturnValue;
}


void SetCustomDepthStencilValue(void* _this, int Value)
{
	static void* fn = 0;
	if (!fn) fn = FindMyObject(xMe(L"PrimitiveComponent.SetCustomDepthStencilValue"));

	struct {
		int Value;
	} Params = { Value };

	ProcessEvent(_this, fn, &Params);
}

void SetRenderCustomDepth(void* _this, bool bValue)
{
	static void* fn = 0;
	if (!fn) fn = FindMyObject(xMe(L"PrimitiveComponent.SetRenderCustomDepth"));

	struct {
		bool bValue;
	} Params = { bValue };

	ProcessEvent(_this, fn, &Params);
}

double FVector::DistancePred(FVector v)
{
	return double(STATIC_Sqrt(LI_FN(pow).safe_cached()(v.X - X, 2.0) + LI_FN(pow).safe_cached()(v.Y - Y, 2.0) + LI_FN(pow).safe_cached()(v.Z - Z, 2.0)));
}

void* GetProjectileTemplate(void* WeaponData)
{
	static void* fn = 0;
	if (!fn) fn = FindMyObject(xMe(L"FortWeaponRangedItemDefinition.GetProjectileTemplate"));
	
	struct {
		void* ReturnValue;
	} params;

	ProcessEvent(WeaponData, fn, &params);

	return params.ReturnValue;
}
bool HasLightweightProjectile(void* WeaponData)
{
	static void* fn = 0;
	if (!fn) fn = FindMyObject(xMe(L"FortWeaponRangedItemDefinition.HasLightweightProjectile"));
	

	struct {
		float ReturnValue;
	} params;

	ProcessEvent(WeaponData, fn, &params);

	return params.ReturnValue;
}
float GetValueAtLevel(FScalableFloat Input, int Level)
{
	static void* fn = 0;
	static void* fn1 = 0;
	if (!fn) fn = FindMyObject(xMe(L"FortScalableFloatUtils.GetValueAtLevel"));
	if (!fn1) fn1 = FindMyObject(xMe(L"FortniteGame.FortScalableFloatUtils"));

	struct {
		FScalableFloat Input;
		int Level;
		float ReturnValue;
	} params = { Input, Level };

	ProcessEvent(fn1, fn, &params);

	return params.ReturnValue;
}