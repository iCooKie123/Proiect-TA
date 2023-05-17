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

// capitol 3
int ackermann_recursiv(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (n == 0)
        return ackermann_recursiv(m - 1, 1);
    return ackermann_recursiv(m - 1, ackermann_recursiv(m, n - 1));
}

void ackermannIterativ(int k)
{
    int m, n, a[100] = {0};
    cout << "m=";
    cin >> m;
    cout << "n=";
    cin >> n;
    a[1] = m;
    a[2] = n;
    while (k > 1)
    {
        if (a[k - 1] == 0)
        {
            a[k - 1] = a[k] + 1;
            k--;
        }
        else if (a[k] == 0)
        {
            a[k - 1] = a[k - 1] - 1;
            a[k] = 1;
        }
        else
        {
            a[k + 1] = a[k] - 1;
            a[k] = a[k - 1];
            a[k - 1] = a[k - 1] - 1;
            k++;
        }
    }
    cout << a[1] << endl;
}

void backT(int st[20], int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        st[k] = i;
        if (validRecursiv(st, k) == true)
            if (k == n)
                afiseazaRec(st, n);
            else
                backT(st, k + 1, n);
    }
}

void afiseazaRec(int st[20], int n)
{
    for (int i = 1; i <= n; i++)
        cout << st[i] << ' ';
    cout << endl;
}

bool validRecursiv(int st[20], int k)
{
    for (int i = 1; i < k; i++)
        if (st[i] == st[k])
            return false;
    return true;
}

void factoriPrimiRecursiv(int n, int factoriPrimi[], int &count)
{
    // Verificăm dacă numărul este divizibil cu 2
    while (n % 2 == 0)
    {
        factoriPrimi[count++] = 2;
        n = n / 2;
    }

    // Verificăm divizibilitatea cu alți factori primi impari
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            factoriPrimi[count++] = i;
            n = n / i;
        }
    }

    // Dacă numărul rămas este mai mare decât 2, înseamnă că el însuși este prim
    if (n > 2)
    {
        factoriPrimi[count++] = n;
    }
}

// fct cap 4

int poz(int v[100], int st, int dr)
{
    int pozitie = st;
    for (int i = st; i <= dr; i++)
        if (v[i] > v[dr])
        {
            int aux = v[i];
            v[i] = v[dr];
            v[dr] = aux;
            pozitie++;
        }
    return pozitie;
}

void quikSortRecursiv(int v[100], int st, int dr)
{
    if (st < dr)
    {
        int m = poz(v, st, dr);
        quikSortRecursiv(v, st, m - 1);
        quikSortRecursiv(v, m + 1, dr);
    }
}

int cautareBinara(int v[100], int st, int dr, int x)
{
    if (st > dr)
        return -1;
    else
    {
        int m = (st + dr) / 2;
        if (x == v[m])
            return m;
        if (x < v[m])
            return cautareBinara(v, st, m - 1, x);
        else
            return cautareBinara(v, m + 1, dr, x);
    }
}

int maxim(int v[100], int i, int j)
{
    if (i == j)
        return v[i];
    else
    {
        int a = maxim(v, i, (i + j) / 2);
        int b = maxim(v, (i + j) / 2 + 1, j);
        if (a > b)
            return a;
        else
            return b;
    }
}

int minim(int v[100], int i, int j)
{
    if (i == j)
        return v[i];
    else
    {
        int a = minim(v, i, (i + j) / 2);
        int b = minim(v, (i + j) / 2 + 1, j);
        if (a < b)
            return a;
        else
            return b;
    }
}

void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << a << b << endl;
    }
    else
    {
        hanoi(n - 1, a, c, b);
        cout << a << b << endl;
        hanoi(n - 1, c, b, a);
    }
}

int combinareAlgEuclid(int a, int b)
{
    while (a != b)
        if (a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}

int cmmdc(int v[100], int st, int dr)
{
    for (int i = st; i <= dr; i++)
        cout << v[i] << ' ';
    cout << endl;
    if (st < dr)
    {
        int m = (st + dr) / 2;
        int c1 = cmmdc(v, st, m);
        int c2 = cmmdc(v, m + 1, dr);
        int c = combinareAlgEuclid(c1, c2);
        cout << c << endl;
        return c;
    }
    return v[st];
}

// functii cap 5

void comisVoiajorG()
{
    int s[10], a[10][10], n, i, j, v, p, vs, vs1, mint, cost;
    cout << "Numar noduri: ";
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            cin >> a[i][j];
    a[j][i] = a[i][j];
    cout << "Nod de pornire: ";
    cin >> v;
    s[v] = 1;
    vs1 = v;
    cout << "Drumul trece prin: " << v << ' ';
    p = v;
    for (i = 1; i < n; i++)
    {
        mint = 3000;
        for (j = 1; j <= n; j++)
            if (a[v][j] != 0 && s[j] == 0 && mint > a[v][j])
            {
                mint = a[v][j];
                vs = j;
            }
        cost = cost + a[v][vs];
        cout << vs << ' ';
        s[vs] = 1;
        v = vs;
    }
    cout << p << endl;
    cost = cost + a[vs1][v];
    cout << "Cost: " << cost << endl;
}

void plataBancnoteNelimitat()
{
    int n, v[10], N[10], s;
    cout << "Numar de bancnote n=";
    cin >> n;
    cout << "Valorile bancnotelor sunt in ordine descrescatoare" << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Dati suma s=";
    cin >> s;
    int sc = s;
    int T = 0;
    for (int i = 0; i < n; i++)
    {
        N[i] = sc / v[i];
        sc = sc % v[i];
        T = T + N[i] * v[i];
    }
    if (s == T)
    {
        cout << s << '=';
        for (int i = 0; i < n; i++)
        {
            cout << N[i] << '*' << v[i];
            if (i < n - 1)
                cout << '+';
        }
        cout << endl;
    }
    else
        cout << "Algoritmul Greedy nu a gasit solutia" << endl;
}

void plataBancnoteLimitat()
{
    int b[2][7] = {1, 5, 10, 50, 100, 200, 500}, S, ss = 0, n;
    cout << "S=";
    cin >> S;
    for (int i = 0; i < 7; i++)
    {
        cin >> b[1][i];
        ss = ss + b[0][i] * b[1][i];
    }
    if (ss < S)
        cout << "Nu are solutie" << endl;
    else
        for (int i = 6; i >= 0 && S; i--)
        {
            n = S / b[0][i];
            if (n > b[1][i])
                n = b[1][i];
            cout << n << " bancnote cu valoarea " << b[0][i] << endl;
            S = S - n * b[0][i];
        }
}

// capitol 6

int produsMatrice(int n, int p[20])
{
    int M[20][20] = {0};
    int minim, k0, v;
    cout << n << endl;
    for (int i = 1; i <= n + 1; i++)
        cout << p[i] << ' ';
    cout << endl;
    for (int i = n - 1; i >= 1; i--)
        for (int j = i + 1; j <= n; j++)
        {
            minim = M[i][i] + M[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
            k0 = i;
            for (int k = i + 1; k <= j - 1; k++)
            {
                v = M[i][k] + M[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (v < minim)
                {
                    minim = v;
                    k0 = k;
                }
            }
            M[i][j] = minim;
            M[j][i] = k0;
        }
    cout << "Matricea M este: ";
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
    return M[1][n];
}

void parantezare_compunere(int i, int j, int A[10][10][10], int B[10][10][10], int m)
{
    int k, c;
    /// Parantezeaza compunerea de la xi la xj
    if (i < j)
    { /// Cautam c intre 1 si m astfel incat B[i][j][c] = k
        for (c = 1; c <= m; c++)
        { /// c de la 1 la m
            if (B[i][j][c] != 0)
                break;
        }
        k = B[i][j][c];
        if (i < k)
        {
            cout << "(";
            parantezare_compunere(i, k, A, B, m);
            cout << ")";
        }
        else
        {
            parantezare_compunere(i, k, A, B, m);
        }
        cout << "*";
        if (k + 1 < j)
        {
            cout << "(";
            parantezare_compunere(k + 1, j, A, B, m);
            cout << ")";
        }
        else
        {
            parantezare_compunere(k + 1, j, A, B, m);
        }
    }
    else
    {
        cout << "x[" << i << "]";
    }
}

void sumaMinimaInTriunghi()
{
    int A[10][10], n, i, j, S[10][10] = {INT_MAX}, D[10][10] = {0};
    cout << "n=";
    cin >> n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> A[i][j];
    for (int j = 1; j <= n; j++)
        S[n][j] = A[n][j];
    for (i = n - 1; i >= 1; i--)
        for (j = 1; j <= i; j++)
        {
            S[i][j] = A[i][j];
            if (S[i + 1][j] <= S[i + 1][j + 1])
            {
                S[i][j] += S[i + 1][j];
                D[i][j] = j;
            }
            else
            {
                S[i][j] += S[i + 1][j + 1];
                D[i][j] = j + 1;
            }
        }
    cout << "Suma minima este: " << S[1][1] << endl;
}

// capitol 7
void jocul_perspico()
{
    nod *radacina;
    lista_noduri *L1, *L2;
    int L[16] = {0};
    int l, c, x, i, j;
    int X[4] = {-1, 1, 0, 0};
    int Y[4] = {0, 0, -1, 1};
    int C0[4][4];
    cout << "Citim configuratia initiala C0" << endl;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            cin >> C0[i][j];
}

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
    do
    {
        cout << "3. Metoda recursiva \n\n";
        cout << " 3.1. Backtracking recursiv \n";
        cout << " 3.2. Functia Ackermann - recursiva \n";
        cout << " 3.3. Functia Ackermann - iterativa \n";
        cout << " 3.4. Descompunere in factori primi - recursiv \n";
        cout << " 3.5. Schimbarea bazei de numeratie - recursiv --not done--\n";
        cout << " 3.6. Numarul de partitii pentru o multime --not-done-- \n";
        cout << " 3.7. Exemplu de recursivitate indirecta: miscarea unui punct, pe ecran, in mod text --not-done-- \n";
        cout << " 3.0.  \n\n";
        cout << "Optiune capitol 3: ";
        cin >> op3;
        cout << "\n";
        switch (op3)
        {
        case 1:
            cout << "Backtracking Recursiv" << endl;
            cout << "Problema permutarillor" << endl;
            int st[20];
            cout << "n=";
            int n;
            cin >> n;
            backT(st, 1, n);
            break;
        case 2:
            cout << "introduceti m si n \n";
            int m, n;
            cin >> m >> n;
            cout << ackermann_recursiv(m, n) << endl;
            cout << endl;
            break;
        case 3:
            cout << "Funcita Ackermann(iterativa)" << endl;
            int k;
            cout << "k=";
            cin >> k;
            ackermannIterativ(k);
            break;
        case 4:
            int n;
            cout << "Introduceți un număr: ";
            cin >> n;

            int factoriPrimi[100]; // Dimensiunea maximă a tabloului de factori
            int count = 0;

            factoriPrimiRecursiv(n, factoriPrimi, count);

            cout << "Factorii primi ai numărului " << n << " sunt: ";
            for (int i = 0; i < count; ++i)
            {
                cout << factoriPrimi[i] << " ";
            }
            cout << endl;
            break;
        case 0:
            cout << "Incheiere capitol 1\n";
            break;

        default:
            cout << "Optiune invalida!!!\n\n";
            break;
        } // end switch meniu principal

    } while (op3 != 0); // end while op1 capitol 1
}

void capitol4()
{
    int opt4; // optiune capitol 4
    do
    {
        cout << "4. Divide et Impera (5 probleme obligatorii)" << endl;
        cout << "4.1. Quicksort" << endl;
        cout << "4.2. Cautare binara" << endl;
        cout << "4.3. Maxim dintr-un sir de numare naturale" << endl;
        cout << "4.4. Minim dintr-un sir de numare naturale" << endl;
        cout << "4.5. Turnurile din Hanoi" << endl;
        cout << "4.6. CMMDC a n numere naturale" << endl;
        cout << "4.0. Iesire capitol 4" << endl;
        cin >> opt4;
        switch (opt4)
        {
        case 1:
            cout << "Quicksort recursiv" << endl;
            int n;
            cout << "n=";
            cin >> n;
            cout << "Introduceti elementele sirului:";
            int *a = new int[n];
            for (int i = 0; i < n; i++)
                cin >> a[i];
            quikSortRecursiv(a, 0, n - 1);
            cout << endl
                 << "Sirul sortat este:" << endl;
            for (int i = 0; i < n; i++)
                cout << a[i] << ' ';
            cout << endl;
            delete[] a;
            break;
        case 2:
            cout << "Cautare binara" << endl;
            int x;
            cout << "x=";
            cin >> x;
            cout << "n=";
            cin >> n;
            for (int i = 0; i < n; i++)
                cin >> a[i];
            cout << x << " se  gaseste in sir pe pozitia " << cautareBinara(a, 0, n - 1, x) + 1 << endl;
            break;
        case 3:
            cout << "Maximul unui sir de numere" << endl;
            cout << "n=";
            cin >> n;
            for (int i = 0; i < n; i++)
                cin >> a[i];
            cout << "Elementul maxim este: " << maxim(a, 0, n - 1) << endl;
            break;
        case 4:
            cout << "Minimul unui sir de numere" << endl;
            cout << "n=";
            cin >> n;
            for (int i = 0; i < n; i++)
                cin >> a[i];
            cout << "Elementul minim este: " << minim(a, 0, n - 1) << endl;
            break;
        case 5:
            cout << "Turnurile din Hanoi" << endl;
            cout << "n=";
            cin >> n;
            hanoi(n, 'a', 'b', 'c');
            break;
        case 6:
            cout << "CMMDC a n numere" << endl;
            int v[100], c;
            cout << "n=";
            cin >> n;
            for (int i = 0; i < n; i++)
                cin >> v[i];
            c = cmmdc(v, 0, n - 1);
            cout << "CMMDC al elementelor lui v este: " << c << endl;
            break;
        case 0:
            cout << "Iesire din meniul 4" << endl;
            break;
        default:
            cout << "Optiune invalida cap 4" << endl;
            break;
        }
    } while (opt4 != 0);
}

void capitol5()
{
    int op5;
    do
    {
        cout << "   5.METODA GREEDY" << endl;
        cout << "     5.1 Problema Comisului Voiajor" << endl;
        cout << "     5.2 Plata unei sume cu numar nelimitat de bancnote" << endl;
        cout << "     5.3 Plata unei sume cu numar limitat de bancnote" << endl;
        cout << "     5.4 Acoperire tabla nxn de calut --not-done-" << endl;
        cout << "     5.0 Iesire meniu 5" << endl;
        cout << "Optiunea meniu 5: ";
        cin >> op5;
        switch (op5)
        {
        case 1:
        {
            cout << "Problema Comisului Voiajor" << endl;
            comisVoiajorG();
        }
        break;
        case 2:
        {
            cout << "Plata unei sume cu numar nelimitat de bancnote" << endl;
            plataBancnoteNelimitat();
        }
        break;
        case 3:
        {
            cout << "Plata unei sume cu numar limitat de bancnote" << endl;
            plataBancnoteLimitat();
        }
        break;
        case 0:
            cout << "Iesire din meniul 5" << endl;
            break;
        default:
            cout << "Optiune invalida pentru meniul 5" << endl;
            break;
        }
    } while (op5 != 0);
}

void capitol6()
{
    int opt6;
    do
    {
        cout << "   6.PROGRAMARE DINAMICA" << endl;
        cout << "     6.1 Minim de inmultiri in produs de matrice" << endl;
        cout << "     6.2 Sume minima in triunghi" << endl;
        cout << "     6.3 Gasire cuvant intr-un alfabet --not-done--" << endl;
        cout << "     6.0 Iesire meniu 6" << endl;
        cout << "Optiunea meniu 6: ";
        cin >> opt6;
        switch (opt6)
        {
        case 1:
        {
            cout << "     Produs optim de matrice" << endl;
            int n, p[20];
            cout << "Numar de matrice: ";
            cin >> n;
            cout << "Dimensiunile matricelor: ";
            for (int i = 1; i <= n + 1; i++)
                cin >> p[i];
            int pm = produsMatrice(n, p);
            cout << "Numarul minim de inmultiri este: " << pm << endl;
            break;
        }
        break;
        case 2:
        {
            cout << "Sume minima in triunghi" << endl;
            sumaMinimaInTriunghi();
        }
        break;
        case 0:
            cout << "Iesire din meniul 6" << endl;
            break;
        default:
            cout << "Optiune invalida pentru meniul 6" << endl;
            break;
        }
    } while (opt6 != 0);
}

void capitol7()
{
    int opt7;
    do
    {
        cout << "   7.METODA RAMIFICA SI MARGINESTE" << endl;
        cout << "     7.1 Jocul Perspico" << endl;
        cout << "Optiunea meniu 7: ";
        cin >> opt7;
        switch (opt7)
        {
        case 1:
            cout << "Jocul perspico: " << endl;
            jocul_perspico();
            break;
        case 0:
            cout << "Iesire din meniul 7" << endl;
            break;
        default:
            cout << "Optiune invalida pentru meniul 7" << endl;
            break;
        }
    } while (opt7 != 0);
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
