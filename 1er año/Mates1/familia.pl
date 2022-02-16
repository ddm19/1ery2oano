padre(juan,maria).
padre(matias,juan).
primo(maria,luis).
primo(jose,maria).
primo(bea,luis).

abuelo(X,Y):-padre(X,Z),padre(Z,Y).

hijo(X,Y):-padre(Y,X).

tio(X,Z):-(primo(Y,Z);primo(Z,Y)),padre(X,Y).

