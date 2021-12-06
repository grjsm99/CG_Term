#pragma once
#include <vector>

#include "global_var.h"

#include "state.h"
#include "model_3d.h"
#include "model_maker.h"
#include "glManager.h"
#include "light.h"
#include "plain.h"
#include "ant_nest.h"
#include "tower.h"
#include "attack.h"
#include "cake.h"

class mainState : public State {
	//필수 함수들
	static GLvoid Reshape(int w, int h);
	static GLvoid drawScene();
	static GLvoid sKeyboard(int key, int x, int y);
	static GLvoid Keyboard(unsigned char key, int x, int y);
	static GLvoid Mouse(int button, int state, int x, int y);
	static GLvoid Motion(int x, int y);
	static GLvoid Update(int value);

	//변수
	static Camera camera;
	static Light sun;
	static Plain plain;
	static AntNest antNest;
	static std::vector<cake*> cakeList;
	


public:
	//public 변수
	static int gold;

	static std::vector<Ant*> ants;
	static std::vector<Tower*> towers;
	static std::vector<Attack*> attacks;

	static glm::vec3 attLights[200];
	//생성자
	mainState() {
		SetCallbackFunc();
		glm::vec4 dir = glm::vec4(0, 0, 1, 1);
		glm::mat4 rot(1.0f);

		rot = glm::rotate(rot, 45.0f / 180.0f * 3.14f, glm::vec3(0, 1, 0));
		for (int i = 0; i < 8; i++) {
			cake* c = new cake();
			c->GetTransfromPtr()->SetDir(glm::vec3(dir.x, dir.y, dir.z));
			dir = rot * dir;
			cakeList.push_back(c);
		}

		Tower* t = new Tower(5, 5);
		towers.push_back(t);
		t = new Tower(5, 6);
		towers.push_back(t);
		t = new Tower(5, 7);
		t->Upgrade(1);
		towers.push_back(t);
		/*for (int i = 0; i < 10; i++) {
			for (int j = 2; j < 10; j++) {
				Tower* t = new Tower(j, i);
				towers.push_back(t);
			}
		}
		*/
	};

	//자신의 함수 연결하기
	void SetCallbackFunc();

};
