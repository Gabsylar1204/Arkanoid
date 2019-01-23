#include "MyObject.h"

MyObject::MyObject(Bitmap t_sprite, float t_xpos, float t_ypos) : m_sprite(new Bitmap(t_sprite))
													  , m_rect(Rect(t_xpos, t_ypos, t_sprite.GetWidth(), t_sprite.GetHeight()))
{
	m_position.push_back(t_xpos);
	m_position.push_back(t_ypos);
}
MyObject::~MyObject()
{
	delete m_sprite;
}
void MyObject::updateAll(float x, float y) 
{
	m_rect = Rect(x, y, m_sprite->GetWidth(), m_sprite->GetHeight()); 
	update();
}