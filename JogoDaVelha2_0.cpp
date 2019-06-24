#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

char matriz[3][3] = {{NULL, NULL, NULL}, {NULL, NULL, NULL}, {NULL, NULL, NULL}}, valor;
int j1 = 0, j2 = 0, linha, coluna, contador = 0;
bool m = true, contem = false, jogador1 = true, jogador2 = false;

void zerar(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			matriz[i][j] = NULL;
		}
	}
	contador = 0;
}
void mostrar(){
	for(int i = 0; i < 3; i++){
		cout << " | ";
		for(int j = 0; j < 3; j++){
			cout << matriz[i][j] << " | ";
		}
		cout << "\n";
	}
}
char verifica(){
	if(	
		(matriz[0][0] == 'x' && matriz[0][1] == 'x' && matriz[0][2] == 'x') ||
		(matriz[1][0] == 'x' && matriz[1][1] == 'x' && matriz[1][2] == 'x') ||
		(matriz[2][0] == 'x' && matriz[2][1] == 'x' && matriz[2][2] == 'x') ||
	
		(matriz[0][0] == 'x' && matriz[1][0] == 'x' && matriz[2][0] == 'x') ||
		(matriz[0][1] == 'x' && matriz[1][1] == 'x' && matriz[2][1] == 'x') ||
		(matriz[0][2] == 'x' && matriz[1][2] == 'x' && matriz[2][2] == 'x') ||
	
		(matriz[0][0] == 'x' && matriz[1][1] == 'x' && matriz[2][2] == 'x') ||
		(matriz[2][0] == 'x' && matriz[1][1] == 'x' && matriz[0][2] == 'x')
		){
		return 'x';
	}else if(	
			(matriz[0][0] == 'o' && matriz[0][1] == 'o' && matriz[0][2] == 'o') ||
			(matriz[1][0] == 'o' && matriz[1][1] == 'o' && matriz[1][2] == 'o') ||
			(matriz[2][0] == 'o' && matriz[2][1] == 'o' && matriz[2][2] == 'o') ||
		   	
			(matriz[0][0] == 'o' && matriz[1][0] == 'o' && matriz[2][0] == 'o') ||
			(matriz[0][1] == 'o' && matriz[1][1] == 'o' && matriz[2][1] == 'o') ||
			(matriz[0][2] == 'o' && matriz[1][2] == 'o' && matriz[2][2] == 'o') ||
	   		
			(matriz[0][0] == 'o' && matriz[1][1] == 'o' && matriz[2][2] == 'o') ||
			(matriz[0][2] == 'o' && matriz[1][1] == 'o' && matriz[2][0] == 'o') 
			
			){
		return 'o';
	}
	   return ' ';	
}
int main(){
	do{
		if(m){
			if(jogador1){
				cout << "Jogador 1 Pontos: " << j1;
				cout << "\n*Digite -1 para sair.\n*Digite o numero da linha/coluna: \n";
				cin >> linha;
				if(linha <= -1 || linha > 2){return 0;}
				cin >> coluna;
				m = (linha <  3 && coluna < 3) && (linha > -1 && coluna > -1);
				contem = matriz[linha][coluna];
				if(!contem){
					matriz[linha][coluna] = 'x';
					mostrar();
					contador++;
					jogador1 = false;
					jogador2 = true;
				}else{
					cout << "Campo preenchido!";
					jogador1 = true;
					jogador2 = false;
				}
			}else if(jogador2){
				cout << "Jogador 2 Pontos: " << j2 << endl;
				linha = rand() % 3;
				coluna = rand() % 3;
				m = (linha <  3 && coluna < 3) && (linha > -1 && coluna > -1);
				contem = matriz[linha][coluna];
				if(!contem){
					matriz[linha][coluna] = 'o';
					mostrar();
					contador++;
					jogador2 = false;
					jogador1 = true;
				}else{
					jogador2 = true;
					jogador1 = false;
				}
			}

				}
	if(verifica() == 'x'){
		j1++;
		cout << "\n***Jogador 1 ganhou!***\n";
		zerar();
		}else if(verifica() == 'o'){
			j2++;
			cout << "\n***Jogador 2 ganhou!***\n";
			zerar();
		}
	}
	// while(linha < 4 || coluna < 4);
	while(coluna < 4);
	system("pause");
	return 0;
}


