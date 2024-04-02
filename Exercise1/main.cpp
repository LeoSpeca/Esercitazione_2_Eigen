#include "Eigen/Eigen"
using namespace Eigen;

int main()
{
    int n = 5;
    //per l'esercizio
    //MatrixXd A = MatrixXd::Random(3,5);
    //MatrixXd A = MatrixXd::Const(3,5,2.0);
    MatrixXd A = MatrixXd::Zero(n,n);
    VectorXd p = VectorXd::LinSpaced(5 * 5, 1, 25);

    for (unsigned int i = 0; i<n; i++)
    {
        A.row(i) = p.segment(n*i,n);

    }

    A = p.reshaped<RowMajor>(n,n); //prende il vettore p e lo trasforma in una matrice n*n
    // e uso RowMajor per farlo lavorare per riga e non per colonna (default)

    cout<<p * p.transpose()<<endl;

    // uso "cwiseProduct(v)" per fare operazioni componente per componente


    for (unsigned int i = 0; i<n; i++)
    {
        A.col(i) = VectorXd::LinSpaced(n, i+1, n+i);

    }

    A = A.cwiseInverse(); //inverte i coefficienti
    cout<< scientific << setprecision(4) << A << endl;

    JacobiSVD<MatrixXd> svd(A);
    VectorXd sing = svd.singularValues();
    cout<< sing.maxCoeff() / sing.minCoeff()<<endl;
    return 0;
}

