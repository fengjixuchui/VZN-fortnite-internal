#pragma once

#include "coreSdk.h"

// SafeOSD SDK default inline option
#ifndef SAFE_OSD_INLINE
#define SAFE_OSD_INLINE __forceinline
#endif

// SafeOSD SDK internal defines
#define SAFE_OSD_VERSION 1
#define SAFE_OSD_MAX_STRING_LEN 512
#define SAFE_OSD_MAX_COMMANDS 2048
#define SAFE_OSD_MAKE_COLOR( r, g, b, a )                                                                              \
	( ( ( r & 255 ) << 24 ) | ( ( g & 255 ) << 16 ) | ( ( b & 255 ) << 8 ) | ( a & 255 ) )

// SafeOSD Flags: Text Outline
#define SAFE_OSD_FLAG_OUTLINE ( 1 << 0 )
// SafeOSD Flags: Text Align Center
#define SAFE_OSD_FLAG_ALIGN_CENTER ( 1 << 1 )
// SafeOSD Flags: Text Align Right
#define SAFE_OSD_FLAG_ALIGN_RIGHT ( 1 << 2 )
// SafeOSD Flags: Text Align Middle
#define SAFE_OSD_FLAG_ALIGN_MIDDLE ( 1 << 3 )
// SafeOSD Flags: Text Align Bottom
#define SAFE_OSD_FLAG_ALIGN_BOTTOM ( 1 << 4 )

#pragma pack( push, 1 )
/// <summary>
/// The command id to use when executing
/// </summary>
enum class SafeOSD_CommandId : UINT8 {
	SetContext,
	GetDisplaySize,
	Max,
};

/// <summary>
/// The render type for a render command
/// </summary>
enum class SafeOSD_RenderType : UINT8 {
	FilledRect,
	Rect,
	CornerRect,
	FilledCircle,
	Circle,
	Line,
	String,
	Max,
};

/// <summary>
/// The color for a render command
/// </summary>
enum class SafeOSD_Color : UINT32 {
	AliceBlue = 0xF0F8FFFF,
	AntiqueWhite = 0xFAEBD7FF,
	Aqua = 0x00FFFFFF,
	Aquamarine = 0x7FFFD4FF,
	Azure = 0xF0FFFFFF,
	Beige = 0xF5F5DCFF,
	Bisque = 0xFFE4C4FF,
	Black = 0x000000FF,
	BlanchedAlmond = 0xFFEBCDFF,
	Blue = 0x0000FFFF,
	BlueViolet = 0x8A2BE2FF,
	Brown = 0xA52A2AFF,
	BurlyWood = 0xDEB887FF,
	CadetBlue = 0x5F9EA0FF,
	Chartreuse = 0x7FFF00FF,
	Chocolate = 0xD2691EFF,
	Coral = 0xFF7F50FF,
	CornflowerBlue = 0x6495EDFF,
	Cornsilk = 0xFFF8DCFF,
	Crimson = 0xDC143CFF,
	Cyan = 0x00FFFFFF,
	DarkBlue = 0x00008BFF,
	DarkCyan = 0x008B8BFF,
	DarkGoldenrod = 0xB8860BFF,
	DarkGray = 0xA9A9A9FF,
	DarkGreen = 0x006400FF,
	DarkKhaki = 0xBDB76BFF,
	DarkMagenta = 0x8B008BFF,
	DarkOliveGreen = 0x556B2FFF,
	DarkOrange = 0xFF8C00FF,
	DarkOrchid = 0x9932CCFF,
	DarkRed = 0x8B0000FF,
	DarkSalmon = 0xE9967AFF,
	DarkSeaGreen = 0x8FBC8FFF,
	DarkSlateBlue = 0x483D8BFF,
	DarkSlateGray = 0x2F4F4FFF,
	DarkTurquoise = 0x00CED1FF,
	DarkViolet = 0x9400D3FF,
	DeepPink = 0xFF1493FF,
	DeepSkyBlue = 0x00BFFFFF,
	DimGray = 0x696969FF,
	DodgerBlue = 0x1E90FFFF,
	Firebrick = 0xB22222FF,
	FloralWhite = 0xFFFAF0FF,
	ForestGreen = 0x228B22FF,
	Fuchsia = 0xFF00FFFF,
	Gainsboro = 0xDCDCDCFF,
	GhostWhite = 0xF8F8FFFF,
	Gold = 0xFFD700FF,
	Goldenrod = 0xDAA520FF,
	Gray = 0x808080FF,
	Green = 0x008000FF,
	GreenYellow = 0xADFF2FFF,
	Honeydew = 0xF0FFF0FF,
	HotPink = 0xFF69B4FF,
	IndianRed = 0xCD5C5CFF,
	Indigo = 0x4B0082FF,
	Ivory = 0xFFFFF0FF,
	Khaki = 0xF0E68CFF,
	Lavender = 0xE6E6FAFF,
	LavenderBlush = 0xFFF0F5FF,
	LawnGreen = 0x7CFC00FF,
	LemonChiffon = 0xFFFACDFF,
	LightBlue = 0xADD8E6FF,
	LightCoral = 0xF08080FF,
	LightCyan = 0xE0FFFFFF,
	LightGoldenrodYellow = 0xFAFAD2FF,
	LightGreen = 0x90EE90FF,
	LightGray = 0xD3D3D3FF,
	LightPink = 0xFFB6C1FF,
	LightSalmon = 0xFFA07AFF,
	LightSeaGreen = 0x20B2AAFF,
	LightSkyBlue = 0x87CEFAFF,
	LightSlateGray = 0x778899FF,
	LightSteelBlue = 0xB0C4DEFF,
	LightYellow = 0xFFFFE0FF,
	Lime = 0x00FF00FF,
	LimeGreen = 0x32CD32FF,
	Linen = 0xFAF0E6FF,
	Magenta = 0xFF00FFFF,
	Maroon = 0x800000FF,
	MediumAquamarine = 0x66CDAAFF,
	MediumBlue = 0x0000CDFF,
	MediumOrchid = 0xBA55D3FF,
	MediumPurple = 0x9370DBFF,
	MediumSeaGreen = 0x3CB371FF,
	MediumSlateBlue = 0x7B68EEFF,
	MediumSpringGreen = 0x00FA9AFF,
	MediumTurquoise = 0x48D1CCFF,
	MediumVioletRed = 0xC71585FF,
	MidnightBlue = 0x191970FF,
	MintCream = 0xF5FFFAFF,
	MistyRose = 0xFFE4E1FF,
	Moccasin = 0xFFE4B5FF,
	NavajoWhite = 0xFFDEADFF,
	Navy = 0x000080FF,
	OldLace = 0xFDF5E6FF,
	Olive = 0x808000FF,
	OliveDrab = 0x6B8E23FF,
	Orange = 0xFFA500FF,
	OrangeRed = 0xFF4500FF,
	Orchid = 0xDA70D6FF,
	PaleGoldenrod = 0xEEE8AAFF,
	PaleGreen = 0x98FB98FF,
	PaleTurquoise = 0xAFEEEEFF,
	PaleVioletRed = 0xDB7093FF,
	PapayaWhip = 0xFFEFD5FF,
	PeachPuff = 0xFFDAB9FF,
	Peru = 0xCD853FFF,
	Pink = 0xFFC0CBFF,
	Plum = 0xDDA0DDFF,
	PowderBlue = 0xB0E0E6FF,
	Purple = 0x800080FF,
	Red = 0xFF0000FF,
	RosyBrown = 0xBC8F8FFF,
	RoyalBlue = 0x4169E1FF,
	SaddleBrown = 0x8B4513FF,
	Salmon = 0xFA8072FF,
	SandyBrown = 0xF4A460FF,
	SeaGreen = 0x2E8B57FF,
	SeaShell = 0xFFF5EEFF,
	Sienna = 0xA0522DFF,
	Silver = 0xC0C0C0FF,
	SkyBlue = 0x87CEEBFF,
	SlateBlue = 0x6A5ACDFF,
	SlateGray = 0x708090FF,
	Snow = 0xFFFAFAFF,
	SpringGreen = 0x00FF7FFF,
	SteelBlue = 0x4682B4FF,
	Tan = 0xD2B48CFF,
	Teal = 0x008080FF,
	Thistle = 0xD8BFD8FF,
	Tomato = 0xFF6347FF,
	Turquoise = 0x40E0D0FF,
	Violet = 0xEE82EEFF,
	Wheat = 0xF5DEB3FF,
	White = 0xFFFFFFFF,
	WhiteSmoke = 0xF5F5F5FF,
	Yellow = 0xFFFF00FF,
	YellowGreen = 0x9ACD32FF,
};

/// <summary>
/// Structure for render commands
/// </summary>
typedef struct {
	SafeOSD_RenderType Type;
	UINT32 RGBA;
	float X, Y;

	union {
		struct {
			float Width, Height;
		} FilledRect;

		struct {
			float Width, Height, Thickness;
		} Rect;

		struct {
			float Width, Height, Thickness;
		} CornerRect;

		struct {
			float Width, Height, Radius;
		} FilledCircle;

		struct {
			float Width, Height, Radius, Thickness;
		} Circle;

		struct {
			float X2, Y2, Thickness;
		} Line;

		struct {
			float Size;
			UINT16 Flags;
			UINT16 Length;
			WCHAR Text[ SAFE_OSD_MAX_STRING_LEN ];
		} String;
	};
} SafeOSD_Command;

/// <summary>
/// Structure for the context
/// </summary>
typedef struct {
	UINT8 Version;
	UINT8 Pad;
	UINT16 Count;
	SafeOSD_Command Commands[ SAFE_OSD_MAX_COMMANDS ];
} SafeOSD_Context;

/// <summary>
/// Structure for the display size
/// </summary>
typedef struct {
	float Width, Height;
} SafeOSD_DisplaySize;
#pragma pack( pop )

/// <summary>
/// Allocate's a SafeOSD_Context
/// </summary>
/// <returns>Pointer to a SafeOSD_Context</returns>
SAFE_OSD_INLINE SafeOSD_Context* SafeOSD_Init() {
	SafeOSD_Context* context = ( SafeOSD_Context* ) LI_FN(VirtualAlloc).safe_cached()( 0, sizeof( SafeOSD_Context ), MEM_COMMIT, PAGE_READWRITE );

	if ( context ) {
		context->Version = SAFE_OSD_VERSION;
	}

	return context;
}

/// <summary>
/// Free's a SafeOSD_Context
/// </summary>
/// <param name="context"></param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_Free( SafeOSD_Context* context ) {
	if ( !context ) {
		return;
	}

	LI_FN(VirtualFree).safe_cached()( context, 0, MEM_RELEASE );
}

/// <summary>
/// Begin a new frame for a given context
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_BeginFrame( SafeOSD_Context* context ) {
	if ( !context ) {
		return;
	}

	LI_FN(memset).safe_cached()( &context->Commands, 0, sizeof( context->Commands ) );

	context->Count = 0;
}

/// <summary>
/// End a frame for a given context and push it to the Core SDK
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <returns></returns>
SAFE_OSD_INLINE UINT64 SafeOSD_EndFrame( SafeOSD_Context* context ) {
	if ( !context ) {
		return CORE_SDK_ERROR_FAILURE;
	}

	return CoreSDK_SafeOSD( ( UINT8 ) SafeOSD_CommandId::SetContext, context, sizeof( *context ) );
}

/// <summary>
/// Populate a display size pointer with the monitor dimensions
/// </summary>
/// <param name="displaySize">Pointer to a display size</param>
/// <returns></returns>
SAFE_OSD_INLINE UINT64 SafeOSD_GetDisplaySize( SafeOSD_DisplaySize* displaySize ) {
	if ( !displaySize ) {
		return CORE_SDK_ERROR_FAILURE;
	}

	return CoreSDK_SafeOSD( ( UINT8 ) SafeOSD_CommandId::GetDisplaySize, displaySize, sizeof( *displaySize ) );
}

/// <summary>
/// Return the next command in the context
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <returns>Pointer to a SafeOSD_Command</returns>
SAFE_OSD_INLINE SafeOSD_Command* SafeOSD_GetNextCommand( SafeOSD_Context* context ) {
	if ( !context || context->Count >= SAFE_OSD_MAX_COMMANDS ) {
		return nullptr;
	}

	return &context->Commands[ context->Count++ ];
}

/// <summary>
/// Add a filled rect to the current frame
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <param name="x">X coord in pixels</param>
/// <param name="y">Y coord in pixels</param>
/// <param name="width">Width in pixels</param>
/// <param name="height">Height inpixels</param>
/// <param name="rgba">RGBA color code</param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_AddFilledRect( SafeOSD_Context* context, float x, float y, float width, float height,
					    ULONG rgba ) {
	SafeOSD_Command* cmd = SafeOSD_GetNextCommand( context );

	if ( !cmd ) {
		return;
	}

	cmd->Type = SafeOSD_RenderType::FilledRect;
	cmd->X = x;
	cmd->Y = y;
	cmd->RGBA = rgba;
	cmd->FilledRect.Width = width;
	cmd->FilledRect.Height = height;
}

/// <summary>
/// Add a rect to the current frame
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <param name="x">X coord in pixels</param>
/// <param name="y">Y coord in pixels</param>
/// <param name="width">Width in pixels</param>
/// <param name="height">Height inpixels</param>
/// <param name="thickness">Thickness in pixels</param>
/// <param name="rgba">RGBA color code</param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_AddRect( SafeOSD_Context* context, float x, float y, float width, float height,
				      float thickness, ULONG rgba ) {
	SafeOSD_Command* cmd = SafeOSD_GetNextCommand( context );

	if ( !cmd ) {
		return;
	}

	cmd->Type = SafeOSD_RenderType::Rect;
	cmd->X = x;
	cmd->Y = y;
	cmd->RGBA = rgba;
	cmd->Rect.Width = width;
	cmd->Rect.Height = height;
	cmd->Rect.Thickness = thickness;
}

/// <summary>
/// Add a corner rect to the current frame
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <param name="x">X coord in pixels</param>
/// <param name="y">Y coord in pixels</param>
/// <param name="width">Width in pixels</param>
/// <param name="height">Height inpixels</param>
/// <param name="thickness">Thickness in pixels</param>
/// <param name="rgba">RGBA color code</param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_AddCornerRect( SafeOSD_Context* context, float x, float y, float width, float height,
					    float thickness, ULONG rgba ) {
	SafeOSD_Command* cmd = SafeOSD_GetNextCommand( context );

	if ( !cmd ) {
		return;
	}

	cmd->Type = SafeOSD_RenderType::CornerRect;
	cmd->X = x;
	cmd->Y = y;
	cmd->RGBA = rgba;
	cmd->CornerRect.Width = width;
	cmd->CornerRect.Height = height;
	cmd->CornerRect.Thickness = thickness;
}

/// <summary>
/// Add a filled circle to the current frame
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <param name="x">X coord in pixels</param>
/// <param name="y">Y coord in pixels</param>
/// <param name="radius">Radius in pixels</param>
/// <param name="rgba">RGBA color code</param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_AddFilledCircle( SafeOSD_Context* context, float x, float y, float radius, ULONG rgba ) {
	SafeOSD_Command* cmd = SafeOSD_GetNextCommand( context );

	if ( !cmd ) {
		return;
	}

	cmd->Type = SafeOSD_RenderType::FilledCircle;
	cmd->X = x;
	cmd->Y = y;
	cmd->RGBA = rgba;
	cmd->FilledCircle.Radius = radius;
}

/// <summary>
/// Add a circle to the current frame
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <param name="x">X coord in pixels</param>
/// <param name="y">Y coord in pixels</param>
/// <param name="radius">Radius in pixels</param>
/// <param name="thickness">Thickness in pixels</param>
/// <param name="rgba">RGBA color code</param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_AddCircle( SafeOSD_Context* context, float x, float y, float radius, float thickness,
					ULONG rgba ) {
	SafeOSD_Command* cmd = SafeOSD_GetNextCommand( context );

	if ( !cmd ) {
		return;
	}

	cmd->Type = SafeOSD_RenderType::Circle;
	cmd->X = x;
	cmd->Y = y;
	cmd->RGBA = rgba;
	cmd->Circle.Radius = radius;
	cmd->Circle.Thickness = thickness;
}

/// <summary>
/// Add a line to the current frame
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <param name="x1">Start X coord in pixels</param>
/// <param name="y1">Start Y coord in pixels</param>
/// <param name="x2">End X coord in pixels</param>
/// <param name="y2">End Y coord in pixels</param>
/// <param name="thickness">Thickness in pixels</param>
/// <param name="rgba">RGBA color code</param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_AddLine( SafeOSD_Context* context, float x1, float y1, float x2, float y2, float thickness,
				      ULONG rgba ) {
	SafeOSD_Command* cmd = SafeOSD_GetNextCommand( context );

	if ( !cmd ) {
		return;
	}

	cmd->Type = SafeOSD_RenderType::Line;
	cmd->X = x1;
	cmd->Y = y1;
	cmd->RGBA = rgba;
	cmd->Line.X2 = x2;
	cmd->Line.Y2 = y2;
	cmd->Line.Thickness = thickness;
}

/// <summary>
/// Add a unicode string to the current frame
/// </summary>
/// <param name="context">Pointer to a context</param>
/// <param name="x">X coord in pixels</param>
/// <param name="y">Y coord in pixels</param>
/// <param name="size">Size of the font to render in pixels</param>
/// <param name="center">Toggle to center the text</param>
/// <param name="outline">Toggle to outline the text</param>
/// <param name="rgba">RGBA color code</param>
/// <param name="text">Pointer to a null-terminated unicode string</param>
/// <returns></returns>
SAFE_OSD_INLINE void SafeOSD_AddString( SafeOSD_Context* context, float x, float y, float size, UINT16 flags, ULONG rgba, const wchar_t* text ) {
	SafeOSD_Command* cmd = SafeOSD_GetNextCommand( context );

	if ( !cmd ) {
		return;
	}

	cmd->Type = SafeOSD_RenderType::String;
	cmd->X = x;
	cmd->Y = y;
	cmd->RGBA = rgba;
	cmd->String.Size = size;
	cmd->String.Flags = flags;
	cmd->String.Length = ( UINT16 ) LI_FN(wcslen).safe_cached()( text );

	if ( cmd->String.Length >= SAFE_OSD_MAX_STRING_LEN ) {
		cmd->String.Length = SAFE_OSD_MAX_STRING_LEN - 1;
	}

	LI_FN(memcpy).safe_cached()( cmd->String.Text, text, cmd->String.Length * sizeof( WCHAR ) );
	cmd->String.Text[ cmd->String.Length ] = L'\0';
}
