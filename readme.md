# 1️⃣ Il problema che try / catch risolve (prima del codice)

Immagina questa situazione senza eccezioni:
- crei un oggetto
- qualcosa va storto (grado sbagliato)
- il programma non sa cosa fare
Senza eccezioni hai solo due scelte brutte:
- crashare
- ritornare valori strani (-1, false, ecc.)
Le eccezioni servono a dire:
“Qui è successa una cosa non valida.
Non posso continuare normalmente.
Qualcun altro deve decidere cosa fare.”
## 2️⃣ Cos’è un’eccezione (in parole semplici)
Un’eccezione è:
un oggetto speciale che rappresenta un errore serio
Non è una stringa.
Non è una printf.
È un oggetto C++.
Quando fai:
```c++
throw Qualcosa();
```
stai dicendo:
**“Sto lanciando un oggetto che descrive l’errore”**
## 3️⃣ Cosa fa try
```c++
try {
    // codice
}
```
try significa:
“Sto per eseguire del codice che POTREBBE FALLIRE.”
È come dire:
“Attenzione: qui dentro può succedere un disastro.”

## 4️⃣ Cosa fa throw
Quando il codice incontra:
```c++
throw qualcosa;
```
succedono 3 cose immediate:
* il codice si ferma lì
* le righe successive NON vengono eseguite
* il programma cerca un catch compatibile
👉 importantissimo: non torna indietro, non continua, salta via.

## 5️⃣ Cosa fa catch
```c++
catch (std::exception &e) {
    // gestione errore
}
```
catch significa:
“Se qualcuno ha lanciato un’eccezione, dammela e ci penso io.”

## 6️⃣ std::exception &e
Prendiamola pezzo per pezzo.
🔹 std::exception
È una classe base della libreria standard.
Tutte le eccezioni “normali” in C++ derivano da questa classe.

Esempio:

std::runtime_error
std::out_of_range
le tue GradeTooHighException, GradeTooLowException
👉 se derivano da std::exception, allora posso catturarle tutte con:
catch (std::exception &e)
🔹 &e (reference)
Significa:
“Non fare una copia dell’eccezione, dammi l’oggetto vero”
Perché è importante?
evita copie inutili
mantiene il tipo reale dell’eccezione
📌 Regola pratica:
Le eccezioni si catturano SEMPRE per reference.
🔹 e cosa rappresenta?
e è:
l’oggetto eccezione che è stato lanciato con throw
Esempio mentale:
throw GradeTooLowException();
Nel catch:
catch (std::exception &e)
👉 e è quell’oggetto lì

## 7️⃣ Cos’è e.what()
what() è una funzione membro di std::exception.
Ritorna:
```c++
const char*
```
cioè:
un messaggio di testo che spiega l’errore
Esempio:
```c++
std::cout << e.what() << std::endl;
```
stampa qualcosa tipo:
Grade too low
Tu decidi cosa scrive what() nelle tue eccezioni.
## 8️⃣ Tutto insieme: esempio reale, riga per riga
```c++
try {
    Bureaucrat b("Anna", 0);
    std::cout << "NON arrivo qui\n";
}
catch (std::exception &e) {
    std::cout << "Errore: " << e.what() << std::endl;
}
```
Succede questo:
- entra nel try
- chiama il costruttore
- il costruttore vede grade = 0
- fa throw GradeTooHighException();
- il try si interrompe
- entra nel catch
- e contiene l’eccezione
- e.what() stampa il messaggio
- il programma continua normalmente dopo il catch

## 9️⃣ Una frase da ricordare
try = “prova a fare”
throw = “non posso continuare”
catch = “gestisco l’errore”

## Quindi: a cosa serve what() se l’oggetto non esiste?
Quando il costruttore fa 
throw GradeTooHighException();, 
non sta “stampando” nulla.
Sta solo lanciando un oggetto-errore.
Nel catch, tu ricevi quell’oggetto come e:
```c++
catch (std::exception &e)
```
e puoi chiedergli:
```c++
e.what()
```
che è semplicemente:
“dimmi che messaggio di errore porti dentro”
what() ritorna un const char* (una stringa C) che tu stampi.

# td::exception &e

```c++
catch (std::exception &e)
```
significa:
* **std::exception**: “voglio catturare eccezioni che derivano da std::exception”
(quindi anche le tue GradeTooHighException / GradeTooLowException se le fai derivare da std::exception)
* **& (reference)**: “non farmi una copia, dammi l’eccezione originale”
(è lo standard: le eccezioni si catturano quasi sempre per reference)
* **e**: è solo il nome della variabile che rappresenta l’eccezione catturata
(potresti chiamarla anche err, ex, ecc.)

**Cosa ci fai con e?**
La cosa più comune è:
```c++
std::cout << e.what() << std::endl;
```
**what()** è una funzione di std::exception che ritorna un messaggio testuale (const char*) che descrive l’errore.

Esempio pratico:
Se nel costruttore fai:
```c++
throw GradeTooHighException();
```
e nel main hai:
```c++
catch (std::exception &e) {
    std::cout << e.what() << "\n";
}
```
allora e “contiene” proprio quell’errore, e e.what() stamperà il messaggio che hai definito per quella eccezione.

### Far derivare le tue eccezioni da std::exception ti dà 3 vantaggi enormi
+ 1) Le puoi catturare “in modo generico”
Se tutte le tue eccezioni derivano da std::exception, allora questa riga funziona per TUTTE:
```c++
catch (std::exception &e)
```
Cioè: non devi scrivere mille catch diversi ogni volta.
Senza ereditarietà, saresti costretta a fare catch specifici o catch strani (tipo catch di stringhe), ed è brutta pratica.

+ 2) Hai già un’interfaccia standard: what()
std::exception ti dà una funzione comune:
what() → “dimmi che errore è successo”
Quindi chi cattura l’eccezione sa sempre come ottenere un messaggio, anche se l’eccezione è “tua”.
Se non derivassi da std::exception, non avresti un modo standard per chiedere il messaggio.

+ 3) È polimorfismo: “tante eccezioni, una sola rete”
Tu puoi creare tante eccezioni diverse:
```c++
GradeTooHighException
GradeTooLowException
```
Ma puoi gestirle tutte con un unico catch “rete di sicurezza”:
```c++
catch (std::exception &e)
```
È come dire: “qualsiasi errore standard, lo gestisco qui”.

## LE ECCEZIONI — SPIEGAZIONE “DA AULA”
1️⃣ Il problema di fondo (prima del C++)
In programmazione succedono due tipi di problemi:
Errori normali
– input sbagliato
– file che non esiste
– valore fuori range
Errori di programmazione
– dereferenziare un puntatore nullo
– accedere fuori da un array
Le eccezioni servono al primo tipo:
quando il programma è scritto bene, ma la situazione non permette di continuare normalmente.

2️⃣ Cos’è davvero un’eccezione (concetto chiave)
Un’eccezione è un oggetto che rappresenta un problema serio,
e serve a interrompere il flusso normale del programma in modo controllato.
Non è:
una printf
un if
un valore di ritorno
È un meccanismo di controllo del flusso.

3️⃣ Chi usa le eccezioni e perché
Ci sono due ruoli distinti:
🔹 Chi scopre il problema
È una funzione / un costruttore / un metodo.
Esempio:
“Mi hai chiesto di creare un Bureaucrat con grade 0.
Questo è impossibile.”
Questa parte non deve decidere cosa fare dopo.
Deve solo segnalare il problema.
👉 Questo ruolo usa throw.

🔹 Chi decide cosa fare
È il livello più alto del programma:
main
o una funzione che controlla il flusso
Esempio:
“Ok, il Bureaucrat non si può creare.
Stampo un messaggio e continuo.”
👉 Questo ruolo usa try / catch.
4️⃣ throw: cosa fa veramente
Quando scrivi:
throw GradeTooLowException();
stai facendo tre cose precise:
Crei un oggetto di tipo GradeTooLowException
Interrompi immediatamente la funzione corrente
Passi il controllo a chi sta chiamando, cercando un catch
👉 Non ritorna, non continua, non “va avanti un po’”.
5️⃣ Cosa succede allo stack (importantissimo)
Immagina questa chiamata:
```c++
main()
 └── Bureaucrat("Anna", 0)
     └── throw GradeTooHighException()
```
il costruttore si interrompe
l’oggetto non viene creato
il programma risale lo stack
cerca un catch compatibile
Questo si chiama stack unwinding.

6️⃣ try: cosa significa
```c++
try {
    // codice
}
```
Non fa nulla di magico.
Significa solo:
“Se da qui parte un’eccezione, sono pronto a gestirla.”
È come dire:
“Attenzione: qui potrebbe succedere qualcosa di grave.”

7️⃣ catch: cosa rappresenta
```c++
catch (std::exception &e)
```
Vuol dire:
cattura qualsiasi oggetto
che è di tipo std::exception o derivato
e chiamalo e
👉 e è l’errore stesso, sotto forma di oggetto.

8️⃣ Perché si eredita da std::exception
Ora veniamo al punto cruciale.
std::exception è la classe base di tutte le eccezioni standard.
Derivare da std::exception significa:
✔️ Compatibilità
Puoi catturare tutte le tue eccezioni con:
```c++
catch (std::exception &e)
```
✔️ Polimorfismo
Tante eccezioni diverse → un solo catch
✔️ Interfaccia comune
std::exception ti garantisce:
```c++
const char* what() const;
```
cioè:
“Dimmi che errore è successo”

9️⃣ what(): cos’è davvero
what() è una funzione virtuale.
Tu la ridefinisci nelle tue eccezioni per spiegare l’errore.
Esempio concettuale:
```c++
GradeTooHighException::what() → “Grade too high”
GradeTooLowException::what() → “Grade too low”
```
Nel catch:
```c++
std::cout << e.what();
```
Tu non sai che eccezione precisa è stata lanciata,
ma sai sempre come ottenere un messaggio.


```c++
```