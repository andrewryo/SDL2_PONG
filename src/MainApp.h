/*********************************************************************************
**  Copyright 2013 Eric Basile 												  	**
**  																			**
**  This file is part of SDL2_Pong.                                    			**
**  																			**
**  SDL2_Pong is free software: you can redistribute it and/or modify			**
**  it under the terms of the GNU General Public License as published by		**
**  the Free Software Foundation, either version 3 of the License, or		  	**
**  (at your option) any later version.										  	**
**  																			**
**  SDL2_Pong is distributed in the hope that it will be useful,			    **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of			  	**
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			  	**
**  GNU General Public License for more details.								**
**  																			**
**  You should have received a copy of the GNU General Public License		  	**
**  along with SDL2_Pong.  If not, see <http://www.gnu.org/licenses/>.			**
**  																			**
**********************************************************************************/
//Main application and game loop singleton

#ifndef _MAINAPP_H_
#define _MAINAPP_H_





#include <SDL2/SDL.h>

#ifdef APPLE
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_ttf.h>
#endif
#include "Define.h"
#include "BaseClasses/Events.h"
#include "Renderer/MainRender.h"
#include "BaseClasses/Level.h"
#include "PongLevel.h"





class MainApp : public Events
{
    /* Singleton stuff */
    public:
        static MainApp* Instance();



    private:
        MainApp();
        MainApp(MainApp const&){};
        MainApp& operator = (MainApp const&){};
        static MainApp* m_pInstance;
		~MainApp();


    /*************************/

    public:

        int OnExecute();

    public:

        bool OnInit();

        void OnEvent(SDL_Event* Event);

        void OnKeyDown(SDL_Keycode sym,  SDL_Keymod mod, Uint16 unicode);

        void OnKeyUp(SDL_Keycode sym, SDL_Keymod mod, Uint16 unicode);

        void OnExit();

        void OnLoop();

		void LoadGame();



        void OnRender();

        void OnCleanup();

		MainRender* GetMainRenderTarget();


    private:
        bool            Running;


		//BounceSquare		Test;

        Level*          CurrentLevel;
		SDL_Window*		MainWindow;
		MainRender		MainRenderTarget;






};



#endif
