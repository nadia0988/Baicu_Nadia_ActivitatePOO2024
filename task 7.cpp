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
        cout<<"nume: ";
        in>>s.nume;
        cout<<"varsta: ";
        in>>s.varsta;
        char buffer[100];
        cout<<"specializare: ";
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



//
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

 //getteri& setteri
 
 
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


//clasa elev--mosteneste claa Student


class Elev:public Student{
private:
    string scoala;
    float medie;

public:

    Elev():Student(){
        scoala="NA";
        medie=0.0;
    }

    Elev(string nume, int varsta, const char* specializare, int an,string scoala, float medie)
    :Student(nume, varsta, specializare, an){
        this->scoala=scoala;
        this->medie=medie;
    }

    Elev(const Elev& e):Student(e){
        this->scoala=e.scoala;
        this->medie=e.medie;
    }

  //getteri si setteri
    
    string getScoala()const{
        return scoala;
    }
        
    void setScoala(string scoalaNoua){
        scoala=scoalaNoua;
    }

    float getMedie()const{
        return medie;
    }
    void setMedie(float medieNoua){
        medie=medieNoua;
    }

//operatori

    friend ostream& operator<<(ostream& out,const Elev& e){
        out<<(Student)e<<" scoala: "<<e.scoala<<" media: "<<e.medie;
        return out;
    }
};



//clasa ProfesorUniversitar ---mosteneste Profesor
class ProfesorUniversitar:public Profesor{
private:
    string departament;
    int numarPublicatii;

public:
  
  
    ProfesorUniversitar():Profesor(){
        departament="NA";
        numarPublicatii=0;
    }

    ProfesorUniversitar(string nume,int varsta,float experienta,int an,string departament,int numarPublicatii):Profesor(nume,varsta,experienta,an){
        this->departament=departament;
        this->numarPublicatii=numarPublicatii;
    }


    ProfesorUniversitar(const ProfesorUniversitar& pu):Profesor(pu){
        this->departament=pu.departament;
        this->numarPublicatii=pu.numarPublicatii;
    }

    //getteri si setteri
    string getDepartament()const{
        return departament;
    }
    
    void setDepartament(string departamentNou){
        departament=departamentNou;
    }

    int getNumarPublicatii()const{
        return numarPublicatii;
    }
    void setNumarPublicatii(int numarNou){
        numarPublicatii=numarNou;
    }




    friend ostream& operator<<(ostream& out,const ProfesorUniversitar& pu){
        out<<(Profesor)pu<<" departament: "<<pu.departament<<" publicatii: "<<pu.numarPublicatii;
        return out;
    }
};


int main(){


    Elev elev1("Ana", 16, "mate", 2021, "Liceul 1", 9.5);
    Elev elev2("Maria", 15, "istorie",2021,"Scoala 10", 8.5);
    cout<<"lista elevi: "<<endl;
    cout<<elev1<<endl;
    cout<<elev2<<endl;


    ProfesorUniversitar prof1("Ion Adam", 50, 25, 1998, "Economie", 30);
    ProfesorUniversitar prof2("Dan Popescu", 45, 20, 2000, "Matematica", 15);
    cout<<" \n Profesori universitari: "<<endl;
    cout<<prof1<<endl;
    cout<<prof2<<endl;

   



    //Upcasting
     cout<<" \n Upcasting: "<<endl;
    
    Student* elevUp1=&elev1;
    Student*elevUp2=&elev2;
    
    cout <<"elev->student: "<< *elevUp1<<endl;
    cout <<"elev->student: "<< *elevUp2<<endl;

//
    Profesor* profUp1= &prof1;
    Profesor* profUp2=&prof2;
    
    cout<<"Profesor universitar->profesor: "<<*profUp1<<endl;
    cout<<"Profesor universitar->profesor: "<<*profUp2<<endl;

    return 0;
}
