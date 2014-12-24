#include "EventHandler.h"

	EventHandler::EventHandler(){
		
		int qtty = (int)sf::Keyboard::KeyCount;
		actionActivated_k = std::vector<bool> (qtty, false);
		actionKey_k = std::vector<sf::Keyboard::Key> (qtty, sf::Keyboard::Unknown);
		
		dirKeys = std::vector<sf::Keyboard::Key> (4);
		dirKeys[0] = sf::Keyboard::Up; dirKeys[1] = sf::Keyboard::Down;
		dirKeys[2] = sf::Keyboard::Right; dirKeys[3] = sf::Keyboard::Left;
		
		edirKeys = std::vector<sf::Keyboard::Key> (4);
		edirKeys[0] = sf::Keyboard::W;	edirKeys[1] = sf::Keyboard::S;
		edirKeys[2] = sf::Keyboard::D;	edirKeys[3] = sf::Keyboard::A;
		edirKeys[4] = sf::Keyboard::E;	edirKeys[5] = sf::Keyboard::Q;
		edirKeys[6] = sf::Keyboard::C;	edirKeys[7] = sf::Keyboard::Z;
		
		fireKey_k = sf::Keyboard::F;
		jumpKey_k = sf::Keyboard::Space;

	}
	
	/** 
	 * Function that will handle the events for the given window 'w'
	 * w -> renderWindow from which you want to handle the events;
	 */
	void EventHandler::handleEvents(sf::RenderWindow& w){
		sf::Event event;
		while(w.pollEvent(event)){
			handleEvent(event);
		}	
	}

	void EventHandler::handleEvent(sf::Event event){ 
		switch (event.type){
				//KeyPressed event
				case  sf::Event::KeyPressed:
					
					//basic movement
					if (event.key.code == dirKeys[up])    { k_dir = up; }
					if (event.key.code == dirKeys[down])  { k_dir = down; }
					if (event.key.code == dirKeys[left])  { k_dir = left; }
					if (event.key.code == dirKeys[right]) { k_dir = right; }
					
					//extended movement
					if (event.key.code == edirKeys[N])  { k_edir = N; }
					if (event.key.code == edirKeys[S])  { k_edir = S; }
					if (event.key.code == edirKeys[E])  { k_edir = E; }
					if (event.key.code == edirKeys[W])  { k_edir = W; }
					if (event.key.code == edirKeys[NE]) { k_edir = NE; }
					if (event.key.code == edirKeys[NW]) { k_edir = NW; }
					if (event.key.code == edirKeys[SE]) { k_edir = SE; }
					if (event.key.code == edirKeys[SW]) { k_edir = SW; }
					
					//fire
					if (event.key.code == fireKey_k) { fireActivated = true; }
					
					//jump 
					if (event.key.code == jumpKey_k) { jumpActivated = true; }

					//actions
					for(int i = 0; i < actionKey_k.size(); ++i) {
						if (event.key.code == actionKey_k[i]) { 
								actionActivated_k[i] = true;
						}
					}
					
				break;
				
				//Default
				default:
					//Do nothing
					break;
			}
	}
	
	void EventHandler::setDirectionKeys(std::vector<sf::Keyboard::Key> keys, int id){ dirKeys = keys; }
	
	void EventHandler::setExtendedDirectionKeys(std::vector<sf::Keyboard::Key> keys, int id){ edirKeys = keys; }

	
	void EventHandler::setFireKey_j(int but){ fireBut_j = but; }
	
	void EventHandler::setFireKey_k(sf::Keyboard::Key key){ fireKey_k = key; }
	
	void EventHandler::setFireKey_m(sf::Mouse::Button but){ fireBut_m = but; }

	
	void EventHandler::setJumpKey_j(int but){ jumpBut_j = but; }
	
	void EventHandler::setJumpKey_k(sf::Keyboard::Key key){ jumpKey_k = key; }
	
	void EventHandler::setJumpKey_m(sf::Mouse::Button but){ fireBut_m = but; }

	
	void EventHandler::setActionKey_j(int but, int id){ actionBut_j[id] = but; }
	
	void EventHandler::setActionKey_k(sf::Keyboard::Key key, int id){ actionKey_k[id] = key; }
	
	void EventHandler::setActionKey_m(sf::Mouse::Button but, int id){ actionBut_m[id] = but; }
	
	