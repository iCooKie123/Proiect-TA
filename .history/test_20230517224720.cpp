
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