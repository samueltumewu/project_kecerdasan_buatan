//#include <iostream>
//#include <conio.h>
//#include <cstdlib>
//#include <ctime>
//#include <Windows.h>
//#include<SFML\Graphics.hpp>
//using namespace std;
//
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
//sf::Text inputan;
//sf::Text number;
////void printMap(int map[9][9]);
//
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
//	//printMap(map);
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
//	//printMap(map);
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
//			//printf("|%2d", map[row][col]);
//			/*if (row == 0 && col == 0){
//				number.setPosition(33, 33);
//			}*/
//			//else{
//			number.setPosition((row * 40) + 5, (col * 40) + 5);
//			//}
//			if (map[col][row] != 0){
//				number.setString(to_string(static_cast<long long>(map[col][row])));
//				window.draw(number);
//			}
//		}
//		// printf("\n------------------------------------------------------\n");
//	}
//}
//
//bool cekInput(int map[9][9]){
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
//	// cout << "solving" << endl;
//	int baris, kolom;
//
//	//sf::Event event;
//	//if (window.pollEvent(event))
//	//{
//	//	if (event.type == sf::Event::Closed)
//	//		window.close();
//	//}
//
//	//window.clear();
//	//window.draw(boardSprite);
//	//printMap(window, map);
//	//window.display();
//
//	if (masihAdaKosong(map, baris, kolom) == false){
//		return true;
//	}
//	for (int i = 1; i<10; i++){
//
//		//UNTUK MELAKUKAN ANIMASI PART 1/3
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
//			//UNTUK MELAKUKAN ANIMASI PART 2/3
//			/*system("CLS");
//			printMap(map);
//			Sleep(1);*/
//
//			if (solve(map) == true)
//				return true;
//
//			map[baris][kolom] = 0;
//
//			//UNTUK MELAKUKAN ANIMASI PART 3/3
//			/*system("CLS");
//			printMap(map);
//			Sleep(1);*/
//		}
//	}
//	return false;
//}
//bool solve(sf::RenderWindow &window, int map[9][9], sf::Sprite boardSprite){
//	//cout << "solving" << endl;
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
//		//UNTUK MELAKUKAN ANIMASI PART 1/3
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
//			//UNTUK MELAKUKAN ANIMASI PART 2/3
//			/*system("CLS");
//			printMap(map);
//			Sleep(1);*/
//
//			if (solve(window, map, boardSprite) == true)
//				return true;
//
//			map[baris][kolom] = 0;
//
//			//UNTUK MELAKUKAN ANIMASI PART 3/3
//			/*system("CLS");
//			printMap(map);
//			Sleep(1);*/
//		}
//	}
//
//	//cout<<"gagal";
//	return false;
//}
//bool cekPointerPlayer(float x, float y){
//	if((x>=0 && y>=0 )&&( x<=320 && y<=320)){
//		cout<<"\n--true--\n";
//		return true;
//	}
//	else{
//		cout<<"\n--false--\n";
//		return false;
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
//
//void main(){
//	sf::RenderWindow window(sf::VideoMode(500, 356), "SFML works!");
//
//	sf::RectangleShape buttonplay;
//	buttonplay.setFillColor(sf::Color::Cyan);
//	buttonplay.setSize(sf::Vector2f(100,50));
//	buttonplay.setPosition(400, 0);
//
//	sf::Font arialFont;
//	arialFont.loadFromFile("arial.ttf");
//
//	number.setColor(sf::Color::Blue);
//	number.setFont(arialFont);
//	number.setCharacterSize(12);	
//
//	inputan.setColor(sf::Color::Blue);
//	inputan.setFont(arialFont);
//	inputan.setCharacterSize(12);
//
//	sf::Texture boardTexture;
//	sf::Sprite boardSprite;
//	boardTexture.loadFromFile("MAPSUDOKU.png");
//	boardSprite.setTexture(boardTexture);
//	boardSprite.setScale(0.5, 0.5);
//
//	sf::RectangleShape pointerPlayer;
//	pointerPlayer.setFillColor(sf::Color(0,144,144,50));
//	pointerPlayer.setSize(sf::Vector2f(40,40));
//	
//	int start_s = clock();
//	/*int map[9][9] = {
//	{3, 0, 6, 5, 0, 8, 4, 0, 0},
//	{5, 2, 0, 0, 0, 0, 0, 0, 0},
//	{0, 8, 7, 0, 0, 0, 0, 3, 1},
//	{0, 0, 3, 0, 1, 0, 0, 8, 0},
//	{9, 0, 0, 8, 6, 3, 0, 0, 5},
//	{0, 5, 0, 0, 9, 0, 6, 0, 0},
//	{1, 3, 0, 0, 0, 0, 2, 5, 0},
//	{0, 0, 0, 0, 0, 0, 0, 7, 4},
//	{0, 0, 5, 2, 0, 6, 3, 0, 0}};*/
//	int map[9][9] = { { 1, 0, 0, 0, 0, 0, 0, 0, 5 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
//	{ 3, 0, 0, 0, 0, 0, 0, 0, 9 } };
//
//	int mapPlay[9][9] = { { 2, 1, 4, 3, 5, 6, 7, 8, 9 },
//	{ 3, 4, 5, 1, 8, 9, 2, 6, 7 },
//	{ 1, 6, 7, 9, 2, 3, 4, 5, 8 },
//	{ 4, 2, 8, 6, 7, 5, 1, 9, 3 },
//	{ 5, 7, 3, 8, 9, 1, 6, 2, 4 },
//	{ 6, 9, 1, 2, 3, 4, 8, 7, 5 },
//	{ 8, 5, 2, 4, 6, 7, 9, 3, 1 },
//	{ 9, 3, 6, 7, 1, 8, 5, 4, 2 },
//	{ 7, 8, 9, 5, 4, 2, 3, 1, 6 } };
//
//	int myArray[9][9];
//	
//	bool userInput = false;
//	pointerPlayer.setPosition(-50,-50);
//	int posX, posY, nilai;
//	while (window.isOpen())
//	{
//		sf::Event event;
//        while (window.pollEvent(event))
//		{
//            if (event.type == sf::Event::Closed)
//				window.close();
//			if (event.type == sf::Event::KeyPressed){
//				if (event.key.code == sf::Keyboard::S){
//					solve(window,map,boardSprite);
//				}	
//				if (event.key.code == sf::Keyboard::A){
//					//userInput = false;
//					if(!userInput)
//						solve(map);
//					else{
//						//printMap(map);
//						cekInput(map);
//					}
//				}
//				
//				if (event.key.code == sf::Keyboard::C){
//					for (int i = 0; i < 9; i++)
//					{
//						for (int j = 0; j < 9; j++) 
//						{
//							map[i][j] = 0;
//							myArray[i][j] = 0;
//						}
//					}
//				}
//				if (event.key.code == sf::Keyboard::L){
//					FILE * pf;
//					char buffer[100];
//					int num;
//					pf = fopen("map.txt", "r");
//					if (pf == NULL)
//						cout << "Error opening file";
//					else
//					{
//						for (int i = 0; i < 9; i++)
//						{
//							for (int j = 0; j < 9; j++)
//							{
//								fscanf(pf, "%d", &num);
//								myArray[i][j] = num;
//							}
//						}
//
//					}
//					for (int i = 0; i < 9; i++)
//					{
//						for (int j = 0; j < 9; j++)
//						{
//							map[i][j] = myArray[i][j];
//						}
//					}
//					window.clear();
//					//window.draw(buttonplay);
//					//window.draw(playtext);
//					window.draw(boardSprite);
//					printMap(window, myArray);
//					window.display();
//				}
//			}	
//			if (event.type == sf::Event::KeyPressed){
//				if (event.key.code == sf::Keyboard::G){
//					userInput = true;
//					pointerPlayer.setPosition(0, 0);
//				}	
//			}
//			if(userInput){
//				if (event.type == sf::Event::KeyPressed){
//						if (event.key.code == sf::Keyboard::Right){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							if(cekPointerPlayer(pos.x+40, pos.y))
//								pointerPlayer.setPosition(pos.x + 40, pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Left){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							if(cekPointerPlayer(pos.x-40, pos.y))
//								pointerPlayer.setPosition(pos.x - 40, pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Up){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							if(cekPointerPlayer(pos.x, pos.y-40))
//								pointerPlayer.setPosition(pos.x, pos.y - 40);
//						}	
//						if (event.key.code == sf::Keyboard::Down){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							if(cekPointerPlayer(pos.x, pos.y+40))
//								pointerPlayer.setPosition(pos.x, pos.y + 40);
//						}	
//						if (event.key.code == sf::Keyboard::Num1){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40.0;
//							pos.y /= 40.0;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 1;
//							cout<<"1";
//							//printNumber(1, window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Num2){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40;
//							pos.y /= 40;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 2;
//							cout<<"2";
//							//printNumber(2,window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Num3){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40;
//							pos.y /= 40;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 3;
//							cout<<"3";
//							//printNumber(3,window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}
//						if (event.key.code == sf::Keyboard::Num4){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40;
//							pos.y /= 40;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 4;
//							cout<<"4";
//							//printNumber(4,window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Num5){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40;
//							pos.y /= 40;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 5;
//							cout<<"5";
//							//printNumber(5,window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Num6){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40;
//							pos.y /= 40;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 6;
//							cout<<"6";
//							//printNumber(6,window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Num7){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40;
//							pos.y /= 40;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 7;
//							cout<<"7";
//							//printNumber(7,window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Num8){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40;
//							pos.y /= 40;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 8;
//							cout<<"8";
//							//printNumber(8,window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::Num9){
//							sf::Vector2f pos = pointerPlayer.getPosition();
//							pos.x /= 40;
//							pos.y /= 40;
//							posX = pos.x;
//							posY = pos.y;
//							nilai = 9;
//							cout<<"9";
//							//printNumber(9,window, pos.x, pos.y);
//							printf(" %f;%f\n", pos.x,pos.y);
//						}	
//						if (event.key.code == sf::Keyboard::C){
//							for (int i = 0; i < 9; i++)
//							{
//								for (int j = 0; j < 9; j++) 
//								{
//									map[i][j] = 0;
//									myArray[i][j] = 0;
//									nilai = 0;
//									userInput= false;
//								}
//							}
//						}
//						if (event.key.code == sf::Keyboard::P){
//							if(solve(map)==false){
//								cout<<"TIDak mungkin";
//							}
//							else
//								cout<<"mungkin";
//						}	
//					}
//			}
//		}
//		
//        window.clear();
//		window.draw(boardSprite);
//		if(userInput){
//			window.draw(pointerPlayer);
//			printNumber(nilai, window, posX, posY, map);
//		}
//		else
//			printMap(window, map);
//		//window.draw(buttonplay);
//		//window.draw(playtext);
//        window.display();
//	}
//
//}