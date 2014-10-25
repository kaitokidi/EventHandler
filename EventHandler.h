#ifndef _EVENT_HANDLER_HPP_
#define _EVENT_HANDLER_HPP_

#include <vector>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

enum dir {up, down, left, right, no_dir};
enum edir {N, NE, E, SE, S, SW, W, no_edir};

class EventHandler {

	public:

		/** 
		* Creator of the Event Handler object
		*no parameters required 
		*/
		EventHandler();
		
		/** 
		* Function that will handle the events for the given window 'w'
		* w -> renderWindow from which you want to handle the events;
		*/
		void handleEvents(sf::RenderWindow& w);
		
		/**
		 * Function to set which keys do you want to use for your keyboard
		 * and the id you will use to take their values, by default it will
		 * use W A S D which will be the id = 0;
		 * keys -> a vector with the four keys using sf::Keyboard::Key, 
		 * in the order up, down, left, right
		 * id -> integer that will discrimine which keyboard are you using
		 */
		void setDirectionKeys(std::vector<sf::Keyboard::Key> keys, int id);
		
		//getters
		//setXbuttonk_m_j
		
		
	private:

		dir k_dir;
		dir m_dir;
		dir j_dir;
		
		edir k_edir;
		edir m_edir;
		edir j_edir;
	
	
};

#endif // _EVENT_HANDLER_HPP_
