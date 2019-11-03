#pragma once
class State
{
public:
	State();
	~State();
	virtual void Init() = 0;

	virtual void HandleInput() = 0;
	virtual void Update() = 0;
	virtual void Draw(float DeltaTime) = 0;
	virtual void Pause() {}
	virtual void Resume() {}
};