#ifndef EXPOSITION_H
#define EXPOSITION_H

#include <string>
#include <cstring>
#include <vector>
#include <utility>
#include <typeinfo>

#include "supersport.h"
#include "coupe.h"
#include "cabrio.h"
#include "hothatch.h"

template<typename T>
class Exposition {
    static int totalExpositions;
    int nrTot = 0;
    std::vector<T*> v;
public:
    Exposition();
    ~Exposition();
    Exposition(T* masina);
    Exposition(const Exposition& e);
    void Push(T* masina);
    void PopX(int i);
    void afisNrTot() const;
    static int getTotalExpositions();

    //inline pentru ca imi da eroare friend declaration declares a non-template function
    friend std::istream& operator>>(std::istream& in, Exposition<T>& e){
        int n;
        std::string name;
        T* masina;
        std::cout << "Number of cars in "<< typeid(masina).name() << " exposition: \n";
        in >> n;
        std::cin.get();
        for (int i = 0; i < n; ++i) {
            std::cout << i + 1 <<". ";
            std::getline(in, name);
            masina = new T(name);
            e.Push(masina);
            // delete masina; nu pot sa dau delete aici pentru ca mi ar sterge elem vectorului
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, Exposition<T> e) {
        out << "\nThe cars in the exposition are: \n";
        for (const auto& element : e.v)
            out << *element << " - " << typeid(*element).name() << '\n';
        out << "With a total of " << e.nrTot << '\n';
        return out;
    }

};
//nu merge in .cpp
template<typename T>
int Exposition<T>::totalExpositions = 0;

template<typename T>
Exposition<T>::Exposition() {
    totalExpositions ++;
};

template<typename T>
Exposition<T>::~Exposition() {
    for (auto* ptr: v){
        // std::cout << ptr<<'\n';
        delete ptr;
    }
    v.clear();
}

template<typename T>
Exposition<T>::Exposition(T* masina){
    this->v.push_back(masina);
    ++nrTot;
    totalExpositions ++;
}

template<typename T>
Exposition<T>::Exposition(const Exposition& e){
    this->nrTot = e.nrTot;
    for (const auto& element : e.v)
        this->v.push_back(element);
}

template<typename T>
void Exposition<T>::Push(T* masina) {
    v.push_back(masina);
    ++nrTot;
}

template<typename T>
void Exposition<T>::PopX(int i) {
    if (i < v.size()) {
        this->v.erase(v.begin() + i, v.begin() + i + 1);
        --nrTot;
    }
}

template<typename T>
void Exposition<T>::afisNrTot() const {
    std::cout << nrTot;
}

template<typename T>
int Exposition<T>::getTotalExpositions() {
    return totalExpositions;
}

//Exposition explicitly specialized for <Car>
template<>
class Exposition<Car> {
    static int totalExpositions;
    int nrTot = 0;
    std::vector<Car*> v;
public:
    Exposition();
    ~Exposition();
    Exposition(Car* masina);
    Exposition(const Exposition& e);
    void Push(Car* masina);
    void PopX(int i);
    void afisNrTot() const;
    static int getTotalExpositions();

    //inline pentru ca imi da eroare friend declaration declares a non-template function
    friend std::istream& operator>>(std::istream& in, Exposition<Car>& e){
        std::cout << "Number of cars in exposition: \n";
        int n;
        std::string name;
        char type[11];
        Car* masina;
        in >> n;
        for (int i = 0; i < n; ++i) {
            std::cout << "Type of car(COUPE/HOTHATCH/CABRIO/SUPERSPORT): ";
            in >> type;
            std::cout << "Car name: ";
            std::cin.get();
            
            std::cout << i + 1 << ". ";
            if (!strcmp(type, "COUPE"))
                std::getline(in, name), masina = new Coupe(name), e.Push(masina);
            else if (!strcmp(type, "HOTHATCH")) 
                std::getline(in, name), masina = new Hothatch(name), e.Push(masina);
            else if (!strcmp(type, "CABRIO"))
                std::getline(in, name), masina = new Cabrio(name), e.Push(masina);
            else if (!strcmp(type, "SUPERSPORT"))
                std::getline(in, name), masina = new Supersport(name), e.Push(masina);
            else 
                std::cout << "BAD TYPE\n", i -= 1;
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, Exposition<Car> e) {
        out << "\nThe cars in the exposition are: \n";
        for (const auto& element : e.v)
            out << *element << " - " << typeid(*element).name() << '\n';
        out << "With a total of " << e.nrTot << '\n';
        return out;
    }
    
};

int Exposition<Car>::totalExpositions = 0;

Exposition<Car>::Exposition() {
    totalExpositions ++;
};

Exposition<Car>::~Exposition() {
    for (auto* ptr: v){
        // std::cout << *ptr << '\n';
        delete ptr;
    }
    v.clear();
}



Exposition<Car>::Exposition(Car* masina){
    this->v.push_back(masina);
    ++nrTot;
    totalExpositions ++;
}

Exposition<Car>::Exposition(const Exposition& e){
    this->nrTot = e.nrTot;
    for (const auto& element : e.v)
        this->v.push_back(element);
}

void Exposition<Car>::Push(Car* masina) {
    v.push_back(masina);
    ++nrTot;
}

void Exposition<Car>::PopX(int i) {
    if (i < v.size()) {
        this->v.erase(v.begin() + i, v.begin() + i + 1);
        --nrTot;
    }
}

void Exposition<Car>::afisNrTot() const {
    std::cout << nrTot;
}

int Exposition<Car>::getTotalExpositions() {
    return totalExpositions;
}

//Exposition explicitly specialized for <Supersport>
template<>
class Exposition<Supersport>{
    static int totalExpositions;
    int nrTot = 0;
    int nrTotSold = 0;
    std::vector<std::pair<Supersport*, int> > v;
    std::vector<Supersport*> vSold;
public:
    Exposition();
    ~Exposition();
    Exposition(Supersport* masina, int pret=-1);
    Exposition(const Exposition& masina);
    void Push(Supersport* masina, int pret=-1);
    void Sell(Supersport* masina, int price);
    static int getTotalExpositions();
    Exposition<Supersport>& operator-=(const int nrVanzari);

    //inline pentru ca imi da eroare friend declaration declares a non-template function
    friend std::istream& operator>>(std::istream& in, Exposition<Supersport>& e){
        int n, pret;
        std::string name;
        Supersport* masina;
        std::cout << "Number of cars in Supersport exposition: \n";
        in >> n;
        std::cin.get();
        for (int i = 0; i < n; ++i){
            std::cout << "Supersport car " << i + 1 << ". and the price was sold(-1 if not sold) ";
            std::getline(in, name);
            std::cin >> pret;
            std::cin.get();
            masina = new Supersport(name);
            e.Push(masina, pret);
        }
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, Exposition<Supersport> e){
        out << "\nThe cars in the exposition are: \n";
        for (const auto& pair : e.v)
            out << *pair.first << " | " ;
        out << "\nThe sold ones are: \n";
        for (const auto& element : e.vSold)
            out << *element << " | ";
        out << "\nWith a total of " << e.nrTot << " available cars and " << e.nrTotSold << " sold ones\n";
        return out;
    }
};

int Exposition<Supersport>::totalExpositions = 0;

Exposition<Supersport>::Exposition() {
    totalExpositions ++;
}

Exposition<Supersport>::~Exposition() {
    for (auto& pair : v){
        delete pair.first;
    }
    v.clear();
}

Exposition<Supersport>::Exposition(Supersport* masina, int pret){
    this->v.push_back(std::make_pair(masina, pret));
    if (pret != -1)
        ++ nrTotSold, vSold.push_back(masina);
    else 
        ++ nrTot;
    totalExpositions ++;
}

Exposition<Supersport>::Exposition(const Exposition& e){
    this->nrTot = e.nrTot;
    this->nrTotSold = e.nrTotSold;
    for (const auto& pair : e.v)
        this->v.push_back(std::make_pair(pair.first, pair.second));

    for (const auto& element : e.vSold)
        this->vSold.push_back(element);
}

void Exposition<Supersport>::Push(Supersport* masina, int pret) {
    this->v.push_back(std::make_pair(masina, pret));
    if (pret != -1)
        ++ nrTotSold, vSold.push_back(masina);
    else 
        ++ nrTot;
}

void Exposition<Supersport>::Sell(Supersport* masina, int price){
    for (auto& pair : v)
        if (masina == pair.first && pair.second == -1) {
            pair.second = price;
            this->vSold.push_back(pair.first);
            --nrTot;
            ++nrTotSold;
        }
}

int Exposition<Supersport>::getTotalExpositions() {
    return totalExpositions;
}

Exposition<Supersport>& Exposition<Supersport>::operator-=(const int nrVanzari){
        if (nrVanzari <= nrTot){
            this->nrTot -= nrVanzari;
            this->nrTotSold += nrVanzari;

            for (int i = 0, j = 0; i < nrVanzari && j < v.size(); ++j){
                if (v[j].second == -1){
                    v[j].second = 0, ++i;
                    vSold.push_back(v[j].first);
                    }
            }

            return *this;
        }
        else 
            throw std::out_of_range("Not enough stock to sell!\n");
    // catch(const std::out_of_range ex){
    //     std::cout << "Exception occured: " << ex.what() << '\n';
    // }
} 

#endif