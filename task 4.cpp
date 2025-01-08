#include<iostream>
#include<cstring>
using namespace std;

class Student{
    
private:
    string nume;
    int varsta;
    char* specializare;
    const int anInmatriculare;
    static int numarStudenti;

public:
    Student():anInmatriculare(2021){
        nume="NA";
        varsta=18;
        specializare=new char[10];
        strcpy(specializare," ");
        numarStudenti++;
    }

    Student(string nume, int varsta, const char* specializare, int an):anInmatriculare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->specializare=new char[strlen(specializare)+1];
        strcpy(this->specializare,specializare);
        numarStudenti++;
    }

    Student(const Student&s):anInmatriculare(s.anInmatriculare){
        this->nume=s.nume;
        this->varsta=s.varsta;
        this->specializare=new char[strlen(s.specializare)+1];
        strcpy(this->specializare, s.specializare);
    }

    ~Student(){
        if(specializare){
            delete[] specializare;
        }
    }

//operatori
    Student& operator=(const Student& s){
        if(this!=&s){
            nume=s.nume;
            varsta=s.varsta;
            if(specializare){
                delete[]specializare;
            }
            specializare=new char[strlen(s.specializare)+1];
            strcpy(specializare,s.specializare);
        }
        return *this;
    }


    bool operator==(const Student& s) const {
        return (nume==s.nume && varsta==s.varsta && string(specializare)==string(s.specializare) && anInmatriculare==s.anInmatriculare);
    }
    

    Student operator+(int ani){
        Student temp=*this;
        temp.varsta+=ani;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Student& s){
         out<<"Nume student: "<<s.nume<<" varsta: "<<s.varsta<<" specializarea: "<<s.specializare<<" anul: "<<s.anInmatriculare;
        return out;
    }

    string getNume()const{
        return nume;
        
    }
    void setNume(string numeNou){
        nume=numeNou;
        
    }

    int getVarsta()const{
        return varsta;
        
    }
    void setVarsta(int varstaNoua){
        varsta=varstaNoua;
        
    }

    string getSpecializare()const{
        return string(specializare);
        
    }
    void setSpecializare(const char* specializareNoua){
        if(specializare){
            delete[]specializare;
        }
        specializare=new char[strlen(specializareNoua)+1];
        strcpy(specializare,specializareNoua);
    }

    int getAnInmatriculare()const{
        return anInmatriculare;
        
    }

    static int getNumarStudenti(){
        return numarStudenti;
        
    }

    void afisare()const{
        cout<<"Studentul "<<nume<<" are "<<varsta<<" ani, este la specializarea "<<specializare<<" si este inmatriculat in anul "<<anInmatriculare<<endl;
    }

    friend void modificaSpecializare(Student&s, const char* nouaSpecializare);
};

int Student::numarStudenti=0;

void modificaSpecializare(Student&s,const char* nouaSpecializare){
    s.setSpecializare(nouaSpecializare);
    cout<<"Specializarea studentului "<<s.getNume()<<" a fost schimbata in "<<s.getSpecializare()<<endl;
}

class Profesor{
private:
    string nume;
    int varsta;
    float experienta;
    const int anAngajare;
    static int numarProfesori;

public:
    Profesor():anAngajare(2020){
        nume="NA";
        varsta=30;
        experienta=0.0;
        numarProfesori++;
    }

    Profesor(string nume, int varsta, float experienta, int an):anAngajare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->experienta=experienta;
        numarProfesori++;
    }

    Profesor(const Profesor&p):anAngajare(p.anAngajare){
        this->nume=p.nume;
        this->varsta=p.varsta;
        this->experienta=p.experienta;
    }

    ~Profesor(){}
    
    

    Profesor& operator=(const Profesor& p){
        if(this!=&p){
            nume=p.nume;
            varsta=p.varsta;
            experienta=p.experienta;
        }
        return *this;
    }

    bool operator<(const Profesor& p) const {
        return experienta<p.experienta;
    }

    Profesor operator+(float ani){
        Profesor temp=*this;
        temp.experienta+=ani;
        return temp;
    }

    friend ostream& operator<<(ostream& out,const Profesor& p){
        out<<"Nume profesor: "<<p.nume<<" varsta: "<<p.varsta<<" experienta: "<<p.experienta<<" anul angajarii: "<<p.anAngajare;
        return out;
    }

    string getNume()const{
        return nume;
        
    }
    void setNume(string numeNou){
        nume=numeNou;
        
    }

    int getVarsta()const{
        return varsta;
        
    }
    void setVarsta(int varstaNoua){
        varsta=varstaNoua;
        
    }

    float getExperienta()const{
        return experienta;
        
    }
    void setExperienta(float experientaNoua){
        experienta=experientaNoua;
        
    }

    int getAnAngajare()const{
        return anAngajare;
        
    }

    static int getNumarProfesori(){
        return numarProfesori;
        
    }

    void afisare()const{
        cout<<"Profesorul "<<nume<<" cu varsta de "<<varsta<<" si experienta de "<<experienta<<" este angajat din anul "<<anAngajare<<endl;
    }

    friend void cresteExperienta(Profesor&p,float ani);
};




int Profesor::numarProfesori=0;


void cresteExperienta(Profesor&p,float ani){
    p.setExperienta(p.getExperienta()+ani);
    cout<<"Experienta profesorului "<<p.getNume()<<" a crescut la "<<p.getExperienta()<<" de ani"<<endl;
    
}




class Bibliotecar{
    
private:
    string nume;
    int varsta;
    char* sectie;
    const int anAngajare;
    static int numarBibliotecari;



public:
    Bibliotecar():anAngajare(2015){
        nume="NA";
        varsta=40;
        sectie=new char[10];
        strcpy(sectie," ");
        numarBibliotecari++;
    }

    Bibliotecar(string nume, int varsta, const char* sectie, int an):anAngajare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->sectie=new char[strlen(sectie)+1];
        strcpy(this->sectie,sectie);
        numarBibliotecari++;
    }

    Bibliotecar(const Bibliotecar&b):anAngajare(b.anAngajare){
        this->nume=b.nume;
        this->varsta=b.varsta;
        this->sectie=new char[strlen(b.sectie)+1];
        strcpy(this->sectie,b.sectie);
    }

    
    Bibliotecar& operator=(const Bibliotecar& b){
        if(this!=&b){
            nume=b.nume;
            varsta=b.varsta;
            if(sectie){
                delete[]sectie;
            }
            sectie=new char[strlen(b.sectie)+1];
            strcpy(sectie,b.sectie);
        }
        return *this;
    }

    bool operator==(const Bibliotecar& b) const {
        return (nume==b.nume && varsta==b.varsta && string(sectie)==string(b.sectie) && anAngajare==b.anAngajare);
    }

    Bibliotecar operator+(int ani){
        Bibliotecar temp=*this;
        temp.varsta+=ani;
        return temp;
    }

    friend ostream& operator<<(ostream& out,const Bibliotecar& b){
        out<<"Nume bibliotecar: "<<b.nume<<" varsta: "<<b.varsta<<" sectie: "<<b.sectie<<" anul angajarii: "<<b.anAngajare;
        return out;
    }

    string getNume()const{
        return nume;
        
    }
    void setNume(string numeNou){
        nume=numeNou;
        
    }

    int getVarsta()const{
        return varsta;
        
    }
    void setVarsta(int varstaNoua){
        varsta=varstaNoua;
        
    }

    string getSectie()const{
        return string(sectie);
        
    }
    void setSectie(const char* sectieNoua){
        if(sectie){
            delete[]sectie;
        }
        sectie=new char[strlen(sectieNoua)+1];
        strcpy(sectie,sectieNoua);
    }

    int getAnAngajare()const{
        return anAngajare;
        
    }
    
    static int getNumarBibliotecari(){
        return numarBibliotecari;
        
    }
    
    
     ~Bibliotecar(){
        if(sectie){
            delete[]sectie;
        }
    }

    void afisare()const{
        cout<<"Bibliotecarul "<<nume<<" are varsta de "<<varsta<<" si face parte din sectia "<<sectie<<" cu anul angajare "<<anAngajare<<endl;
    }
    
    
    

    friend void modificaSectie(Bibliotecar&b,const char*nouaSectie);
    
    
    
    
};

int Bibliotecar::numarBibliotecari=0;



void modificaSectie(Bibliotecar&b,const char*nouaSectie){
    b.setSectie(nouaSectie);
    cout<<"Sectia bibliotecarului "<<b.getNume()<<" a fost schimbata in "<<b.getSectie()<<endl;
}

int main(){
    
    Student s1("Ana Marinescu",21,"economie",2021);
Student s2=s1;
cout<<s2<<endl;
    s2.setNume("Ana Marin");
    s2=s2+3;
    
    cout<<(s1==s2)<<endl;
    cout<<s2<<endl;

    
    Profesor p1("Dan Andrei",45,20,2000);
    cout<<p1<<endl;

    Profesor p2=p1+2;
      cout<<(p1<p2)<<endl;
     cout<<p2<<endl;

   
    Bibliotecar b1("Ovidiu Adam",50,"informatica",1995);
    
    Bibliotecar b2=b1+5;
    
     cout<<b1<<endl;
    b2.setSectie("matematica");
    cout<<(b1==b2)<<endl;
    cout<<b2<<endl;

    return 0;
}
