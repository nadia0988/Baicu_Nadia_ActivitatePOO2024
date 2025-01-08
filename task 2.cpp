#include<iostream>
#include<cstring>
using namespace std;


class Student{
public:
    string nume;
    int varsta;
    char* specializare;
    const int anInmatriculare;
    static int numarStudenti;
    
//

    Student(string nume,int varsta,const char*specializare,int an):anInmatriculare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->specializare=new char[strlen(specializare)+1];
        strcpy(this->specializare,specializare);
        numarStudenti++;
    }
    
//  
    Student():anInmatriculare(2021){
        nume="NA";
        varsta=18;
        specializare=new char[10];
        strcpy(specializare," ");
        numarStudenti++;
    }

//
    Student(const Student&s):anInmatriculare(s.anInmatriculare){
        this->nume=s.nume;
        this->varsta=s.varsta;
        this->specializare=new char[strlen(s.specializare)+1];
        strcpy(this->specializare,s.specializare);
    }

    ~Student(){
        if(specializare){
            delete[]specializare;
        }
    }

    void afisare()const{
        cout<<"Studentul "<<nume<<" in varsta de "<<varsta
            <<" de ani, are specializarea de"<<specializare
            <<" si este inmatriculat in anul "<<anInmatriculare<<endl;
    }
//    
    static void afiseazaNumarStudenti(){
        cout<<"numar stud: "<<numarStudenti<<endl;
    }

};

int Student::numarStudenti=0;

class Profesor{
public:
    string nume;
    int varsta;
    float experienta;
    const int anAngajare;
    static int numarProfesori;

//
    Profesor():anAngajare(2020){
        nume="NA";
        varsta=30;
        experienta=0.0;
        numarProfesori++;
    }
//
    Profesor(string nume, int varsta, float experienta, int an):anAngajare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->experienta=experienta;
        numarProfesori++;
    }

//
    Profesor(const Profesor& p):anAngajare(p.anAngajare){
        this->nume=p.nume;
        this->varsta=p.varsta;
        this->experienta=p.experienta;
    }

  
    void afisare()const{
        cout<<"Profesorul "<<nume<<" cu varsta de "<<varsta
            <<" are experienta de "<<experienta
            <<" ani, an angajare "<<anAngajare<<endl;
    }
     
 
//   
     static void afiseazaNumarProfesori(){
        cout<<"numar profesori: "<<numarProfesori<<endl;
    }
};

int Profesor::numarProfesori=0;



class Bibliotecar{
public:
    string nume;
    int varsta;
    char* sectie;
    const int anAngajare;
    static int numarBibliotecari;


//

  Bibliotecar(string nume, int varsta, const char*sectie, int an):anAngajare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->sectie=new char[strlen(sectie)+1];
        strcpy(this->sectie,sectie);
        numarBibliotecari++;
    }
//
    
    Bibliotecar():anAngajare(2015){
        nume="NA";
        varsta=40;
        sectie=new char[10];
        strcpy(sectie," ");
        numarBibliotecari++;
    }

  
//
    
    Bibliotecar(const Bibliotecar&b):anAngajare(b.anAngajare){
        this->nume=b.nume;
        this->varsta=b.varsta;
        this->sectie=new char[strlen(b.sectie)+1];
        strcpy(this->sectie,b.sectie);
    }

   
//
    static void afiseazaNumarBibliotecari(){
        cout<<"numar bibliotecari:"<<numarBibliotecari<<endl;
    }

    void afisare()const{
        cout<<"Bibliotecarul "<<nume<<" in varsta de "<<varsta
            <<" , lucreaza in sectia "<<sectie
            <<" , iar anul de angajare este "<<anAngajare<<endl;
    }
    
     ~Bibliotecar(){
        if(sectie){
            delete[]sectie;
        }
    }
};
int Bibliotecar::numarBibliotecari=0;

int main(){
     Student s1("Ana Marinescu",21,"economie",2021);
    Student s2;
    
    Student s3(s2);

    s1.afisare();
    s2.afisare();
    
    s3.afisare();
    Student::afiseazaNumarStudenti();

     Profesor p1;
    Profesor p2("Diana Dragan",45,20,2000);
    
    Profesor p4(p2);

    p1.afisare();
    p2.afisare();
    
    p4.afisare();
    Profesor::afiseazaNumarProfesori();

   Bibliotecar b1("Ana Dumitrescu",50,"stiintele naturii",1995);
    Bibliotecar b2;
    
    
    Bibliotecar b3(b1);

    b1.afisare();
    
    b2.afisare();
     b3.afisare();
    
    Bibliotecar::afiseazaNumarBibliotecari();

    return 0;
}
