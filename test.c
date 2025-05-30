
#include "clienti.h"
#include "lezioni.h"
#include "prenotazioni.h"
#include "date.h"
#include <stdio.h>

void testPrenotazioneEDisponibilita() {
    printf("\n--- TEST: Prenotazione e disponibilità ---\n");
    inizializzaClienti();
    inizializzaLezioni();
    inizializzaPrenotazioni();

    int id_cliente = aggiungiCliente("Mario", "Rossi", 3);
    date d = {1, 6, 2025};
    int id_lezione = aggiungiLezione("Yoga", "10:00", 2, d);

    aggiungiPrenotazione(id_cliente, id_lezione);
    aggiungiPrenotazione(id_cliente, id_lezione);
    aggiungiPrenotazione(id_cliente, id_lezione);
    aggiungiPrenotazione(id_cliente, id_lezione);

    visualizzaDisponibilita();
}

void testAbbonamenti() {
    printf("\n--- TEST: Validità abbonamento ---\n");
    inizializzaClienti();

    int id1 = aggiungiCliente("Luigi", "Bianchi", 1);
    int id2 = aggiungiCliente("Anna", "Verdi", 0);

    printf("Abbonamento cliente %d valido? %s\n", id1,
           verificaValiditaAbbonamento(id1) ? "SI" : "NO");
    printf("Abbonamento cliente %d valido? %s\n", id2,
           verificaValiditaAbbonamento(id2) ? "SI" : "NO");
}

void testReport() {
    printf("\n--- TEST: Generazione report ---\n");
    inizializzaClienti();
    inizializzaLezioni();
    inizializzaPrenotazioni();

    int c1 = aggiungiCliente("Giulia", "Neri", 5);
    int c2 = aggiungiCliente("Marco", "Blu", 2);

    date d = {2, 6, 2025};
    int l1 = aggiungiLezione("Pilates", "09:00", 5, d);
    int l2 = aggiungiLezione("Boxe", "18:00", 5, d);

    aggiungiPrenotazione(c1, l1);
    aggiungiPrenotazione(c1, l2);
    aggiungiPrenotazione(c2, l1);

    generaReport();
}

int main() {
    testPrenotazioneEDisponibilita();
    testAbbonamenti();
    testReport();

    return 0;
}
