
#include "Eigen/Eigen"
#include <iostream>
    using namespace Eigen;
    using namespace std;

    int foo(int c)
    {
        c++;
        return c;
    }

    void foo2(const int& c,  //mettere il const davanti serve per ottimizzare lo spazio in memoria
              int& d)
    {

        // return
    }
    //per le funzioni abbiamo visto int, void, bool





    int main()
    {
        const int b = 5;
        //    b = 5; darebbe errore

        int v = 5;
        int a = v; //faccio una copia di a

        v++;

        //    cout<<"a : " << a << endl;

        int i = foo(a); // cosa sto facendo?
        // step 1:
        // int c = a;
        // esegue le istruzioni {...}
        // reurn -> int i = return c;


        double d = 5.5;
        int ii = d;
        int &refVal = ii; //così refVal è un alias di ii

        int ci = 5;
        const int &refci = ci; //così posso modificare ci ma non refci


        refVal++; //sta volta questo modifica a
        ci++;
        //    cout<<"refci : " << refci << endl;

        const int dtemp = d;
        const int &refdi = dtemp;
        d += 2;
        //     cout<<"refdi : " << refdi << endl;

        //

        int cc = 5;
        int dd = 6;
        //int bb = foo2(cc,dd);

        //step 1: int &c = cc;
        //        int &d = dd;

        //iniziamo a usare Eigen
        srand(5);//set seed
        //Vector4d v1 = Vector4d::Zero(); //così creo un vettore con 4 double
        RowVectorXd v1 = VectorXd::Ones(5); //se ci metto X vuol dire che posso modificarne la dimensione

        cout<<"v1:"<<endl;
        cout<<v1<<endl;


        v1.conservativeResize(4);

        cout<<"v1:"<<endl;
        cout<<v1<<endl;

    return 0;
}
