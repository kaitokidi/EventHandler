#ifndef _EVENT_HANDLER_HPP_
#define _EVENT_HANDLER_HPP_

#include <vector>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

enum dir  {up, down, left, right, no_dir};
enum edir {N, S, E, W, NE, NW, SE, SW, no_edir};

class EventHandler {

	public:

		/** 
		* Creator of the Event Handler object
		*no parameters required 
		*/
		EventHandler();
		
		/** 
		* Function that will handle the events for the given window 'w'
		* 	w -> renderWindow from which you want to handle the events;
		*/
		void handleEvents(sf::RenderWindow& w);
		
		/** 
		* Function that will update the variables if the event requieres it.
		*/
		void handleEvent(sf::Event e);
		
		/**
		 * Function to set which keys do you want to use for the directions
		 * control (only up down right left) on your keyboard
		 * and the id you will use to take their values, by default it will
		 * use W A S D and id = 0;
		 * 	keys -> a vector with the four keys using sf::Keyboard::Key, 
		 * 		in the order: up, down, left, right
		 * 	id -> integer that will discrimine which keyboard are you using
		 */
		void setDirectionKeys(std::vector<sf::Keyboard::Key> keys, int id);
		
		/**
		 * Function to set which keys do you want to use for the directions
		 * control (up down right left and diagonals) on your keyboard
		 * and the id you will use to take their values, by default it will
		 * use W A S D and id = 0;
		 * 	keys -> a vector with the four keys using sf::Keyboard::Key, 
		 * 		in the order: up, down, left, right
		 * 	id -> integer that will discrimine which keyboard are you using
		 */ 
		void setExtendedDirectionKeys(std::vector<sf::Keyboard::Key> keys, int id);
		
		/**
		 * Function to set the Fire button of the joystick
		 * 	but -> the number of the button you want to use
		 * 		(it depends on the joystick so check it out)
		 */
		void setFireKey_j(int but);
		
		/**
		 * Function to set the Fire key of the keyboard
		 * 	key -> the kay you want to use to fire in the form sf::Keyboard::Key key
		 */
		void setFireKey_k(sf::Keyboard::Key key);
		
		/**
		 * Function to set the Fire button of the mouse
		 * 	but -> the button you want to use to fire in the form sf::Mouse::Button but
		 */
		void setFireKey_m(sf::Mouse::Button but);
		
		void setJumpKey_j(int but);
		void setJumpKey_k(sf::Keyboard::Key key);
		void setJumpKey_m(sf::Mouse::Button but);
		
		void setActionKey_j(int but, int id);
		void setActionKey_k(sf::Keyboard::Key key, int id);
		void setActionKey_m(sf::Mouse::Button but, int id);
		
		
		//getters
		//setXbuttonk_m_j
		
		
	private:		

		dir k_dir;
		dir m_dir;
		dir j_dir;
		
		edir k_edir;
		edir m_edir;
		edir j_edir;

		int fireBut_j;
		int jumpBut_j;
		std::vector<int> actionBut_j;
		
		sf::Keyboard::Key fireKey_k;
		sf::Keyboard::Key jumpKey_k;
		std::vector<bool> actionActivated_k;
		std::vector<sf::Keyboard::Key> actionKey_k;
		
		sf::Mouse::Button fireBut_m;
		sf::Mouse::Button jumpBut_m;		
		std::vector<bool> actionActivated_m;
		std::vector<sf::Mouse::Button> actionBut_m;
		
		bool haveFocus;
		bool fireActivated;
		bool jumpActivated;
		
		std::vector<sf::Keyboard::Key> dirKeys;
		std::vector<sf::Keyboard::Key> edirKeys;
	
};

#endif // _EVENT_HANDLER_HPP_
