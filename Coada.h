#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED
#include "Nod.h"

using namespace std;
class Coada
{
private:
    Nod *m_prim;
    Nod *m_ultim;
    int m_dim_max;
public:
    void set_prim(Nod* p)
    {
        m_prim = p;
    }
    void set_ultim(Nod *p)
    {
        m_ultim = p;
    }
    void set_dim_max(int dim)
    {
        m_dim_max = dim;
    }
    Nod* get_prim ()
    {
        return m_prim;
    }
    Nod* get_ultim ()
    {
        return m_ultim;
    }
    int get_dim_max ()
    {
        return m_dim_max;
    }
    Coada()
            : m_prim(nullptr), m_ultim(nullptr), m_dim_max(0)
    {

    }
    Coada(Nod *prim,Nod *ultim, int dim_max)
            : m_prim(prim), m_ultim(ultim), m_dim_max(dim_max)
    {

    }
    Coada(const Coada &ob)
            : m_prim(ob.m_prim), m_ultim(ob.m_ultim), m_dim_max(ob.m_dim_max)
    {

    }
    virtual void insert(char* cuvant, int prioritate)
    {
        Nod *aux = new Nod;
        aux->set_info(cuvant);
        aux->m_next = nullptr;
        aux->m_prioritate = prioritate;
        if(!m_prim)
        {
            m_prim = m_ultim = aux;
        }
        else
        {;
            m_ultim->m_next=aux;
            m_ultim = aux;
        }

    }
    char* top()
    {
        Nod *aux;
        Nod *rez;
        aux = m_prim;
        int max_prio = 0;
        while(aux != nullptr)
        {
            if(aux->m_prioritate > max_prio)
            {
                max_prio = aux->m_prioritate;
                rez = aux;
            }
        }
        return rez->m_info;
    }
    virtual void pop()
    {
        if(!m_prim)
            return;
        Nod *aux;
        aux = m_prim;
        m_prim=m_prim->m_next;
        if(m_prim == m_ultim)
            m_ultim = m_prim;
        delete aux;
    }
    void empty()
    {
        if(!m_prim)
            return;
        Nod *aux;
        aux = m_prim;
        while(m_prim != nullptr)
        {
            aux = m_prim;
            m_prim = m_prim->m_next;
            delete aux;
        }
        m_ultim = m_prim = nullptr;
    }
    Coada& operator=(Coada &a)
    {
        empty();
        if(a.get_prim() == nullptr)
            return *this;

        if(a.get_ultim() == nullptr)
        {
            Nod *aux = new Nod;
            aux->set_info(a.get_prim()->get_info());
            aux->set_next(nullptr);
            aux->set_prioritate(a.get_prim()->get_prioritate());
            set_prim(aux);
            return *this;
        }
        else
        {
            Nod *x = a.get_prim();
            int i=0;
            while(x!= nullptr)
            {
                Nod *aux = new Nod;
                if(i==0)
                    set_prim(aux);
                aux->set_info(x->get_info());
                aux->set_prioritate(x->get_prioritate());
                aux->set_next(x->get_next());
                x = x->get_next();
                i++;
                if(aux->get_next() == nullptr)
                    set_ultim(aux);
            }
            return *this;
        }


    }
    friend istream& operator>> (istream &in, Coada &a)
    {

    }
    friend ostream& operator<< (ostream &out, Coada &a)
    {
        cout << "Valorile cozii sunt: " << endl;

        Nod *aux;
        aux = a.m_prim;
        while(aux!=nullptr)
        {
            cout << aux->get_info() << " ";
            aux = aux->get_next();
        }
        cout << endl;
        return out;
    }
    ~Coada()
    {
        empty();
    }
};

#endif // COADA_H_INCLUDED
