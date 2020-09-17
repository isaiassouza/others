#include<bits/stdc++.h>
using namespace std;

void ImprimeVetorSeparadoPorEspacos(char _Vetor[], int tamVet)
{
	for(int a = 0; a < tamVet; a++)
		cout << _Vetor[a] << ' ';
	
	cout << endl;		
}

void InsertionSort(char _Vetor[], int tam)
{
	int j, ContSubInstrucoes;
	char atual;
	
	cout << "--Vetor que será trabalhado: ";
	ImprimeVetorSeparadoPorEspacos(_Vetor, tam);
	for(int i = 1; i < tam; i++)
	{
		ContSubInstrucoes = 1;
		cout << "	" << ContSubInstrucoes << "	Caractere a ser comparado durante o laco atual '" << _Vetor[i] << "'." << endl;
		ContSubInstrucoes++;
		atual = _Vetor[i];
		cout << "	" << ContSubInstrucoes << "	Posicao de onde comecara as comparacoes durante o " << i << "º laco: " << i - 1 << '.' << endl; 
		ContSubInstrucoes++;
		j = i - 1;
		cout << "	" << ContSubInstrucoes << "	Entrou no while interno que verificara onde '" << atual << "', devera ficar." << endl;
		ContSubInstrucoes++;
		while( (j >= 0) and (atual < _Vetor[j]) )
		{
			
			_Vetor[j + 1] = _Vetor[j];
			j--;
			
			if(!(j < 0))
				cout << "	" << ContSubInstrucoes << "	Saiu do loop responsavel por achar a posicao de '" << atual <<  
				"' dentro do sub-vetor ''ordenado'', pois chegou na 1ª posicao" << endl;
			else
			if(!(atual < _Vetor[j])) 
				cout << "	" << ContSubInstrucoes << "	Saiu do loop responsavel por achar a posicao de '" << atual <<  
				"' dentro do sub-vetor ''ordenado'', pois achou '" << _Vetor[j + 1] << "'" <<
				" que e maior ou igual." << endl;
			else
				cout << "	" << ContSubInstrucoes << "	Saiu do loop responsavel por achar a posicao de '" << atual <<  
				"' dentro do sub-vetor ''ordenado'', pois '" << atual << "' e menor que '" << _Vetor[j] << "'." << endl;
				
			ContSubInstrucoes++;
		}
		_Vetor[j + 1] = atual;
		cout << "	" << ContSubInstrucoes << "	A posição [" << j + 1 << "] do vetor teve seu valor alterado para '" << atual << "'." << endl;
		
		cout << i << ")--Vetor Atualmente: ";
		ImprimeVetorSeparadoPorEspacos(_Vetor, tam);
		cout << endl;
	}
	cout << "--Vetor Ordenado: ";
	ImprimeVetorSeparadoPorEspacos(_Vetor, tam);
}

void ShellSort(char _Vetor[], int tam)
{
	int j, Aux, ContSubInstrucoes, Pulo = tam / 2;
	
	cout << "--Vetor que será trabalhado: ";
	ImprimeVetorSeparadoPorEspacos(_Vetor, tam);
	
	while(Pulo > 0)
	{
		for(int i = Pulo; i < tam; i++)
		{
			Aux = _Vetor[i];
			j = i;
			while( (j >= Pulo) and (_Vetor[j - Pulo] > Aux) )
			{
				
				_Vetor[j] = _Vetor[j - Pulo];
				j = j - Pulo;
					
				ContSubInstrucoes++;
			}
			_Vetor[j] = Aux;	
		}
		Pulo /= 2;
		
		cout << ")--Vetor Atualmente: ";
		ImprimeVetorSeparadoPorEspacos(_Vetor, tam);
		cout << endl;
	}
	cout << "--Vetor Ordenado: ";
	ImprimeVetorSeparadoPorEspacos(_Vetor, tam);
}

int main()
{
	int x;
	
	do
	{
		char _Frase[] = {'U', 'M', 'D', 'O', 'I', 'S'};
		
		cout << endl << "Escolha qual o método de ordenação para ser demonstrado em '";
		ImprimeVetorSeparadoPorEspacos(_Frase, strlen(_Frase));
		
		cout << "1 - Insertion Sort " << endl;
		cout << "2 - Shell Sort " << endl;
		cout << "3 - Merge Sort " << endl;
		cout << "4 - Quick Sort " << endl << endl;
		
		cout << "5 - Sair " << endl << endl;
		
		cin >> x;
		switch ( x )
		{
		  case 1 : 
			cout << "Opção INSERTION SORT Escolhida - 1 " << endl << endl;
			InsertionSort(_Frase, strlen(_Frase));
			break;

		  case 2 : 
			cout << "Opção SHELL SORT Escolhida - 2 " << endl << endl;
			ShellSort(_Frase, strlen(_Frase));
			break;
			
		/* case 3 : 
			cout << "Opção MERGE SORT Escolhida - 3 " << endl << endl;
			MergeSort(_Frase, strlen(_Frase));
			break;
		
		 case 4 : 
			cout << "Opção QUICK SORT Escolhida - 4 " << endl << endl;
			QuickSort(_Frase, strlen(_Frase));
			break;*/
		
		case 5 : 
			cout << "Até mais!" << endl;
			return 0;
			

		  default : 
			cout << "Opção escolhida não é valida!" << endl << endl;
			break;
		}
	}while(x != 5);
	
	return 0;
}
