    do{
        system("cls");
        cout <<"\t\t\t\tAPLIKASI ADMINISTRASI \n\t\t\t\t KANTOR URUSAN AGAMA" <<endl <<endl;
        cout <<"Data Calon Pengantin \n";
        cout <<"\t(1). Input Data \t\t (2). Delete Data \n" ;
        cout <<"\t(3). Edit Data  \t\t (4). Search Data \n" ;
        cout <<"\t(5). Show Data  \t\t (0). Exit        \n" ;
        cout <<"\nPilihan : ";
        cin >>pil;

        switch (pil){
        case '1' :
// INPUT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            do{
                system("cls");
                cout <<"\t\t\t\t    INPUT DATA" <<endl <<endl;
                cout <<"(1). Input Data Pria  " <<endl;
                cout <<"(2). Input Data Wanita  " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"\nPilihan : ";
                cin >>pol;
                switch (pol){
                    case '1' :
                        cout <<"(1). Input Data Pria  " <<endl;
                        x = insertInfo();
                        P = alokasi(x);
                        insertLast(pria, P);
                        getch();
                        break;
                    case '2' :
                        cout <<"(2). Input Data Wanita  " <<endl;
                        x = insertInfo();
                        P = alokasi(x);
                        insertLast(wanita, P);
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
// INPUT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case '2' :
// DELETE ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            do{
                system("cls");
                cout <<"\t\t\t\t    DELETE DATA" <<endl <<endl;
                cout <<"(1). Delete Data Pria  " <<endl;
                cout <<"(2). Delete Data Wanita  " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"\nPilihan : ";
                cin >>pol;
                switch (pol){
                    case '1' :
                        cout <<"(1). Delete Data Pria  " <<endl;



                        getch();
                        break;
                    case '2' :
                        cout <<"(2). Delete Data Wanita  " <<endl;


                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
// DELETE ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case '3' :
// EDIT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            do{
                system("cls");
                cout <<"\t\t\t\t    EDIT DATA" <<endl <<endl;
                cout <<"(1). Edit Data Pria  " <<endl;
                cout <<"(2). Edit Data Wanita  " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"\nPilihan : ";
                cin >>pol;
                switch (pol){
                    case '1' :
                        cout <<"(1). Edit Data Pria  " <<endl;
                        cout <<"Masukkan NIK : ";
                        cin >>x.nik;
                        P = findElm(pria, x);
                        if (P == NULL){
                            cout <<"Data tidak ditemukan" <<endl;
                        }
                        else{
                            x = insertInfo();
                            info(P) = x;
                        }
                        getch();
                        break;
                    case '2' :
                        cout <<"(2). Edit Data Wanita  " <<endl;
                        cout <<"Masukkan NIK : ";
                        cin >>x.nik;
                        P = findElm(wanita, x);
                        if (P == NULL){
                            cout <<"Data tidak ditemukan" <<endl;
                        }
                        else{
                            x = insertInfo();
                            info(P) = x;
                        }
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
// EDIT ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case '4' :
// SEARCH ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            do{
                system("cls");
                cout <<"\t\t\t\t    SEARCH DATA" <<endl <<endl;
                cout <<"(1). Search Data Pria  " <<endl;
                cout <<"(2). Search Data Wanita  " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"\nPilihan : ";
                cin >>pol;
                switch (pol){
                    case '1' :
                        cout <<"(1). Search Data Pria  " <<endl;
                        cout <<"Masukkan NIK : ";
                        cin >>x.nik;
                        P = findElm(pria, x);
                        if (P == NULL){
                            cout <<"Data tidak ditemukan" <<endl;
                        }
                        else{
                            printInfo(pria, P);
                        }
                        getch();
                        break;
                    case '2' :
                        cout <<"(2). Search Data Wanita  " <<endl;
                        cout <<"Masukkan NIK : ";
                        cin >>x.nik;
                        P = findElm(wanita, x);
                        if (P == NULL){
                            cout <<"Data tidak ditemukan" <<endl;
                        }
                        else{
                            printInfo(wanita, P);
                        }
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
// SEARCH ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case '5' :
// SHOW ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            do{
                system("cls");
                cout <<"\t\t\t\t    SHOW DATA" <<endl <<endl;
                cout <<"(1). Show Data Pria  " <<endl;
                cout <<"(2). Show Data Wanita  " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"\nPilihan : ";
                cin >>pol;
                switch (pol){
                    case '1' :
                        cout <<"(1). Show Data Pria  " <<endl;
                        if(first(pria) == NULL){
                            cout <<"Data Kosong" <<endl;
                        }
                        else{
                            P = first(pria);
                            j = 1;
                            while(P != NULL){
                                cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                printInfo(pria, P);
                                P = next(P);
                                j++;
                            }
                        }
                        getch();
                        break;
                    case '2' :
                        cout <<"(2). Show Data Wanita  " <<endl;
                        if(first(wanita) == NULL){
                            cout <<"Data Kosong" <<endl;
                        }
                        else{
                            P = first(wanita);
                            j = 1;
                            while(P != NULL){
                                cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                printInfo(wanita, P);
                                P = next(P);
                                j++;
                            }
                        }
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
// SHOW ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        case '0'  : break;
        default : break;
        }
    }while (pil != 0);
