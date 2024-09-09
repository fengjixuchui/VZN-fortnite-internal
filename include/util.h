#pragma once

#ifndef UTIL_INLINE
#define UTIL_INLINE __forceinline
#endif

#define PAGE_SIZE 0x1000
#define MAX_PATTERN_SIZE 128

typedef void (*MemCpy_t)(void*, void*, size_t);
//typedef void (*MemMove_t)(void*, const void*, size_t);
//typedef void (*MemSet_t)(void*, int, size_t);
//typedef wchar_t* (*WcsStr_t)(const wchar_t*, const wchar_t*);
//typedef int (*WcsnCmp_t)(const wchar_t*, const wchar_t*, size_t);

//typedef void (*ProcessEvent_t)(void* object, void* function, void* params);
typedef void (*PostRender_t)(void*, void*);
//ProcessEvent_t ProcessEvent = nullptr;
MemCpy_t MemCpy = nullptr;
//MemMove_t MemMove = nullptr;
//MemSet_t MemSet = nullptr;
DWORD loopCount = NULL;
//WcsStr_t WcsStr = nullptr;
//WcsnCmp_t WcsnCmp = nullptr;

namespace Util {
	UTIL_INLINE uintptr_t imageBase()
	{
		return *(uintptr_t*)(__readgsqword(0x60) + 0x10);
	}

	template < typename T >
	UTIL_INLINE T ReadMemory(void* address) {
		T temp;
		MemCpy(&temp, address, sizeof(T));
		return temp;
	}

	template < typename T >
	UTIL_INLINE void WriteMemory(void* address, T value) {
		MemCpy(address, &value, sizeof(T));
	}

	template < typename T >
	UTIL_INLINE void ReadMemoryEx(T* data, void* address, SIZE_T count) {
		MemCpy(data, address, sizeof(T) * count);
	}

	/*UTIL_INLINE UINT32 GetImageSize(BYTE* image) {
		IMAGE_DOS_HEADER dosHeader = ReadMemory< IMAGE_DOS_HEADER >(image);
		IMAGE_NT_HEADERS ntHeaders = ReadMemory< IMAGE_NT_HEADERS >(image + dosHeader.e_lfanew);

		return ntHeaders.OptionalHeader.SizeOfImage;
	}*/

	/*UTIL_INLINE BYTE* Relative32(BYTE* inst, UINT32 offset) {
		INT32 relativeOffset = ReadMemory< INT32 >(inst + offset);

		return (inst + relativeOffset + offset + sizeof(INT32));
	}*/

	UTIL_INLINE BYTE* RelativeVA(BYTE* inst, UINT32 offset) {
		//(addr + Util::ReadMemory<int>(addr + (size - 4)) + size)
		INT relativeOffset = ReadMemory< INT >(inst + (offset - 4));

		return (inst + relativeOffset + offset);
	}

	//UTIL_INLINE bool ComparePattern(BYTE* base, BYTE* pattern, SIZE_T mask) {
	//	for (; mask; ++base, ++pattern, mask--) {
	//		if (*pattern != 0xCC && *base != *pattern) {
	//			return false;
	//		}
	//	}

	//	return true;
	//}

	//UTIL_INLINE BYTE* FindPattern(BYTE* base, SIZE_T size, BYTE* pattern, SIZE_T mask) {
	//	size -= mask;

	//	for (SIZE_T i = 0; i <= size; ++i) {
	//		BYTE* addr = &base[i];

	//		if (ComparePattern(addr, pattern, mask)) {
	//			return addr;
	//		}
	//	}

	//	return nullptr;
	//}

	//UTIL_INLINE BYTE* FindPatternSafe(BYTE* address, SIZE_T size, BYTE* pattern, SIZE_T mask) {
	//	BYTE buffer[PAGE_SIZE + MAX_PATTERN_SIZE];
	//	MemSet(buffer, 0xCC, mask);

	//	for (SIZE_T i = 0; i < (size / PAGE_SIZE); i++) {
	//		BYTE* va = address + (i * PAGE_SIZE);

	//		// Remote buffer uses MemCpy gadget
	//		MemCpy(&buffer[mask], va, PAGE_SIZE);

	//		BYTE* result = FindPattern(buffer, PAGE_SIZE + mask, pattern, mask);

	//		if (result) {
	//			return va + (result - &buffer[mask]);
	//		}

	//		// Local buffer uses regular memcpy
	//		MemCpy(buffer, &buffer[PAGE_SIZE], mask);
	//	}

	//	return nullptr;
	//}

	//BYTE* FindPatternImage(BYTE* image, BYTE* pattern, size_t mask) {
	//	IMAGE_DOS_HEADER dosHeader = ReadMemory< IMAGE_DOS_HEADER >(image);
	//	IMAGE_NT_HEADERS ntHeaders = ReadMemory< IMAGE_NT_HEADERS >(image + dosHeader.e_lfanew);

	//	BYTE* sectionBase = image + dosHeader.e_lfanew + FIELD_OFFSET(IMAGE_NT_HEADERS, OptionalHeader) +
	//		ntHeaders.FileHeader.SizeOfOptionalHeader;

	//	for (UINT32 i = 0; i < ntHeaders.FileHeader.NumberOfSections; i++) {
	//		IMAGE_SECTION_HEADER section =
	//			ReadMemory< IMAGE_SECTION_HEADER >(sectionBase + (i * sizeof(IMAGE_SECTION_HEADER)));

	//		if ((section.Characteristics & IMAGE_SCN_MEM_EXECUTE) == 0 ||
	//			(section.Characteristics & IMAGE_SCN_MEM_DISCARDABLE) != 0) {
	//			continue;
	//		}

	//		UINT32 len = max(section.SizeOfRawData, section.Misc.VirtualSize);
	//		BYTE* result = FindPatternSafe(image + section.VirtualAddress, len, pattern, mask);

	//		if (result) {
	//			return result;
	//		}
	//	}

	//	return nullptr;
	//}

	//class VmtHook {
	//private:
	//	static const SIZE_T N = 512;

	//public:
	//	UTIL_INLINE VmtHook(void* instance) : Instance((UINT64**)instance), OldTable(nullptr) {
	//		Copy();
	//	}

	//	UTIL_INLINE ~VmtHook() {
	//		Restore();
	//	}

	//	UTIL_INLINE void Copy() {
	//		// Ensure instance is still valid
	//		/*if (!CoreSDK_IsValidPtr(Instance)) {
	//			return;
	//		}*/

	//		UINT64* prevOldTable = OldTable;

	//		// Set the old table
	//		OldTable = *Instance;

	//		// Copy the table to the new table
	//		for (UINT32 i = 0; i < N; i++) {
	//			// Skip any previously hooked entries from the previous old table
	//			if (prevOldTable) {
	//				UINT64 prevOldValue = ReadMemory< UINT64 >(prevOldTable + i);

	//				if (NewTable[i] != 0 && NewTable[i] != prevOldValue) {
	//					continue;
	//				}
	//			}

	//			UINT64 origValue = ReadMemory< UINT64 >(OldTable + i);

	//			NewTable[i] = origValue;
	//		}
	//	}

	//	UTIL_INLINE void Update(void* instance) {
	//		// Ignore if the instance hasn't changed
	//		if (Instance == instance) {
	//			return;
	//		}

	//		// Restore the old instance
	//		Restore();

	//		// Update the instance
	//		Instance = (UINT64**)instance;

	//		// Copy the vtable again
	//		Copy();

	//		// Apply hooks to the new instance
	//		Apply();
	//	}

	//	UTIL_INLINE void Apply() {
	//		// Ensure instance is still valid
	//		/*if (!CoreSDK_IsValidPtr(Instance)) {
	//			return;
	//		}*/

	//		// Apply the new table if the old table is active on the instance
	//		_InterlockedCompareExchange64((INT64*)Instance, (INT64)NewTable, (INT64)OldTable);
	//	}

	//	UTIL_INLINE void Restore() {
	//		// Ensure instance is still valid
	//		/*if (!CoreSDK_IsValidPtr(Instance)) {
	//			return;
	//		}*/

	//		// Restore the old table if the new table is active on the instance
	//		_InterlockedCompareExchange64((INT64*)Instance, (INT64)OldTable, (INT64)NewTable);
	//	}

	//	template < typename T >
	//	UTIL_INLINE T Hook(void* function, UINT32 index) {
	//		if (index < 0 || index >= N) {
	//			return 0;
	//		}

	//		NewTable[index] = (UINT64)function;

	//		return (T)ReadMemory< UINT64 >(OldTable + index);
	//	}

	//	template < typename T >
	//	UTIL_INLINE T Original(UINT32 index) {
	//		if (index < 0 || index >= N) {
	//			return 0;
	//		}

	//		return (T)ReadMemory< UINT64 >(OldTable + index);
	//	}

	//private:
	//	UINT64** Instance;
	//	UINT64* OldTable;
	//	UINT64 NewTable[N];
	//};


	UTIL_INLINE int custom_strlen(const char* string)
	{
		int cnt = 0;
		if (string)
		{
			for (; *string != 0; ++string) ++cnt;
		}
		return cnt;
	}

	UTIL_INLINE PIMAGE_NT_HEADERS SqurlSize(HMODULE mxdule) {
		return (PIMAGE_NT_HEADERS)((PBYTE)mxdule + PIMAGE_DOS_HEADER(mxdule)->e_lfanew);
	}

	UTIL_INLINE PBYTE SomLove(PBYTE start, DWORD size, LPCSTR pattern, LPCSTR mask) {

		auto checkMask = [](PBYTE buffer, LPCSTR pattern, LPCSTR mask) -> BOOL
			{
				for (auto x = buffer; *mask; pattern++, mask++, x++) {
					//auto addr = *(BYTE*)(pattern);
					auto addr = Util::ReadMemory<BYTE>((PBYTE)pattern);
					if (addr != *x && *mask != '?')
						return FALSE;
				}

				return TRUE;
			};

		for (auto x = 0; x < size - custom_strlen(mask); x++) {

			auto addr = (PBYTE)start + x;
			if (checkMask(addr, pattern, mask)) {
				return addr;
			}
		}
	}

	UTIL_INLINE PBYTE SearchMoi(HMODULE mxdule, LPCSTR pattern, LPCSTR mask, DWORD occurence) {

		size_t size = SqurlSize(mxdule)->OptionalHeader.SizeOfImage;

		auto checkMask = [](PBYTE buffer, LPCSTR pattern, LPCSTR mask) -> BOOL
			{
				for (auto x = buffer; *mask; pattern++, mask++, x++) {
					//auto addr = *(BYTE*)(pattern);
					auto addr = Util::ReadMemory<BYTE>((PBYTE)pattern);
					if (addr != *x && *mask != '?')
						return FALSE;
				}

				return TRUE;
			};

		if (occurence)
			occurence -= 1;

		for (auto x = 0; x < size - custom_strlen(mask); x++) {

			auto addr = (PBYTE)mxdule + x;

			if (checkMask(addr, pattern, mask)) {

				if (!occurence || loopCount == occurence && addr) {
					loopCount = NULL; // resets the count. (Incase we need to use it again)
					return addr;
				}

				if (loopCount < occurence) {
					addr = SomLove((PBYTE)mxdule + x, (PBYTE)size - addr, pattern, mask);
					++loopCount;
					continue;
				}
			}
		}

		return NULL;
	}
}

//#define FIND_PATTERN( base, size, sig ) Util::FindPatternSafe( ( BYTE* ) base, size, ( BYTE* ) sig, sizeof( sig ) - 1 );
//#define FIND_PATTERN_IMAGE( base, sig ) Util::FindPatternImage( ( BYTE* ) base, ( BYTE* ) sig, sizeof( sig ) - 1 );