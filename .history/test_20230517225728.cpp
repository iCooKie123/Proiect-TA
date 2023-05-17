#include<iostream>
#include<cmath>
#include<iomanip>


// Lista de probleme
// Rezolvari din capitolul 1: EXEMPLE DE ALGORITMI
//     1.1. Norme de matrici
//     1.2. Metoda coardei pentru ecuatii in R
//     1.3. Metoda tangentei pentru ecuatii in R
// Rezolvari pentru capitolul 2: METODA BACKTRACKING
//     2.1. Generarea permutarilor
//     2.2. Generarea combinarilor
//     2.3. Generarea aranjamentelor
//     2.4. Problema reginelor
//     2.5. Problema turelor
//     2.6. Problema calutilor
//     2.7. Problema comis voiajor
//     2.8. Problema parantezelor
// Rezolvari pentru capitolul 3: RECURSIVITATE
//     3.1. Calcului Factoriarulului
//     3.2. Sirul lui Fibonacci
//     3.3. Functia Ackerman(recursiv)
//     3.4. Functia Ackerman(iterativa)
//     3.5. Backtracking Recursiv
//     3.6. Problema Labirintului
//     3.7. Descompunerea in factori primi
//     3.8. Trecerea din baza 10 in alta baza
//     3.9. Numarul de partitii ale unei multimi
// Rezolvari din capitolul 4: DIVIDE ET IMPERA
//     4.1. Sortare prin Interclasare
//     4.2. Sortare rapida (quikSort)
//     4.3. Cautare binara
//     4.4. Maximul unui sir de numere
//     4.5. Minimul unui sir de numere
//     4.6. Turnurile din Hanoi
//     4.7. CMMDC a n numere
// Rezolvari din capitolul 5: METODA GREEDY
//     5.1. Problema Comisului Voiajor
//     5.2. Plata unei sume cu numar nelimitat de bancnote
//     5.3. Plata unei sume cu numar limitat de bancnote
// Rezolvari din capitolul 6: PROGRAMARE DINAMICA
//     6.1. Produs optim de matrice
//     6.2. Suma maxima intru-un triunghi de numere
//     6.3. Compunere intr-un alfabet

using namespace std;

// definitie de tipuri
// variabile globale
// functii

float norma_infinit(int n, float M[10][10])
{
    // calculeaza norma infinit pentru o matrice M patratica de ordin n
    int i,j;
    float maxim=0;
    for(i=0;i<n;i++)
    {
        float sum=0;
        for(j=0;j<n;j++)
            sum=sum+fabs(M[i][j]);
        if(maxim<sum)
            maxim=sum;
    }
    return maxim;
}

float norma1(int n, float M[10][10])
{
    // calculeaza norma 1 pentru o matrice M patratica de ordin n
    int i,j;
    float maxim=0;
    for(j=0;j<n;j++)
    {
        float sum=0;
        for(i=0;i<n;i++)
            sum=sum+fabs(M[i][j]);
        if(maxim<sum)
            maxim=sum;
    }
    return maxim;
}

float f(float x)
{
    return x*x-5;
}

float fp(float x)
{
    return 2*x;
}

void metoda_coardei()
{
    float a,b,eps,x1,x2,er;
    int n; // nr de iteratii
    cout<<"Intervalul pe care este definita functia:";
    cin>>a>>b;
    cout<<"Marja de eroare este:";
    cin>>eps;
    x1=a-f(a)*(b-a)/(f(b)-f(a));
    cout<<scientific<<setprecision(10)<<x1<<endl;
    n=1;
    do
    {
        x2=x1-f(x1)*(b-x1)/(f(b)-f(x1));
        cout<<scientific<<setprecision(10)<<x2<<endl;
        er=fabs(x2-x1);
        x1=x2;
        n++;
    }
    while(er>eps);
    cout<<"solutia: "<<scientific<<setprecision(10)<<x1<<"cu eroarea: "<<scientific<<setprecision(10)<<eps<<endl;
    cout<<"s-au obtinut in "<<n<<" iteratii"<<endl;
}

void metoda_tangentei()
{
    float a,b,eps,err,x1;
    cout<<"a=";cin>>a;
    cout<<"b=";cin>>b;
    cout<<"Marja de eroare este:";cin>>eps;
    float x0=a-f(a)/fp(a);
    do
    {
        x1=x0-f(x0)/fp(x0);
        cout<<x1<<endl;
        err=abs(x1-x0);
        x0=x1;

    }while(err>eps);
    cout<<"Solutia "<<x1<<" la aprox "<<eps;
}

bool validarePermutari(int y,int k,int x[20])
{
    for(int j=1;j<k;j++)
        if(x[j]==y)
            return false;
    return true;
}

bool validareCombinari(int k,int x[20])
{
    if(x[k]>x[k-1])
        return true;
    return false;
}

bool validareAranjamente(int y,int k,int x[20])
{
    for(int j=1;j<k;j++)
        if(x[j]==y)
            return false;
    return true;
}

bool validareRegine(int y,int k,int x[20])
{
    for(int j=1;j<k;j++)
        if(y==x[j] || (abs(y-x[j])==abs(k-j)))
            return false;
    return true;
}

bool validareTure(int y,int k,int x[20])
{
    for(int j=1;j<k;j++)
        if(y==x[j])
            return false;
    return true;
}

bool validareCaluti(int y,int k,int x[20])
{
    if((x[k]-2==x[k-1])||(x[k]+2==x[k+1]) || ((x[k]-1==x[k-2])) || (x[k]+1==x[k-2]))
            return false;
    return true;
}

bool validareComisVoiajor()
{
    return true;
}

bool validareParanteze(int k,int n,int x[20])
{
    int nd=0,ni=0;
    for(int j=1;j<k;j++)
        if(x[j]==1)
            nd++;
    else ni++;
    if(nd>=ni && nd<=n/2)
        return true;
    else return false;
}

void afisareVector(int x[20],int n)
{
    for(int i=1;i<=n;i++)
        cout<<x[i]<<' ';
    cout<<endl;
}

void generarePermutari(int n)
{
    int k=1,nr_sol=0,v=0,x[20]={0};
    x[1]=0;
    while(k>0)
    {
        v=0;
        while(v==0 && x[k]+1<=n)
        {
            x[k]=x[k]+1;
            if(validarePermutari(x[k],k,x)==true)
                v=1;
        }
        if(v==0)
            k--;
        else
        {
            if(k==n)
            {
                nr_sol++;
                afisareVector(x,n);
            }
            else
            {
                k++;
                x[k]=0;
            }

        }
    }
    cout<<"Numarul de permutari de "<<n<<" elemente este: "<<nr_sol<<endl;
}

void generareCombinari(int n,int m)
{
    int k=1,nr_sol=0,v=0,x[20]={0};
    x[1]=0;
    while(k>0)
    {
        v=0;
        while(v==0 && x[k]+1<=n)
        {
            x[k]=x[k]+1;
            if(validareCombinari(k,x)==true)
                v=1;
        }
        if(v==0)
            k--;
        else
        {
            if(k==m)
            {
                nr_sol++;
                afisareVector(x,m);
            }
            else
            {
                k++;
                x[k]=0;
            }

        }
    }
    cout<<"Numarul de combinari de "<<m<<" elemente este: "<<nr_sol<<endl;
}

void generareAranjamente(int n,int m)
{
    int k=1,nr_sol=0,v=0,x[20]={0};
    x[1]=0;
    while(k>0)
    {
        v=0;
        while(v==0 && x[k]+1<=n)
        {
            x[k]=x[k]+1;
            if(validareAranjamente(x[k],k,x)==true)
                v=1;
        }
        if(v==0)
            k--;
        else
        {
            if(k==m)
            {
                nr_sol++;
                afisareVector(x,m);
            }
            else
            {
                k++;
                x[k]=0;
            }

        }
    }
    cout<<"Numarul de combinari de "<<m<<" elemente este: "<<nr_sol<<endl;
}

void generareRegine(int n)
{
    int k=1,nr_sol=0,v=0,x[20]={0};
    x[1]=0;
    while(k>0)
    {
        v=0;
        while(v==0 && x[k]+1<=n)
        {
            x[k]=x[k]+1;
            if(validarePermutari(x[k],k,x)==true)
                v=1;
        }
        if(v==0)
            k--;
        else
        {
            if(k==n)
            {
                nr_sol++;
                afisareVector(x,n);
            }
            else
            {
                k++;
                x[k]=0;
            }

        }
    }
    cout<<"Numarul de posibilitati: "<<nr_sol<<endl;
}

void generareTure(int n)
{
    int k=1,nr_sol=0,v=0,x[20]={0};
    x[1]=0;
    while(k>0)
    {
        v=0;
        while(v==0 && x[k]+1<=n)
        {
            x[k]=x[k]+1;
            if(validareTure(x[k],k,x)==true)
                v=1;
        }
        if(v==0)
            k--;
        else
        {
            if(k==n)
            {
                nr_sol++;
                afisareVector(x,n);
            }
            else
            {
                k++;
                x[k]=0;
            }

        }
    }
    cout<<"Numarul de posibilitati: "<<nr_sol<<endl;
}

void generareCaluti(int n)
{
    int k=1,nr_sol=0,v=0,x[20]={0};
    x[1]=0;
    while(k>0)
    {
        v=0;
        while(v==0 && x[k]+1<=n)
        {
            x[k]=x[k]+1;
            if(validareCaluti(x[k],k,x)==true)
                v=1;
        }
        if(v==0)
            k--;
        else
        {
            if(k==n)
            {
                nr_sol++;
                afisareVector(x,n);
            }
            else
            {
                k++;
                x[k]=0;
            }

        }
    }
    cout<<"Numarul de posibilitati: "<<nr_sol<<endl;
}

void generareComisVoiajor(int n)
{
    int k=1,nr_sol=0,v=0,x[20]={0};
    x[1]=0;
    while(k>0)
    {
        v=0;
        while(v==0 && x[k]+1<=n)
        {
            x[k]=x[k]+1;
            if(validareCaluti(x[k],k,x)==true)
                v=1;
        }
        if(v==0)
            k--;
        else
        {
            if(k==n)
            {
                nr_sol++;
                afisareVector(x,n);
            }
            else
            {
                k++;
                x[k]=0;
            }

        }
    }
    cout<<"Numarul de posibilitati: "<<nr_sol<<endl;
}

void generareParanteze()
{
    int p,n,r,t,k=1,nr_sol=0,x[20]={0},v=0,k1=0,v1=0;
    cout<<"p=";cin>>p;
    cout<<"n=";cin>>n;
    cout<<"r=";cin>>r;
    cout<<"t=";cin>>t;
    int s=p-r;
    x[k]=0;
    while(k>0)
    {
        v=0;
        while(v==0 && x[k]+1<=t)
        {
            x[k]=x[k]+1;
            if(validareParanteze(x[k],k,x)==true)
                v=1;
        }
        if(v==0)
            k--;
        else
        {
            if(k==r)
            {
                k1=1;
                x[r+k1]=t;
                while(k1>0)
                {
                    v1=0;
                    while(v1==0 && x[r+k1]<=n)
                    {
                        x[r+k1]=x[r+k1]+1;
                        if(validareParanteze(x[r+k1],r+k1,x)==true)
                            v1=0;

                    }
                    if(v1==0)
                        k1=k1-1;
                    else
                    {
                        if(k1==s)
                        {
                            nr_sol++;
                            afisareVector(x,p);
                        }
                        else
                        {
                            k1++;
                            x[r+k1]=t;
                        }
                    }
                }
            }
            else
            {
                k++;
                x[k]=0;
            }
        }
    }
}

int factorial(int n)
{
    if(n==0 || n==1) return 1;
    else return n*factorial(n-1);
}

int fibonacci(int n)
{
    if(!n)
        return 0;
    else if(n==1)
        return 1;
    else return fibonacci(n-2)+fibonacci(n-1);
}

int ackermannRecursiv(int m,int n)
{
    if(m==0)
        return n+1;
    if(n==0)
        return ackermannRecursiv(m-1,1);
    else return ackermannRecursiv(m-1,ackermannRecursiv(m,n-1));
}

void ackermannIterativ(int k)
{
    int m,n,a[100]={0};
    cout<<"m=";cin>>m;
    cout<<"n=";cin>>n;
    a[1]=m;
    a[2]=n;
    while(k>1)
    {
        if(a[k-1]==0)
        {
            a[k-1]=a[k]+1;
            k--;
        }
        else if(a[k]==0)
        {
            a[k-1]=a[k-1]-1;
            a[k]=1;
        }
        else
        {
            a[k+1]=a[k]-1;
            a[k]=a[k-1];
            a[k-1]=a[k-1]-1;
            k++;
        }
    }
    cout<<a[1]<<endl;
}

void afiseazaRec(int st[20],int n)
{
    for(int i=1;i<=n;i++)
        cout<<st[i]<<' ';
    cout<<endl;
}

bool validRecursiv(int st[20],int k)
{
    for(int i=1;i<k;i++)
        if(st[i]==st[k])
            return false;
    return true;
}

void backT(int st[20],int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        st[k]=i;
        if(validRecursiv(st,k)==true)
            if(k==n)
                afiseazaRec(st,n);
            else backT(st,k+1,n);
    }
}

void problemaLabirintului(int i,int j,int a[10][10],int n,int m)
{
    if(i<n)
    {
        if(a[i][j]==1)
        {
            cout<<i<<' '<<j<<endl;
            problemaLabirintului(i+1,j,a,n,m);
        }
        else if(j<m)
            problemaLabirintului(i-1,j+1,a,n,m);
    }
}

void descompunereFacPrimi(int n,int d)
{
    if(n>1)
        if(n%d==0)
        {
            cout<<d<<" ";
            descompunereFacPrimi(n/d,d);
        }
        else descompunereFacPrimi(n,d+1);
}

void schimbareBaza(int n,int b)
{
    if(n>0)
    {
        schimbareBaza(n/b,b);
        cout<<n%b;
    }
}

int partitie(int n,int k)
{
    if(k==1 || k==n)
        return 1;
    if(k==2)
        return ((pow(2,n-1))-1);
    if(k>n)
        return 0;
    return partitie(n-1,k-1)+k*partitie(n-1,k);
}

void coborare(int l,int n);

void urcare(int l,int n)
{
    if(l==1)
        coborare(l+1,n);
    else urcare(l-1,n);
}

void coborare(int l,int n)
{
    if(l==n)
        urcare(l-1,n);
    else coborare(l+1,n);

}

int combinareAlgEuclid(int a,int b)
{
    while(a!=b)
        if(a>b)
            a=a-b;
        else b=b-a;
    return a;
}

int cmmdc(int v[100],int st,int dr)
{
    for(int i=st;i<=dr;i++)
        cout<<v[i]<<' ';
    cout<<endl;
    if(st<dr)
    {
        int m=(st+dr)/2;
        int c1=cmmdc(v,st,m);
        int c2=cmmdc(v,m+1,dr);
        int c=combinareAlgEuclid(c1,c2);
        cout<<c<<endl;
        return c;
    }
    return v[st];
}

void interclasare(int a[100],int st,int m,int dr)
{
    int b[100]={0};
    int i=0,j=st,k;
    while(j<=m)
        b[i++]=a[j++];
    i=0;
    k=st;
    while(k<j && j<=dr)
        if(b[i]<=a[j])
            a[k++]=b[i++];
    else a[k++]=a[j++];
    while(k<j)
        a[k++]=b[i++];
}

void sortareInterclasare(int a[100],int st,int dr)
{
    if(st<dr)
    {
        int m=(st+dr)/2;
        sortareInterclasare(a,st,m);
        sortareInterclasare(a,m+1,dr);
        interclasare(a,st,m,dr);
    }
}

int poz(int v[100],int st,int dr)
{
    int pozitie=st;
    for(int i=st;i<=dr;i++)
        if(v[i]>v[dr])
        {
            int aux=v[i];
            v[i]=v[dr];
            v[dr]=aux;
            pozitie++;
        }
    return pozitie;
}

void quikSort(int v[100],int st,int dr)
{
    if(st<dr)
    {
        int m=poz(v,st,dr);
        quikSort(v,st,m-1);
        quikSort(v,m+1,dr);
    }
}

int cautareBinara(int v[100],int st,int dr,int x)
{
    if(st>dr)
        return -1;
    else
    {
        int m=(st+dr)/2;
        if(x==v[m])
            return m;
        if(x<v[m])
            return cautareBinara(v,st,m-1,x);
        else return cautareBinara(v,m+1,dr,x);
    }
}

int maxim(int v[100],int i,int j)
{
    if(i==j)
        return v[i];
    else
    {
        int a=maxim(v,i,(i+j)/2);
        int b=maxim(v,(i+j)/2+1,j);
        if(a>b)
            return a;
        else return b;
    }
}

int minim(int v[100],int i,int j)
{
    if(i==j)
        return v[i];
    else
    {
        int a=minim(v,i,(i+j)/2);
        int b=minim(v,(i+j)/2+1,j);
        if(a<b)
            return a;
        else return b;
    }
}

void hanoi(int n, char a, char b, char c)
{
    if(n==1)
    {
         cout<<a<<b<<endl;
    }
    else
    {
        hanoi(n-1,a,c,b);
        cout<<a<<b<<endl;
        hanoi(n-1,c,b,a);
    }
}

void comisVoiajorG()
{
    int s[10],a[10][10],n,i,j,v,p,vs,vs1,mint,cost;
    cout<<"Numar noduri: ";cin>>n;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            cin>>a[i][j];
        a[j][i]=a[i][j];
        cout<<"Nod de pornire: ";cin>>v;
        s[v]=1;
        vs1=v;
        cout<<"Drumul trece prin: "<<v<<' ';
        p=v;
        for(i=1;i<n;i++)
        {
            mint=3000;
            for(j=1;j<=n;j++)
            if(a[v][j]!=0&&s[j]==0&&mint>a[v][j])
            {
                mint=a[v][j];
                vs=j;
            }
            cost=cost+a[v][vs];
            cout<<vs<<' ';
            s[vs]=1;
            v=vs;
        }
        cout<<p<<endl;
        cost=cost+a[vs1][v];
        cout<<"Cost: "<<cost<<endl;
}

void plataBancnoteNelimitat()
{
    int n,v[10],N[10],s;
    cout<<"Numar de bancnote n=";cin>>n;
    cout<<"Valorile bancnotelor sunt in ordine descrescatoare"<<endl;
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<"Dati suma s=";cin>>s;
    int sc=s;
    int T=0;
    for(int i=0;i<n;i++)
    {
        N[i]=sc/v[i];
        sc=sc%v[i];
        T=T+N[i]*v[i];
    }
    if(s==T)
    {
        cout<<s<<'=';
        for(int i=0;i<n;i++)
        {
            cout<<N[i]<<'*'<<v[i];
            if(i<n-1)
                cout<<'+';
        }
        cout<<endl;
    }
    else cout<<"Algoritmul Greedy nu a gasit solutia"<<endl;
}

void plataBancnoteLimitat()
{
    int b[2][7]={1,5,10,50,100,200,500},S,ss=0,n;
    cout<<"S=";cin>>S;
    for(int i=0;i<7;i++)
    {
        cin>>b[1][i];
        ss=ss+b[0][i]*b[1][i];

    }
    if(ss<S)
        cout<<"Nu are solutie"<<endl;
    else
        for(int i=6;i>=0&&S;i--)
        {
            n=S/b[0][i];
            if(n>b[1][i])
                n=b[1][i];
            cout<<n<<" bancnote cu valoarea "<<b[0][i]<<endl;
            S=S-n*b[0][i];
        }
}

int produsMatrice(int n,int p[20])
{
    int M[20][20]={0};
    int minim,k0,v;
    cout<<n<<endl;
    for(int i=1;i<=n+1;i++)
        cout<<p[i]<<' ';
    cout<<endl;
    for(int i=n-1;i>=1;i--)
        for(int j=i+1;j<=n;j++)
        {
            minim=M[i][i]+M[i+1][j]+p[i]*p[i+1]*p[j+1];
            k0=i;
            for(int k=i+1;k<=j-1;k++)
            {
                v=M[i][k]+M[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(v<minim)
                {
                    minim=v;
                    k0=k;
                }
            }
            M[i][j]=minim;
            M[j][i]=k0;
        }
    cout<<"Matricea M este: ";
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
    return M[1][n];
}

void parantezare_compunere(int i, int j, int A[10][10][10], int B[10][10][10], int m) {
    int k,c;
    ///Parantezeaza compunerea de la xi la xj
    if(i<j) { ///Cautam c intre 1 si m astfel incat B[i][j][c] = k
        for(c=1;c<=m;c++) { ///c de la 1 la m
            if(B[i][j][c]!=0)
                break;
        }
        k=B[i][j][c];
        if(i<k) {
            cout << "(";
            parantezare_compunere(i,k,A,B,m);
            cout << ")";
        } else {
            parantezare_compunere(i,k,A,B,m);
        }
        cout << "*";
        if(k+1<j) {
            cout << "(";
            parantezare_compunere(k+1,j,A,B,m);
            cout << ")";
        } else {
            parantezare_compunere(k+1,j,A,B,m);
        }
    } else {
        cout << "x[" << i << "]";
    }
}

bool compunere_alfabet(int m,int n,int M[10][10],int x[100],int y)
{
    bool ok=false;
    int i,j,c,cd,c1,c2,k,pas=0;
    int A[10][10][10]={0};
    int B[10][10][10]={0};
    for(i=1;i<=n;i++)
        for(c=1;c<=m;c++)
            if(x[i]==c){
                A[i][i][c]=1;
                B[i][i][c]=i;
            }
    //primul pas in calculul matricelor A
    cout<<"Pasul de initializare este pas="<<pas<<endl;
    for(c=1;c<=m;c++)
    {
        cout<<"Pentru c="<<c<<endl;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout<<A[i][j][c]<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
    for(cd=1;cd<n;cd++)
    {
        //cd contor pt codiagonale in stratul matricelor A
        pas++;
        for(i=1;i<=n-cd;i++)//n-cd = nr de elementele pe a cd diagonala
        {
            j=i+cd;
            //Calculam A[i][j][c]
            for(c=1;c<=m;c++)
                for(k=1;k<j;k++)
                   for(c1=1;c1<=m;c1++)
                        for(c2=1;c2<=m;c2++)
                            if(A[i][k][c1]==1 && A[k+1][j][c2]==1 && M[c1][c2]==c)
                            {
                                A[i][j][c]=1;
                                B[i][j][c]=k;
                            }

        }
        cout<<"La pasul pas="<<pas<<endl;
        for(c=1;c<=m;c++)
        {
            cout<<"Pentru c="<<c<<endl;
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                    cout<<A[i][j][c]<<' ';
                cout<<endl;
            }
            cout<<endl;
        }
    }
    if(A[1][n][y]==1)
    {
        cout << endl << y << " este o compunere a elementelor lui x" << endl;
        parantezare_compunere(1,n,A,B,m);
        ok=true;
    }
    else cout<<y<<" nu poate fi o compunere a elementelor lui x indiferent de asociere"<<endl;
    return ok;
}

void sumaMaximaInTriunghi()
{
    int A[10][10],n,i,j,S[10][10]={0},D[10][10]={0};
    cout<<"n=";cin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin>>A[i][j];
    for(int j=1;j<=n;j++)
        S[n][j]=A[n][j];
    for(i=n-1;i>=1;i--)
        for(j=1;j<=i;j++)
        {
            S[i][j]=A[i][j];
            if(S[i+1][j]>=S[i+1][j+1])
            {
                S[i][j]=S[i][j]+S[i+1][j];
                D[i][j]=i;
            }
            else
            {
                S[i][j]=S[i][j]+S[i+1][j+1];
                D[i][j]=j+1;
            }
        }
    cout<<S[1][1]<<' ';
    for(int i=2;i<=n;i++)
    {
        if(i==2)
            j=1;
        else j=D[i-1][j];
        cout<<i<<' '<<j<<endl;
    }

}

typedef struct nod {
    int c[4][4]; ///Matricea configuratiei
    int g; ///nivelul in arborele de configuratie
    int h; ///numarul de casute care nu sunt la locul lor
    /// h=0 pentru configuratia finala
    nod *parinte; ///Adresa nodului parinte
    nod *urm; ///Este adresa nodului urmator in lista L1 sau L2
    ///L1(sunt configuratii neexpandate) sau L2(sunt configuratii expandate)
    struct succesor { ///Lista succesorilor
        nod *n; ///Nod in arbore
        nod *urmator; ///Adresa nodului urmator din lista
    };
};

typedef struct lista_noduri { ///Lista de noduri
    nod *n; ///Nod in arbore
    nod *urmator; ///Adresa nodului urmator din lista
};

void jocul_perspico() {
    nod *radacina;
    lista_noduri *L1, *L2;
    int L[16]={0};
    int l,c,x,i,j;
    int X[4]={-1, 1, 0, 0};
    int Y[4]={0, 0, -1, 1};
    int C0[4][4];
    ///Citim configuratia initiala C0
    cout << "Citim configuratia initiala C0" << endl;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            cin >> C0[i][j];
    ///Verificam daca din C0 se poate ajunge in configuratia finala
    ///..... de completat din cursul 9
}

int main()
{
    int op,op1,opt2,opt3,opt4,opt5,opt6,opt7,opt8,opt9,m;
    float A[10][10],ni,n1;
    do
    {
        cout<<"Carnu Bianca-Maria_Program_TA_1332A"<<endl;
        cout<<"*********************************"<<endl<<endl;
        cout<<"   1.EXEMPLE DE ALGORITMI"<<endl;
        cout<<"   2.METODA BACKTRACKING"<<endl;
        cout<<"   3.RECURSIVITATE"<<endl;
        cout<<"   4.DIVIDE ET IMPERA"<<endl;
        cout<<"   5.METODA GREEDY"<<endl;
        cout<<"   6.PROGRAMARE DINAMICA"<<endl;
        cout<<"   7.METODA RAMIFICA SI MARGINESTE"<<endl;
        cout<<"   8.METODE PROBABILISTE"<<endl;
        cout<<"0.INCHEIERE PROGRAM"<<endl;
        cout<<"CITESTE OPTIUNE:";cin>>op;
        switch(op)
        {
            case 1:
                do
                {
                    cout<<"   1.EXEMPLE DE ALGORITMI"<<endl;
                    cout<<"     1.1 Norme de matrici"<<endl;
                    cout<<"     1.2 Metoda coardei pentru ec in R"<<endl;
                    cout<<"     1.3 Metoda tangentei pentru ec in R"<<endl;
                    cout<<"     1.0 Iesire din meniul 1"<<endl;
                    cout<<"         Citeste optiunea din meniul 1: ";cin>>op1;
                    switch(op1)
                    {
                        case 1:
                            cout<<"     Norme de matrici"<<endl;
                            cout<<"dimensiune matrice:";cin>>m;
                            for(int i=0;i<m;i++)
                                for(int j=0;j<m;j++)
                                {
                                    cout<<"A["<<i<<"]["<<j<<"]: ";
                                    cin>>A[i][j];
                                }
                            cout<<"matricea A este:"<<endl;
                            for(int i=0;i<m;i++)
                            {
                                for(int j=0;j<m;j++)
                                    cout<<A[i][j]<<" ";
                                cout<<endl;
                            }
                            ni=norma_infinit(m,A);
                            cout<<"Norma infinita a matricei A este: "<<ni<<endl;
                            n1=norma1(m,A);
                            cout<<"Norma 1 a matricei A este: "<<n1<<endl;
                            break;
                        case 2:
                            cout<<"     Metoda coardei pentru ec in R"<<endl;
                            metoda_coardei();
                            break;
                        case 3:
                            cout<<"     Metoda tangentei pentru ec in R"<<endl;
                            metoda_tangentei();
                            break;
                        case 0:
                            cout<<"Iesire din meniul 1"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 1"<<endl;
                            break;
                        }
                }while(op1);
                break;
            case 2:
                do
                {
                    cout<<"   2.METODA BACKTRACKING"<<endl;
                    cout<<"     2.1. Generarea permutarilor"<<endl;
                    cout<<"     2.2. Generarea combinarilor"<<endl;
                    cout<<"     2.3. Generarea aranjamentelor"<<endl;
                    cout<<"     2.4. Problema reginelor "<<endl;
                    cout<<"     2.5. Problema turelor "<<endl;
                    cout<<"     2.6. Problema calutilor "<<endl;
                    cout<<"     2.7. Problema comis voiajor "<<endl;
                    cout<<"     2.8. Problema parantezelor "<<endl;
                    cout<<"     2.0. Incheiere meniu 2"<<endl;
                    cout<<"Optiunea meniu 2: ";cin>>opt2;
                    switch(opt2)
                    {
                        case 1:
                            cout<<"     Generarea permutarilor"<<endl;
                            int n;
                            cout<<"Numar permutari: ";cin>>n;
                            generarePermutari(n);
                            break;
                        case 2:
                            cout<<"     Generarea combinarilor"<<endl;
                            int m;
                            cout<<"Numar elemente: ";cin>>n;
                            cout<<"Luate cate: ";cin>>m;
                            generareCombinari(n,m);
                            break;
                        case 3:
                            cout<<"     Generarea aranjamentelor"<<endl;
                            cout<<"Numar elemente: ";cin>>n;
                            cout<<"Luate cate: ";cin>>m;
                            generareAranjamente(n,m);
                            break;
                        case 4:
                            cout<<"     Problema reginelor "<<endl;
                            cout<<"Numar regine: ";cin>>n;
                            generareRegine(n);
                            break;
                        case 5:
                            cout<<"     Problema turelor "<<endl;
                            cout<<"Numar ture: ";cin>>n;
                            generareTure(n);
                            break;
                        case 6:
                            cout<<"     Problema calutilor "<<endl;
                            cout<<"Numar caluti: ";cin>>n;
                            generareCaluti(n);
                            break;
                        case 7:
                            cout<<"     Problema comis voiajor "<<endl;
                            cout<<"Mai ai de completat"<<endl;
                            break;
                        case 8:
                            cout<<"     Problema parantezelor "<<endl;
                            generareParanteze();
                            cout<<endl;
                            break;
                        case 0:
                            cout<<"Iesire din meniul 2"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 2"<<endl;
                            break;
                    }
                }while(opt2!=0);
                break;
            case 3:
                do
                {
                    cout<<"   3.RECURSIVITATE"<<endl;
                    cout<<"     3.1 Calculul Factorialului"<<endl;
                    cout<<"     3.2 Sirul lui Fibonacci"<<endl;
                    cout<<"     3.3 Funcita Ackermann(recursiv)"<<endl;
                    cout<<"     3.4 Funcita Ackermann(iterativa)"<<endl;
                    cout<<"     3.5 Backtracking Recursiv"<<endl;
                    cout<<"     3.6 Problema Labirintului"<<endl;
                    cout<<"     3.7 Descompunerea in factori primi"<<endl;
                    cout<<"     3.8 Trecerea din baza 10 in alta baza"<<endl;
                    cout<<"     3.9 Numarul de partitii ale unei multimi"<<endl;
                    cout<<"     3.10 Recursivitate indirecta"<<endl;
                    cout<<"Optiunea meniu 3: ";cin>>opt3;
                    switch(opt3)
                    {
                        case 1:
                            cout<<"     Calculul Factorialului"<<endl;
                            int n;
                            cout<<"n=";cin>>n;
                            cout<<n<<"!="<<factorial(n)<<endl;
                            break;
                        case 2:
                            cout<<"     Sirul lui Fibonacci"<<endl;
                            cout<<"n=";cin>>n;
                            cout<<fibonacci(n)<<endl;
                            break;
                        case 3:
                            cout<<"     Funcita Ackermann(recursiv)"<<endl;
                            int m;
                            cout<<"m=";cin>>m;
                            cout<<"n=";cin>>n;
                            cout<<ackermannRecursiv(m,n)<<endl;
                            break;
                        case 4:
                            cout<<"     Funcita Ackermann(iterativa)"<<endl;
                            int k;
                            cout<<"k=";cin>>k;
                            ackermannIterativ(k);
                            break;
                        case 5:
                            cout<<"     Backtracking Recursiv"<<endl;
                            cout<<"     Problema permutarillor"<<endl;
                            int st[20];
                            cout<<"n=";cin>>n;
                            backT(st,1,n);
                            break;
                        case 6:
                            cout<<"     Problema Labirintului"<<endl;
                            int a[10][10];
                            cout<<"Numarul de coloane este n=";cin>>n;
                            cout<<"Numarul de linii este m=";cin>>m;
                             for(int i=0;i<n;i++)
                                for(int j=0;j<m;j++)
                                    cin>>a[i][j];
                            problemaLabirintului(0,0,a,n,m);
                            break;
                        case 7:
                            cout<<"     Descompunerea in factori primi"<<endl;
                            cout<<"n=";cin>>n;
                            descompunereFacPrimi(n,2);
                            cout<<endl;
                            break;
                        case 8:
                            cout<<"     Trecerea din baza 10 in alta baza"<<endl;
                            int b;
                            cout<<"n=";cin>>n;
                            cout<<"b=";cin>>b;
                            schimbareBaza(n,b);
                            cout<<endl;
                            break;
                        case 9:
                            cout<<"     Numarul de partitii ale unei multimi"<<endl;
                            cout<<"n=";cin>>n;
                            cout<<"k=";cin>>k;
                            cout<<partitie(n,k)<<endl;
                            break;
                        case 10:
                            cout<<"     Recursivitate indirecta"<<endl;
                            int l;
                            cout<<"l=";cin>>l;
                            cout<<"n=";cin>>n;
                            urcare(l,n);
                            cout<<endl;
                            break;
                        case 0:
                            cout<<"Iesire din meniul 3"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 3"<<endl;
                            break;
                    }
                }while(opt3!=0);
                break;
            case 4:
                do
                {
                    cout<<"   4.DIVIDE ET IMPERA"<<endl;
                    cout<<"     4.1 Sortare prin Interclasare"<<endl;
                    cout<<"     4.2 Sortare rapida"<<endl;
                    cout<<"     4.3 Cautare binara"<<endl;
                    cout<<"     4.4 Maximul unui sir de numere"<<endl;
                    cout<<"     4.5 Minimul unui sir de numere"<<endl;
                    cout<<"     4.6 Turnurile din Hanoi"<<endl;
                    cout<<"     4.7 CMMDC a n numere"<<endl;
                    cout<<"Optiunea meniu 4: ";cin>>opt4;
                    switch(opt4)
                    {
                        case 1:
                            cout<<"     Sortare prin Interclasare"<<endl;
                            int a[100],n;
                            cout<<"n=";cin>>n;
                            for(int i=0;i<n;i++)
                                cin>>a[i];
                            sortareInterclasare(a,0,n-1);
                            for(int i=0;i<n;i++)
                                cout<<a[i]<<' ';
                            cout<<endl;
                            break;
                        case 2:
                            cout<<"     Sortare rapida"<<endl;
                            cout<<"n=";cin>>n;
                            for(int i=0;i<n;i++)
                                cin>>a[i];
                            quikSort(a,0,n-1);
                            for(int i=0;i<n;i++)
                                cout<<a[i]<<' ';
                            cout<<endl;
                            break;
                        case 3:
                            cout<<"     Cautare binara"<<endl;
                            int x;
                            cout<<"x=";cin>>x;
                            cout<<"n=";cin>>n;
                            for(int i=0;i<n;i++)
                                cin>>a[i];
                            cout<<x<<" se  gaseste in sir pe pozitia "<<cautareBinara(a,0,n-1,x)+1<<endl;
                            break;
                        case 4:
                            cout<<"     Maximul unui sir de numere"<<endl;
                            cout<<"n=";cin>>n;
                            for(int i=0;i<n;i++)
                                cin>>a[i];
                            cout<<"Elementul maxim este: "<<maxim(a,0,n-1)<<endl;
                            break;
                        case 5:
                            cout<<"     Minimul unui sir de numere"<<endl;
                            cout<<"n=";cin>>n;
                            for(int i=0;i<n;i++)
                                cin>>a[i];
                            cout<<"Elementul minim este: "<<minim(a,0,n-1)<<endl;
                            break;
                        case 6:
                            cout<<"     Turnurile din Hanoi"<<endl;
                            cout<<"n=";cin>>n;
                            hanoi(n,'a','b','c');
                            break;
                        case 7:
                            cout<<"     CMMDC a n numere"<<endl;
                            int v[100],c;
                            cout<<"n=";cin>>n;
                            for(int i=0;i<n;i++)
                                cin>>v[i];
                            c=cmmdc(v,0,n-1);
                            cout<<"CMMDC al elementelor lui v este: "<<c<<endl;
                            break;
                        case 0:
                            cout<<"Iesire din meniul 4"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 4"<<endl;
                            break;
                    }
                }while(opt4!=0);
                break;
            case 5:
                do
                {
                    cout<<"   5.METODA GREEDY"<<endl;
                    cout<<"     5.1 Problema Comisului Voiajor"<<endl;
                    cout<<"     5.2 Plata unei sume cu numar nelimitat de bancnote"<<endl;
                    cout<<"     5.3 Plata unei sume cu numar limitat de bancnote"<<endl;
                    cout<<"     5.4 Acoperirea unei table de sah cu mutari de caluti"<<endl;
                    cout<<"     5.0 Iesire meniu 5"<<endl;
                    cout<<"Optiunea meniu 5: ";cin>>opt5;
                    switch(opt5)
                    {
                        case 1:
                            {
                                cout<<"     Problema Comisului Voiajor"<<endl;
                                comisVoiajorG();
                            }
                            break;
                        case 2:
                            {
                                cout<<"     Plata unei sume cu numar nelimitat de bancnote"<<endl;
                                plataBancnoteNelimitat();
                            }
                            break;
                        case 3:
                            {
                                cout<<"     Plata unei sume cu numar limitat de bancnote"<<endl;
                                plataBancnoteLimitat();
                            }
                            break;
                        case 4:
                            {
                                cout<<"     Acoperirea unei table de sah cu mutari de caluti"<<endl;
                            }
                            break;
                        case 0:
                            cout<<"Iesire din meniul 5"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 5"<<endl;
                            break;
                    }
                }while(opt5!=0);
                break;
            case 6:
                do
                {
                    cout<<"   6.PROGRAMARE DINAMICA"<<endl;
                    cout<<"     6.1 Produs optim de matrice"<<endl;
                    cout<<"     6.2 Suma maxima intru-un triunghi de numere"<<endl;
                    cout<<"     6.3 Compunere intr-un alfabet"<<endl;
                    cout<<"     6.0 Iesire meniu 6"<<endl;
                    cout<<"Optiunea meniu 6: ";cin>>opt6;
                    switch(opt6)
                    {
                        case 1:
                            {
                                cout<<"     Produs optim de matrice"<<endl;
                                int n,p[20];
                                cout<<"Numar de matrice: ";cin>>n;
                                cout<<"Dimensiunile matricelor: ";
                                for(int i=1;i<=n+1;i++)
                                    cin>>p[i];
                                int pm=produsMatrice(n,p);
                                cout<<"Numarul minim de inmultiri este: "<<pm<<endl;
                                break;
                            }
                            break;
                        case 2:
                            {
                                cout<<"     Suma maxima intru-un triunghi de numere"<<endl;
                                sumaMaximaInTriunghi();
                            }
                            break;
                        case 3:
                            {
                                cout<<"    Compunere intr-un alfabet"<<endl;
                                int n,m,M[10][10]={0},y,x[100];
                                cout<<"Numarul de caractere din alfabet m=";cin>>m;
                                cout<<"Legea de compozitie="<<endl;
                                for(int i=1;i<=m;i++)
                                    for(int j=1;j<=m;j++)
                                        cin>>M[i][j];
                                cout<<"Numarul de caractere din sirul x, n=";cin>>n;
                                for(int i=1;i<=n;i++)
                                    cin>>x[i];
                                cout<<"Rezultatul compunerii sa fie y=";cin>>y;
                                if(compunere_alfabet(m,n,M,x,y))
                                    cout<<y<<" este o compunere de elemente ale lui x"<<endl;
                                break;
                            }
                        case 4:
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7:
                            break;
                        case 0:
                            cout<<"Iesire din meniul 6"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 6"<<endl;
                            break;
                    }
                }while(opt6!=0);
                break;
            case 0:
                cout<<"Incheiere program"<<endl;
                break;
            case 7:
                do
                {
                    cout<<"   7.METODA RAMIFICA SI MARGINESTE"<<endl;
                    cout<<"     7.1 Jocul Perspico"<<endl;
                    cout<<"Optiunea meniu 7: "; cin>>opt7;
                    switch(opt7)
                    {
                        case 1:
                            cout << "Jocul perspico: " << endl;
                            jocul_perspico();
                            break;
                        case 0:
                            cout<<"Iesire din meniul 7"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 7"<<endl;
                            break;
                    }
                }while(opt7!=0);
                break;

                case 8:
                do
                {
                    cout<<"   8.METODE PROBABILISTE"<<endl;
                    cout<<"     8.1 Acul lui Buffon"<<endl;
                    cout<<"     8.2 Aruncarea sagetii in cerc"<<endl;
                    cout<<"     8.3 Aproximarea integralei unei functii"<<endl;
                    cout<<"     8.4 Determinarea unui element"<<endl;
                    cout<<"     8.5 Stergerea elementelor unui graf cu numar minim de mutari"<<endl;
                    cout<<"     8.6 Gasirea unui text care se repeta intr-un sir de texte"<<endl;
                    cout<<"     8.7 Algoritmul probabilist pentru problema reginelor"<<endl;
                    cout<<"Optiunea meniu 8: ";cin>>opt8;
                    switch(opt8)
                    {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7:
                            break;
                        case 0:
                            cout<<"Iesire din meniul 8"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 8"<<endl;
                            break;
                    }
                }while(opt8!=0);
                break;

                case 9:
                do
                {
                    cout<<"   9.ALGORITMI GENETICI"<<endl;
                    cout<<"     9.1 Determinarea maximului unei functii reale printr-un algoritm genetic"<<endl;
                    cout<<"Optiunea meniu 9: ";cin>>opt9;
                    switch(opt9)
                    {
                        case 1:
                            break;
                        ;
                        case 0:
                            cout<<"Iesire din meniul 9"<<endl;
                            break;
                        default :
                            cout<<"Optiune invalida pentru meniul 9"<<endl;
                            break;
                    }
                }while(opt9!=0);
                break;

            default:
                cout<<"Optiune gresita"<<endl;
                break;
        }
    }while(op);
    return 0;
}
