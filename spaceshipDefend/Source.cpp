#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
#include<string>

#include"struct.cpp"
#include"functions_control_console.h"
#include"variable.h"

using namespace std;

int *g_printSpeed = new int(20);
char *c = new char(' ');
int* g_count_down = new int(0);
int* g_choice = new int(0);
int* g_playerSize = new int(0);

int* score = new int(0);
int* destroyed = new int(0);
int* process = new int(0);
int* contact = new int(0);

struct infoPlayer;

Position cursorPos = { 0,0,0,0 };
Position playerPos = { 0,0,0,0 };
Position enemyPos = { 0,0,0,0 };
Position bulletPos = { 0,0,0,0 };

Activities activities = Activities::stop;

PLAYER playerWeak(5, 100, "|-[O]-|", ".");
ENEMY enemyWeak(70, 1, 1, "|-x-|");

#pragma region functions
std::vector<infoPlayer>inputDataAccount();

void loadingScreen();
void loadingPlot();

int welcomeScreen(int printSpeed, string name);
int login_register(vector<infoPlayer>dataUsers);

void saveDataUsers(vector<infoPlayer>Data);
void drawListPlayers();
void drawLog_ResScreen(string title);

void story_chapter_1(int printSpeed);
int stage_chapter_1(int speed);

void story_chapter_2(int printSpeed);
void stage_chapter_2(int speed, int& process, int& contact);

void stage_chapter_game(int &score, int &destroyed);

void info_about_game(int printSpeed);
void about_me(int printSpeed);
void endGame(int score, int destroyed, int printSpeed);

int main();
#pragma endregion

int main() {
	SetConsoleTitle(L"Spaceship Defender");

	showCursor(false);
	setWindowSize(209, 55);

	setScreenBufferSize(209, 55);
	//loadingScreen();
	int posUser = -1;
	string nameUser = "";

	infoPlayer Player;

	vector<infoPlayer>data;
	data = inputDataAccount();

	while (true)
	{
		system("cls");
		if (posUser >= 0) //login
		{
			nameUser = data[posUser].name;
			Player = data[posUser];
		}
		else if (posUser == -2) // new register
		{
			posUser = data.size() - 1;
			nameUser = data[posUser].name;
		}

		int res = 0;
		res = welcomeScreen(*g_printSpeed, nameUser);

		if (res == 1) //data need export: serial, name, scoreChapter1, process/contact, scoreChapter2,scoreChapterGame
		{
			system("cls");
			cout << "Ban co muon di theo cot truyen khong (Y/N): ";
			char c;
			cin >> c;
			c = tolower(c);
			if (c == 'y')
			{
				result A;
				loadingPlot();
				story_chapter_1(*g_printSpeed);
				Player.scoreChapter1 = stage_chapter_1(200);//export scoreChapter1

				loadingPlot();
				story_chapter_2(*g_printSpeed);
				loadingScreen();
				stage_chapter_2(*g_printSpeed, *process, *contact);
				Player.process = *process;
				Player.contact = *contact;

				cout << "[ Dang khoi dong man choi chinh ]";
				Sleep(2000);

				loadingPlot();
				system("cls");

				stage_chapter_game(*score, *destroyed);
				Player.scoreChapterGame = *score;

				endGame(*score, *destroyed, *g_printSpeed);
			}
			else {
				loadingPlot();
				stage_chapter_game(*score,*destroyed);
				Player.scoreChapterGame = *score;

				endGame(*score, *destroyed, *g_printSpeed);
				//main();
			}
			if (data.size() > 0 && posUser != -1)
			{
				data[posUser] = Player;
			};
		}
		else if (res == 2) {
			posUser = login_register(data);
			if (posUser == -2)
			{
				drawLog_ResScreen("REGISTER");
				gotoXY(85, 5);

				cout << "Please tell me your name:";
				cin >> nameUser;

				Player = { 0,"",0,0,0,0 };
				Player.name = nameUser;
				Player.serial = data.size() + 1;
				data.push_back(Player);

				saveDataUsers(data);
			};
		}
		else if (res == 3) {
			drawListPlayers();
		}
		else if (res == 4) {

			info_about_game(*g_printSpeed);
		}
		else if (res == 5)
		{
			about_me(*g_printSpeed);//error: second loop will make the program died
		}
		saveDataUsers(data);
	}
	return 0;
}
