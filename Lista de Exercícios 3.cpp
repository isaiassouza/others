#include<bits/stdc++.h>
using namespace std;

string NumerosRomanos[15] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV"};
int contChamadas_merge, contInstrucoesMergeSort;

void ImprimeVetorSeparadoPorEspacos(char _Vetor[], int tamVet, int NumeroDeElementosAgrupados, int PosInicial = 0)
{																//Controle para construir subgrupos, necessário no Merge Sort
	int ContNumerodeCasasImpressos = 0;
	for(int i = PosInicial; i < tamVet; i++)
	{
		cout << _Vetor[i];
		ContNumerodeCasasImpressos++;
		//Controle para construir subgrupos, necessário no Merge Sort
		if(ContNumerodeCasasImpressos == NumeroDeElementosAgrupados) 
		{
			cout << "  ";
			ContNumerodeCasasImpressos = 0;
		}
		else
			cout << ' ';
	}
		
	
	cout << endl;		
}

void InsertionSort(char _Vetor[], int tam)
{
	int j, ContSubInstrucoes;
	char atual;
	
	cout << "--Vetor que será trabalhado: ";
	ImprimeVetorSeparadoPorEspacos(_Vetor, tam, tam);
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
		ImprimeVetorSeparadoPorEspacos(_Vetor, tam, tam);
		cout << endl;
	}
	cout << "--Vetor Ordenado: ";
	ImprimeVetorSeparadoPorEspacos(_Vetor, tam, tam);
}

void ShellSort(char _Vetor[], int tam)
{
	int j, Aux, ContSubInstrucoes = 1, Pulo = tam / 2;
	
	cout << "--Vetor que será trabalhado: ";
	ImprimeVetorSeparadoPorEspacos(_Vetor, tam, tam);
	cout << endl;
	
	while(Pulo > 0)
	{
		if(Pulo != 1)
			cout << "	" << ContSubInstrucoes << "	Começando a comparação, entre " << Pulo << " posições" << endl;
		else
			cout << "	" << ContSubInstrucoes << "	Ultima lote de verificação, similar ao Insertion Sort!" << endl;
			
		ContSubInstrucoes++;
		
		for(int i = Pulo; i < tam; i++)
		{
			Aux = _Vetor[i];
			j = i;
			while( (j >= Pulo) and (_Vetor[j - Pulo] > Aux) )
			{	
				_Vetor[j] = _Vetor[j - Pulo];
				j = j - Pulo;
			}
			_Vetor[j] = Aux;	
			
			if(i != j)
				cout << "	" << ContSubInstrucoes <<  "	Foram trocados os conteúdos das posições [" << i << ", " << j << "]" << 
				", os caracteres {'" << _Vetor[i] << "', '" << _Vetor[j] << "'" << "'}" << endl;
			else
				cout << "	" << ContSubInstrucoes<< "	Não houve troca pois '" << _Vetor[i] << "' esta na posição certa [" << i << "], pois é maior que " <<
				"[" << j-Pulo << "] '" << _Vetor[j - Pulo] << "'" << endl;
					
			ContSubInstrucoes++;
			
			cout  << "	" << "--Atualização: ";
			ImprimeVetorSeparadoPorEspacos(_Vetor, tam, tam);
			cout << endl;
		}
		Pulo /= 2;
		
		if(Pulo > 0)
		{
			cout << "--Vetor Atualmente: ";
			ImprimeVetorSeparadoPorEspacos(_Vetor, tam, tam);
			cout << endl;
		}
		else
		{
			cout << "--Vetor Final Ordenado: ";
			ImprimeVetorSeparadoPorEspacos(_Vetor, tam, tam);
		}
	}
}

void merge(char _Vetor[], int Inicio, int PosMeio, int Final)
{
	int PosInicioFixa = Inicio; 
	int meio = PosMeio - 1;
	int n = Final - PosInicioFixa + 1;
	int i = 0;
	char _VetorTemp[n];
	
	// Se haver ordenação nesta chamada
	if(n != Inicio)
	{
		cout << "	" << contInstrucoesMergeSort << "-Ordenando Sub Vetor: ";
		contInstrucoesMergeSort++;
		ImprimeVetorSeparadoPorEspacos(_Vetor, n, n, Inicio);
		cout << endl;
	}
	else
	{
		cout << "	" << contInstrucoesMergeSort << "-Nesta chamada do merge não houve ordenação." << endl;
		contInstrucoesMergeSort++;
	}
		
	while( (Inicio <= meio) and (PosMeio <= Final) )
	{
		if(_Vetor[Inicio] < _Vetor[PosMeio])
		{
			_VetorTemp[i] = _Vetor[Inicio];
			
			cout << "	" << contInstrucoesMergeSort << "-A primeira metade do vetor tem um char menor que a segunda 		: (" << Inicio << ")'" 
			<< _Vetor[Inicio] << "' <  (" << PosMeio << ")'" << _Vetor[PosMeio] << "'" <<  endl;
			contInstrucoesMergeSort++;
			
			Inicio++;
			i++;
		} 
		else
		{
			_VetorTemp[i] = _Vetor[PosMeio];
			
			cout << "	" << contInstrucoesMergeSort << "-A primeira metade do vetor tem um char maior ou igual que a segunda : (" << Inicio << ")'" 
			<< _Vetor[Inicio] << "' >= (" << PosMeio << ")'" << _Vetor[PosMeio] << "'" <<  endl;
			contInstrucoesMergeSort++;
			
			PosMeio++;
			i++;
		}
	}
	
	// Preenche o vetor temporario analisado do inicio até o meio
	while(Inicio <= meio)
	{
		_VetorTemp[i] = _Vetor[Inicio];
		Inicio++;
		i++;
	}
	
	// Preenche o vetor analisado do meio até o final
	while(PosMeio <= Final)
	{
		_VetorTemp[i] = _Vetor[PosMeio];
		PosMeio++;
		i++;        
	}
	
	cout << endl;
	
	for(int j = 0; j < n; j++)
	{
		cout << "	" << contInstrucoesMergeSort <<  "-Foram trocados do vetor original e o vetor temporario respectivamente os conteúdos das posições [" 
		<< PosInicioFixa + j << ", " << j << "]" << ", os caracteres {'" << _Vetor[PosInicioFixa + j] << "', '" << _VetorTemp[j] << "'" << "'}" << endl;
		contInstrucoesMergeSort++; 
		_Vetor[PosInicioFixa + j] = _VetorTemp[j];
	}
	
	cout << " " << NumerosRomanos[contChamadas_merge] << " --Vetor Ordenado na " << contChamadas_merge + 1 << "ª chamada do merge: ";
	contChamadas_merge++;
	ImprimeVetorSeparadoPorEspacos(_Vetor, strlen(_Vetor), strlen(_Vetor));
	cout << endl;
}

void MergeSort(char _Vetor[], int Inicio, int Final) 
{
	int Meio;
	//chama até que tenha n vetores, do tamanho do vetor, com um elemento
	if(Inicio == Final) 
		return;
	else
	{
		Meio = (Inicio + Final) / 2;
		cout << "	" << contInstrucoesMergeSort << "-Dividindo vetor em sub-vetores de " << Meio << " posições" << endl;
		contInstrucoesMergeSort++;
		cout << "	";
		
		ImprimeVetorSeparadoPorEspacos(_Vetor, strlen(_Vetor), Meio);
		MergeSort(_Vetor, Inicio, Meio);
		MergeSort(_Vetor, Meio + 1, Final);
		merge(_Vetor , Inicio, Meio + 1, Final);
	}
}

int main()
{
	int x;
	
	do
	{
		char _Frase[] = {'U', 'M', 'D', 'O', 'I', 'S'};
		
		cout << endl << "Escolha qual o método de ordenação para ser demonstrado em '";
		ImprimeVetorSeparadoPorEspacos(_Frase, strlen(_Frase), strlen(_Frase));
		
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
			
		case 3 : 
			cout << "Opção MERGE SORT Escolhida - 3 " << endl << endl;
			
			cout << "--Vetor que será trabalhado: ";
			ImprimeVetorSeparadoPorEspacos(_Frase, strlen(_Frase), strlen(_Frase));
			cout << endl;
			
			contChamadas_merge = 0;
			contInstrucoesMergeSort = 1;
			
			MergeSort(_Frase, 0, strlen(_Frase) - 1);
			break;
	/* 	
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
