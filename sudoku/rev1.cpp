//#include <SFML/Graphics.hpp>
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//bool cekPointerPlayer(float x, float y){
//	if((x>=0 && y>=0 )&&( x<=320 && y<=320)){
//		cout<<"\n--true--\n"<<x<<" "<<y<<endl;
//		return true;
//	}
//	else{
//		cout<<"\n--false--\n"<<x<<" "<<y<<endl;
//		return false;
//	}
//}
//int const REGION[9][9] = {
//	{ 0, 0, 1, 1, 1, 1, 1, 2, 2 },
//	{ 0, 0, 0, 1, 1, 1, 2, 2, 2 },
//	{ 3, 0, 0, 0, 1, 2, 2, 2, 5 },
//	{ 3, 3, 0, 4, 4, 4, 2, 5, 5 },
//	{ 3, 3, 3, 4, 4, 4, 5, 5, 5 },
//	{ 3, 3, 6, 4, 4, 4, 8, 5, 5 },
//	{ 3, 6, 6, 6, 7, 8, 8, 8, 5 },
//	{ 6, 6, 6, 7, 7, 7, 8, 8, 8 },
//	{ 6, 6, 7, 7, 7, 7, 7, 8, 8 }
//};
//sf::Text number, inputan;
//bool masihAdaKosong(int map[9][9], int &baris, int &kolom){
//	for (int i = 0; i<9; i++){
//		for (int j = 0; j<9; j++){
//			if (map[i][j] == 0){
//				baris = i;
//				kolom = j;
//				return true;
//			}
//		}
//	}
//	return false;
//}
//bool barisAman(int map[9][9], int baris, int angka){
//	for (int j = 0; j<9; j++){
//		if (map[baris][j] == angka){
//			return false;
//		}
//	}
//	return true;
//}
//bool barisAman(int map[9][9], int baris){
//	for (int i = 0; i<9; i++){
//		for (int j=0; j<9; j++){
//			if (i != j)
//			{
//				if (map[baris][i] == map[baris][j]){
//					return false;
//				}
//			}
//		}
//	}
//	return true;
//}
//bool kolomAman(int map[9][9], int kolom, int angka){
//	for (int i = 0; i<9; i++){
//		if (map[i][kolom] == angka){
//			return false;
//		}
//	}
//	return true;
//}
//bool kolomAman(int map[9][9], int kolom){
//	for (int i = 0; i<9; i++){
//		for(int j=0; j<9; j++){
//			if (i != j)
//			{
//				if (map[i][kolom] == map[j][kolom]){
//					return false;
//				}
//			}
//			cout<<endl;
//		}
//	}
//	return true;
//}
//bool sectionAman(int map[9][9], int baris, int kolom, int angka){
//	int reg = REGION[baris][kolom];
//
//	for (int i = 0; i<9; i++)
//	{
//		for (int j = 0; j<9; j++)
//		{
//			if (REGION[i][j] == reg)
//			{
//				if (map[i][j] == angka)
//					return false;
//			}
//		}
//	}
//	return true;
//}
//bool sectionAman(int map[9][9], int baris, int kolom){
//	int reg = REGION[baris][kolom];
//
//	for (int i = 0; i<9; i++)
//	{
//		for (int j = 0; j<9; j++)
//		{
//			if (REGION[i][j] == reg)
//			{
//				for (int x=0; x<9; x++){
//					for (int y=0; y<9; y++){
//						if (REGION[x][y] == reg)
//						{
//							if(i!=x && j!=y){
//								if (map[i][j] == map[x][y])
//									return false;
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	return true;
//}
//void printMap(int map[9][9]){
//	for (int i=0;i<9;i++){
//		for(int j=0; j<9;j++){
//			printf("%d ", map[i][j]);
//		}
//		cout<<endl;
//	}
//}
//bool isSafe(int map[9][9], int baris, int kolom){
//	printMap(map);
//	bool a, b, c;
//	a = sectionAman(map, baris, kolom);
//	b = barisAman(map, baris);
//	c = kolomAman(map, kolom);
//	if (a && b && c){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//bool isSafe(int map[9][9], int baris, int kolom, int i){
//	printMap(map);
//	bool a, b, c;
//	a = sectionAman(map, baris, kolom, i);
//	b = barisAman(map, baris, i);
//	c = kolomAman(map, kolom, i);
//	if (a && b && c){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//
//void printMap(sf::RenderWindow &window, int map[9][9]){
//	for (int row = 0; row < 9; row++)
//	{
//		for (int col = 0; col < 9; col++){
//			printf("|%2d", map[row][col]);
//			/*if (row == 0 && col == 0){
//				number.setPosition(33, 33);
//			}*/
//			else{
//			number.setPosition((row * 40) + 5, (col * 40) + 5);
//			}
//			if (map[col][row] != 0){
//				number.setString(to_string(static_cast<long long>(map[col][row])));
//				window.draw(number);
//			}
//		}
//		 printf("\n------------------------------------------------------\n");
//	}
//}
//void insertMapPlay(int angka, int mapPlay[9][9], int x, int y){
//	mapPlay[y][x] = angka;
//}
//void printMapPlay(int mapPlay[9][9], sf::RenderWindow &window){
//	for (int row = 0; row < 9; row++)
//	{
//		for (int col = 0; col < 9; col++){
//			inputan.setPosition(col*40 + 5, row*40 + 5);
//			if (mapPlay[row][col] != 0){
//				inputan.setString(to_string(static_cast<long long>(mapPlay[row][col])));
//				window.draw(inputan);
//			}
//		}
//	}
//}
//void printNumber(int angka, sf::RenderWindow &window, int x, int y, int mapPlay[9][9]){
//	insertMapPlay(angka, mapPlay, x, y);
//	printMapPlay(mapPlay, window);
//	/*inputan.setPosition(x+5,y+5);
//	inputan.setString(to_string(static_cast<long long>(angka)));
//	window.draw(inputan);
//	mapPlay[x][y] = angka;*/
//}
//bool cekInput(int map[9][9]){
//	cout<<"SOLVING"<<endl;
//	for(int i=0; i<9; i++){
//		for(int j=0; j<9; j++){
//			if(isSafe(map, i,j)==false){
//				cout<<"GAGAL";
//				return false;
//			}else
//			{
//				cout<<"berhasil";
//			}
//			cout<<endl;
//		}
//	}
//	return true;
//}
//bool solve(int map[9][9]){
//	 cout << "solving" << endl;
//	int baris, kolom;
//
//	sf::Event event;
//	if (window.pollEvent(event))
//	{
//		if (event.type == sf::Event::Closed)
//			window.close();
//	}
//
//	window.clear();
//	window.draw(boardSprite);
//	printMap(window, map);
//	window.display();
//
//	if (masihAdaKosong(map, baris, kolom) == false){
//		return true;
//	}
//	for (int i = 1; i<10; i++){
//
//		UNTUK MELAKUKAN ANIMASI PART 1/3
//		/*int temp = map[baris][kolom];
//		map[baris][kolom] = i;
//		system("CLS");
//		printMap(map);
//		Sleep(1);
//		map[baris][kolom] = temp;*/
//
//
//		if (isSafe(map, baris, kolom, i) == true){
//			map[baris][kolom] = i;
//
//			UNTUK MELAKUKAN ANIMASI PART 2/3
//			/*system("CLS");
//			printMap(map);
//			Sleep(1);*/
//
//			if (solve(map) == true)
//				return true;
//
//			map[baris][kolom] = 0;
//
//			UNTUK MELAKUKAN ANIMASI PART 3/3
//			/*system("CLS");
//			printMap(map);
//			Sleep(1);*/
//		}
//	}
//	return false;
//}
//bool solve(sf::RenderWindow &window, int map[9][9], sf::Sprite boardSprite){
//	cout << "solving" << endl;
//	int baris, kolom;
//
//	sf::Event event;
//	if (window.pollEvent(event))
//	{
//		if (event.type == sf::Event::Closed)
//			window.close();
//	}
//
//	window.clear();
//	window.draw(boardSprite);
//	printMap(window, map);
//	window.display();
//
//	if (masihAdaKosong(map, baris, kolom) == false)
//		return true;
//
//	for (int i = 1; i<10; i++){
//
//		UNTUK MELAKUKAN ANIMASI PART 1/3
//		/*int temp = map[baris][kolom];
//		map[baris][kolom] = i;
//		system("CLS");
//		printMap(map);
//		Sleep(1);
//		map[baris][kolom] = temp;*/
//
//
//		if (isSafe(map, baris, kolom, i) == true){
//			map[baris][kolom] = i;
//
//			UNTUK MELAKUKAN ANIMASI PART 2/3
//			/*system("CLS");
//			printMap(map);
//			Sleep(1);*/
//
//			if (solve(window, map, boardSprite) == true)
//				return true;
//
//			map[baris][kolom] = 0;
//
//			UNTUK MELAKUKAN ANIMASI PART 3/3
//			/*system("CLS");
//			printMap(map);
//			Sleep(1);*/
//		}
//	}
//
//	cout<<"gagal";
//	return false;
//}
//class CBackground{
//private:
//	sf::Texture bgTexture;
//	sf::Sprite bg;
//	string id;
//public:
//	CBackground(){
//		id = "none";
//		bgTexture.loadFromFile("Assets/bg_menu.jpg");
//		bg.setTexture(bgTexture);
//		bg.setPosition(sf::Vector2f(0,0));
//	}
//	void setBackground(string _id){
//		id = _id;
//		if (id == "menu")
//			bgTexture.loadFromFile("Assets/bg_menu.jpg");
//		else if (id == "game")
//			bgTexture.loadFromFile("Assets/bg_game.png");
//	}
//	sf::Sprite getSprite(){
//		return bg;
//	}
//};
//void main(){
//	int map[9][9] = 
//	{ { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
//	sf::Sprite boardSprite;
//	sf::Texture boardTexture;
//	boardTexture.loadFromFile("MAPSUDOKU.png");
//	boardSprite.setTexture(boardTexture);
//	boardSprite.setScale(0.5, 0.5);
//
//	int code_game = 0;
//	1 = play game, 2 = random solve, 3 = special solve
//	sf::RenderWindow window;
//	sf::Event event;
//	window.create(sf::VideoMode(1000,700), "SUDOKU");
//	CBackground bg;
//home:
//	while(window.isOpen()){
//		window.setMouseCursorVisible(true);
//		bg.setBackground("menu");
//		menu - init
//		sf::Texture btnTexture[5];
//		sf::Sprite btn[5];
//		btnTexture[0].loadFromFile("Assets/title.png");
//		btnTexture[1].loadFromFile("Assets/bt_play.png");
//		btnTexture[2].loadFromFile("Assets/bt_random.png");
//		btnTexture[3].loadFromFile("Assets/bt_special.png");
//		btnTexture[4].loadFromFile("Assets/bt_exit.png");
//		for (int a = 1; a < 5; a++){
//			btn[a].setTexture(btnTexture[a]);
//			btn[a].scale(0.41, 0.335);
//			btn[a].setPosition(sf::Vector2f(227, 100*(a + 2) - 25));
//		}
//		btn[0].setTexture(btnTexture[0]);
//		btn[0].setPosition(sf::Vector2f(190, 111));
//		menu - play
//		while(window.pollEvent(event)){
//			if (event.type == sf::Event::Closed)
//				window.close();
//			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//				if(btn[1].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
//					code_game = 1;
//					goto game;
//				}
//				if(btn[2].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
//					code_game = 2;
//					goto game;
//				}
//				if(btn[3].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
//					code_game = 3;
//					goto game;
//				}
//				else if (btn[4].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
//					window.close();
//				}
//			}
//		}
//		window.clear();
//		window.draw(bg.getSprite());
//		for (int a = 0; a < 5; a++)
//			window.draw(btn[a]);
//		window.display();
//	}
//game:
//	if(code_game == 1)
//	{
//		int posX, posY, nilai;
//		sf::Font arialFont;
//		arialFont.loadFromFile("arial.ttf");
//
//		sf::Text solve1, solve2, textclear;
//		solve1.setColor(sf::Color::White);
//		solve1.setFont(arialFont);
//		solve1.setCharacterSize(24);
//		solve1.setString("Solve (Animated)");	
//		solve1.setPosition(sf::Vector2f(427, 50));
//
//		sf::Texture btnTexture, btnTex1;
//		sf::Sprite btn, btnSolve1;
//		btnTexture.loadFromFile("Assets/bt_back.png");
//		btn.setTexture(btnTexture);
//		btn.scale(0.41, 0.335);
//		btn.setPosition(sf::Vector2f(727, 100));
//
//		btnTex1.loadFromFile("Assets/start-1.png");
//		btnSolve1.setTexture(btnTex1);
//		btnSolve1.scale(0.41, 0.335);
//		btnSolve1.setPosition(sf::Vector2f(427, 50));
//
//		sf::RectangleShape pointerPlayer;
//		pointerPlayer.setFillColor(sf::Color(0,144,144,50));
//		pointerPlayer.setSize(sf::Vector2f(40,40));
//		pointerPlayer.setPosition(0,0);
//
//		while(window.isOpen()){
//			while(window.pollEvent(event)){
//				if (event.type == sf::Event::Closed)
//					window.close();
//				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//					if (btn.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
//						goto home;
//					}
//					if (btnSolve1.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)){
//						solve(window, map, boardSprite);
//					}
//				}
//				if (event.type == sf::Event::KeyPressed){
//					if (event.key.code == sf::Keyboard::Right){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						if(cekPointerPlayer(pos.x+40, pos.y))
//							pointerPlayer.setPosition(pos.x + 40, pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Left){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						if(cekPointerPlayer(pos.x-40, pos.y))
//							pointerPlayer.setPosition(pos.x - 40, pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Up){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						if(cekPointerPlayer(pos.x, pos.y-40))
//							pointerPlayer.setPosition(pos.x, pos.y - 40);
//					}	
//					if (event.key.code == sf::Keyboard::Down){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						if(cekPointerPlayer(pos.x, pos.y+40))
//							pointerPlayer.setPosition(pos.x, pos.y + 40);
//					}	
//					if (event.key.code == sf::Keyboard::Num1){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40.0;
//						pos.y /= 40.0;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 1;
//						cout<<"1";
//						printNumber(1, window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Num2){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40;
//						pos.y /= 40;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 2;
//						cout<<"2";
//						printNumber(2,window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Num3){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40;
//						pos.y /= 40;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 3;
//						cout<<"3";
//						printNumber(3,window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}
//					if (event.key.code == sf::Keyboard::Num4){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40;
//						pos.y /= 40;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 4;
//						cout<<"4";
//						printNumber(4,window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Num5){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40;
//						pos.y /= 40;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 5;
//						cout<<"5";
//						printNumber(5,window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Num6){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40;
//						pos.y /= 40;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 6;
//						cout<<"6";
//						printNumber(6,window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Num7){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40;
//						pos.y /= 40;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 7;
//						cout<<"7";
//						printNumber(7,window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Num8){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40;
//						pos.y /= 40;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 8;
//						cout<<"8";
//						printNumber(8,window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}	
//					if (event.key.code == sf::Keyboard::Num9){
//						sf::Vector2f pos = pointerPlayer.getPosition();
//						pos.x /= 40;
//						pos.y /= 40;
//						posX = pos.x;
//						posY = pos.y;
//						nilai = 9;
//						cout<<"9";
//						printNumber(9,window, pos.x, pos.y);
//						printf(" %f;%f\n", pos.x,pos.y);
//					}	
//				}
//			}
//			window.clear();
//			window.draw(boardSprite);
//			window.draw(btn);
//			window.draw(btnSolve1);
//			window.draw(solve1);
//			window.draw(pointerPlayer);
//			printNumber(nilai, window, posX, posY, map);
//			window.display();
//		}
//	}
//	else if(code_game == 2){
//		while(window.isOpen()){
//			while(window.pollEvent(event)){
//				if (event.type == sf::Event::Closed)
//					window.close();
//			}
//			window.clear();
//			boardSprite.setPosition(0.0f, 100.0f);
//			window.draw(boardSprite);
//			window.display();
//		}
//	}
//}