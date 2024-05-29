habitat(dog,land).
habitat(mouse,land).

habitat(fish,water).
habitat(dolphin,water).

habitat(bat,air).
habitat(bird,air).

land_animal(X):-habitat(X,land).
water_animal(X):-habitat(X,water).
flying_animal(X):-habitat(X,air).

classify_animal(Animal):-
    land_animal(Animal),
    write(Animal),write(' is a land animal'),nl.



classify_animal(Animal):-
    water_animal(Animal),
    write(Animal),write(' is a water animal'),nl.


classify_animal(Animal):-
    flying_animal(Animal),
    write(Animal),write(' is a flying animal'),nl.


classify_animal(Animal):-
    write(Animal),write(' is a not an animal'),nl.

identy_animal_category:-
    write('Welcome to the animal classifier'),nl,
    write('Enter animal name'),nl,
    read(Animal),
    classify_animal(Animal).

main:-
    identy_animal_category,
    write('to continue type yes or else type quit'),nl,
    read(Input),
    (Input==quit->halt;main).

:-main.