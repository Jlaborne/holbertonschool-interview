#!/usr/bin/python3
import sys


def is_safe(queens, row, col):
    """
    Vérifie si une reine peut être placée à la position (row, col)
    sans être en conflit avec une autre reine déjà placée.
    """
    for r in range(row):
        c = queens[r]
        # Conflit vertical ou diagonale
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve_nqueens(n, row=0, queens=[], solutions=[]):
    """
    Résout le problème des N reines par backtracking.
    - n: taille de l'échiquier
    - row: ligne actuelle
    - queens: liste contenant la colonne de chaque reine déjà placée
    - solutions: liste des solutions trouvées
    """
    # Si toutes les reines sont placées, on ajoute la solution
    if row == n:
        solutions.append([[i, queens[i]] for i in range(n)])
        return

    # On teste chaque colonne possible pour la ligne actuelle
    for col in range(n):
        if is_safe(queens, row, col):
            queens.append(col)             # On place une reine
            solve_nqueens(n, row + 1, queens, solutions)
            queens.pop()                   # Backtrack : on retire la reine


def main():
    """
    Point d'entrée du programme :
    - Gère les erreurs d'entrée utilisateur
    - Lance la résolution
    - Affiche toutes les solutions
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve_nqueens(n, 0, [], solutions)

    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
