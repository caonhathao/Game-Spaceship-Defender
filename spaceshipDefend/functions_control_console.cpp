#include"functions_control_console.h"
void setWindowSize(SHORT width, SHORT height) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT WindowSize{};
	WindowSize.Top = 0;
	WindowSize.Left = 0;
	WindowSize.Right = width;
	WindowSize.Bottom = height;
	SetConsoleWindowInfo(hStdout, true, &WindowSize);
}
void setScreenBufferSize(SHORT width, SHORT height) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD newSize{};
	newSize.X = width + 1;
	newSize.Y = height + 1; 
	SetConsoleScreenBufferSize(hStdout, newSize);
}
void moveWindow(SHORT x, SHORT y, SHORT width, SHORT height)
{
	HWND console = GetConsoleWindow();
	MoveWindow(console, x, y, width, height, false);

}
void disableResizeWindow() {
	HWND console = GetConsoleWindow();
	LONG style = GetWindowLong(console, GWL_STYLE);
	style &= ~(WS_THICKFRAME | WS_MAXIMIZEBOX);
	SetWindowLong(console, GWL_STYLE, style);
}
void atXY(SHORT posX, SHORT posY) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position{};
	Position.X = posX;
	Position.Y = posY;
	SetConsoleCursorPosition(hStdout, Position);
}
void showCursor(bool cursorVisibility) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO	 ConCurInf{};
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = cursorVisibility;
	SetConsoleCursorInfo(handle, &ConCurInf);
}
void showScrollbar(BOOL Show) {
	HWND hWnd = GetConsoleWindow();
	ShowScrollBar(hWnd, SB_BOTH, Show);
}
void setColor(int background_color, int text_color) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = background_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}
void disableSelection() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
int random(int minN, int maxN) {
	return minN + rand() % (maxN + 1 - minN);
}