#include "MyObject.h"

class Ball : public MyObject
{
public:
	Ball(Bitmap t_sprite, float xpos, float ypos) : MyObject(t_sprite, xpos, ypos)
												  , m_speedX(0.05), m_speedY(-0.05)
	{
	}
	virtual				 ~Ball() {}
	virtual void		 update();
			void		 setDirection(Direction dir);

private:
	float m_speedX, m_speedY;
};