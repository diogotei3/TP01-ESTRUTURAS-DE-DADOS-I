#include <iostream> //entrada e saida
#include <iomanip> //fun��es para saida e formata��o
#include <locale.h> //exibir caracteres especiais
using namespace std; 

#define LIN 16
#define COL 41

int main(int argc, char** argv)
{        
	 setlocale(LC_ALL, "Portuguese");
       int marc=1;
       int i;
       int j;
       int linha;
       int coluna;
       int contador1=0;
	   int contador2=0;
	   int contador3=0;
	   int faturamento;
       char poltronas[16][41];
       
       //percorrer fileiras e atribuir '.'  para vago em todas
       for(i=1; i<LIN; ++i)
       {
		for(j = 1; j<COL; ++j)
			{
			poltronas[i][j] = '.';
		   	}
       }
       
	 while(marc!=0)
{	 
   	 cout << "Projeto Bilheteria" << endl;	
	 cout << "Digite uma das op��es a seguir: " << endl
	 << "0.	Finalizar" << endl
	 << "1.	Reservar poltrona"<< endl
	 << "2.	Mapa de ocupa��o"<< endl
	 << "3.	Faturamento"<< endl;
	 char op;
	 cin >> op;
	 
	 if(op=='0') //cumpre condi��o do la�o
	 {
	 	marc=0;
	 	cout << "Op��o 0" << endl << "Fim da aplica��o." <<endl;
	 	
	 }
	 
	  else if(op=='1') //'.' = vago e '#' = ocupado
	 {
	 cout << "Op��o 1" << endl<< "Digite a fileira da poltrona desejada, de 1 at� 15: " <<endl;
	 cin >> linha;
	 cout << endl;
	 cout << "Digite a coluna da poltrona desejada, de 1 at� 40: " <<endl;
	 cin >> coluna;
	 
	 if(poltronas[linha][coluna]=='.')
		 {
			cout << "Poltrona reservada!" <<endl;
			poltronas[linha][coluna]= '#';
			if(linha<6)
			{
			contador1++;	
			}	
			else if(linha<11 && linha>5)
			{
			contador2++;	
			}
			else if(linha<16 && linha>10)
			{
			contador3++;	
			}
		 }
	 else
		 {
			cout << "Poltrona ocupada!" <<endl; 
		 }	 
	 cout << endl;	
	 }
	 
	  else if(op=='2') //percorre e exibe poltronas
	 {
	 cout << "Op��o 2" << endl<< "Mapa de ocupa��o: " <<endl; 	 
	 	
	 for(i=1; i<LIN; ++i)
		{
			for(j = 1; j<COL; ++j)
			{
				cout << poltronas[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;	
	 }
	 
	  else if(op=='3') //quantidade de poltronas ocupadas (soma contadores), e calcula valor com regra
	 {
	 cout << "Op��o 3" << endl<< "Faturamento: " <<endl;
	 faturamento=contador1*50 + contador2*30 + contador3*15;
	cout << faturamento <<endl <<endl;	 		
	 }
	 
	  else
	 {
		cout << "Voc� n�o digitou uma op��o v�lida, tente novamente e continue a aplica��o: " <<endl; 
		cout << endl;
	 }
//fim la�o	 
}	
	return 0;
}