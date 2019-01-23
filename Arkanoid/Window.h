#pragma once

#include <map>
#include "Ball.h"
#include "Platform.h"

#define			map_it   std::map<MyObject*, bool>::iterator

using namespace prcore;

// I know about smart pointers, but VS2008 doesn't support C++11
class Window : public FrameBuffer
{
public:
	Window();
	~Window();
	bool EventMain();
	void EventDraw();
	bool collision(Rect &r1, Rect &r2);
	void processTargets();
	bool settingsInput();

private:
	Ball* m_ball;
	Platform* m_platform;
	std::map<MyObject*, bool> m_targets;
	Rect m_border;
};