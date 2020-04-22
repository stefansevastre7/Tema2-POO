#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED

using namespace std;
class Nod
{
private:
    char* m_info;
    Nod *m_next;
    int m_prioritate;
public:
    void set_info(char* c)
    {
        m_info = c;
    }
    void set_next(Nod *p)
    {
        m_next = p;
    }
    void set_prioritate(int prioritate)
    {
        m_prioritate = prioritate;
    }
    char* get_info()
    {
        return m_info;
    }
    Nod* get_next()
    {
        return m_next;
    }
    int get_prioritate ()
    {
        return m_prioritate;
    }
    Nod()
            :m_next(nullptr),m_prioritate(0)
    {
        m_info = "\0";
    }
    Nod(char *info, Nod *next)
            :m_next(next), m_prioritate(1)
    {
        m_info = info;
    }
    Nod& operator=(Nod &a)
    {
        m_prioritate = a.m_prioritate;
        m_next = a.m_next;
        m_info = a.m_info;
        return *this;
    }
    friend istream& operator>> (istream &in, Nod &a)
    {
        char t[1000];
        int x;
        cout << "Se citeste valorile nodului." << endl;
        cout << "Info "; in >> t; in.get();
        cout << "Prioritate"; in >> x;
        a.set_info(t);
        a.set_prioritate(x);
        return in;
    }
    friend ostream& operator<< (ostream &out, Nod &a)
    {
        cout << "Valorile nodului sunt: " << endl;
        cout << "Info: " << a.get_info() << endl;
        cout << "Prioritate: " << a.get_prioritate() << endl;
        return out;
    }
    ~Nod()   ///destructor
    {

    }
    friend class Coada;
};



#endif // NOD_H_INCLUDED
