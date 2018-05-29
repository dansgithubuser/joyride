#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>

int main(){
	sf::RenderWindow window(sf::VideoMode(640, 480), "joyrider");
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed: window.close(); break;
				case sf::Event::JoystickButtonPressed: case sf::Event::JoystickButtonReleased:
					std::cout<<"joystick: "<<event.joystickButton.joystickId<<", ";
					std::cout<<"button: "<<event.joystickButton.button<<", ";
					std::cout<<(event.type==sf::Event::JoystickButtonPressed?"pressed":"released")<<"\n";
					break;
				case sf::Event::JoystickMoved:
					std::cout<<"joystick: "<<event.joystickMove.joystickId<<", ";
					std::cout<<"axis: "<<event.joystickMove.axis<<", ";
					std::cout<<"position: "<<event.joystickMove.position<<"\n";
					break;
				case sf::Event::JoystickConnected: case sf::Event::JoystickDisconnected:
					std::cout<<"joystick: "<<event.joystickConnect.joystickId<<", ";
					std::cout<<(event.type==sf::Event::JoystickConnected?"connected":"disconnected")<<"\n";
					break;
				default: break;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	return 0;
}
