#include<iostream>
#include<cstring>
#include<vector>
#include<fstream>
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

    Student(string nume,int varsta,const char* specializare,int an):anInmatriculare(an){
        this->nume=nume;
        this->varsta=varsta;
        this->specializare=new char[strlen(specializare)+1];
        strcpy(this->specializare,specializare);
    }

    Student(const Student&s):anInmatriculare(s.anInmatriculare){
        this->nume=s.nume;
        this->varsta=s.varsta;
        this->specializare=new char[strlen(s.specializare)+1];
        strcpy(this->specializare,s.specializare);
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
            strcpy(specializare,s.specializare);
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out,const Student& s){
         out<<"Nume student: "<<s.nume<<" varsta: "<<s.varsta<<" specializarea: "<<s.specializare<<" anul: "<<s.anInmatriculare;
        return out;
    }

    friend istream& operator>>(istream& in,Student& s){
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

    void scrieFisierText(const string& fisier){
        ofstream out(fisier,ios::app);
        out<<nume<<","<<varsta<<","<<specializare<<","<<anInmatriculare<<"\n";
        out.close();
    }

    void citesteFisierText(const string& fisier){
        ifstream in(fisier);
        string linie;
        while(getline(in,linie)){
            cout<<linie<<endl;
        }
        in.close();
    }

    void scrieFisierBinar(const string& fisier){
        ofstream out(fisier,ios::binary|ios::app);
        size_t lungime=nume.size();
        out.write((char*)&lungime, sizeof(lungime));
        out.write(nume.c_str(),lungime);
        out.write((char*)&varsta, sizeof(varsta));
        lungime=strlen(specializare);
        out.write((char*)&lungime, sizeof(lungime));
        out.write(specializare, lungime);
        out.write((char*)&anInmatriculare, sizeof(anInmatriculare));
        out.close();
    }

    void citesteFisierBinar(const string& fisier){
        ifstream in(fisier,ios::binary);
        size_t lungime;
        
          in.read((char*)&lungime, sizeof(lungime));
          nume.resize(lungime);
             in.read(&nume[0], lungime);
        in.read((char*)&varsta, sizeof(varsta));
        in.read((char*)&lungime, sizeof(lungime));
        
        delete[]specializare;
            specializare=new char[lungime+1];
            in.read(specializare,lungime);
        specializare[lungime]='\0';
        in.close();
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

    Profesor& operator=(const Profesor& p){
        if(this!=&p){
            nume=p.nume;
            varsta=p.varsta;
            experienta=p.experienta;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Profesor& p){
        out<<"Nume profesor: "<<p.nume<<" varsta: "<<p.varsta<<" experienta: "<<p.experienta<<" anul angajarii: "<<p.anAngajare;
        return out;
    }

    friend istream& operator>>(istream& in,Profesor& p){
        cout<<"nume: ";
        in>>p.nume;
        cout<<"varsta: ";
        in>>p.varsta;
        cout<<"experinta: ";
        in>>p.experienta;
        return in;
    }

    void scrieFisierText(const string& fisier){
        ofstream out(fisier,ios::app);
        out<<nume<<","<<varsta<<","<<experienta<<","<<anAngajare<<"\n";
        out.close();
    }

    void citesteFisierText(const string& fisier){//
             ifstream in(fisier);
         string linie;
         while(getline(in,linie)){
            cout<<linie<<endl;
        }
        in.close();
    }
};

int main(){
    
    Student s1("Ion", 21, "economie", 2021);
    
    Student s2("Maria", 20 , "matematica", 2021);
    Profesor p1("Ion Pop", 50, 25, 1995);
    Profesor p2("Dan Ion", 55, 27, 1986);

//
    cout<<"wr student"<<endl;
    s1.scrieFisierText("studenti.txt");
    s2.scrieFisierText("studenti.txt");
    s1.citesteFisierText("studenti.txt");
    s2.citesteFisierText("studenti.txt");
    cout<<"\n wr prof "<<endl;
    p1.scrieFisierText("profesori.txt");
    p2.scrieFisierText("profesori.txt");
    p1.citesteFisierText("profesori.txt");
    p2.citesteFisierText("profesori.txt");
    cout<<"\nwr binar student "<<endl;
    s1.scrieFisierBinar("studenti.dat");
    s2.scrieFisierBinar("studenti.dat");
   
    Student s3;
     
    s3.citesteFisierBinar("studenti.dat");
    cout<<s3<<endl;

    return 0;
}
