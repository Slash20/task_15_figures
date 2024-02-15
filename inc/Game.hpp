#pragma once
#include <string>
#include <Circle.hpp>
#include <Rectangle.hpp>
#include <Triangle.hpp>
#include <Lines.hpp>



namespace mt
{
	class Game
	{
		int m_width;
		int m_height;
		int m_n;
		std::string m_capture;
		mt::Circle* m_c;
		mt::Triangle* m_t;
		mt::Line* m_l;
		mt::Rectangle* m_r;
		sf::RenderWindow m_window;
		
	public:
		Game(int width, int height, const std::string& capture)
		{
			m_width = width;
			m_height = height;
			m_capture = capture;
		}

		void Setup(int n)
		{
			m_n = n;

			m_window.create(sf::VideoMode(m_width, m_height), m_capture);

			srand(time(0));

			m_c = new mt::Circle[m_n];
			m_l = new mt::Line[m_n];
			m_r = new mt::Rectangle[m_n];
			m_t = new mt::Triangle[m_n];

			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 600;
				int r = rand() % 100 + 1;
				m_c[i].Setup(x, y, r);
			}

			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 600;

				int a = 200;
				int b = 50;
				
				
				m_r[i].Setup(x, y, a, b);
			}

			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 600;

				m_t[i].Setup(x, y);
			}

			for (int i = 0; i < m_n; i++)
			{
				int x = rand() % 1000;
				int y = rand() % 600;

				int a = 150;
				int b = 5;

				m_l[i].Setup(x, y, a, b);
			}

		}

		void LifeCycle()
		{
			while (m_window.isOpen())
			{

				sf::Event event;
				while (m_window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						m_window.close();
				}

				m_window.clear();
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_c[i].Get());
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_r[i].Get());
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_t[i].Get());
				for (int i = 0; i < m_n; i++)
					m_window.draw(m_l[i].Get());
				


				m_window.display();
			}
		}
	};
}