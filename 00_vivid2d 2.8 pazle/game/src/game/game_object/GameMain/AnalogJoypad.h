#pragma once

#include "vivid.h"

//アナログスティック 左入力 受け取り
vivid::Vector2 AnalogJoyPad_Left(void);
//アナログスティック 右入力 受け取り
vivid::Vector2 AnalogJoyPad_Right(void);
//アナログスティックの入力状況を画面右上に表示
void AnalogJoyPad_InputCheck(void);

vivid::Vector2 AnalogJoyPad_Left(void)
{
	int InputX;
	int InputY;

	GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_PAD1);

	vivid::Vector2 Input = { (float)InputX,(float)InputY };

	return Input;
}

vivid::Vector2 AnalogJoyPad_Right(void)
{
	DINPUT_JOYSTATE input;

	GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

	vivid::Vector2 Input = { (float)input.Rx,(float)input.Ry };

	return Input;
}

void AnalogJoyPad_InputCheck(void)
{
	DINPUT_JOYSTATE input;
	int Color = 0xffffffff;

	GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

	DrawFormatString(0, 0, Color, "X:%d Y:%d", input.X, input.Y);
	DrawFormatString(0, 16, Color, "X:%d Y:%d", input.Rx, input.Ry);
}