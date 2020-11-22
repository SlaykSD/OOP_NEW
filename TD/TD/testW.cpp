#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
using namespace sf;
using namespace std;
class A
{
protected:
	A();
	void foo()
	{
		cout << "foo() called\n";
	};
	sf::Sprite sprite;
public:
	virtual void g(sf::RenderWindow* window) //обратите внимание на ключевое слово virtual
	{
		cout << "original g() called\n";
	};
};

class B : public A
{
public:
	B();
	virtual void g(sf::RenderWindow* window) //обратите внимание на ключевое слово virtual
	{
		cout << "g() called\n\t";
		foo();
		sprite.setTexture(texture);
		window->draw(sprite);
	};
private:
	sf::Texture texture;
};
int fun(sf::RenderWindow& window);
int fun2(sf::RenderWindow& window);
int fun3(sf::RenderWindow& widnow);
class cScreen
{
public:
	virtual int Run(sf::RenderWindow& App) = 0;
};
class screen_1 : public cScreen
{
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
public:
	screen_1(void);
	virtual int Run(sf::RenderWindow& App);
};
screen_1::screen_1(void)
{
	movement_step = 5;
	posx = 320;
	posy = 240;
	//Setting sprite
	Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
	Rectangle.setSize({ 10.f, 10.f });
}

int screen_1::Run(sf::RenderWindow& App)
{
	sf::Event Event;
	bool Running = true;

	while (Running)
	{
		B objB;
		//objB.g(&App);                     //Вызовется g() из объекта типа A, как и должно быть
		A* ptrA = (A*)(&objB); //берём адрес objB, приводим его к типу указателя на A и                         //записываем в ptrA
		B* ptrB = (B*)(ptrA);
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (Event.type == sf::Event::MouseButtonPressed)
			{
				if (Event.key.code == sf::Mouse::Left)
				{
					return 0;
				}
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Escape:
					return (0);
					break;
				case sf::Keyboard::Up:
					posy -= movement_step;
					break;
				case sf::Keyboard::Down:
					posy += movement_step;
					break;
				case sf::Keyboard::Left:
					posx -= movement_step;
					break;
				case sf::Keyboard::Right:
					posx += movement_step;
					break;
				default:
					break;
				}
			}
		}

		//Updating
		if (posx > 630)
			posx = 630;
		if (posx < 0)
			posx = 0;
		if (posy > 470)
			posy = 470;
		if (posy < 0)
			posy = 0;
		Rectangle.setPosition({ posx, posy });

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing
		App.draw(Rectangle);
		ptrA->g(&App);
		ptrB->g(&App);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}
A::A():sprite()
{
	sprite.setTextureRect(sf::Rect<int>(0, 0, 64, 64));
}
B::B()
{
	sf::Rect <int> rect(0, 0, 64, 64);
	sf::Image widget; //создаем объект Image (изображение)
	widget.loadFromFile("heavy_infantry.png");//загружаем в него файл
	widget.createMaskFromColor(sf::Color(255, 255, 255));
	texture.loadFromImage(widget);
}
/*int main()
{
	sf::RenderWindow window(sf::VideoMode(640, 640), "SFML works!");
	screen_1 scr;

	scr.Run(window);
	//fun2(window);
	fun3(window);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	return 1;
}
*/
int fun(sf::RenderWindow& window)
{
	int choise;
	sf::Vector2i vec = sf::Mouse::getPosition(window);
	Texture widget_buy;
	widget_buy.loadFromFile("widget_buy_effect.jpg");
	sf::Sprite menu1(widget_buy);
	menu1.setTextureRect(IntRect(0, 0, 64, 64));

	sf::Sprite menu2(widget_buy);
	menu2.setTextureRect(IntRect(64, 0, 64, 64));

	sf::Sprite menu3(widget_buy);
	menu3.setTextureRect(IntRect(0, 64, 64, 64));

	sf::Sprite menu4(widget_buy);
	menu4.setTextureRect(IntRect(64, 64, 64, 64));

	menu1.setPosition(vec.x - 64, vec.y - 64);
	menu2.setPosition(vec.x, vec.y - 64);
	menu3.setPosition(vec.x - 64, vec.y);
	menu4.setPosition(vec.x, vec.y);


	bool isMenu = 1;
	int menuNumb = 0;
	sf::Vector2i tmp;
	sf::Event Event;
	int fluctuation_x, fluctuation_y, fluctuation_x2, fluctuation_y2;
	while (isMenu)
	{
		menuNumb = 0;
		tmp = sf::Mouse::getPosition(window);
		fluctuation_x = (int)(tmp.x - vec.x);
		fluctuation_y = (int)(tmp.y - vec.y);
		std::cout << "x: " << tmp.x << " y: " << tmp.y;
		std::cout << "\nf1 x: " << fluctuation_x << " f1 y: " << fluctuation_y;
		if ((abs(fluctuation_x) <= 64 && fluctuation_x < 0) && (abs(fluctuation_y) <= 64 && fluctuation_y < 0))
		{
			menu1.setColor(Color::Red); menuNumb = 1;
		}
		else
		{
			menu1.setColor(Color::White);
		}


		if ((abs(fluctuation_x) <= 64 && fluctuation_x > 0) && (abs(fluctuation_y) <= 64 && fluctuation_y < 0))
		{
			menu2.setColor(Color::Red); menuNumb = 2;
		}
		else
		{
			menu2.setColor(Color::White);
		}


		if ((abs(fluctuation_x) <= 64 && fluctuation_x < 0) && (abs(fluctuation_y) <= 64 && fluctuation_y > 0))
		{
			menu3.setColor(Color::Red); menuNumb = 3;
		}
		else
		{
			menu3.setColor(Color::White);
		}

		if ((abs(fluctuation_x) <= 64 && fluctuation_x > 0) && (abs(fluctuation_y) <= 64 && fluctuation_y > 0))
		{
			menu4.setColor(Color::Red); menuNumb = 4;
		}
		else
		{
			menu4.setColor(Color::White);
		}


		while (window.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (Event.type == sf::Event::MouseButtonPressed)
			{

				if (menuNumb != 0)
				{
					std::cout << "succes" << std::endl;
					isMenu = false;
					choise = menuNumb;
				}
				else
				{
					std::cout << "unsucces" << std::endl;
					isMenu = false;
					choise = 0;
				}
			}
			//Key pressed

		}
		system("cls");
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
	return choise;
}

int fun2(sf::RenderWindow& window)
{

	int choise;
	sf::Vector2i vec = sf::Mouse::getPosition(window);
	Texture widget_buy;
	widget_buy.loadFromFile("widget_lvlup.jpg");
	sf::Sprite menu1(widget_buy);
	menu1.setTextureRect(IntRect(0, 0, 64, 64));

	sf::Sprite menu2(widget_buy);
	menu2.setTextureRect(IntRect(64, 0, 64, 64));

	menu1.setPosition(vec.x-64, vec.y-32);
	menu2.setPosition(vec.x, vec.y-32);
	bool isMenu = 1;
	int menuNumb = 0;
	sf::Vector2i tmp;
	sf::Event Event;
	int fluctuation_x, fluctuation_y, fluctuation_x2, fluctuation_y2;
	while (isMenu)
	{
		menuNumb = 0;
		tmp = sf::Mouse::getPosition(window);
		fluctuation_x = (int)(tmp.x - vec.x);
		fluctuation_y = (int)(tmp.y - vec.y-32);
		std::cout << "x: " << tmp.x << " y: " << tmp.y;
		std::cout << "\nf1 x: " << fluctuation_x << " f1 y: " << fluctuation_y;
		if ((abs(fluctuation_x) <= 64 && fluctuation_x < 0) && (abs(fluctuation_y) <= 64 && fluctuation_y < 0))
		{
			menu1.setColor(Color::Red); menuNumb = 1;
		}
		else
		{
			menu1.setColor(Color::White);
		}


		if ((abs(fluctuation_x) <= 64 && fluctuation_x > 0) && (abs(fluctuation_y) <= 64 && fluctuation_y < 0))
		{
			menu2.setColor(Color::Red); menuNumb = 2;
		}
		else
		{
			menu2.setColor(Color::White);
		}
		while (window.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (Event.type == sf::Event::MouseButtonPressed)
			{
				if (menuNumb != 0)
				{
					std::cout << "succes" << std::endl;
					isMenu = false;
					choise = menuNumb;
				}
				else
				{
					isMenu = false;
					choise = 0;
				}
			}
			//Key pressed

		}
		system("cls");
		window.draw(menu1);
		window.draw(menu2);
		window.display();
	}
	return choise;
}

int fun3(sf::RenderWindow& window)
{

	int choise;
	sf::Vector2i vec = sf::Mouse::getPosition(window);
	Image widget; //создаем объект Image (изображение)
	widget.loadFromFile("magic_tower_f.png");//загружаем в него файл
	widget.createMaskFromColor(sf::Color(255, 255, 255));

	Image widget2; //создаем объект Image (изображение)
	widget2.loadFromFile("magic_tower_p.png");//загружаем в него файл
	widget2.createMaskFromColor(sf::Color(255, 255, 255));

	Image widget3; //создаем объект Image (изображение)
	widget3.loadFromFile("magic_tower_m.png");//загружаем в него файл
	widget3.createMaskFromColor(sf::Color(255, 255, 255));

	Image widget4; //создаем объект Image (изображение)
	widget4.loadFromFile("towerDefense_tile204.png");//загружаем в него файл
	widget4.createMaskFromColor(sf::Color(255, 255, 255));

	Texture widget_buy;
	Texture widget_buy1;
	Texture widget_buy2;
	Texture widget_buy3;
	widget_buy.loadFromImage(widget);
	widget_buy2.loadFromImage(widget2);
	widget_buy1.loadFromImage(widget3);
	widget_buy3.loadFromImage(widget4);
	sf::Sprite menu1(widget_buy);
	menu1.setTextureRect(IntRect(0, 0, 64, 64));
	menu1.setColor(sf::Color(255, 255, 255, 0));

	sf::Sprite menu2(widget_buy1);
	menu2.setTextureRect(IntRect(0, 0, 64, 64));
	menu2.setColor(sf::Color(255, 255, 255, 0));

	sf::Sprite menu3(widget_buy2);
	menu3.setTextureRect(IntRect(0, 0, 64, 64));
	menu3.setColor(sf::Color(255, 255, 255, 0));

	sf::Sprite menu4(widget_buy3);
	menu4.setTextureRect(IntRect(0, 0, 64, 64));
	menu4.setColor(sf::Color(255, 255, 255, 0));

	menu1.setPosition(vec.x - 64, vec.y - 64);
	menu2.setPosition(vec.x, vec.y - 64);
	menu3.setPosition(vec.x - 64, vec.y);
	menu4.setPosition(vec.x, vec.y);


	bool isMenu = 1;
	int menuNumb = 0;
	sf::Vector2i tmp;
	sf::Event Event;
	int fluctuation_x, fluctuation_y, fluctuation_x2, fluctuation_y2;
	while (isMenu)
	{
		menuNumb = 0;
		tmp = sf::Mouse::getPosition(window);
		fluctuation_x = (int)(tmp.x - vec.x);
		fluctuation_y = (int)(tmp.y - vec.y);
		std::cout << "x: " << tmp.x << " y: " << tmp.y;
		std::cout << "\nf1 x: " << fluctuation_x << " f1 y: " << fluctuation_y;
		if ((abs(fluctuation_x) <= 64 && fluctuation_x < 0) && (abs(fluctuation_y) <= 64 && fluctuation_y < 0))
		{
			menu1.setColor(Color::Red); menuNumb = 1;
		}
		else
		{
			menu1.setColor(Color::White);
		}


		if ((abs(fluctuation_x) <= 64 && fluctuation_x > 0) && (abs(fluctuation_y) <= 64 && fluctuation_y < 0))
		{
			menu2.setColor(Color::Red); menuNumb = 2;
		}
		else
		{
			menu2.setColor(Color::White);
		}


		if ((abs(fluctuation_x) <= 64 && fluctuation_x < 0) && (abs(fluctuation_y) <= 64 && fluctuation_y > 0))
		{
			menu3.setColor(Color::Red); menuNumb = 3;
		}
		else
		{
			menu3.setColor(Color::White);
		}

		if ((abs(fluctuation_x) <= 64 && fluctuation_x > 0) && (abs(fluctuation_y) <= 64 && fluctuation_y > 0))
		{
			menu4.setColor(Color::Red); menuNumb = 4;
		}
		else
		{
			menu4.setColor(Color::White);
		}


		while (window.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			if (Event.type == sf::Event::MouseButtonPressed)
			{

				if (menuNumb != 0)
				{
					std::cout << "succes" << std::endl;
					isMenu = false;
					choise = menuNumb;
				}
				else
				{
					std::cout << "unsucces" << std::endl;
					isMenu = false;
					choise = 0;
				}
			}
			//Key pressed

		}
		system("cls");
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
	return choise;
}