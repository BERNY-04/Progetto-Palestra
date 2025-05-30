
/*Funzione inizializzaLezioni()
	SPECIFICA SINTATTICA: void inizializzaLezioni()
	TIPI: Void.

	SPECIFICA SEMANTICA: inizializzaLezioni()void;
	PRECONDIZIONI: 
	- Esiste la procedura “liberaLezione()”;
	- Esistono e sono dichiarati i dati “testa_lezioni” e “prossimo_id_lezione”.
	POSTCONDIZIONI: Vengono inizializzati i dati “testa_lezioni” e “prossimo_id_lezione”.

	REALIZZAZIONE
	1 Richiamiamo la funzione “libera_Lezioni()”;
	2 Inizializziamo a NULL il dato “testa_lezioni”;
	3 Inizializziamo a 1 il dato “prossimo_id_lezione”;

	CODICE
	void inizializzaLezioni() {
		liberaLezioni();
		testa_lezioni = NULL;
		prossimo_id_lezione = 1;
	}

*/

/* Funzione aggiungiLezione()
	SPECIFICA SINTATTICA: int aggiungiLezione(const char* nome, const char* orario, int max_partecipanti, date data)
	TIPI: int, char, date.

	SPECIFICA SEMANTICA: aggiungiLezione(nome, orario, max_partecipanti, data)void
	PRECONDIZIONI: I dati “nome”, “orario”, “max_partecipanti” e “data” sono dati esistenti.
	POSTCONDIZIONI:

	REALIZZAZIONE
	1 Controlliamo se “max_partecipanti” è minore o uguale a 0; se il controllo risulta vero, stampiamo una scritta di errore.
	2 Facciamo un controllo per verificare se la data inserita è una data esistente, se così non fosse, stampiamo un messaggio di errore.
	3 Facciamo un controllo per verificare se c’è spazio per registrare una lezione, se così non fosse, stampiamo un messaggio di errore. 
	4 Inizializziamo la nuova lezione, e stampiamo un messaggio per dire ciò è avvenuto con successo, mostrando anche l’ID della lezione stessa.

	CODICE
	int aggiungiLezione(const char* nome, const char* orario, int max_partecipanti, date data) {
    // Validazione input
    if (max_partecipanti <= 0) {
        printf("Errore: numero massimo partecipanti non valido.\n");
        return -1;
    }

    // Validazione data (semplificata)
    if (data.aa < 2023 || data.mm < 1 || data.mm > 12 || data.gg < 1 || data.gg > 31) {
        printf("Errore: data non valida.\n");
        return -1;
    }

    LezioneFitness* nuova = malloc(sizeof(LezioneFitness));
    if (!nuova) {
        printf("Errore di memoria.\n");
        return -1;
    }

    // Inizializzazione nuova lezione
    nuova->id = prossimo_id_lezione++;
    strncpy(nuova->nome, nome, sizeof(nuova->nome));
    strncpy(nuova->orario, orario, sizeof(nuova->orario));
    nuova->max_partecipanti = max_partecipanti;
    nuova->prenotati = 0;
    nuova->data = data;
    nuova->next = testa_lezioni;
    testa_lezioni = nuova;

    printf("Lezione aggiunta con ID %d.\n", nuova->id);
    return nuova->id;
}

*/


/*  Funzione visualizzaDisponibilita()
	SPECIFICA SINTATTICA: void visualizzaDisponibilita().
	TIPI: Void.

	SPECIFICA SEMANTICA: visualizzaDisponibilita()void
	PRECONDIZIONI: Esistono i dati “curr” e “testa_lezioni”;
	POSTCONDIZIONI: Assegniamo alla variabile “curr” il valore della variabile “testa_lezioni”.

	REALIZZAZIONE:
	1 Assegniamo alla variabile “curr” il valore della variabile “testa_lezioni”;
	2 Controlliamo se esiste una lezione disponibile; se esiste stampiamo le informazione inerenti alla lezione, altrimenti stampiamo un messaggio di errore.

	CODICE
	void visualizzaDisponibilita() {
    printf("\n--- Disponibilità Lezioni ---\n");
    LezioneFitness* curr = testa_lezioni;
    
    if (!curr) {
        printf("Nessuna lezione disponibile.\n");
        return;
    }

    while (curr) {
        printf("ID: %d | %s alle %s | Posti: %d/%d | Data: %02d/%02d/%d\n",
               curr->id, curr->nome, curr->orario, curr->prenotati,
               curr->max_partecipanti, curr->data.gg, curr->data.mm, curr->data.aa);
        curr = curr->next;
    }
}



*/


/*	Funzione verificaPostiDisponibili()
	SPECIFICA SINTATTICA: int verificaPostiDisponibili(int id_lezione)
	TIPI: Int.

	SPECIFICA SEMANTICA: verificaPostiDisponibili(id_lezione)void;
	PRECONDIZIONI: Esistono i dati “curr” e “testa_lezioni”;
	POSTCONDIZIONI:

	REALIZZAZIONE:
	1 Scorre la lista delle lezioni
	2 Per ogni elemento, verifica se l'ID corrisponde a quello cercato
	3 Se trova corrispondenza confronta prenotati con max_partecipanti

	CODICE
	int verificaPostiDisponibili(int id_lezione) {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        if (curr->id == id_lezione) {
            return curr->prenotati < curr->max_partecipanti;
        }
        curr = curr->next;
    }
    return 0;
}


*/


/*	Funzione incrementaPrenotati()
	SPECIFICA SINTATTICA: int incrementaPrenotati(int id_lezione).
	TIPI: Int.

	SPECIFICA SEMANTICA: incrementaPrenotati(id_lezione) Void;
	PRECONDIZIONI: Esistono i dati “curr” e “testa_lezioni”;
	POSTCONDIZIONI: Variabile prenotati viene incrementata se la funzione va a buon fine

	REALIZZAZIONE
	1 Facciamo un controllo per verificare se è possibile prenotarsi a lezione, se così fosse, incrementiamo di 1 i prenotati.

	CODICE
	int incrementaPrenotati(int id_lezione) {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        if (curr->id == id_lezione && curr->prenotati < curr->max_partecipanti) {
            curr->prenotati++;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}


*/


/*	Funzione liberaLezioni()
	SPECIFICA SINTATTICA: void liberaLezioni().
	TIPI: Void.

	SPECIFICA SEMANTICA: liberalezioni() void;
	PRECONDIZIONI: Esistono i dati “curr” e “testa_lezioni”;
	POSTCONDIZIONI: Il dato “testa_lezioni” viene inizializzato a NULL.

	REALIZZAZIONE: 
	1 Scorre tutta la lista lezioni
	2 Salva il nodo attuale in una variabile temporanea
	3 Passa al prossimo nodo
	4 Libera la variabile temporanea, così da liberare tutta la memoria
	CODICE
	void liberaLezioni() {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        LezioneFitness* temp = curr;
        curr = curr->next;
        free(temp);
    }
    testa_lezioni = NULL;
}



*/






#include "lezioni.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static LezioneFitness* testa_lezioni = NULL;    // Testa della lista lezioni
static int prossimo_id_lezione = 1;             // Contatore per gli ID lezioni

// Inizializza la lista lezioni
void inizializzaLezioni() {
    liberaLezioni();
    testa_lezioni = NULL;
    prossimo_id_lezione = 1;
}

// Aggiunge una nuova lezione alla lista
int aggiungiLezione(const char* nome, const char* orario, int max_partecipanti, date data) {
    // Validazione input
    if (max_partecipanti <= 0) {
        printf("Errore: numero massimo partecipanti non valido.\n");
        return -1;
    }

    // Validazione data (semplificata)
    if (data.aa < 2023 || data.mm < 1 || data.mm > 12 || data.gg < 1 || data.gg > 31) {
        printf("Errore: data non valida.\n");
        return -1;
    }

    LezioneFitness* nuova = malloc(sizeof(LezioneFitness));
    if (!nuova) {
        printf("Errore di memoria.\n");
        return -1;
    }

    // Inizializzazione nuova lezione
    nuova->id = prossimo_id_lezione++;
    strncpy(nuova->nome, nome, sizeof(nuova->nome));
    strncpy(nuova->orario, orario, sizeof(nuova->orario));
    nuova->max_partecipanti = max_partecipanti;
    nuova->prenotati = 0;
    nuova->data = data;
    nuova->next = testa_lezioni;
    testa_lezioni = nuova;

    printf("Lezione aggiunta con ID %d.\n", nuova->id);
    return nuova->id;
}

// Visualizza tutte le lezioni con disponibilità
void visualizzaDisponibilita() {
    printf("\n--- Disponibilità Lezioni ---\n");
    LezioneFitness* curr = testa_lezioni;
    
    if (!curr) {
        printf("Nessuna lezione disponibile.\n");
        return;
    }

    while (curr) {
        printf("ID: %d | %s alle %s | Posti: %d/%d | Data: %02d/%02d/%d\n",
               curr->id, curr->nome, curr->orario, curr->prenotati,
               curr->max_partecipanti, curr->data.gg, curr->data.mm, curr->data.aa);
        curr = curr->next;
    }
}

// Verifica se ci sono posti disponibili per una lezione
int verificaPostiDisponibili(int id_lezione) {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        if (curr->id == id_lezione) {
            return curr->prenotati < curr->max_partecipanti;
        }
        curr = curr->next;
    }
    return 0;
}

// Incrementa il contatore dei prenotati per una lezione
int incrementaPrenotati(int id_lezione) {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        if (curr->id == id_lezione && curr->prenotati < curr->max_partecipanti) {
            curr->prenotati++;
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}

// Libera la memoria occupata dalla lista lezioni
void liberaLezioni() {
    LezioneFitness* curr = testa_lezioni;
    while (curr) {
        LezioneFitness* temp = curr;
        curr = curr->next;
        free(temp);
    }
    testa_lezioni = NULL;
}