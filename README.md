![regineb](https://user-images.githubusercontent.com/81011287/211863256-8edfa77c-8293-4adb-bc50-ee4be0b13bad.png)

![Frame 2](https://user-images.githubusercontent.com/81011287/211864973-0d3643a7-090d-4909-9c08-a7ba939e61b7.png)

Problema celor 8 regine este una cunoscută în informatică, care implică aşezarea a 8 regine pe o tabla de şah într-un mod în care nici o regină nu atacă pe celelalte. Pentru a rezolva această problema vom folosi metoda backtracking.
    În cazul problemei celor 8 regine, backtracking ne permite să încercăm să plasăm reginele pe tabla de şah într-o anumită ordine, iar dacă nu găsim o soluţie, să întoarcem înapoi şi să încercăm altă ordine. Acest proces se repetă până când găsim o soluţie sau epuizăm toate posibilităţile.

![Frame 2](https://user-images.githubusercontent.com/81011287/211865184-b22c1e7b-3c0f-4c1b-8013-75f12ad149ba.png)
Începem prin declararea a doua variabile: 
![carbon (2)](https://user-images.githubusercontent.com/81011287/211865336-7d3bd029-8a69-4850-83a1-5d169adfb29e.png)

Unde n este o variabilă care memorează dimensiunea tablei de șah, iar R[9] este un vector care memorează pozițiile reginelor pe tabla de șah. R[i] reprezintă coloana în care este plasată regina din i-ul rând. De exemplu, dacă R[3] = 5, înseamnă că regina din al treilea rînd este plasată în a cincea coloană. Dimensiunea vectorului este setată la 9 pentru că dimensiunea maximă a tablei de șah este 8 si vectorul este indexat începand de la 1.

![carbon (1)](https://user-images.githubusercontent.com/81011287/211863911-1e81eab9-74f5-4bd0-9cb5-59083caf8734.png)

Această funcție verifică daca o poziție dată (x, y) pe  tabla de șah este validă pentru a plasa o regină pe tabla de șah n x n. Acest lucru îl face prin iterarea prin rândurile de la 1 la x-1 din tabla de șah si verificând dacă oricare dintre reginele plasate anterior conflictueaza cu poziția (x, y). Dacă este găsit un conflict, funcția incrementează y cu 1 si repetă loop-ul de la primul rand. Dacă y devine mai mare decât n, funcția returnează 0, altfel returnează y.
Cele trei verificări din interiorul for loop verifică trei tipuri diferite de conflicte:
- Dacă rândul reginei plasate anterior este același ca rândul poziției care este verificată (R[i] == y).
- 	Dacă diferența dintre rânduri este aceeași ca diferența dintre coloane
 (i - R[i] == x - y). Acest lucru ar însemna că reginele sunt pe diagonală.
- Dacă diferența dintre rânduri este aceeași ca diferența dintre coloane 
(i - x == y - R[i]). Acest lucru ar insemna de asemenea că reginele sunt pe diagonală.
Este de menționat faptul că această funcție nu plasează de fapt regina pe tabla de șah, ci doar verifică dacă poziția este validă.

Urmatorul for() loop are blocul de inițializare omis deoarece variabila i este inițializată înafara buclei.
![carbon (4)](https://user-images.githubusercontent.com/81011287/211866544-4c60539c-8d23-453b-a754-1b45ad985c63.png)
 Acest for() loop face următoarele:
-	Itereaza prin elementele array-ului R de la i la n (i este variabila care ține evidența rândului curent al tablei de șah)

-In interiorul acestui for loop, apelul functiei check() este folosit pentru a verifica dacă poate fi plasată o regină pe poziția curentă. Dacă este posibil să fie plasată o regină, atunci se setează valoarea elementului curent din array-ul R la poziția returnată de funcția check(). 
   Dacă nu este posibil să fie plasată o regină, atunci se face backtracking, adica se seteaza valoarea elementului curent din array-ul R la 1, se incrementeaza valoarea elementului anterior din array-ul R cu 1, și se decrementează valoarea variabilei i cu 2. In acest caz, i este decrementat cu 2 în cazul în care conflict nu este 0. Această decrementare a lui i are ca scop să facă ca bucla să se execute înapoi, cu o poziție, astfel încat să poată verifica dacă există o alta poziție validă pentru regină.

Acești pași sunt repetați până când variabila i depaseste n. Dupa ce variabila i depaseste n, bucla se opreste.

Acest bloc de cod:
![carbon (5)](https://user-images.githubusercontent.com/81011287/211867070-6168be25-6724-4c78-935a-920edf20da28.png)

face un "nested loop" (bucla aninata) prin care parcurge fiecare poziție a tablei de șah și verifică dacă poziția este ocupată de o regină (R[i]). Daca pozitia este ocupată de o regină, atunci afiseaza "Q", altfel afiseaza "-". Dupa ce se parcurg toate pozițiile de pe aceeași linie, se afișează un rand nou, astfel încat sa se poata afisa intreaga tablă de șah.

La sfârșitul funcției main() avem următoarele linii de cod:
![carbon (6)](https://user-images.githubusercontent.com/81011287/211867362-c2c77dac-7393-4034-aeea-8298590db5df.png)

Acest lucru permite ca bucla while să poată fi reluată, începând de la ultima poziție a tablei de șah, verificând dacă există o poziție validă pentru regina în această poziție. Dacă nu există o poziție validă, atunci valoarea lui i va fi decrementată cu 2, asa cum este descris în explicația anterioară, și se va încerca din nou să se plaseze regina pe tabla de șah.

![Frame 2](https://user-images.githubusercontent.com/81011287/211867431-ea25e3be-aa5f-444a-bfb0-a0ca8d14d123.png)

Această problemă se numește "Problema celor 8 Regine" si este o problemă clasică de backtracking. Pentru a rezolva aceasta problema, am folosit metoda de backtracking în care se încercă să se plaseze o regină pe tabla de șah, începand de la prima poziție și mergând spre ultima poziție. Dacă regina poate fi plasata pe o anumită poziție, atunci se trece la urmatoarea poziție și se încerca din nou să se plaseze regină. Dacă regina nu poate fi plasată pe poziția curentă, atunci se face backtracking și se încercă să se plaseze regina pe o altă poziție. Acest proces se repetă până când toate reginele au fost plasate pe tabla de șah, sau pana cand s-a ajuns la o poziție în care nu mai este posibil să se plaseze regina, caz în care se întoarce înapoi la pozițiile anterioare și se încearcă să se găsească o alta poziție validă pentru regină.
   
  În concluzie, rezolvarea acestei problema ajută la dezvoltarea capacităților de viitor programator, deoarece cere folosirea unor metode avansate de programare.





