#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
#include<string>

#include"struct.cpp"
#include"functions_control_console.h"
#include"variable.h"

using std::cout;

int* g_printSpeed = new int(20);
int* g_speed = new int(150); //toc do lam moi

char* c = new char(' ');
int* g_count_down = new int(0);
int* g_choice = new int(0);
int* g_PlayerSize = new int(0);
int* g_step = new int(1);

int* g_score = new int(0);
int* g_destroyed = new int(0);
int* g_process = new int(0);
int* g_contact = new int(0);

struct infoPlayer;

Position cursorPos = { 0,0,0,0 };
Position PlayerPos = { 0,0,0,0 };
Position EnemyPos = { 0,0,0,0 };
Position bulletPos = { 0,0,0,0 };

Activities activities = Activities::stop;

Player* PlayerWeak = new Player(5, 100, "|-[O]-|", ".");
Enemy* EnemyWeak = new Enemy(70, 1, 1, "|-x-|");

#pragma region functions
std::vector<infoPlayer>inputDataAccount();

void loadingScreen();
void loadingPlot();
void stringFlicker(string str, int posX, int posY, int colorCode_1, int colorCode_2);
void printTitle(int posX, int posY, int colorCode);
int welcomeScreen(int printSpeed, string name);
int login_register(vector<infoPlayer>dataUsers);

void saveDataUsers(vector<infoPlayer>Data);
void drawListPlayers();
void drawLog_ResScreen(string title);

void story_chapter_1(int printSpeed);
void stage_chapter_1(int speed, int& res);

void story_chapter_2(int printSpeed);
void stage_chapter_2(int speed, int& g_process, int& g_contact);

void stage_chapter_game(int& speed, int& g_score, int& g_destroyed);

void info_about_game(int printSpeed);
void about_me(int printSpeed);
void endGame(int g_score, int g_destroyed, int printSpeed);

int main();
#pragma endregion

/*
	- speed: toc do di chuyen hay toc do lam moi khung hinh
	- voi di chuyen len xuong thi toc do nhanh hon rat nhieu
	- Tuy nhien, lai kha cham neu di chyen theo chieu ngang
	- Test toc do moi:
		+ Neu di chuyen len, xuong thi tang (giam) 1 don vi truc Y
		+ Nguoc lai, tang (giam) 2 don vi truc X
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	SetConsoleTitle(L"Spaceship Defender");

	showCursor(false);
	showScrollbar(false);
	disableResizeWindow();
	setWindowSize(209, 55);
	setScreenBufferSize(209, 55);

	loadingScreen();
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

		if (res == 1) //data need export: serial, name, g_scoreChapter1, g_process/g_contact, g_scoreChapter2,g_scoreChapterGame
		{
			system("cls");
			cout << "Ban co muon di theo cot truyen khong (Y/N): ";
			char c;
			cin >> c;
			c = tolower(c);
			if (c == 'y')
			{
				loadingPlot();
				story_chapter_1(*g_printSpeed);
				stage_chapter_1(*g_speed, Player.g_scoreChapter1);//export g_scoreChapter1

				system("cls");
				cout << "Waiting for next chapter...";
				Sleep(1500);

				loadingPlot();
				story_chapter_2(*g_printSpeed);
				loadingScreen();
				stage_chapter_2(*g_speed, *g_process, *g_contact);
				Player.g_process = *g_process;
				Player.g_contact = *g_contact;
				cin.ignore();//chay duoc stage_chapter_game

				cout << "[ Dang khoi dong man choi chinh ]";
				Sleep(2000);

				loadingPlot();
				system("cls");

				stage_chapter_game(*g_speed, *g_score, *g_destroyed);
				Player.g_scoreChapterGame = *g_score;

				endGame(*g_score, *g_destroyed, *g_printSpeed);
			}
			else {
				loadingScreen();
				stage_chapter_game(*g_speed, *g_score, *g_destroyed);
				Player.g_scoreChapterGame = *g_score;

				endGame(*g_score, *g_destroyed, *g_printSpeed);
				main();
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
				atXY(85, 5);

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
			about_me(*g_printSpeed);
		}
		saveDataUsers(data);
	}
	return 0;
}


