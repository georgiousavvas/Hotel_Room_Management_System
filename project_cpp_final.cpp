#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <string.h>
#include <limits>
#include <ctime>

using namespace std;



class Domatio;



class Kratisi {

    public:
        static unsigned int id_kratisis ;
        int copy_id_kratisis , afixi ,atoma , meres_diamonis , id_domatiou;
        string name_pelati;
        Domatio* ptr_domatio = NULL;

        Kratisi(string a , int b , int c , int d){
            name_pelati = a;
            afixi = b;
            atoma = d;
            meres_diamonis = c;
            id_kratisis ++;
            copy_id_kratisis = id_kratisis;
        }

        void anathesi_domatiou(Domatio* a);

        void print_id(){
        cout<<copy_id_kratisis<<endl;
        }

        void print_id_domatiou();
};



class Domatio{


    protected:
        static unsigned int id_domatiou;

    public:
        int  xwritikotita;
        unsigned int copy_id_domatiou;
        double timi_atomo;
        Kratisi** diathesimotita;


        void print_id(){
            cout << copy_id_domatiou <<endl;
        }

        Domatio(int a , double b){

            id_domatiou++;
            copy_id_domatiou = id_domatiou;
            diathesimotita = new Kratisi*[30];
            xwritikotita = a;
            timi_atomo = b;

        }

         bool prosthiki_kratisis(Kratisi &a){
            int i=0 ;
            int all_good=0;
            int last_day = a.afixi + a.meres_diamonis ;
            for(i = a.afixi ; i<last_day; i++){
                if(diathesimotita[i] != NULL){
                    return false;
                }else if(a.atoma <= xwritikotita && diathesimotita[i] == NULL){
                    all_good++;

                }
            }

            if(all_good == a.meres_diamonis){
                for(i = a.afixi ; i<last_day; i++){
                    diathesimotita[i] = &a;
                }
                return true;
            }else {
                return false;
            }
        }


         double timologisi(){

            int i=0;
            double sunoliko = 0.0;
            int counter = 0;
            for(i=0; i<30; i++){
                if(diathesimotita[i] != NULL){
                    counter += diathesimotita[i]->atoma;
                }

             }
             sunoliko = counter * timi_atomo;
        return sunoliko;
        }



        bool akirwsi(int a){

            int i=0;
            int j=0;
            int index;
            int counter=0;
            for(i=0; i<30; i++){
                if (diathesimotita[i]->id_kratisis == a){
                    if(diathesimotita[i] != NULL){
                        for(j=0; j < diathesimotita[i]->meres_diamonis ; j++){
                        index = i + j + 1;
                        diathesimotita[index] = NULL;
                        counter++;
                        }
              diathesimotita[i] = NULL;
cout<<"ΕΓΙΝΕ Η ΑΚΥΡΩΣΗ ΓΙΑ "<<counter<<"  ΜΕΡΕΣ"<<endl;
            return true;
                }

            }

            }
           return false;
        }




         int plirotita(){
            int i=0;
            int pososto = 0;
            int counter = 0;
            for(i=0; i<31; i++){
                if(diathesimotita[i] != NULL){
                counter++;
                }

            }
            pososto =  ( (double)counter / (double)i ) *100;
            return pososto;
        }


};



class Hotel{

public:
        string hotel_name;

        Hotel(string a){
            hotel_name = a;
        }


	void print_name(){
        cout << hotel_name << endl;
	}

	vector<Domatio*>vector_ptr_Domatio;
	vector<Kratisi*>vector_ptr_Kratisi;
	vector<Domatio*>::iterator it_vector_domatio;
	vector<Kratisi*>::iterator it_vector_kratisi;


    void prosthiki_domatiou_lista(Domatio &a){
        vector_ptr_Domatio.push_back(&a);
    }
    void prosthiki_kratisis_lista(Kratisi &a){
        vector_ptr_Kratisi.push_back(&a);
    }


    Domatio* anaktisi_domatiou_id(unsigned int id){
        int i = 0;
        for(it_vector_domatio = vector_ptr_Domatio.begin() ; it_vector_domatio != vector_ptr_Domatio.end() ; it_vector_domatio++ ){
            if(vector_ptr_Domatio.at(i)->copy_id_domatiou == id){
                i = distance(vector_ptr_Domatio.begin() , it_vector_domatio);
                return vector_ptr_Domatio.at(i);
                break;

            }

        }
    }



    Kratisi* anaktisi_kratisis_id( int id){
        int i = 0;
        for(it_vector_kratisi = vector_ptr_Kratisi.begin() ; it_vector_kratisi != vector_ptr_Kratisi.end() ; ++it_vector_kratisi){
            if(vector_ptr_Kratisi.at(i)->copy_id_kratisis == id){
                i = distance(vector_ptr_Kratisi.begin() , it_vector_kratisi);
                return vector_ptr_Kratisi.at(i);
                break;

            }

        }
    }




    int prosthiki_kratisis(Kratisi &a){
        int i=0;
        bool answer;
        for(it_vector_domatio = vector_ptr_Domatio.begin() ; it_vector_domatio != vector_ptr_Domatio.end() ; ++it_vector_domatio ){
            i = distance(vector_ptr_Domatio.begin() , it_vector_domatio);
            answer = vector_ptr_Domatio.at(i)->prosthiki_kratisis(a);
                if(answer == true){
                    cout<<"ΕΓΙΝΕ Η ΚΡΑΤΗΣΗ : "<<a.copy_id_kratisis<<"   ΣΤΟ ΔΩΜΑΤΙΟ : "<<vector_ptr_Domatio.at(i)->copy_id_domatiou<<endl;
                    prosthiki_kratisis_lista(a);
                    a.anathesi_domatiou(vector_ptr_Domatio.at(i));

                    return vector_ptr_Domatio.at(i)->copy_id_domatiou;
                    break;
                }
         }
        cout<<"ΔΕΝ ΒΡΕΘΗΚΕ ΕΛΕΥΘΕΡΟ ΔΩΜΑΤΙΟ ΓΙΑ ΑΥΤΗ ΤΗΝ ΚΡΑΤΗΣΗ"<<endl;
        return 0;

    }

bool prosthiki_kratisis_se_domatio(Kratisi &a , int b){
        Domatio* c;
        int i = 0;
        bool answer;
        c = anaktisi_domatiou_id(b);
        //answer = c->prosthiki_kratisis(a);
        for(it_vector_domatio = vector_ptr_Domatio.begin(); it_vector_domatio != vector_ptr_Domatio.end(); ++it_vector_domatio){
            i = distance(vector_ptr_Domatio.begin() , it_vector_domatio);
            if(vector_ptr_Domatio.at(i)->copy_id_domatiou == b){
                answer = vector_ptr_Domatio.at(i)->prosthiki_kratisis(a);
                if(answer == true){
                prosthiki_kratisis_lista(a);
                a.anathesi_domatiou(c);
                cout<<"ΕΓΙΝΕ Η ΚΡΑΤΗΣΗ"<<endl;
                return true;
                }else{
                    cout<<"ΔΕΝ ΜΠΟΡΕΣΕ ΝΑ ΓΙΝΕΙ Η ΚΡΑΤΗΣΗ ΣΤΟ ΔΩΜΑΤΙΟ  "<<b<<endl;
                    return false;
                }
            }
        }
    }


    bool akirwsi_kratisis(int a){

        //Kratisi* b;
        int i = 0;
        //b = anaktisi_kratisis_id(a);
        bool answer;
        for(it_vector_domatio = vector_ptr_Domatio.begin() ; it_vector_domatio != vector_ptr_Domatio.end() ; ++it_vector_domatio){
            i = distance(vector_ptr_Domatio.begin() , it_vector_domatio);
            answer = vector_ptr_Domatio.at(i)->akirwsi(a);
            if(answer == true){
                if(vector_ptr_Kratisi.size() > 1){
                    swap(vector_ptr_Kratisi.at(i) , vector_ptr_Kratisi.back());
                    vector_ptr_Kratisi.pop_back();
                    cout <<"ΕΓΙΝΕ Η ΑΚΥΡΩΣΗ ΤΗΣ ΚΡΑΤΗΣΗΣ ΚΑΙ ΑΠΟ ΤΗΝ ΛΙΣΤΑ"<<endl;
                    return true;

                }else{

                    vector_ptr_Kratisi.clear();
                    cout <<"ΕΓΙΝΕ Η ΑΚΥΡΩΣΗ ΤΗΣ ΚΡΑΤΗΣΗΣ ΚΑΙ ΑΠΟ ΤΗΝ ΛΙΣΤΑ"<<endl;
                    cout<<"Η ΛΙΣΤΑ ΚΡΑΤΗΣΕΩΝ ΕΙΝΑΙ ΚΕΝΗ"<<endl;
                    return true;
                }
            }

        }
        return false;

    }


    double upologismos_esodwn(int a){
        Domatio* domatio;
        double b = 0.0;
        domatio = anaktisi_domatiou_id(a);
        b = domatio->timologisi();
        return b;
    }


    double upologismos_esodwn(){

        int i = 0;
        double sunolika_esoda = 0.0;
        double temp_esoda = 0.0;
        for(it_vector_domatio = vector_ptr_Domatio.begin() ; it_vector_domatio != vector_ptr_Domatio.end() ; ++it_vector_domatio ){
            i = distance(vector_ptr_Domatio.begin() , it_vector_domatio);
            temp_esoda = vector_ptr_Domatio.at(i)->timologisi();
            sunolika_esoda += temp_esoda;

        }
        return sunolika_esoda;

    }



    void provoli_kratisewn(){
        int i = 0;
        cout << " | ΚΩΔΙΚΟΣ ΚΡΑΤΗΣΗΣ |  ΟΝΟΜΑ ΠΕΛΑΤΗ |  ΚΩΔΙΚΟΣ ΔΩΜΑΤΙΟΥ |"<<endl<<endl;
	cout << "-------------------------------------------------------------"<<endl<<endl;
        for(it_vector_kratisi = vector_ptr_Kratisi.begin() ; it_vector_kratisi != vector_ptr_Kratisi.end() ; ++it_vector_kratisi){
            i = distance(vector_ptr_Kratisi.begin() , it_vector_kratisi);
            cout<<" |  "<<vector_ptr_Kratisi.at(i)->copy_id_kratisis<<"               |  "<<vector_ptr_Kratisi.at(i)->name_pelati<< "    |    "<<vector_ptr_Kratisi.at(i)->id_domatiou <<endl;
	cout << "-------------------------------------------------------------"<<endl;
        }
    }

    void provoli_domation(){
        int i = 0;
        int plirotita;
        double timologisi;
        cout<<" | ΚΩΔΙΚΟΣ ΔΩΜΑΤΙΟΥ | ΠΛΗΡΟΤΗΤΑ | ΕΣΟΔΑ |"<<endl<<endl;
	cout << "-------------------------------------------------------------"<<endl<<endl;
        for(it_vector_domatio = vector_ptr_Domatio.begin() ; it_vector_domatio != vector_ptr_Domatio.end() ; ++it_vector_domatio){
            i = distance(vector_ptr_Domatio.begin() , it_vector_domatio);
            plirotita = vector_ptr_Domatio.at(i)->plirotita();
            timologisi = vector_ptr_Domatio.at(i)->timologisi();
            cout<<" | "<<vector_ptr_Domatio.at(i)->copy_id_domatiou<<"           | "<<plirotita<<"%         |  "<<timologisi<<endl;
		cout << "-------------------------------------------------------------"<<endl;

        }


    }

    void plano_kratisewn(){

        int i = 0;
        int j = 0;
        int k = 0;
        cout <<endl<<endl<<"ΔΩΜΑΤΙΟ    ";
        for(k = 1; k < 31 ; k++){
            cout <<"  "<<k;
        }


        cout<<endl<<endl<<endl;

        for(it_vector_domatio = vector_ptr_Domatio.begin() ; it_vector_domatio != vector_ptr_Domatio.end() ; ++it_vector_domatio){
            i = distance(vector_ptr_Domatio.begin() , it_vector_domatio);
            cout<<vector_ptr_Domatio.at(i)->copy_id_domatiou<<"       ";
            for(j = 0; j < 31 ; j++ ){
                if(vector_ptr_Domatio.at(i)->diathesimotita[j] != NULL){
                    cout <<" *  ";
                }else{
                    cout <<" _  ";
                }
            }
            cout<<endl<<endl;

        }
    }


};




class Domatio_typeA : public Domatio{

    public:
            double timi_ana_mera ;

            Domatio_typeA(int a , double b , double c):Domatio(a , b){

                timi_ana_mera = c;

            }

            double timologisi(){
            int i;
            int day_counter = 0;
            double sunoliko = 0.0;
                for(i=0; i<30; i++){
                    if(diathesimotita[i] != NULL){
                        day_counter++;
                    }
                }
            sunoliko = day_counter * timi_ana_mera;
            return sunoliko;
            }


};



class Domatio_typeB : public Domatio_typeA{
    public:
            int daily_ektpwsi;


        Domatio_typeB(int a , double b , double c , int d):Domatio_typeA(a,b,c){

            daily_ektpwsi = d;
        }

        double timologisi(){
            int i;
            int counter = 0;
            double sunoliko = 0.0;
            double sunoliko_xwris = 0.0;
            double ekptwsi = 0.0;

            for(i=0; i<30; i++){
                if(diathesimotita[i] != NULL){
                counter++;
                }
            }
        sunoliko_xwris = counter * timi_ana_mera;
            if( (counter * daily_ektpwsi) > 50){
                sunoliko = sunoliko_xwris / 2;
            }else{
                ekptwsi = (sunoliko_xwris / 100 ) * (daily_ektpwsi * counter);
                sunoliko = sunoliko_xwris - ekptwsi;
            }
          return sunoliko;
        }

        bool akirwsi(int a){
            return false;
        }

};



class Domatio_typeC : public Domatio{

    public:
            int min_atoma , min_meres;

            Domatio_typeC(int a , double b , int c , int d):Domatio(a,b){
                min_atoma = c;
                min_meres = d;

            }


  bool prosthiki_kratisis(Kratisi a){
            int i=0 ;
            int all_good=0;
            int last_day = a.afixi + a.meres_diamonis ;
            for(i = a.afixi ; i<last_day; i++){
                if(diathesimotita[i] != NULL){
                    cout<<"ΔΕΝ ΕΓΙΝΕ Η ΚΡΑΤΗΣΗ"<<endl;
                    return false;
                }else if(a.atoma <= xwritikotita && diathesimotita[i] == NULL && a.atoma >= min_atoma && a.meres_diamonis >= min_meres){
                    all_good++;

                }
            }

            if(all_good == a.meres_diamonis){
                for(i = a.afixi ; i<last_day; i++){
                    diathesimotita[i] = &a;
                }
                cout<<"ΕΓΙΝΕ Η ΚΡΑΤΗΣΗ"<<endl;
                return true;
            }else {
                cout<<"ΔΕΝ ΕΓΙΝΕ Η ΚΡΑΤΗΣΗ"<<endl;
                return false;
            }
        }


};



void Kratisi::anathesi_domatiou(Domatio* a){
    ptr_domatio = a;
    id_domatiou = ptr_domatio->copy_id_domatiou;
}



void Kratisi::print_id_domatiou(){
        ptr_domatio->print_id();
        }



class Domatio_typeD : public Domatio_typeA{

    public:
            double epivarinsi_atomo;

            Domatio_typeD(int a , double b , double c ,double d):Domatio_typeA(a ,b ,c){

                epivarinsi_atomo = d;
            }

            double timologisi(){
                int i;
                int counter_days , counter_atoma_day;
                double sunoliko = 0.0;
                double sunoliko_daily_plus_epivarinsi = 0.0;
                for(i=0; i<30; i++){
                    if(diathesimotita[i] !=NULL){
                        counter_days++;
                        counter_atoma_day = diathesimotita[i]->atoma;
                        sunoliko_daily_plus_epivarinsi += counter_atoma_day * epivarinsi_atomo;
                    }
                }
                sunoliko =  (timi_ana_mera * counter_days) + sunoliko_daily_plus_epivarinsi;
            return sunoliko;
            }


};



class Domatio_typeE : public Domatio {

    public:
            int min_pososto_plirotitas;

            Domatio_typeE(int a ,double b , int c):Domatio(a,b){

                min_pososto_plirotitas = c;

            }

            int plirotita(){
                int i=0;
                int pososto = 0;
                int counter = 0;

                for(i=0; i<30; i++){
                    if(diathesimotita[i] != NULL){
                        counter++;
                    }

                }
                pososto =  ( (double)counter / (double)i ) *100;
                return pososto;
            }


            bool akirwsi(int plirotita()){
                int a = plirotita();
                int j=0;

                if( a > min_pososto_plirotitas ){
                    return false;
                }else{
                    int i=0;
                    int j=0;
                    int index;
                    int counter=0;
                    for(i=0; i<30; i++){
                        if (diathesimotita[i]->id_kratisis == a){
                            if(diathesimotita[i] != NULL){
                                for(j=0; j < diathesimotita[i]->meres_diamonis ; j++){
                                    index = i + j + 1;
                                    diathesimotita[index] = NULL;
                                    counter++;
                                }
                                diathesimotita[i] = NULL;
                                cout<<"ΕΓΙΝΕ Η ΑΚΥΡΩΣΗ ΓΙΑ "<<counter<<"  ΜΕΡΕΣ"<<endl;
                                return true;
                            }

                        }

                    }
                    return false;
                }
            }
};



void print_menu(){

   cout<<endl<<endl;
   cout<<"|-------------------------------------------------------------------|"<<endl;
   cout<<"                         ΜΕΝΟΥ ΕΠΙΛΟΓΩΝ";
   cout<<endl;
   cout<<"|-------------------------------------------------------------------|"<<endl;
   cout<<"|1. -  ΕΠΟΜΕΝΗ ΕΠΑΝΑΛΗΨΗ         |"<<"    5. -  ΠΡΟΒΟΛΗ ΔΩΜΑΤΙΩΝ        |"<<endl;
   cout<<"|--------------------------------|----------------------------------|"<<endl;
   cout<<"|2. -  ΠΡΟΣΘΗΚΗ ΚΡΑΤΗΣΗΣ         |"<<"    6. -  ΠΡΟΒΟΛΗ ΠΛΑΝΟΥ ΚΡΑΤΗΣΕΩΝ|" <<endl;
   cout<<"|--------------------------------|----------------------------------|"<<endl;
   cout<<"|3. -  ΑΚΥΡΩΣΗ ΚΡΑΤΗΣΗΣ          |"<<"    7. -  ΠΡΟΒΟΛΗ ΕΣΟΔΩΝ          |"<<endl;
   cout<<"|--------------------------------|----------------------------------|"<<endl;
   cout<<"|4. -  ΠΡΟΒΟΛΗ ΚΡΑΤΗΣΕΩΝ         |"<<"    8. -  ΤΕΡΜΑΤΙΣΜΟΣ             |" <<endl;
   cout<<"|--------------------------------|----------------------------------|"<<endl<<endl;

   cout<<"ΕΠΙΛΟΓΗ  : ";

}

unsigned int Kratisi::id_kratisis=0;
unsigned int Domatio::id_domatiou=0;

string rand_string(){

    char *array1="abcdefghijklmnopqrstuvwxyz";
    string rand_name;
    int rand_index_array1 , i , array1_index;

    rand_index_array1 =  ( rand() % 10) + 1;
    for(i = 0; i < rand_index_array1; i++){
        array1_index =  rand() % 26;
        rand_name += array1[array1_index];

    }
    return rand_name;

}


int main(){


    int  menu_answer , afixi , meres_diamonis , meres_diamonis_kratisis , atoma ,atoma_kratisis , kwdikos_domatiou , kwdikos_kratisis , rand_index , afixi_kratisis , rand_id ,epilogi_domatiou_akirwsi;
    string name_pelati , name_pelati1 , name_kratisis ;
    char apantisi_gia_kwdiko;
    long menu_answer_int;
    double esoda_kwdiko = 0.0;
    double esoda_xwris = 0.0;
    double esoda = 0.0;

    //Dimiourgia xenodoxeiou kai domation

    Hotel hotel1("Golden Bay");
    Domatio domatio1(2, 5) , domatio2(2 ,10) ,domatio3(2 ,15) , domatio4(2,20) , domatio5(2,25);
    Domatio_typeA domatio_typeA(3 , 10 , 30);
    Domatio_typeB domatio_typeB(4 , 10 , 30, 5);
    Domatio_typeC domatio_typeC(5 , 5, 3 , 3);
    Domatio_typeD domatio_typeD(5 , 10 , 20 ,5 );
    Domatio_typeE domatio_typeE(20 , 20 , 80);


    //Prosthiki domation sto xenodoxeio

    hotel1.prosthiki_domatiou_lista(domatio1);
    hotel1.prosthiki_domatiou_lista(domatio2);
    hotel1.prosthiki_domatiou_lista(domatio3);
    hotel1.prosthiki_domatiou_lista(domatio4);
    hotel1.prosthiki_domatiou_lista(domatio5);
    hotel1.prosthiki_domatiou_lista(domatio_typeA);
    hotel1.prosthiki_domatiou_lista(domatio_typeB);
    hotel1.prosthiki_domatiou_lista(domatio_typeC);
    hotel1.prosthiki_domatiou_lista(domatio_typeD);
    hotel1.prosthiki_domatiou_lista(domatio_typeE);



    //Arxi systimatos

    //RANDOM KRATISI GENARATOR


    srand(time(NULL));
    afixi_kratisis = (rand() % 30 ) + 1;
    meres_diamonis_kratisis = ( rand() % (30 - afixi_kratisis)  ) + 1 ;
    atoma_kratisis = (rand() % 4) + 1;
    name_kratisis = rand_string();
    Kratisi kratisi1( name_kratisis , afixi_kratisis , meres_diamonis_kratisis , atoma_kratisis);
    hotel1.prosthiki_kratisis(kratisi1);


    while(1){


        //RANDOM AKURWSI GENARATOR

        if(rand() % 4 == 0){

            if(hotel1.vector_ptr_Kratisi.size() != 0){
                rand_index = hotel1.vector_ptr_Kratisi.size();
                rand_id = (rand() % rand_index) + 1;
                hotel1.akirwsi_kratisis(rand_id);
            }
        }




        print_menu();
        cin>>menu_answer;

        while(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ, ΠΡΟΣΠΑΘΗΣΤΕ ΞΑΝΑ :";
            cin >> menu_answer;
        }

        switch(menu_answer){


        case 1:

            break;

/*--------------------------------------------------------------------------------------------------------------*/


        case 2:

            cout<<"ΟΝΟΜΑ  :";
            cin>>name_pelati;
            name_pelati1 = name_pelati;
            cout<<"ΑΦΙΞΗ  :";
            cin>>afixi;
            while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ , ΠΡΟΣΠΑΘΗΣΤΕ ΞΑΝΑ \nΑΦΙΞΗ :";
                cin >> afixi;
            }
            cout<<"ΜΕΡΕΣ ΔΙΑΜΟΝΗΣ  :";
            cin>>meres_diamonis;
            while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ , ΠΡΟΣΠΑΘΗΣΤΕ ΞΑΝΑ \nΜΕΡΕΣ ΔΙΑΜΟΝΗΣ :";
                cin >> meres_diamonis;
            }
            cout<<"ΑΤΟΜΑ  :";
            cin>>atoma;
            while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ , ΠΡΟΣΠΑΘΗΣΤΕ ΞΑΝΑ \nΑΤΟΜΑ:";
                cin >> atoma;
            }
            cout<<"ΘΕΛΕΤΕ ΝΑ ΔΩΣΕΤΕ ΚΩΔΙΚΟ ΔΩΜΑΤΙΟΥ?  (Y/n) ";
            cin>>apantisi_gia_kwdiko;
            if(apantisi_gia_kwdiko == 'Y'){
                cin>>kwdikos_domatiou;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ , ΠΡΟΣΠΑΘΗΣΤΕ ΞΑΝΑ /nΚΩΔΙΚΟΣ ΔΩΜΑΤΙΟΥ :";
                    cin >> kwdikos_domatiou;
                }
                Kratisi kratisi(name_pelati , afixi , meres_diamonis , atoma) ;
                hotel1.prosthiki_kratisis_se_domatio(kratisi,kwdikos_domatiou);
            }else{

                Kratisi kratisi(name_pelati , afixi , meres_diamonis , atoma);
                hotel1.prosthiki_kratisis(kratisi);

            }
            break;

/*-----------------------------------------------------------------------------------------*/

        case 3:

            cout<<"ΚΩΔΙΚΟΣ ΚΡΑΤΗΣΗΣ ΓΙΑ ΑΚΥΡΩΣΗ :  ";
            cin>>kwdikos_kratisis;
            while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ , ΠΡΟΣΠΑΘΗΣΤΕ ΞΑΝΑ \nΚΩΔΙΚΟΣ ΚΡΑΤΗΣΗΣ ΓΙΑ ΑΚΥΡΩΣΗ :";
                cin >> kwdikos_kratisis;
            }
            cout<<kwdikos_kratisis<<endl;
            hotel1.akirwsi_kratisis(kwdikos_kratisis);
            break;

/*--------------------------------------------------------------------------------------------*/
        case 4:

            hotel1.provoli_kratisewn();
            break;

/*---------------------------------------------------------------------------------------------*/

        case 5:

            hotel1.provoli_domation();
            break;


/*---------------------------------------------------------------------------------------------*/


        case 6:

            hotel1.plano_kratisewn();
            break;


/*-----------------------------------------------------------------------------------------------*/

        case 7:

            cout<<"ΘΕΛΕΤΕ ΝΑ ΔΩΣΕΤΕ ΚΩΔΙΚΟ ΔΩΜΑΤΙΟΥ ?  (Y/n) :";
            cin>>apantisi_gia_kwdiko;
            if(apantisi_gia_kwdiko == 'Y'){
                cin>>kwdikos_domatiou;
                while(cin.fail()){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << "Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ , ΠΡΟΣΠΑΘΗΣΤΕ ΞΑΝΑ \nΚΩΔΙΚΟΣ ΔΩΜΑΤΙΟΥ:";
                    cin >> kwdikos_domatiou;
                }
                esoda_kwdiko = hotel1.upologismos_esodwn(kwdikos_domatiou);
                cout << "ΤΑ ΕΣΟΔΑ ΓΙΑ ΤΟ ΔΩΜΑΤΙΟ : "<< kwdikos_domatiou <<"  ΕΙΝΑΙ :"<<setprecision(2)<<esoda_kwdiko <<endl;
            }else{
                esoda_xwris = hotel1.upologismos_esodwn();
                cout << "ΤΑ ΣΥΝΟΛΙΚΑ ΕΣΟΔΑ ΕΙΝΑΙ : "<<esoda_xwris <<endl;

            }

            break;

/*-------------------------------------------------------------------------------------------------*/

        case 8:

            return 0;


/*-------------------------------------------------------------------------------------------------*/

        case 9:

            while (1){

            cout<<"ΕΠΙΛΕΞΤΕ ΔΩΜΑΤΙΟ ΠΟΥ ΘΕΛΕΤΕ ΝΑ ΚΑΝΕΤΕ ΤΙΜΟΛΟΓΗΣΗ :";
            cin>>epilogi_domatiou_akirwsi;

            while(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << "Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ , ΠΡΟΣΠΑΘΗΣΤΕ ΞΑΝΑ \nΚΩΔΙΚΟΣ ΔΩΜΑΤΙΟΥ:";
                cin >> epilogi_domatiou_akirwsi;
                }


            switch(epilogi_domatiou_akirwsi){

                case 1:

                    esoda = domatio1.timologisi();
                    cout << esoda <<endl;
                    break;

                case 2:

                    esoda = domatio2.timologisi();
                    cout << esoda <<endl;
                    break;

                case 3:

                    esoda = domatio3.timologisi();
                    cout << esoda <<endl;
                    break;

                case 4:

                    esoda = domatio4.timologisi();
                    cout << esoda <<endl;
                    break;

                case 5:

                    esoda = domatio5.timologisi();
                    cout << esoda <<endl;
                    break;

                case 6:

                    esoda = domatio_typeA.timologisi();
                    cout << esoda <<endl;
                    break;

                case 7:

                    esoda = domatio_typeB.timologisi();
                    cout << esoda <<endl;
                    break;

                case 8:

                    esoda = domatio_typeC.timologisi();
                    cout << esoda <<endl;
                    break;

                case 9:

                    esoda = domatio_typeD.timologisi();
                    cout << esoda <<endl;
                    break;

                case 10:

                    esoda = domatio_typeE.timologisi();
                    cout << esoda <<endl;
                    break;

                }
            break;
        }


/*-------------------------------------------------------------------------------------------------*/

        default:

            cout<<"Η ΕΠΙΛΟΓΗ ΣΑΣ ΕΙΝΑΙ ΜΗ ΕΓΚΥΡΗ , ΞΑΝΑΠΡΟΣΠΑΘΗΣΤΕ "<<endl;
            break;

        }//end of switch


    }//end of while



}
