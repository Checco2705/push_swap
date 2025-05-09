# 🎮 Push Swap

## 📝 Descrizione
Push Swap è un progetto che implementa un algoritmo di ordinamento utilizzando due stack e un set limitato di operazioni. Il programma prende in input una lista di numeri interi e li ordina utilizzando le operazioni di push, swap e rotate.

## 🎯 Obiettivo
L'obiettivo è ordinare i numeri utilizzando il minor numero possibile di operazioni, dimostrando efficienza e ottimizzazione nell'implementazione.

## ⚡ Operazioni Disponibili
| Operazione | Descrizione |
|------------|-------------|
| `sa` | 🔄 Scambia i primi due elementi dello stack A |
| `sb` | 🔄 Scambia i primi due elementi dello stack B |
| `ss` | 🔄 Esegue `sa` e `sb` contemporaneamente |
| `pa` | ➡️ Sposta il primo elemento da B ad A |
| `pb` | ⬅️ Sposta il primo elemento da A a B |
| `ra` | 🔄 Ruota lo stack A verso l'alto |
| `rb` | 🔄 Ruota lo stack B verso l'alto |
| `rr` | 🔄 Esegue `ra` e `rb` contemporaneamente |
| `rra` | 🔄 Ruota lo stack A verso il basso |
| `rrb` | 🔄 Ruota lo stack B verso il basso |
| `rrr` | 🔄 Esegue `rra` e `rrb` contemporaneamente |

## 📁 Struttura del Progetto

### 🎯 File Principali
- `main_sorter.c` 🧠 - Contiene la funzione principale che gestisce l'ordinamento
- `main_sorter.h` 📋 - Header file con tutte le definizioni e prototipi delle funzioni

### 📥 Gestione degli Input
- `args_parser.c` 🔍 - Parsing degli argomenti da riga di comando
- `input_validation.c` ✅ - Validazione degli input
- `arg_helper.c` 🛠️ - Funzioni di supporto per la gestione degli argomenti

### 📊 Operazioni sugli Stack
- `stack_ops.c` ⚙️ - Implementazione delle operazioni base sugli stack
- `elem_list.c` 📝 - Gestione della lista collegata per gli elementi dello stack

### 🔄 Algoritmi di Ordinamento
- `small_sort.c` 🔢 - Ordinamento per stack di dimensione ≤ 3
- `sort_three_utils.c` 🛠️ - Funzioni di supporto per l'ordinamento di 3 elementi
- `sort_four_five.c` 🔢 - Ordinamento ottimizzato per 4 e 5 elementi
- `chunk_sort.c` 📊 - Algoritmo principale per stack di grandi dimensioni
- `chunk_utils.c` 🛠️ - Funzioni di supporto per l'algoritmo chunk sort

### 🛠️ Utilità
- `sort_utils.c` 🔧 - Funzioni di supporto per l'ordinamento
- `array_utils.c` 📊 - Funzioni di utilità per la gestione degli array
- `string_utils.c` 📝 - Funzioni di utilità per la gestione delle stringhe
- `extra_utils.c` 🔧 - Funzioni di utilità aggiuntive

## 💡 Dettagli delle Funzioni

### 📥 Gestione degli Input
#### `args_parser.c`
- `ft_parse_args` 🔍 - Converte gli argomenti da riga di comando in una lista di numeri
- `ft_validate_args` ✅ - Verifica che gli argomenti siano numeri interi validi
- `ft_check_duplicates` 🔍 - Controlla la presenza di numeri duplicati

#### `input_validation.c`
- `ft_is_valid_number` ✅ - Verifica se una stringa rappresenta un numero intero valido
- `ft_is_sorted` 📊 - Controlla se la lista è già ordinata
- `ft_check_limits` ⚠️ - Verifica che i numeri siano entro i limiti di INT_MIN e INT_MAX

### 📊 Operazioni sugli Stack
#### `stack_ops.c`
- `ft_sa/ft_sb` 🔄 - Scambia i primi due elementi dello stack A/B
- `ft_pa/ft_pb` ➡️ - Sposta il primo elemento tra gli stack A e B
- `ft_ra/ft_rb` 🔄 - Ruota lo stack A/B verso l'alto
- `ft_rra/ft_rrb` 🔄 - Ruota lo stack A/B verso il basso
- `ft_ss/ft_rr/ft_rrr` 🔄 - Esegue le operazioni combinate

#### `elem_list.c`
- `ft_new_elem` ➕ - Crea un nuovo elemento della lista
- `ft_add_back` ➕ - Aggiunge un elemento alla fine della lista
- `ft_list_size` 📏 - Calcola la dimensione della lista
- `ft_free_list` 🗑️ - Libera la memoria allocata per la lista

### 🔄 Algoritmi di Ordinamento
#### `small_sort.c`
- `sort_three` 🔢 - Implementa l'algoritmo ottimizzato per 3 elementi
- `sort_four_five` 🔢 - Gestisce l'ordinamento di 4 e 5 elementi

#### `sort_three_utils.c`
- `find_min` 🔍 - Trova il valore minimo nello stack
- `find_max` 🔍 - Trova il valore massimo nello stack
- `is_sorted` ✅ - Verifica se lo stack è ordinato

#### `sort_four_five.c`
- `sort_four` 🔢 - Ordina 4 elementi in massimo 7 mosse
- `sort_five` 🔢 - Ordina 5 elementi in massimo 12 mosse
- `find_min_pos` 🔍 - Trova la posizione del minimo nello stack

#### `chunk_sort.c` e `chunk_utils.c`
- `chunk_sort` 📊 - Algoritmo principale per stack di grandi dimensioni
- `push_chunks` ➡️ - Sposta gli elementi nei chunk appropriati
- `pull_chunks` ⬅️ - Riporta gli elementi ordinati nello stack A
- `rotate_b` 🔄 - Ottimizza le rotazioni dello stack B
- `handle_push_to_b` ➡️ - Gestisce il push degli elementi in B

### 🛠️ Funzioni di Utilità
#### `sort_utils.c`
- `ft_abs` 📊 - Calcola il valore assoluto
- `ft_min` 🔍 - Trova il minimo tra due numeri
- `ft_max` 🔍 - Trova il massimo tra due numeri

#### `array_utils.c`
- `ft_array_len` 📏 - Calcola la lunghezza di un array
- `ft_array_dup` 📋 - Duplica un array
- `ft_array_sort` 🔄 - Ordina un array

#### `string_utils.c`
- `ft_strlen` 📏 - Calcola la lunghezza di una stringa
- `ft_strcmp` 🔍 - Confronta due stringhe
- `ft_atoi` 🔢 - Converte una stringa in intero

#### `extra_utils.c`
- `ft_error` ⚠️ - Gestisce gli errori
- `ft_free_split` 🗑️ - Libera la memoria di un array di stringhe
- `ft_print_ops` 📝 - Stampa le operazioni eseguite

## 🎮 Esempi di Utilizzo

### 🔢 Ordinamento di 3 numeri
```bash
./push_swap 3 1 2
```
Output: `sa ra`

### 🔢 Ordinamento di 5 numeri
```bash
./push_swap 5 2 1 4 3
```
Output: `pb pb ra pb ra pa pa pa`

### 🔢 Ordinamento di 100 numeri
```bash
./push_swap $(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
```
Output: Sequenza di operazioni ottimizzata per 100 numeri

## ⚡ Dettagli Implementativi

### 🔢 Ordinamento per Stack Piccoli
- `sort_three` 🎯 - Ordina 3 elementi in massimo 2 mosse
- `sort_four` 🎯 - Ordina 4 elementi in massimo 7 mosse
- `sort_five` 🎯 - Ordina 5 elementi in massimo 12 mosse

### 📊 Chunk Sort
L'algoritmo principale per stack di grandi dimensioni funziona in questo modo:
1. 📥 Divide lo stack in chunk di dimensione appropriata
2. ➡️ Sposta gli elementi nei chunk corretti
3. 🔄 Riordina lo stack B per ottimizzare le mosse
4. ⬅️ Riporta gli elementi ordinati nello stack A

### ⚡ Ottimizzazioni
- 📊 Per stack ≤ 100 elementi: 5 chunk
- 📊 Per stack > 100 elementi: 11 chunk
- 🔄 Rotazioni ottimizzate per minimizzare le mosse
- 🎯 Gestione efficiente dei casi speciali

## 🛠️ Compilazione
```bash
make
```

## 🚀 Utilizzo
```bash
./push_swap [numeri da ordinare]
```

## 📋 Requisiti
- 💻 Compilatore C (gcc)
- 🛠️ Make
- 🐧 Sistema operativo Unix-like

## ��‍💻 Autore
ffebbrar 