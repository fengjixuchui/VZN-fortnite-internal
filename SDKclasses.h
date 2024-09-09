struct FName
{
	union
	{
		struct
		{
			int ComparisonIndex;
			int Number;
		};

		int CompositeComparisonValue;
	};

	inline FName()
		: ComparisonIndex(0),
		Number(0)
	{
	};

	inline FName(int i)
		: ComparisonIndex(i),
		Number(0)
	{
	};

	inline bool operator==(const FName& other) const
	{
		return ComparisonIndex == other.ComparisonIndex;
	};
};

template<class TEnum>
class TEnumAsByte
{
public:
	inline TEnumAsByte()
	{
	}

	inline TEnumAsByte(TEnum _value)
		: value(static_cast<UINT8>(_value))
	{
	}

	explicit inline TEnumAsByte(UINT32 _value)
		: value(static_cast<UINT8>(_value))
	{
	}

	explicit inline TEnumAsByte(UINT8 _value)
		: value(_value)
	{
	}

	inline operator TEnum() const
	{
		return (TEnum)value;
	}

	inline TEnum GetValue() const
	{
		return (TEnum)value;
	}

private:
	UINT8 value;
};
/*
class UObject
{
public:
	void** Vtable;                                                   // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	UINT32                                            ObjectFlags;                                              // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	UINT32                                            InternalIndex;                                            // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	class UClass* Class;                                                    // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	FName                                              Name;                                                     // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	class UObject* Outer;                                                    // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
};
*/
// Structs
struct FVector
{
	double                                             X;                                                        // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	double                                             Y;                                                        // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	double                                             Z;                                                        // 0x0010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)

	inline FVector()
		: X(0), Y(0), Z(0)
	{ }

	inline FVector(double x, double y, double z)
		: X(x),
		Y(y),
		Z(z)
	{ }

	FVector operator-(const FVector& V) {
		return FVector(X - V.X, Y - V.Y, Z - V.Z);
	}

	FVector operator+(const FVector& V) {
		return FVector(X + V.X, Y + V.Y, Z + V.Z);
	}

	FVector operator*(double Scale) const {
		return FVector(X * Scale, Y * Scale, Z * Scale);
	}

	FVector operator/(double Scale) const {
		const double RScale = 1.f / Scale;
		return FVector(X * RScale, Y * RScale, Z * RScale);
	}

	FVector operator+(double A) const {
		return FVector(X + A, Y + A, Z + A);
	}

	FVector operator-(double A) const {
		return FVector(X - A, Y - A, Z - A);
	}

	FVector operator*(const FVector& V) const {
		return FVector(X * V.X, Y * V.Y, Z * V.Z);
	}

	FVector operator/(const FVector& V) const {
		return FVector(X / V.X, Y / V.Y, Z / V.Z);
	}

	double operator|(const FVector& V) const {
		return X * V.X + Y * V.Y + Z * V.Z;
	}

	double operator^(const FVector& V) const {
		return X * V.Y - Y * V.X - Z * V.Z;
	}

	FVector& operator+=(const FVector& v) {
		X += v.X;
		Y += v.Y;
		Z += v.Z;
		return *this;
	}

	FVector& operator-=(const FVector& v) {
		X -= v.X;
		Y -= v.Y;
		Z -= v.Z;
		return *this;
	}

	FVector& operator*=(const FVector& v) {
		X *= v.X;
		Y *= v.Y;
		Z *= v.Z;
		return *this;
	}

	FVector& operator/=(const FVector& v) {
		X /= v.X;
		Y /= v.Y;
		Z /= v.Z;
		return *this;
	}

	bool operator==(const FVector& src) const {
		return (src.X == X) && (src.Y == Y) && (src.Z == Z);
	}

	bool operator!=(const FVector& src) const {
		return (src.X != X) || (src.Y != Y) || (src.Z != Z);
	}

	double Dot(const FVector& vOther) const {
		const FVector& a = *this;

		return (a.X * vOther.X + a.Y * vOther.Y + a.Z * vOther.Z);
	}

	double Distance(FVector v)
	{
		return ((X - v.X) * (X - v.X) +
			(Y - v.Y) * (Y - v.Y) +
			(Z - v.Z) * (Z - v.Z));
	}

	double DistancePred(FVector v);

	__forceinline double DistanceFrom(const FVector& Other) const {
		const FVector& a = *this;
		double dx = (a.X - Other.X);
		double dy = (a.Y - Other.Y);
		double dz = (a.Z - Other.Z);

		return ((dx * dx) + (dy * dy) + (dz * dz));
	}

	bool IsNearlyZero() const {
		const float Tolerance = 1e-6;
		return (X * X + Y * Y + Z * Z) < Tolerance;
	}
};

struct FRotator
{
	double                                             Pitch;                                                    // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	double                                             Yaw;                                                      // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	double                                             Roll;                                                     // 0x0010(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	
	inline FRotator()
		: Pitch(0), Yaw(0), Roll(0)
	{ }

	inline FRotator(double Pitch, double Yaw, double Roll)
		: Pitch(Pitch),
		Yaw(Yaw),
		Roll(Roll)
	{ }

	FRotator operator-(const FRotator& V) {
		return FRotator(Pitch - V.Pitch, Yaw - V.Yaw, Roll - V.Roll);
	}
};

struct FVector2D
{
	double                                             X;                                                        // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	double                                             Y;                                                        // 0x0008(0x0008) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)

	inline FVector2D()
		: X(0), Y(0)
	{ }

	inline FVector2D(double x, double y)
		: X(x),
		Y(y)
	{ }

	FVector2D operator-(const FVector2D& V) {
		return FVector2D(X - V.X, Y - V.Y);
	}

	FVector2D operator+(const FVector2D& V) {
		return FVector2D(X + V.X, Y + V.Y);
	}

	FVector2D operator*(double Scale) const {
		return FVector2D(X * Scale, Y * Scale);
	}

	FVector2D operator/(double Scale) const {
		const double RScale = 1.f / Scale;
		return FVector2D(X * RScale, Y * RScale);
	}

	FVector2D operator+(double A) const {
		return FVector2D(X + A, Y + A);
	}

	FVector2D operator-(double A) const {
		return FVector2D(X - A, Y - A);
	}

	FVector2D operator*(const FVector2D& V) const {
		return FVector2D(X * V.X, Y * V.Y);
	}

	FVector2D operator/(const FVector2D& V) const {
		return FVector2D(X / V.X, Y / V.Y);
	}

	double operator|(const FVector2D& V) const {
		return X * V.X + Y * V.Y;
	}

	double operator^(const FVector2D& V) const {
		return X * V.Y - Y * V.X;
	}

	FVector2D& operator+=(const FVector2D& v) {
		X += v.X;
		Y += v.Y;
		return *this;
	}

	FVector2D& operator-=(const FVector2D& v) {
		X -= v.X;
		Y -= v.Y;
		return *this;
	}

	FVector2D& operator*=(const FVector2D& v) {
		X *= v.X;
		Y *= v.Y;
		return *this;
	}

	FVector2D& operator/=(const FVector2D& v) {
		X /= v.X;
		Y /= v.Y;
		return *this;
	}

	bool operator==(const FVector2D& src) const {
		return (src.X == X) && (src.Y == Y);
	}

	bool operator!=(const FVector2D& src) const {
		return (src.X != X) || (src.Y != Y);
	}
};

struct FLinearColor
{
	float                                              R;                                                        // 0x0000(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	float                                              G;                                                        // 0x0004(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	float                                              B;                                                        // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)
	float                                              A;                                                        // 0x000C(0x0004) (Edit, BlueprintVisible, ZeroConstructor, SaveGame, IsPlainOldData)

	inline FLinearColor()
		: R(0), G(0), B(0), A(0)
	{ }

	inline FLinearColor(float r, float g, float b, float a)
		: R(r / 255.f),
		G(g / 255.f),
		B(b / 255.f),
		A(a)
	{ }

	bool operator==(const FLinearColor& src) const {
		return (src.R == R) && (src.G == G) && (src.B == B);
	}

};

template<class T>
struct TArray
{
	friend struct FString;

public:
	inline TArray()
	{
		Data = nullptr;
		Count = Max = 0;
	};

	inline int Num() const
	{
		return Count;
	};

	inline T& operator[](int i)
	{
		return Data[i];
	};

	inline const T& operator[](int i) const
	{
		return Data[i];
	};

	inline bool IsValidIndex(int i) const
	{
		return i < Num();
	}

private:
	T* Data;
	UINT32 Count;
	UINT32 Max;
};

inline int custom_wcslen(const wchar_t* string)
{
	int cnt = 0;
	if (string)
	{
		for (; *string != 0; ++string) ++cnt;
	}
	return cnt;
}

struct FString : private TArray<wchar_t>
{
	inline FString()
	{
	};

	inline FString(const wchar_t* other)
	{
		Max = Count = *other ? custom_wcslen(other) + 1 : 0;

		if (Count)
		{
			Data = const_cast<wchar_t*>(other);
		}
	};

	inline bool IsValid() const
	{
		return Data != nullptr;
	}

	inline const wchar_t* c_str() const
	{
		if (Data != nullptr)
			return Data;
		else
			return xMe(L"");
	}
};


//class UFortClientSettingsRecord
//{
//public:
//	unsigned char                                      UnknownData00[0x2e0];
//	float HUDScale;
//};
//
//class ULocalPlayer
//{
//public:
//	unsigned char                                      UnknownData00[0x30];
//	class APlayerController* PlayerController;
//	unsigned char                                      UnknownData01[0x34];
//	void* ViewportClient;
//	unsigned char                                      UnknownData02[0x338];
//	UFortClientSettingsRecord* ClientSettingsRecord;
//};
//
//class UGameInstance
//{
//public:
//	unsigned char                                      UnknownData00[0x38];
//	TArray<class ULocalPlayer*>                        LocalPlayers;
//};
//
//struct UWorld : public UObject { //0x28 from UObject
//	unsigned char UnknownData00[0x180];
//	class UGameInstance* OwningGameInstance;
//};

struct UKismetStringLibrary_Conv_StringToName_Params
{
	struct FString                                     InString;                                                 // (Parm, ZeroConstructor)
	struct FName                                       ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct APlayerController_GetViewportSize_Params
{
	int                                                SizeX;                                                    // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	int                                                SizeY;                                                    // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
};

struct UFortKismetLibrary_GetFortPlayerPawns_Params
{
	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	TArray<void*> ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct AFortWeapon_IsProjectileWeapon_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

enum class ECollisionResponse : UINT8 {
	ECR_Ignore = 0,
	ECR_Overlap = 1,
	ECR_Block = 2,
	ECR_MAX = 3
};

enum class ECollisionChannel : UINT8
{
	ECC_WorldStatic = 0, // legs
	ECC_WorldDynamic = 1,
	ECC_Pawn = 2, //body
	ECC_Visibility = 3,
	ECC_Camera = 4, // legs
	ECC_PhysicsBody = 5, // legs
	ECC_Vehicle = 6,
	ECC_Destructible = 7,
	ECC_EngineTraceChannel1 = 8,
	ECC_EngineTraceChannel2 = 9,
	ECC_EngineTraceChannel3 = 10,
	ECC_EngineTraceChannel4 = 11,
	ECC_EngineTraceChannel5 = 12,
	ECC_EngineTraceChannel6 = 13,
	ECC_GameTraceChannel1 = 14,
	ECC_GameTraceChannel2 = 15,
	ECC_GameTraceChannel3 = 16,
	ECC_GameTraceChannel4 = 17,
	ECC_GameTraceChannel5 = 18,
	ECC_GameTraceChannel6 = 19,
	ECC_GameTraceChannel7 = 20,
	ECC_GameTraceChannel8 = 21,
	ECC_GameTraceChannel9 = 22,
	ECC_GameTraceChannel10 = 23,
	ECC_GameTraceChannel11 = 24,
	ECC_GameTraceChannel12 = 25,
	ECC_GameTraceChannel13 = 26,
	ECC_GameTraceChannel14 = 27,
	ECC_GameTraceChannel15 = 28,
	ECC_GameTraceChannel16 = 29,
	ECC_GameTraceChannel17 = 30,
	ECC_GameTraceChannel18 = 31,
	ECC_OverlapAll_Deprecated = 32,
	ECC_MAX = 33
};

struct UPrimitiveComponent_SetCollisionResponseToAllChannels_Params
{
	TEnumAsByte<ECollisionResponse>                    NewResponse;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};
struct UPrimitiveComponent_SetCollisionResponseToChannel_Params
{
	TEnumAsByte<ECollisionChannel>                     Channel;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ECollisionResponse>                    NewResponse;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

struct AFortProjectileBase_GetOwnerPlayerController_Params
{
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct APlayerCameraManager_GetCameraLocation_Params
{
	struct FVector                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct AController_K2_GetPawn_Params
{
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UFortKismetLibrary_OnSameTeam_Params
{
	void* ActorA;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	void* ActorB;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct AFortPawn_IsDead_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UKismetMathLibrary_Double_Params
{
	double                                              A;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	double                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UCanvas_K2_DrawLine_Params
{
	struct FVector2D                                   ScreenPositionA;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   ScreenPositionB;                                          // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Thickness;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                RenderColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

struct UCanvas_K2_TextSize_Params
{
	void* RenderFont;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     RenderText;                                               // (Parm, ZeroConstructor)
	struct FVector2D                                   Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UCanvas_K2_DrawText_Params
{
	void* RenderFont;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     RenderText;                                               // (Parm, ZeroConstructor)
	struct FVector2D                                   ScreenPosition;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   Scale;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                RenderColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	double                                             Kerning;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                ShadowColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   ShadowOffset;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bCentreX;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bCentreY;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bOutlined;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                OutlineColor;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

struct FKey
{
	struct FName                                       KeyName;                                                  // 0x0000(0x0008) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x10];                                      // 0x0004(0x0014) MISSED OFFSET
};

struct APlayerController_FKey_Params
{
	struct FKey                                        Key;                                                      // (Parm)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UCanvas_K2_DrawBox_Params
{
	struct FVector2D                                   ScreenPosition;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector2D                                   ScreenSize;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              Thickness;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                RenderColor;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

struct USceneComponent_GetSocketLocation_Params
{
	struct FName                                       InSocketName;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UCanvas_K2_Project_Params
{
	struct FVector                                     WorldLocation;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct APlayerCameraManager_GetFOVAngle_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct APlayerCameraManager_GetCameraRotation_Params
{
	struct FRotator                                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct APlayerController_GetMousePosition_Params
{
	float                                              LocationX;                                                // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	float                                              LocationY;                                                // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UKismetMathLibrary_Atan2_Params
{
	double                                              Y;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	double                                              X;                                                        // (Parm, ZeroConstructor, IsPlainOldData)
	double                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct APawn_IsBotControlled_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Enums
enum class EFortItemTier : uint8_t
{
	No_Tier = 0,
	I = 1,
	II = 2,
	III = 3,
	IV = 4,
	V = 5,
	VI = 6,
	VII = 7,
	VIII = 8,
	IX = 9,
	X = 10,
	NumItemTierValues = 11,
	EFortItemTier_MAX = 12
};

class FTextData {
public:
	char pad_0x0000[0x28];  //0x0000
	wchar_t* Name;          //0x0028 
	__int32 Length;         //0x0030 
};

struct FText {
	FTextData* Data;
	char UnknownData[0x10];

	wchar_t* GetText() const {
		if (Data)
			return Data->Name;

		return nullptr;
	}
};
/*
class UFortItemDefinition
{
public:
	unsigned char                                      UnknownData00[0x74];
	EFortItemTier                                      Tier;                                                     // 0x0074(0x0001) (Edit, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData01[0x18];
	struct FText                                       DisplayName;
};

struct FFortItemEntry
{
	unsigned char                                      UnknownData00[0x18];                                       // 0x0014(0x0004) MISSED OFFSET
	class UFortItemDefinition* ItemDefinition;                                           // 0x0018(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, SaveGame, IsPlainOldData)
};
*/
//
//class AFortPickupAthena
//{
//public:
//	unsigned char                                      UnknownData00[0x2f8];                                       // 0x0014(0x0004) MISSED OFFSET
//	struct FFortItemEntry                              PrimaryPickupItemEntry;
//};

struct UKismetSystemLibrary_GetObjectName_Params
{
	void* Object;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};
/*
// Class CoreUObject.Field
// 0x0008 (0x0030 - 0x0028)
class UField : public UObject
{
public:
	class UField* Next;                                                     // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
};

//
//// Class CoreUObject.Struct
//// 0x0080 (0x00B0 - 0x0030)
class UStruct : public UField
{
public:
	char                                               pad_0030[0x10];                                           // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	class UStruct* SuperField;                                               // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	class UField* Children;                                                 // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	void* ChildProperties;                                          // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	UINT32                                            PropertySize;                                             // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	UINT32                                            MinAlignment;                                             // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
	char                                               pad_0060[0x50];                                           // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
};

class UClass : public UStruct
{
public:
	unsigned char                                      UnknownData00[0x180];                                     // 0x00B0(0x0180) MISSED OFFSET
};
*/
//
//class UFunction : public UStruct
//{
//public:
//	UINT32                                            FunctionFlags;                                            // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	UINT8                                             NumParms;                                                 // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	UINT16                                            RepOffset;                                                // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	char                                               pad_00B7[1];                                              // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	UINT16                                            ParmsSize;                                                // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	UINT16                                            ReturnValueOffset;                                        // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	UINT16                                            RPCId;                                                    // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	UINT16                                            RPCResponseId;                                            // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	class UProperty* FirstPropertyToInit;                                      // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	class UFunction* EventGraphFunction;                                       // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	UINT32                                            EventGraphCallOffset;                                     // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	char                                               pad_00D4[4];                                              // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//	void* Func;                                                     // 0x0000(0x0000) NOT AUTO-GENERATED PROPERTY
//};
//
//class APlayerController
//{
//public:
//	unsigned char                                      UnknownData00[0x328];
//	void* PlayerCameraManager;                                      // 0x0328(0x0008) (BlueprintVisible, BlueprintReadOnly, ZeroConstructor, IsPlainOldData)
//	unsigned char                                      UnknownData01[0x1B8];
//	void* NetConnection;                                            // 0x04E8(0x0008) (ZeroConstructor, DuplicateTransient, IsPlainOldData)
//	FRotator RotationInput;
//	unsigned char                                      UnknownData02[0x10];
//	float                                              InputYawScale;                                            // 0x0508(0x0004) (ZeroConstructor, Config, Deprecated, IsPlainOldData)
//	float                                              InputPitchScale;                                          // 0x050C(0x0004) (ZeroConstructor, Config, Deprecated, IsPlainOldData)
//};
//
//class tryaim {
//public:
//	unsigned char                                      UnknownData00[0x4E8];
//	void* NetConnection;                                            // 0x04E8(0x0008) (ZeroConstructor, DuplicateTransient, IsPlainOldData)
//	FRotator RotationInput;
//};
struct AFortWeapon_GetWeaponDataItemType_Params
{
	uint8_t                                      ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
struct UFortKismetLibrary_GetHumanReadableName_Params
{
	void* Actor;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct APawn_AddControllerPitchInput_Params
{
	float                                              Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};
/*
struct APawn_AddControllerYawInput_Params
{
	float                                              Val;                                                      // (Parm, ZeroConstructor, IsPlainOldData)
};*/

//class ChestTest {
//public:
//	//unsigned char                                      UnknownData00[0xfd8];                                      // 0x0D68(0x0010) MISSED OFFSET
//	//float                        SearchSpeed;
//	unsigned char                                      UnknownData00[0x1034];                                      // 0x0D68(0x0010) MISSED OFFSET
//	float                                              TimeUntilLootRegenerates;
//};

struct ABuildingContainer_GetLootTier_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

//class ABuildingContainer
//{
//public:
//	unsigned char                                      UnknownData00[0xFB9];                                      // 0x0D68(0x0010) MISSED OFFSET
//	unsigned char                                      bUseLootProperties_Athena : 1;                            // 0x0F51(0x0001) (Edit, BlueprintVisible)
//	unsigned char                                      bAlwaysShowContainer : 1;                                 // 0x0F51(0x0001) (Edit, BlueprintVisible)
//	unsigned char                                      bAlwaysMaintainLoot : 1;                                  // 0x0F51(0x0001) (Edit)
//	unsigned char                                      bDestroyContainerOnSearch : 1;                            // 0x0F51(0x0001) (Edit, BlueprintVisible)
//	unsigned char                                      bForceHidePickupMinimapIndicator : 1;                     // 0x0F51(0x0001) (Edit, BlueprintVisible)
//	unsigned char                                      bForceSpawnLootOnDestruction : 1;                         // 0x0F51(0x0001) (Edit, BlueprintVisible)
//	unsigned char                                      bForceTossLootOnSpawn : 1;                                // 0x0F51(0x0001) (Edit, BlueprintVisible)
//	unsigned char                                      bAlreadySearched : 1;                                     // 0x0F51(0x0001) (BlueprintVisible, Net, Transient)
//	unsigned char                                      bDoNotDropLootOnDestruction : 1;                          // 0x0F52(0x0001) (Edit)
//	unsigned char                                      UnknownData05 : 2;                                        // 0x0F52(0x0001)
//	unsigned char                                      bBuriedTreasure : 1;                                      // 0x0F52(0x0001) (Edit, BlueprintVisible)
//	unsigned char                                      bHasRaisedTreasure : 1;                                   // 0x0F52(0x0001) (Edit, BlueprintVisible)
//};

struct AActor_K2_GetActorLocation_Params
{
	struct FVector                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
struct AActor_K2_GetActorRotation_Params
{
	struct FRotator                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
//struct UKismetMathLibrary_RInterpTo_Params
//{
//	struct FRotator                                    Current;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
//	struct FRotator                                    Target;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
//	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
//	float                                              InterpSpeed;                                              // (Parm, ZeroConstructor, IsPlainOldData)
//	struct FRotator                                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
//};

//struct UGameplayStatics_GetWorldDeltaSeconds_Params
//{
//	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
//	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
//};

/*
struct UKismetMathLibrary_FindLookAtRotation_Params
{
	struct FVector                                     Start;                                                    // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
	struct FVector                                     Target;                                                   // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
	struct FRotator                                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
*/

//class UFortWeaponItemDefinition {
//public:
//	unsigned char                                      UnknownData00[0x74];
//	EFortItemTier Tier;
//	unsigned char                                      UnknownData01[0x14];
//	FText DisplayName;
//};

//class AFortWeapon {
//public:
//	unsigned char                                      UnknownData00[0x311];
//	bool bIsReloadingWeapon; //0x311
//	unsigned char                                      UnknownData01[0xC0];
//	UFortWeaponItemDefinition* WeaponData; //0x3d8
//	//unsigned char                                      UnknownData02[0xA80];
//	//EFortWeaponCoreAnimation						   WeaponCoreAnimation; // 0xe60
//};

//class AActor
//{
//public:
//	unsigned char                                      UnknownData06[0x128];
//	FVector RelativeLocation;
//};
//
//void
//{
//public:
//	unsigned char                                      UnknownData06[0x188];
//	class AActor* RootComponent;
//	unsigned char                                      UnknownData00[0x100];
//	void* PlayerState;
//	unsigned char                                      UnknownData07[0x58];
//	void* Mesh;                                                     // 0x02F0(0x0008) (Edit, BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, EditConst, InstancedReference, IsPlainOldData)
//
//	unsigned char                                      UnknownData01[0x452];
//	unsigned char                                      bTreatAsPawnForHitMarkers : 1;                            // 0x06F2(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
//	unsigned char                                      bDisplayPawnHitMarkersForChildActors : 1;                 // 0x74a(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
//	unsigned char                                      bUsesStats : 1;                                           // 0x74a(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
//	unsigned char                                      bAllowBuildingActorTeleport : 1;                          // 0x74a(0x0001) (Edit, BlueprintVisible, BlueprintReadOnly)
//	unsigned char                                      bIsDBNO : 1;                                              // 0x74a(0x0001) (BlueprintVisible, BlueprintReadOnly, Net)
//	// must always show +1
//	unsigned char                                      UnknownData02[0x9E];
//	class AFortWeapon* CurrentWeapon;
//};

struct AFortPlayerState_GetPlatform_Params
{
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct AFortPlayerStateAthena_GetKillScore_Params
{
	int                                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

// Function Engine.GameplayStatics.GetAllActorsOfClass
struct UGameplayStatics_GetAllActorsOfClass_Params
{
	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	void* ActorClass;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<void*>                              OutActors;                                                // (Parm, OutParm, ZeroConstructor)
};

//class ABuildingWeakSpot
//{
//public:
//	unsigned char                                      UnknownData00[0x298];                                      // 0x0278(0x0020) MISSED OFFSET
//	void* ParentObject;                                             // 0x0298(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
//	unsigned char                                      bHit : 1;                                                 // 0x02A0(0x0001) (BlueprintVisible, BlueprintReadOnly)
//	unsigned char                                      bFadeOut : 1;                                             // 0x02A0(0x0001) (BlueprintVisible, BlueprintReadOnly)
//	unsigned char                                      bActive : 1;                                              // 0x02A0(0x0001) (BlueprintVisible, BlueprintReadOnly)
//};

//struct AFortPlayerPawn_IsDrivingVehicle_Params {
//	bool ReturnValue;
//};

struct AActor_GetActorForwardVector_Params
{
	struct FVector                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

//class carfly {
//public:
//	unsigned char                                      UnknownData00[0x21b8];                                      // 0x0278(0x0020) MISSED OFFSET
//	UObject* CurrentVehicle;                                             // 0x0298(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
//};

struct AFortAthenaVehicle_ClientTeleportVehicleToLoc_Params
{
	struct FVector                                     TeleportLocation;                                         // (ConstParm, Parm, ZeroConstructor, ReferenceParm, IsPlainOldData)
};
// Function Engine.Actor.K2_SetActorRotation
struct AActor_K2_SetActorRotation_Params
{
	struct FRotator                                    NewRotation;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bTeleportPhysics;                                         // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct AActor_K2_SetActorLocation_Params
{
	struct FVector                                     NewLocation;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bSweep;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	void* SweepHitResult;                                           // (Parm, OutParm, IsPlainOldData)
	bool                                               bTeleport;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct AActor_K2_SetActorLocationAndRotation_Params
{
	struct FVector                                     NewLocation;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FRotator                                    NewRotation;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bSweep;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	void* SweepHitResult;                                           // (Parm, OutParm, IsPlainOldData)
	bool                                               bTeleport;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UKismetMathLibrary_RInterpTo_Params
{
	struct FRotator                                    Current;                                                  // (Parm, ZeroConstructor, IsPlainOldData)
	struct FRotator                                    Target;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              DeltaTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              InterpSpeed;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FRotator                                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UGameplayStatics_GetWorldDeltaSeconds_Params
{
	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UKismetMathLibrary_FindLookAtRotation_Params
{
	struct FVector                                     Start;                                                    // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
	struct FVector                                     Target;                                                   // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
	struct FRotator                                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct AFortPawn_IsDBNO_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UFortItemDefinition_GetTier_Params
{
	EFortItemTier                                      ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
struct AFortPickup_GetPrimaryItemDefinition_Params
{
	void* ReturnValue;                                              // (ConstParm, Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
struct FGuid
{
	int32_t                                                A;                                                        // 0x0000(0x0004) (Edit, ZeroConstructor, SaveGame, IsPlainOldData)
	int32_t                                                B;                                                        // 0x0004(0x0004) (Edit, ZeroConstructor, SaveGame, IsPlainOldData)
	int32_t                                                C;                                                        // 0x0008(0x0004) (Edit, ZeroConstructor, SaveGame, IsPlainOldData)
	int32_t                                                D;                                                        // 0x000C(0x0004) (Edit, ZeroConstructor, SaveGame, IsPlainOldData)
};
struct FFortPickupRequestInfo
{
	struct FGuid                                       SwapWithItem;                                             // 0x0000(0x0010) (ZeroConstructor, IsPlainOldData)
	float                                              FlyTime;                                                  // 0x0010(0x0004) (ZeroConstructor, IsPlainOldData)
	struct FVector                                     Direction;                                                // 0x0014(0x000C) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      bPlayPickupSound : 1;                                     // 0x0020(0x0001)
	unsigned char                                      bIsAutoPickup : 1;                                        // 0x0020(0x0001)
	unsigned char                                      bUseRequestedSwap : 1;                                    // 0x0020(0x0001)
	unsigned char                                      bTrySwapWithWeapon : 1;                                   // 0x0020(0x0001)
	unsigned char                                      bIsVisualOnlyPickup : 1;                                  // 0x0020(0x0001)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0021(0x0003) MISSED OFFSET
};
struct AFortPlayerPawn_ServerHandlePickupInfo_Params
{
	void* PickUp;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FFortPickupRequestInfo                      Params;                                                   // (Parm)
};
struct AFortPlayerPawn_ServerHandlePickup_Params
{
	void* PickUp;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              InFlyTime;                                                // (Parm, ZeroConstructor, IsPlainOldData)
	struct FVector                                     InStartDirection;                                         // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bPlayPickupSound;                                         // (Parm, ZeroConstructor, IsPlainOldData)
};
struct UKismetStringLibrary_Conv_IntToString_Params
{
	int                                                inInt;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};
struct UKismetStringLibrary_Concat_StrStr_Params
{
	struct FString                                     A;                                                        // (Parm, ZeroConstructor)
	struct FString                                     B;                                                        // (Parm, ZeroConstructor)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};
struct UKismetStringLibrary_Contains_Params
{
	struct FString                                     SearchIn;                                                 // (Parm, ZeroConstructor)
	struct FString                                     Substring;                                                // (Parm, ZeroConstructor)
	bool                                               bUseCase;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bSearchFromEnd;                                           // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
struct FBuildingClassData
{
	void* BuildingClass;                                            // 0x0000(0x0008) (ZeroConstructor, Transient, IsPlainOldData)
	int                                                PreviousBuildingLevel;                                    // 0x0008(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UpgradeLevel;                                             // 0x000C(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x000D(0x0003) MISSED OFFSET
};

// ScriptStruct FortniteGame.CreateBuildingActorData
// 0x0038
struct FCreateBuildingActorData
{
	uint32_t                                           BuildingClassHandle;                                      // 0x0000(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	struct FVector                       BuildLoc;                                                 // 0x0004(0x000C) (Transient)
	struct FRotator                                    BuildRot;                                                 // 0x0010(0x000C) (ZeroConstructor, Transient, IsPlainOldData)
	bool                                               bMirrored;                                                // 0x001C(0x0001) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x001D(0x0003) MISSED OFFSET
	float                                              SyncKey;                                                  // 0x0020(0x0004) (ZeroConstructor, Transient, IsPlainOldData)
	unsigned char                                      UnknownData01[0x4];                                       // 0x0024(0x0004) MISSED OFFSET
	struct FBuildingClassData                          BuildingClassData;                                        // 0x0028(0x0010) (Transient)
};

struct AFortPlayerController_ServerCreateBuildingActor_Params
{
	struct FCreateBuildingActorData                    CreateBuildingData;                                       // (Parm)
};

struct UFortKismetLibrary_GetClosestBuildingActorFromArray_Params
{
	void* Actor;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	TArray<void*>                    ArrayOfBuildings;                                         // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	class ABuildingSMActor* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct SpecialStruct
{
	struct FString name;
	struct FLinearColor color;
};

struct UFortKismetLibrary_CheckLineOfSightToActorWithChannel_Params
{
	struct FVector                                     SourcePos;                                                // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
	void* Target;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ECollisionChannel>                     TargetFilterChannel;                                      // (Parm, ZeroConstructor, IsPlainOldData)
	void* Source;                                                   // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct AFortPlayerPawn_IsDrivingVehicle_Params
{
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct AActor_K2_TeleportTo_Params
{
	struct FVector                                     DestLocation;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	struct FRotator                                    DestRotation;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UFortKismetLibrary_GetActorPvPTeamIndex_Params
{
	void* Actor;                                                    // (ConstParm, Parm, ZeroConstructor)
	unsigned char                                      TeamIndex;                                                // (Parm, OutParm, ZeroConstructor, IsPlainOldData)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UFortKismetLibrary_AttemptGetPlayerStateForPawn_Params
{
	void* FortPawn;                                                 // (ConstParm, Parm, ZeroConstructor)
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct UFortLocalPlayer_GetClientSettings_Params
{
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct UFortClientSettingsRecord_GetHUDScale_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct UKismetStringLibrary_IsEmpty_Params
{
	struct FString                                     InString;                                                 // (Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct APawn_GetControlRotation_Params
{
	struct FRotator                                    ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};
struct UKismetStringLibrary_Conv_NameToString_Params
{
	struct FName                                       InName;                                                   // (Parm, ZeroConstructor, IsPlainOldData)
	struct FString                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct FVector4 {
	double X; // 0x00(0x08)
	double Y; // 0x08(0x08)
	double Z; // 0x10(0x08)
	double W; // 0x18(0x08)
};

enum class EBloomMethod : UINT8 {
	BM_SOG = 0,
	BM_FFT = 1,
	BM_MAX = 2
};
// Enum Engine.EAutoExposureMethod
enum class EAutoExposureMethod : UINT8 {
	AEM_Histogram = 0,
	AEM_Basic = 1,
	AEM_Manual = 2,
	AEM_MAX = 3
};
enum class ETemperatureMethod : UINT8 {
	TEMP_WhiteBalance = 0,
	TEMP_ColorTemperature = 1,
	TEMP_MAX = 2
};
enum class EDynamicGlobalIlluminationMethod : UINT8 {
	None = 0,
	Lumen = 1,
	ScreenSpace = 2,
	RayTraced = 3,
	Plugin = 4,
	EDynamicGlobalIlluminationMethod_MAX = 5
};

// Enum Engine.EReflectionMethod
enum class EReflectionMethod : UINT8 {
	None = 0,
	Lumen = 1,
	ScreenSpace = 2,
	RayTraced = 3,
	EReflectionMethod_MAX = 4
};

// Enum Engine.ERayTracingGlobalIlluminationType
enum class ERayTracingGlobalIlluminationType : UINT8 {
	Disabled = 0,
	BruteForce = 1,
	FinalGather = 2,
	ERayTracingGlobalIlluminationType_MAX = 3
};
enum class EReflectionsType : UINT8 {
	ScreenSpace = 0,
	RayTracing = 1,
	EReflectionsType_MAX = 2
};
enum class ELumenRayLightingModeOverride : UINT8 {
	Default = 0,
	SurfaceCache = 1,
	HitLighting = 2,
	ELumenRayLightingModeOverride_MAX = 3
};
enum class EReflectedAndRefractedRayTracedShadows : UINT8 {
	Disabled = 0,
	Hard_shadows = 1,
	Area_shadows = 2,
	EReflectedAndRefractedRayTracedShadows_MAX = 3
};
enum class ETranslucencyType : UINT8 {
	Raster = 0,
	RayTracing = 1,
	ETranslucencyType_MAX = 2
};

struct FWeightedBlendables {
	struct TArray<void*> Array; // 0x00(0x10)
};


struct FPostProcessSettings {
	char bOverride_TemperatureType : 1; // 0x00(0x01)
	char bOverride_WhiteTemp : 1; // 0x00(0x01)
	char bOverride_WhiteTint : 1; // 0x00(0x01)
	char bOverride_ColorSaturation : 1; // 0x00(0x01)
	char bOverride_ColorContrast : 1; // 0x00(0x01)
	char bOverride_ColorGamma : 1; // 0x00(0x01)
	char bOverride_ColorGain : 1; // 0x00(0x01)
	char bOverride_ColorOffset : 1; // 0x00(0x01)
	char bOverride_ColorSaturationShadows : 1; // 0x01(0x01)
	char bOverride_ColorContrastShadows : 1; // 0x01(0x01)
	char bOverride_ColorGammaShadows : 1; // 0x01(0x01)
	char bOverride_ColorGainShadows : 1; // 0x01(0x01)
	char bOverride_ColorOffsetShadows : 1; // 0x01(0x01)
	char bOverride_ColorSaturationMidtones : 1; // 0x01(0x01)
	char bOverride_ColorContrastMidtones : 1; // 0x01(0x01)
	char bOverride_ColorGammaMidtones : 1; // 0x01(0x01)
	char bOverride_ColorGainMidtones : 1; // 0x02(0x01)
	char bOverride_ColorOffsetMidtones : 1; // 0x02(0x01)
	char bOverride_ColorSaturationHighlights : 1; // 0x02(0x01)
	char bOverride_ColorContrastHighlights : 1; // 0x02(0x01)
	char bOverride_ColorGammaHighlights : 1; // 0x02(0x01)
	char bOverride_ColorGainHighlights : 1; // 0x02(0x01)
	char bOverride_ColorOffsetHighlights : 1; // 0x02(0x01)
	char bOverride_ColorCorrectionShadowsMax : 1; // 0x02(0x01)
	char bOverride_ColorCorrectionHighlightsMin : 1; // 0x03(0x01)
	char bOverride_ColorCorrectionHighlightsMax : 1; // 0x03(0x01)
	char bOverride_BlueCorrection : 1; // 0x03(0x01)
	char bOverride_ExpandGamut : 1; // 0x03(0x01)
	char bOverride_ToneCurveAmount : 1; // 0x03(0x01)
	char bOverride_FilmSlope : 1; // 0x03(0x01)
	char bOverride_FilmToe : 1; // 0x03(0x01)
	char bOverride_FilmShoulder : 1; // 0x03(0x01)
	char bOverride_FilmBlackClip : 1; // 0x04(0x01)
	char bOverride_FilmWhiteClip : 1; // 0x04(0x01)
	char bOverride_SceneColorTint : 1; // 0x04(0x01)
	char bOverride_SceneFringeIntensity : 1; // 0x04(0x01)
	char bOverride_ChromaticAberrationStartOffset : 1; // 0x04(0x01)
	char bOverride_AmbientCubemapTint : 1; // 0x04(0x01)
	char bOverride_AmbientCubemapIntensity : 1; // 0x04(0x01)
	char bOverride_BloomMethod : 1; // 0x04(0x01)
	char bOverride_BloomIntensity : 1; // 0x05(0x01)
	char bOverride_BloomThreshold : 1; // 0x05(0x01)
	char bOverride_Bloom1Tint : 1; // 0x05(0x01)
	char bOverride_Bloom1Size : 1; // 0x05(0x01)
	char bOverride_Bloom2Size : 1; // 0x05(0x01)
	char bOverride_Bloom2Tint : 1; // 0x05(0x01)
	char bOverride_Bloom3Tint : 1; // 0x05(0x01)
	char bOverride_Bloom3Size : 1; // 0x05(0x01)
	char bOverride_Bloom4Tint : 1; // 0x06(0x01)
	char bOverride_Bloom4Size : 1; // 0x06(0x01)
	char bOverride_Bloom5Tint : 1; // 0x06(0x01)
	char bOverride_Bloom5Size : 1; // 0x06(0x01)
	char bOverride_Bloom6Tint : 1; // 0x06(0x01)
	char bOverride_Bloom6Size : 1; // 0x06(0x01)
	char bOverride_BloomSizeScale : 1; // 0x06(0x01)
	char bOverride_BloomConvolutionTexture : 1; // 0x06(0x01)
	char bOverride_BloomConvolutionScatterDispersion : 1; // 0x07(0x01)
	char bOverride_BloomConvolutionSize : 1; // 0x07(0x01)
	char bOverride_BloomConvolutionCenterUV : 1; // 0x07(0x01)
	char bOverride_BloomConvolutionPreFilter : 1; // 0x07(0x01)
	char bOverride_BloomConvolutionPreFilterMin : 1; // 0x07(0x01)
	char bOverride_BloomConvolutionPreFilterMax : 1; // 0x07(0x01)
	char bOverride_BloomConvolutionPreFilterMult : 1; // 0x07(0x01)
	char bOverride_BloomConvolutionBufferScale : 1; // 0x07(0x01)
	char bOverride_BloomDirtMaskIntensity : 1; // 0x08(0x01)
	char bOverride_BloomDirtMaskTint : 1; // 0x08(0x01)
	char bOverride_BloomDirtMask : 1; // 0x08(0x01)
	char bOverride_CameraShutterSpeed : 1; // 0x08(0x01)
	char bOverride_CameraISO : 1; // 0x08(0x01)
	char bOverride_AutoExposureMethod : 1; // 0x08(0x01)
	char bOverride_AutoExposureLowPercent : 1; // 0x08(0x01)
	char bOverride_AutoExposureHighPercent : 1; // 0x08(0x01)
	char bOverride_AutoExposureMinBrightness : 1; // 0x09(0x01)
	char bOverride_AutoExposureMaxBrightness : 1; // 0x09(0x01)
	char bOverride_AutoExposureCalibrationConstant : 1; // 0x09(0x01)
	char bOverride_AutoExposureSpeedUp : 1; // 0x09(0x01)
	char bOverride_AutoExposureSpeedDown : 1; // 0x09(0x01)
	char bOverride_AutoExposureBias : 1; // 0x09(0x01)
	char bOverride_AutoExposureBiasCurve : 1; // 0x09(0x01)
	char bOverride_AutoExposureMeterMask : 1; // 0x09(0x01)
	char bOverride_AutoExposureApplyPhysicalCameraExposure : 1; // 0x0a(0x01)
	char bOverride_HistogramLogMin : 1; // 0x0a(0x01)
	char bOverride_HistogramLogMax : 1; // 0x0a(0x01)
	char bOverride_LocalExposureContrastScale : 1; // 0x0a(0x01)
	char bOverride_LocalExposureHighlightContrastScale : 1; // 0x0a(0x01)
	char bOverride_LocalExposureShadowContrastScale : 1; // 0x0a(0x01)
	char bOverride_LocalExposureDetailStrength : 1; // 0x0a(0x01)
	char bOverride_LocalExposureBlurredLuminanceBlend : 1; // 0x0a(0x01)
	char bOverride_LocalExposureBlurredLuminanceKernelSizePercent : 1; // 0x0b(0x01)
	char bOverride_LocalExposureMiddleGreyBias : 1; // 0x0b(0x01)
	char bOverride_LensFlareIntensity : 1; // 0x0b(0x01)
	char bOverride_LensFlareTint : 1; // 0x0b(0x01)
	char bOverride_LensFlareTints : 1; // 0x0b(0x01)
	char bOverride_LensFlareBokehSize : 1; // 0x0b(0x01)
	char bOverride_LensFlareBokehShape : 1; // 0x0b(0x01)
	char bOverride_LensFlareThreshold : 1; // 0x0b(0x01)
	char bOverride_VignetteIntensity : 1; // 0x0c(0x01)
	char bOverride_GrainIntensity : 1; // 0x0c(0x01)
	char bOverride_GrainJitter : 1; // 0x0c(0x01)
	char bOverride_FilmGrainIntensity : 1; // 0x0c(0x01)
	char bOverride_FilmGrainIntensityShadows : 1; // 0x0c(0x01)
	char bOverride_FilmGrainIntensityMidtones : 1; // 0x0c(0x01)
	char bOverride_FilmGrainIntensityHighlights : 1; // 0x0c(0x01)
	char bOverride_FilmGrainShadowsMax : 1; // 0x0c(0x01)
	char bOverride_FilmGrainHighlightsMin : 1; // 0x0d(0x01)
	char bOverride_FilmGrainHighlightsMax : 1; // 0x0d(0x01)
	char bOverride_FilmGrainTexelSize : 1; // 0x0d(0x01)
	char bOverride_FilmGrainTexture : 1; // 0x0d(0x01)
	char bOverride_AmbientOcclusionIntensity : 1; // 0x0d(0x01)
	char bOverride_AmbientOcclusionStaticFraction : 1; // 0x0d(0x01)
	char bOverride_AmbientOcclusionRadius : 1; // 0x0d(0x01)
	char bOverride_AmbientOcclusionFadeDistance : 1; // 0x0d(0x01)
	char bOverride_AmbientOcclusionFadeRadius : 1; // 0x0e(0x01)
	char bOverride_AmbientOcclusionDistance : 1; // 0x0e(0x01)
	char bOverride_AmbientOcclusionRadiusInWS : 1; // 0x0e(0x01)
	char bOverride_AmbientOcclusionPower : 1; // 0x0e(0x01)
	char bOverride_AmbientOcclusionBias : 1; // 0x0e(0x01)
	char bOverride_AmbientOcclusionQuality : 1; // 0x0e(0x01)
	char bOverride_AmbientOcclusionMipBlend : 1; // 0x0e(0x01)
	char bOverride_AmbientOcclusionMipScale : 1; // 0x0e(0x01)
	char bOverride_AmbientOcclusionMipThreshold : 1; // 0x0f(0x01)
	char bOverride_AmbientOcclusionTemporalBlendWeight : 1; // 0x0f(0x01)
	char pad_F_2 : 6; // 0x0f(0x01)
	char bOverride_RayTracingAO : 1; // 0x10(0x01)
	char bOverride_RayTracingAOSamplesPerPixel : 1; // 0x10(0x01)
	char bOverride_RayTracingAOIntensity : 1; // 0x10(0x01)
	char bOverride_RayTracingAORadius : 1; // 0x10(0x01)
	char pad_10_4 : 4; // 0x10(0x01)
	char pad_11[0x3]; // 0x11(0x03)
	char bOverride_LPVIntensity : 1; // 0x14(0x01)
	char bOverride_LPVDirectionalOcclusionIntensity : 1; // 0x14(0x01)
	char bOverride_LPVDirectionalOcclusionRadius : 1; // 0x14(0x01)
	char bOverride_LPVDiffuseOcclusionExponent : 1; // 0x14(0x01)
	char bOverride_LPVSpecularOcclusionExponent : 1; // 0x14(0x01)
	char bOverride_LPVDiffuseOcclusionIntensity : 1; // 0x14(0x01)
	char bOverride_LPVSpecularOcclusionIntensity : 1; // 0x14(0x01)
	char bOverride_LPVSize : 1; // 0x14(0x01)
	char bOverride_LPVSecondaryOcclusionIntensity : 1; // 0x15(0x01)
	char bOverride_LPVSecondaryBounceIntensity : 1; // 0x15(0x01)
	char bOverride_LPVGeometryVolumeBias : 1; // 0x15(0x01)
	char bOverride_LPVVplInjectionBias : 1; // 0x15(0x01)
	char bOverride_LPVEmissiveInjectionIntensity : 1; // 0x15(0x01)
	char bOverride_LPVFadeRange : 1; // 0x15(0x01)
	char bOverride_LPVDirectionalOcclusionFadeRange : 1; // 0x15(0x01)
	char bOverride_IndirectLightingColor : 1; // 0x15(0x01)
	char bOverride_IndirectLightingIntensity : 1; // 0x16(0x01)
	char bOverride_ColorGradingIntensity : 1; // 0x16(0x01)
	char bOverride_ColorGradingLUT : 1; // 0x16(0x01)
	char bOverride_DepthOfFieldFocalDistance : 1; // 0x16(0x01)
	char bOverride_DepthOfFieldFstop : 1; // 0x16(0x01)
	char bOverride_DepthOfFieldMinFstop : 1; // 0x16(0x01)
	char bOverride_DepthOfFieldBladeCount : 1; // 0x16(0x01)
	char bOverride_DepthOfFieldSensorWidth : 1; // 0x16(0x01)
	char bOverride_DepthOfFieldSqueezeFactor : 1; // 0x17(0x01)
	char bOverride_DepthOfFieldDepthBlurRadius : 1; // 0x17(0x01)
	char bOverride_DepthOfFieldDepthBlurAmount : 1; // 0x17(0x01)
	char bOverride_DepthOfFieldFocalRegion : 1; // 0x17(0x01)
	char bOverride_DepthOfFieldNearTransitionRegion : 1; // 0x17(0x01)
	char bOverride_DepthOfFieldFarTransitionRegion : 1; // 0x17(0x01)
	char bOverride_DepthOfFieldScale : 1; // 0x17(0x01)
	char bOverride_DepthOfFieldNearBlurSize : 1; // 0x17(0x01)
	char bOverride_DepthOfFieldFarBlurSize : 1; // 0x18(0x01)
	char bOverride_MobileHQGaussian : 1; // 0x18(0x01)
	char bOverride_DepthOfFieldOcclusion : 1; // 0x18(0x01)
	char bOverride_DepthOfFieldSkyFocusDistance : 1; // 0x18(0x01)
	char bOverride_DepthOfFieldVignetteSize : 1; // 0x18(0x01)
	char bOverride_MotionBlurAmount : 1; // 0x18(0x01)
	char bOverride_MotionBlurMax : 1; // 0x18(0x01)
	char bOverride_MotionBlurTargetFPS : 1; // 0x18(0x01)
	char bOverride_MotionBlurPerObjectSize : 1; // 0x19(0x01)
	char bOverride_ScreenPercentage : 1; // 0x19(0x01)
	char bOverride_ReflectionMethod : 1; // 0x19(0x01)
	char bOverride_LumenReflectionQuality : 1; // 0x19(0x01)
	char bOverride_ScreenSpaceReflectionIntensity : 1; // 0x19(0x01)
	char bOverride_ScreenSpaceReflectionQuality : 1; // 0x19(0x01)
	char bOverride_ScreenSpaceReflectionMaxRoughness : 1; // 0x19(0x01)
	char bOverride_ScreenSpaceReflectionRoughnessScale : 1; // 0x19(0x01)
	char pad_1A[0x2]; // 0x1a(0x02)
	char bOverride_ReflectionsType : 1; // 0x1c(0x01)
	char bOverride_RayTracingReflectionsMaxRoughness : 1; // 0x1c(0x01)
	char bOverride_RayTracingReflectionsMaxBounces : 1; // 0x1c(0x01)
	char bOverride_RayTracingReflectionsSamplesPerPixel : 1; // 0x1c(0x01)
	char bOverride_RayTracingReflectionsShadows : 1; // 0x1c(0x01)
	char bOverride_RayTracingReflectionsTranslucency : 1; // 0x1c(0x01)
	char bOverride_TranslucencyType : 1; // 0x1c(0x01)
	char bOverride_RayTracingTranslucencyMaxRoughness : 1; // 0x1c(0x01)
	char bOverride_RayTracingTranslucencyRefractionRays : 1; // 0x1d(0x01)
	char bOverride_RayTracingTranslucencySamplesPerPixel : 1; // 0x1d(0x01)
	char bOverride_RayTracingTranslucencyShadows : 1; // 0x1d(0x01)
	char bOverride_RayTracingTranslucencyRefraction : 1; // 0x1d(0x01)
	char bOverride_DynamicGlobalIlluminationMethod : 1; // 0x1d(0x01)
	char bOverride_LumenSceneLightingQuality : 1; // 0x1d(0x01)
	char bOverride_LumenSceneDetail : 1; // 0x1d(0x01)
	char bOverride_LumenSceneViewDistance : 1; // 0x1d(0x01)
	char bOverride_LumenSceneLightingUpdateSpeed : 1; // 0x1e(0x01)
	char bOverride_LumenFinalGatherQuality : 1; // 0x1e(0x01)
	char bOverride_LumenFinalGatherLightingUpdateSpeed : 1; // 0x1e(0x01)
	char bOverride_LumenMaxTraceDistance : 1; // 0x1e(0x01)
	char bOverride_LumenDiffuseColorBoost : 1; // 0x1e(0x01)
	char bOverride_LumenSkylightLeaking : 1; // 0x1e(0x01)
	char bOverride_LumenFullSkylightLeakingDistance : 1; // 0x1e(0x01)
	char pad_1E_7 : 1; // 0x1e(0x01)
	char pad_1F[0x1]; // 0x1f(0x01)
	char bOverride_LumenRayLightingMode : 1; // 0x20(0x01)
	char bOverride_LumenFrontLayerTranslucencyReflections : 1; // 0x20(0x01)
	char bOverride_LumenSurfaceCacheResolution : 1; // 0x20(0x01)
	char pad_20_3 : 5; // 0x20(0x01)
	char pad_21[0x3]; // 0x21(0x03)
	char bOverride_RayTracingGI : 1; // 0x24(0x01)
	char bOverride_RayTracingGIMaxBounces : 1; // 0x24(0x01)
	char bOverride_RayTracingGISamplesPerPixel : 1; // 0x24(0x01)
	char bOverride_PathTracingMaxBounces : 1; // 0x24(0x01)
	char bOverride_PathTracingSamplesPerPixel : 1; // 0x24(0x01)
	char bOverride_PathTracingFilterWidth : 1; // 0x24(0x01)
	char bOverride_PathTracingEnableEmissive : 1; // 0x24(0x01)
	char bOverride_PathTracingMaxPathExposure : 1; // 0x24(0x01)
	char bOverride_PathTracingEnableReferenceDOF : 1; // 0x25(0x01)
	char bOverride_PathTracingEnableReferenceAtmosphere : 1; // 0x25(0x01)
	char bOverride_PathTracingEnableDenoiser : 1; // 0x25(0x01)
	char pad_25_3 : 5; // 0x25(0x01)
	char pad_26[0x2]; // 0x26(0x02)
	char bMobileHQGaussian : 1; // 0x28(0x01)
	char pad_28_1 : 7; // 0x28(0x01)
	enum class EBloomMethod BloomMethod; // 0x29(0x01)
	enum class EAutoExposureMethod AutoExposureMethod; // 0x2a(0x01)
	enum class ETemperatureMethod TemperatureType; // 0x2b(0x01)
	float WhiteTemp; // 0x2c(0x04)
	float WhiteTint; // 0x30(0x04)
	char pad_34[0xc]; // 0x34(0x0c)
	struct FVector4 ColorSaturation; // 0x40(0x20)
	struct FVector4 ColorContrast; // 0x60(0x20)
	struct FVector4 ColorGamma; // 0x80(0x20)
	struct FVector4 ColorGain; // 0xa0(0x20)
	struct FVector4 ColorOffset; // 0xc0(0x20)
	struct FVector4 ColorSaturationShadows; // 0xe0(0x20)
	struct FVector4 ColorContrastShadows; // 0x100(0x20)
	struct FVector4 ColorGammaShadows; // 0x120(0x20)
	struct FVector4 ColorGainShadows; // 0x140(0x20)
	struct FVector4 ColorOffsetShadows; // 0x160(0x20)
	struct FVector4 ColorSaturationMidtones; // 0x180(0x20)
	struct FVector4 ColorContrastMidtones; // 0x1a0(0x20)
	struct FVector4 ColorGammaMidtones; // 0x1c0(0x20)
	struct FVector4 ColorGainMidtones; // 0x1e0(0x20)
	struct FVector4 ColorOffsetMidtones; // 0x200(0x20)
	struct FVector4 ColorSaturationHighlights; // 0x220(0x20)
	struct FVector4 ColorContrastHighlights; // 0x240(0x20)
	struct FVector4 ColorGammaHighlights; // 0x260(0x20)
	struct FVector4 ColorGainHighlights; // 0x280(0x20)
	struct FVector4 ColorOffsetHighlights; // 0x2a0(0x20)
	float ColorCorrectionHighlightsMin; // 0x2c0(0x04)
	float ColorCorrectionHighlightsMax; // 0x2c4(0x04)
	float ColorCorrectionShadowsMax; // 0x2c8(0x04)
	float BlueCorrection; // 0x2cc(0x04)
	float ExpandGamut; // 0x2d0(0x04)
	float ToneCurveAmount; // 0x2d4(0x04)
	float FilmSlope; // 0x2d8(0x04)
	float FilmToe; // 0x2dc(0x04)
	float FilmShoulder; // 0x2e0(0x04)
	float FilmBlackClip; // 0x2e4(0x04)
	float FilmWhiteClip; // 0x2e8(0x04)
	struct FLinearColor SceneColorTint; // 0x2ec(0x10)
	float SceneFringeIntensity; // 0x2fc(0x04)
	float ChromaticAberrationStartOffset; // 0x300(0x04)
	float BloomIntensity; // 0x304(0x04)
	float BloomThreshold; // 0x308(0x04)
	float BloomSizeScale; // 0x30c(0x04)
	float Bloom1Size; // 0x310(0x04)
	float Bloom2Size; // 0x314(0x04)
	float Bloom3Size; // 0x318(0x04)
	float Bloom4Size; // 0x31c(0x04)
	float Bloom5Size; // 0x320(0x04)
	float Bloom6Size; // 0x324(0x04)
	struct FLinearColor Bloom1Tint; // 0x328(0x10)
	struct FLinearColor Bloom2Tint; // 0x338(0x10)
	struct FLinearColor Bloom3Tint; // 0x348(0x10)
	struct FLinearColor Bloom4Tint; // 0x358(0x10)
	struct FLinearColor Bloom5Tint; // 0x368(0x10)
	struct FLinearColor Bloom6Tint; // 0x378(0x10)
	float BloomConvolutionScatterDispersion; // 0x388(0x04)
	float BloomConvolutionSize; // 0x38c(0x04)
	struct UTexture2D* BloomConvolutionTexture; // 0x390(0x08)
	struct FVector2D BloomConvolutionCenterUV; // 0x398(0x10)
	float BloomConvolutionPreFilterMin; // 0x3a8(0x04)
	float BloomConvolutionPreFilterMax; // 0x3ac(0x04)
	float BloomConvolutionPreFilterMult; // 0x3b0(0x04)
	float BloomConvolutionBufferScale; // 0x3b4(0x04)
	struct UTexture* BloomDirtMask; // 0x3b8(0x08)
	float BloomDirtMaskIntensity; // 0x3c0(0x04)
	struct FLinearColor BloomDirtMaskTint; // 0x3c4(0x10)
	enum class EDynamicGlobalIlluminationMethod DynamicGlobalIlluminationMethod; // 0x3d4(0x01)
	char pad_3D5[0x3]; // 0x3d5(0x03)
	struct FLinearColor IndirectLightingColor; // 0x3d8(0x10)
	float IndirectLightingIntensity; // 0x3e8(0x04)
	float LumenSceneLightingQuality; // 0x3ec(0x04)
	float LumenSceneDetail; // 0x3f0(0x04)
	float LumenSceneViewDistance; // 0x3f4(0x04)
	float LumenSceneLightingUpdateSpeed; // 0x3f8(0x04)
	float LumenFinalGatherQuality; // 0x3fc(0x04)
	float LumenFinalGatherLightingUpdateSpeed; // 0x400(0x04)
	float LumenMaxTraceDistance; // 0x404(0x04)
	float LumenDiffuseColorBoost; // 0x408(0x04)
	float LumenSkylightLeaking; // 0x40c(0x04)
	float LumenFullSkylightLeakingDistance; // 0x410(0x04)
	float LumenSurfaceCacheResolution; // 0x414(0x04)
	enum class ERayTracingGlobalIlluminationType RayTracingGIType; // 0x418(0x01)
	char pad_419[0x3]; // 0x419(0x03)
	int32_t RayTracingGIMaxBounces; // 0x41c(0x04)
	int32_t RayTracingGISamplesPerPixel; // 0x420(0x04)
	enum class EReflectionMethod ReflectionMethod; // 0x424(0x01)
	enum class EReflectionsType ReflectionsType; // 0x425(0x01)
	char pad_426[0x2]; // 0x426(0x02)
	float LumenReflectionQuality; // 0x428(0x04)
	enum class ELumenRayLightingModeOverride LumenRayLightingMode; // 0x42c(0x01)
	char LumenFrontLayerTranslucencyReflections : 1; // 0x42d(0x01)
	char pad_42D_1 : 7; // 0x42d(0x01)
	char pad_42E[0x2]; // 0x42e(0x02)
	float ScreenSpaceReflectionIntensity; // 0x430(0x04)
	float ScreenSpaceReflectionQuality; // 0x434(0x04)
	float ScreenSpaceReflectionMaxRoughness; // 0x438(0x04)
	float RayTracingReflectionsMaxRoughness; // 0x43c(0x04)
	int32_t RayTracingReflectionsMaxBounces; // 0x440(0x04)
	int32_t RayTracingReflectionsSamplesPerPixel; // 0x444(0x04)
	enum class EReflectedAndRefractedRayTracedShadows RayTracingReflectionsShadows; // 0x448(0x01)
	char RayTracingReflectionsTranslucency : 1; // 0x449(0x01)
	char pad_449_1 : 7; // 0x449(0x01)
	char pad_44A[0x2]; // 0x44a(0x02)
	struct FLinearColor AmbientCubemapTint; // 0x44c(0x10)
	float AmbientCubemapIntensity; // 0x45c(0x04)
	struct UTextureCube* AmbientCubemap; // 0x460(0x08)
	float CameraShutterSpeed; // 0x468(0x04)
	float CameraISO; // 0x46c(0x04)
	float DepthOfFieldFstop; // 0x470(0x04)
	float DepthOfFieldMinFstop; // 0x474(0x04)
	int32_t DepthOfFieldBladeCount; // 0x478(0x04)
	float AutoExposureBias; // 0x47c(0x04)
	float AutoExposureBiasBackup; // 0x480(0x04)
	char bOverride_AutoExposureBiasBackup : 1; // 0x484(0x01)
	char pad_484_1 : 7; // 0x484(0x01)
	char pad_485[0x3]; // 0x485(0x03)
	char AutoExposureApplyPhysicalCameraExposure : 1; // 0x488(0x01)
	char pad_488_1 : 7; // 0x488(0x01)
	char pad_489[0x7]; // 0x489(0x07)
	struct UCurveFloat* AutoExposureBiasCurve; // 0x490(0x08)
	struct UTexture* AutoExposureMeterMask; // 0x498(0x08)
	float AutoExposureLowPercent; // 0x4a0(0x04)
	float AutoExposureHighPercent; // 0x4a4(0x04)
	float AutoExposureMinBrightness; // 0x4a8(0x04)
	float AutoExposureMaxBrightness; // 0x4ac(0x04)
	float AutoExposureSpeedUp; // 0x4b0(0x04)
	float AutoExposureSpeedDown; // 0x4b4(0x04)
	float HistogramLogMin; // 0x4b8(0x04)
	float HistogramLogMax; // 0x4bc(0x04)
	float AutoExposureCalibrationConstant; // 0x4c0(0x04)
	float LocalExposureContrastScale; // 0x4c4(0x04)
	float LocalExposureHighlightContrastScale; // 0x4c8(0x04)
	float LocalExposureShadowContrastScale; // 0x4cc(0x04)
	float LocalExposureDetailStrength; // 0x4d0(0x04)
	float LocalExposureBlurredLuminanceBlend; // 0x4d4(0x04)
	float LocalExposureBlurredLuminanceKernelSizePercent; // 0x4d8(0x04)
	float LocalExposureMiddleGreyBias; // 0x4dc(0x04)
	float LensFlareIntensity; // 0x4e0(0x04)
	struct FLinearColor LensFlareTint; // 0x4e4(0x10)
	float LensFlareBokehSize; // 0x4f4(0x04)
	float LensFlareThreshold; // 0x4f8(0x04)
	char pad_4FC[0x4]; // 0x4fc(0x04)
	struct UTexture* LensFlareBokehShape; // 0x500(0x08)
	struct FLinearColor LensFlareTints[0x8]; // 0x508(0x80)
	float VignetteIntensity; // 0x588(0x04)
	float GrainJitter; // 0x58c(0x04)
	float GrainIntensity; // 0x590(0x04)
	float FilmGrainIntensity; // 0x594(0x04)
	float FilmGrainIntensityShadows; // 0x598(0x04)
	float FilmGrainIntensityMidtones; // 0x59c(0x04)
	float FilmGrainIntensityHighlights; // 0x5a0(0x04)
	float FilmGrainShadowsMax; // 0x5a4(0x04)
	float FilmGrainHighlightsMin; // 0x5a8(0x04)
	float FilmGrainHighlightsMax; // 0x5ac(0x04)
	float FilmGrainTexelSize; // 0x5b0(0x04)
	char pad_5B4[0x4]; // 0x5b4(0x04)
	struct UTexture2D* FilmGrainTexture; // 0x5b8(0x08)
	float AmbientOcclusionIntensity; // 0x5c0(0x04)
	float AmbientOcclusionStaticFraction; // 0x5c4(0x04)
	float AmbientOcclusionRadius; // 0x5c8(0x04)
	char AmbientOcclusionRadiusInWS : 1; // 0x5cc(0x01)
	char pad_5CC_1 : 7; // 0x5cc(0x01)
	char pad_5CD[0x3]; // 0x5cd(0x03)
	float AmbientOcclusionFadeDistance; // 0x5d0(0x04)
	float AmbientOcclusionFadeRadius; // 0x5d4(0x04)
	float AmbientOcclusionDistance; // 0x5d8(0x04)
	float AmbientOcclusionPower; // 0x5dc(0x04)
	float AmbientOcclusionBias; // 0x5e0(0x04)
	float AmbientOcclusionQuality; // 0x5e4(0x04)
	float AmbientOcclusionMipBlend; // 0x5e8(0x04)
	float AmbientOcclusionMipScale; // 0x5ec(0x04)
	float AmbientOcclusionMipThreshold; // 0x5f0(0x04)
	float AmbientOcclusionTemporalBlendWeight; // 0x5f4(0x04)
	char RayTracingAO : 1; // 0x5f8(0x01)
	char pad_5F8_1 : 7; // 0x5f8(0x01)
	char pad_5F9[0x3]; // 0x5f9(0x03)
	int32_t RayTracingAOSamplesPerPixel; // 0x5fc(0x04)
	float RayTracingAOIntensity; // 0x600(0x04)
	float RayTracingAORadius; // 0x604(0x04)
	float ColorGradingIntensity; // 0x608(0x04)
	char pad_60C[0x4]; // 0x60c(0x04)
	struct UTexture* ColorGradingLUT; // 0x610(0x08)
	float DepthOfFieldSensorWidth; // 0x618(0x04)
	float DepthOfFieldSqueezeFactor; // 0x61c(0x04)
	float DepthOfFieldFocalDistance; // 0x620(0x04)
	float DepthOfFieldDepthBlurAmount; // 0x624(0x04)
	float DepthOfFieldDepthBlurRadius; // 0x628(0x04)
	float DepthOfFieldFocalRegion; // 0x62c(0x04)
	float DepthOfFieldNearTransitionRegion; // 0x630(0x04)
	float DepthOfFieldFarTransitionRegion; // 0x634(0x04)
	float DepthOfFieldScale; // 0x638(0x04)
	float DepthOfFieldNearBlurSize; // 0x63c(0x04)
	float DepthOfFieldFarBlurSize; // 0x640(0x04)
	float DepthOfFieldOcclusion; // 0x644(0x04)
	float DepthOfFieldSkyFocusDistance; // 0x648(0x04)
	float DepthOfFieldVignetteSize; // 0x64c(0x04)
	float MotionBlurAmount; // 0x650(0x04)
	float MotionBlurMax; // 0x654(0x04)
	int32_t MotionBlurTargetFPS; // 0x658(0x04)
	float MotionBlurPerObjectSize; // 0x65c(0x04)
	float LPVIntensity; // 0x660(0x04)
	float LPVVplInjectionBias; // 0x664(0x04)
	float LPVSize; // 0x668(0x04)
	float LPVSecondaryOcclusionIntensity; // 0x66c(0x04)
	float LPVSecondaryBounceIntensity; // 0x670(0x04)
	float LPVGeometryVolumeBias; // 0x674(0x04)
	float LPVEmissiveInjectionIntensity; // 0x678(0x04)
	float LPVDirectionalOcclusionIntensity; // 0x67c(0x04)
	float LPVDirectionalOcclusionRadius; // 0x680(0x04)
	float LPVDiffuseOcclusionExponent; // 0x684(0x04)
	float LPVSpecularOcclusionExponent; // 0x688(0x04)
	float LPVDiffuseOcclusionIntensity; // 0x68c(0x04)
	float LPVSpecularOcclusionIntensity; // 0x690(0x04)
	enum class ETranslucencyType TranslucencyType; // 0x694(0x01)
	char pad_695[0x3]; // 0x695(0x03)
	float RayTracingTranslucencyMaxRoughness; // 0x698(0x04)
	int32_t RayTracingTranslucencyRefractionRays; // 0x69c(0x04)
	int32_t RayTracingTranslucencySamplesPerPixel; // 0x6a0(0x04)
	enum class EReflectedAndRefractedRayTracedShadows RayTracingTranslucencyShadows; // 0x6a4(0x01)
	char RayTracingTranslucencyRefraction : 1; // 0x6a5(0x01)
	char pad_6A5_1 : 7; // 0x6a5(0x01)
	char pad_6A6[0x2]; // 0x6a6(0x02)
	int32_t PathTracingMaxBounces; // 0x6a8(0x04)
	int32_t PathTracingSamplesPerPixel; // 0x6ac(0x04)
	float PathTracingFilterWidth; // 0x6b0(0x04)
	char PathTracingEnableEmissive : 1; // 0x6b4(0x01)
	char pad_6B4_1 : 7; // 0x6b4(0x01)
	char pad_6B5[0x3]; // 0x6b5(0x03)
	float PathTracingMaxPathExposure; // 0x6b8(0x04)
	char PathTracingEnableReferenceDOF : 1; // 0x6bc(0x01)
	char PathTracingEnableReferenceAtmosphere : 1; // 0x6bc(0x01)
	char PathTracingEnableDenoiser : 1; // 0x6bc(0x01)
	char pad_6BC_3 : 5; // 0x6bc(0x01)
	char pad_6BD[0x3]; // 0x6bd(0x03)
	float LPVFadeRange; // 0x6c0(0x04)
	float LPVDirectionalOcclusionFadeRange; // 0x6c4(0x04)
	float ScreenPercentage; // 0x6c8(0x04)
	char pad_6CC[0x4]; // 0x6cc(0x04)
	struct FWeightedBlendables WeightedBlendables; // 0x6d0(0x10)
};

enum class EFortWeaponCoreAnimation : uint8_t
{
	Melee = 0,
	Pistol = 1,
	Shotgun = 2,
	PaperBlueprint = 3,
	Rifle = 4,
	MeleeOneHand = 5,
	MachinePistol = 6,
	RocketLauncher = 7,
	GrenadeLauncher = 8,
	GoingCommando = 9,
	AssaultRifle = 10,
	TacticalShotgun = 11,
	SniperRifle = 12,
	TrapPlacement = 13,
	ShoulderLauncher = 14,
	AbilityDecoTool = 15,
	Crossbow = 16,
	C4 = 17,
	RemoteControl = 18,
	DualWield = 19,
	AR_BullPup = 20,
	AR_ForwardGrip = 21,
	MedPackPaddles = 22,
	SMG_P90 = 23,
	AR_DrumGun = 24,
	Consumable_Small = 25,
	Consumable_Large = 26,
	Balloon = 27,
	MountedTurret = 28,
	CreativeTool = 29,
	ExplosiveBow = 30,
	AshtonIndigo = 31,
	AshtonChicago = 32,
	MeleeDualWield = 33,
	Unarmed = 34,
	MAX = 35,
};

struct AFortWeapon_GetChargePercent_Params
{
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};


// Function FortniteGame.FortWeapon.GetProjectileSpeed
struct AFortWeapon_GetProjectileSpeed_Params
{
	float                                              ChargePercent;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};


struct AActor_GetVelocity_Params
{
	struct FVector                                     ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};


enum class EDrawDebugTrace : uint8_t
{
	None = 0,
	ForOneFrame = 1,
	ForDuration = 2,
	Persistent = 3,
	EDrawDebugTrace_MAX = 4
};

enum class ETraceTypeQuery : uint8_t
{
	TraceTypeQuery1 = 0,
	TraceTypeQuery2 = 1,
	TraceTypeQuery3 = 2,
	TraceTypeQuery4 = 3,
	TraceTypeQuery5 = 4,
	TraceTypeQuery6 = 5,
	TraceTypeQuery7 = 6,
	TraceTypeQuery8 = 7,
	TraceTypeQuery9 = 8,
	TraceTypeQuery10 = 9,
	TraceTypeQuery11 = 10,
	TraceTypeQuery12 = 11,
	TraceTypeQuery13 = 12,
	TraceTypeQuery14 = 13,
	TraceTypeQuery15 = 14,
	TraceTypeQuery16 = 15,
	TraceTypeQuery17 = 16,
	TraceTypeQuery18 = 17,
	TraceTypeQuery19 = 18,
	TraceTypeQuery20 = 19,
	TraceTypeQuery21 = 20,
	TraceTypeQuery22 = 21,
	TraceTypeQuery23 = 22,
	TraceTypeQuery24 = 23,
	TraceTypeQuery25 = 24,
	TraceTypeQuery26 = 25,
	TraceTypeQuery27 = 26,
	TraceTypeQuery28 = 27,
	TraceTypeQuery29 = 28,
	TraceTypeQuery30 = 29,
	TraceTypeQuery31 = 30,
	TraceTypeQuery32 = 31,
	TraceTypeQuery_MAX = 32,
	ETraceTypeQuery_MAX = 33
};

struct FHitResult
{
	unsigned char                                      UnknownData69[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	int                                                FaceIndex;                                                // 0x0000(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              Time;                                                     // 0x0004(0x0004) (ZeroConstructor, IsPlainOldData)
	float                                              Distance;                                                 // 0x0008(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x4];                                       // 0x000C(0x0004) MISSED OFFSET
	struct FVector                         Location;                                                 // 0x0010(0x0018)
	struct FVector                         ImpactPoint;                                              // 0x0028(0x0018)
	struct FVector                   Normal;                                                   // 0x0040(0x0018)
	struct FVector                   ImpactNormal;                                             // 0x0058(0x0018)
	struct FVector                         TraceStart;                                               // 0x0070(0x0018)
	struct FVector                         TraceEnd;                                                 // 0x0088(0x0018)
	float                                              PenetrationDepth;                                         // 0x00A0(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                MyItem;                                                   // 0x00A4(0x0004) (ZeroConstructor, IsPlainOldData)
	int                                                Item;                                                     // 0x00A8(0x0004) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      ElementIndex;                                             // 0x00AC(0x0001) (ZeroConstructor, IsPlainOldData)
	unsigned char                                      bBlockingHit : 1;                                         // 0x00AD(0x0001)
	unsigned char                                      bStartPenetrating : 1;                                    // 0x00AD(0x0001)
	unsigned char                                      UnknownData01[0x2];                                       // 0x00AE(0x0002) MISSED OFFSET
	void* PhysMaterial;                                             // 0x00B0(0x0008) (ZeroConstructor, IsPlainOldData)
	void* HitObjectHandle;                                          // 0x00B8(0x0018)
	void* Component;                                                // 0x00D0(0x0008) (ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData)
	unsigned char                                      UnknownData02[0x8];                                       // 0x00AE(0x0002) MISSED OFFSET
	struct FName                                       BoneName;                                                 // 0x00D8(0x0008) (ZeroConstructor, IsPlainOldData)
	struct FName                                       MyBoneName;                                               // 0x00DC(0x0008) (ZeroConstructor, IsPlainOldData)
};

struct UKismetSystemLibrary_LineTraceSingle_Params
{
	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor)
	struct FVector                                     Start;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	struct FVector                                     End;                                                      // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<ETraceTypeQuery>                       TraceChannel;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bTraceComplex;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	TArray<void*>									   ActorsToIgnore;                                           // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm)
	TEnumAsByte<EDrawDebugTrace>                       DrawDebugType;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FHitResult                                  OutHit;                                                   // (Parm, OutParm, IsPlainOldData)
	bool                                               bIgnoreSelf;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                TraceColor;                                               // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                TraceHitColor;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	float                                              DrawTime;                                                 // (Parm, ZeroConstructor, IsPlainOldData)
	unsigned char                                      SwyzzFix[0x8];                                       // 0x00AE(0x0002) MISSED OFFSET
	bool                                               ReverseReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};


struct AFortPlayerController_GetLocationUnderReticle_Params
{
	FVector ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};


struct UMovementComponent_StopMovementImmediately_Params
{

};

struct UProjectileMovementComponent_MoveInterpolationTarget_Params
{
	FVector NewLocation;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
	FRotator NewRotation;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};


struct UFortKismetLibrary_GetFortPawnsInRange_Params
{
	void* WorldContextObject;                                       // (Parm, ZeroConstructor)
	struct FVector                                     SourcePosition;                                           // (ConstParm, Parm, OutParm, ZeroConstructor, ReferenceParm, IsPlainOldData)
	float                                              Range;                                                    // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bDo2DCheck;                                               // (ConstParm, Parm, ZeroConstructor, IsPlainOldData)
	TArray< void*>                           OutFortPawns;                                             // (Parm, OutParm, ZeroConstructor)
};

struct UFortKismetLibrary_CheckPlayerLineOfSightToPawn_Params
{
	void* SourcePawn;                                               // (ConstParm, Parm, ZeroConstructor)
	void* TargetPawn;                                               // (ConstParm, Parm, ZeroConstructor)
	bool                                               ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};


struct UFortKismetLibrary_GetFirstLocalFortPlayerController_Params
{
	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor)
	bool                                               bIncludeNonSpectators;                                    // (Parm, ZeroConstructor, IsPlainOldData)
	bool                                               bIncludeSpectators;                                       // (Parm, ZeroConstructor, IsPlainOldData)
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct UStaticMesh_GetMaterial_Params
{
	int                                                MaterialIndex;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};
struct UKismetMaterialLibrary_GetVectorParameterValue_Params
{
	void* WorldContextObject;                                       // (Parm, ZeroConstructor)
	void* Collection;                                               // (Parm, ZeroConstructor)
	struct FName                                       ParameterName;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData)
};

struct APlayerController_StartFire_Params
{
	unsigned char                                      FireModeNum;                                              // (Parm, ZeroConstructor, IsPlainOldData)
};

struct UMaterialInstanceDynamic_SetVectorParameterValue_Params
{
	struct FName                                       ParameterName;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	struct FLinearColor                                Value;                                                    // (Parm, ZeroConstructor, IsPlainOldData)
};

enum class EMaterialParameterAssociation : uint8_t
{
	LayerParameter = 0,
	BlendParameter = 1,
	GlobalParameter = 2,
	EMaterialParameterAssociation_MAX = 3
};

struct FMaterialParameterInfo
{
	struct FName                                       Name;                                                     // 0x0000(0x0008) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	TEnumAsByte<EMaterialParameterAssociation>         Association;                                              // 0x0004(0x0001) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	unsigned char                                      UnknownData00[0x3];                                       // 0x0005(0x0003) MISSED OFFSET
	int                                                Index;                                                    // 0x0008(0x0004) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
};

struct FVectorParameterValue
{
	struct FMaterialParameterInfo                      ParameterInfo;                                            // 0x0000(0x000C) (Edit, BlueprintVisible)
	struct FLinearColor                                ParameterValue;                                           // 0x000C(0x0010) (Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData)
	struct FGuid                                       ExpressionGUID;                                           // 0x001C(0x0010) (ZeroConstructor, IsPlainOldData)
};

struct FPawnHighlight {
	float Priority_28_E2E1B5344846E187B9C11B863A7F0698; // 0x00(0x04)
	struct FLinearColor Inner_21_4CC2801147EA190DE16F59B34F36853E; // 0x04(0x10)
	struct FLinearColor Outer_22_5A1D7D0543D303E8B54B66A7F7BD2E2E; // 0x14(0x10)
	float FresnelBrightness_23_52B0F96447FF640F47DF2895B0602E92; // 0x24(0x04)
	float FresnelExponent_24_B427CF0C441AA37ED49833BF7579DE6D; // 0x28(0x04)
	float UsesPulse_25_E29229F64E540F0617E4C4987AD77605; // 0x2c(0x04)
};

struct APlayerPawn_Athena_C_ApplyPawnHighlight_Params
{
	void* Source;                                                   // (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor)
	struct FPawnHighlight                              HitGlow;                                                  // (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData)
};

struct UMeshComponent_GetMaterials_Params
{
public:
	TArray<void*>            ReturnValue;                                       // 0x0(0x10)(Parm, OutParm, ZeroConstructor, ReturnParm, NativeAccessSpecifierPublic)
};

struct UPrimitiveComponent_SetMaterial_Params
{
	int                                                ElementIndex;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	void* Material;                                                 // (Parm, ZeroConstructor)
};


struct UPrimitiveComponent_GetNumMaterials_Params
{
	int                                                num;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};
struct UMaterialInterface_GetBaseMaterial_Params
{
	void* ReturnValue;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

enum class EMIDCreationFlags : uint8_t
{
	None = 0,
	Transient = 1,
	EMIDCreationFlags_MAX = 2
};

struct UKismetMaterialLibrary_CreateDynamicMaterialInstance_Params
{
	void* WorldContextObject;                                       // (Parm, ZeroConstructor)
	void* Parent;                                                   // (Parm, ZeroConstructor)
	struct FName                                       OptionalName;                                             // (Parm, ZeroConstructor, IsPlainOldData)
	EMIDCreationFlags                                  CreationFlags;                                            // (Parm, ZeroConstructor, IsPlainOldData)
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct UMaterialInstanceDynamic_K2_CopyMaterialInstanceParameters_Params
{
	void* Source;                                                   // (Parm, ZeroConstructor)
	bool                                               bQuickParametersOnly;                                     // (Parm, ZeroConstructor, IsPlainOldData)
};

struct AFortWeapon_GetCoreAnimation_Params
{
	TEnumAsByte<EFortWeaponCoreAnimation>  ReturnValue;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

struct AFortPawn_GetCurrentWeapon_Params
{
	void* ReturnValue;                                             // (Parm, ZeroConstructor, IsPlainOldData)
};

struct UGameplayStatics_GetPlayerCameraManager_Params
{
	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor)
	int                                                PlayerIndex;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct UGameplayStatics_GetPlayerController_Params
{
	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor)
	int                                                PlayerIndex;                                              // (Parm, ZeroConstructor, IsPlainOldData)
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct UGameplayStatics_GetGameInstance_Params
{
	void* WorldContextObject;                                       // (ConstParm, Parm, ZeroConstructor)
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct AFortPlayerPawn_GetVehicleActor_Params
{
	void* ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

struct AFortProjectileBase_GetGravityScale_Params
{
	float ReturnValue;                                              // (Parm, OutParm, ZeroConstructor, ReturnParm)
};

enum class ERendererStencilMask : uint8_t
{
	zero = 0,
	one = 1,
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ERSM_MAX = 10
};

struct FScalableFloat {
	float Value; // 0x00(0x04)
	char pad_18[0x24];
};
