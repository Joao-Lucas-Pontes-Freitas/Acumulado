progenitor(jose,joao).
progenitor(jose,ana).
progenitor(maria,joao).
progenitor(maria,ana).
progenitor(ana,helena).
progenitor(ana,joana).
progenitor(joao,mario).
progenitor(mario,carlos).
progenitor(helena,carlos).
masculino(jose).
masculino(joao).
masculino(carlos).
masculino(mario).
feminino(ana).
feminino(maria).
feminino(helena).
feminino(joana).

pai(X,Y):- progenitor(X,Y),masculino(X).

mae(X,Y):- progenitor(X,Y),feminino(X).

irmao(X,Y):- progenitor(Z,X),progenitor(Z,Y),masculino(X), (X\=Y).

irma(X,Y):- progenitor(Z,X),progenitor(Z,Y),feminino(X),(X\=Y).

avo(X,Y):- progenitor(X,Z),progenitor(Z,Y).

descendente(X,Y) :- progenitor(X,Y).

descendente(X,Y):- progenitor(X,Z),descendente(Z,Y).

primo(X,Y):- progenitor(Z,X),progenitor(A,Y), irma(Z,A),(X\=Y).

primo(X,Y):- progenitor(Z,X),progenitor(A,Y), irmao(Z,A),(X\=Y).

tio(X,Y):- progenitor(Z,Y),irmao(Z,X).

tio(X,Y):- irma(Z,X),progenitor(Z,Y).

tem_irmao(X):- progenitor(Y,X),progenitor(Y,Z),masculino(Z).

tem_irma(X):- progenitor(Y,X),progenitor(Y,Z),feminino(Z).

filho(X,Y):- pai(Y,X).

filho(X,Y):- mae(Y,X).
