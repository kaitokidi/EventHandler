#include "EventHandler.h"

    void EventHandler::mouseInit(){
        m_dir = no_dir;
        m_edir = no_edir;

        movementMargin = 0.0;

        fireBut_m = sf::Mouse::Left;
        jumpBut_m = sf::Mouse::Middle;
        movementButton_m = sf::Mouse::Right;

        qtty = (int) sf::Mouse::ButtonCount;
        actionActivated_m = std::vector<bool>(qtty, false);
        actionBut_m = std::vector<sf::Mouse::Button> (qtty, sf::Mouse::ButtonCount);
    }

    void EventHandler::keyboardInit(){
        k_dir = no_dir;
        k_edir = no_edir;

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

    void EventHandler::joystickInit(){ }

	EventHandler::EventHandler(){

        mouseInit();
        keyboardInit();
        joystickInit(); //not implemented yet
        keysEnabled = false;
        mouseEnabled = false;
        joystickEnabled = false;

	}

	void EventHandler::handleEvents(sf::RenderWindow& w){
		sf::Event event;
		while(w.pollEvent(event)){
			handleEvent(event);
			switch(event.type){		
				case sf::Event::Closed:
					w.close();
					break;
			}
		}	
	}

	void EventHandler::handleEvent(sf::Event event){ 
		switch (event.type){
				//KeyPressed event
                case  sf::Event::KeyPressed:
                    if(keysEnabled){
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

                    }
					break;
				
                case sf::Event::MouseButtonPressed:
                    if(mouseEnabled){
                        /*if (event.mouseButton.button == sf::Mouse::Left) {}
                        if (event.mouseButton.button == sf::Mouse::Right) {}
                        if (event.mouseButton.button == sf::Mouse::Middle) {}
                        if (event.mouseButton.button == sf::Mouse::XButton1) {}
                        if (event.mouseButton.button == sf::Mouse::XButton2) {}
                        */
                        if (event.mouseButton.button == movementButton_m) {
                            float delay = movementMargin/2;

                            if(event.mouseButton.x < movementReference.x - delay){
                                if(event.mouseButton.y < movementReference.y - delay){
                                    m_edir = NW; m_dir = no_dir;
                                }
                                if(event.mouseButton.y > movementReference.y + delay){
                                    m_edir = SW; m_dir = no_dir;
                                }
                                else {
                                    m_edir = W;  m_dir = Left;
                                }
                            }
                            else if(event.mouseButton.x > movementReference.x + delay){
                                if(event.mouseButton.y < movementReference.y - delay){
                                    m_edir = NE;  m_dir = no_dir;
                                }
                                if(event.mouseButton.y > movementReference.y + delay){
                                    m_edir = SE;  m_dir = no_dir;
                                }
                                else {
                                    m_edir = E;   m_dir = Right;
                                }
                            }
                            else {
                                if(event.mouseButton.y < movementReference.y - delay){
                                    m_edir = N;  m_dir = up;
                                }
                                if(event.mouseButton.y > movementReference.y + delay){
                                    m_edir = S;  m_dir = down;
                                }
                                else {
                                    m_edir = no_edir; m_dir = no_dir;
                                }
                            }
                        }

                        if (event.mouseButton.button == fireBut_m) {
                            fireActivated = true;
                        }

                        if (event.mouseButton.button == jumpBut_m) {
                            jumpActivated = true;
                        }

                        for(int i = 0; i < actionBut_m.size(); ++i){
                            if (event.mouseButton.button == actionBut_m[i]) {
                                actionActivated_m[i] = true;
                            }
                        }
                    }
                    break;

				
				//Default
				default:
					//Do nothing
					break;
			}
	}

    void EventHandler::setMovementMargin(float n){ movementMargin = n; }
	
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
	
    void EventHandler::setMovementReference(sf::Vector2f p){
        movementReference = p;
    }

    void EventHandler::setMovementReference(float x, float y){
        setMovementReference(sf::Vector2f(x,y));
    }
