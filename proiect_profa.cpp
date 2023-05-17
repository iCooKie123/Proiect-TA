#include <iostream>

using namespace std;

// Student: ****** *****
// subgrupa: 1331B
// subgrupa 1332A

// tipuri de variabile

// variabile globale

int xr[100], nr_sol_r;

// functii ale utilizatorului
//*******************
// functii capitol 1
//*******************
void verificare_CMMDC()
{

}

void norme_matriciale()
{

}

void capitol1()
{
    int op1; // optiune capitol 1
    do
    {
        cout<<"1. Exemple de algoritmi\n\n";
        cout<<"   1.1. Verificare c.m.m.d.c. elemente sir Fibonacci \n";
        cout<<"   1.2. Calcul norme matriciale \n";
        cout<<"   1.0. Incheiere capitol 1 \n\n";
        cout<<"Optiune capitol1: "; cin>>op1; cout<<endl;
        switch (op1)
        {
        case 1:
            verificare_CMMDC();
            break;

        case 2:
            norme_matriciale();
            break;

        case 0:
            cout<<"Incheiere capitol 1\n";
            break;

        default:
            cout<<"Optiune invalida!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op1!=0); // end while op1 capitol 1
}

//*******************
// functii capitol 2
//*******************

int validare_permutari(int x[100],int k)
{
    for(int i=1;i<k;i++)
        if (x[i]==x[k])
           return 0;
    return 1;
}

void generare_permutari(int n)
{
    // A_k={1, 2, ..., n}; a_k=1; p_k=1; b_k=n
    int i,k,nrs=0,v,x[100];
    k=1;
    x[1]=0; // a_1-p_1
    while (k>0)
    {
        v=0; // v=0 daca nu este verificata conditia de validare
        while ((v == 0) && (x[k]+1) <= n)
        {
            x[k]=x[k]+1;
            v=validare_permutari(x,k);
        } // end while alege x[k]
        if (v == 0)
            k=k-1;
        else
        {
            if (k == n)
            {
                nrs++;
                // scrie solutie
                for(i=1;i<=n;i++)
                    cout<<x[i]<<" ";
                cout<<endl;
            }
            else
            {
                k++;
                x[k]=0; // a_k-p_k
            }
        }
    } // end while k>0
    if  (n==0)
        nrs=1;
    cout<<"Numarul de permutari de "<<n<<" elemente este "<<nrs<<endl;
}

void capitol2()
{
    int op2; // optiune capitol 2
    do
    {
        cout<<"2. Metoda backtracking\n\n";
        cout<<"   2.1. Generarea permutarilor \n";
        cout<<"   2.2. Generarea combinarilor \n";
        cout<<"   2.3. Generarea aranjamentelor \n";
        cout<<"   2.4. Problena reginelor \n";
        cout<<"   2.5. Problema turnurilor \n";
        cout<<"   2.6. Problema calutilor\n";
        cout<<"   2.7. Problema comisului voiajor \n";
        cout<<"   2.8. Problema parantezelor \n";
        cout<<"   2.0. Incheiere capitol 2 \n\n";
        cout<<"Optiune capitol 2: "; cin>>op2; cout<<endl;
        switch (op2)
        {
        case 1:
            //generare_permutari();
            int n;
            cout<<"Generarea permutarilor de n = "; cin>>n;
            generare_permutari(n);
            break;

        case 2:
            //generare_combinari();
            break;

        case 3:
            //generare_aranjamente();
            break;

        case 4:
            //problema_reginelor();
            break;


        case 0:
            cout<<"Incheiere capitol 2\n";
            break;

        default:
            cout<<"Optiune invalida capitol 2!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op2!=0); // end while op2 capitol 2
}

//*******************
// functii capitol 3
//*******************
void recursiv_back_permutari(int n,int k)
{
    if ( k == n+1 )
    {
        // a juns la o solutie
        nr_sol_r++;
        for(int i=1; i <= n;i++)
            cout<<xr[i]<<" ";
        cout<<endl;
    }
    else // alegem x[k]
    {
        for(int i=1; i <= n; i++)
        {
            xr[k]=i;
            if  (validare_permutari(xr,k)) // merge sa aleaga x[k+1]
                 recursiv_back_permutari(n,k+1)    ;
        }
    }
}

//********************
void capitol3()
{
    int op3; // optiune capitol 3
    do
    {
        cout<<"3. Metoda recursiva\n\n";
        cout<<"   3.1. Backtracking recursiv (pentru o problema de la backtracking)\n";
        cout<<"   3.2. Functia Ackermann - recursiva \n";
        cout<<"   3.3. Functia Ackermann - iterativa \n";
        cout<<"   3.4. Descompunerea in factori primi - rercursiv \n";
        cout<<"   3.5. Schimbarea bazei de numeratie - recursiv \n";
        cout<<"   3.6. Numarul de partitii pentru o multime \n";
        cout<<"   3.7. Exemplu de recursivitate indirecta: miscarea unui punct, pe ecran, in mod text \n";
        cout<<"   3.0. Incheiere capitol 3 \n\n";
        cout<<"Optiune capitol 3: "; cin>>op3; cout<<endl;
        switch (op3)
        {
        case 1:
            //o problema de la backtracking recursiv);
            // exemplu pentru generarea permutarilor
            int n;
            cout<<" n = "; cin >>n;
            nr_sol_r=0;
            recursiv_back_permutari(n,1);
            cout<<"Numarul de permutari de "<<n<<" este "<<nr_sol_r<<endl<<endl;
            break;

        case 2:
            //
            break;

        case 3:
            //
            break;

        case 4:
            //
            break;


        case 0:
            cout<<"Incheiere capitol 3\n";
            break;

        default:
            cout<<"Optiune invalida capitol 3!!!\n\n";
            break;
        }// end switch meniu principal


    }while(op3!=0); // end while op3 capitol 3
}

//*******************
// functii capitol 4
//*******************
void capitol4()
{
    int op4; // optiune capitol 4
    do
    {
        cout<<"4. Metoda divide et impera\n\n";
        cout<<"   4.1. Quicksort\n";
        cout<<"   4.2. Cautare binara \n";
        cout<<"   3.3. Turnurile din Hanoi \n";
        cout<<"   3.4. Minim si maxim dintr-un sir de numare naturale \n";
        cout<<"   3.5. CMMDC a n numere naturale\n";
        cout<<"   3.0. Incheiere capitol 4 \n\n";
        cout<<"Optiune capitol 4: "; cin>>op4; cout<<endl;
        switch (op4)
        {
        case 1:
            // quicksort;

            break;

        case 2:
            // cautare binara
            break;

        case 3:
            // turnurile din Hanoi
            break;

        case 4:
            //min-max
            break;
        case 5:
            // CMMDC
            break;


        case 0:
            cout<<"Incheiere capitol 4\n";
            break;

        default:
            cout<<"Optiune invalida capitol 4!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op4!=0); // end while op4 capitol 4
}

//*******************
// functii capitol 5
//*******************
void capitol5()
{
    int op5; // optiune capitol 5
    do
    {
        cout<<"5. Metoda Greedy\n\n";
        cout<<"   5.1. Problema comisului voiajor (varianta Greedy\n";
        cout<<"   5.2. Plata unei sume (nelimitat)\n";
        cout<<"   5.3. Plata unei sume (limitat)\n";
        cout<<"   5.4. Acoperire tabla nxn de calut\n";
        cout<<"   5.0. Incheiere capitol 5 \n\n";
        cout<<"Optiune capitol 5: "; cin>>op5; cout<<endl;
        switch (op5)
        {
        case 1:
            // voiajor;

            break;

        case 2:
            // suma nelimitat
            break;

        case 3:
            // suma limitat
            break;

        case 4:
            //tabla nxn
            break;


        case 0:
            cout<<"Incheiere capitol 5\n";
            break;

        default:
            cout<<"Optiune invalida capitol 5!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op5!=0); // end while op5 capitol 5
}

//*******************
// functii capitol 6
//*******************
void capitol6()
{
    int op6; // optiune capitol 6
    do
    {
        cout<<"6. Programare dinamica\n\n";
        cout<<"   6.1. Minim de inmultiri in produs de matrice\n";
        cout<<"   6.2. Sume minima in triunghi\n";
        cout<<"   6.3. Gasire cuvant intr-un alfabet\n";
        cout<<"   6.0. Incheiere capitol 6 \n\n";
        cout<<"Optiune capitol 6: "; cin>>op6; cout<<endl;
        switch (op6)
        {
        case 1:
            // minim produs matrice;

            break;

        case 2:
            // suma minima in triunghi
            break;

        case 3:
            // alfabet
            break;

        case 0:
            cout<<"Incheiere capitol 6\n";
            break;

        default:
            cout<<"Optiune invalida capitol 6!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op6!=0); // end while op6 capitol 6
}

//*******************
// functii capitol 7
//*******************
void capitol7()
{
    int op7; // optiune capitol 7
    do
    {
        cout<<"7. Metoda 'branch and bound'\n\n";
        cout<<"   7.1. Jocul Perspico\n";
        cout<<"   7.0. Incheiere capitol 7 \n\n";
        cout<<"Optiune capitol 7: "; cin>>op7; cout<<endl;
        switch (op7)
        {
        case 1:
            // jocul Perspico

            break;

         case 0:
            cout<<"Incheiere capitol 7\n";
            break;

        default:
            cout<<"Optiune invalida capitol 7!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op7!=0); // end while op7 capitol 7

}


//*******************
// functii capitol 8
//*******************
void capitol8()
{
    int op8; // optiune capitol 8
    do
    {
        cout<<"8. Algoritmi probabilisti\n\n";
        cout<<"   8.1. Acul lui Buffon\n";
        cout<<"   8.2. Aruncare sageata\n";
        cout<<"   8.3. Aproximare integrala\n";
        cout<<"   8.4. Exemplu de alg Monte-Carlo: eliminarea nodurilor intr-un graf\n";
        cout<<"   8.5. Exemplu de alg Las Vegas: problema reginelor (rezolvare probabilista)\n";
        cout<<"   8.0. Incheiere capitol 8 \n\n";
        cout<<"Optiune capitol 8: "; cin>>op8; cout<<endl;
        switch (op8)
        {
        case 1:
            // Buffon;

            break;

        case 2:
            // aruncare sageata
            break;

        case 3:
            // aproximare integrala
            break;

        case 4:
            // eliminarea nodurilor intr-un graf
            break;

        case 5:
            // problema reginelor -  rezolvare probabilista

            break;

        case 0:
            cout<<"Incheiere capitol 8\n";
            break;

        default:
            cout<<"Optiune invalida capitol 8!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op8!=0); // end while op5 capitol 8
}


//*******************
// functii capitol 9
//*******************
void capitol9()
{
    int op9; // optiune capitol 7
    do
    {
        cout<<"9. Metoda 'branch and bound'\n\n";
        cout<<"   9.1. Maximul unei functii cu valori reale\n";
        cout<<"   9.0. Incheiere capitol 9 \n\n";
        cout<<"Optiune capitol 9: "; cin>>op9; cout<<endl;
        switch (op9)
        {
        case 1:
            //Maximul unei functii cu valori reale

            break;

         case 0:
            cout<<"Incheiere capitol 9! \n";
            break;

        default:
            cout<<"Optiune invalida capitol 9!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op9!=0); // end while op9 capitol 9
}

//*******************
// PROGRAM PRINCIPAL
//*******************
int main()
{
    int op; // optiune meniu principal
    do
    {
        cout<<"Programe TEORIA ALGORITMILOR\n\n";
        cout<<"1. Exemple de algoritmi \n";
        cout<<"2. Metoda backtracking \n";
        cout<<"3. Recursivitate \n";
        cout<<"4. Divide et Impera\n";
        cout<<"5. Metoda Greedy\n";
        cout<<"6. Programare dinamica\n";
        cout<<"7. Metoda 'branch and bound'\n";
        cout<<"8. Algoritmi probabilisti\n";
        cout<<"9. Algoritmi genetici\n";
        cout<<"0. Iesire din program \n\n";
        cout<<"Optiune: "; cin>>op; cout<<endl;
        switch (op)
        {
        case 1: // probleme diverse
            capitol1();
            break;

        case 2: // backtracking
            capitol2();
            break;

        case 3: // recursivitate
            capitol3();
            break;

        case 4: // divide et impera
            capitol4();
            break;

        case 5: // Metoda Greedy
            capitol5();
            break;

        case 6: // Programare dinamica
            capitol6();
            break;

        case 7: // Metoda "branch and bound"
            capitol7();
            break;

        case 8: // Algoritmi probabilisti
            capitol8();
            break;

        case 9: // Metoda Greedy
            capitol9();
            break;

        case 0:
            cout<<"Incheiere program. La revedere!\n";
            break;

        default:
            cout<<"Optiune invalida!!!\n\n";
            break;
        }// end switch meniu principal

    }while(op!=0); // end while op meniu principal
    return 0;
}
