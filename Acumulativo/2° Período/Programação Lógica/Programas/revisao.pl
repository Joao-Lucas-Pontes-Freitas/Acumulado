% This buffer is for notes you don't want to save.
% If you want to create a file, visit that file with C-x C-f,
% then enter the text in that file's own buffer.

pertence(X, [X|_]):-!.
pertence(X,[_|T]):- pertence(X,T).

ultimo(X,[X]):-!.
ultimo(X,[_|T]):- ultimo(X,T).

consecutivos(X,Y,[X,Y|_]).
consecutivos(X,Y,[_|T]):- consecutivos(X,Y,T),!.

tamanho([],0).
tamanho([_|T],R):-
    tamanho(T,R1),
     R is R1 +1.

fatorial(0,1).
fatorial(X,R):-
    X1 is X-1,
    fatorial(X1,R1),
    R is R1 * X,!.

equacao(1,2).
equacao(N,R):-
    N1 is N-1,
    equacao(N1,R1),
    R is R1 - 3*N*N, !.

f(X,0):- X < 3,!.
f(X,2):- X < 6,!.
f(_,4).
m(1).
m(2):-!.
m(3).
m1(X,Y) :-
    m(X), m(Y).
m2(X,Y) :-
    m(X),!,m(Y).

imprimeAte(X):- rec(0,X).
rec(I,F):- I > F.
rec(I,F):-write(F),write(' '), F1 is F - 1, rec(I,F1).

exp(_,0,1).
exp(X,Y,R):- Y1 is Y-1, exp(X,Y1,R1), R is R1 * X,!.

pre([X],[X|_]).
pre([_|Y],[_|T]):- pre(Y,T),!.

su(L,L).
su(L,[_|T]):- su(L,T),!.

par([],[]).
par([H|T],R) :- par(T,T1), (( H mod 2) =:= 0 -> R = [H|T1]; R = T1).

