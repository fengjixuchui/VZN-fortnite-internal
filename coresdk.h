#pragma once

#include <windows.h>
#include <intrin.h>

// Core SDK default inline option
#ifndef CORE_SDK_INLINE
#define CORE_SDK_INLINE __forceinline
#endif

// Core SDK internal defines
#define CORE_SDK_COMMAND_VERSION 1
#define CORE_SDK_COMMAND_MSR 0xCAFEBEEF
#define CORE_SDK_PTR_CHECK 0xD34DB33FC0D30000

// Core SDK Error: Success
#define CORE_SDK_SUCCESS 0
// Core SDK Error: Standard failure or invalid arguments
#define CORE_SDK_ERROR_FAILURE 1
// Core SDK Map DLL Error: Process could not be found or was invalid
#define CORE_SDK_MAP_DLL_ERROR_PROCESS_NOT_FOUND 2
// Core SDK Map DLL Error: Too many dlls are already loaded
#define CORE_SDK_MAP_DLL_ERROR_LIMIT_REACHED 3
// Core SDK Map DLL Error: The mapped file could not be parsed properly
#define CORE_SDK_MAP_DLL_ERROR_PARSING_ERROR 4

// Map Dll Flag: Looks for process by hash instead of pid
#define CORE_SDK_MAP_DLL_FLAG_IS_USING_HASH ( 1 << 0 )
// Map Dll Flag: Unloads any loaded dlls before executing new entry point
#define CORE_SDK_MAP_DLL_FLAG_EJECT_EXISTING ( 1 << 1 )
// Map Dll Flag: Should the memory be free'd on exit
#define CORE_SDK_MAP_DLL_FLAG_FREE_ON_EJECT ( 1 << 2 )
// Map Dll Flag: Disable the return address spoofing for imports
#define CORE_SDK_MAP_DLL_FLAG_UNSAFE_IMPORTS ( 1 << 3 )
// Map Dll Flag: Forwards exceptions generated from your dll to the process
#define CORE_SDK_MAP_DLL_FLAG_FORWARD_EXCEPTIONS ( 1 << 4 )

#pragma pack( push, 1 )
/// <summary>
/// The command id to use when executing
/// </summary>
enum class CoreSDK_CommandId : UINT8 {
	MapDll,
	SafeOSD,
	SetExceptionHandler,
	SetWndProcHandler,
	SetHandleEscalation,
	GetKeyStates,
	SetD3DRenderHandler,
	SetD3DResizeHandler,
	Max,
};

/// <summary>
/// Structure for any Core SDK commands
/// </summary>
typedef struct {
	UINT8 Version;
	CoreSDK_CommandId Id;
	PVOID Data;
	ULONG DataSize;
	UINT64 ReturnValue;
} CoreSDK_Command;

/// <summary>
/// Structure for map dll command
/// </summary>
typedef struct {
	UINT64 PidOrHash;
	UINT64 Argument;
	UINT32 Flags;
	PVOID Buffer;
	ULONG BufferSize;
} CoreSDK_MapDllCommand;

/// <summary>
/// Structure for map dll context, will be set on the reserved parameter of DllMain
/// </summary>
typedef struct {
	UINT64 ImageBase;
	UINT32 ImageSize;
	UINT32 EntryPoint;
	UINT64 Argument;
} CoreSDK_MapDllContext;

/// <summary>
/// Structure for SafeOSD command
/// </summary>
typedef struct {
	UINT8 CommandId;
	PVOID Buffer;
	ULONG BufferSize;
} CoreSDK_SafeOSDCommand;

/// <summary>
/// Structure for GetKeyStates command
/// </summary>
typedef struct {
	UINT8 Data[64];
} CoreSDK_KeyStates;
#pragma pack( pop )

/// <summary>
/// Executes a Core SDK command
/// </summary>
/// <param name="cmd">Pointer to a command structure</param>
/// <returns>Core SDK error</returns>
UINT64 CoreSDK_Exec(CoreSDK_Command* cmd);

/// <summary>
/// Map a DLL into a given process
/// </summary>
/// <param name="pidOrHash">Process Id or Process Name Hash</param>
/// <param name="argument">Argument to set in the reserved parameter</param>
/// <param name="flags">Use any of the CORE_SDK_MAP_DLL_FLAG_* flags</param>
/// <param name="data">Buffer containing the dll</param>
/// <param name="size">Size of the bufffer</param>
/// <returns>Core SDK error</returns>
CORE_SDK_INLINE UINT64 CoreSDK_MapDll(UINT64 pidOrHash, UINT64 argument, UINT32 flags, PVOID data, ULONG size) {
	CoreSDK_MapDllCommand mapDllCmd{ pidOrHash, argument, flags, data, size };
	CoreSDK_Command cmd{ CORE_SDK_COMMAND_VERSION, CoreSDK_CommandId::MapDll, &mapDllCmd, sizeof(mapDllCmd) };

	return CoreSDK_Exec(&cmd);
}

/// <summary>
/// Executes a SafeOSD command (used by the SafeOSD SDK)
/// </summary>
/// <param name="commandId">SafeOSD Command Id</param>
/// <param name="data">SafeOSD data</param>
/// <param name="size">SafeOSD data size</param>
/// <returns>Core SDK error</returns>
CORE_SDK_INLINE UINT64 CoreSDK_SafeOSD(UINT8 commandId, PVOID data, ULONG size) {
	CoreSDK_SafeOSDCommand safeOsdCmd{ commandId, data, size };
	CoreSDK_Command cmd{ CORE_SDK_COMMAND_VERSION, CoreSDK_CommandId::SafeOSD, &safeOsdCmd, sizeof(safeOsdCmd) };

	return CoreSDK_Exec(&cmd);
}

/// <summary>
/// Replaces the exception handler in the current process
/// </summary>
/// <param name="handler">Pointer to an exception handler function</param>
/// <returns>Core SDK error</returns>
CORE_SDK_INLINE UINT64 CoreSDK_SetExceptionHandler(PVOID handler) {
	CoreSDK_Command cmd{ CORE_SDK_COMMAND_VERSION, CoreSDK_CommandId::SetExceptionHandler, handler,
				 sizeof(handler) };

	return CoreSDK_Exec(&cmd);
}

/// <summary>
/// Replaces the WndProc in the current process
/// </summary>
/// <param name="handler">Pointer a WndProc handler function</param>
/// <returns>Core SDK error</returns>
CORE_SDK_INLINE UINT64 CoreSDK_SetWndProcHandler(PVOID handler) {
	CoreSDK_Command cmd{ CORE_SDK_COMMAND_VERSION, CoreSDK_CommandId::SetWndProcHandler, handler,
				 sizeof(handler) };

	return CoreSDK_Exec(&cmd);
}

/// <summary>
/// Enable handle privilege escalation on all handles
/// Note: Open a process handle using PROCESS_QUERY_LIMITED_INFORMATION
/// </summary>
/// <param name="enabled">Boolean to enable escalation</param>
/// <returns>Core SDK error</returns>
CORE_SDK_INLINE UINT64 CoreSDK_SetHandleEscalation(UINT8 enabled) {
	CoreSDK_Command cmd{ CORE_SDK_COMMAND_VERSION, CoreSDK_CommandId::SetHandleEscalation, &enabled,
				 sizeof(enabled) };

	return CoreSDK_Exec(&cmd);
}

/// <summary>
/// Get a copy of the current key states
/// </summary>
/// <param name="keyStates">Pointer to a CoreSDK_KeyStates structure</param>
/// <returns>Core SDK error</returns>
CORE_SDK_INLINE UINT64 CoreSDK_GetKeyStates(CoreSDK_KeyStates* keyStates) {
	CoreSDK_Command cmd{ CORE_SDK_COMMAND_VERSION, CoreSDK_CommandId::GetKeyStates, keyStates,
				 sizeof(*keyStates) };

	return CoreSDK_Exec(&cmd);
}

/// <summary>
/// Sets up a D3D render hook in the current process
/// </summary>
/// <param name="handler">Pointer a GDI render handler function</param>
/// <returns>Core SDK error</returns>
CORE_SDK_INLINE UINT64 CoreSDK_SetD3DRenderHandler(PVOID handler) {
	CoreSDK_Command cmd{ CORE_SDK_COMMAND_VERSION, CoreSDK_CommandId::SetD3DRenderHandler, handler,
				 sizeof(handler) };

	return CoreSDK_Exec(&cmd);
}

/// <summary>
/// Sets up a D3D resize hook in the current process
/// </summary>
/// <param name="handler">Pointer a GDI resize handler function</param>
/// <returns>Core SDK error</returns>
CORE_SDK_INLINE UINT64 CoreSDK_SetD3DResizeHandler(PVOID handler) {
	CoreSDK_Command cmd{ CORE_SDK_COMMAND_VERSION, CoreSDK_CommandId::SetD3DResizeHandler, handler,
				 sizeof(handler) };

	return CoreSDK_Exec(&cmd);
}

/// <summary>
/// Validates a given pointer without risk of faulting
/// </summary>
/// <param name="address">The address to read</param>
/// <returns>Boolean indicating if the pointer could be read</returns>
CORE_SDK_INLINE bool CoreSDK_IsValidPtr(PVOID address) {
	if (!address || (ULONG64(address) > 0x7FFFFFFEFFFF)) {
		return false;
	}

	ULONG64 buffer = CORE_SDK_PTR_CHECK;
	__movsb((PBYTE)&buffer, (PBYTE)address, 1);
	return buffer != (CORE_SDK_PTR_CHECK >> 8);
}

/// <summary>
/// Checks if CoreSDK is initialized by attempting to read a bad address
/// </summary>
/// <returns>Boolean indicating if the CoreSDK is initialized</returns>
CORE_SDK_INLINE bool CoreSDK_IsInitialized() {
	__try {
		if (!CoreSDK_IsValidPtr((void*)0x11223344ull)) {
			return true;
		}
	}
	__except (1) {
	}

	return false;
}

/// <summary>
/// Hashes a given string (used for process name hashes, etc)
/// </summary>
/// <param name="str">Pointer to an ascii string</param>
/// <returns>Hash of the string</returns>
CORE_SDK_INLINE UINT64 CoreSDK_Hash(const char* str) {
	UINT64 hash = 0xCBF29CE484222325;

	while (*str) {
		hash =
			(hash ^ UINT32((*str >= 'A' && *str <= 'Z') ? *str - ('A' - 'a') : *str)) * 0x100000001B3;
		str++;
	}

	return hash;
}

/// <summary>
/// Takes a function address and returns a new address for ret spoofing
/// </summary>
/// <param name="address">Address of function to spoof</param>
/// <returns>Address that will be spoofed when called</returns>
CORE_SDK_INLINE UINT64 CoreSDK_RetSpoof(UINT64 address) {
	return (address & ~(1ull << 43));
}

/// <summary>
/// Buffer for recent key states
/// </summary>
extern UINT8 CoreSDK_RecentKeyState[32];

/// <summary>
/// Returns the current state of a key. Matches the behavior of GetAsyncKeyState in the Win32 API
/// Reference: https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getasynckeystate
/// </summary>
/// <param name="keyStates">Pointer to a CoreSDK_KeyStates structure</param>
/// <param name="key">VK key code</param>
/// <returns>Same as GetAsyncKeyState</returns>
CORE_SDK_INLINE UINT16 CoreSDK_GetKeyState(CoreSDK_KeyStates* keyStates, UINT8 key) {
#define GET_KS_BYTE( vk ) ( ( vk ) *2 / 8 )
#define GET_KS_DOWN_BIT( vk ) ( 1 << ( ( ( vk ) % 4 ) * 2 ) )
#define IS_KEY_DOWN( ks, vk ) ( ( ( ks )[ GET_KS_BYTE( vk ) ] & GET_KS_DOWN_BIT( vk ) ) ? TRUE : FALSE )

	bool isPressed = IS_KEY_DOWN(keyStates->Data, key);
	bool wasPressed = CoreSDK_RecentKeyState[key / 8] & 1 << key % 8;

	if (isPressed) {
		CoreSDK_RecentKeyState[key / 8] |= 1 << key % 8;
	}
	else {
		CoreSDK_RecentKeyState[key / 8] &= ~(1 << key % 8);
	}

	UINT16 ret = 0;

	if (isPressed) {
		ret |= 0x8000;
	}

	if (isPressed && !wasPressed) {
		ret |= 0x1;
	}

	return ret;
}

/// <summary>
/// Reads the OSBuildNumber from the x64 PEB
/// </summary>
/// <returns>Windows Build Number</returns>
CORE_SDK_INLINE UINT16 CoreSDK_GetBuildNumber() {
	// Read the PEB
	UINT64 peb = (UINT64)__readgsqword(0x60);

	// Read PEB->OSBuildNumber
	return *(UINT16*)(peb + 0x120);
}
