
/* Funzione inizializzaClienti()

	SPECIFICA SINTATTICA: void inizializzaClienti()
	TIPI: void
	
	SPECIFICA SEMANTICA: inizializzaClienti() -> void
	
	Pre-condizioni:
	- Deve esistere il puntatore testa_clienti che punta alla lista clienti
	- Deve esistere la funzione liberaClienti() per la deallocazione della memoria
	
	Post-condizioni:
	- La lista dei clienti viene impostata a Null
	- Il contatore degli Id viene resettato a 1
	- Tutta la memoria precedentemente allocata viene liberata
	
	REALIZZAZIONE:
	1 Chiama liberaClienti() per deallocare la memoria dedicata ad ogni cliente
	2 Resetta il puntatore alla lista dei clienti
	3 Resetta il contatore degli Id
	
	CODICE:
	void inizializzaClienti() {
    liberaClienti();
    testa_clienti = NULL;
    prossimo_id = 1;
}

*/


/* Funzione aggiungiCliente()
	SPECIFICA SINTATTICA: int aggiungiCliente(const char* nome, const char* cognome, int giorni_abbonamento)
	TIPI: int, char
	
	SPECIFICA SEMANTICA: aggiungiCliente(nome, cognome, giorni_abbonamento) -> int
	
	Pre-condizioni:
	- Nome e Cognome devono essere stringhe valide;
	- Nome e Cognome devono rientrare nella dimensione prestabilita;
	- Testa_clienti deve essere un puntatore valido, inizializzato a NUll se la lista è vuota;
	
	Post-condizioni:
	- In caso che la funzione riscontri successo un nuovo cliente viene aggiunto alla testa della lista, con il proprio Id, con la copia del nome e del cognome dati in input e con i propri giorni d'abbonamento;
	- In caso di fallimento lal ista rimane invariata
	
	
	
	REALIZZAZIONE:
	1 Controlla se ci sono errori inerenti alla memoria
	2 Aggiunge un nuovo cliente a una lista collegata di clienti.
	3 Alloca spazio per ogni cliente ed ad ogni cliente viene attribuito:
		- Id univoco;
		- Nome;
		- Cognome;
		- Giorni d'abbonamento;
	4 Aggiunge il cliente alla lista, con i propri dati e stampa un messaggio per confermare
	
	CODICE:
	int aggiungiCliente(const char* nome, const char* cognome, int giorni_abbonamento) {
    if (giorni_abbonamento <= 0) {
        printf("Errore: durata abbonamento non valida.\n");
        return -1;
    }

    Cliente* nuovo = malloc(sizeof(Cliente));
    if (!nuovo) {
        printf("Errore di memoria.\n");
        return -1;
    }

    nuovo->id = prossimo_id++;
    strncpy(nuovo->nome, nome, sizeof(nuovo->nome));
    strncpy(nuovo->cognome, cognome, sizeof(nuovo->cognome));
    nuovo->giorni_abbonamento = giorni_abbonamento;
    nuovo->next = testa_clienti;
    testa_clienti = nuovo;

    printf("Cliente aggiunto con ID %d.\n", nuovo->id);
    return nuovo->id;
}
	
	*/

/*Funzione verificaAbbonamenti()
	
	SPECIFICA SINTATTICA: void verificaAbbonamenti()
	TIPI: void
	
	SPECIFICA SEMANTICA: verificaAbbonamenti() -> void
	
	Pre-condizioni;
	- La lista dei clienti deve essere correttamente inizializzata;
	- I campi dei clienti devono essere validi.
	
	Post-condizioni:
	- Se la lista è vuota stampa un errore e non modifica la lista;
	- Se la lista contiene dei clienti ne stampa i dati e non modifica la lista;
	
	1 Verifica se all'interno della lista esiste almeno un cliente, se la lista è vuota stampa un errore
	2 Scorre la lista stampando rispettivamente ogni cliente con i propri dati, cioè:
	- Nome;
	- Cognome;
	- Giorni d'abbonamento rimanenti;
	Per poi passare al prossimo cliente.
	
	CODICE:
	void verificaAbbonamenti() {
    printf("\n--- Stato Abbonamenti ---\n");
    Cliente* curr = testa_clienti;
    
    if (!curr) {
        printf("Nessun cliente registrato.\n");
        return;
    }

    while (curr) {
        printf("\nCliente %d: %s %s | Giorni restanti: %d\n",
               curr->id, curr->nome, curr->cognome, curr->giorni_abbonamento);
        curr = curr->next;
    }
}
	
	*/

/*Funzione verificaValiditaAbbonamento()
	
	SPECIFICA SINTATTICA: int verificaValiditaAbbonamento(int id_cliente)
	TIPI: int
	
	SPECIFICA SEMANTICA: verificaValiditaAbbonamento(id_cliente) -> int
	
	Pre-condizioni:
	- Id-cliente deve essere un intero valido;
	- la lista dei clienti può essere vuota, se non è Null ogni next deve puntare al cliente successivo.
	
	Post- condizioni:
	- Restituisce 1 se il cliente esiste ed il suo abbonamento è valido;
	- Restituisce 0 se il cliente non esiste oppure il cliente esiste ma il suo abbonamento è scaduto;
	- Non modifica ne la lista ne i dati del cliente.
	
	REALIZZAZIONE:
	Verifica se l'abbonamento di un cliente è ancora valido cercandolo tramite l'id cliente.
	1 Scorre la lista dei clienti e restituisce:
		- 1 se giorni_abbonamenti > 0;
		- 0 se giorni_abbonamento <=0;
	
	CODICE:
	int verificaValiditaAbbonamento(int id_cliente) {
    Cliente* curr = testa_clienti;
    while (curr) {
        if (curr->id == id_cliente)
            return curr->giorni_abbonamento > 0;
        curr = curr->next;
    }
    return 0;
}
	*/

/*Funzione stampaListaClienti()
	
	SPECIFICA SINTATTICA: void stampaListaClienti()
	TIPI: void
	
	SPECIFICA SEMANTICA: stampaListaClienti() -> void
	
	Pre-condizioni:
	-testa_clienti deve essere un puntatore valido;
	- I campi dei clienti devono essere validi.

	Post-condizioni:
	- Se la lista è vuota stampa un messaggio e non modifica la lista;
	- Se la lista contiene dei clienti ne stampa i dati e non modifica la lista.
	
	REALIZZAZIONE
	1 Verifica se la lista è vuota, se lo è stampa un messaggio d'errore
	2 Scorre tutta la lista dei clienti e stampa una lista formattata di tutti i clienti registrati, mostrando per ciascun cliente:
		- Id;
		- Nome;
		- Cognome;
	
	
	CODICE:
	void stampaListaClienti() {
    Cliente* corrente = testa_clienti;
    
    printf("\n--- LISTA COMPLETA CLIENTI ---\n");
    
    if (!corrente) {
        printf("Nessun cliente registrato.\n");
        return;
    }
    
    printf("%-5s %-20s %-20s\n", "ID", "NOME", "COGNOME");
    printf("----------------------------------------\n");
    
    while (corrente) {
        printf("%-5d %-20s %-20s\n", 
               corrente->id, corrente->nome, corrente->cognome);
        corrente = corrente->next;
    }
}
	

*/

/*Funzione liberaClienti()

	SPECIFICA SINTATTICA: void liberaClienti()
	TIPI: void
	
	SPECIFICA SEMANTICA: liberaCLieenti() -> void
	
	Pre-condizioni:
	- testa_clienti deve essere un puntatore valido;
	
	Post-condizioni:
	- Tutta la memoria inerente ai nodi è stata deallocata;
	- testa_clienti è impostata a Null;
	- la funzione non restituisce nessun valore ma modifica lo stato della lista.
	
	REALIZZAZIONE:
	1 Parte dal puntatore testa_clienti, usando un ciclo while scorre tutta la lista.
	2 Libera tutta la memoria allocata per la lista dei clienti e imposta testa_clienti a Null per indicare che la lista è vuota.
	
	
	CODICE:
	void liberaClienti() {
    Cliente* curr = testa_clienti;
    while (curr) {
        Cliente* temp = curr;
        curr = curr->next;
        free(temp);
    }
    testa_clienti = NULL;
}


*/




#include "clienti.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Cliente* testa_clienti = NULL;    // Testa della lista clienti
static int prossimo_id = 1;              // Contatore per gli ID clienti

// Inizializza la lista clienti
void inizializzaClienti() {
    liberaClienti();
    testa_clienti = NULL;
    prossimo_id = 1;
}

// Aggiunge un nuovo cliente alla lista
int aggiungiCliente(const char* nome, const char* cognome, int giorni_abbonamento) {
    if (giorni_abbonamento <= 0) {
        printf("Errore: durata abbonamento non valida.\n");
        return -1;
    }

    Cliente* nuovo = malloc(sizeof(Cliente));
    if (!nuovo) {
        printf("Errore di memoria.\n");
        return -1;
    }

    nuovo->id = prossimo_id++;
    strncpy(nuovo->nome, nome, sizeof(nuovo->nome));
    strncpy(nuovo->cognome, cognome, sizeof(nuovo->cognome));
    nuovo->giorni_abbonamento = giorni_abbonamento;
    nuovo->next = testa_clienti;
    testa_clienti = nuovo;

    printf("Cliente aggiunto con ID %d.\n", nuovo->id);
    return nuovo->id;
}

// Visualizza lo stato degli abbonamenti di tutti i clienti
void verificaAbbonamenti() {
    printf("\n--- Stato Abbonamenti ---\n");
    Cliente* curr = testa_clienti;
    
    if (!curr) {
        printf("Nessun cliente registrato.\n");
        return;
    }

    while (curr) {
        printf("\nCliente %d: %s %s | Giorni restanti: %d\n",
               curr->id, curr->nome, curr->cognome, curr->giorni_abbonamento);
        curr = curr->next;
    }
}



// Verifica se un cliente ha un abbonamento valido
int verificaValiditaAbbonamento(int id_cliente) {
    Cliente* curr = testa_clienti;
    while (curr) {
        if (curr->id == id_cliente)
            return curr->giorni_abbonamento > 0;
        curr = curr->next;
    }
    return 0;
}

void stampaListaClienti() {
    Cliente* corrente = testa_clienti;
    
    printf("\n--- LISTA COMPLETA CLIENTI ---\n");
    
    if (!corrente) {
        printf("Nessun cliente registrato.\n");
        return;
    }
    
    printf("%-5s %-20s %-20s\n", "ID", "NOME", "COGNOME");
    printf("----------------------------------------\n");
    
    while (corrente) {
        printf("%-5d %-20s %-20s\n", 
               corrente->id, corrente->nome, corrente->cognome);
        corrente = corrente->next;
    }
}

// Libera la memoria occupata dalla lista clienti
void liberaClienti() {
    Cliente* curr = testa_clienti;
    while (curr) {
        Cliente* temp = curr;
        curr = curr->next;
        free(temp);
    }
    testa_clienti = NULL;
}