# Linked List Cycle

## Description

Ce projet consiste à implémenter une fonction en C permettant de détecter la présence d'un cycle dans une liste chaînée simple.

## Compilation & Exécution

Toutes les sources doivent être compilées avec `gcc` sous Ubuntu 14.04 LTS avec les options suivantes :

```sh
gcc -Wall -Werror -Wextra -pedantic 0-main.c 0-check_cycle.c 0-linked_lists.c -o cycle
```

Pour exécuter :

```sh
./cycle
```

## Exigences

- Les fichiers doivent être écrits en C.
- Utilisation des normes Betty pour le style du code.
- Pas de variables globales autorisées.
- Pas plus de 5 fonctions par fichier.
- Tous les fichiers doivent finir par une nouvelle ligne.
- Un fichier `lists.h` doit contenir les prototypes des fonctions et une protection d'inclusion.

## Fonctions Implémentées

### `int check_cycle(listint_t *list);`

Cette fonction détecte si une liste chaînée simple contient un cycle.

- **Entrée** : un pointeur vers la liste `listint_t *list`
- **Sortie** :
  - `1` si un cycle est détecté
  - `0` sinon

### `size_t print_listint(const listint_t *h);`

Affiche tous les éléments d'une liste chaînée.

### `listint_t *add_nodeint(listint_t **head, const int n);`

Ajoute un nouveau nœud au début d'une liste chaînée.

### `void free_listint(listint_t *head);`

Libère la mémoire allouée pour une liste chaînée.

## Structure de Données

```c
/**
 * struct listint_s - Liste chaînée simple
 * @n: Valeur de l'entier stocké dans le nœud
 * @next: Pointeur vers le prochain nœud
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Exemple de Test

Un exemple de test est fourni dans `0-main.c`, où une liste est créée, affichée, puis un cycle est introduit et détecté.

**Exécution attendue :**

```sh
1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle
```

## Auteur

Carrie Ybay, Software Engineer at Holberton School
