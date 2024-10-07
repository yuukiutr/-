#pragma once

#include "vivid.h"

//�A�i���O�X�e�B�b�N ������ �󂯎��
vivid::Vector2 AnalogJoyPad_Left(void);
//�A�i���O�X�e�B�b�N �E���� �󂯎��
vivid::Vector2 AnalogJoyPad_Right(void);
//�A�i���O�X�e�B�b�N�̓��͏󋵂���ʉE��ɕ\��
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