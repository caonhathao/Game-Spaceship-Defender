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

//the variable below will add some units for posY (scale this frame)
int* addPosY = new int(0);

Position cursorPos = { 0,0,0,0 };
Position PlayerPos = { 0,0,0,0 };
Position EnemyPos = { 0,0,0,0 };
Position bulletPos = { 0,0,0,0 };

Activities activities = Activities::stop;

Player* PlayerWeak = new Player(5, 100, "|-[O]-|", ".");
Enemy* EnemyWeak = new Enemy(70, 1, 1, "|-x-|");

#pragma region functions
std::vector<infoPlayer>inputDataAccount(string& st_login);

infoPlayer login_register(vector<infoPlayer>dataUsers);

void loadingScreen();
void loadingPlot();

int welcomeScreen(int printSpeed, string name);

void saveDataUsers(vector<infoPlayer>Data);
void drawListPlayers(vector<infoPlayer>&data);

bool isSkipPlotGame();

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
	- speed variable: Speed of movement and speed of renew fame
	- We have a problem with this speed:
		+ If the object move vertically, we feel normally.
		+ But, if the object move horizontally, we fell slowly.
		+ Because, with commandline console, the vertical and horizontal are different per cell
	- Offering some solutions to fix this feeling:
		+ Change speed of movement when move horizontal, from +1 to +2
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	SetConsoleTitle(L"Spaceship Defender");

	showCursor(false);
	showScrollbar(false);
	moveWindow(0, 0, 200, 50);
	setWindowSize(200, 50);
	setScreenBufferSize(200, 50);
	disableResizeWindow();

	//loadingScreen();
	infoPlayer user;
	string st_login = "";

/*
	- When the first time program is opened:
		+ We have two method:
			> One, if user plays game without login: don't save.
			> Two, if the user registers a new account and plays game, be sure this account will auto-login for the next start.
	- When the user opens the program more than once time:
		+ We have two method:
			> Follow 'Two' from above.
			> If the user sign out and login another, save all data of accounts
	- The problem is here: How can i mark the account that signed in?
*/

	//scan all data, and found the account which signed in
	vector<infoPlayer>data = inputDataAccount(st_login);

	if (st_login == "current")
	{
		auto index = find_if(data.begin(), data.end(), [&]( const infoPlayer& a) {
			return a.hadLogin == true;
			});

		if (index != data.end())
		{
			user = *index; 
		}
	};

	while (true)
	{
		system("cls");
		int res = 0;
		res = welcomeScreen(*g_printSpeed, user.name);
		
		//data need export: serial, name, g_scoreChapter1, g_process/g_contact, g_scoreChapter2,g_scoreChapterGame
		if (res == 1)
		{
			system("cls");
			if (isSkipPlotGame())
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
			}
			if (data.size() > 0)
			{
				auto index = find_if(data.begin(), data.end(), [&](const infoPlayer& a) {
					return a.hadLogin == true;
					});
				if (index != data.end())
				{
					*index = user;
					saveDataUsers(data);
				}
			};
		}
		else if (res == 2) {
			user = login_register(data);
			//if (user.name == "")
			//{
			//	//drawLog_ResScreen("REGISTER");

			//	atXY(85, 5);
			//	cout<<"[FIRST CHARACTER IS A NUMBER OR ALPHA]";
			//	atXY(85, 6);
			//	cout << "Please tell me your name: ";
			//	cin >> user.name;
			//	cin.ignore();
			//	user.serial = data.size() + 1;
			//	user.hadLogin = true;
			//	data.push_back(user);

			//	saveDataUsers(data);
			//};
		}
		else if (res == 3) {
			drawListPlayers(data);
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


