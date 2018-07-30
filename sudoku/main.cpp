#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<ctime>
#include<vector>
using namespace std;

int const REGION[9][9] = {
	{ 0, 0, 1, 1, 1, 1, 1, 2, 2 },
	{ 0, 0, 0, 1, 1, 1, 2, 2, 2 },
	{ 3, 0, 0, 0, 1, 2, 2, 2, 5 },
	{ 3, 3, 0, 4, 4, 4, 2, 5, 5 },
	{ 3, 3, 3, 4, 4, 4, 5, 5, 5 },
	{ 3, 3, 6, 4, 4, 4, 8, 5, 5 },
	{ 3, 6, 6, 6, 7, 8, 8, 8, 5 },
	{ 6, 6, 6, 7, 7, 7, 8, 8, 8 },
	{ 6, 6, 7, 7, 7, 7, 7, 8, 8 }
};
sf::Text number, inputan;

bool masihAdaKosong(int map[9][9], int &baris, int &kolom, bool keluar){
	if(keluar)
		return false;

	for (int i = 0; i<9; i++){
		for (int j = 0; j<9; j++){
			if (map[i][j] == 0){
				baris = i;
				kolom = j;
				return true;
			}
		}
	}
	return false;
}
bool barisAman(int map[9][9], int baris, int angka){
	for (int j = 0; j<9; j++){
		if (map[baris][j] == angka){
			return false;
		}
	}
	return true;
}
bool barisAman(int map[9][9], int baris){
	for (int i = 0; i<9; i++){
		for (int j=0; j<9; j++){
			if (i != j)
			{
				if (map[baris][i] == map[baris][j]){
					return false;
				}
			}
		}
	}
	return true;
}
bool kolomAman(int map[9][9], int kolom, int angka){
	for (int i = 0; i<9; i++){
		if (map[i][kolom] == angka){
			return false;
		}
	}
	return true;
}
bool kolomAman(int map[9][9], int kolom){
	for (int i = 0; i<9; i++){
		for(int j=0; j<9; j++){
			if (i != j)
			{
				if (map[i][kolom] == map[j][kolom]){
					return false;
				}
			}
			cout<<endl;
		}
	}
	return true;
}
bool sectionAman(int map[9][9], int baris, int kolom, int angka){
	int reg = REGION[baris][kolom];

	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			if (REGION[i][j] == reg)
			{
				if (map[i][j] == angka)
					return false;
			}
		}
	}
	return true;

}
bool sectionAman(int map[9][9], int baris, int kolom){
	int reg = REGION[baris][kolom];

	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			if (REGION[i][j] == reg)
			{
				for (int x=0; x<9; x++){
					for (int y=0; y<9; y++){
						if (REGION[x][y] == reg)
						{
							if(i!=x && j!=y){
								if (map[i][j] == map[x][y])
									return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}
void printMap(int map[9][9]){
	for (int i=0;i<9;i++){
		for(int j=0; j<9;j++){
			printf("%d ", map[i][j]);
		}
		cout<<endl;
	}
}
bool isSafe(int map[9][9], int baris, int kolom){
	//printMap(map);
	bool a, b, c;
	a = sectionAman(map, baris, kolom);
	b = barisAman(map, baris);
	c = kolomAman(map, kolom);
	if (a && b && c){
		return true;
	}
	else{
		return false;
	}
}
bool isSafe(int map[9][9], int baris, int kolom, int i){
	//printMap(map);
	bool a, b, c;
	a = sectionAman(map, baris, kolom, i);
	b = barisAman(map, baris, i);
	c = kolomAman(map, kolom, i);
	if (a && b && c){
		return true;
	}
	else{
		return false;
	}
}

void printMap(sf::RenderWindow &window, int map[9][9]){
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++){
			//printf("|%2d", map[row][col]);
			/*if (row == 0 && col == 0){
				number.setPosition(33, 33);
			}*/
			//else{
			number.setPosition((row * 40) + 5, (col * 40) + 5);
			//}
			if (map[col][row] != 0){
				number.setString(to_string(static_cast<long long>(map[col][row])));
				window.draw(number);
			}
		}
		// printf("\n------------------------------------------------------\n");
	}
}
void insertMapPlay(int angka, int mapPlay[9][9], int x, int y){
	mapPlay[y][x] = angka;
}

void printMapPlay(int mapPlay[9][9], sf::RenderWindow &window){
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++){
			inputan.setPosition(col*40 + 5, row*40 + 5);
			if (mapPlay[row][col] != 0){
				inputan.setString(to_string(static_cast<long long>(mapPlay[row][col])));
				window.draw(inputan);
			}
		}
	}
}
void printNumber(int angka, sf::RenderWindow &window, int x, int y, int mapPlay[9][9]){
	insertMapPlay(angka, mapPlay, x, y);
}
bool cekInput(int map[9][9]){
	cout<<"SOLVING"<<endl;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(isSafe(map, i,j)==false){
				cout<<"GAGAL";
				return false;
			}else
			{
				cout<<"berhasil";
			}
			cout<<endl;
		}
	}
	return true;
}
bool solve(int map[9][9]){
	int baris, kolom;

	if (masihAdaKosong(map, baris, kolom, false) == false){
		return true;
	}
	for (int i = 1; i<10; i++){
		if (isSafe(map, baris, kolom, i) == true){
			map[baris][kolom] = i;

			if (solve(map) == true)
				return true;

			map[baris][kolom] = 0;
		}
	}
	return false;
}

bool solve(sf::RenderWindow &window, int map[9][9], sf::Sprite boardSprite){
	int baris, kolom;

	sf::Event event;
	bool keluar = false;
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == event.KeyPressed){
			keluar = true;
		}
	}

	window.clear();
	window.draw(boardSprite);
	printMap(window, map);
	window.display();

	if (masihAdaKosong(map, baris, kolom, keluar) == false)
		return true;

	for (int i = 1; i<10; i++){
		if (isSafe(map, baris, kolom, i) == true){
			map[baris][kolom] = i;

			if (solve(window, map, boardSprite) == true)
				return true;

			map[baris][kolom] = 0;
		}
	}
	return false;
}

class CBackground{
private:
	sf::Texture bgTexture;
	sf::Sprite bg;
	string id;
public:
	CBackground(){
		id = "none";
		bgTexture.loadFromFile("Assets/bg_menu.jpg");
		bg.setTexture(bgTexture);
		bg.setPosition(sf::Vector2f(0,0));
	}
	void setBackground(string _id){
		id = _id;
		if (id == "menu")
			bgTexture.loadFromFile("Assets/bg_menu.jpg");
		else if (id == "game")
			bgTexture.loadFromFile("Assets/bg_game.png");
	}
	sf::Sprite getSprite(){
		return bg;
	}
};
bool cekPointerPlayer(float x, float y){
	if((x>=0 && y>=0 )&&( x<=320 && y<=320)){
		cout<<"\n--true--\n"<<x<<" "<<y<<endl;
		return true;
	}
	else{
		cout<<"\n--false--\n"<<x<<" "<<y<<endl;
		return false;
	}
}
void main(){
	int map[9][9] = 
	{ { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	sf::Sprite boardSprite;
	sf::Texture boardTexture;
	boardTexture.loadFromFile("MAPSUDOKU.png");
	boardSprite.setTexture(boardTexture);
	boardSprite.setScale(0.5, 0.5);
	sf::Font arialFont;
	arialFont.loadFromFile("arial.ttf");

	number.setColor(sf::Color::Blue);
	number.setFont(arialFont);
	number.setCharacterSize(12);	
	inputan.setColor(sf::Color::Magenta);
	inputan.setFont(arialFont);
	inputan.setCharacterSize(12);

	int code_game = 0;
	int timeSolving = 0;
	//1 = play game, 2 = random solve, 3 = special solve
	sf::RenderWindow window;
	sf::Event event;
	window.create(sf::VideoMode(1000,700), "SUDOKU");
	CBackground bg;
home:
	while(window.isOpen()){
		window.setMouseCursorVisible(true);
		bg.setBackground("menu");
		//menu - init
		sf::Texture btnTexture[5];
		sf::Sprite btn[5];
		btnTexture[0].loadFromFile("Assets/title.png");
		btnTexture[1].loadFromFile("Assets/bt_play.png");
		btnTexture[2].loadFromFile("Assets/bt_random.png");
		btnTexture[3].loadFromFile("Assets/bt_special.png");
		btnTexture[4].loadFromFile("Assets/bt_exit.png");
		for (int a = 1; a < 5; a++){
			btn[a].setTexture(btnTexture[a]);
			btn[a].scale(0.41, 0.335);
			btn[a].setPosition(sf::Vector2f(227, 100*(a + 2) - 25));
		}
		btn[0].setTexture(btnTexture[0]);
		btn[0].setPosition(sf::Vector2f(190, 111));
		//menu - play
		while(window.pollEvent(event)){
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
				if(btn[1].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
					code_game = 1;
					goto play;
				}
				if(btn[2].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
					code_game = 2;
					goto play;
				}
				if(btn[3].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
					code_game = 3;
					goto play;
				}
				else if (btn[4].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
					window.close();
				}
			}
		}
		window.clear();
		window.draw(bg.getSprite());
		for (int a = 0; a < 5; a++)
			window.draw(btn[a]);
		window.display();
	}
play:
		sf::RectangleShape pointerPlayer;
		pointerPlayer.setFillColor(sf::Color(0,144,144,50));
		pointerPlayer.setSize(sf::Vector2f(40,40));
		pointerPlayer.setPosition(0,0);


		sf::Text solve1, solve2, textclear, time;
		solve1.setColor(sf::Color::White);
		solve1.setFont(arialFont);
		solve1.setCharacterSize(24);
		solve1.setString("Solve (Animated)");	
		solve1.setPosition(sf::Vector2f(455, 80));

		solve2.setColor(sf::Color::White);
		solve2.setFont(arialFont);
		solve2.setCharacterSize(24);
		solve2.setString("Solve");	
		solve2.setPosition(sf::Vector2f(455, 180));

		textclear.setColor(sf::Color::White);
		textclear.setFont(arialFont);
		textclear.setCharacterSize(24);
		textclear.setString("Clear");	
		textclear.setPosition(sf::Vector2f(455, 280));

		time.setColor(sf::Color::White);
		time.setFont(arialFont);
		time.setCharacterSize(24);
		time.setString("Time Elapsed " + to_string(static_cast<long long>(timeSolving)) + " ms");	
		time.setPosition(sf::Vector2f(455, 480));

		int posX, posY, nilai;

		while(window.isOpen()){
			window.setMouseCursorVisible(true);
			//game - init
			sf::Texture btnTexture, btnTex1, btnTex2, btnTex3;
			sf::Sprite btn, btnSolve1, btnSolve2, btnClear;

			btnTex1.loadFromFile("Assets/start-1.png");
			btnSolve1.setTexture(btnTex1);
			btnSolve1.scale(0.41, 0.335);
			btnSolve1.setPosition(sf::Vector2f(427, 50));

			btnTexture.loadFromFile("Assets/bt_back.png");
			btn.setTexture(btnTexture);
			btn.scale(0.41, 0.335);
			btn.setPosition(sf::Vector2f(727, 100));

			btnTex2.loadFromFile("Assets/start-1.png");
			btnSolve2.setTexture(btnTex2);
			btnSolve2.setScale(0.41, 0.335);
			btnSolve2.setPosition(sf::Vector2f(427, 150));

			btnTex3.loadFromFile("Assets/start-1.png");
			btnClear.setTexture(btnTex3);
			btnClear.setScale(0.41, 0.335);
			btnClear.setPosition(sf::Vector2f(427, 250));

			if (code_game == 1){
				while(window.pollEvent(event)){
					if (event.type == sf::Event::Closed)
						window.close();
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						if (btn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							for (int i=0;i<9;i++){
								for (int j=0;j<9;j++){
									map[i][j] = 0;
								}
							}
							time.setString("Time Elapsed " + to_string(static_cast<long long>(0)) + " ms");
							timeSolving = 0;
							goto home;
						}
						if (btnSolve1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							if(!solve(window, map, boardSprite)){
								cout<<"GAGAL";
							}
						}
						if (btnSolve2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							cout<<"SOLVING...\n";
							int Start, Stop;
							Start = clock();
							if(solve(map)){
								cout<<"BERHASIL";
								Stop = clock();	
							}else{
								cout<<"GAGAL";
							}
							cout<<"SOLVED\n";
							timeSolving = (Stop-Start)/double(CLOCKS_PER_SEC)*1000;
							time.setString("Time Elapsed " + to_string(static_cast<long long>(timeSolving)) + " ms");
							cout<<"TIME ELAPSED: "<<timeSolving<<endl;
						}
						if (btnClear.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							for (int i=0;i<9;i++){
								for (int j=0;j<9;j++){
									map[i][j] = 0;
								}
							}
							time.setString("Time Elapsed " + to_string(static_cast<long long>(0)) + " ms");
							timeSolving = 0;
						}
					}
					if (event.type == sf::Event::KeyPressed){
						if (event.key.code == sf::Keyboard::Right){
							sf::Vector2f pos = pointerPlayer.getPosition();
							if(cekPointerPlayer(pos.x+40, pos.y))
								pointerPlayer.setPosition(pos.x + 40, pos.y);
						}	
						if (event.key.code == sf::Keyboard::Left){
							sf::Vector2f pos = pointerPlayer.getPosition();
							if(cekPointerPlayer(pos.x-40, pos.y))
								pointerPlayer.setPosition(pos.x - 40, pos.y);
						}	
						if (event.key.code == sf::Keyboard::Up){
							sf::Vector2f pos = pointerPlayer.getPosition();
							if(cekPointerPlayer(pos.x, pos.y-40))
								pointerPlayer.setPosition(pos.x, pos.y - 40);
						}	
						if (event.key.code == sf::Keyboard::Down){
							sf::Vector2f pos = pointerPlayer.getPosition();
							if(cekPointerPlayer(pos.x, pos.y+40))
								pointerPlayer.setPosition(pos.x, pos.y + 40);
						}	
						if (event.key.code == sf::Keyboard::Num1){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40.0;
							pos.y /= 40.0;
							posX = pos.x;
							posY = pos.y;
							nilai = 1;
							cout<<"1";
							//printNumber(1, window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
						if (event.key.code == sf::Keyboard::Num2){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 2;
							cout<<"2";
							//printNumber(2,window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
						if (event.key.code == sf::Keyboard::Num3){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 3;
							cout<<"3";
							//printNumber(3,window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}
						if (event.key.code == sf::Keyboard::Num4){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 4;
							cout<<"4";
							//printNumber(4,window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
						if (event.key.code == sf::Keyboard::Num5){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 5;
							cout<<"5";
							//printNumber(5,window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
						if (event.key.code == sf::Keyboard::Num6){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 6;
							cout<<"6";
							//printNumber(6,window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
						if (event.key.code == sf::Keyboard::Num7){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 7;
							cout<<"7";
							//printNumber(7,window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
						if (event.key.code == sf::Keyboard::Num8){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 8;
							cout<<"8";
							//printNumber(8,window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
						if (event.key.code == sf::Keyboard::Num9){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 9;
							cout<<"9";
							insertMapPlay(nilai, map, posX, posY);
							//printNumber(9,window, pos.x, pos.y);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
						if (event.key.code == sf::Keyboard::Num0){
							sf::Vector2f pos = pointerPlayer.getPosition();
							pos.x /= 40;
							pos.y /= 40;
							posX = pos.x;
							posY = pos.y;
							nilai = 0;
							cout<<"0";
							//printNumber(8,window, pos.x, pos.y);
							insertMapPlay(nilai, map, posX, posY);
							printf(" %f;%f\n", pos.x,pos.y);
						}	
					}
					
				}	
				window.clear();
				window.draw(btnSolve1);
				window.draw(btnSolve2);
				window.draw(btnClear);
				window.draw(solve1);
				window.draw(solve2);
				window.draw(textclear);
				window.draw(boardSprite);
				window.draw(pointerPlayer);
				window.draw(btn);
				window.draw(time);
				//printNumber(nilai, window, posX, posY, map);
				printMap(window, map);
				window.display();
			}
			else if (code_game == 2){
				while(window.pollEvent(event)){
					if (event.type == sf::Event::Closed)
						window.close();
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						if (btn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							for (int i=0;i<9;i++){
								for (int j=0;j<9;j++){
									map[i][j] = 0;
								}
							}
							time.setString("Time Elapsed " + to_string(static_cast<long long>(0)) + " ms");
							timeSolving = 0;
							goto home;
						}
						if (btnSolve1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							solve(window, map, boardSprite);
						}
						if (btnSolve2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							cout<<"SOLVING...\n";
							int Start, Stop;
							Start = clock();
							if(solve(map)){
								cout<<"BERHASIL";		
								Stop = clock();
							}else{
								cout<<"GAGAL";
							}
							cout<<"SOLVED\n";
							timeSolving = (Stop-Start)/double(CLOCKS_PER_SEC)*1000;
							time.setString("Time Elapsed " + to_string(static_cast<long long>(timeSolving)) + " ms");
							cout<<"TIME ELAPSED: "<<timeSolving<<endl;
						}
						if (btnClear.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							for (int i=0;i<9;i++){
								for (int j=0;j<9;j++){
									map[i][j] = 0;
								}
							}
							time.setString("Time Elapsed " + to_string(static_cast<long long>(0)) + " ms");
							timeSolving = 0;
						}
					}
					window.clear();
					window.draw(btnSolve1);
					window.draw(btnSolve2);
					window.draw(btnClear);
					window.draw(solve1);
					window.draw(solve2);
					window.draw(textclear);
					window.draw(boardSprite);
					window.draw(btn);
					window.draw(time);
					printMap(window, map);
					window.display();
				}
			}
			else if (code_game == 3){
				int myArray[9][9];
				solve1.setString("Load");

				sf::Sprite btnanimate;
				sf::Text textsolveanimate;
				textsolveanimate.setColor(sf::Color::White);
				textsolveanimate.setFont(arialFont);
				textsolveanimate.setCharacterSize(24);
				textsolveanimate.setString("Solve (Animated)");	
				textsolveanimate.setPosition(sf::Vector2f(455, 380));

				sf::Texture textureload;
				textureload.loadFromFile("Assets/start-1.png");
				btnanimate.setTexture(btnTex1);
				btnanimate.scale(0.41, 0.335);
				btnanimate.setPosition(sf::Vector2f(427, 350));

				while(window.pollEvent(event)){
					if (event.type == sf::Event::Closed){
						window.close();
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
						if (btn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							for (int i=0;i<9;i++){
								for (int j=0;j<9;j++){
									map[i][j] = 0;
								}
							}
							time.setString("Time Elapsed " + to_string(static_cast<long long>(0)) + " ms");
							timeSolving = 0;
							goto home;
						}
						if (btnSolve1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							FILE * pf;
							char buffer[100];
							int num;
							pf = fopen("map.txt", "r");
							if (pf == NULL)
								cout << "Error opening file";
							else
							{
								for (int i = 0; i < 9; i++)
								{
									for (int j = 0; j < 9; j++)
									{
										fscanf(pf, "%d", &num);
										myArray[i][j] = num;
									}
								}

							}
							for (int i = 0; i < 9; i++)
							{
								for (int j = 0; j < 9; j++)
								{
									map[i][j] = myArray[i][j];
								}
							}
						}
						if (btnSolve2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							cout<<"SOLVING...\n";
							int Start, Stop;
							Start = clock();
							if(solve(map)){
								cout<<"BERHASIL";
								Stop = clock();
							} else {
								cout<<"GAGAL";
							}
							cout<<"SOLVED\n";
							timeSolving = (Stop-Start)/double(CLOCKS_PER_SEC)*1000;
							time.setString("Time Elapsed " + to_string(static_cast<long long>(timeSolving)) + " ms");
							cout<<"TIME ELAPSED: "<<timeSolving<<endl;
						}
						if (btnClear.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							for (int i=0;i<9;i++){
								for (int j=0;j<9;j++){
									map[i][j] = 0;
								}
							}
							time.setString("Time Elapsed " + to_string(static_cast<long long>(0)) + " ms");
							timeSolving = 0;
						}
						if (btnanimate.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
							solve(window, map, boardSprite);
						}
					}
					window.clear();
					window.draw(btnSolve1);
					window.draw(btnSolve2);
					window.draw(btnClear);
					window.draw(btnanimate);
					window.draw(solve1);
					window.draw(solve2);
					window.draw(textclear);
					window.draw(textsolveanimate);
					window.draw(boardSprite);
					window.draw(time);
					window.draw(btn);
					//printNumber(nilai, window, posX, posY, map);
					printMap(window, map);
					window.display();
				}
			}
		}
}