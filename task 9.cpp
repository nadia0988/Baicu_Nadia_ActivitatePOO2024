#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;

// Clasa abstracta Persoana
class Persoana{
public:
    virtual void afisare() const=0;
    virtual void scrieFisierText(const string& fisier) const=0;
    virtual void citesteFisierText(const string& fisier)=0;
    virtual ~Persoana() {}
};

class Student : public Persoana{
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

    Student& operator=(const Student& s){
        if(this!=&s){
            nume=s.nume;
            varsta=s.varsta;
            if(specializare){
                delete[]specializare;
            }
            specializare=new char[strlen(s.specializare)+1];
            strcpy(specializare, s.specializare);
        }
        return *this;
    }

    void afisare() const override {
        cout<<"Nume student: "<<nume<<" varsta: "<<varsta<<" specializarea: "<<specializare<<" anul: "<<anInmatriculare<<endl;
    }

    void scrieFisierText(const string& fisier) const override{
        ofstream out(fisier,ios::app);
        out<<nume<<","<<varsta<<","<<specializare<<","<<anInmatriculare<<"\n";
        out.close();
    }

    void citesteFisierText(const string& fisier) override{
        ifstream in(fisier);
        string linie;
        while(getline(in,linie)){
            cout<<linie<<endl;
        }
        in.close();
    }
};

class Profesor : public Persoana{
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

    Profesor& operator=(const Profesor& p){
        if(this!=&p){
            nume=p.nume;
            varsta=p.varsta;
            experienta=p.experienta;
        }
        return *this;
    }

    void afisare() const override{
        cout<<"Nume profesor: "<<nume<<" varsta: "<<varsta<<" experienta: "<<experienta<<" anul angajarii: "<<anAngajare<<endl;
    }

    void scrieFisierText(const string& fisier) const override{
        ofstream out(fisier,ios::app);
        out<<nume<<","<<varsta<<","<<experienta<<","<<anAngajare<<"\n";
        out.close();
    }

    void citesteFisierText(const string& fisier) override{
        ifstream in(fisier);
        string linie;
        while(getline(in,linie)){
            cout<<linie<<endl;
        }
        in.close();
    }
};

class Bibliotecar : public Persoana{
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

    void afisare() const override{
        cout<<"Nume bibliotecar: "<<nume<<" varsta: "<<varsta<<" sectie: "<<sectie<<" anul angajarii: "<<anAngajare<<endl;
    }

    void scrieFisierText(const string& fisier) const override{
        ofstream out(fisier, ios::app);
        out<<nume<<","<<varsta<<","<<sectie<<","<<anAngajare<<"\n";
        out.close();
    }

    void citesteFisierText(const string& fisier) override{
        ifstream in(fisier);
        string linie;
        while(getline(in,linie)){
            cout<<linie<<endl;
        }
        in.close();
    }
};

int main(){
    vector<Persoana*> persoane;
    
     persoane.push_back(new Student("Ion", 21, "matematica", 2021));
        persoane.push_back(new Student("Maria", 20, "economie", 2021));
     persoane.push_back(new Profesor("Ioana", 50, 25, 2013));
     persoane.push_back(new Profesor("Dan", 45, 20, 2000));
     persoane.push_back(new Bibliotecar("Andrei", 35, "Lb. romana", 2010));
    persoane.push_back(new Bibliotecar("Elena", 40, "statistica", 2015));

    cout<<"lista persoane: "<<endl;
    for(auto persoana:persoane){
        persoana->afisare();
    }


    for(auto persoana:persoane){
        delete persoana;
    }



    return 0;
}
