#include "kua.h"
int main()
{
    int  j;
    char pil, pol;
    List pria, wanita;
    infotype x, s, i;
    address P, X, Y;
    createList(pria);
    createList(wanita);

    List_r kawin;
    createList_r(kawin);
    address_r Q, R;

    do{
        system("cls");
        cout <<"\t\t\t\tAPLIKASI ADMINISTRASI \n\t\t\t\t KANTOR URUSAN AGAMA" <<endl <<endl;

        cout <<"(1). Input Data  \t\t" ;
        cout <<"(2). Edit Data   \t\t" ;
        cout <<"(3). Delete Data " <<endl;
        cout <<"(4). Search Data \t\t" ;
        cout <<"(5). Sort Data   \t\t" ;
        cout <<"(6). Show Data   " <<endl;
        cout <<"\t\t\t\t\t\t\t\t(0). Exit " <<endl;
        cout <<"Pilihan : ";
        cin >>pil;

        switch (pil){
        case '1' :
//INPUT DATA ###########################################################################################################################
            do{
                system("cls");
                cout <<"\t\t\t\t    INPUT DATA" <<endl <<endl;
                cout <<"(1). Input Data Pria  " <<endl;
                cout <<"(2). Input Data Wanita  " <<endl;
                cout <<"(3). Input Data Hubungan " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"Pilihan : ";
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
                    case '3' :
                        cout <<"(3). Input Data Hubungan  " <<endl;
                        char pel;
                        do{
                            cout <<"(1). Perkawinan  (2). Perceraian : " <<endl;
                            cout <<"Pilihan : ";
                            cin >>pel;
                        } while( (pel != '1') && (pel != '2') );
                        switch (pel){
                        case '1' :
                            cout <<"\nMasukkan NIK Pria   : ";
                            cin >> s.nik;
                            X = findElm(pria, s);
                            if (X == NULL){
                                cout <<"\nData tidak ditemukan" <<endl;
                                getch();
                                break;
                            }

                            cout <<"\nMasukkan NIK Wanita : ";
                            cin >> i.nik;
                            Y = findElm(wanita, i);
                            if (Y == NULL){
                                cout <<"\nData tidak ditemukan" <<endl;
                            }

                            if ((Y != NULL) && (X != NULL)){
                                info(X).status = 2;
                                info(Y).status = 2;
                                Q = alokasi_r(X, Y);
                                insertFirst_r(kawin, Q);
                                cout <<"\nSelamat Menempuh Hidup Baru";
                            }
                            break;
                        case '2' :
                            cout <<"\nMasukkan NIK Wanita : ";
                            cin >> i.nik;
                            Y = findElm(wanita, i);
                            if (Y == NULL){
                                cout <<"\nData tidak ditemukan" <<endl;
                            }
                            else{
                                 if (info(Y).status != 2){
                                    cout <<"\nData yang dimasukkan tidak memiliki pasangan" <<endl;
                                 }
                                 else{
                                    Q = findElm_rs(kawin, Y);
                                    info(up(Q)).status = 3;
                                    info(down(Q)).status = 3;
                                    delData_r(kawin, Q);
                                 }
                            }
                            break;
                        }
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
//INPUT DATA ###########################################################################################################################

        case '2' :
//EDIT DATA ############################################################################################################################
            do{
                system("cls");
                cout <<"\t\t\t\t    EDIT DATA" <<endl <<endl;
                cout <<"(1). Edit Data Pria  " <<endl;
                cout <<"(2). Edit Data Wanita  " <<endl;
                cout <<"(3). Edit Data Hubungan " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"Pilihan : ";
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
                    case '3' :
                        cout <<"(3). Edit Data Hubungan  " <<endl;
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
//EDIT DATA ############################################################################################################################

        case '3' :
//DELETE DATA ##########################################################################################################################
            do{
                system("cls");
                cout <<"\t\t\t\t   DELETE DATA" <<endl <<endl;
                cout <<"(1). Delete Data Pria  " <<endl;
                cout <<"(2). Delete Data Wanita  " <<endl;
                cout <<"(3). Delete Data Hubungan " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"Pilihan : ";
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
                    case '3' :
                        cout <<"(3). Delete Data Hubungan  " <<endl;
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
//DELETE DATA ##########################################################################################################################

        case '4' :
//SEARCH DATA ##########################################################################################################################
            do{
                system("cls");
                cout <<"\t\t\t\t    SEARCH DATA" <<endl <<endl;
                cout <<"(1). Search Data Pria  " <<endl;
                cout <<"(2). Search Data Wanita  " <<endl;
                cout <<"(3). Search Data Hubungan " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"Pilihan : ";
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
                    case '3' :
                        cout <<"(3). Search Data Hubungan  " <<endl;
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');

            getch();
            break;
//SEARCH DATA ##########################################################################################################################

        case '5' :
//SORT DATA ############################################################################################################################


            getch();
            break;
//SORT DATA ############################################################################################################################

        case '6' :
//SHOW DATA ############################################################################################################################
            do{
                system("cls");
                cout <<"\t\t\t\t    SHOW DATA" <<endl <<endl;
                cout <<"(1). Show Data Pria  " <<endl;
                cout <<"(2). Show Data Wanita  " <<endl;
                cout <<"(3). Show Data Hubungan " <<endl;
                cout <<"(0). Exit" <<endl;
                cout <<"Pilihan : ";
                cin >>pol;
                switch (pol){
                    case '1' :
                        cout <<" Show Data Pria  " <<endl;
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
                    case '3' :
                        cout <<"(3). Show Data Hubungan  " <<endl;
                        if(first(kawin) == NULL){
                            cout <<"Data Kosong" <<endl;
                        }
                        else{
                            char pel;
                            do{
                                cout <<"(1). Perkawinan  (2). Perceraian" <<endl;
                                cout <<"Pilihan : ";
                                cin >>pel;
                            } while( (pel != '1') && (pel != '2') );

                            switch (pel){
                            case '1' :
                                R = first(kawin);
                                j = 1;
                                while(R != NULL){
                                    cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                    cout <<"\tSuami : " <<info(up(R)).nama <<" (" <<info(up(R)).nik <<") " <<endl;
                                    cout <<"\tIstri : " <<info(down(R)).nama <<" (" <<info(down(R)).nik <<") " <<endl;
                                    R = next(R);
                                    j++;
                                }
                                break;
                            case '2' :
                                X = first(pria);
                                Y = first(wanita);
                                j = 1;
                                if( (first(pria) == NULL) && (first(wanita) == NULL) ){
                                    cout <<"Data Kosong" <<endl;
                                }
                                else{
                                    while(X != NULL){
                                        if (info(X).status == 3){
                                            cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                            cout <<"\tNama : " <<info(X).nama <<endl;
                                            cout <<"\tNIK  : " <<info(X).nik <<endl;
                                            X = next(X);
                                            j++;
                                        }
                                    }

                                    while(Y != NULL){
                                        if (info(Y).status == 3){
                                            cout <<"(" <<j <<").___________________________________________________________" <<endl;
                                            cout <<"\tNama : " <<info(Y).nama <<endl;
                                            cout <<"\tNIK  : " <<info(Y).nik <<endl;
                                            Y = next(Y);
                                            j++;
                                        }
                                    }
                                    getch();
                                    break;
                                }

                                break;
                            }
                        }
                        getch();
                        break;
                    case '0'  : break;
                    default : break;
                }
            }while (pol != '0');
            break;
//SHOW DATA ############################################################################################################################

        case '0'  : break;
        default : break;
        }

    }while (pil != 0);

    return 0;
}
