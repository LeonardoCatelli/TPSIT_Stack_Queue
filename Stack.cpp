/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

//Creazione della struct per la formazione dello stack
struct cell
{
//Inizializzazione dei campi della struct
  char value;
  cell * next = nullptr;
};

//Creazione e inserimento del valore nella nuova cella
void Aggiungi(cell *&r, char val, int &counter)
{
    cell *newCell = new cell;
    newCell -> value = val;
    newCell -> next = r;
    r = newCell;
    counter++;
}

//Rimozione di tutti gli elementi dello stack
void RimuoviTutto(cell *&r, int counter)
{
  for(int i = 0; i < counter; i++)
  {
    cell *temp = r;
    r = temp -> next;
    delete(temp);
  }
}

//Rimozione di un elemento
void Rimuovi(cell *&r, int &counter)
{
    cell *temp = r;
    r = temp->next;
    delete(temp);
    counter--;
}

//Stampo i valori di tutte le celle dello stack
void StampaTutto(cell * r)
{
  for(cell* i = r; i != nullptr; i = i->next) 
    cout << i -> value;
}

int main()
{
  cell *r = nullptr;
  int n_celle = 0;
  Aggiungi(r, 'O', n_celle);
  Aggiungi(r, 'D', n_celle);
  Aggiungi(r, 'R', n_celle);
  Aggiungi(r, 'A', n_celle);
  Aggiungi(r, 'N', n_celle);
  Aggiungi(r, 'O', n_celle);
  Aggiungi(r, 'E', n_celle);
  Aggiungi(r, 'L', n_celle);
  Aggiungi(r, ' ', n_celle);
  Aggiungi(r, 'I', n_celle);
  Aggiungi(r, 'L', n_celle);
  Aggiungi(r, 'L', n_celle);
  Aggiungi(r, 'E', n_celle);
  Aggiungi(r, 'T', n_celle);
  Aggiungi(r, 'A', n_celle);
  Aggiungi(r, 'C', n_celle);
  cout << "Numero di celle: " << n_celle << "\n";
  StampaTutto(r);
}
