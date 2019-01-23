#include <prcore/prcore.hpp>
#include <vector>

using namespace prcore;

#ifndef MY_OBJECT
#define MY_OBJECT

enum Direction { UP, DOWN, SIDE };

class MyObject
{
public:
	MyObject() : m_sprite(NULL) {}
	MyObject(Bitmap t_sprite, float t_xpos, float t_ypos);
	virtual ~MyObject();
	virtual void updateAll(float x, float y);
	virtual void update() {}
	virtual Bitmap GetSprite() { return *m_sprite; }
	virtual Rect GetRect() { return m_rect; }
	virtual float GetX() { return m_position[0]; }
	virtual float GetY() { return m_position[1]; }
	virtual float GetWidth() { return m_sprite->GetWidth(); }
	virtual float GetHeight() { return m_sprite->GetHeight(); }
protected:
	Bitmap* m_sprite;
	Rect m_rect;
	std::vector<float> m_position;
};
#endif
