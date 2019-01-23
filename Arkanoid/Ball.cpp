#include "Ball.h"

void Ball::update()
{
	m_position[0] += m_speedX;
	m_position[1] += m_speedY;
}
void Ball::setDirection(Direction dir)
{
	switch(dir)
	{
	case SIDE:
		m_speedX *= -1;
		break;
	case UP:
		m_speedY = -0.05;
		break;
	case DOWN:
		m_speedY = 0.05;
		break;
	default:
		m_speedX *= -1;
		m_speedY *= -1;
		break;
	}
}