floors([floor(_,5),floor(_,4),floor(_,3),floor(_,2),floor(_,1)]).
building(Floors) :- floors(Floors),
    person(floor(Baron, B), Floors), B \= 5,
    person(floor(Cook, C), Floors), C \= 1,
    person(floor(Frank, F), Floors), F \= 1, F \= 5,
    person(floor(Mike, M), Floors), M > C,
    person(floor(Sam, S), Floors),
not(adjacent(S, F)),
    not(adjacent(F, C)),
    print_floors(Floors).
print_floors([A | B]) :- write(A), nl, print_floors(B).
print_floors([]).
person(X, [X | _]).
person(X, [_ | Y]) :- person(X, Y).
adjacent(X, Y) :- X =:= Y+1.
adjacent(X, Y) :- X =:= Y-1.
not(Goal) :- \+ call(Goal).
