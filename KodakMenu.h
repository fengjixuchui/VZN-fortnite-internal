#pragma once

// Defines
#define mpe 3.14159265358979323846264338327950288419716939937510582f
#define D2R(d) (d / 180.f) * mpe

// Variables
FVector2D Target_MenuInitialPos = { 109, 474 };
FVector2D borderStartPos;
FVector2D borderSize;
FLinearColor Target_ThemeColor = { 179, 5, 60, 1.f };
bool Target_bIsDragging = false, Lclick = false;
float Target_MenuDragStartX = 0;
float Target_MenuDragStartY = 0;
float Target_MenuW = 550;
float Target_MenuH = 480;
int Target_TabIndex = 0;
float Mx, My;
FVector2D Target_ItemsCalculation;

// Function headers
void MenuDrawTabs(void* pCanvas);
void MenuDrawItemsFor(void* pCanvas, int index);
void MenuHandleMouseClicks();

void DrawFilledRect(void* concern, FVector2D initial_pos, double width, double height, FLinearColor color)
{
	for (float i = 0.0f; i < height; i += 1.0f)
		K2_DrawLine(concern, FVector2D(initial_pos.X, initial_pos.Y + i), FVector2D(initial_pos.X + width, initial_pos.Y + i), 1.0f, color);
}

void DrawMenu(void* pCanvas) {
	// Menu background
	DrawFilledRect(pCanvas, Target_MenuInitialPos, Target_MenuW - 2, Target_MenuH - 2, FLinearColor(0, 0, 0, 1.f));
	// Menu tabs
	MenuDrawTabs(pCanvas);
	// Items in the menu
	MenuDrawItemsFor(pCanvas, Target_TabIndex);
	// Handle mouse clicks
	MenuHandleMouseClicks();

	GetMousePosition(retired, &Mx, &My);

	Lclick = WasInputKeyJustPressed(retired, geyz::LeftMouseButton);

	if (Mx && My) K2_DrawBox(pCanvas, FVector2D{ Mx - 2, My - 1 }, { 4, 4 }, 1.f, Target_ThemeColor);
}

bool IsInMenu(float x, float y)
{
	return (x >= Target_MenuInitialPos.X) && (x <= Target_MenuInitialPos.X + Target_MenuW) && (y >= Target_MenuInitialPos.Y) && (y <= Target_MenuInitialPos.Y + Target_MenuH);
}

bool IsInRectangle(float x1, float y1, float x2, float y2, float x, float y) {
	if (x > x1 and x < x2 and y > y1 and y < y2)
		return true;

	return false;
}

void MenuDrawTabs(void* pCanvas) {
	int pTabs_Size = 4;

	auto inp = Target_MenuInitialPos + FVector2D(20, 35);

	//K2_DrawText(pCanvas, geyz::funt, xMe(L"KETAMINE SLOTTED"), Target_MenuInitialPos + FVector2D(22, 11), FVector2D(1.0f, 1.0f), Target_ThemeColor, 1.0f, FLinearColor(0, 0, 0, 1.0f), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.0f));
	K2_DrawText(pCanvas, geyz::funt, xMe(L"QUECK PRIVATE"), Target_MenuInitialPos + FVector2D(22, 11), FVector2D(1.0f, 1.0f), Target_ThemeColor, 1.0f, FLinearColor(0, 0, 0, 1.0f), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.0f));

	auto tabsz = (Target_MenuW - 40) / pTabs_Size; tabsz -= 2;
	FVector2D ip = inp + FVector2D(2, 2);

	// for border around tabs
	FVector2D startPos;
	FVector2D widthHeight; widthHeight.Y = 22;

	auto i = 0;
	for (int p = 0; p < pTabs_Size; p++) {
		auto tab = p == 0 ? xMe(L"Aimbot") : p == 1 ? xMe(L"Visuals") : p == 2 ? xMe(L"Weapons") : xMe(L"Misc");

		auto clr2 = FLinearColor(0.f, 0.f, 0.f, 1.f);
		auto clr = FLinearColor(255.f, 255.f, 255.f, 1.f);
		if (Target_TabIndex == i) {
			clr = FLinearColor(0.f, 0.f, 0.f, 1.f);
			clr2 = Target_ThemeColor;
		}

		DrawFilledRect(pCanvas, ip, tabsz, 22, clr2);

		float x1 = ip.X, y1 = ip.Y, x2 = ip.X + tabsz, y2 = ip.Y + 22;

		// given point
		if (IsInRectangle(x1, y1, x2, y2, Mx, My)) {
			Target_bIsDragging = false;
			if (Lclick)
				Target_TabIndex = i;
		}

		if (!startPos.X || startPos.X == 0)
			startPos = ip;

		widthHeight.X += tabsz + 2;

		FVector2D TextSize0 = K2_TextSize(pCanvas, geyz::funt, tab, FVector2D(1.0f, 1.0f));
		float bestFitByDanielle = (ip.X + (tabsz / 2)) - (TextSize0.X / 2);
		K2_DrawText(pCanvas, geyz::funt, tab, FVector2D(bestFitByDanielle, ip.Y + 3), FVector2D(1.0f, 1.0f), clr, 1.0f, FLinearColor(0, 0, 0, 1.0f), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.0f));

		ip.X += tabsz + 2;
		i++;
	}
	widthHeight.X -= 2;

	// draw border
	K2_DrawBox(pCanvas, startPos, widthHeight, 1.f, FLinearColor(150, 150, 150, 1.f));
	borderStartPos = startPos;
	borderSize = widthHeight;

	Target_ItemsCalculation = inp + FVector2D(0, 35);
}

double customRound(double value) {
	// Handle negative numbers by converting them to positive numbers
	bool isNegative = value < 0;
	if (isNegative) {
		value = -value;
	}

	// Get the integer part of the number
	double intPart = static_cast<double>(static_cast<long long>(value));

	// Get the fractional part of the number
	double fracPart = value - intPart;

	// Check the fractional part to decide how to round
	if (fracPart < 0.5) {
		// No need to change the integer part
	}
	else if (fracPart > 0.5) {
		intPart += 1; // Round up
	}
	else {
		// If the fractional part is exactly 0.5, round to the nearest even integer
		if (static_cast<long long>(intPart) % 2 != 0) {
			intPart += 1;
		}
	}

	// Convert back to negative if the original number was negative
	if (isNegative) {
		intPart = -intPart;
	}

	return intPart;
}

void Render_Circle(void* pCanvas, FVector2D pos, float r, FLinearColor color)
{
	float circum = mpe * 2.f * r;

	int seg;
	int inum = (int)circum;
	if (circum == (float)inum) {
		seg = inum;
	}
	seg = inum + 1;

	if (seg > 180) seg = 180;

	float theta = 0.f;
	float step = 180.f / seg;

	for (size_t i = 0; i < seg; ++i)
	{
		theta = i * step;
		auto delta = FVector2D((float)customRound(r * STATIC_Sin(D2R(theta))), (float)customRound(r * STATIC_Cos(D2R(theta))));
		K2_DrawLine(pCanvas, pos + delta, pos - delta, 1.f, color);
	}
}

void Render_Clear(void* pCanvas, FVector2D one, FVector2D two, FLinearColor color) {
	for (auto x = one.X; x < two.X; x += 1.f)
	{
		K2_DrawLine(pCanvas, FVector2D(x, one.Y), FVector2D(x, two.Y), 1.f, color);
	}
}

void Render_PointArray(void* pCanvas, size_t count, FVector2D* ary, FLinearColor color) {
	for (size_t i = 1; i < count; ++i)
		K2_DrawLine(pCanvas, ary[i - 1], ary[i], 1.0f, color);
}

void Render_CircleOutline(void* pCanvas, FVector2D pos, float r, FLinearColor outline) {
	float circum = mpe * 2.f * r;

	int seg;
	int inum = (int)circum;
	if (circum == (float)inum) {
		seg = inum;
	}
	seg = inum + 1;

	if (seg > 180) seg = 180;

	float theta = 0.f;
	float step = 360.f / seg;

	FVector2D points[180] = {};

	for (size_t i = 0; i < seg; ++i)
	{
		theta = i * step;
		points[i] = FVector2D(pos.X + customRound(r * STATIC_Sin(D2R(theta))), pos.Y + customRound(r * STATIC_Cos(D2R(theta))));
	}

	Render_PointArray(pCanvas, seg, points, outline);
}

void Render_CircleOutlined(void* pCanvas, FVector2D pos, float r, FLinearColor fill, FLinearColor outline) {
	Render_Circle(pCanvas, pos, r, fill);
	Render_CircleOutline(pCanvas, pos, r, outline);
}

void Render_Toggle(void* pCanvas, FVector2D& loc_ref, const wchar_t* name, bool* on) {
	auto loc = &loc_ref;

	bool hover = Mx > loc->X && Mx < (loc->X + 64) && My > loc->Y && My < (loc->Y + 20);
	if (hover)
		Target_bIsDragging = false;

	if (Lclick && hover)
		*on = !*on;

	FLinearColor col = *on ? Target_ThemeColor : FLinearColor(170.f, 170.f, 170.f, 1.f);

	Render_Circle(pCanvas, FVector2D(loc->X + 10, loc->Y + 10), 6, col);
	Render_Circle(pCanvas, FVector2D(loc->X + 18, loc->Y + 10), 6, col);
	Render_Clear(pCanvas, FVector2D(loc->X + 10, loc->Y + 4), FVector2D(loc->X + 18, loc->Y + 16), col);

	if (*on) {
		Render_CircleOutlined(pCanvas, FVector2D(loc->X + 18, loc->Y + 10), 5, hover ? FLinearColor(0.8f * 255, 0.8f * 255, 0.8f * 255, 1.f) : FLinearColor(255, 255, 255, 1), FLinearColor(0, 0, 0, 1.f));
		K2_DrawLine(pCanvas, FVector2D(loc->X + 9, loc->Y + 8), FVector2D(loc->X + 9, loc->Y + 12), 1.f, FLinearColor(0, 0, 0, 1.f));
	}
	else {
		Render_CircleOutlined(pCanvas, FVector2D(loc->X + 10, loc->Y + 10), 5, hover ? FLinearColor(0.8f * 255, 0.8f * 255, 0.8f * 255, 1.f) : FLinearColor(255, 255, 255, 1), FLinearColor(0, 0, 0, 1.f));
		Render_CircleOutline(pCanvas, FVector2D(loc->X + 19, loc->Y + 10), 2, FLinearColor(0, 0, 0, 1.f));
	}

	K2_DrawText(pCanvas, geyz::funt, name, FVector2D(loc->X + 32, loc->Y + 2), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->Y += 25.0f;
}

void Render_Slider(void* pCanvas, const wchar_t* name, float minimum, float maximum, float* val, FVector2D* loc) {
	maximum += 0.1f;
	auto kinda_white = FLinearColor(204.f, 204.f, 204.f, 1.f);

	K2_DrawText(pCanvas, geyz::funt, name, FVector2D(loc->X + 6, loc->Y), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X += 6.f;

	bool hover = Mx > loc->X && Mx < (loc->X + 199) && My > loc->Y && My < (loc->Y + 30);
	if (hover)
		Target_bIsDragging = false;

	if (IsInputKeyDown(retired, geyz::LeftMouseButton) && hover) {
		float ratio = (float)(Mx - loc->X) / 199;
		if (ratio < 0.f) ratio = 0.f;
		if (ratio > 1.f) ratio = 1.f;
		*val = minimum + ((maximum - minimum) * ratio);
	}

	float xpos = ((*val - minimum) / (maximum - minimum)) * 199;
	loc->Y += 24.f;

	Render_Circle(pCanvas, *loc, 3, Target_ThemeColor);
	Render_Clear(pCanvas, FVector2D(loc->X, loc->Y - 3), FVector2D(loc->X + xpos, loc->Y + 3), Target_ThemeColor);

	Render_Clear(pCanvas, FVector2D(loc->X + xpos, loc->Y - 3), FVector2D(loc->X + 199, loc->Y + 3), kinda_white);
	Render_Circle(pCanvas, FVector2D(loc->X + 199, loc->Y), 3, kinda_white);

	Render_CircleOutlined(pCanvas, FVector2D(loc->X + xpos, loc->Y), 5, FLinearColor(255.f, 255.f, 255.f, 1.f), FLinearColor(0.f, 0.f, 0.f, 1.f));

	loc->Y -= 24.f;

	auto loler = STATIC_Conv_IntToString(*val);

	FVector2D TextSize1 = K2_TextSize(pCanvas, geyz::funt, loler, FVector2D(1.0f, 1.0f));

	K2_DrawText(pCanvas, geyz::funt, loler, FVector2D(loc->X + 199 - TextSize1.X, loc->Y + 33), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X -= 6.f;
	loc->Y += 35.0f;
	loc->Y += 13.0f;
}

void Render_SliderColorPicker(void* pCanvas, const wchar_t* name, float minimum, float maximum, float* val, FVector2D* loc) {
	minimum -= 0.1f;
	maximum += 0.1f;
	auto kinda_white = FLinearColor(204.f, 204.f, 204.f, 1.f);

	K2_DrawText(pCanvas, geyz::funt, name, FVector2D(loc->X + 6, loc->Y), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X += 6.f;

	bool hover = Mx > loc->X && Mx < (loc->X + 199) && My > loc->Y && My < (loc->Y + 30);
	if (hover)
		Target_bIsDragging = false;

	if (IsInputKeyDown(retired, geyz::LeftMouseButton) && hover) {
		float ratio = (float)(Mx - loc->X) / 199;
		if (ratio < 0.f) ratio = 0.f;
		if (ratio > 1.f) ratio = 1.f;
		*val = minimum + ((maximum - minimum) * ratio);

		if (*val >= 5.5f)
			*val = 6.0f;
		else if (*val >= 4.5f)
			*val = 5.0f;
		else if (*val >= 3.5f)
			*val = 4.0f;
		else if (*val >= 2.5f)
			*val = 3.0f;
		else if (*val >= 1.5f)
			*val = 2.0f;
		else if (*val < 1.5f)
			*val = 1.0f;
		else if (*val < 2.5f)
			*val = 2.0f;
		else if (*val < 3.5f)
			*val = 3.0f;
		else if (*val < 4.5f)
			*val = 4.0f;
		else if (*val < 5.5f)
			*val = 5.0f;
	}

	float xpos = ((*val - minimum) / (maximum - minimum)) * 199;
	loc->Y += 24.f;

	Render_Circle(pCanvas, *loc, 3, Target_ThemeColor);
	Render_Clear(pCanvas, FVector2D(loc->X, loc->Y - 3), FVector2D(loc->X + xpos, loc->Y + 3), Target_ThemeColor);

	Render_Clear(pCanvas, FVector2D(loc->X + xpos, loc->Y - 3), FVector2D(loc->X + 199, loc->Y + 3), kinda_white);
	Render_Circle(pCanvas, FVector2D(loc->X + 199, loc->Y), 3, kinda_white);

	Render_CircleOutlined(pCanvas, FVector2D(loc->X + xpos, loc->Y), 5, FLinearColor(255.f, 255.f, 255.f, 1.f), FLinearColor(0.f, 0.f, 0.f, 1.f));

	loc->Y -= 24.f;

	auto loler = GetColorFromOption(*val);

	FVector2D TextSize1 = K2_TextSize(pCanvas, geyz::funt, loler.name, FVector2D(1.0f, 1.0f));

	K2_DrawText(pCanvas, geyz::funt, loler.name, FVector2D(loc->X + 199 - TextSize1.X, loc->Y + 33), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X -= 6.f;
	loc->Y += 35.0f;
	loc->Y += 13.0f;
}

void Render_SliderRarity(void* pCanvas, const wchar_t* name, float minimum, float maximum, float* val, FVector2D* loc) {
	minimum -= 0.1f;
	maximum += 0.1f;
	auto kinda_white = FLinearColor(204.f, 204.f, 204.f, 1.f);

	K2_DrawText(pCanvas, geyz::funt, name, FVector2D(loc->X + 6, loc->Y), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X += 6.f;

	bool hover = Mx > loc->X && Mx < (loc->X + 199) && My > loc->Y && My < (loc->Y + 30);
	if (hover)
		Target_bIsDragging = false;

	if (IsInputKeyDown(retired, geyz::LeftMouseButton) && hover) {
		float ratio = (float)(Mx - loc->X) / 199;
		if (ratio < 0.f) ratio = 0.f;
		if (ratio > 1.f) ratio = 1.f;
		*val = minimum + ((maximum - minimum) * ratio);

		if (*val >= 8.5f)
			*val = 9.0f;
		else if (*val >= 7.5f)
			*val = 8.0f;
		else if (*val >= 6.5f)
			*val = 7.0f;
		else if (*val >= 5.5f)
			*val = 6.0f;
		else if (*val >= 4.5f)
			*val = 5.0f;
		else if (*val >= 3.5f)
			*val = 4.0f;
		else if (*val >= 2.5f)
			*val = 3.0f;
		else if (*val >= 1.5f)
			*val = 2.0f;
		else if (*val < 1.5f)
			*val = 1.0f;
		else if (*val < 2.5f)
			*val = 2.0f;
		else if (*val < 3.5f)
			*val = 3.0f;
		else if (*val < 4.5f)
			*val = 4.0f;
		else if (*val < 5.5f)
			*val = 5.0f;
		else if (*val < 6.5f)
			*val = 6.0f;
		else if (*val < 7.5f)
			*val = 7.0f;
		else if (*val < 8.5f)
			*val = 8.0f;
	}

	float xpos = ((*val - minimum) / (maximum - minimum)) * 199;
	loc->Y += 24.f;

	Render_Circle(pCanvas, *loc, 3, Target_ThemeColor);
	Render_Clear(pCanvas, FVector2D(loc->X, loc->Y - 3), FVector2D(loc->X + xpos, loc->Y + 3), Target_ThemeColor);

	Render_Clear(pCanvas, FVector2D(loc->X + xpos, loc->Y - 3), FVector2D(loc->X + 199, loc->Y + 3), kinda_white);
	Render_Circle(pCanvas, FVector2D(loc->X + 199, loc->Y), 3, kinda_white);

	Render_CircleOutlined(pCanvas, FVector2D(loc->X + xpos, loc->Y), 5, FLinearColor(255.f, 255.f, 255.f, 1.f), FLinearColor(0.f, 0.f, 0.f, 1.f));

	loc->Y -= 24.f;

	auto lolerclr = GetItemColor(EFortItemTier(*val));

	auto loler = GetItemTierName(EFortItemTier(*val));

	FVector2D TextSize1 = K2_TextSize(pCanvas, geyz::funt, loler, FVector2D(1.0f, 1.0f));

	K2_DrawText(pCanvas, geyz::funt, loler, FVector2D(loc->X + 199 - TextSize1.X, loc->Y + 33), FVector2D(1.0f, 1.0f), lolerclr, 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X -= 6.f;
	loc->Y += 35.0f;
	loc->Y += 13.0f;
}

void Render_SliderBones(void* pCanvas, const wchar_t* name, float minimum, float maximum, float* val, FVector2D* loc) {
	minimum -= 0.1f;
	maximum += 0.1f;
	auto kinda_white = FLinearColor(204.f, 204.f, 204.f, 1.f);

	K2_DrawText(pCanvas, geyz::funt, name, FVector2D(loc->X + 6, loc->Y), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X += 6.f;

	bool hover = Mx > loc->X && Mx < (loc->X + 199) && My > loc->Y && My < (loc->Y + 30);
	if (hover)
		Target_bIsDragging = false;

	if (IsInputKeyDown(retired, geyz::LeftMouseButton) && hover) {
		float ratio = (float)(Mx - loc->X) / 199;
		if (ratio < 0.f) ratio = 0.f;
		if (ratio > 1.f) ratio = 1.f;
		*val = minimum + ((maximum - minimum) * ratio);

		if (*val >= 5.5f)
			*val = 6.0f;
		else if (*val >= 4.5f)
			*val = 5.0f;
		else if (*val >= 3.5f)
			*val = 4.0f;
		else if (*val >= 2.5f)
			*val = 3.0f;
		else if (*val >= 1.5f)
			*val = 2.0f;
		else if (*val < 1.5f)
			*val = 1.0f;
		else if (*val < 2.5f)
			*val = 2.0f;
		else if (*val < 3.5f)
			*val = 3.0f;
		else if (*val < 4.5f)
			*val = 4.0f;
		else if (*val < 5.5f)
			*val = 5.0f;
	}

	float xpos = ((*val - minimum) / (maximum - minimum)) * 199;
	loc->Y += 24.f;

	Render_Circle(pCanvas, *loc, 3, Target_ThemeColor);
	Render_Clear(pCanvas, FVector2D(loc->X, loc->Y - 3), FVector2D(loc->X + xpos, loc->Y + 3), Target_ThemeColor);

	Render_Clear(pCanvas, FVector2D(loc->X + xpos, loc->Y - 3), FVector2D(loc->X + 199, loc->Y + 3), kinda_white);
	Render_Circle(pCanvas, FVector2D(loc->X + 199, loc->Y), 3, kinda_white);

	Render_CircleOutlined(pCanvas, FVector2D(loc->X + xpos, loc->Y), 5, FLinearColor(255.f, 255.f, 255.f, 1.f), FLinearColor(0.f, 0.f, 0.f, 1.f));

	loc->Y -= 24.f;

	FString skid;
	if (*val == 1) skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"HEAD"));
	if (*val == 2) skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"NECK"));
	if (*val == 3) skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"BODY"));
	if (*val == 4) skid = STATIC_Concat_StrStr(xMe(L""), xMe(L"CLOSEST"));

	FVector2D TextSize1 = K2_TextSize(pCanvas, geyz::funt, skid, FVector2D(1.0f, 1.0f));

	K2_DrawText(pCanvas, geyz::funt, skid, FVector2D(loc->X + 199 - TextSize1.X, loc->Y + 33), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X -= 6.f;
	loc->Y += 35.0f;
	loc->Y += 13.0f;
}

FVector2D RenderFKey_Busy = FVector2D();
bool LclickFix = false;

void Render_FKey(void* pCanvas, const wchar_t* name, FKey* val, FVector2D* loc) {
	K2_DrawText(pCanvas, geyz::funt, name, FVector2D(loc->X + 6, loc->Y), FVector2D(1.0f, 1.0f), FLinearColor(255.f, 255.f, 255.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));

	loc->X += 6.f;

	loc->Y += 24.f;

	bool hover = Mx > loc->X && Mx < (loc->X + 200) && My > loc->Y && My < (loc->Y + 31);
	if (hover)
		Target_bIsDragging = false;

	if (!LclickFix && RenderFKey_Busy == FVector2D() && Lclick && hover) {
		LclickFix = true;
		RenderFKey_Busy = *loc;
	}

	if (RenderFKey_Busy == *loc) {
		if (WasInputKeyJustPressed(retired, geyz::MouseScrollUp)) { *val = geyz::MouseScrollUp; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::MouseScrollDown)) { *val = geyz::MouseScrollDown; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::MouseWheelAxis)) { *val = geyz::MouseWheelAxis; RenderFKey_Busy = FVector2D(); }
		if (!LclickFix && WasInputKeyJustPressed(retired, geyz::LeftMouseButton)) { *val = geyz::LeftMouseButton; RenderFKey_Busy = FVector2D(); LclickFix = true; }
		if (WasInputKeyJustPressed(retired, geyz::RightMouseButton)) { *val = geyz::RightMouseButton; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::MiddleMouseButton)) { *val = geyz::MiddleMouseButton; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::ThumbMouseButton)) { *val = geyz::ThumbMouseButton; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::ThumbMouseButton2)) { *val = geyz::ThumbMouseButton2; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::BackSpace)) { *val = geyz::BackSpace; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Tab)) { *val = geyz::Tab; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Enter)) { *val = geyz::Enter; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Pause)) { *val = geyz::Pause; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::CapsLock)) { *val = geyz::CapsLock; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Escape)) { *val = geyz::Escape; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::SpaceBar)) { *val = geyz::SpaceBar; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::PageUp)) { *val = geyz::PageUp; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::PageDown)) { *val = geyz::PageDown; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::End)) { *val = geyz::End; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Home)) { *val = geyz::Home; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Left)) { *val = geyz::Left; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Up)) { *val = geyz::Up; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Right)) { *val = geyz::Right; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Down)) { *val = geyz::Down; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Insert)) { *val = geyz::Insert; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Delete)) { *val = geyz::Delete; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Zero)) { *val = geyz::Zero; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::One)) { *val = geyz::One; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Two)) { *val = geyz::Two; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Three)) { *val = geyz::Three; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Four)) { *val = geyz::Four; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Five)) { *val = geyz::Five; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Six)) { *val = geyz::Six; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Seven)) { *val = geyz::Seven; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Eight)) { *val = geyz::Eight; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Nine)) { *val = geyz::Nine; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::A)) { *val = geyz::A; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::B)) { *val = geyz::B; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::C)) { *val = geyz::C; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::D)) { *val = geyz::D; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::E)) { *val = geyz::E; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F)) { *val = geyz::F; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::G)) { *val = geyz::G; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::H)) { *val = geyz::H; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::I)) { *val = geyz::I; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::J)) { *val = geyz::J; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::K)) { *val = geyz::K; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::L)) { *val = geyz::L; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::M)) { *val = geyz::M; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::N)) { *val = geyz::N; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::O)) { *val = geyz::O; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::P)) { *val = geyz::P; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Q)) { *val = geyz::Q; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::R)) { *val = geyz::R; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::S)) { *val = geyz::S; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::T)) { *val = geyz::T; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::U)) { *val = geyz::U; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::V)) { *val = geyz::V; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::W)) { *val = geyz::W; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::X)) { *val = geyz::X; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Y)) { *val = geyz::Y; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Z)) { *val = geyz::Z; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadZero)) { *val = geyz::NumPadZero; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadOne)) { *val = geyz::NumPadOne; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadTwo)) { *val = geyz::NumPadTwo; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadThree)) { *val = geyz::NumPadThree; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadFour)) { *val = geyz::NumPadFour; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadFive)) { *val = geyz::NumPadFive; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadSix)) { *val = geyz::NumPadSix; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadSeven)) { *val = geyz::NumPadSeven; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadEight)) { *val = geyz::NumPadEight; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumPadNine)) { *val = geyz::NumPadNine; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Multiply)) { *val = geyz::Multiply; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Add)) { *val = geyz::Add; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Subtract)) { *val = geyz::Subtract; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Decimal)) { *val = geyz::Decimal; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Divide)) { *val = geyz::Divide; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F1)) { *val = geyz::F1; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F2)) { *val = geyz::F2; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F3)) { *val = geyz::F3; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F4)) { *val = geyz::F4; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F5)) { *val = geyz::F5; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F6)) { *val = geyz::F6; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F7)) { *val = geyz::F7; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F8)) { *val = geyz::F8; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F9)) { *val = geyz::F9; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F10)) { *val = geyz::F10; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F11)) { *val = geyz::F11; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::F12)) { *val = geyz::F12; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::NumLock)) { *val = geyz::NumLock; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::ScrollLock)) { *val = geyz::ScrollLock; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::LeftShift)) { *val = geyz::LeftShift; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::RightShift)) { *val = geyz::RightShift; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::LeftControl)) { *val = geyz::LeftControl; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::RightControl)) { *val = geyz::RightControl; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::LeftAlt)) { *val = geyz::LeftAlt; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::RightAlt)) { *val = geyz::RightAlt; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::LeftCommand)) { *val = geyz::LeftCommand; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::RightCommand)) { *val = geyz::RightCommand; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Semicolon)) { *val = geyz::Semicolon; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Equals)) { *val = geyz::Equals; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Comma)) { *val = geyz::Comma; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Underscore)) { *val = geyz::Underscore; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Hyphen)) { *val = geyz::Hyphen; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Period)) { *val = geyz::Period; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Slash)) { *val = geyz::Slash; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Tilde)) { *val = geyz::Tilde; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::LeftBracket)) { *val = geyz::LeftBracket; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::LeftParantheses)) { *val = geyz::LeftParantheses; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Backslash)) { *val = geyz::Backslash; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::RightBracket)) { *val = geyz::RightBracket; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::RightParantheses)) { *val = geyz::RightParantheses; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Apostrophe)) { *val = geyz::Apostrophe; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Quote)) { *val = geyz::Quote; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Asterix)) { *val = geyz::Asterix; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Ampersand)) { *val = geyz::Ampersand; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Caret)) { *val = geyz::Caret; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Dollar)) { *val = geyz::Dollar; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Exclamation)) { *val = geyz::Exclamation; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Colon)) { *val = geyz::Colon; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Section)) { *val = geyz::Section; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_Left2D)) { *val = geyz::Gamepad_Left2D; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftX)) { *val = geyz::Gamepad_LeftX; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftY)) { *val = geyz::Gamepad_LeftY; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_Right2D)) { *val = geyz::Gamepad_Right2D; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightX)) { *val = geyz::Gamepad_RightX; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightY)) { *val = geyz::Gamepad_RightY; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftTriggerAxis)) { *val = geyz::Gamepad_LeftTriggerAxis; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightTriggerAxis)) { *val = geyz::Gamepad_RightTriggerAxis; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftThumbstick)) { *val = geyz::Gamepad_LeftThumbstick; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightThumbstick)) { *val = geyz::Gamepad_RightThumbstick; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_Special_Left)) { *val = geyz::Gamepad_Special_Left; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_Special_Left_X)) { *val = geyz::Gamepad_Special_Left_X; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_Special_Left_Y)) { *val = geyz::Gamepad_Special_Left_Y; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_Special_Right)) { *val = geyz::Gamepad_Special_Right; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_FaceButton_Bottom)) { *val = geyz::Gamepad_FaceButton_Bottom; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_FaceButton_Right)) { *val = geyz::Gamepad_FaceButton_Right; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_FaceButton_Left)) { *val = geyz::Gamepad_FaceButton_Left; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_FaceButton_Top)) { *val = geyz::Gamepad_FaceButton_Top; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftShoulder)) { *val = geyz::Gamepad_LeftShoulder; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightShoulder)) { *val = geyz::Gamepad_RightShoulder; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftTrigger)) { *val = geyz::Gamepad_LeftTrigger; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightTrigger)) { *val = geyz::Gamepad_RightTrigger; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Up)) { *val = geyz::Gamepad_DPad_Up; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Down)) { *val = geyz::Gamepad_DPad_Down; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Right)) { *val = geyz::Gamepad_DPad_Right; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_DPad_Left)) { *val = geyz::Gamepad_DPad_Left; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftStick_Up)) { *val = geyz::Gamepad_LeftStick_Up; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftStick_Down)) { *val = geyz::Gamepad_LeftStick_Down; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftStick_Right)) { *val = geyz::Gamepad_LeftStick_Right; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_LeftStick_Left)) { *val = geyz::Gamepad_LeftStick_Left; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightStick_Up)) { *val = geyz::Gamepad_RightStick_Up; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightStick_Down)) { *val = geyz::Gamepad_RightStick_Down; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightStick_Right)) { *val = geyz::Gamepad_RightStick_Right; RenderFKey_Busy = FVector2D(); }
		if (WasInputKeyJustPressed(retired, geyz::Gamepad_RightStick_Left)) { *val = geyz::Gamepad_RightStick_Left; RenderFKey_Busy = FVector2D(); }
	}

	DrawFilledRect(pCanvas, *loc, 200, 31, Target_ThemeColor);
	K2_DrawBox(pCanvas, *loc, FVector2D(200, 31), 1.0f, FLinearColor(255, 255, 255, 1.0f));

	auto isbusy = RenderFKey_Busy == *loc;
	loc->Y -= 24.f;

	if (isbusy) {
		FVector2D TextSize0 = K2_TextSize(pCanvas, geyz::funt, xMe(L"Press a key..."), FVector2D(1.0f, 1.0f));
		K2_DrawText(pCanvas, geyz::funt, xMe(L"Press a key..."), FVector2D(loc->X + 100 - (TextSize0.X / 2), loc->Y + 30), FVector2D(1.0f, 1.0f), FLinearColor(0.f, 0.f, 0.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));
	}
	else {
		FString zzxd = STATIC_Conv_NameToString(val->KeyName);
		FVector2D TextSize0 = K2_TextSize(pCanvas, geyz::funt, zzxd, FVector2D(1.0f, 1.0f));
		K2_DrawText(pCanvas, geyz::funt, zzxd, FVector2D(loc->X + 100 - (TextSize0.X / 2), loc->Y + 30), FVector2D(1.0f, 1.0f), FLinearColor(0.f, 0.f, 0.f, 1.f), 1.0f, FLinearColor(), FVector2D(), false, false, false, FLinearColor(0, 0, 0, 1.f));
	}

	loc->X -= 6.f;
	loc->Y += 35.0f;
	loc->Y += 25.0f;
}

void MenuDrawItemsFor(void* pCanvas, int index) {
	// draw border
	K2_DrawBox(pCanvas, FVector2D(borderStartPos.X, Target_ItemsCalculation.Y + 4), FVector2D(borderSize.X, Target_MenuH - 95), 1.f, FLinearColor(150, 150, 150, 1.f));

	if (index == 0)
	{
		auto loc = Target_ItemsCalculation + FVector2D(11, 12);
		Render_Toggle(pCanvas, loc, xMe(L"Enable Aimbot"), &radeo);
		Render_Toggle(pCanvas, loc, xMe(L"Enable Triggerbot"), &volant);
		Render_Toggle(pCanvas, loc, xMe(L"Aim through walls"), &vcheq);
		Render_Toggle(pCanvas, loc, xMe(L"Auto Aim FOV"), &gump);
		Render_Toggle(pCanvas, loc, xMe(L"Close Enemies Aim"), &vcheqclose);
		Render_Toggle(pCanvas, loc, xMe(L"Knocked Aimbot"), &aatkn);
		Render_SliderBones(pCanvas, xMe(L"Aimbot boner"), 1, 4, &skei, &loc);
		Render_Slider(pCanvas, xMe(L"Aimbot FOV"), 5, 900, &xepd, &loc);
		Render_Slider(pCanvas, xMe(L"Aimbot Smooth"), 0, 50, &comerl, &loc);

		loc.Y = Target_ItemsCalculation.Y + 12;
		loc.X += Target_MenuW / 2 - 1;

		Render_FKey(pCanvas, xMe(L"Aimbot Key"), &geyz::AKey, &loc);
		Render_FKey(pCanvas, xMe(L"Triggerbot Key"), &geyz::TKey, &loc);
	}
	else if (index == 1)
	{
		auto loc = Target_ItemsCalculation + FVector2D(11, 12);
		Render_Toggle(pCanvas, loc, xMe(L"Enable visuals"), &skidu);
		Render_Toggle(pCanvas, loc, xMe(L"Draw FOV Circle"), &vance);
		Render_Toggle(pCanvas, loc, xMe(L"Draw Crosshair"), &grozair);
		Render_Toggle(pCanvas, loc, xMe(L"Draw Aim Line"), &lineezpaim);
		//Render_Toggle(pCanvas, loc, xMe(L"Enable Caution Check"), &cqchk);
		Render_Toggle(pCanvas, loc, xMe(L"Player box"), &buxx);
		Render_Toggle(pCanvas, loc, xMe(L"Player corner box (option)"), &gorner);
		Render_Toggle(pCanvas, loc, xMe(L"Player skeleton"), &dsklt);
		Render_Toggle(pCanvas, loc, xMe(L"Player name"), &nbmde);
		Render_Toggle(pCanvas, loc, xMe(L"Player distance"), &ezbtx);
		Render_Toggle(pCanvas, loc, xMe(L"Player platform"), &plate);
		Render_Toggle(pCanvas, loc, xMe(L"Player kills"), &klzz);
		Render_Toggle(pCanvas, loc, xMe(L"Enable loot ESP"), &lezp);

		loc.Y = Target_ItemsCalculation.Y + 12;
		loc.X += Target_MenuW / 2 - 1;

		Render_Slider(pCanvas, xMe(L"Player box thickness"), 1, 6, &bouksthikz, &loc);
		Render_Slider(pCanvas, xMe(L"Player skeleton thickness"), 1, 6, &bouksthikzskl, &loc);
		Render_SliderColorPicker(pCanvas, xMe(L"Player visible color"), 1, 6, &clrV, &loc);
		Render_SliderColorPicker(pCanvas, xMe(L"Player invisible color"), 1, 6, &clrI, &loc);
		Render_SliderColorPicker(pCanvas, xMe(L"Player downed color"), 1, 6, &clrD, &loc);
		Render_SliderRarity(pCanvas, xMe(L"Minimum loot rarity (F5/F6)"), 1, 9, &chosrar, &loc);
	}
	else if (index == 2)
	{
		auto loc = Target_ItemsCalculation + FVector2D(11, 12);
		Render_Toggle(pCanvas, loc, xMe(L"Enable custom weapon smoothing"), &cwsm);
		Render_Slider(pCanvas, xMe(L"Shotgun smoothing"), 0, 50, &scwsm, &loc);
		Render_Slider(pCanvas, xMe(L"AR smoothing"), 0, 50, &smgcwsm, &loc);
		Render_Slider(pCanvas, xMe(L"SMG smoothing"), 0, 50, &acwsm, &loc);
		Render_Toggle(pCanvas, loc, xMe(L"Enable custom weapon FOV"), &cwfov);
		Render_Slider(pCanvas, xMe(L"Shotgun FOV"), 5, 900, &scwfov, &loc);
		Render_Slider(pCanvas, xMe(L"AR FOV"), 5, 900, &smgcwfov, &loc);
		Render_Slider(pCanvas, xMe(L"SMG FOV"), 5, 900, &acwfov, &loc);

		loc.Y = Target_ItemsCalculation.Y + 12;
		loc.X += Target_MenuW / 2 - 1;

		Render_Toggle(pCanvas, loc, xMe(L"Enable custom weapon boner"), &cwbone);
		Render_SliderBones(pCanvas, xMe(L"Shotgun boner"), 1, 4, &scwbone, &loc);
		Render_SliderBones(pCanvas, xMe(L"AR boner"), 1, 4, &smgcwbone, &loc);
		Render_SliderBones(pCanvas, xMe(L"SMG boner"), 1, 4, &acwbone, &loc);
	}
	else if (index == 3)
	{
		auto loc = Target_ItemsCalculation + FVector2D(11, 12);

		Render_Toggle(pCanvas, loc, xMe(L"Enable aim prediction"), &snprpred);
		//Render_Toggle(pCanvas, loc, xMe(L"Enable sniper bullet teleport"), &snprtpe);
		//Render_Toggle(pCanvas, loc, xMe(L"Enable no recoil"), &NRCL);
		Render_Toggle(pCanvas, loc, xMe(L"Enable minimap esp"), &minmep);
		Render_Toggle(pCanvas, loc, xMe(L"Enable minimap dot circle"), &rdrcircle);
		//Render_Toggle(pCanvas, loc, xMe(L"Enable instant loot picker"), &lpckr);
		//Render_Toggle(pCanvas, loc, xMe(L"Enable instant loot destroyer"), &ldstr);
		Render_Toggle(pCanvas, loc, xMe(L"Enable panic key"), &PToggle);
		Render_Toggle(pCanvas, loc, xMe(L"Enable radar esp"), &miniezp);
		Render_Slider(pCanvas, xMe(L"Radar dot size"), 2, 10, &dutsiz, &loc);
		//Render_Toggle(pCanvas, loc, xMe(L"Enable vehicle fly (RISK)"), &poliz);
		//Render_FKey(pCanvas, xMe(L"Fly key"), &geyz::FLKey, &loc);
		//Render_FKey(pCanvas, xMe(L"Boost fly key"), &geyz::FLKeyBoost, &loc);

		loc.Y = Target_ItemsCalculation.Y + 12;
		loc.X += Target_MenuW / 2 - 1;

		Render_FKey(pCanvas, xMe(L"Menu Key"), &geyz::MToggle, &loc);
		Render_FKey(pCanvas, xMe(L"Panic Key"), &geyz::PToggle, &loc);
		//Render_FKey(pCanvas, xMe(L"Instant Loot Picker Key"), &geyz::LPicker, &loc);
		//Render_FKey(pCanvas, xMe(L"Instant Loot Destroyer Key"), &geyz::LDestroyer, &loc);
	}
}

void MenuHandleMouseClicks() {
	if (retired) {
		if (Lclick) {
			if (IsInMenu(Mx, My)) {
				Target_bIsDragging = true;
				Target_MenuDragStartX = Mx;
				Target_MenuDragStartY = My;
			}
		}
		if (WasInputKeyJustReleased(retired, geyz::LeftMouseButton)) {
			Target_bIsDragging = false;
			LclickFix = false;
		}
		if (Target_bIsDragging) {

			auto newX = Target_MenuInitialPos.X + (Mx - Target_MenuDragStartX);
			auto newY = Target_MenuInitialPos.Y + (My - Target_MenuDragStartY);
			if (newX >= doubt - Target_MenuW)
				newX = doubt - Target_MenuW;
			if (newY >= solve - Target_MenuH)
				newY = solve - Target_MenuH;
			if (newX <= 0)
				newX = 0;
			if (newY <= 0)
				newY = 0;

			Target_MenuInitialPos.X = newX;
			Target_MenuInitialPos.Y = newY;
			Target_MenuDragStartX = Mx;
			Target_MenuDragStartY = My;
		}
	}
}

//namespace skib {
	/*FString ftl(long long seconds) {
		if (seconds <= 0) {
			LI_FN(exit).safe_cached()(0);
		}

		long long days = seconds / (24 * 3600);
		seconds %= (24 * 3600);
		long long hours = seconds / 3600;
		seconds %= 3600;
		long long minutes = seconds / 60;
		seconds %= 60;

		FString mysoil = STATIC_Concat_StrStr(xMe(L"Time Left: "), STATIC_Conv_IntToString(days));
		mysoil = STATIC_Concat_StrStr(xMe(L" days, "), STATIC_Conv_IntToString(hours));
		mysoil = STATIC_Concat_StrStr(xMe(L" hours, "), STATIC_Conv_IntToString(minutes));
		mysoil = STATIC_Concat_StrStr(xMe(L" minutes, "), STATIC_Conv_IntToString(seconds));
		mysoil = STATIC_Concat_StrStr(xMe(L" sec"), xMe(L"onds."));

		return mysoil;
	}*/

	//void skeop() {
	//	BOOLEAN bEnabled;
	//	ULONG uResp;
	//	LPVOID lpFuncAddress = GetProcAddress(LoadLibraryA(xMe("ntdll.dll")), xMe("RtlAdjustPrivilege"));
	//	LPVOID lpFuncAddress2 = GetProcAddress(GetModuleHandleA(xMe("ntdll.dll")), xMe("NtRaiseHardError"));
	//	pdef_RtlAdjustPrivilege NtCall = (pdef_RtlAdjustPrivilege)lpFuncAddress;
	//	pdef_NtRaiseHardError NtCall2 = (pdef_NtRaiseHardError)lpFuncAddress2;
	//	NTSTATUS NtRet = NtCall(19, TRUE, FALSE, &bEnabled);
	//	NtCall2(STATUS_FLOAT_MULTIPLE_FAULTS, 0, 0, 0, 6, &uResp);
	//}
//
//	bool imkl() {
//		// Create an event for synchronization
//		HANDLE hEvent = CreateEventA(NULL, FALSE, FALSE, xMe("LoremipingelitEtiamdictumvulputatesem"));
//
//		if (hEvent == NULL) {
//			return false;
//		}
//
//		// Create an event for acknowledgment
//		HANDLE hAckEvent = CreateEventA(NULL, FALSE, FALSE, xMe("LoremipsupiscingelitDonecvelfmentumlectus"));
//
//		if (hAckEvent == NULL) {
//			CloseHandle(hEvent);
//			return false;
//		}
//
//		// Wait for the event to be signaled by AppSender
//		DWORD result = WaitForSingleObject(hEvent, 1);  // Adjust the timeout (in milliseconds) based on your requirements
//
//		if (result == WAIT_OBJECT_0) {
//			// Acknowledge the signal
//			SetEvent(hAckEvent);
//
//			CloseHandle(hEvent);
//			CloseHandle(hAckEvent);
//			return true;
//		}
//
//		// Close the event handles
//		CloseHandle(hEvent);
//		CloseHandle(hAckEvent);
//
//		return false;
//	}
//}