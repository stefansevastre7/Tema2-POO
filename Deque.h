#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#include "Coada.h"
using namespace std;
class Deque: public Coada
{
private:

public:
    Deque()
            : Coada()
    {

    }
    Deque(Nod *prim,Nod *ultim, int dim_max)
            : Coada(prim,ultim,dim_max)
    {

    }
    Deque(const Deque &ob)
            : Coada(ob)
    {

    }
    void pop_front()
    {
        auto prim = get_prim();
        auto ultim = get_ultim();
        if(prim)
            return;
        Nod *aux;
        aux = prim;
        prim=prim->get_next();
        if(prim == ultim)
            ultim = prim;
        delete aux;
    }
    void pop_back()
    {
        auto prim = get_prim();
        auto ultim = get_ultim();
        if(!ultim)
            return;
        Nod *aux = prim;
        while(aux->get_next() != ultim)
        {
            aux = aux->get_next();
        }
        delete ultim;
        ultim = aux;
        if(prim == ultim)
            prim = ultim;
    }
    void pop()
    {
        try {
            std::string t;
            std::cout << "pop() called for deque. Type 'front' or 'back': ";
            cin >> t;
            if(t!="front" && t!="back")
                throw "eroare";
            else
            if(t=="front")
                pop_front();
            else
                pop_back();
        }
        catch(const std::string &error)
        {
            std::cout << "Type error. No pop() has been commited." << endl;
        }
    }
    void insert_back(char* cuvant, int prioritate)
    {
        auto m_prim = get_prim();
        auto m_ultim = get_ultim();
        Nod *aux = new Nod;
        aux->set_info(cuvant);
        aux->set_next(nullptr);
        aux->set_prioritate(1);
        if(!m_prim)
        {
            m_prim = m_ultim = aux;
        }
        else
        {;
            m_ultim->set_next(aux);
            m_ultim = aux;
        }
        set_prim(m_prim);
        set_ultim(m_ultim);
    }
    void insert_front(char* cuvant, int prioritate)
    {
        auto m_prim = get_prim();
        auto m_ultim = get_ultim();
        Nod *aux = new Nod;
        aux->set_info(cuvant);
        aux->set_next(nullptr);
        aux->set_prioritate(1);
        if(!m_prim)
        {
            m_prim = m_ultim = aux;
        }
        else
        {
            aux->set_next(m_prim);
            m_prim = aux;
        }
        set_prim(m_prim);
        set_ultim(m_ultim);
    }
    void insert(char* cuvant, int prioritate)
    {
        try {
            std::string t;
            std::cout << "insert() called for deque. Type 'front' or 'back': ";
            cin >> t;
            if(t!="front" && t!="back")
                throw "eroare";
            else
            if(t=="front")
                insert_back(cuvant,prioritate);
            else
                insert_front(cuvant,prioritate);
        }
        catch(const std::string &error)
        {
            std::cout << "Type error. No pop() has been commited." << endl;
        }
    }
    friend istream& operator>> (istream &in, Deque &a)
    {
        return in;
    }
    friend ostream& operator<< (ostream &out, Deque &a)
    {
        cout << "Valorile cozii duble sunt: " << endl;
        Nod *aux;
        aux = a.get_prim();
        while(aux!=nullptr)
        {
            cout << aux->get_info() << " ";
            aux = aux->get_next();
        }
        cout << endl;
        return out;
    }
    Deque& operator=(Deque &a) {
        empty();
        if (a.get_prim() == nullptr)
            return *this;

        if (a.get_ultim() == nullptr) {
            Nod *aux = new Nod;
            aux->set_info(a.get_prim()->get_info());
            aux->set_next(nullptr);
            aux->set_prioritate(a.get_prim()->get_prioritate());
            set_prim(aux);
            return *this;
        } else {
            Nod *x = a.get_prim();
            int i = 0;
            while (x != nullptr) {
                Nod *aux = new Nod;
                if (i == 0)
                    set_prim(aux);
                aux->set_info(x->get_info());
                aux->set_prioritate(x->get_prioritate());
                aux->set_next(x->get_next());
                x = x->get_next();
                i++;
                if (aux->get_next() == nullptr)
                    set_ultim(aux);
            }
            return *this;
        }
    }
    ~Deque()
    {
        empty();
    }
};

#endif // DEQUE_H_INCLUDED
