#include <iostream>
#include <string>
#include <list>

using namespace std;

class Student{
protected:
    string name, surname;
    list<double> grades;
public:
    string getname(){return name;}
    string getsurname(){return surname;}
    Student(string name, string surname){
        this->name=name; this->surname=surname;
    }

    void addGrade(double grade){
        grades.push_back(grade);
    }

    void showgrades(){
        for (list<double>::iterator ite=grades.begin(); ite!=grades.end(); ++ite) cout<<*ite<<"\t";
    }

    double mean(){
        double sum=0;
        for (list<double>::iterator ite=grades.begin(); ite!=grades.end(); ++ite ) sum+= *ite;
        return sum/grades.size();
    }

    void showstudent(){
        cout<<"Name: "<<name<<"\tSurname: "<<surname<<"\tMean: "<<mean()<<"\nGrades:\n";
    }
};

class LabGroup{
protected:
    string name;

    list<Student*> students;
    double sum=0;
    double mmean=0;

public:
    string getname(){return name;}
    double getn(){return students.size();}

    LabGroup(string name){
        this->name=name;

    }

    void addStudent(Student &s){
        students.push_back(&s);
    }

    double gmean(){
        for (list<Student*>::iterator iter=students.begin(); iter!=students.end(); ++iter) sum+= (*iter)->mean();
        mmean=sum/students.size();
        return mmean;
    }

    void scholarship(){
        for (list<Student*>::iterator ite=students.begin(); ite!=students.end(); ++ite) {
            if ((*ite)->mean() > mmean/students.size()) cout<<"\n"<<(*ite)->getname()<<" "<<(*ite)->getsurname()<<" should have scholarship.";
        }
    }
};

class LecGroup{
protected:
    string name;

    list<LabGroup*> labstudents;
    double sum=0;
public:
    string getname(){return name;}

    LecGroup(string name){
        this->name=name;

    }

    void addLabGroup(LabGroup& lg){
        labstudents.push_back(&lg);
    }

    double grmean(){
        for (list<LabGroup*>::iterator iter=labstudents.begin(); iter!=labstudents.end(); ++iter) sum+= (*iter)->gmean();
        return sum/scount();
    }

    double scount(){
        int count=0;
        for (list<LabGroup*>::iterator iter=labstudents.begin(); iter!=labstudents.end(); ++iter) count+= (*iter)->getn();
        return count;
    }
};


int main()
{
    Student st1("Artur","Kozak");
    Student st4("Bartek","Nieprogramista");
    Student st2("Kamil","Kebabowymistrz");
    Student st3("Rafal","Panstarosta");
    st1.addGrade(5);
    st1.addGrade(4);
    st1.addGrade(5);
    st1.addGrade(5);
    st1.addGrade(3);
    st1.addGrade(3);


    st2.addGrade(3);
    st2.addGrade(3);
    st2.addGrade(4);
    st2.addGrade(4);


    st3.addGrade(5);
    st3.addGrade(4);
    st3.addGrade(4);
    st3.addGrade(4);


    st4.addGrade(3);
    st4.addGrade(3);
    st4.addGrade(3);
    st4.addGrade(4);


    st1.showstudent();
    st1.showgrades();
    cout<<"\n\n";
    st2.showstudent();
    st2.showgrades();
    cout<<"\n\n";
    st3.showstudent();
    st3.showgrades();
    cout<<"\n\n";
    st4.showstudent();
    st4.showgrades();

    LabGroup gl1("Lab1");
    gl1.addStudent(st1);
    gl1.addStudent(st2);

    LabGroup gl2("Lab2");
    gl2.addStudent(st3);
    gl2.addStudent(st4);

    LabGroup gl3("Lab3");
    gl3.addStudent(st2);
    gl3.addStudent(st3);

    LecGroup lec1("Lec1");
    lec1.addLabGroup(gl1);
    lec1.addLabGroup(gl2);
    lec1.addLabGroup(gl3);


    cout<<"\n\nLaboratory group: "<<gl1.getname()<<"\tNumber of students: "<<gl1.getn()<<"\tGroup's mean: "<<gl1.gmean()<<"\n";
    cout<<"\nLaboratory group: "<<gl2.getname()<<"\tNumber of students: "<<gl2.getn()<<"\tGroup's mean: "<<gl2.gmean()<<"\n";
    cout<<"\nLaboratory group: "<<gl3.getname()<<"\tNumber of students: "<<gl3.getn()<<"\tGroup's mean: "<<gl3.gmean()<<"\n";
    cout<<"\nLecture group: "<<lec1.getname()<<"\tNumber of students: "<<lec1.scount()<<"\tGroup's mean: "<<lec1.grmean()<<"\n";
    cout<<"\n\nWho can acquire scholarship in Laboratory group "<<gl1.getname()<<" :";
    gl1.scholarship();
    cout<<"\n\nWho can acquire scholarship in Laboratory group "<<gl2.getname()<<" :";
    gl2.scholarship();
    cout<<"\n\nWho can acquire scholarship in Laboratory group "<<gl3.getname()<<" :";
    gl3.scholarship();
cout<<"\n";
}

