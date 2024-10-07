#pragma once
#include"vivid.h"

class CREDIT 
{
protected:
	const float  width;
	const float	 height;
	vivid::Vector2 pos;
public:
	void Initialize(void) ;
	void Update(void) ;
	void Draw(void) ;
	void Finalize(void);
};
