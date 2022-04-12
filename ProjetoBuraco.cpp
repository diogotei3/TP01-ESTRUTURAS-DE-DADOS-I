#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <iomanip>
#include <locale.h>
using namespace std;

string selectNaipe(int number) {
	switch(number)	{
	case 1:
		return "Copas";
		break;
	case 2:
		return "Paus";
		break;
	case 3:
		return "Ouro";
		break;
	case 4:
		return "Espada";
		break;
	}
}

int main()
{
		/*N-99-B = Onde:
		N  -> Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
		99 -> Número da carta (01-Ás / 13-Rei)
		B  -> Baralho (1 ou 2)
		11 cartas para 4 jogadores */
		
	setlocale(LC_ALL, "Portuguese");
    cout << "Projeto Buraco" << endl << endl;
    
    bool ***baralhos;
    int i;
	int j;
	int k;
    
    baralhos = new bool**[2];
    for(i = 1; i < 3; i++) {
		baralhos[i] = new bool*[4];
		
		for(j = 1; j < 5; j++) {
			baralhos[i][j] = new bool[13];
			
			for(k = 1; k < 13; k++) 
			{
				baralhos[i][j][k] = false;				
			}
		}
	}
	
		
	int jogador;
	int carta;
	for (jogador = 1; jogador < 5; jogador++) 
	{
		cout << " Jogador " << jogador << endl;
		
		for(carta = 1; carta < 12;  carta++) 
		{
			int a;
			int b;
			int c;
			
			do 
			{ 
				a = rand() % ( 2 + 1 - 1) + 1;
				b = rand() % ( 4 + 1 - 1) + 1;
				c = rand() % ( 13 + 1 - 1) + 1;
			} while(baralhos[a][b][c]); 
			
			baralhos[a][b][c] = true;
			
			int baralho = a;
			int naipe = b;
			int carta = c;
			
			cout << "  (" << naipe << "-" << setfill('0') << setw(2) << carta << "-" << baralho;
			cout << ") = " << setw(2) << carta << " de " << selectNaipe(naipe) << ", baralho " << baralho << endl;
		}		
		cout << endl;
	}
	
    return 0;       
}