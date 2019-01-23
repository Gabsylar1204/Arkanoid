#include "MyObject.h"

class Platform : public MyObject
{
public:
	Platform(Bitmap t_sprite, float xpos, float ypos) : MyObject(t_sprite, xpos, ypos)
													  , m_speed(0.1), m_isMoving(false)
	{
	}
	virtual ~Platform() {}
	virtual void update();
	void stop();
	void moveLeft();
	void moveRight();
private:
	float m_speed;
	bool m_isMoving;
};