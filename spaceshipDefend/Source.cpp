#include<iostream>
#include<conio.h>
#include<vector>

#include"struct.cpp"
#include"functions_control_console.h"
#include"variable.h"

using namespace std;

int g_printSpeed = 20;
char c = ' ';
int task_point = 0;
int g_count_down = 0;
int* choice = new int(0);


struct result;
struct infoPlayer;
Position cursorPos = { 0,0,0,0 };

vector<infoPlayer>data;

#pragma region functions
std::vector<infoPlayer>inputDataAccount();

void loadingScreen();
void loadingPlot();

int welcomeScreen(int printSpeed, string name);
int loginScreen(vector<infoPlayer>dataUsers);
void drawListPlayers(vector<infoPlayer>Data);

void story_chapter_1(int printSpeed);
void stage_chapter_1(int speed);

void story_chapter_2(int printSpeed);
void stage_chapter_2(int speed);

result stage_chapter_game();

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

	data = inputDataAccount();

	while (true)
	{
		system("cls");
		if (posUser!=-1)
		{
			nameUser = data[posUser].name;
		}
		int res = 0;

		res = welcomeScreen(g_printSpeed, nameUser);

		if (res == 1) //data need export: serial, name, scoreChapter1, process/contact, scoreChapter2,scoreChapterGame
		{
			system("cls");
			cout << "Ban co muon di theo cot truyen khong (Y/N): ";
			char c;
			cin >> c;
			c = tolower(c);
			if (c == 'y')
			{
				loadingPlot();
				story_chapter_1(g_printSpeed);
				stage_chapter_1(200);//export scoreChapter1
				loadingPlot();
				story_chapter_2(g_printSpeed);
				loadingScreen();
				stage_chapter_2(200);
				result A = stage_chapter_game();
				endGame(A.score, A.destroyed, g_printSpeed);
			}
			else {
				result A = stage_chapter_game();
				endGame(A.score, A.destroyed, g_printSpeed);
				//main();
			}
		}
		else if (res == 2) {
			posUser = loginScreen(data);
		}
		else if (res == 3) {
			drawListPlayers();
		}
		else if (res == 4) {

			info_about_game(g_printSpeed);
		}
		else if (res == 5)
		{
			about_me(g_printSpeed);//error: second loop will make the program died
		}
	}
	return 0;
}