#include "kua.h"

address alokasi(infotype x){
    address P;
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

address_r alokasi_r(address x, address y){
    address_r P;
    P = new elmlist_r;
    next(P) = NULL;
    prev(P) = NULL;
    up(P) = x;
    down(P) = y;
    return P;
}

void dealokasi(address P){
    delete P;
}

void dealokasi_r(address_r P){
    delete P;
}

address findElm(List L, infotype x){
    address p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (info(p).nik == x.nik){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return p;
    }
    else{
        return NULL;
    }
}

address_r findElm_rs(List_r L, address X){
    address_r p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (down(p) == X){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return p;
    }
    else{
        return NULL;
    }
}

address findElm_ri(List_r L, address Y){
    address_r p;
    bool cek;
    cek = false;
    if (first(L) != NULL){
        p = first(L);
        while ((cek==false) && (p != NULL)){
            if (up(p) == Y){
                cek = true;
            }
            else {
                p = next(p);
            }
        }
    }
    if (cek==true) {
        return down(p);
    }
    else{
        return NULL;
    }
}

void printInfo(List L, address P){
    cout <<"\nMasukkan NIK           : " <<info(P).nik <<endl;
    cout <<"Masukkan Nama          : " <<info(P).nama <<endl;
    cout <<"Masukkan Pekerjaan     : " <<info(P).pekerjaan <<endl;
    cout <<"Masukkan Alamat        : " <<info(P).alamat <<endl;
    cout <<"Masukkan Tempat Lahir  : " <<info(P).lahir.tempat <<endl;
    cout <<"Masukkan Tanggal Lahir : " <<info(P).lahir.tgl <<" - " <<info(P).lahir.bln <<" - " <<info(P).lahir.thn <<endl;
    cout <<"Status Perkawinan      : ";
    if (info(P).status == 1){
        cout <<"Lajang" <<endl;
    }
    else if (info(P).status == 2){
        cout <<"Kawin" <<endl;
    }
    else if (info(P).status == 3){
        cout <<"Cerai" <<endl;
    }
    cout <<endl;
}

infotype insertInfo(){
    infotype x;
    cout <<"\nMasukkan NIK           : ";
    cin >>x.nik;
    cout <<"Masukkan Nama          : ";
    cin >>x.nama;fflush(stdin);
    cout <<"Masukkan Pekerjaan     : ";
    cin >>x.pekerjaan;fflush(stdin);
    cout <<"Masukkan Alamat        : ";
    cin >>x.alamat;fflush(stdin);
    cout <<"Masukkan Tempat Lahir  : ";
    cin >>x.lahir.tempat;fflush(stdin);
    cout <<"Masukkan Tanggal Lahir : ";
    cin >>x.lahir.tgl;
    cout <<"Masukkan Bulan Lahir   : ";
    cin >>x.lahir.bln;
    cout <<"Masukkan Tahun Lahir   : ";
    cin >>x.lahir.thn;
    x.status = 1;
    return x;
};

void createList(List &L){
    if (first(L) != NULL){
        first(L) = NULL;
        last(L)= NULL;
    }
}

void createList_r(List_r &L){
    first(L) = NULL;
    last(L) = NULL;
}


void delFirst(List &L, address &P){
    if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            P = first(L);
            first(L) = next(first(L));
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
    }
}

void delLast(List &L, address &P){
     if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else{
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
    }
}

void delAfter(List &L, address &P, address Prec){
     if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (next(Prec)==last(L)){
            delLast(L,P);
        }
        else if (Prec==last(L)){

        }
        else{
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void delFirst_r(List_r &L, address_r &P){
    if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
            up(P) = NULL;
            down(P) = NULL;
        }
        else{
            P = first(L);
            first(L) = next(first(L));
            prev(first(L)) = NULL;
            next(P) = NULL;
            up(P) = NULL;
            down(P) = NULL;
        }
    }
}

void delLast_r(List_r &L, address_r &P){
     if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
            up(P) = NULL;
            down(P) = NULL;
        }
        else{
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
            up(P) = NULL;
            down(P) = NULL;
        }
    }
}

void delAfter_r(List_r &L, address_r &P, address_r Prec){
     if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (next(Prec)==last(L)){
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        else if (Prec==last(L)){

        }
        else{
            P = next(Prec);
            next(Prec) = next(P);
            prev(next(P)) = Prec;
            next(P) = NULL;
            prev(P) = NULL;
        }
        up(P) = NULL;
        down(P) = NULL;
    }
}

void delData(List &L, address &P){
     if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (last(L)==P){
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        else if (first(L)==P){
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
        else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

void delData_r(List_r &L, address_r &P){
     if(first(L)!=NULL){
        if (first(L)==last(L)){
            P = first(L);
            first(L) = NULL;
            last(L) = NULL;
        }
        else if (last(L)==P){
            P = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(P) = NULL;
        }
        else if (first(L)==P){
            P = first(L);
            first(L) = next(P);
            prev(first(L)) = NULL;
            next(P) = NULL;
        }
        else{
            next(prev(P)) = next(P);
            prev(next(P)) = prev(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
        up(P) = NULL;
        down(P) = NULL;
    }
}


void insertFirst(List &L, address P){
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else {
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertLast(List &L, address P){
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}

void insertAfter(List &L, address P, address Prec){
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else if (Prec==last(L)) {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
    else {
        next(P) = next(Prec);
        prev(next(P)) = P;
        next(Prec) = P;
        prev(P) = Prec;
    }
}

void insertFirst_r(List_r &L, address_r P){
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
        prev(P)=NULL;
    }
    else {
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertLast_r(List_r &L, address_r P){
    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
}
void insertAfter_r(List_r &L, address_r P, address_r Prec){

    if (first(L)==NULL){
        first(L)=P;
        last(L)=P;
    }
    else if (Prec==last(L)) {
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }
    else {
        next(Prec)=next(P);
        prev(next(P))=Prec;
        next(P)=Prec;
        prev(Prec)=P;
    }
}


void editList(List &L, address P){
    infotype x;
    char pil;

    cout <<"\nData yang ingin diubah : "<<endl;
    cout <<"(1). NIK            " <<endl;
    cout <<"(2). Nama           " <<endl;
    cout <<"(3). Pekerjaan      " <<endl;
    cout <<"(4). Alamat         " <<endl;
    cout <<"(5). Tempat Lahir   " <<endl;
    cout <<"(6). Tanggal Lahir  " <<endl;
    cin>>pil;
    switch (pil) {
    case '1' :
            cout <<"Masukkan NIK baru : ";
            cin >>info(P).nik;

        break;
    case '2' :
            cout <<"Masukkan Nama baru : ";
            cin >>info(P).nama;

        break;
    case '3' :
        cout <<"Masukkan Pekerjaan baru : ";
            cin >>info(P).pekerjaan;

        break;
    case '4' :
        cout <<"Masukkan Alamat baru : ";
            cin >>info(P).alamat;

        break;
    case '5' :
        cout <<"Masukkan Tempat Lahir baru : ";
            cin >>info(P).lahir.tempat;

        break;
    case '6' :
        cout <<"Masukkan Tanggal Lahir baru : ";
            cout <<"Masukkan Tanggal Lahir : ";
            cin >>x.lahir.tgl;
            cout <<"Masukkan Bulan Lahir   : ";
            cin >>x.lahir.bln;
            cout <<"Masukkan Tahun Lahir   : ";
            cin >>x.lahir.thn;

        break;
        };

}

void tukar(List &L, address P, address Q){
    if ((P == first(L))&&(Q == last(L))){
        next(Q) = P;
        prev(Q) = NULL;
        prev(P) = Q;
        next(P) = NULL;
        first(L) = Q;
        last(L) = P;
    }
    else if ((P == first(L))&&(Q != last(L))){
        next(P) = next(Q);
        prev(next(Q)) = P;
        prev(P) = Q;
        next(Q) = P;
        prev(Q) = NULL;
        first(L) = Q;
    }
    else if ((P != first(L))&&(Q == last(L))){
        next(prev(P)) = Q;
        next(Q) = P;
        prev(P) = Q;
        next(P) = NULL;
        last(L) = P;
    }
    else{
        next(prev(P)) = Q;
        prev(Q) = prev(P);
        prev(next(Q)) = P;
        next(P) = next(Q);
        next(Q) = P;
        prev(P) = Q;
    }
}

void sortAs_nik(List L){
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address P,Q;
        int pass,panjang;
        P = first(L);
        panjang = 1;
        while (P!=NULL){
            panjang++;
            P = next(P);
        }

        for (pass=1; pass<panjang; pass++){
            P = first(L);
            while (next(P)!=NULL){
                Q = next(P);
                if (info(Q).nik < info(P).nik){
                    tukar(L,P,Q);
                }
                else{
                    P = next(P);
                }
            }
        }

        P = first(L);
        while (P!=NULL){
            printInfo(L,P);
            getch();
            P = next(P);
        }
    }
    else {
        cout << endl << "List Kosong";
        getch();
    }
};

void sortDes_nik(List L){
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address P,Q;
        int pass,panjang;
        P = first(L);
        panjang = 1;
        while (P!=NULL){
            panjang++;
            P = next(P);
        }

        for (pass=1; pass<panjang; pass++){
            P = first(L);
            while (next(P)!=NULL){
                Q = next(P);
                if (info(Q).nik > info(P).nik){
                    tukar(L,P,Q);
                }
                else{
                    P = next(P);
                }
            }
        }

    }
    else {
        cout << endl << "List Kosong";
        getch();
    }
};

void sortAs_usia(List L){
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address P,Q;
        int pass,panjang;
        P = first(L);
        panjang = 1;
        while (P!=NULL){
            panjang++;
            P = next(P);
        }

        for (pass=1; pass<panjang; pass++){
            P = first(L);
            while (next(P)!=NULL){
                Q = next(P);
                if ( (info(Q).lahir.tgl + info(Q).lahir.tgl*100 + info(Q).lahir.tgl*1000) < (info(P).lahir.tgl + info(P).lahir.tgl*100 + info(P).lahir.tgl*1000) ){
                    tukar(L,P,Q);
                }
                else{
                    P = next(P);
                }
            }
        }

        P = first(L);
        while (P!=NULL){
            printInfo(L,P);
            getch();
            P = next(P);
        }
    }
    else {
        cout << endl << "List Kosong";
        getch();
    }
};

void sortDes_usia(List L){
    if ((first(L) != NULL)&&(first(L)!=last(L))){
        address P,Q;
        int pass,panjang;
        P = first(L);
        panjang = 1;
        while (P!=NULL){
            panjang++;
            P = next(P);
        }

        for (pass=1; pass<panjang; pass++){
            P = first(L);
            while (next(P)!=NULL){
                Q = next(P);
                if ((info(Q).lahir.tgl + info(Q).lahir.tgl*100 + info(Q).lahir.tgl*1000) > (info(P).lahir.tgl + info(P).lahir.tgl*100 + info(P).lahir.tgl*1000)){
                    tukar(L,P,Q);
                }
                else{
                    P = next(P);
                }
            }
        }

    }
    else {
        cout << endl << "List Kosong";
        getch();
    }
};
