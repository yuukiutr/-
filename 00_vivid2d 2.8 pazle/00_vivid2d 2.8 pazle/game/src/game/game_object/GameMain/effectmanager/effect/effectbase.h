#pragma once
#include "vivid.h"
#include "../effect_id.h"

class EffectBase
{
protected:
	int m_Width;
	int m_Height;

	vivid::Vector2	m_Position;
	unsigned int	m_Color;
	vivid::Rect		m_Rect;
	vivid::Vector2	m_Center;
	vivid::Vector2	m_Scale;
	float			m_Rotation;

	float m_Angle;
	float m_Speed;

public:

	EffectBase(int width,int height);
	virtual void Initialize(vivid::Vector2 pos,float rotation);
	virtual void Update(void);
	virtual void Draw(void);
	virtual void Finalize(void);

	//Active== true other == false
	bool GetActiveFlag(void);

};