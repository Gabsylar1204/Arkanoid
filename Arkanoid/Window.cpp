#include "Window.h"

Window::Window()
{
	OpenBuffer(640,480,"TestArkanoid");

	m_targets[new MyObject(Bitmap(40, 20, PIXELFORMAT_RGB888), 50, 50)] = false;
	m_targets[new MyObject(Bitmap(40, 20, PIXELFORMAT_RGB888), 250, 100)] = false;
	m_targets[new MyObject(Bitmap(40, 20, PIXELFORMAT_RGB888), 400, 250)] = false;

	m_ball = new Ball (Bitmap("ball.png", PIXELFORMAT_ARGB8888), 250, 250);
	m_platform = new Platform(Bitmap("capsule.png", PIXELFORMAT_ARGB8888), 250, 400);
	m_border = GetWindowRect();
}

bool Window::EventMain()
{
	EventDraw();
	return true;
}
void Window::EventDraw()
{
	if(m_ball && m_platform)
	{
		processTargets();
	
		if(m_ball->GetX() <= 0 || m_ball->GetX() >= m_border.width - m_ball->GetWidth())
		{
			m_ball->setDirection(SIDE);
		}
		
		if(m_ball->GetY() <= 0)
		{
			m_ball->setDirection(DOWN);
		}

		else if(collision(m_platform->GetRect(), m_ball->GetRect()))
		{
			m_ball->setDirection(UP);
		}
		else if(m_ball->GetY() >= m_border.height - m_ball->GetHeight())
		{
			delete m_ball;
			delete m_platform;
			m_ball = NULL;
			m_platform = NULL;
			BlitWrite(0, 0, Bitmap("game_over.jpg", PIXELFORMAT_ARGB8888));
			PageFlip();
			return;
		}

		if(IsDown(KEYCODE_LEFT) && !(m_platform->GetX() <= 0))
		{
			m_platform->moveLeft();
		}
		else if(IsDown(KEYCODE_RIGHT) && !(m_platform->GetX() >= m_border.width - m_platform->GetWidth()))
		{
			m_platform->moveRight();
		}
		else
			m_platform->stop();

		m_ball->updateAll(m_ball->GetX(), m_ball->GetY());
		m_platform->updateAll(m_platform->GetX(), m_platform->GetY());

		ClearBuffer(0x0);
		for(map_it target = m_targets.begin(); target != m_targets.end();)
			if(!(*target).second)
			{
				BlitWrite((*target).first->GetX(), (*target).first->GetY(), (*target).first->GetSprite());
				++target;
			}
			else
			{
				std::map<MyObject*, bool>::iterator temp = target;
				++target;
				m_targets.erase(temp);
			}
		if(m_targets.empty())
		{
			delete m_ball;
			delete m_platform;
			m_ball = NULL;
			m_platform = NULL;
			BlitWrite(0, 0, Bitmap("win.png", PIXELFORMAT_ARGB8888));
			PageFlip();
			return;
		}
			

		BlitWrite(m_ball->GetX(), m_ball->GetY(), m_ball->GetSprite());
		BlitWrite(m_platform->GetX(), m_platform->GetY(), m_platform->GetSprite());

		PageFlip();
	}

}

bool Window::collision(Rect& r1, Rect& r2)
{
	return r1.Intersect(r1, r2);
}

// process collision between ball and targets to be destroyed
// NOTE: here C++11 for cycle could be used, but VS2008 doesn't support C++11
void Window::processTargets()
{
	for(map_it target = m_targets.begin(); target != m_targets.end(); ++target)
	{
		if(collision(m_ball->GetRect(), (*target).first->GetRect()))
		{
			if((abs(m_ball->GetX() - (*target).first->GetX()) <= 0.1) 
				|| (abs(m_ball->GetX() - (*target).first->GetX() + (*target).first->GetWidth()) <= 0.1))
			{
				m_ball->setDirection(SIDE);
				(*target).second = true;
				continue;
			}
			if(abs(m_ball->GetY() - (*target).first->GetY()) <= 0.1)
			{
				m_ball->setDirection(UP);
				(*target).second = true;
				continue;
			}
			else if(abs(m_ball->GetY() - (*target).first->GetY() - (*target).first->GetHeight()) <= 0.1)
			{
				m_ball->setDirection(DOWN);
				(*target).second = true;
				continue;
			}
		}
	}
}

bool Window::settingsInput() // can be later turned into an adequate input handler
{
	m_targets[new MyObject(Bitmap(40, 20, PIXELFORMAT_RGB888), 50, 50)] = false;
	m_targets[new MyObject(Bitmap(40, 20, PIXELFORMAT_RGB888), 250, 100)] = false;
	m_targets[new MyObject(Bitmap(40, 20, PIXELFORMAT_RGB888), 400, 250)] = false;

	return true;
}
Window::~Window(void)
{
	delete m_ball;
	delete m_platform;
}
