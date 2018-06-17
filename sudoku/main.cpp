#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

int const REGION[9][9]={ 
 {0, 0, 1, 1, 1, 1, 1, 2, 2}, 
 {0, 0, 0, 1, 1, 1, 2, 2, 2}, 
 {3, 0, 0, 0, 1, 2, 2, 2, 5}, 
 {3, 3, 0, 4, 4, 4, 2, 5, 5}, 
 {3, 3, 3, 4, 4, 4, 5, 5, 5}, 
 {3, 3, 6, 4, 4, 4, 8, 5, 5}, 
 {3, 6, 6, 6, 7, 8, 8, 8, 5}, 
 {6, 6, 6, 7, 7, 7, 8, 8, 8}, 
 {6, 6, 7, 7, 7, 7, 7, 8, 8} 
};

void printMap(int map[9][9]);
bool masihAdaKosong(int map[9][9], int &baris, int &kolom){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(map[i][j] == 0){
				baris = i;
				kolom = j;
				return true;
			}
		}
	}
	return false;
}
bool barisAman(int map[9][9], int baris, int angka){
	for(int j=0; j<9; j++){
		if(map[baris][j] == angka){
			return false;
		}
	}
	return true;
}
bool kolomAman(int map[9][9], int kolom, int angka){
	for(int i=0; i<9; i++){
		if(map[i][kolom] == angka){
			return false;
		}
	}
	return true;
}
bool sectionAman(int map[9][9], int baris, int kolom, int angka){
	int reg=REGION[baris][kolom]; 

	for(int i=0;i<9;i++) 
	{ 
		for(int j=0;j<9;j++) 
		{ 
			if(REGION[i][j]==reg) 
			{ 
				if(map[i][j]==angka) 
					return false; 
			} 
		}
	}
	return true;
}
bool isSafe(int map[9][9], int baris, int kolom, int i){
	bool a,b,c;
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
void printMap(int map[9][9]){
	for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             printf("|%2d", map[row][col]);
        printf("\n------------------------------------------------------\n");
    }
}

bool solve(int map[9][9]){
	int baris, kolom;

	if(masihAdaKosong(map, baris, kolom) == false)
		return true;
	
	for (int i=1; i<10; i++){
		
		//UNTUK MELAKUKAN ANIMASI PART 1/3
		/*int temp = map[baris][kolom];
		map[baris][kolom] = i;
		system("CLS");
		printMap(map);
		Sleep(1);
		map[baris][kolom] = temp;*/

		if (isSafe(map, baris, kolom, i) == true){
			map[baris][kolom] = i;

			//UNTUK MELAKUKAN ANIMASI PART 2/3
			/*system("CLS");
			printMap(map);
			Sleep(1);*/

			if (solve(map) == true)
				return true;

			map[baris][kolom] = 0;

			//UNTUK MELAKUKAN ANIMASI PART 3/3
			/*system("CLS");
			printMap(map);
			Sleep(1);*/
		}
	}

	return false;
}

void main(){
int start_s=clock();
	/*int map[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};*/
	int map[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

	if (solve(map)){
		printMap(map);
	} else {
		cout<<"GAGAL";
	}
int stop_s=clock();
cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 <<" ms"<< endl;
	
}
