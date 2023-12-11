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
std::vector<infoPlayer>inputDataAccount(string& st_login);

void loadingScreen();
void loadingPlot();
void stringFlicker(string str, int posX, int posY, int colorCode_1, int colorCode_2);
void printTitle(int posX, int posY, int colorCode);

int welcomeScreen(int printSpeed, string name);

infoPlayer login_register(vector<infoPlayer>dataUsers);

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
	infoPlayer user;
	string nameUser = "";
	string st_login = "";

	//add data saved (if it exists)
	vector<infoPlayer>data = inputDataAccount(st_login);

	if (st_login == "current")
	{
		auto index = find_if(data.begin(), data.end(), [&](const infoPlayer& a) {
			return a.hadLogin == true;
			});

		if (index != data.end())
		{
			user = *index;
		}
		nameUser = user.name;
	};

	while (true)
	{
		int res = 0;
		res = welcomeScreen(*g_printSpeed, nameUser);

		//data need export: serial, name, g_scoreChapter1, g_process/g_contact, g_scoreChapter2,g_scoreChapterGame
		if (res == 1)
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
				stage_chapter_1(*g_speed, user.g_scoreChapter1);//export g_scoreChapter1

				system("cls");
				cout << "Waiting for next chapter...";
				Sleep(1500);

				loadingPlot();
				story_chapter_2(*g_printSpeed);
				loadingScreen();
				stage_chapter_2(*g_speed, *g_process, *g_contact);
				user.g_process = *g_process;
				user.g_contact = *g_contact;
				cin.ignore();

				cout << "[ Dang khoi dong man choi chinh ]";
				Sleep(2000);

				loadingPlot();
				system("cls");

				stage_chapter_game(*g_speed, *g_score, *g_destroyed);
				user.g_scoreChapterGame = *g_score;

				endGame(*g_score, *g_destroyed, *g_printSpeed);
			}
			else {
				loadingScreen();
				stage_chapter_game(*g_speed, *g_score, *g_destroyed);
				user.g_scoreChapterGame = *g_score;

				endGame(*g_score, *g_destroyed, *g_printSpeed);
				main();
			}
			if (data.size() > 0 && nameUser != "")
			{
				auto index = find_if(data.begin(), data.end(), [&](const infoPlayer& a) {
					return a.hadLogin == true;
					});
				if (index != data.end())
				{
					*index = user;
				}
				saveDataUsers(data);
			};
		}
		else if (res == 2) {
			user = login_register(data);
			if (user.name == "_")
			{
				drawLog_ResScreen("REGISTER");
				atXY(85, 5);

				cout << "Please tell me your name:";
				cin >> nameUser;

				user.name = nameUser;
				user.serial = data.size() + 1;
				data.push_back(user);

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


