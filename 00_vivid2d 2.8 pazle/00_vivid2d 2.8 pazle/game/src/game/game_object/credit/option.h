#pragma once
#include"vivid.h"

class OPTION 
{
protected:
	const float  width = 0.0f;
	const float	 height = 0.0f;
	vivid::Vector2 pos;
public:
	void Initialize(void) ;
	void Update(void) ;
	void Draw(void) ;
	void Finalize(void);
};
