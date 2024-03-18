:-dynamic(pedido/7).
:- use_module(library(http/thread_httpd)).
:- use_module(library(http/http_dispatch)).
:- use_module(library(http/http_parameters)).
:- use_module(library(uri)).
:- http_handler(root(cancela_pedido), cancela, []).
:- http_handler(root(processa_pedido), mensagem, []).
:- dynamic(nomeCliente/2).
:- dynamic(telCliente/2).

servidor(Porta) :-
 http_server(http_dispatch, [port(Porta)]).

mensagem(R) :-
    format('Content-type: text/plain~n~n'),
    format('Pedido realizado!~n~n'),
    format('Listagem dos dados!~n'),
    http_parameters(R,[nomeCliente(C,[]),
                       telCliente(T,[]),
                       emailCliente(E,[]),
                       tamanho(S,[]),
                       ing(I,[]),
                       tempo(H,[]),
                       obs(O,[])
                      ]),
    write(nome(C)),nl,
    write(telefone(T)),nl,
    write(email(E)),nl,
    write(tamanho(S)),nl,
    write(ingrediente(I)),nl,
    write(tempo(H)),nl,
    write(obs(O)),nl,
    executa(C, T, E, S, I, H, O).

executa(C, T, E, S, I, H, O):-
    append('pedidos.pl'),
    write('pedido'),write('('),teste,write(C),teste,write(','),teste,write(T),teste,write(','),teste,write(E),teste,write(','),teste,write(S),teste,write(','),teste,write(I),teste,write(','),teste,write(H),teste,write(','),teste,write(O),teste,write(')'),write('.'),nl,
    told.

cancela(R):-
     http_parameters(R,[nomeCliente(C,[]),
                       telCliente(T,[]),
                       emailCliente(_,[]),
                       tamanho(_,[]),
                       ing(_,[]),
                       tempo(_,[]),
                       obs(_,[])
                      ]),
    reconsult('pedidos.pl'),
    retract(pedido(C,T,_,_,_,_,_)),
    tell('pedidos.pl'),
    listing(pedido/7),
    told,
    format('Content-type: text/plain~n~n'),
    format('Pedido cancelado!~n~n').

cancela(_):-
   format('Content-type: text/plain~n~n'),
   format('Pedido não encontrado!~n~n').

teste:-
 write("'").

