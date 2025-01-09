#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

class Student{
    
private:
    string nume;
    int varsta;
    char* specializare;
    const int anInmatriculare;

public:
    Student():anInmatriculare(2021){
        nume="NA";
        varsta=18;
        specializare=new char[10];
        strcpy(specializare," ");
    }

    Student(string nume, int varsta, const char* specializare, int an):anInmatriculare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->specializare=new char[strlen(specializare)+1];
        strcpy(this->specializare,specializare);
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

    friend istream& operator>>(istream& in, Student& s){
        cout<<"Nume: ";
        in>>s.nume;
        cout<<"Varsta: ";
        in>>s.varsta;
        char buffer[100];
        cout<<"Specializare: ";
        in>>buffer;
        if(s.specializare){
            delete[]s.specializare;
        }
        s.specializare=new char[strlen(buffer)+1];
        strcpy(s.specializare,buffer);
        
        return in;
    }
};


class Profesor{
private:
    string nume;
    int varsta;
    float experienta;
    const int anAngajare;

public:
    Profesor():anAngajare(2020){
        nume="NA";
        varsta=30;
        experienta=0.0;
    }

    Profesor(string nume, int varsta, float experienta, int an):anAngajare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->experienta=experienta;
    }

    Profesor(const Profesor&p):anAngajare(p.anAngajare){
        this->nume=p.nume;
        this->varsta=p.varsta;
        this->experienta=p.experienta;
    }

    ~Profesor(){}

    //operatori
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

    friend istream& operator>>(istream& in, Profesor& p){
        cout<<"nume: ";
        in>>p.nume;
        cout<<"varsta: ";
        in>>p.varsta;
        cout<<"experinta: ";
        in>>p.experienta;
        return in;
    }
};

class Bibliotecar{
    
private:
    string nume;
    int varsta;
    char* sectie;
    const int anAngajare;

public:
    Bibliotecar():anAngajare(2015){
        nume="NA";
        varsta=40;
        sectie=new char[10];
        strcpy(sectie," ");
    }

    Bibliotecar(string nume, int varsta, const char* sectie, int an):anAngajare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->sectie=new char[strlen(sectie)+1];
        strcpy(this->sectie,sectie);
    }

    Bibliotecar(const Bibliotecar&b):anAngajare(b.anAngajare){
        this->nume=b.nume;
            this->varsta=b.varsta;
        this->sectie=new char[strlen(b.sectie)+1];
        strcpy(this->sectie,b.sectie);
    }

    ~Bibliotecar(){
        if(sectie){
            delete[]sectie;
        }
    }

    //opratori
    Bibliotecar& operator=(const Bibliotecar& b){
        if(this!=&b){
            nume=b.nume;
            varsta=b.varsta;
          //
          
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

    friend istream& operator>>(istream& in,Bibliotecar& b){
        cout<<"nume: ";
        in>>b.nume;
        cout<<"varsta: ";
        in>>b.varsta;//
               char buffer[100];
        cout<<"sectie: ";
         in>>buffer;
        if(b.sectie){
            delete[]b.sectie;
        }
        b.sectie=new char[strlen(buffer)+1];
        strcpy(b.sectie,buffer);
        return in;
    }
};

class Scoala {
private:
     string numeScoala;
     int nrClase;
        vector<Student> studenti;
         vector<Profesor> profesori;
     vector<Bibliotecar> bibliotecari;

public:

    //constructori
    Scoala(){
        numeScoala="Scoala 1";
        nrClase=0;
    }

    Scoala(string nume, int nrClase, const vector<Student>& studenti, const vector<Profesor>& profesori, const vector<Bibliotecar>& bibliotecari){
        this->numeScoala=nume;
         this->nrClase=nrClase;
        this->studenti=studenti;
        this->profesori=profesori;
        this->bibliotecari=bibliotecari;
    }

    Scoala(const Scoala& s){
        this->numeScoala=s.numeScoala;
        this->nrClase=s.nrClase;
        this->studenti=s.studenti;
        this->profesori=s.profesori;
           this->bibliotecari=s.bibliotecari;
    }



    ~Scoala(){}

 //getteri si setteri
 
 
    string getNumeScoala() const {
        return numeScoala;
        }
    void setNumeScoala(string nume){
        numeScoala=nume;
        }

    int getNrClase() const {
        return nrClase; 
        
    }
    void setNrClase(int nr){
        nrClase=nr;
        }
        
        

    vector<Student> getStudenti() const {
        return studenti;
        }
    void setStudenti(const vector<Student>& studenti){ 
        this->studenti=studenti;
        }
        
        

    vector<Profesor> getProfesori() const {
        return profesori; 
        
    }
    
    void setProfesori(const vector<Profesor>& profesori){
        this->profesori=profesori;
        }

    vector<Bibliotecar> getBibliotecari() const {
        return bibliotecari; 
        
    }
    
    void setBibliotecari(const vector<Bibliotecar>& bibliotecari){
        this->bibliotecari=bibliotecari;
        }



    //operatori
    
    
    Scoala& operator=(const Scoala& s){
        if(this!=&s){
            numeScoala=s.numeScoala;
            nrClase=s.nrClase;
            studenti=s.studenti;
            profesori=s.profesori;
            bibliotecari=s.bibliotecari;
        }
        return *this;
    }



     Scoala operator+(int extraClase){
        Scoala temp=*this;
        temp.nrClase+=extraClase;
        return temp;
    }

    friend ostream& operator<<(ostream& out, const Scoala& s){
        out<<"scoala: "<<s.numeScoala<<", clase nr: "<<s.nrClase<<endl;
        out<<"studenti: "<<endl;
        for(const auto& student : s.studenti){
            out<<"  "<<student<<endl;
        }
        out<<"profesori:"<<endl;
        for(const auto& profesor : s.profesori){
            out<<"  "<<profesor<<endl;
        }
        out<<"bibliotecari :"<<endl;
        for(const auto& bibliotecar : s.bibliotecari){
            out<<"  "<<bibliotecar<<endl;
        }
        
        
        return out;
    }
};


int main(){



    int n,m,k;
    cout<<"Nr studenti: ";
    cin>>n;
    vector<Student> studenti(n);
    for(int i=0; i<n; i++){
            cout<<"Student "<<i+1<<" : "<<endl;
        cin>>studenti[i];
    }


    cout<<"Nr profesori: ";
    cin>>m;
    vector<Profesor> profesori(m);
    for(int i=0; i<m; i++){
        cout<<"Profesor "<<i+1<<" : "<<endl;
        cin>>profesori[i];
    }

  
    cout<<"Nr bibliotecari: ";
    cin>>k;
    
    vector<Bibliotecar> bibliotecari(k);
    for(int i=0; i<k; i++){
        cout<<"Bibliotecar "<<i+1<<" : "<<endl;
    cin>>bibliotecari[i];
    }

    Scoala scoala1("Scoala 5", 10, studenti, profesori, bibliotecari);
    cout<<"Scoala initiala:"<<endl;
    cout<<scoala1;


    scoala1.setNumeScoala("Liceul 2");
    scoala1.setNrClase(10);

    //adaug clase
    Scoala scoala2= scoala1+5;

    //afisam scoala modif
    cout<<"Scoala modificata:"<<endl;
    cout<<scoala2;

    return 0;
}

