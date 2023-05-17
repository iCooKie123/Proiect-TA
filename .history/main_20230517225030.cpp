#include <iostream>
#include <cmath>

using namespace std;

// Student: ****** *****
// subgrupa: 1332A

// tipuri de variabile

// variabile globale

// functii ale utilizatorului

int cmmdc(int m, int n)
{
    while (m != n)
        if (m > n)
            m -= n;
        else
            n -= m;
    return m;
}

bool verificare_CMMMDC(int m, int n)
{
    int x = n;
    if (m > n)
        x = m;
    long long v[x + 1];
    v[1] = v[2] = 1;
    for (int i = 3; i <= x; i++)
        v[i] = v[i - 1] + v[i - 2];
    for (int i = 1; i <= x; i++)
        cout << v[i] << " ";
    cout << "\n";
    cout << "v[" << m << "]=" << v[m] << ", v[" << n << "]=" << v[n] << "\n";
    if (cmmdc(v[m], v[n]) == v[cmmdc(m, n)])
        return true;
    return false;
}

int validare_permutari(int x[100], int k)
{
    for (int i = 1; i < k; i++)
        if (x[i] == x[k])
            return 0;
    return 1;
}

void generare_permutari(int n)
{
    int i, k, nrs = 0, v, x[100];
    k = 1;
    x[1] = 0; // a_1-p_1
    while (k > 0)
    {
        v = 0; // v=0 daca nu este verificata conditia de validare
        while ((v == 0) && (x[k] + 1) <= n)
        {
            x[k] = x[k] + 1;
            v = validare_permutari(x, k);
        } // end while alege x[k]
        if (v == 0)
            k = k - 1;
        else
        {
            if (k == n)
            {
                nrs++;
                // scrie solutie
                for (i = 1; i <= n; i++)
                    cout << x[i] << " ";
                cout << endl;
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
    } // end while k>0
    cout << "Numarul de permutari de " << n << " elemente este " << nrs << endl;
}
void generare_combinarile(int n, int k, int x[], int k_ant)
{
    if (k == k_ant)
    { // am selectat deja k elemente
        for (int i = 1; i <= k; i++)
            cout << x[i] << " ";
        cout << endl;
        return;
    }
    for (int i = x[k_ant] + 1; i <= n; i++)
    { // selectam un element incepand de la pozitia k_ant+1
        x[k_ant + 1] = i;
        generare_combinarile(n, k, x, k_ant + 1); // apelam recursiv functia pentru pozitia k_ant+1
    }
}

void generare_aranjamente(int n, int k, int x[], int k_ant)
{
    if (k == k_ant)
    { // am selectat deja k elemente
        for (int i = 1; i <= k; i++)
            cout << x[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        bool valid = true;
        for (int j = 1; j <= k_ant; j++)
        { // verificam sa nu selectam acelasi element de mai multe ori
            if (x[j] == i)
            {
                valid = false;
                break;
            }
        }
        if (valid)
        {
            x[k_ant + 1] = i;
            generare_aranjamente(n, k, x, k_ant + 1); // apelam recursiv functia pentru pozitia k_ant+1
        }
    }
}

void norme_matriciale()
{
    int n;
    cout << "Introduceti dimensiunea matricii: ";
    cin >> n;
    double a[n][n];
    cout << "Introduceti elementele matricii:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    // Norma maxima
    double norma_maxima = 0;
    for (int i = 0; i < n; i++)
    {
        double suma = 0;
        for (int j = 0; j < n; j++)
        {
            suma += abs(a[i][j]);
        }
        if (suma > norma_maxima)
        {
            norma_maxima = suma;
        }
    }
    cout << "Norma maxima: " << norma_maxima << endl;
    // Norma Frobenius
    double norma_frobenius = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            norma_frobenius += pow(a[i][j], 2);
        }
    }
    norma_frobenius = sqrt(norma_frobenius);
    cout << "Norma Frobenius: " << norma_frobenius << endl;

    // norma spectrala
}

bool verif_col(int n, int tabla[100][100], int coloanaCautata)
{

    for (int i = 0; i < n; i++)
    {
        if (tabla[coloanaCautata][i] == 1)
            return false;
    }
    return true;
}

bool verif_rand(int n, int tabla[100][100], int randCautat)
{
    for (int i = 0; i < n; i++)
    {
        if (tabla[i][randCautat] == 1)
            return false;
    }
    return true;
}

bool verif_diag(int n, int tabla[100][100], int rand, int coloana)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; i++)
        {
            if (tabla[i][j] == 1)
                return false;
        }
    }
    return true;
}

bool verif_totala(int n, int tabla[100][100], int coloana, int rand)
{
    if (verif_col(n, tabla, coloana) && verif_rand(n, tabla, rand) && verif_diag(n, tabla, rand, coloana))
        return true;
    return false;
}

void problema_reginelor()
{
    int n;
    cout << "introduceti marimea tablei de sah: ";
    cin >> n;
    cout << endl;
    int tabla[n][n];
    tabla[0][0] = 1;
    tabla[1][1] = 1;
    tabla[0][5] = 1;
    tabla[2][3] = 1;
}


///<>

void capitol1()
{
    int op1; // optiune capitol 1
    do
    {
        cout << "1. Exemple de algoritmi\n\n";
        cout << " 1.1. Verificare c.m.m.d.c. elemente sir Fibonacci \n";
        cout << " 1.2. Calcul norme matriciale \n";
        cout << " 1.0. Incheiere capitol 1 \n\n";
        cout << "Optiune capitol1: ";
        cin >> op1;
        cout << "\n";
        switch (op1)
        {
        case 1:
            int m, n;
            cout << "Introducti m si n \n";
            cin >> m >> n;
            if (verificare_CMMMDC(m, n) == true)
                cout << "Corect \n";
            else
                cout << "Incorect \n";

            break;

        case 2:
            norme_matriciale();
            break;

        case 0:
            cout << "Incheiere capitol 1\n";
            break;

        default:
            cout << "Optiune invalida!!!\n\n";
            break;
        } // end switch meniu principal

    } while (op1 != 0); // end while op1 capitol 1
}

void capitol2()
{
    int op2; // optiune capitol 1
    do
    {
        cout << "2. Metoda backtracking\n\n";
        cout << " 2.1. Generarea permutarilor \n";
        cout << " 2.2. Generarea combinarilor \n";
        cout << " 2.3. Generarea aranjamentelor \n";
        cout << " 2.4. Problena reginelor \n";
        cout << " 2.5. Problema turnurilor\n";
        cout << " 2.6. Problena calutilor \n";
        cout << " 2.7. Problena comisului voiajor \n";
        cout << " 2.8. Problena parantezelor \n";
        cout << " 2.0. Incheiere capitol 2 \n\n";
        cout << "Optiune capitol2: ";
        cin >> op2;
        cout << "\n";
        switch (op2)
        {
        case 1:
            int n;
            cout << "Introduceti n " << endl;
            cin >> n;
            generare_permutari(n);
            break;

        case 2:
            int k;
            cout << "Introduceti n si k: ";
            cin >> n >> k;
            int x[100];
            generare_combinarile(n, k, x, 0);
            break;
        case 3:
            cout << "Introduceti n si k: ";
            cin >> n >> k;
            generare_aranjamente(n, k, x, 0);
            break;
        case 4:
            // problema_reginelor();
            break;

        case 0:
            cout << "Incheiere capitol 1\n";
            break;

        default:
            cout << "Optiune invalida!!!\n\n";
            break;
        } // end switch meniu principal

    } while (op2 != 0); // end while op2 capitol 2
}

void capitol3()
 {
    int op3; // optiune capitol 3
    do {
        cout<<"3. Metoda recursiva \n\n";
        cout<<" 3.1. Backtracking recursiv \n";
        cout<<" 3.2. Functia Ackermann - recursiva \n";
        cout<<" 3.3. Functia Ackermann - iterativa \n";
        cout<<" 3.4. Descompunere in factori primi - recursiv \n";
        cout<<" 3.5. Schimbarea bazei de numeratie - recursiv \n";
        cout<<" 3.6. Numarul de partitii pentru o multime \n";
        cout<<" 3.7. Exemplu de recursivitate indirecta: miscarea unui punct, pe ecran, in mod text \n";
        cout<<" 3.0.  \n\n";
        cout<<"Optiune capitol 3: "; cin>>op3; cout<<"\n";
        switch (op3) {
            case 1:
                //o problema de la backtracking
                break;

            case 2:
                cout<<"introduceti m si n \n";
                int m,n;
                cin>>m>>n;
                cout<<ackermann_recursiv(m,n)<<endl;
                cout<<endl;
                break;
            case 3:
                cout<<"introduceti m si n \n";
                cin>>m>>n;
                cout<<ackermann_iterativ(m,n)<<endl;
                break;

            case 0:
                cout<<"Incheiere capitol 1\n";
                break;

            default:
                cout<<"Optiune invalida!!!\n\n";
                break;
        } // end switch meniu principal

    } while(op3!=0); // end while op1 capitol 1
}

int main()
{
    int op; // optiune meniu principal
    do
    {
        cout << "Programe TEORIA ALGORITMILOR\n\n";
        cout << "1. Exemple de algoritmi \n";
        cout << "2. Metoda backtracking \n";
        cout << "3. Recursivitate \n";
        cout << "0. Iesire din program \n\n";
        cout << "Optiune: ";
        cin >> op;
        cout << "\n";
        switch (op)
        {
        case 1:
            capitol1();
            break;

        case 2:
            capitol2();
            break;
        case 3:
            capitol3();
            break;
        case 0:
            cout << "Incheiere program. La revedere!\n";
            break;

        default:
            cout << "Optiune invalida!!!\n\n";
            break;
        } // end switch meniu principal

    } while (op != 0); // end while op meniu principal
    return 0;
}

// bool este_sigur(int tabla[100][100], int linie, int coloana, int dimensiune) {
//     int i, j;
//     // verificam pe linie
//     for(i=1; i<=coloana; i++)
//         if(tabla[linie][i] == 1)
//             return false;
//     // verificam diagonala principala
//     for(i=linie, j=coloana; i>=1 && j>=1; i--, j--)
//         if(tabla[i][j] == 1)
//             return false;
//     // verificam diagonala secundara
//     for(i=linie, j=coloana; i<=dimensiune && j>=1; i++, j--)
//         if(tabla[i][j] == 1)
//             return false;
//     // daca am trecut de toate verificarile, pozitia este sigura
//     return true;
// }

// void afisare_solutie(int tabla[100][100], int dimensiune) {
//     static int nr_solutii = 0;
//     cout << "Solutia " << ++nr_solutii << ":" << endl;
//     for(int i=1; i<=dimensiune; i++) {
//         for(int j=1; j<=dimensiune; j++)
//             cout << tabla[i][j] << " ";
//         cout << endl;
//     }
//     cout << endl;
// }

// void problema_reginelor_backtracking(int tabla[100][100], int coloana, int dimensiune) {
//     if(coloana > dimensiune) { // am plasat regine pe toate coloanele, am gasit o solutie
//         afisare_solutie(tabla, dimensiune);
//         return;
//     }
//     for(int i=1; i<=dimensiune; i++) { // incercam sa plasam o regina pe fiecare linie din coloana curenta
//         if(este_sigur(tabla, i, coloana, dimensiune)) { // daca pozitia este sigura
//             tabla[i][coloana] = 1; // plasam regina
//             problema_reginelor_backtracking(tabla, coloana+1, dimensiune); // apelam recursiv functia pentru urmatoarea coloana
//             tabla[i][coloana] = 0; // anulam ultima mutare
//         }
//     }
// }

// void problema_reginelor() {
//     int dimensiune, tabla[100][100];
//     cout << "Introduceti dimensiunea tablei: "; cin >> dimensiune;
//     for(int i=1; i<=dimensiune; i++)
//         for(int j=1; j<=dimensiune; j++)
//             tabla[i][j] = 0;
//     problema_reginelor_backtracking(tabla, 1, dimensiune);
// }
