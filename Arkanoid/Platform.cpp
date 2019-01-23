#include "Platform.h"

void Platform::update()
{
	if(m_isMoving)
		m_position[0] += m_speed;
}
void Platform::stop() 
{ 
	m_isMoving = false; 
}
void Platform::moveLeft() 
{ 
	m_isMoving = true; 
	m_speed = -0.1; 
}
void Platform::moveRight() 
{ 
	m_isMoving = true; 
	m_speed = 0.1;
}