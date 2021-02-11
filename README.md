# Programowanie_rownolegle
Zadanie E1

Napisać równoległa implementację operacji dodawania wektora B i wektora C Wynik zapisywany jest w wektorze A. Tzn: A[i] = B[i] + C[i], i=0....n. n=1048576. Waktory B i C należy wypełnić losowymi liczbami z zakresu [0:1]. Jako wynik wypisać A[0] i A[n-1] - należy zwrócić uwagę gdzie składowane są odpowiednie elementy. Wektory mogą być w dowolny sposób rozmieszczone w pamięci. 

Aplikacje należy uruchomić na 1, 2, 4 procesorach (rdzeniach, wątkach) (może być na laptopie) i podać czasy wykonania.

Język programowania dowolny.

Zadanie E2

Napisać program równoległy, który wyznaczy normę wektora A[i] (i=1,1024). Tablicę należy wypełnic liczbami losowymi z przedziału [0:1]. Wynik należy zabrać na procesorze 0 i wypisać na standardowe wyjście. Dla przypomnienia, norma wektorów  to √∑A[i]*A[i].

Język programowania dowolny.

Zadanie E3

Napisać program równoległy, który wczyta z pliku in.txt n liczb całkowitych z zakresu [0:100]  a nastepnie w sposób równoległy wyznaczy histogram, tzn. wyznaczy wektor B[i] (i=0,100) w którego kolejnych komórkach będzie znajdowała się ilość liczb o okreslonej wartości B[0] ilość 0, B[1] ilość 1, B[2] ilość 2 itd. Tablicę B[i] należy zabrać na procesorze 0 i wypisać na standardowe wyjście.

Plik wejściowy powinien zawierać co najmniej 1024 liczb. 

Język programowania dowolny.
