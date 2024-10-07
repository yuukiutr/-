#pragma once

class GenericFunctionManager
{
private:

public:
	void Initialize(void);
	void Update(void);
	void Draw(void);
	void Finalize(void);

	void Animation(int width, int height);
};