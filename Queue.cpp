/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

//Creazione della struct per la formazione della queue
struct cell 
{ 
	int value = 0;			
	cell *next = nullptr;	
};

//Creazione di una seconda struct per una più facile gestione della queue
struct queue
{ 
	cell *firstItem = nullptr;	
	cell *lastItem = nullptr;	
};

//Funzione per aggiungere una cella nella queue
void AddItem(queue *&queue, int n)
{
    //Passaggio del valore come parametro
	cell *newCell = new cell;
	newCell -> value = n;

    //Istanza se la cella creata è l'unica della queue, in quel caso sarà sia la prima che l'ultima
	if(queue -> firstItem == nullptr)
	{
		queue -> firstItem = newCell;
		queue -> lastItem = newCell;
	}
	
	//Istanza se la cella creata non è l'unica della queue
	else if(queue -> firstItem != nullptr)
	{
		queue -> lastItem -> next = newCell;		
		queue -> lastItem = newCell;			
	}
}

//Funzione per la rimozione della prima cella dalla queue
int RemoveItem(queue *&queue)
{
	int value = queue -> firstItem -> value;
	
	//Salvataggio del primo valore della queue in una cella temporanea che successivamente verrà cancellata
	cell *tmp = queue -> firstItem;		
	queue -> firstItem = queue -> firstItem -> next;
	delete tmp;
	
	//Ritorno del valore eliminato
	return value;
}

//Funzione per la determinazione della lunghezza della queue
int QueueLength(queue *&queue)
{
    //Variabile per il conteggio di celle
	int length;
	
	//Istanza se la queue è vuota
	if (queue -> firstItem == nullptr)	
	{
		return 0;
	}
	
	//Conteggio delle celle presenti nella queue utilizzando una cella temporanea
	for (cell *tmp = queue -> firstItem; tmp != nullptr; tmp = tmp -> next)
	{
		length++;		
	}
	return length;
}


//Funzione per dare in output l'intera queue
void PrintQueue(queue *&queue)
{
    //Inizializzazione di una variabile indice e ciclo per l'output di tutti i valori della queue messi in ordine
	int i = 0;
	for (cell* tmp = queue -> firstItem; tmp != nullptr; tmp = tmp -> next)
	{
	    cout << "Cella " << i << ": " << tmp -> value << "\n";
		i++;
	}
}

//Funzione per la cancellazione della coda
void Delete(queue *&queue)
{
	int length = QueueLength(queue);
	
	//Ciclo per la rimozione di tutti i valori della queue
	for (int i = 0; i < length; i++)
	{
		RemoveItem(queue);			
	}
}

int main()
{
	queue *coda = new queue;
	AddItem(coda, 1);
	AddItem(coda, 2);
	AddItem(coda, 3);
	PrintQueue(coda);
	cout << "\n";
	AddItem(coda, 4);
	PrintQueue(coda);
	cout << "\n";
	RemoveItem(coda);
	RemoveItem(coda);
	PrintQueue(coda);
	QueueLength(coda);
	Delete(coda);
	PrintQueue(coda);

    return 0;
}